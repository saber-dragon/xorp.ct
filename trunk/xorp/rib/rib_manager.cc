// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001-2003 International Computer Science Institute
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

#ident "$XORP: xorp/rib/rib_manager.cc,v 1.10 2003/03/20 04:29:22 pavlin Exp $"

#include "rib_module.h"
#include "libxorp/xorp.h"
#include "libxorp/xlog.h"
#include "libxorp/debug.h"
#include "libxorp/utils.hh"
#include "rib_manager.hh"

RibManager::RibManager(EventLoop& event_loop, XrlStdRouter& xrl_std_router)
    : _event_loop(event_loop),
      _xrl_router(xrl_std_router),
      _rserv(&_xrl_router),
      _urib4(UNICAST),
      _mrib4(MULTICAST),
      _urib6(UNICAST),
      _mrib6(MULTICAST),
      _vifmanager(_xrl_router, _event_loop, this),
      _xrt(&_xrl_router, _urib4, _mrib4, _urib6, _mrib6, _vifmanager, this)
{
    _urib4.initialize_export(&_urib4_clients_list);
    _urib4.initialize_register(&_rserv);
    if (_urib4.add_igp_table("connected") < 0) {
	XLOG_ERROR("Could not add igp table \"connected\" for urib4");
	return;
    }

    _mrib4.initialize_export(&_mrib4_clients_list);
    _mrib4.initialize_register(&_rserv);
    if (_mrib4.add_igp_table("connected") < 0) {
	XLOG_ERROR("Could not add igp table \"connected\" for mrib4");
	return;
    }

    _urib6.initialize_export(&_urib6_clients_list);
    _urib6.initialize_register(&_rserv);
    if (_urib6.add_igp_table("connected") < 0) {
	XLOG_ERROR("Could not add igp table \"connected\" for urib6");
	return;
    }

    _mrib6.initialize_export(&_mrib6_clients_list);
    _mrib6.initialize_register(&_rserv);
    if (_mrib6.add_igp_table("connected") < 0) {
	XLOG_ERROR("Could not add igp table \"connected\" for mrib6");
	return;
    }
}

RibManager::~RibManager()
{
    stop();
    
    delete_pointers_list(_urib4_clients_list);
    delete_pointers_list(_mrib4_clients_list);
    delete_pointers_list(_urib6_clients_list);
    delete_pointers_list(_mrib6_clients_list);
}

/**
 * RibManager::start:
 * @void: 
 * 
 * Start operation.
 * 
 * Return value: %XORP_OK on success, otherwize %XORP_ERROR.
 **/
int
RibManager::start(void)
{
    if (ProtoState::start() < 0)
	return (XORP_ERROR);
    
    _vifmanager.start();
    
    return (XORP_OK);
}

/**
 * RibManager::stop:
 * @void: 
 * 
 * Gracefully stop the RIB.
 * 
 * Return value: %XORP_OK on success, otherwise %XORP_ERROR.
 **/
int
RibManager::stop(void)
{
    if (! is_up())
	return (XORP_ERROR);
    
    _vifmanager.stop();
    
    ProtoState::stop();
    
    return (XORP_OK);
}

int
RibManager::new_vif(const string& vifname, const Vif& vif, string& err) 
{
    if (_urib4.new_vif(vifname, vif)) {
	err = (c_format("Failed to add vif \"%s\" to unicast IPv4 rib",
			vifname.c_str()));
	return XORP_ERROR;
    }

    if (_mrib4.new_vif(vifname, vif)) {
	err = (c_format("Failed to add vif \"%s\" to multicast IPv4 rib",
			     vifname.c_str()));
	return XORP_ERROR;
    }

    if (_urib6.new_vif(vifname, vif)) {
	err = (c_format("Failed to add vif \"%s\" to unicast IPv6 rib",
			vifname.c_str()));
	return XORP_ERROR;
    }

    if (_mrib6.new_vif(vifname, vif)) {
	err = (c_format("Failed to add vif \"%s\" to multicast IPv6 rib",
			     vifname.c_str()));
	return XORP_ERROR;
    }
    return XORP_OK;
}

int
RibManager::delete_vif(const string& vifname, string& err) 
{
    if (_urib4.delete_vif(vifname)) {
	err = (c_format("Failed to delete vif \"%s\" from unicast IPv4 rib",
			vifname.c_str()));
	return XORP_ERROR;
    }

    if (_mrib4.delete_vif(vifname)) {
	err = (c_format("Failed to delete vif \"%s\" from multicast IPv4 rib",
			     vifname.c_str()));
	return XORP_ERROR;
    }

    if (_urib6.delete_vif(vifname)) {
	err = (c_format("Failed to delete vif \"%s\" from unicast IPv6 rib",
			vifname.c_str()));
	return XORP_ERROR;
    }

    if (_mrib6.delete_vif(vifname)) {
	err = (c_format("Failed to delete vif \"%s\" from multicast IPv6 rib",
			     vifname.c_str()));
	return XORP_ERROR;
    }
    return XORP_OK;
}

int
RibManager::add_vif_addr(const string& vifname,
			 const IPv4& addr,
			 const IPNet<IPv4>& subnet,
			 string& err)
{
    if (_urib4.add_vif_address(vifname, addr, subnet)) {
	err = "Failed to add IPv4 Vif address to unicast RIB";
	return XORP_ERROR;
    }

    if (_mrib4.add_vif_address(vifname, addr, subnet)) {
	err = "Failed to add IPv4 Vif address to multicast RIB";
	return XORP_ERROR;
    }

    return XORP_OK;
}

int
RibManager::delete_vif_addr(const string& vifname,
			    const IPv4& addr,
			    string& err)
{
    if (_urib4.delete_vif_address(vifname, addr)) {
	err = "Failed to delete IPv4 Vif address from unicast RIB";
	return XORP_ERROR;
    }

    if (_mrib4.delete_vif_address(vifname, addr)) {
	err = "Failed to delete IPv4 Vif address from multicast RIB";
	return XORP_ERROR;
    }

    return XORP_OK;
}

int
RibManager::add_vif_addr(const string& vifname,
			 const IPv6& addr,
			 const IPNet<IPv6>& subnet,
			 string& err)
{
    if (_urib6.add_vif_address(vifname, addr, subnet)) {
	err = "Failed to add IPv6 Vif address to unicast RIB";
	return XORP_ERROR;
    }

    if (_mrib6.add_vif_address(vifname, addr, subnet)) {
	err = "Failed to add IPv6 Vif address to multicast RIB";
	return XORP_ERROR;
    }

    return XORP_OK;
}

int
RibManager::delete_vif_addr(const string& vifname,
			    const IPv6& addr,
			    string& err)
{
    if (_urib6.delete_vif_address(vifname, addr)) {
	err = "Failed to delete IPv6 Vif address from unicast RIB";
	return XORP_ERROR;
    }

    if (_mrib6.delete_vif_address(vifname, addr)) {
	err = "Failed to delete IPv6 Vif address from multicast RIB";
	return XORP_ERROR;
    }

    return XORP_OK;
}

//
// Select the appropriate list of RIB clients
//
list<RibClient *> *
RibManager::select_rib_clients_list(int family, bool is_unicast,
				    bool is_multicast)
{
    if (! (is_unicast ^ is_unicast))
	return (NULL);	// Only one of the flags must be set
    
    //
    // Select the appropriate list
    //
    switch (family) {
    case AF_INET:
	if (is_unicast)
	    return (&_urib4_clients_list);
	if (is_multicast)
	    return (&_mrib4_clients_list);
	break;
#ifdef HAVE_IPV6
    case AF_INET6:
	if (is_unicast)
	    return (&_urib6_clients_list);
	if (is_multicast)
	    return (&_mrib6_clients_list);
	break;
#endif // HAVE_IPV6
    default:
	XLOG_FATAL("Invalid address family: %d", family);
	break;
    }
    
    //
    // Nothing found
    //
    return (NULL);
}

//
// Find a RIB client for a given target name, address family, and
// unicast/multicast flags.
//
RibClient *
RibManager::find_rib_client(const string& target_name, int family,
			    bool is_unicast, bool is_multicast)
{
    list<RibClient *> *rib_clients_list;
    
    rib_clients_list = select_rib_clients_list(family, is_unicast,
					       is_multicast);
    if (rib_clients_list == NULL)
	return (NULL);
    
    //
    // Search for a RIB client with the same target name
    //
    list<RibClient *>::iterator iter;
    for (iter = rib_clients_list->begin();
	 iter != rib_clients_list->end();
	 ++iter) {
	RibClient *rib_client = *iter;
	if (rib_client->target_name() == target_name)
	    return (rib_client);
    }
    
    //
    // Nothing found
    //
    return (NULL);
}

//
// Add a RIB client for a given target name, address family, and
// unicast/multicast flags.
//
// Return: XORP_OK on success, otherwise XORP_ERROR.
//
int
RibManager::add_rib_client(const string& target_name, int family,
			   bool is_unicast, bool is_multicast)
{
    list<RibClient *> *rib_clients_list;
    
    //
    // Check if this RIB client has been added already
    //
    if (find_rib_client(target_name, family, is_unicast, is_multicast) != NULL)
	return (XORP_OK);
    
    //
    // Find the list of RIB clients to add the new client to.
    //
    rib_clients_list = select_rib_clients_list(family, is_unicast,
					       is_multicast);
    if (rib_clients_list == NULL)
	return (XORP_ERROR);
    
    //
    // Create a new RibClient, and add it to the list
    //
    RibClient *rib_client = new RibClient(_xrl_router, target_name);
    rib_clients_list->push_back(rib_client);
    
    return (XORP_OK);
}

//
// Delete a RIB client for a given target name, address family, and
// unicast/multicast flags.
//
// Return: XORP_OK on success, otherwise XORP_ERROR.
//
int
RibManager::delete_rib_client(const string& target_name, int family,
			      bool is_unicast, bool is_multicast)
{
    RibClient *rib_client;
    list<RibClient *> *rib_clients_list;
    
    //
    // Find the RIB client
    //
    rib_client = find_rib_client(target_name, family, is_unicast,
				 is_multicast);
    if (rib_client == NULL)
	return (XORP_ERROR);

    //
    // Find the list of RIB clients
    //
    rib_clients_list = select_rib_clients_list(family, is_unicast,
					       is_multicast);
    if (rib_clients_list == NULL)
	return (XORP_ERROR);
    
    list<RibClient *>::iterator iter;
    iter = find(rib_clients_list->begin(),
		rib_clients_list->end(),
		rib_client);
    XLOG_ASSERT(iter != rib_clients_list->end());
    rib_clients_list->erase(iter);
    
    delete rib_client;
    
    return (XORP_OK);
}

//
// Enable a RIB client for a given target name, address family, and
// unicast/multicast flags.
//
// Return: XORP_OK on success, otherwise XORP_ERROR.
//
int
RibManager::enable_rib_client(const string& target_name, int family,
			      bool is_unicast, bool is_multicast)
{
    RibClient *rib_client;
    
    //
    // Find the RIB client
    //
    rib_client = find_rib_client(target_name, family, is_unicast,
				 is_multicast);
    if (rib_client == NULL)
	return (XORP_ERROR);
    
    rib_client->set_enabled(true);
    
    return (XORP_OK);
}

//
// Disable a RIB client for a given target name, address family, and
// unicast/multicast flags.
//
// Return: XORP_OK on success, otherwise XORP_ERROR.
//
int
RibManager::disable_rib_client(const string& target_name, int family,
			       bool is_unicast, bool is_multicast)
{
    RibClient *rib_client;
    
    //
    // Find the RIB client
    //
    rib_client = find_rib_client(target_name, family, is_unicast,
				 is_multicast);
    if (rib_client == NULL)
	return (XORP_ERROR);
    
    rib_client->set_enabled(false);
    
    return (XORP_OK);
}

//
// Don't try to communicate with the FEA.
//
// Note that this method will be obsoleted in the future, and will
// be replaced with cleaner interface.
//
int
RibManager::no_fea()
{
    // TODO: FEA target name hardcoded
    disable_rib_client("fea", AF_INET, true, false);
#ifdef HAVE_IPV6
    disable_rib_client("fea", AF_INET6, true, false);
#endif
    
    _vifmanager.no_fea();
    
    return (XORP_OK);
}
