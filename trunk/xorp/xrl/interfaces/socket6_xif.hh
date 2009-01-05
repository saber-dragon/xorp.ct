/*
 * Copyright (c) 2001-2009 XORP, Inc.
 * See the XORP LICENSE.lgpl file for licensing, conditions, and warranties
 * on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 *
 * $XORP: xorp/xrl/interfaces/socket6_xif.hh,v 1.27 2008/10/02 21:58:40 bms Exp $
 */

#ifndef __XRL_INTERFACES_SOCKET6_XIF_HH__
#define __XRL_INTERFACES_SOCKET6_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifSocket6"

#include "libxorp/xlog.h"
#include "libxorp/callback.hh"

#include "libxipc/xrl.hh"
#include "libxipc/xrl_error.hh"
#include "libxipc/xrl_sender.hh"


class XrlSocket6V0p1Client {
public:
    XrlSocket6V0p1Client(XrlSender* s) : _sender(s) {}
    virtual ~XrlSocket6V0p1Client() {}

    typedef XorpCallback2<void, const XrlError&, const string*>::RefPtr TcpOpenCB;
    /**
     *  Send Xrl intended to:
     *
     *  Open a TCP socket.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param creator the Xrl Target instance name of the socket creator. The
     *  named target must implement socket4_user/0.1.
     */
    bool send_tcp_open(
	const char*	dst_xrl_target_name,
	const string&	creator,
	const TcpOpenCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const string*>::RefPtr UdpOpenCB;
    /**
     *  Send Xrl intended to:
     *
     *  Open an UDP socket.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param creator the Xrl Target instance name of the socket creator. The
     *  named target must implement socket4_user/0.1.
     */
    bool send_udp_open(
	const char*	dst_xrl_target_name,
	const string&	creator,
	const UdpOpenCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const string*>::RefPtr TcpOpenAndBindCB;
    /**
     *  Send Xrl intended to:
     *
     *  Create a bound TCP socket.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param creator the Xrl Target instance name of the socket creator. The
     *  named target must implement socket6_user/0.1.
     *
     *  @param local_addr the interface address to bind socket to.
     *
     *  @param local_port the port to bind socket to.
     */
    bool send_tcp_open_and_bind(
	const char*	dst_xrl_target_name,
	const string&	creator,
	const IPv6&	local_addr,
	const uint32_t&	local_port,
	const TcpOpenAndBindCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const string*>::RefPtr UdpOpenAndBindCB;
    /**
     *  Send Xrl intended to:
     *
     *  Create a bound UDP socket.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param creator the Xrl Target instance name of the socket creator. The
     *  named target must implement socket6_user/0.1.
     *
     *  @param local_addr the interface address to bind socket to.
     *
     *  @param local_port the port to bind socket to.
     */
    bool send_udp_open_and_bind(
	const char*	dst_xrl_target_name,
	const string&	creator,
	const IPv6&	local_addr,
	const uint32_t&	local_port,
	const UdpOpenAndBindCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const string*>::RefPtr UdpOpenBindJoinCB;
    /**
     *  Send Xrl intended to:
     *
     *  Create a bound UDP multicast socket.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param creator the Xrl Target instance name of the socket creator. The
     *  named target must implement socket6_user/0.1.
     *
     *  @param local_addr the interface address to bind socket to.
     *
     *  @param local_port the port to bind socket to.
     *
     *  @param mcast_addr the multicast group address to join.
     *
     *  @param ttl the ttl to use for this multicast socket.
     *
     *  @param reuse allow other sockets to bind to same multicast group.
     */
    bool send_udp_open_bind_join(
	const char*	dst_xrl_target_name,
	const string&	creator,
	const IPv6&	local_addr,
	const uint32_t&	local_port,
	const IPv6&	mcast_addr,
	const uint32_t&	ttl,
	const bool&	reuse,
	const UdpOpenBindJoinCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const string*>::RefPtr TcpOpenBindConnectCB;
    /**
     *  Send Xrl intended to:
     *
     *  Create a bound and connected TCP socket.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param creator the Xrl Target instance name of the socket creator. The
     *  named target must implement socket6_user/0.1.
     *
     *  @param local_addr the interface address to bind socket to.
     *
     *  @param local_port the port to bind socket to.
     *
     *  @param remote_addr the address to connect to.
     *
     *  @param remote_port the remote port to connect to.
     */
    bool send_tcp_open_bind_connect(
	const char*	dst_xrl_target_name,
	const string&	creator,
	const IPv6&	local_addr,
	const uint32_t&	local_port,
	const IPv6&	remote_addr,
	const uint32_t&	remote_port,
	const TcpOpenBindConnectCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const string*>::RefPtr UdpOpenBindConnectCB;
    /**
     *  Send Xrl intended to:
     *
     *  Create a bound and connected UDP socket.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param creator the Xrl Target instance name of the socket creator. The
     *  named target must implement socket6_user/0.1.
     *
     *  @param local_addr the interface address to bind socket to.
     *
     *  @param local_port the port to bind socket to.
     *
     *  @param remote_addr the address to connect to.
     *
     *  @param remote_port the remote port to connect to.
     */
    bool send_udp_open_bind_connect(
	const char*	dst_xrl_target_name,
	const string&	creator,
	const IPv6&	local_addr,
	const uint32_t&	local_port,
	const IPv6&	remote_addr,
	const uint32_t&	remote_port,
	const UdpOpenBindConnectCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr BindCB;
    /**
     *  Send Xrl intended to:
     *
     *  Bind a socket.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param sockid the socket ID of the socket to bind.
     *
     *  @param local_addr the interface address to bind socket to.
     *
     *  @param local_port the port to bind socket to.
     */
    bool send_bind(
	const char*	dst_xrl_target_name,
	const string&	sockid,
	const IPv6&	local_addr,
	const uint32_t&	local_port,
	const BindCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr UdpJoinGroupCB;
    /**
     *  Send Xrl intended to:
     *
     *  Join multicast group on already bound socket.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param sockid unique socket ID.
     *
     *  @param mcast_addr group to join.
     *
     *  @param join_if_addr interface address to perform join on.
     */
    bool send_udp_join_group(
	const char*	dst_xrl_target_name,
	const string&	sockid,
	const IPv6&	mcast_addr,
	const IPv6&	join_if_addr,
	const UdpJoinGroupCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr UdpLeaveGroupCB;
    /**
     *  Send Xrl intended to:
     *
     *  Leave multicast group on already bound socket.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param sockid unique socket ID.
     *
     *  @param mcast_addr group to leave.
     *
     *  @param leave_if_addr interface address to perform leave on.
     */
    bool send_udp_leave_group(
	const char*	dst_xrl_target_name,
	const string&	sockid,
	const IPv6&	mcast_addr,
	const IPv6&	leave_if_addr,
	const UdpLeaveGroupCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CloseCB;
    /**
     *  Send Xrl intended to:
     *
     *  Close socket.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param sockid unique socket ID of socket to be closed.
     */
    bool send_close(
	const char*	dst_xrl_target_name,
	const string&	sockid,
	const CloseCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr TcpListenCB;
    /**
     *  Send Xrl intended to:
     *
     *  Listen for inbound connections on socket. When a connection request
     *  received the socket creator will receive notification through
     *  socket6_user/0.1/inbound_connect_event.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param sockid the unique socket ID of the socket to perform listen.
     *
     *  @param backlog the maximum number of pending connections.
     */
    bool send_tcp_listen(
	const char*	dst_xrl_target_name,
	const string&	sockid,
	const uint32_t&	backlog,
	const TcpListenCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SendCB;
    /**
     *  Send Xrl intended to:
     *
     *  Send data on socket.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param sockid unique socket ID.
     *
     *  @param data block of data to be sent.
     */
    bool send_send(
	const char*	dst_xrl_target_name,
	const string&	sockid,
	const vector<uint8_t>&	data,
	const SendCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SendToCB;
    /**
     *  Send Xrl intended to:
     *
     *  Send data on socket to a given destination. The packet is not routed as
     *  the forwarding engine sending the packet may not have access to the
     *  full routing table.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param sockid unique socket ID.
     *
     *  @param remote_addr destination address for data.
     *
     *  @param remote_port destination port for data.
     *
     *  @param data block of data to be sent.
     */
    bool send_send_to(
	const char*	dst_xrl_target_name,
	const string&	sockid,
	const IPv6&	remote_addr,
	const uint32_t&	remote_port,
	const vector<uint8_t>&	data,
	const SendToCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SendFromMulticastIfCB;
    /**
     *  Send Xrl intended to:
     *
     *  Send data on socket to a given multicast group from a given interface.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param sockid unique socket ID.
     *
     *  @param group_addr destination address for data.
     *
     *  @param group_port destination port for data.
     *
     *  @param ifaddr interface address
     */
    bool send_send_from_multicast_if(
	const char*	dst_xrl_target_name,
	const string&	sockid,
	const IPv6&	group_addr,
	const uint32_t&	group_port,
	const IPv6&	ifaddr,
	const vector<uint8_t>&	data,
	const SendFromMulticastIfCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetSocketOptionCB;
    /**
     *  Send Xrl intended to:
     *
     *  Set a named socket option with an integer value.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param sockid unique socket ID.
     *
     *  @param optname name of option to be set. Valid values are: "reuseport"
     *  "ttl" "multicast_loopback" "multicast_ttl"
     *
     *  @param optval value of option to be set. If value is logically boolean
     *  then zero represents false and any non-zero value true.
     */
    bool send_set_socket_option(
	const char*	dst_xrl_target_name,
	const string&	sockid,
	const string&	optname,
	const uint32_t&	optval,
	const SetSocketOptionCB&	cb
    );

protected:
    XrlSender* _sender;

private:
    void unmarshall_tcp_open(
	const XrlError&	e,
	XrlArgs*	a,
	TcpOpenCB		cb
    );

    void unmarshall_udp_open(
	const XrlError&	e,
	XrlArgs*	a,
	UdpOpenCB		cb
    );

    void unmarshall_tcp_open_and_bind(
	const XrlError&	e,
	XrlArgs*	a,
	TcpOpenAndBindCB		cb
    );

    void unmarshall_udp_open_and_bind(
	const XrlError&	e,
	XrlArgs*	a,
	UdpOpenAndBindCB		cb
    );

    void unmarshall_udp_open_bind_join(
	const XrlError&	e,
	XrlArgs*	a,
	UdpOpenBindJoinCB		cb
    );

    void unmarshall_tcp_open_bind_connect(
	const XrlError&	e,
	XrlArgs*	a,
	TcpOpenBindConnectCB		cb
    );

    void unmarshall_udp_open_bind_connect(
	const XrlError&	e,
	XrlArgs*	a,
	UdpOpenBindConnectCB		cb
    );

    void unmarshall_bind(
	const XrlError&	e,
	XrlArgs*	a,
	BindCB		cb
    );

    void unmarshall_udp_join_group(
	const XrlError&	e,
	XrlArgs*	a,
	UdpJoinGroupCB		cb
    );

    void unmarshall_udp_leave_group(
	const XrlError&	e,
	XrlArgs*	a,
	UdpLeaveGroupCB		cb
    );

    void unmarshall_close(
	const XrlError&	e,
	XrlArgs*	a,
	CloseCB		cb
    );

    void unmarshall_tcp_listen(
	const XrlError&	e,
	XrlArgs*	a,
	TcpListenCB		cb
    );

    void unmarshall_send(
	const XrlError&	e,
	XrlArgs*	a,
	SendCB		cb
    );

    void unmarshall_send_to(
	const XrlError&	e,
	XrlArgs*	a,
	SendToCB		cb
    );

    void unmarshall_send_from_multicast_if(
	const XrlError&	e,
	XrlArgs*	a,
	SendFromMulticastIfCB		cb
    );

    void unmarshall_set_socket_option(
	const XrlError&	e,
	XrlArgs*	a,
	SetSocketOptionCB		cb
    );

};

#endif /* __XRL_INTERFACES_SOCKET6_XIF_HH__ */
