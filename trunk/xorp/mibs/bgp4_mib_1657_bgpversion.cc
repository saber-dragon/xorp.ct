// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001-2009 XORP, Inc.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License, Version 2, June
// 1991 as published by the Free Software Foundation. Redistribution
// and/or modification of this program under the terms of any other
// version of the GNU General Public License is not permitted.
// 
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. For more details,
// see the GNU General Public License, Version 2, a copy of which can be
// found in the XORP LICENSE.gpl file.
// 
// XORP Inc, 2953 Bunker Hill Lane, Suite 204, Santa Clara, CA 95054, USA;
// http://xorp.net

#ident "$XORP: xorp/mibs/bgp4_mib_1657_bgpversion.cc,v 1.18 2008/10/02 21:57:41 bms Exp $"


#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "fixconfigs.h"

#include "bgp4_mib_module.h"
#include "libxorp/xorp.h"

#include "xorpevents.hh"
#include "bgp4_mib_1657.hh"
#include "bgp4_mib_1657_bgpversion.hh"

/** Initializes the bgp_version_scalar module */
void
init_bgp4_mib_1657_bgpversion (void)
{
    static oid bgpVersion_oid[] = { 1,3,6,1,2,1,15,1, 0 };

    DEBUGMSGTL((BgpMib::the_instance().name(),"Initializing bgpVersion...\n"));

    netsnmp_register_read_only_instance(netsnmp_create_handler_registration
                                        ("bgpVersion",
                                         get_bgpVersion,
                                         bgpVersion_oid,
                                         OID_LENGTH(bgpVersion_oid),
                                         HANDLER_CAN_RONLY));
}

void get_bgp_version_done(const XrlError& e, const uint32_t* ver, 
			       netsnmp_delegated_cache* cache)
{

    DEBUGMSGTL((BgpMib::the_instance().name(), "get_bgp_version_done called\n"));

    netsnmp_request_info *requests;
    netsnmp_agent_request_info *reqinfo;

    cache = netsnmp_handler_check_cache(cache);

    if (!cache) {
        snmp_log(LOG_ERR, "illegal call to return delayed response\n");
        return;
    }

    // re-establish the previous pointers we are used to having 
    reqinfo = cache->reqinfo;
    requests = cache->requests;

    if (e != XrlError::OKAY()) {
	DEBUGMSGTL((BgpMib::the_instance().name(), "XrlError: "));
	DEBUGMSGTL((BgpMib::the_instance().name(), e.error_msg()));
	DEBUGMSGTL((BgpMib::the_instance().name(), "\n"));
	netsnmp_set_request_error(reqinfo, requests, SNMP_NOSUCHINSTANCE);
	requests->delegated = 0;
	return;
    }

    DEBUGMSGTL((BgpMib::the_instance().name(),"continued delayed req, "
	"mode = %d\n", reqinfo->mode));

    // no longer delegated since we'll answer down below

    requests->delegated = 0;
    uint8_t bgpVersion_bin = 1 << (*ver - 1);

    snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
	(unsigned char *) &bgpVersion_bin, sizeof(uint8_t));

    return;
}


int
get_bgpVersion(netsnmp_mib_handler * handler,
                          netsnmp_handler_registration * reginfo,
                          netsnmp_agent_request_info *  reqinfo,
                          netsnmp_request_info *requests)
{
    DEBUGMSGTL((BgpMib::the_instance().name(), "get_bgpVersion called\n"));
    BgpMib& bgp_mib = BgpMib::the_instance();
    BgpMib::GetBgpVersionCB cb_version;
    netsnmp_delegated_cache* req_cache = netsnmp_create_delegated_cache
	(handler, reginfo, reqinfo, requests, NULL);
    cb_version = callback(get_bgp_version_done, req_cache);
    bgp_mib.send_get_bgp_version("bgp", cb_version); 

    requests->delegated = 1;
    return SNMP_ERR_NOERROR;
}
