/*
 * Copyright (c) 2001-2009 XORP, Inc.
 * See the XORP LICENSE.lgpl file for licensing, conditions, and warranties
 * on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'tgt-gen'.
 */

#ident "$XORP: xorp/xrl/targets/ribclient_base.cc,v 1.23 2008/10/02 21:58:49 bms Exp $"


#include "ribclient_base.hh"


XrlRibclientTargetBase::XrlRibclientTargetBase(XrlCmdMap* cmds)
    : _cmds(cmds)
{
    if (_cmds)
	add_handlers();
}

XrlRibclientTargetBase::~XrlRibclientTargetBase()
{
    if (_cmds)
	remove_handlers();
}

bool
XrlRibclientTargetBase::set_command_map(XrlCmdMap* cmds)
{
    if (_cmds == 0 && cmds) {
        _cmds = cmds;
        add_handlers();
        return true;
    }
    if (_cmds && cmds == 0) {
	remove_handlers();
        _cmds = cmds;
        return true;
    }
    return false;
}

const XrlCmdError
XrlRibclientTargetBase::handle_rib_client_0_1_route_info_changed4(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 6) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(6), XORP_UINT_CAST(xa_inputs.size()), "rib_client/0.1/route_info_changed4");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rib_client_0_1_route_info_changed4(
	    xa_inputs.get(0, "addr").ipv4(),
	    xa_inputs.get(1, "prefix_len").uint32(),
	    xa_inputs.get(2, "nexthop").ipv4(),
	    xa_inputs.get(3, "metric").uint32(),
	    xa_inputs.get(4, "admin_distance").uint32(),
	    xa_inputs.get(5, "protocol_origin").text());
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "rib_client/0.1/route_info_changed4", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlRibclientTargetBase::handle_rib_client_0_1_route_info_changed6(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 6) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(6), XORP_UINT_CAST(xa_inputs.size()), "rib_client/0.1/route_info_changed6");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rib_client_0_1_route_info_changed6(
	    xa_inputs.get(0, "addr").ipv6(),
	    xa_inputs.get(1, "prefix_len").uint32(),
	    xa_inputs.get(2, "nexthop").ipv6(),
	    xa_inputs.get(3, "metric").uint32(),
	    xa_inputs.get(4, "admin_distance").uint32(),
	    xa_inputs.get(5, "protocol_origin").text());
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "rib_client/0.1/route_info_changed6", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlRibclientTargetBase::handle_rib_client_0_1_route_info_invalid4(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 2) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(2), XORP_UINT_CAST(xa_inputs.size()), "rib_client/0.1/route_info_invalid4");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rib_client_0_1_route_info_invalid4(
	    xa_inputs.get(0, "addr").ipv4(),
	    xa_inputs.get(1, "prefix_len").uint32());
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "rib_client/0.1/route_info_invalid4", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlRibclientTargetBase::handle_rib_client_0_1_route_info_invalid6(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 2) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(2), XORP_UINT_CAST(xa_inputs.size()), "rib_client/0.1/route_info_invalid6");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rib_client_0_1_route_info_invalid6(
	    xa_inputs.get(0, "addr").ipv6(),
	    xa_inputs.get(1, "prefix_len").uint32());
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "rib_client/0.1/route_info_invalid6", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

void
XrlRibclientTargetBase::add_handlers()
{
	if (_cmds->add_handler("rib_client/0.1/route_info_changed4",
	    callback(this, &XrlRibclientTargetBase::handle_rib_client_0_1_route_info_changed4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "ribclient", "rib_client/0.1/route_info_changed4");
	}
	if (_cmds->add_handler("rib_client/0.1/route_info_changed6",
	    callback(this, &XrlRibclientTargetBase::handle_rib_client_0_1_route_info_changed6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "ribclient", "rib_client/0.1/route_info_changed6");
	}
	if (_cmds->add_handler("rib_client/0.1/route_info_invalid4",
	    callback(this, &XrlRibclientTargetBase::handle_rib_client_0_1_route_info_invalid4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "ribclient", "rib_client/0.1/route_info_invalid4");
	}
	if (_cmds->add_handler("rib_client/0.1/route_info_invalid6",
	    callback(this, &XrlRibclientTargetBase::handle_rib_client_0_1_route_info_invalid6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "ribclient", "rib_client/0.1/route_info_invalid6");
	}
	_cmds->finalize();
}

void
XrlRibclientTargetBase::remove_handlers()
{
	_cmds->remove_handler("rib_client/0.1/route_info_changed4");
	_cmds->remove_handler("rib_client/0.1/route_info_changed6");
	_cmds->remove_handler("rib_client/0.1/route_info_invalid4");
	_cmds->remove_handler("rib_client/0.1/route_info_invalid6");
}
