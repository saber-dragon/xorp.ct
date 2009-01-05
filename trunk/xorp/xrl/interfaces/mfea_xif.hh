/*
 * Copyright (c) 2001-2009 XORP, Inc.
 * See the XORP LICENSE.lgpl file for licensing, conditions, and warranties
 * on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 *
 * $XORP: xorp/xrl/interfaces/mfea_xif.hh,v 1.28 2008/10/02 21:58:36 bms Exp $
 */

#ifndef __XRL_INTERFACES_MFEA_XIF_HH__
#define __XRL_INTERFACES_MFEA_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifMfea"

#include "libxorp/xlog.h"
#include "libxorp/callback.hh"

#include "libxipc/xrl.hh"
#include "libxipc/xrl_error.hh"
#include "libxipc/xrl_sender.hh"


class XrlMfeaV0p1Client {
public:
    XrlMfeaV0p1Client(XrlSender* s) : _sender(s) {}
    virtual ~XrlMfeaV0p1Client() {}

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr HaveMulticastRouting4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Test if the underlying system supports IPv4 multicast routing.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     */
    bool send_have_multicast_routing4(
	const char*	dst_xrl_target_name,
	const HaveMulticastRouting4CB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr HaveMulticastRouting6CB;
    /**
     *  Send Xrl intended to:
     *
     *  Test if the underlying system supports IPv6 multicast routing.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     */
    bool send_have_multicast_routing6(
	const char*	dst_xrl_target_name,
	const HaveMulticastRouting6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr RegisterProtocol4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Register a protocol on an interface in the Multicast FEA. There could
     *  be only one registered protocol per interface/vif.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param xrl_sender_name the XRL name of the originator of this XRL.
     *
     *  @param if_name the name of the interface to register for the particular
     *  protocol.
     *
     *  @param vif_name the name of the vif to register for the particular
     *  protocol.
     *
     *  @param ip_protocol the IP protocol number. It must be between 1 and
     *  255.
     */
    bool send_register_protocol4(
	const char*	dst_xrl_target_name,
	const string&	xrl_sender_name,
	const string&	if_name,
	const string&	vif_name,
	const uint32_t&	ip_protocol,
	const RegisterProtocol4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr RegisterProtocol6CB;

    bool send_register_protocol6(
	const char*	dst_xrl_target_name,
	const string&	xrl_sender_name,
	const string&	if_name,
	const string&	vif_name,
	const uint32_t&	ip_protocol,
	const RegisterProtocol6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr UnregisterProtocol4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Unregister a protocol on an interface in the Multicast FEA. There could
     *  be only one registered protocol per interface/vif.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param xrl_sender_name the XRL name of the originator of this XRL.
     *
     *  @param if_name the name of the interface to unregister for the
     *  particular protocol.
     *
     *  @param vif_name the name of the vif to unregister for the particular
     *  protocol.
     */
    bool send_unregister_protocol4(
	const char*	dst_xrl_target_name,
	const string&	xrl_sender_name,
	const string&	if_name,
	const string&	vif_name,
	const UnregisterProtocol4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr UnregisterProtocol6CB;

    bool send_unregister_protocol6(
	const char*	dst_xrl_target_name,
	const string&	xrl_sender_name,
	const string&	if_name,
	const string&	vif_name,
	const UnregisterProtocol6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr AddMfc4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Add/delete a Multicast Forwarding Cache with the kernel.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param xrl_sender_name the XRL name of the originator of this XRL.
     *
     *  @param source_address the source address of the MFC to add/delete.
     *
     *  @param group_address the group address of the MFC to add/delete.
     *
     *  @param iif_vif_index the index of the vif that is the incoming
     *  interface.
     *
     *  @param oiflist the bit-vector with the set of outgoing interfaces.
     *
     *  @param oiflist_disable_wrongvif the bit-vector with the set of outgoing
     *  interfaces to disable WRONGVIF kernel signal.
     *
     *  @param max_vifs_oiflist the number of vifs covered by oiflist or
     *  oiflist_disable_wrongvif .
     *
     *  @param rp_address the RP address of the MFC to add.
     */
    bool send_add_mfc4(
	const char*	dst_xrl_target_name,
	const string&	xrl_sender_name,
	const IPv4&	source_address,
	const IPv4&	group_address,
	const uint32_t&	iif_vif_index,
	const vector<uint8_t>&	oiflist,
	const vector<uint8_t>&	oiflist_disable_wrongvif,
	const uint32_t&	max_vifs_oiflist,
	const IPv4&	rp_address,
	const AddMfc4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr AddMfc6CB;

    bool send_add_mfc6(
	const char*	dst_xrl_target_name,
	const string&	xrl_sender_name,
	const IPv6&	source_address,
	const IPv6&	group_address,
	const uint32_t&	iif_vif_index,
	const vector<uint8_t>&	oiflist,
	const vector<uint8_t>&	oiflist_disable_wrongvif,
	const uint32_t&	max_vifs_oiflist,
	const IPv6&	rp_address,
	const AddMfc6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteMfc4CB;

    bool send_delete_mfc4(
	const char*	dst_xrl_target_name,
	const string&	xrl_sender_name,
	const IPv4&	source_address,
	const IPv4&	group_address,
	const DeleteMfc4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteMfc6CB;

    bool send_delete_mfc6(
	const char*	dst_xrl_target_name,
	const string&	xrl_sender_name,
	const IPv6&	source_address,
	const IPv6&	group_address,
	const DeleteMfc6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr AddDataflowMonitor4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Add/delete a dataflow monitor with the MFEA.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param xrl_sender_name the XRL name of the originator of this XRL.
     *
     *  @param source_address the source address of the dataflow to start/stop
     *  monitoring.
     *
     *  @param group_address the group address of the dataflow to start/stop
     *  monitoring.
     *
     *  @param threshold_interval_sec the number of seconds in the interval to
     *  measure.
     *
     *  @param threshold_interval_usec the number of microseconds in the
     *  interval to measure.
     *
     *  @param threshold_packets the threshold (in number of packets) to
     *  compare against.
     *
     *  @param threshold_bytes the threshold (in number of bytes) to compare
     *  against.
     *
     *  @param is_threshold_in_packets if true, threshold_packets is valid.
     *
     *  @param is_threshold_in_bytes if true, threshold_bytes is valid.
     *
     *  @param is_geq_upcall if true, the operation for comparison is ">=".
     *
     *  @param is_leq_upcall if true, the operation for comparison is "<=".
     */
    bool send_add_dataflow_monitor4(
	const char*	dst_xrl_target_name,
	const string&	xrl_sender_name,
	const IPv4&	source_address,
	const IPv4&	group_address,
	const uint32_t&	threshold_interval_sec,
	const uint32_t&	threshold_interval_usec,
	const uint32_t&	threshold_packets,
	const uint32_t&	threshold_bytes,
	const bool&	is_threshold_in_packets,
	const bool&	is_threshold_in_bytes,
	const bool&	is_geq_upcall,
	const bool&	is_leq_upcall,
	const AddDataflowMonitor4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr AddDataflowMonitor6CB;

    bool send_add_dataflow_monitor6(
	const char*	dst_xrl_target_name,
	const string&	xrl_sender_name,
	const IPv6&	source_address,
	const IPv6&	group_address,
	const uint32_t&	threshold_interval_sec,
	const uint32_t&	threshold_interval_usec,
	const uint32_t&	threshold_packets,
	const uint32_t&	threshold_bytes,
	const bool&	is_threshold_in_packets,
	const bool&	is_threshold_in_bytes,
	const bool&	is_geq_upcall,
	const bool&	is_leq_upcall,
	const AddDataflowMonitor6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteDataflowMonitor4CB;

    bool send_delete_dataflow_monitor4(
	const char*	dst_xrl_target_name,
	const string&	xrl_sender_name,
	const IPv4&	source_address,
	const IPv4&	group_address,
	const uint32_t&	threshold_interval_sec,
	const uint32_t&	threshold_interval_usec,
	const uint32_t&	threshold_packets,
	const uint32_t&	threshold_bytes,
	const bool&	is_threshold_in_packets,
	const bool&	is_threshold_in_bytes,
	const bool&	is_geq_upcall,
	const bool&	is_leq_upcall,
	const DeleteDataflowMonitor4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteDataflowMonitor6CB;

    bool send_delete_dataflow_monitor6(
	const char*	dst_xrl_target_name,
	const string&	xrl_sender_name,
	const IPv6&	source_address,
	const IPv6&	group_address,
	const uint32_t&	threshold_interval_sec,
	const uint32_t&	threshold_interval_usec,
	const uint32_t&	threshold_packets,
	const uint32_t&	threshold_bytes,
	const bool&	is_threshold_in_packets,
	const bool&	is_threshold_in_bytes,
	const bool&	is_geq_upcall,
	const bool&	is_leq_upcall,
	const DeleteDataflowMonitor6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteAllDataflowMonitor4CB;

    bool send_delete_all_dataflow_monitor4(
	const char*	dst_xrl_target_name,
	const string&	xrl_sender_name,
	const IPv4&	source_address,
	const IPv4&	group_address,
	const DeleteAllDataflowMonitor4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteAllDataflowMonitor6CB;

    bool send_delete_all_dataflow_monitor6(
	const char*	dst_xrl_target_name,
	const string&	xrl_sender_name,
	const IPv6&	source_address,
	const IPv6&	group_address,
	const DeleteAllDataflowMonitor6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr EnableVifCB;
    /**
     *  Send Xrl intended to:
     *
     *  Enable/disable/start/stop a MFEA vif interface.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param vif_name the name of the vif to enable/disable/start/stop.
     *
     *  @param enable if true, then enable the vif, otherwise disable it.
     */
    bool send_enable_vif(
	const char*	dst_xrl_target_name,
	const string&	vif_name,
	const bool&	enable,
	const EnableVifCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr StartVifCB;

    bool send_start_vif(
	const char*	dst_xrl_target_name,
	const string&	vif_name,
	const StartVifCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr StopVifCB;

    bool send_stop_vif(
	const char*	dst_xrl_target_name,
	const string&	vif_name,
	const StopVifCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr EnableAllVifsCB;
    /**
     *  Send Xrl intended to:
     *
     *  Enable/disable/start/stop all MFEA vif interfaces.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param enable if true, then enable the vifs, otherwise disable them.
     */
    bool send_enable_all_vifs(
	const char*	dst_xrl_target_name,
	const bool&	enable,
	const EnableAllVifsCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr StartAllVifsCB;

    bool send_start_all_vifs(
	const char*	dst_xrl_target_name,
	const StartAllVifsCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr StopAllVifsCB;

    bool send_stop_all_vifs(
	const char*	dst_xrl_target_name,
	const StopAllVifsCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr EnableMfeaCB;
    /**
     *  Send Xrl intended to:
     *
     *  Enable/disable/start/stop the MFEA.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param enable if true, then enable the MFEA, otherwise disable it.
     */
    bool send_enable_mfea(
	const char*	dst_xrl_target_name,
	const bool&	enable,
	const EnableMfeaCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr StartMfeaCB;

    bool send_start_mfea(
	const char*	dst_xrl_target_name,
	const StartMfeaCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr StopMfeaCB;

    bool send_stop_mfea(
	const char*	dst_xrl_target_name,
	const StopMfeaCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr EnableCliCB;
    /**
     *  Send Xrl intended to:
     *
     *  Enable/disable/start/stop the MFEA CLI access.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param enable if true, then enable the MFEA CLI access, otherwise
     *  disable it.
     */
    bool send_enable_cli(
	const char*	dst_xrl_target_name,
	const bool&	enable,
	const EnableCliCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr StartCliCB;

    bool send_start_cli(
	const char*	dst_xrl_target_name,
	const StartCliCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr StopCliCB;

    bool send_stop_cli(
	const char*	dst_xrl_target_name,
	const StopCliCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr LogTraceAllCB;
    /**
     *  Send Xrl intended to:
     *
     *  Enable/disable the MFEA trace log for all operations.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param enable if true, then enable the trace log, otherwise disable it.
     */
    bool send_log_trace_all(
	const char*	dst_xrl_target_name,
	const bool&	enable,
	const LogTraceAllCB&	cb
    );

protected:
    XrlSender* _sender;

private:
    void unmarshall_have_multicast_routing4(
	const XrlError&	e,
	XrlArgs*	a,
	HaveMulticastRouting4CB		cb
    );

    void unmarshall_have_multicast_routing6(
	const XrlError&	e,
	XrlArgs*	a,
	HaveMulticastRouting6CB		cb
    );

    void unmarshall_register_protocol4(
	const XrlError&	e,
	XrlArgs*	a,
	RegisterProtocol4CB		cb
    );

    void unmarshall_register_protocol6(
	const XrlError&	e,
	XrlArgs*	a,
	RegisterProtocol6CB		cb
    );

    void unmarshall_unregister_protocol4(
	const XrlError&	e,
	XrlArgs*	a,
	UnregisterProtocol4CB		cb
    );

    void unmarshall_unregister_protocol6(
	const XrlError&	e,
	XrlArgs*	a,
	UnregisterProtocol6CB		cb
    );

    void unmarshall_add_mfc4(
	const XrlError&	e,
	XrlArgs*	a,
	AddMfc4CB		cb
    );

    void unmarshall_add_mfc6(
	const XrlError&	e,
	XrlArgs*	a,
	AddMfc6CB		cb
    );

    void unmarshall_delete_mfc4(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteMfc4CB		cb
    );

    void unmarshall_delete_mfc6(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteMfc6CB		cb
    );

    void unmarshall_add_dataflow_monitor4(
	const XrlError&	e,
	XrlArgs*	a,
	AddDataflowMonitor4CB		cb
    );

    void unmarshall_add_dataflow_monitor6(
	const XrlError&	e,
	XrlArgs*	a,
	AddDataflowMonitor6CB		cb
    );

    void unmarshall_delete_dataflow_monitor4(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteDataflowMonitor4CB		cb
    );

    void unmarshall_delete_dataflow_monitor6(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteDataflowMonitor6CB		cb
    );

    void unmarshall_delete_all_dataflow_monitor4(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteAllDataflowMonitor4CB		cb
    );

    void unmarshall_delete_all_dataflow_monitor6(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteAllDataflowMonitor6CB		cb
    );

    void unmarshall_enable_vif(
	const XrlError&	e,
	XrlArgs*	a,
	EnableVifCB		cb
    );

    void unmarshall_start_vif(
	const XrlError&	e,
	XrlArgs*	a,
	StartVifCB		cb
    );

    void unmarshall_stop_vif(
	const XrlError&	e,
	XrlArgs*	a,
	StopVifCB		cb
    );

    void unmarshall_enable_all_vifs(
	const XrlError&	e,
	XrlArgs*	a,
	EnableAllVifsCB		cb
    );

    void unmarshall_start_all_vifs(
	const XrlError&	e,
	XrlArgs*	a,
	StartAllVifsCB		cb
    );

    void unmarshall_stop_all_vifs(
	const XrlError&	e,
	XrlArgs*	a,
	StopAllVifsCB		cb
    );

    void unmarshall_enable_mfea(
	const XrlError&	e,
	XrlArgs*	a,
	EnableMfeaCB		cb
    );

    void unmarshall_start_mfea(
	const XrlError&	e,
	XrlArgs*	a,
	StartMfeaCB		cb
    );

    void unmarshall_stop_mfea(
	const XrlError&	e,
	XrlArgs*	a,
	StopMfeaCB		cb
    );

    void unmarshall_enable_cli(
	const XrlError&	e,
	XrlArgs*	a,
	EnableCliCB		cb
    );

    void unmarshall_start_cli(
	const XrlError&	e,
	XrlArgs*	a,
	StartCliCB		cb
    );

    void unmarshall_stop_cli(
	const XrlError&	e,
	XrlArgs*	a,
	StopCliCB		cb
    );

    void unmarshall_log_trace_all(
	const XrlError&	e,
	XrlArgs*	a,
	LogTraceAllCB		cb
    );

};

#endif /* __XRL_INTERFACES_MFEA_XIF_HH__ */
