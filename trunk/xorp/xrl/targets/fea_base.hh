/*
 * Copyright (c) 2002 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by '../scripts/tgt-gen'.
 *
 * $XORP: xorp/xrl/targets/fea_base.hh,v 1.4 2003/01/28 00:37:56 hodson Exp $
 */


#ifndef __XRL_INTERFACES_FEA_BASE_HH__
#define __XRL_INTERFACES_FEA_BASE_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XrlFeaTarget"

#include "libxorp/xlog.h"
#include "libxipc/xrl_cmd_map.hh"

class XrlFeaTargetBase {
protected:
    XrlCmdMap* _cmds;
    
public:
    XrlFeaTargetBase(XrlCmdMap* cmds) : _cmds(cmds) { add_handlers(); }
    virtual ~XrlFeaTargetBase() { remove_handlers(); }

    inline const string& name() const { return _cmds->name(); }
    inline const char* version() const { return "fea/0.0"; }

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

    virtual XrlCmdError ifmgr_0_1_get_all_interface_names(
	// Output values, 
	XrlAtomList&	ifnames) = 0;

    virtual XrlCmdError ifmgr_0_1_get_configured_interface_names(
	// Output values, 
	XrlAtomList&	ifnames) = 0;

    virtual XrlCmdError ifmgr_0_1_get_all_vif_names(
	// Input values, 
	const string&	ifname, 
	// Output values, 
	XrlAtomList&	vifs) = 0;

    virtual XrlCmdError ifmgr_0_1_get_configured_vif_names(
	// Input values, 
	const string&	ifname, 
	// Output values, 
	XrlAtomList&	vifs) = 0;

    virtual XrlCmdError ifmgr_0_1_get_vif_flags4(
	// Input values, 
	const string&	ifname, 
	const string&	vif, 
	const IPv4&	address, 
	// Output values, 
	bool&	enabled, 
	bool&	broadcast, 
	bool&	loopback, 
	bool&	point_to_point, 
	bool&	multicast) = 0;

    virtual XrlCmdError ifmgr_0_1_get_vif_flags6(
	// Input values, 
	const string&	ifname, 
	const string&	vif, 
	const IPv6&	address, 
	// Output values, 
	bool&	enabled, 
	bool&	loopback, 
	bool&	point_to_point, 
	bool&	multicast) = 0;

    virtual XrlCmdError ifmgr_0_1_get_all_vif_addresses4(
	// Input values, 
	const string&	ifname, 
	const string&	vif, 
	// Output values, 
	XrlAtomList&	addresses) = 0;

    virtual XrlCmdError ifmgr_0_1_get_configured_vif_addresses4(
	// Input values, 
	const string&	ifname, 
	const string&	vif, 
	// Output values, 
	XrlAtomList&	addresses) = 0;

    virtual XrlCmdError ifmgr_0_1_get_all_vif_addresses6(
	// Input values, 
	const string&	ifname, 
	const string&	vif, 
	// Output values, 
	XrlAtomList&	addresses) = 0;

    virtual XrlCmdError ifmgr_0_1_get_configured_vif_addresses6(
	// Input values, 
	const string&	ifname, 
	const string&	vif, 
	// Output values, 
	XrlAtomList&	addresses) = 0;

    virtual XrlCmdError ifmgr_0_1_get_interface_enabled(
	// Input values, 
	const string&	ifname, 
	// Output values, 
	bool&	enabled) = 0;

    virtual XrlCmdError ifmgr_0_1_get_mac(
	// Input values, 
	const string&	ifname, 
	// Output values, 
	Mac&	mac) = 0;

    virtual XrlCmdError ifmgr_0_1_get_mtu(
	// Input values, 
	const string&	ifname, 
	// Output values, 
	uint32_t&	mtu) = 0;

    virtual XrlCmdError ifmgr_0_1_get_vif_enabled(
	// Input values, 
	const string&	ifname, 
	const string&	vif, 
	// Output values, 
	bool&	enabled) = 0;

    virtual XrlCmdError ifmgr_0_1_get_prefix4(
	// Input values, 
	const string&	ifname, 
	const string&	vif, 
	const IPv4&	address, 
	// Output values, 
	uint32_t&	prefix) = 0;

    virtual XrlCmdError ifmgr_0_1_get_broadcast4(
	// Input values, 
	const string&	ifname, 
	const string&	vif, 
	const IPv4&	address, 
	// Output values, 
	IPv4&	broadcast) = 0;

    virtual XrlCmdError ifmgr_0_1_get_endpoint4(
	// Input values, 
	const string&	ifname, 
	const string&	vif, 
	const IPv4&	address, 
	// Output values, 
	IPv4&	endpoint) = 0;

    virtual XrlCmdError ifmgr_0_1_get_prefix6(
	// Input values, 
	const string&	ifname, 
	const string&	vif, 
	const IPv6&	address, 
	// Output values, 
	uint32_t&	prefix) = 0;

    virtual XrlCmdError ifmgr_0_1_get_endpoint6(
	// Input values, 
	const string&	ifname, 
	const string&	vif, 
	const IPv6&	address, 
	// Output values, 
	IPv6&	endpoint) = 0;

    virtual XrlCmdError ifmgr_0_1_start_transaction(
	// Output values, 
	uint32_t&	tid) = 0;

    virtual XrlCmdError ifmgr_0_1_commit_transaction(
	// Input values, 
	const uint32_t&	tid) = 0;

    virtual XrlCmdError ifmgr_0_1_abort_transaction(
	// Input values, 
	const uint32_t&	tid) = 0;

    virtual XrlCmdError ifmgr_0_1_create_interface(
	// Input values, 
	const uint32_t&	tid, 
	const string&	ifname) = 0;

    virtual XrlCmdError ifmgr_0_1_delete_interface(
	// Input values, 
	const uint32_t&	tid, 
	const string&	ifname) = 0;

    virtual XrlCmdError ifmgr_0_1_set_interface_enabled(
	// Input values, 
	const uint32_t&	tid, 
	const string&	ifname, 
	const bool&	enabled) = 0;

    virtual XrlCmdError ifmgr_0_1_set_mac(
	// Input values, 
	const uint32_t&	tid, 
	const string&	ifname, 
	const Mac&	mac) = 0;

    virtual XrlCmdError ifmgr_0_1_set_mtu(
	// Input values, 
	const uint32_t&	tid, 
	const string&	ifname, 
	const uint32_t&	mtu) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Create a vif
     *  
     *  @param ifname the name of the physical interface associated with the
     *  new vif.
     *  
     *  @param vif name for new vif, must be unique across all the vifs in the
     *  system.
     */
    virtual XrlCmdError ifmgr_0_1_create_vif(
	// Input values, 
	const uint32_t&	tid, 
	const string&	ifname, 
	const string&	vif) = 0;

    virtual XrlCmdError ifmgr_0_1_delete_vif(
	// Input values, 
	const uint32_t&	tid, 
	const string&	ifname, 
	const string&	vif) = 0;

    virtual XrlCmdError ifmgr_0_1_set_vif_enabled(
	// Input values, 
	const uint32_t&	tid, 
	const string&	ifname, 
	const string&	vif, 
	const bool&	enabled) = 0;

    virtual XrlCmdError ifmgr_0_1_create_address4(
	// Input values, 
	const uint32_t&	tid, 
	const string&	ifname, 
	const string&	vif, 
	const IPv4&	address) = 0;

    virtual XrlCmdError ifmgr_0_1_delete_address4(
	// Input values, 
	const uint32_t&	tid, 
	const string&	ifname, 
	const string&	vif, 
	const IPv4&	address) = 0;

    virtual XrlCmdError ifmgr_0_1_set_address_enabled4(
	// Input values, 
	const uint32_t&	tid, 
	const string&	ifname, 
	const string&	vif, 
	const IPv4&	address, 
	const bool&	enabled) = 0;

    virtual XrlCmdError ifmgr_0_1_get_address_enabled4(
	// Input values, 
	const string&	ifname, 
	const string&	vif, 
	const IPv4&	address, 
	// Output values, 
	bool&	enabled) = 0;

    virtual XrlCmdError ifmgr_0_1_set_prefix4(
	// Input values, 
	const uint32_t&	tid, 
	const string&	ifname, 
	const string&	vif, 
	const IPv4&	address, 
	const uint32_t&	prefix) = 0;

    virtual XrlCmdError ifmgr_0_1_set_broadcast4(
	// Input values, 
	const uint32_t&	tid, 
	const string&	ifname, 
	const string&	vif, 
	const IPv4&	address, 
	const IPv4&	broadcast) = 0;

    virtual XrlCmdError ifmgr_0_1_set_endpoint4(
	// Input values, 
	const uint32_t&	tid, 
	const string&	ifname, 
	const string&	vif, 
	const IPv4&	address, 
	const IPv4&	endpoint) = 0;

    virtual XrlCmdError ifmgr_0_1_create_address6(
	// Input values, 
	const uint32_t&	tid, 
	const string&	ifname, 
	const string&	vif, 
	const IPv6&	address) = 0;

    virtual XrlCmdError ifmgr_0_1_delete_address6(
	// Input values, 
	const uint32_t&	tid, 
	const string&	ifname, 
	const string&	vif, 
	const IPv6&	address) = 0;

    virtual XrlCmdError ifmgr_0_1_set_address_enabled6(
	// Input values, 
	const uint32_t&	tid, 
	const string&	ifname, 
	const string&	vif, 
	const IPv6&	address, 
	const bool&	enabled) = 0;

    virtual XrlCmdError ifmgr_0_1_get_address_enabled6(
	// Input values, 
	const string&	ifname, 
	const string&	vif, 
	const IPv6&	address, 
	// Output values, 
	bool&	enabled) = 0;

    virtual XrlCmdError ifmgr_0_1_set_prefix6(
	// Input values, 
	const uint32_t&	tid, 
	const string&	ifname, 
	const string&	vif, 
	const IPv6&	address, 
	const uint32_t&	prefix) = 0;

    virtual XrlCmdError ifmgr_0_1_set_endpoint6(
	// Input values, 
	const uint32_t&	tid, 
	const string&	ifname, 
	const string&	vif, 
	const IPv6&	address, 
	const IPv6&	endpoint) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Register network interface observer
     *  
     *  @param clientname name of xrl entity supporting fea_ifmgr_client.xif
     *  methods.
     */
    virtual XrlCmdError ifmgr_0_1_register_client(
	// Input values, 
	const string&	clientname) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Unregister network interface observer. This method is not strictly
     *  necessary, the fea will remove the interface observer from it's list of
     *  known observers if interface update XRLs fail.
     */
    virtual XrlCmdError ifmgr_0_1_unregister_client(
	// Input values, 
	const string&	clientname) = 0;

    virtual XrlCmdError fti_0_1_start_transaction(
	// Output values, 
	uint32_t&	tid) = 0;

    virtual XrlCmdError fti_0_1_commit_transaction(
	// Input values, 
	const uint32_t&	tid) = 0;

    virtual XrlCmdError fti_0_1_abort_transaction(
	// Input values, 
	const uint32_t&	tid) = 0;

    virtual XrlCmdError fti_0_1_add_entry4(
	// Input values, 
	const uint32_t&	tid, 
	const IPv4Net&	dst, 
	const IPv4&	gateway, 
	const string&	ifname, 
	const string&	vifname) = 0;

    virtual XrlCmdError fti_0_1_delete_entry4(
	// Input values, 
	const uint32_t&	tid, 
	const IPv4Net&	dst) = 0;

    virtual XrlCmdError fti_0_1_add_entry6(
	// Input values, 
	const uint32_t&	tid, 
	const IPv6Net&	dst, 
	const IPv6&	gateway, 
	const string&	ifname, 
	const string&	vifname) = 0;

    virtual XrlCmdError fti_0_1_delete_entry6(
	// Input values, 
	const uint32_t&	tid, 
	const IPv6Net&	dst) = 0;

    virtual XrlCmdError fti_0_1_delete_all_entries(
	// Input values, 
	const uint32_t&	tid) = 0;

    virtual XrlCmdError fti_0_1_delete_all_entries4(
	// Input values, 
	const uint32_t&	tid) = 0;

    virtual XrlCmdError fti_0_1_delete_all_entries6(
	// Input values, 
	const uint32_t&	tid) = 0;

    virtual XrlCmdError fti_0_1_lookup_route4(
	// Input values, 
	const IPv4&	dst, 
	// Output values, 
	IPv4Net&	netmask, 
	IPv4&	gateway, 
	string&	ifname, 
	string&	vifname) = 0;

    virtual XrlCmdError fti_0_1_lookup_entry4(
	// Input values, 
	const IPv4Net&	dst, 
	// Output values, 
	IPv4&	gateway, 
	string&	ifname, 
	string&	vifname) = 0;

    virtual XrlCmdError fti_0_1_lookup_route6(
	// Input values, 
	const IPv6&	dst, 
	// Output values, 
	IPv6Net&	netmask, 
	IPv6&	gateway, 
	string&	ifname, 
	string&	vifname) = 0;

    virtual XrlCmdError fti_0_1_lookup_entry6(
	// Input values, 
	const IPv6Net&	dst, 
	// Output values, 
	IPv6&	gateway, 
	string&	ifname, 
	string&	vifname) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Send a packet on a raw socket.
     */
    virtual XrlCmdError raw_packet_0_1_send4(
	// Input values, 
	const IPv4&	src_address, 
	const IPv4&	dst_address, 
	const string&	vif_name, 
	const uint32_t&	proto, 
	const uint32_t&	ttl, 
	const uint32_t&	tos, 
	const vector<uint8_t>&	options, 
	const vector<uint8_t>&	payload) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Send raw packet. Checksum is computed and applied before transmission.
     *  All the fields within the IPv4 header must be in network order.
     */
    virtual XrlCmdError raw_packet_0_1_send_raw4(
	// Input values, 
	const string&	vif_name, 
	const vector<uint8_t>&	packet) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Register to receive packets. The receiver is expected to support
     *  raw_socket_client/0.1 interface.
     */
    virtual XrlCmdError raw_packet_0_1_register_vif_receiver(
	// Input values, 
	const string&	router_name, 
	const string&	if_name, 
	const string&	vif_name, 
	const uint32_t&	proto) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Unregister stop receiving packets.
     *  
     *  @param proto Protocol number that the receiver is interested in.
     */
    virtual XrlCmdError raw_packet_0_1_unregister_vif_receiver(
	// Input values, 
	const string&	router_name, 
	const string&	if_name, 
	const string&	vif_name, 
	const uint32_t&	proto) = 0;

private:
    const XrlCmdError handle_common_0_1_get_target_name(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_common_0_1_get_version(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_get_all_interface_names(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_get_configured_interface_names(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_get_all_vif_names(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_get_configured_vif_names(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_get_vif_flags4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_get_vif_flags6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_get_all_vif_addresses4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_get_configured_vif_addresses4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_get_all_vif_addresses6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_get_configured_vif_addresses6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_get_interface_enabled(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_get_mac(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_get_mtu(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_get_vif_enabled(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_get_prefix4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_get_broadcast4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_get_endpoint4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_get_prefix6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_get_endpoint6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_start_transaction(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_commit_transaction(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_abort_transaction(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_create_interface(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_delete_interface(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_set_interface_enabled(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_set_mac(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_set_mtu(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_create_vif(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_delete_vif(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_set_vif_enabled(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_create_address4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_delete_address4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_set_address_enabled4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_get_address_enabled4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_set_prefix4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_set_broadcast4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_set_endpoint4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_create_address6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_delete_address6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_set_address_enabled6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_get_address_enabled6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_set_prefix6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_set_endpoint6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_register_client(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_ifmgr_0_1_unregister_client(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_fti_0_1_start_transaction(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_fti_0_1_commit_transaction(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_fti_0_1_abort_transaction(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_fti_0_1_add_entry4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_fti_0_1_delete_entry4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_fti_0_1_add_entry6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_fti_0_1_delete_entry6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_fti_0_1_delete_all_entries(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_fti_0_1_delete_all_entries4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_fti_0_1_delete_all_entries6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_fti_0_1_lookup_route4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_fti_0_1_lookup_entry4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_fti_0_1_lookup_route6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_fti_0_1_lookup_entry6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_raw_packet_0_1_send4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_raw_packet_0_1_send_raw4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_raw_packet_0_1_register_vif_receiver(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_raw_packet_0_1_unregister_vif_receiver(const Xrl& x, XrlArgs* a);

    void add_handlers()
    {
	if (_cmds->add_handler("common/0.1/get_target_name", 
	    callback(this, &XrlFeaTargetBase::handle_common_0_1_get_target_name)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/common/0.1/get_target_name");
	}
	if (_cmds->add_handler("common/0.1/get_version", 
	    callback(this, &XrlFeaTargetBase::handle_common_0_1_get_version)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/common/0.1/get_version");
	}
	if (_cmds->add_handler("ifmgr/0.1/get_all_interface_names", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_get_all_interface_names)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/get_all_interface_names");
	}
	if (_cmds->add_handler("ifmgr/0.1/get_configured_interface_names", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_get_configured_interface_names)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/get_configured_interface_names");
	}
	if (_cmds->add_handler("ifmgr/0.1/get_all_vif_names", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_get_all_vif_names)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/get_all_vif_names");
	}
	if (_cmds->add_handler("ifmgr/0.1/get_configured_vif_names", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_get_configured_vif_names)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/get_configured_vif_names");
	}
	if (_cmds->add_handler("ifmgr/0.1/get_vif_flags4", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_get_vif_flags4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/get_vif_flags4");
	}
	if (_cmds->add_handler("ifmgr/0.1/get_vif_flags6", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_get_vif_flags6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/get_vif_flags6");
	}
	if (_cmds->add_handler("ifmgr/0.1/get_all_vif_addresses4", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_get_all_vif_addresses4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/get_all_vif_addresses4");
	}
	if (_cmds->add_handler("ifmgr/0.1/get_configured_vif_addresses4", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_get_configured_vif_addresses4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/get_configured_vif_addresses4");
	}
	if (_cmds->add_handler("ifmgr/0.1/get_all_vif_addresses6", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_get_all_vif_addresses6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/get_all_vif_addresses6");
	}
	if (_cmds->add_handler("ifmgr/0.1/get_configured_vif_addresses6", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_get_configured_vif_addresses6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/get_configured_vif_addresses6");
	}
	if (_cmds->add_handler("ifmgr/0.1/get_interface_enabled", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_get_interface_enabled)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/get_interface_enabled");
	}
	if (_cmds->add_handler("ifmgr/0.1/get_mac", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_get_mac)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/get_mac");
	}
	if (_cmds->add_handler("ifmgr/0.1/get_mtu", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_get_mtu)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/get_mtu");
	}
	if (_cmds->add_handler("ifmgr/0.1/get_vif_enabled", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_get_vif_enabled)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/get_vif_enabled");
	}
	if (_cmds->add_handler("ifmgr/0.1/get_prefix4", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_get_prefix4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/get_prefix4");
	}
	if (_cmds->add_handler("ifmgr/0.1/get_broadcast4", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_get_broadcast4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/get_broadcast4");
	}
	if (_cmds->add_handler("ifmgr/0.1/get_endpoint4", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_get_endpoint4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/get_endpoint4");
	}
	if (_cmds->add_handler("ifmgr/0.1/get_prefix6", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_get_prefix6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/get_prefix6");
	}
	if (_cmds->add_handler("ifmgr/0.1/get_endpoint6", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_get_endpoint6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/get_endpoint6");
	}
	if (_cmds->add_handler("ifmgr/0.1/start_transaction", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_start_transaction)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/start_transaction");
	}
	if (_cmds->add_handler("ifmgr/0.1/commit_transaction", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_commit_transaction)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/commit_transaction");
	}
	if (_cmds->add_handler("ifmgr/0.1/abort_transaction", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_abort_transaction)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/abort_transaction");
	}
	if (_cmds->add_handler("ifmgr/0.1/create_interface", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_create_interface)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/create_interface");
	}
	if (_cmds->add_handler("ifmgr/0.1/delete_interface", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_delete_interface)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/delete_interface");
	}
	if (_cmds->add_handler("ifmgr/0.1/set_interface_enabled", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_set_interface_enabled)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/set_interface_enabled");
	}
	if (_cmds->add_handler("ifmgr/0.1/set_mac", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_set_mac)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/set_mac");
	}
	if (_cmds->add_handler("ifmgr/0.1/set_mtu", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_set_mtu)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/set_mtu");
	}
	if (_cmds->add_handler("ifmgr/0.1/create_vif", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_create_vif)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/create_vif");
	}
	if (_cmds->add_handler("ifmgr/0.1/delete_vif", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_delete_vif)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/delete_vif");
	}
	if (_cmds->add_handler("ifmgr/0.1/set_vif_enabled", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_set_vif_enabled)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/set_vif_enabled");
	}
	if (_cmds->add_handler("ifmgr/0.1/create_address4", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_create_address4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/create_address4");
	}
	if (_cmds->add_handler("ifmgr/0.1/delete_address4", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_delete_address4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/delete_address4");
	}
	if (_cmds->add_handler("ifmgr/0.1/set_address_enabled4", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_set_address_enabled4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/set_address_enabled4");
	}
	if (_cmds->add_handler("ifmgr/0.1/get_address_enabled4", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_get_address_enabled4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/get_address_enabled4");
	}
	if (_cmds->add_handler("ifmgr/0.1/set_prefix4", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_set_prefix4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/set_prefix4");
	}
	if (_cmds->add_handler("ifmgr/0.1/set_broadcast4", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_set_broadcast4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/set_broadcast4");
	}
	if (_cmds->add_handler("ifmgr/0.1/set_endpoint4", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_set_endpoint4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/set_endpoint4");
	}
	if (_cmds->add_handler("ifmgr/0.1/create_address6", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_create_address6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/create_address6");
	}
	if (_cmds->add_handler("ifmgr/0.1/delete_address6", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_delete_address6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/delete_address6");
	}
	if (_cmds->add_handler("ifmgr/0.1/set_address_enabled6", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_set_address_enabled6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/set_address_enabled6");
	}
	if (_cmds->add_handler("ifmgr/0.1/get_address_enabled6", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_get_address_enabled6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/get_address_enabled6");
	}
	if (_cmds->add_handler("ifmgr/0.1/set_prefix6", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_set_prefix6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/set_prefix6");
	}
	if (_cmds->add_handler("ifmgr/0.1/set_endpoint6", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_set_endpoint6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/set_endpoint6");
	}
	if (_cmds->add_handler("ifmgr/0.1/register_client", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_register_client)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/register_client");
	}
	if (_cmds->add_handler("ifmgr/0.1/unregister_client", 
	    callback(this, &XrlFeaTargetBase::handle_ifmgr_0_1_unregister_client)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/ifmgr/0.1/unregister_client");
	}
	if (_cmds->add_handler("fti/0.1/start_transaction", 
	    callback(this, &XrlFeaTargetBase::handle_fti_0_1_start_transaction)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/fti/0.1/start_transaction");
	}
	if (_cmds->add_handler("fti/0.1/commit_transaction", 
	    callback(this, &XrlFeaTargetBase::handle_fti_0_1_commit_transaction)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/fti/0.1/commit_transaction");
	}
	if (_cmds->add_handler("fti/0.1/abort_transaction", 
	    callback(this, &XrlFeaTargetBase::handle_fti_0_1_abort_transaction)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/fti/0.1/abort_transaction");
	}
	if (_cmds->add_handler("fti/0.1/add_entry4", 
	    callback(this, &XrlFeaTargetBase::handle_fti_0_1_add_entry4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/fti/0.1/add_entry4");
	}
	if (_cmds->add_handler("fti/0.1/delete_entry4", 
	    callback(this, &XrlFeaTargetBase::handle_fti_0_1_delete_entry4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/fti/0.1/delete_entry4");
	}
	if (_cmds->add_handler("fti/0.1/add_entry6", 
	    callback(this, &XrlFeaTargetBase::handle_fti_0_1_add_entry6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/fti/0.1/add_entry6");
	}
	if (_cmds->add_handler("fti/0.1/delete_entry6", 
	    callback(this, &XrlFeaTargetBase::handle_fti_0_1_delete_entry6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/fti/0.1/delete_entry6");
	}
	if (_cmds->add_handler("fti/0.1/delete_all_entries", 
	    callback(this, &XrlFeaTargetBase::handle_fti_0_1_delete_all_entries)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/fti/0.1/delete_all_entries");
	}
	if (_cmds->add_handler("fti/0.1/delete_all_entries4", 
	    callback(this, &XrlFeaTargetBase::handle_fti_0_1_delete_all_entries4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/fti/0.1/delete_all_entries4");
	}
	if (_cmds->add_handler("fti/0.1/delete_all_entries6", 
	    callback(this, &XrlFeaTargetBase::handle_fti_0_1_delete_all_entries6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/fti/0.1/delete_all_entries6");
	}
	if (_cmds->add_handler("fti/0.1/lookup_route4", 
	    callback(this, &XrlFeaTargetBase::handle_fti_0_1_lookup_route4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/fti/0.1/lookup_route4");
	}
	if (_cmds->add_handler("fti/0.1/lookup_entry4", 
	    callback(this, &XrlFeaTargetBase::handle_fti_0_1_lookup_entry4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/fti/0.1/lookup_entry4");
	}
	if (_cmds->add_handler("fti/0.1/lookup_route6", 
	    callback(this, &XrlFeaTargetBase::handle_fti_0_1_lookup_route6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/fti/0.1/lookup_route6");
	}
	if (_cmds->add_handler("fti/0.1/lookup_entry6", 
	    callback(this, &XrlFeaTargetBase::handle_fti_0_1_lookup_entry6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/fti/0.1/lookup_entry6");
	}
	if (_cmds->add_handler("raw_packet/0.1/send4", 
	    callback(this, &XrlFeaTargetBase::handle_raw_packet_0_1_send4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/raw_packet/0.1/send4");
	}
	if (_cmds->add_handler("raw_packet/0.1/send_raw4", 
	    callback(this, &XrlFeaTargetBase::handle_raw_packet_0_1_send_raw4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/raw_packet/0.1/send_raw4");
	}
	if (_cmds->add_handler("raw_packet/0.1/register_vif_receiver", 
	    callback(this, &XrlFeaTargetBase::handle_raw_packet_0_1_register_vif_receiver)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/raw_packet/0.1/register_vif_receiver");
	}
	if (_cmds->add_handler("raw_packet/0.1/unregister_vif_receiver", 
	    callback(this, &XrlFeaTargetBase::handle_raw_packet_0_1_unregister_vif_receiver)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://fea/raw_packet/0.1/unregister_vif_receiver");
	}
    }

    void remove_handlers()
    {
	_cmds->remove_handler("common/0.1/get_target_name");
	_cmds->remove_handler("common/0.1/get_version");
	_cmds->remove_handler("ifmgr/0.1/get_all_interface_names");
	_cmds->remove_handler("ifmgr/0.1/get_configured_interface_names");
	_cmds->remove_handler("ifmgr/0.1/get_all_vif_names");
	_cmds->remove_handler("ifmgr/0.1/get_configured_vif_names");
	_cmds->remove_handler("ifmgr/0.1/get_vif_flags4");
	_cmds->remove_handler("ifmgr/0.1/get_vif_flags6");
	_cmds->remove_handler("ifmgr/0.1/get_all_vif_addresses4");
	_cmds->remove_handler("ifmgr/0.1/get_configured_vif_addresses4");
	_cmds->remove_handler("ifmgr/0.1/get_all_vif_addresses6");
	_cmds->remove_handler("ifmgr/0.1/get_configured_vif_addresses6");
	_cmds->remove_handler("ifmgr/0.1/get_interface_enabled");
	_cmds->remove_handler("ifmgr/0.1/get_mac");
	_cmds->remove_handler("ifmgr/0.1/get_mtu");
	_cmds->remove_handler("ifmgr/0.1/get_vif_enabled");
	_cmds->remove_handler("ifmgr/0.1/get_prefix4");
	_cmds->remove_handler("ifmgr/0.1/get_broadcast4");
	_cmds->remove_handler("ifmgr/0.1/get_endpoint4");
	_cmds->remove_handler("ifmgr/0.1/get_prefix6");
	_cmds->remove_handler("ifmgr/0.1/get_endpoint6");
	_cmds->remove_handler("ifmgr/0.1/start_transaction");
	_cmds->remove_handler("ifmgr/0.1/commit_transaction");
	_cmds->remove_handler("ifmgr/0.1/abort_transaction");
	_cmds->remove_handler("ifmgr/0.1/create_interface");
	_cmds->remove_handler("ifmgr/0.1/delete_interface");
	_cmds->remove_handler("ifmgr/0.1/set_interface_enabled");
	_cmds->remove_handler("ifmgr/0.1/set_mac");
	_cmds->remove_handler("ifmgr/0.1/set_mtu");
	_cmds->remove_handler("ifmgr/0.1/create_vif");
	_cmds->remove_handler("ifmgr/0.1/delete_vif");
	_cmds->remove_handler("ifmgr/0.1/set_vif_enabled");
	_cmds->remove_handler("ifmgr/0.1/create_address4");
	_cmds->remove_handler("ifmgr/0.1/delete_address4");
	_cmds->remove_handler("ifmgr/0.1/set_address_enabled4");
	_cmds->remove_handler("ifmgr/0.1/get_address_enabled4");
	_cmds->remove_handler("ifmgr/0.1/set_prefix4");
	_cmds->remove_handler("ifmgr/0.1/set_broadcast4");
	_cmds->remove_handler("ifmgr/0.1/set_endpoint4");
	_cmds->remove_handler("ifmgr/0.1/create_address6");
	_cmds->remove_handler("ifmgr/0.1/delete_address6");
	_cmds->remove_handler("ifmgr/0.1/set_address_enabled6");
	_cmds->remove_handler("ifmgr/0.1/get_address_enabled6");
	_cmds->remove_handler("ifmgr/0.1/set_prefix6");
	_cmds->remove_handler("ifmgr/0.1/set_endpoint6");
	_cmds->remove_handler("ifmgr/0.1/register_client");
	_cmds->remove_handler("ifmgr/0.1/unregister_client");
	_cmds->remove_handler("fti/0.1/start_transaction");
	_cmds->remove_handler("fti/0.1/commit_transaction");
	_cmds->remove_handler("fti/0.1/abort_transaction");
	_cmds->remove_handler("fti/0.1/add_entry4");
	_cmds->remove_handler("fti/0.1/delete_entry4");
	_cmds->remove_handler("fti/0.1/add_entry6");
	_cmds->remove_handler("fti/0.1/delete_entry6");
	_cmds->remove_handler("fti/0.1/delete_all_entries");
	_cmds->remove_handler("fti/0.1/delete_all_entries4");
	_cmds->remove_handler("fti/0.1/delete_all_entries6");
	_cmds->remove_handler("fti/0.1/lookup_route4");
	_cmds->remove_handler("fti/0.1/lookup_entry4");
	_cmds->remove_handler("fti/0.1/lookup_route6");
	_cmds->remove_handler("fti/0.1/lookup_entry6");
	_cmds->remove_handler("raw_packet/0.1/send4");
	_cmds->remove_handler("raw_packet/0.1/send_raw4");
	_cmds->remove_handler("raw_packet/0.1/register_vif_receiver");
	_cmds->remove_handler("raw_packet/0.1/unregister_vif_receiver");
    }
};

#endif /* __XRL_INTERFACES_FEA_BASE_HH__ */
