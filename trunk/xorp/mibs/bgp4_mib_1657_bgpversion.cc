/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.scalar.conf,v 1.5 2002/07/18 14:18:52 dts12 Exp $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "xorpevents.hh"
#include "bgp4_mib_1657.hh"
#include "bgp4_mib_1657_bgpversion.hh"

/** Initializes the bgp_version_scalar module */
void
init_bgp4_mib_1657_bgpversion (void)
{
    static oid bgpVersion_oid[] = { 1,3,6,1,2,1,15,1, 0 };

    DEBUGMSGTL(("bgp4_mib_1657_bgpversion", "Initializing\n"));

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
    static const int bgpVerStrMax = 4;
    char bgpVersion[bgpVerStrMax];
    int  bgpVersionLen = snprintf(bgpVersion, bgpVerStrMax, "%d", *ver);

    DEBUGMSGTL(("bgp4_mib_1657_bgpversion", "get_bgp_version_done called\n"));
    DEBUGMSGTL(("bgp4_mib_1657_bgpversion", "ver = %ld\n", *ver));

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
	DEBUGMSGTL(("bgp4_mib_1657_bgpversion", "XrlError: "));
	DEBUGMSGTL(("bgp4_mib_1657_bgpversion", e.error_msg()));
	DEBUGMSGTL(("bgp4_mib_1657_bgpversion", "\n"));
	netsnmp_set_request_error(reqinfo, requests, SNMP_NOSUCHINSTANCE);
	return;
    }

    DEBUGMSGTL((XORP_MODULE_NAME,"continuing delayed req, mode = %d\n", reqinfo->mode));

    // no longer delegated since we'll answer down below
    requests->delegated = 0;

    snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
	(unsigned char *) bgpVersion, bgpVersionLen);

    return;
}


int
get_bgpVersion(netsnmp_mib_handler * handler,
                          netsnmp_handler_registration * reginfo,
                          netsnmp_agent_request_info *  reqinfo,
                          netsnmp_request_info *requests)
{
    DEBUGMSGTL(("bgp4_mib_1657_bgpversion", "get_bgpVersion called\n"));
    BgpMibXrlClient& bgp_mib = BgpMibXrlClient::the_instance();
    BgpMibXrlClient::CB0 cb_version;
    netsnmp_delegated_cache * req_cache = netsnmp_create_delegated_cache(handler,
					    reginfo, reqinfo, requests, NULL);
    cb_version = callback(get_bgp_version_done, req_cache);
    bgp_mib.send_get_bgp_version("bgp", cb_version); 

    requests->delegated = 1;
    SnmpEventLoop& eventloop = SnmpEventLoop::the_instance(); 
    eventloop.export_events();
    return SNMP_ERR_NOERROR;
}
