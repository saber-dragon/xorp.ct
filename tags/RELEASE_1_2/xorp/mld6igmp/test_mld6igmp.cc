// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001-2005 International Computer Science Institute
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software")
// to deal in the Software without restriction, subject to the conditions
// listed in the XORP LICENSE file. These conditions include: you must
// preserve this copyright notice, and you cannot mention the copyright
// holders in advertising related to the Software without their permission.
// The Software is provided WITHOUT ANY WARRANTY, EXPRESS OR IMPLIED. This
// notice is a summary of the XORP LICENSE file; the license in that file is
// legally binding.

#ident "$XORP: xorp/mld6igmp/test_mld6igmp.cc,v 1.46 2005/09/07 20:15:46 pavlin Exp $"


//
// MLD and IGMP test program.
//

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "mld6igmp_module.h"
#include "libxorp/xorp.h"
#include "libxorp/xlog.h"
#include "libxorp/debug.h"
#include "libxorp/callback.hh"
#include "libxorp/eventloop.hh"
#include "libxorp/exceptions.hh"
#include "libxorp/profile.hh"

#include "libxipc/finder_server.hh"
#include "libxipc/xrl_std_router.hh"

#include "cli/xrl_cli_node.hh"

#include "fea/fticonfig.hh"
#include "fea/ifmanager.hh"
#include "fea/ifconfig.hh"
#include "fea/ifconfig_addr_table.hh"
#include "fea/libfeaclient_bridge.hh"
#include "fea/nexthop_port_mapper.hh"
#include "fea/xrl_ifupdate.hh"
#include "fea/xrl_mfea_node.hh"
#include "fea/xrl_rawsock4.hh"
#include "fea/xrl_rawsock6.hh"
#include "fea/xrl_socket_server.hh"
#include "fea/xrl_target.hh"

#include "xrl_mld6igmp_node.hh"

#ifdef HAVE_GETOPT_H
#include <getopt.h>
#endif


#ifndef FEA_DUMMY
static bool is_dummy = false;
#else
static bool is_dummy = true;
#endif


//
// Local functions prototypes
//
static	void usage(const char *argv0, int exit_value);

/**
 * usage:
 * @argv0: Argument 0 when the program was called (the program name itself).
 * @exit_value: The exit value of the program.
 *
 * Print the program usage.
 * If @exit_value is 0, the usage will be printed to the standart output,
 * otherwise to the standart error.
 **/
static void
usage(const char *argv0, int exit_value)
{
    FILE *output;
    const char *progname = strrchr(argv0, '/');

    if (progname != NULL)
	progname++;		// Skip the last '/'
    if (progname == NULL)
	progname = argv0;

    //
    // If the usage is printed because of error, output to stderr, otherwise
    // output to stdout.
    //
    if (exit_value == 0)
	output = stdout;
    else
	output = stderr;

    fprintf(output, "Usage: %s [-F <finder_hostname>[:<finder_port>]]\n",
	    progname);
    fprintf(output, "           -F <finder_hostname>[:<finder_port>]  : finder hostname and port\n");
    fprintf(output, "           -h                                    : usage (this message)\n");
    fprintf(output, "\n");
    fprintf(output, "Program name:   %s\n", progname);
    fprintf(output, "Module name:    %s\n", XORP_MODULE_NAME);
    fprintf(output, "Module version: %s\n", XORP_MODULE_VERSION);

    exit (exit_value);

    // NOTREACHED
}

static void
mld6igmp_main(const string& finder_hostname, uint16_t finder_port,
	      bool start_finder)
{
    string error_msg;
    EventLoop eventloop;

    //
    // Init stuff
    //

    //
    // Start our own finder
    //
    FinderServer *finder = NULL;
    if (start_finder) {
	try {
	    finder = new FinderServer(eventloop, IPv4(finder_hostname.c_str()),
				      finder_port);
	} catch (const InvalidPort&) {
	    XLOG_FATAL("Could not start in-process Finder");
	}
    }

    //
    // CLI
    //
    // XXX: we use a single CLI node to handle both IPv4 and IPv6
    CliNode cli_node(AF_INET, XORP_MODULE_CLI, eventloop);
    cli_node.set_cli_port(12000);
    XrlCliNode xrl_cli_node(eventloop,
			    cli_node.module_name(),
			    finder_hostname,
			    finder_port,
			    "finder",
			    cli_node);
    wait_until_xrl_router_is_ready(eventloop, xrl_cli_node.xrl_router());

    //
    // FEA
    //
    XrlStdRouter xrl_std_router_fea(eventloop,
				    xorp_module_name(AF_INET, XORP_MODULE_FEA),
				    finder_hostname.c_str(),
				    finder_port);

    //
    // Profile entity
    //
    Profile profile;

    //
    // Next-hop port mapper
    //
    NexthopPortMapper nexthop_port_mapper;

    //
    // Interface Configurator and reporters
    //
    XrlIfConfigUpdateReporter xrl_ifc_reporter(xrl_std_router_fea);
    LibFeaClientBridge        lfc_bridge(xrl_std_router_fea);

    IfConfigUpdateReplicator ifc_repl;
    ifc_repl.add_reporter(&xrl_ifc_reporter);
    ifc_repl.add_reporter(&lfc_bridge);

    IfConfigErrorReporter if_err;

    IfConfig ifconfig(eventloop, ifc_repl, if_err, nexthop_port_mapper);
    if (is_dummy)
	ifconfig.set_dummy();
    if (ifconfig.start(error_msg) != XORP_OK) {
	XLOG_FATAL("Cannot start IfConfig: %s", error_msg.c_str());
    }

    //
    // Interface manager
    //
    InterfaceManager ifm(ifconfig);

    //
    // Hook IfTree of interface manager into ifconfig so it can
    // be updated by the ifconfig observers as appropriate.
    //
    ifconfig.hook_local_config(&ifm.iftree());

    //
    // Hook IfTree of interface manager into libfeaclient
    // so it can read config to determine deltas.
    //
    const IfTree& iftree = ifm.iftree();
    lfc_bridge.set_iftree(&iftree);

    //
    // FtiConfig
    //
    FtiConfig fticonfig(eventloop, profile, ifm.iftree(), nexthop_port_mapper);
    if (is_dummy)
	fticonfig.set_dummy();
    if (fticonfig.start(error_msg) != XORP_OK) {
	XLOG_FATAL("Cannot start FtiConfig: %s", error_msg.c_str());
    }

    //
    // Raw Sockets
    //
    XrlRawSocket4Manager xrsm4(eventloop, iftree, xrl_std_router_fea);
    XrlRawSocket6Manager xrsm6(eventloop, iftree, xrl_std_router_fea);

    //
    // Xrl Socket Server and related components
    //
    IfConfigAddressTable ifc_addr_table(iftree);
    ifc_repl.add_reporter(&ifc_addr_table);
    XrlSocketServer xss(eventloop,
			ifc_addr_table,
			xrl_std_router_fea.finder_address(),
			xrl_std_router_fea.finder_port());
    xss.startup();

    //
    // XRL Target
    //
    XrlFeaTarget xrl_fea_target(eventloop, xrl_std_router_fea,
				fticonfig, ifm, xrl_ifc_reporter,
				profile, &xrsm4, &xrsm6, &lfc_bridge, &xss);
    wait_until_xrl_router_is_ready(eventloop, xrl_std_router_fea);

    //
    // MFEA node
    //
    XrlMfeaNode xrl_mfea_node4(AF_INET,
			       XORP_MODULE_MFEA,
			       eventloop,
			       xorp_module_name(AF_INET, XORP_MODULE_MFEA),
			       finder_hostname,
			       finder_port,
			       "finder",
			       xorp_module_name(AF_INET, XORP_MODULE_FEA));
    wait_until_xrl_router_is_ready(eventloop, xrl_mfea_node4.xrl_router());

#ifdef HAVE_IPV6
    XrlMfeaNode xrl_mfea_node6(AF_INET6,
			       XORP_MODULE_MFEA,
			       eventloop,
			       xorp_module_name(AF_INET6, XORP_MODULE_MFEA),
			       finder_hostname,
			       finder_port,
			       "finder",
			       xorp_module_name(AF_INET6, XORP_MODULE_MFEA));
    wait_until_xrl_router_is_ready(eventloop, xrl_mfea_node6.xrl_router());
#endif // HAVE_IPV6

    //
    // MLD6IGMP node
    //
    XrlMld6igmpNode xrl_mld6igmp_node4(AF_INET,
				       XORP_MODULE_MLD6IGMP,
				       eventloop,
				       xorp_module_name(AF_INET,
							XORP_MODULE_MLD6IGMP),
				       finder_hostname,
				       finder_port,
				       "finder",
				       xorp_module_name(AF_INET,
							XORP_MODULE_MFEA));
    wait_until_xrl_router_is_ready(eventloop, xrl_mld6igmp_node4.xrl_router());

#ifdef HAVE_IPV6
    XrlMld6igmpNode xrl_mld6igmp_node6(AF_INET6,
				       XORP_MODULE_MLD6IGMP,
				       eventloop,
				       xorp_module_name(AF_INET6,
							XORP_MODULE_MLD6IGMP),
				       finder_hostname,
				       finder_port,
				       "finder",
				       xorp_module_name(AF_INET6,
							XORP_MODULE_MFEA));
    wait_until_xrl_router_is_ready(eventloop, xrl_mld6igmp_node6.xrl_router());
#endif // HAVE_IPV6

    //
    // Main loop
    //
    for (;;) {
	eventloop.run();
    }

    if (finder != NULL)
	delete finder;
}

int
main(int argc, char *argv[])
{
    int ch;
    string::size_type idx;
    const char *argv0 = argv[0];
    string finder_hostname = FinderConstants::FINDER_DEFAULT_HOST().str();
    uint16_t finder_port = FinderConstants::FINDER_DEFAULT_PORT();

    //
    // Initialize and start xlog
    //
    xlog_init(argv[0], NULL);
    xlog_set_verbose(XLOG_VERBOSE_LOW);		// Least verbose messages
    // XXX: verbosity of the error messages temporary increased
    xlog_level_set_verbose(XLOG_LEVEL_ERROR, XLOG_VERBOSE_HIGH);
    xlog_add_default_output();
    xlog_start();

    //
    // Get the program options
    //
    while ((ch = getopt(argc, argv, "F:h")) != -1) {
	switch (ch) {
	case 'F':
	    // Finder hostname and port
	    finder_hostname = optarg;
	    idx = finder_hostname.find(':');
	    if (idx != string::npos) {
		if (idx + 1 >= finder_hostname.length()) {
		    // No port number
		    usage(argv0, 1);
		    // NOTREACHED
		}
		char* p = &finder_hostname[idx + 1];
		finder_port = static_cast<uint16_t>(atoi(p));
		finder_hostname = finder_hostname.substr(0, idx);
	    }
	    break;
	case 'h':
	case '?':
	    // Help
	    usage(argv0, 0);
	    // NOTREACHED
	    break;
	default:
	    usage(argv0, 1);
	    // NOTREACHED
	    break;
	}
    }
    argc -= optind;
    argv += optind;
    if (argc != 0) {
	usage(argv0, 1);
	// NOTREACHED
    }

    //
    // Run everything
    //
    try {
	mld6igmp_main(finder_hostname, finder_port, true);
    } catch(...) {
	xorp_catch_standard_exceptions();
    }

    //
    // Gracefully stop and exit xlog
    //
    xlog_stop();
    xlog_exit();

    exit (0);
}