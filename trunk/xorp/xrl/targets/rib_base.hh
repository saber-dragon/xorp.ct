/*
 * Copyright (c) 2002 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by '../scripts/tgt-gen'.
 *
 * $XORP: xorp/xrl/targets/rib_base.hh,v 1.3 2003/01/28 00:37:57 hodson Exp $
 */


#ifndef __XRL_INTERFACES_RIB_BASE_HH__
#define __XRL_INTERFACES_RIB_BASE_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XrlRibTarget"

#include "libxorp/xlog.h"
#include "libxipc/xrl_cmd_map.hh"

class XrlRibTargetBase {
protected:
    XrlCmdMap* _cmds;
    
public:
    XrlRibTargetBase(XrlCmdMap* cmds) : _cmds(cmds) { add_handlers(); }
    virtual ~XrlRibTargetBase() { remove_handlers(); }

    inline const string& name() const { return _cmds->name(); }
    inline const char* version() const { return "rib/0.0"; }

protected:

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Get name of Xrl Target
     */
    virtual XrlCmdError common_0_1_get_target_name(
	// Output values, 
	string&	name) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Get version string from Xrl Target
     */
    virtual XrlCmdError common_0_1_get_version(
	// Output values, 
	string&	version) = 0;

    virtual XrlCmdError rib_0_1_add_igp_table4(
	// Input values, 
	const string&	protocol, 
	const bool&	unicast, 
	const bool&	multicast) = 0;

    virtual XrlCmdError rib_0_1_add_igp_table6(
	// Input values, 
	const string&	protocol, 
	const bool&	unicast, 
	const bool&	multicast) = 0;

    virtual XrlCmdError rib_0_1_delete_igp_table4(
	// Input values, 
	const string&	protocol, 
	const bool&	unicast, 
	const bool&	multicast) = 0;

    virtual XrlCmdError rib_0_1_delete_igp_table6(
	// Input values, 
	const string&	protocol, 
	const bool&	unicast, 
	const bool&	multicast) = 0;

    virtual XrlCmdError rib_0_1_add_egp_table4(
	// Input values, 
	const string&	protocol, 
	const bool&	unicast, 
	const bool&	multicast) = 0;

    virtual XrlCmdError rib_0_1_add_egp_table6(
	// Input values, 
	const string&	protocol, 
	const bool&	unicast, 
	const bool&	multicast) = 0;

    virtual XrlCmdError rib_0_1_delete_egp_table4(
	// Input values, 
	const string&	protocol, 
	const bool&	unicast, 
	const bool&	multicast) = 0;

    virtual XrlCmdError rib_0_1_delete_egp_table6(
	// Input values, 
	const string&	protocol, 
	const bool&	unicast, 
	const bool&	multicast) = 0;

    virtual XrlCmdError rib_0_1_add_route4(
	// Input values, 
	const string&	protocol, 
	const bool&	unicast, 
	const bool&	multicast, 
	const IPv4Net&	network, 
	const IPv4&	nexthop, 
	const uint32_t&	metric) = 0;

    virtual XrlCmdError rib_0_1_add_route6(
	// Input values, 
	const string&	protocol, 
	const bool&	unicast, 
	const bool&	multicast, 
	const IPv6Net&	network, 
	const IPv6&	nexthop, 
	const uint32_t&	metric) = 0;

    virtual XrlCmdError rib_0_1_replace_route4(
	// Input values, 
	const string&	protocol, 
	const bool&	unicast, 
	const bool&	multicast, 
	const IPv4Net&	network, 
	const IPv4&	nexthop, 
	const uint32_t&	metric) = 0;

    virtual XrlCmdError rib_0_1_replace_route6(
	// Input values, 
	const string&	protocol, 
	const bool&	unicast, 
	const bool&	multicast, 
	const IPv6Net&	network, 
	const IPv6&	nexthop, 
	const uint32_t&	metric) = 0;

    virtual XrlCmdError rib_0_1_delete_route4(
	// Input values, 
	const string&	protocol, 
	const bool&	unicast, 
	const bool&	multicast, 
	const IPv4Net&	network) = 0;

    virtual XrlCmdError rib_0_1_delete_route6(
	// Input values, 
	const string&	protocol, 
	const bool&	unicast, 
	const bool&	multicast, 
	const IPv6Net&	network) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Lookup nexthop.
     *  
     *  @param addr address to lookup.
     *  
     *  @param unicast look in unicast RIB.
     *  
     *  @param multicast look in multicast RIB.
     *  
     *  @param nexthop contains the resolved nexthop if successful, IPv4::ZERO
     *  otherwise. It is an error for the unicast and multicast fields to both
     *  be true or both false.
     */
    virtual XrlCmdError rib_0_1_lookup_route4(
	// Input values, 
	const IPv4&	addr, 
	const bool&	unicast, 
	const bool&	multicast, 
	// Output values, 
	IPv4&	nexthop) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Lookup nexthop.
     *  
     *  @param addr address to lookup.
     *  
     *  @param unicast look in unicast RIB.
     *  
     *  @param multicast look in multicast RIB.
     *  
     *  @param nexthop contains the resolved nexthop if successful, IPv6::ZERO
     *  otherwise. It is an error for the unicast and multicast fields to both
     *  be true or both false.
     */
    virtual XrlCmdError rib_0_1_lookup_route6(
	// Input values, 
	const IPv6&	addr, 
	const bool&	unicast, 
	const bool&	multicast, 
	// Output values, 
	IPv6&	nexthop) = 0;

    virtual XrlCmdError rib_0_1_new_vif(
	// Input values, 
	const string&	name) = 0;

    virtual XrlCmdError rib_0_1_add_vif_addr4(
	// Input values, 
	const string&	name, 
	const IPv4&	addr, 
	const IPv4Net&	subnet) = 0;

    virtual XrlCmdError rib_0_1_add_vif_addr6(
	// Input values, 
	const string&	name, 
	const IPv6&	addr, 
	const IPv6Net&	subnet) = 0;

    virtual XrlCmdError rib_0_1_redist_enable4(
	// Input values, 
	const string&	from, 
	const string&	to, 
	const bool&	unicast, 
	const bool&	multicast) = 0;

    virtual XrlCmdError rib_0_1_redist_enable6(
	// Input values, 
	const string&	from, 
	const string&	to, 
	const bool&	unicast, 
	const bool&	multicast) = 0;

    virtual XrlCmdError rib_0_1_redist_disable4(
	// Input values, 
	const string&	from, 
	const string&	to, 
	const bool&	unicast, 
	const bool&	multicast) = 0;

    virtual XrlCmdError rib_0_1_redist_disable6(
	// Input values, 
	const string&	from, 
	const string&	to, 
	const bool&	unicast, 
	const bool&	multicast) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Register an interest in a route
     *  
     *  @param target the name of the XRL module to notify when the information
     *  returned by this call becomes invalid.
     *  
     *  @param addr address of interest
     *  
     *  @param resolves returns whether or not the address resolves to a route
     *  that can be used for forwarding.
     *  
     *  @param base_addr returns the address of interest (actually the base
     *  address of the subnet covered by addr/prefix).
     *  
     *  @param prefix prefix returns the prefix that the registration covers.
     *  This response applies to all addresses in addr/prefix.
     *  
     *  @param realprefix realprefix returns the actual prefix of the route
     *  that will be used to route addr. If realprefix is not the same as
     *  prefix, this is because there are some more specific routes that
     *  overlap addr/realprefix. realprefix is primarily given for debugging
     *  reasons.
     *  
     *  @param nexthop returns the address of the next hop for packets sent to
     *  addr
     *  
     *  @param metric returns the IGP metric for this route
     */
    virtual XrlCmdError rib_0_1_register_interest4(
	// Input values, 
	const string&	target, 
	const IPv4&	addr, 
	// Output values, 
	bool&	resolves, 
	IPv4&	base_addr, 
	uint32_t&	prefix, 
	uint32_t&	realprefix, 
	IPv4&	nexthop, 
	uint32_t&	metric) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  De-register an interest in a route
     *  
     *  @param target the name of the XRL module that registered the interest
     *  
     *  @param addr the address of the previous registered interest. addr
     *  should be the base address of the add/prefix subnet.
     *  
     *  @param prefix the prefix length of the registered interest, as given in
     *  the response from register_interest.
     */
    virtual XrlCmdError rib_0_1_deregister_interest4(
	// Input values, 
	const string&	target, 
	const IPv4&	addr, 
	const uint32_t&	prefix) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Register an interest in a route
     *  
     *  @param target the name of the XRL module to notify when the information
     *  returned by this call becomes invalid.
     *  
     *  @param addr address of interest
     *  
     *  @param resolves returns whether or not the address resolves to a route
     *  that can be used for forwarding.
     *  
     *  @param base_addr returns the address of interest (actually the base
     *  address of the subnet covered by addr/prefix).
     *  
     *  @param prefix prefix returns the prefix that the registration covers.
     *  This response applies to all addresses in addr/prefix.
     *  
     *  @param realprefix realprefix returns the actual prefix of the route
     *  that will be used to route addr. If realprefix is not the same as
     *  prefix, this is because there are some more specific routes that
     *  overlap addr/realprefix. realprefix is primarily given for debugging
     *  reasons.
     *  
     *  @param nexthop returns the address of the next hop for packets sent to
     *  addr
     *  
     *  @param metric returns the IGP metric for this route
     */
    virtual XrlCmdError rib_0_1_register_interest6(
	// Input values, 
	const string&	target, 
	const IPv6&	addr, 
	// Output values, 
	bool&	resolves, 
	IPv6&	base_addr, 
	uint32_t&	prefix, 
	uint32_t&	realprefix, 
	IPv6&	nexthop, 
	uint32_t&	metric) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  De-register an interest in a route
     *  
     *  @param target the name of the XRL module that registered the interest
     *  
     *  @param addr the address of the previous registered interest. addr
     *  should be the base address of the add/prefix subnet.
     *  
     *  @param prefix the prefix length of the registered interest, as given in
     *  the response from register_interest.
     */
    virtual XrlCmdError rib_0_1_deregister_interest6(
	// Input values, 
	const string&	target, 
	const IPv6&	addr, 
	const uint32_t&	prefix) = 0;

    virtual XrlCmdError fea_ifmgr_client_0_1_interface_update(
	// Input values, 
	const string&	ifname, 
	const uint32_t&	event) = 0;

    virtual XrlCmdError fea_ifmgr_client_0_1_vif_update(
	// Input values, 
	const string&	ifname, 
	const string&	vifname, 
	const uint32_t&	event) = 0;

    virtual XrlCmdError fea_ifmgr_client_0_1_vifaddr4_update(
	// Input values, 
	const string&	ifname, 
	const string&	vifname, 
	const IPv4&	addr, 
	const uint32_t&	event) = 0;

    virtual XrlCmdError fea_ifmgr_client_0_1_vifaddr6_update(
	// Input values, 
	const string&	ifname, 
	const string&	vifname, 
	const IPv6&	addr, 
	const uint32_t&	event) = 0;

private:
    const XrlCmdError handle_common_0_1_get_target_name(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_common_0_1_get_version(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_rib_0_1_add_igp_table4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_rib_0_1_add_igp_table6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_rib_0_1_delete_igp_table4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_rib_0_1_delete_igp_table6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_rib_0_1_add_egp_table4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_rib_0_1_add_egp_table6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_rib_0_1_delete_egp_table4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_rib_0_1_delete_egp_table6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_rib_0_1_add_route4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_rib_0_1_add_route6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_rib_0_1_replace_route4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_rib_0_1_replace_route6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_rib_0_1_delete_route4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_rib_0_1_delete_route6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_rib_0_1_lookup_route4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_rib_0_1_lookup_route6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_rib_0_1_new_vif(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_rib_0_1_add_vif_addr4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_rib_0_1_add_vif_addr6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_rib_0_1_redist_enable4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_rib_0_1_redist_enable6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_rib_0_1_redist_disable4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_rib_0_1_redist_disable6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_rib_0_1_register_interest4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_rib_0_1_deregister_interest4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_rib_0_1_register_interest6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_rib_0_1_deregister_interest6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_fea_ifmgr_client_0_1_interface_update(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_fea_ifmgr_client_0_1_vif_update(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_fea_ifmgr_client_0_1_vifaddr4_update(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_fea_ifmgr_client_0_1_vifaddr6_update(const Xrl& x, XrlArgs* a);

    void add_handlers()
    {
	if (_cmds->add_handler("common/0.1/get_target_name", 
	    callback(this, &XrlRibTargetBase::handle_common_0_1_get_target_name)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/common/0.1/get_target_name");
	}
	if (_cmds->add_handler("common/0.1/get_version", 
	    callback(this, &XrlRibTargetBase::handle_common_0_1_get_version)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/common/0.1/get_version");
	}
	if (_cmds->add_handler("rib/0.1/add_igp_table4", 
	    callback(this, &XrlRibTargetBase::handle_rib_0_1_add_igp_table4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/rib/0.1/add_igp_table4");
	}
	if (_cmds->add_handler("rib/0.1/add_igp_table6", 
	    callback(this, &XrlRibTargetBase::handle_rib_0_1_add_igp_table6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/rib/0.1/add_igp_table6");
	}
	if (_cmds->add_handler("rib/0.1/delete_igp_table4", 
	    callback(this, &XrlRibTargetBase::handle_rib_0_1_delete_igp_table4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/rib/0.1/delete_igp_table4");
	}
	if (_cmds->add_handler("rib/0.1/delete_igp_table6", 
	    callback(this, &XrlRibTargetBase::handle_rib_0_1_delete_igp_table6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/rib/0.1/delete_igp_table6");
	}
	if (_cmds->add_handler("rib/0.1/add_egp_table4", 
	    callback(this, &XrlRibTargetBase::handle_rib_0_1_add_egp_table4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/rib/0.1/add_egp_table4");
	}
	if (_cmds->add_handler("rib/0.1/add_egp_table6", 
	    callback(this, &XrlRibTargetBase::handle_rib_0_1_add_egp_table6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/rib/0.1/add_egp_table6");
	}
	if (_cmds->add_handler("rib/0.1/delete_egp_table4", 
	    callback(this, &XrlRibTargetBase::handle_rib_0_1_delete_egp_table4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/rib/0.1/delete_egp_table4");
	}
	if (_cmds->add_handler("rib/0.1/delete_egp_table6", 
	    callback(this, &XrlRibTargetBase::handle_rib_0_1_delete_egp_table6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/rib/0.1/delete_egp_table6");
	}
	if (_cmds->add_handler("rib/0.1/add_route4", 
	    callback(this, &XrlRibTargetBase::handle_rib_0_1_add_route4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/rib/0.1/add_route4");
	}
	if (_cmds->add_handler("rib/0.1/add_route6", 
	    callback(this, &XrlRibTargetBase::handle_rib_0_1_add_route6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/rib/0.1/add_route6");
	}
	if (_cmds->add_handler("rib/0.1/replace_route4", 
	    callback(this, &XrlRibTargetBase::handle_rib_0_1_replace_route4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/rib/0.1/replace_route4");
	}
	if (_cmds->add_handler("rib/0.1/replace_route6", 
	    callback(this, &XrlRibTargetBase::handle_rib_0_1_replace_route6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/rib/0.1/replace_route6");
	}
	if (_cmds->add_handler("rib/0.1/delete_route4", 
	    callback(this, &XrlRibTargetBase::handle_rib_0_1_delete_route4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/rib/0.1/delete_route4");
	}
	if (_cmds->add_handler("rib/0.1/delete_route6", 
	    callback(this, &XrlRibTargetBase::handle_rib_0_1_delete_route6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/rib/0.1/delete_route6");
	}
	if (_cmds->add_handler("rib/0.1/lookup_route4", 
	    callback(this, &XrlRibTargetBase::handle_rib_0_1_lookup_route4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/rib/0.1/lookup_route4");
	}
	if (_cmds->add_handler("rib/0.1/lookup_route6", 
	    callback(this, &XrlRibTargetBase::handle_rib_0_1_lookup_route6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/rib/0.1/lookup_route6");
	}
	if (_cmds->add_handler("rib/0.1/new_vif", 
	    callback(this, &XrlRibTargetBase::handle_rib_0_1_new_vif)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/rib/0.1/new_vif");
	}
	if (_cmds->add_handler("rib/0.1/add_vif_addr4", 
	    callback(this, &XrlRibTargetBase::handle_rib_0_1_add_vif_addr4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/rib/0.1/add_vif_addr4");
	}
	if (_cmds->add_handler("rib/0.1/add_vif_addr6", 
	    callback(this, &XrlRibTargetBase::handle_rib_0_1_add_vif_addr6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/rib/0.1/add_vif_addr6");
	}
	if (_cmds->add_handler("rib/0.1/redist_enable4", 
	    callback(this, &XrlRibTargetBase::handle_rib_0_1_redist_enable4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/rib/0.1/redist_enable4");
	}
	if (_cmds->add_handler("rib/0.1/redist_enable6", 
	    callback(this, &XrlRibTargetBase::handle_rib_0_1_redist_enable6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/rib/0.1/redist_enable6");
	}
	if (_cmds->add_handler("rib/0.1/redist_disable4", 
	    callback(this, &XrlRibTargetBase::handle_rib_0_1_redist_disable4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/rib/0.1/redist_disable4");
	}
	if (_cmds->add_handler("rib/0.1/redist_disable6", 
	    callback(this, &XrlRibTargetBase::handle_rib_0_1_redist_disable6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/rib/0.1/redist_disable6");
	}
	if (_cmds->add_handler("rib/0.1/register_interest4", 
	    callback(this, &XrlRibTargetBase::handle_rib_0_1_register_interest4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/rib/0.1/register_interest4");
	}
	if (_cmds->add_handler("rib/0.1/deregister_interest4", 
	    callback(this, &XrlRibTargetBase::handle_rib_0_1_deregister_interest4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/rib/0.1/deregister_interest4");
	}
	if (_cmds->add_handler("rib/0.1/register_interest6", 
	    callback(this, &XrlRibTargetBase::handle_rib_0_1_register_interest6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/rib/0.1/register_interest6");
	}
	if (_cmds->add_handler("rib/0.1/deregister_interest6", 
	    callback(this, &XrlRibTargetBase::handle_rib_0_1_deregister_interest6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/rib/0.1/deregister_interest6");
	}
	if (_cmds->add_handler("fea_ifmgr_client/0.1/interface_update", 
	    callback(this, &XrlRibTargetBase::handle_fea_ifmgr_client_0_1_interface_update)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/fea_ifmgr_client/0.1/interface_update");
	}
	if (_cmds->add_handler("fea_ifmgr_client/0.1/vif_update", 
	    callback(this, &XrlRibTargetBase::handle_fea_ifmgr_client_0_1_vif_update)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/fea_ifmgr_client/0.1/vif_update");
	}
	if (_cmds->add_handler("fea_ifmgr_client/0.1/vifaddr4_update", 
	    callback(this, &XrlRibTargetBase::handle_fea_ifmgr_client_0_1_vifaddr4_update)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/fea_ifmgr_client/0.1/vifaddr4_update");
	}
	if (_cmds->add_handler("fea_ifmgr_client/0.1/vifaddr6_update", 
	    callback(this, &XrlRibTargetBase::handle_fea_ifmgr_client_0_1_vifaddr6_update)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rib/fea_ifmgr_client/0.1/vifaddr6_update");
	}
    }

    void remove_handlers()
    {
	_cmds->remove_handler("common/0.1/get_target_name");
	_cmds->remove_handler("common/0.1/get_version");
	_cmds->remove_handler("rib/0.1/add_igp_table4");
	_cmds->remove_handler("rib/0.1/add_igp_table6");
	_cmds->remove_handler("rib/0.1/delete_igp_table4");
	_cmds->remove_handler("rib/0.1/delete_igp_table6");
	_cmds->remove_handler("rib/0.1/add_egp_table4");
	_cmds->remove_handler("rib/0.1/add_egp_table6");
	_cmds->remove_handler("rib/0.1/delete_egp_table4");
	_cmds->remove_handler("rib/0.1/delete_egp_table6");
	_cmds->remove_handler("rib/0.1/add_route4");
	_cmds->remove_handler("rib/0.1/add_route6");
	_cmds->remove_handler("rib/0.1/replace_route4");
	_cmds->remove_handler("rib/0.1/replace_route6");
	_cmds->remove_handler("rib/0.1/delete_route4");
	_cmds->remove_handler("rib/0.1/delete_route6");
	_cmds->remove_handler("rib/0.1/lookup_route4");
	_cmds->remove_handler("rib/0.1/lookup_route6");
	_cmds->remove_handler("rib/0.1/new_vif");
	_cmds->remove_handler("rib/0.1/add_vif_addr4");
	_cmds->remove_handler("rib/0.1/add_vif_addr6");
	_cmds->remove_handler("rib/0.1/redist_enable4");
	_cmds->remove_handler("rib/0.1/redist_enable6");
	_cmds->remove_handler("rib/0.1/redist_disable4");
	_cmds->remove_handler("rib/0.1/redist_disable6");
	_cmds->remove_handler("rib/0.1/register_interest4");
	_cmds->remove_handler("rib/0.1/deregister_interest4");
	_cmds->remove_handler("rib/0.1/register_interest6");
	_cmds->remove_handler("rib/0.1/deregister_interest6");
	_cmds->remove_handler("fea_ifmgr_client/0.1/interface_update");
	_cmds->remove_handler("fea_ifmgr_client/0.1/vif_update");
	_cmds->remove_handler("fea_ifmgr_client/0.1/vifaddr4_update");
	_cmds->remove_handler("fea_ifmgr_client/0.1/vifaddr6_update");
    }
};

#endif /* __XRL_INTERFACES_RIB_BASE_HH__ */
