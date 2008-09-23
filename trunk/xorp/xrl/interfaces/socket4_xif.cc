/*
 * Copyright (c) 2001-2008 XORP, Inc.
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP: xorp/xrl/interfaces/socket4_xif.cc,v 1.25 2008/07/23 11:55:20 bms Exp $"

#include "socket4_xif.hh"

bool
XrlSocket4V0p1Client::send_tcp_open(
	const char*	dst_xrl_target_name,
	const string&	creator,
	const TcpOpenCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "socket4/0.1/tcp_open");
        x->args().add(XrlAtom(creator));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, creator);

    return _sender->send(*x, callback(this, &XrlSocket4V0p1Client::unmarshall_tcp_open, cb));
}


/* Unmarshall tcp_open */
void
XrlSocket4V0p1Client::unmarshall_tcp_open(
	const XrlError&	e,
	XrlArgs*	a,
	TcpOpenCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(1));
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    string sockid;
    try {
	a->get("sockid", sockid);
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &sockid);
}

bool
XrlSocket4V0p1Client::send_udp_open(
	const char*	dst_xrl_target_name,
	const string&	creator,
	const UdpOpenCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "socket4/0.1/udp_open");
        x->args().add(XrlAtom(creator));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, creator);

    return _sender->send(*x, callback(this, &XrlSocket4V0p1Client::unmarshall_udp_open, cb));
}


/* Unmarshall udp_open */
void
XrlSocket4V0p1Client::unmarshall_udp_open(
	const XrlError&	e,
	XrlArgs*	a,
	UdpOpenCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(1));
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    string sockid;
    try {
	a->get("sockid", sockid);
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &sockid);
}

bool
XrlSocket4V0p1Client::send_tcp_open_and_bind(
	const char*	dst_xrl_target_name,
	const string&	creator,
	const IPv4&	local_addr,
	const uint32_t&	local_port,
	const TcpOpenAndBindCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "socket4/0.1/tcp_open_and_bind");
        x->args().add(XrlAtom(creator));
        x->args().add(XrlAtom(local_addr));
        x->args().add(XrlAtom(local_port));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, creator);
    x->args().set_arg(1, local_addr);
    x->args().set_arg(2, local_port);

    return _sender->send(*x, callback(this, &XrlSocket4V0p1Client::unmarshall_tcp_open_and_bind, cb));
}


/* Unmarshall tcp_open_and_bind */
void
XrlSocket4V0p1Client::unmarshall_tcp_open_and_bind(
	const XrlError&	e,
	XrlArgs*	a,
	TcpOpenAndBindCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(1));
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    string sockid;
    try {
	a->get("sockid", sockid);
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &sockid);
}

bool
XrlSocket4V0p1Client::send_udp_open_and_bind(
	const char*	dst_xrl_target_name,
	const string&	creator,
	const IPv4&	local_addr,
	const uint32_t&	local_port,
	const UdpOpenAndBindCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "socket4/0.1/udp_open_and_bind");
        x->args().add(XrlAtom(creator));
        x->args().add(XrlAtom(local_addr));
        x->args().add(XrlAtom(local_port));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, creator);
    x->args().set_arg(1, local_addr);
    x->args().set_arg(2, local_port);

    return _sender->send(*x, callback(this, &XrlSocket4V0p1Client::unmarshall_udp_open_and_bind, cb));
}


/* Unmarshall udp_open_and_bind */
void
XrlSocket4V0p1Client::unmarshall_udp_open_and_bind(
	const XrlError&	e,
	XrlArgs*	a,
	UdpOpenAndBindCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(1));
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    string sockid;
    try {
	a->get("sockid", sockid);
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &sockid);
}

bool
XrlSocket4V0p1Client::send_udp_open_bind_join(
	const char*	dst_xrl_target_name,
	const string&	creator,
	const IPv4&	local_addr,
	const uint32_t&	local_port,
	const IPv4&	mcast_addr,
	const uint32_t&	ttl,
	const bool&	reuse,
	const UdpOpenBindJoinCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "socket4/0.1/udp_open_bind_join");
        x->args().add(XrlAtom(creator));
        x->args().add(XrlAtom(local_addr));
        x->args().add(XrlAtom(local_port));
        x->args().add(XrlAtom(mcast_addr));
        x->args().add(XrlAtom(ttl));
        x->args().add(XrlAtom(reuse));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, creator);
    x->args().set_arg(1, local_addr);
    x->args().set_arg(2, local_port);
    x->args().set_arg(3, mcast_addr);
    x->args().set_arg(4, ttl);
    x->args().set_arg(5, reuse);

    return _sender->send(*x, callback(this, &XrlSocket4V0p1Client::unmarshall_udp_open_bind_join, cb));
}


/* Unmarshall udp_open_bind_join */
void
XrlSocket4V0p1Client::unmarshall_udp_open_bind_join(
	const XrlError&	e,
	XrlArgs*	a,
	UdpOpenBindJoinCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(1));
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    string sockid;
    try {
	a->get("sockid", sockid);
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &sockid);
}

bool
XrlSocket4V0p1Client::send_tcp_open_bind_connect(
	const char*	dst_xrl_target_name,
	const string&	creator,
	const IPv4&	local_addr,
	const uint32_t&	local_port,
	const IPv4&	remote_addr,
	const uint32_t&	remote_port,
	const TcpOpenBindConnectCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "socket4/0.1/tcp_open_bind_connect");
        x->args().add(XrlAtom(creator));
        x->args().add(XrlAtom(local_addr));
        x->args().add(XrlAtom(local_port));
        x->args().add(XrlAtom(remote_addr));
        x->args().add(XrlAtom(remote_port));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, creator);
    x->args().set_arg(1, local_addr);
    x->args().set_arg(2, local_port);
    x->args().set_arg(3, remote_addr);
    x->args().set_arg(4, remote_port);

    return _sender->send(*x, callback(this, &XrlSocket4V0p1Client::unmarshall_tcp_open_bind_connect, cb));
}


/* Unmarshall tcp_open_bind_connect */
void
XrlSocket4V0p1Client::unmarshall_tcp_open_bind_connect(
	const XrlError&	e,
	XrlArgs*	a,
	TcpOpenBindConnectCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(1));
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    string sockid;
    try {
	a->get("sockid", sockid);
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &sockid);
}

bool
XrlSocket4V0p1Client::send_udp_open_bind_connect(
	const char*	dst_xrl_target_name,
	const string&	creator,
	const IPv4&	local_addr,
	const uint32_t&	local_port,
	const IPv4&	remote_addr,
	const uint32_t&	remote_port,
	const UdpOpenBindConnectCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "socket4/0.1/udp_open_bind_connect");
        x->args().add(XrlAtom(creator));
        x->args().add(XrlAtom(local_addr));
        x->args().add(XrlAtom(local_port));
        x->args().add(XrlAtom(remote_addr));
        x->args().add(XrlAtom(remote_port));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, creator);
    x->args().set_arg(1, local_addr);
    x->args().set_arg(2, local_port);
    x->args().set_arg(3, remote_addr);
    x->args().set_arg(4, remote_port);

    return _sender->send(*x, callback(this, &XrlSocket4V0p1Client::unmarshall_udp_open_bind_connect, cb));
}


/* Unmarshall udp_open_bind_connect */
void
XrlSocket4V0p1Client::unmarshall_udp_open_bind_connect(
	const XrlError&	e,
	XrlArgs*	a,
	UdpOpenBindConnectCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(1));
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    string sockid;
    try {
	a->get("sockid", sockid);
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &sockid);
}

bool
XrlSocket4V0p1Client::send_udp_open_bind_broadcast(
	const char*	dst_xrl_target_name,
	const string&	creator,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	local_port,
	const uint32_t&	remote_port,
	const bool&	reuse,
	const bool&	limited,
	const bool&	connected,
	const UdpOpenBindBroadcastCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "socket4/0.1/udp_open_bind_broadcast");
        x->args().add(XrlAtom(creator));
        x->args().add(XrlAtom(ifname));
        x->args().add(XrlAtom(vifname));
        x->args().add(XrlAtom(local_port));
        x->args().add(XrlAtom(remote_port));
        x->args().add(XrlAtom(reuse));
        x->args().add(XrlAtom(limited));
        x->args().add(XrlAtom(connected));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, creator);
    x->args().set_arg(1, ifname);
    x->args().set_arg(2, vifname);
    x->args().set_arg(3, local_port);
    x->args().set_arg(4, remote_port);
    x->args().set_arg(5, reuse);
    x->args().set_arg(6, limited);
    x->args().set_arg(7, connected);

    return _sender->send(*x, callback(this, &XrlSocket4V0p1Client::unmarshall_udp_open_bind_broadcast, cb));
}


/* Unmarshall udp_open_bind_broadcast */
void
XrlSocket4V0p1Client::unmarshall_udp_open_bind_broadcast(
	const XrlError&	e,
	XrlArgs*	a,
	UdpOpenBindBroadcastCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(1));
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    string sockid;
    try {
	a->get("sockid", sockid);
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &sockid);
}

bool
XrlSocket4V0p1Client::send_bind(
	const char*	dst_xrl_target_name,
	const string&	sockid,
	const IPv4&	local_addr,
	const uint32_t&	local_port,
	const BindCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "socket4/0.1/bind");
        x->args().add(XrlAtom(sockid));
        x->args().add(XrlAtom(local_addr));
        x->args().add(XrlAtom(local_port));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, sockid);
    x->args().set_arg(1, local_addr);
    x->args().set_arg(2, local_port);

    return _sender->send(*x, callback(this, &XrlSocket4V0p1Client::unmarshall_bind, cb));
}


/* Unmarshall bind */
void
XrlSocket4V0p1Client::unmarshall_bind(
	const XrlError&	e,
	XrlArgs*	a,
	BindCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlSocket4V0p1Client::send_udp_join_group(
	const char*	dst_xrl_target_name,
	const string&	sockid,
	const IPv4&	mcast_addr,
	const IPv4&	join_if_addr,
	const UdpJoinGroupCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "socket4/0.1/udp_join_group");
        x->args().add(XrlAtom(sockid));
        x->args().add(XrlAtom(mcast_addr));
        x->args().add(XrlAtom(join_if_addr));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, sockid);
    x->args().set_arg(1, mcast_addr);
    x->args().set_arg(2, join_if_addr);

    return _sender->send(*x, callback(this, &XrlSocket4V0p1Client::unmarshall_udp_join_group, cb));
}


/* Unmarshall udp_join_group */
void
XrlSocket4V0p1Client::unmarshall_udp_join_group(
	const XrlError&	e,
	XrlArgs*	a,
	UdpJoinGroupCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlSocket4V0p1Client::send_udp_leave_group(
	const char*	dst_xrl_target_name,
	const string&	sockid,
	const IPv4&	mcast_addr,
	const IPv4&	leave_if_addr,
	const UdpLeaveGroupCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "socket4/0.1/udp_leave_group");
        x->args().add(XrlAtom(sockid));
        x->args().add(XrlAtom(mcast_addr));
        x->args().add(XrlAtom(leave_if_addr));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, sockid);
    x->args().set_arg(1, mcast_addr);
    x->args().set_arg(2, leave_if_addr);

    return _sender->send(*x, callback(this, &XrlSocket4V0p1Client::unmarshall_udp_leave_group, cb));
}


/* Unmarshall udp_leave_group */
void
XrlSocket4V0p1Client::unmarshall_udp_leave_group(
	const XrlError&	e,
	XrlArgs*	a,
	UdpLeaveGroupCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlSocket4V0p1Client::send_close(
	const char*	dst_xrl_target_name,
	const string&	sockid,
	const CloseCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "socket4/0.1/close");
        x->args().add(XrlAtom(sockid));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, sockid);

    return _sender->send(*x, callback(this, &XrlSocket4V0p1Client::unmarshall_close, cb));
}


/* Unmarshall close */
void
XrlSocket4V0p1Client::unmarshall_close(
	const XrlError&	e,
	XrlArgs*	a,
	CloseCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlSocket4V0p1Client::send_tcp_listen(
	const char*	dst_xrl_target_name,
	const string&	sockid,
	const uint32_t&	backlog,
	const TcpListenCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "socket4/0.1/tcp_listen");
        x->args().add(XrlAtom(sockid));
        x->args().add(XrlAtom(backlog));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, sockid);
    x->args().set_arg(1, backlog);

    return _sender->send(*x, callback(this, &XrlSocket4V0p1Client::unmarshall_tcp_listen, cb));
}


/* Unmarshall tcp_listen */
void
XrlSocket4V0p1Client::unmarshall_tcp_listen(
	const XrlError&	e,
	XrlArgs*	a,
	TcpListenCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlSocket4V0p1Client::send_udp_enable_recv(
	const char*	dst_xrl_target_name,
	const string&	sockid,
	const UdpEnableRecvCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "socket4/0.1/udp_enable_recv");
        x->args().add(XrlAtom(sockid));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, sockid);

    return _sender->send(*x, callback(this, &XrlSocket4V0p1Client::unmarshall_udp_enable_recv, cb));
}


/* Unmarshall udp_enable_recv */
void
XrlSocket4V0p1Client::unmarshall_udp_enable_recv(
	const XrlError&	e,
	XrlArgs*	a,
	UdpEnableRecvCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlSocket4V0p1Client::send_send(
	const char*	dst_xrl_target_name,
	const string&	sockid,
	const vector<uint8_t>&	data,
	const SendCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "socket4/0.1/send");
        x->args().add(XrlAtom(sockid));
        x->args().add(XrlAtom(data));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, sockid);
    x->args().set_arg(1, data);

    return _sender->send(*x, callback(this, &XrlSocket4V0p1Client::unmarshall_send, cb));
}


/* Unmarshall send */
void
XrlSocket4V0p1Client::unmarshall_send(
	const XrlError&	e,
	XrlArgs*	a,
	SendCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlSocket4V0p1Client::send_send_to(
	const char*	dst_xrl_target_name,
	const string&	sockid,
	const IPv4&	remote_addr,
	const uint32_t&	remote_port,
	const vector<uint8_t>&	data,
	const SendToCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "socket4/0.1/send_to");
        x->args().add(XrlAtom(sockid));
        x->args().add(XrlAtom(remote_addr));
        x->args().add(XrlAtom(remote_port));
        x->args().add(XrlAtom(data));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, sockid);
    x->args().set_arg(1, remote_addr);
    x->args().set_arg(2, remote_port);
    x->args().set_arg(3, data);

    return _sender->send(*x, callback(this, &XrlSocket4V0p1Client::unmarshall_send_to, cb));
}


/* Unmarshall send_to */
void
XrlSocket4V0p1Client::unmarshall_send_to(
	const XrlError&	e,
	XrlArgs*	a,
	SendToCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlSocket4V0p1Client::send_send_from_multicast_if(
	const char*	dst_xrl_target_name,
	const string&	sockid,
	const IPv4&	group_addr,
	const uint32_t&	group_port,
	const IPv4&	ifaddr,
	const vector<uint8_t>&	data,
	const SendFromMulticastIfCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "socket4/0.1/send_from_multicast_if");
        x->args().add(XrlAtom(sockid));
        x->args().add(XrlAtom(group_addr));
        x->args().add(XrlAtom(group_port));
        x->args().add(XrlAtom(ifaddr));
        x->args().add(XrlAtom(data));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, sockid);
    x->args().set_arg(1, group_addr);
    x->args().set_arg(2, group_port);
    x->args().set_arg(3, ifaddr);
    x->args().set_arg(4, data);

    return _sender->send(*x, callback(this, &XrlSocket4V0p1Client::unmarshall_send_from_multicast_if, cb));
}


/* Unmarshall send_from_multicast_if */
void
XrlSocket4V0p1Client::unmarshall_send_from_multicast_if(
	const XrlError&	e,
	XrlArgs*	a,
	SendFromMulticastIfCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlSocket4V0p1Client::send_set_socket_option(
	const char*	dst_xrl_target_name,
	const string&	sockid,
	const string&	optname,
	const uint32_t&	optval,
	const SetSocketOptionCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "socket4/0.1/set_socket_option");
        x->args().add(XrlAtom(sockid));
        x->args().add(XrlAtom(optname));
        x->args().add(XrlAtom(optval));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, sockid);
    x->args().set_arg(1, optname);
    x->args().set_arg(2, optval);

    return _sender->send(*x, callback(this, &XrlSocket4V0p1Client::unmarshall_set_socket_option, cb));
}


/* Unmarshall set_socket_option */
void
XrlSocket4V0p1Client::unmarshall_set_socket_option(
	const XrlError&	e,
	XrlArgs*	a,
	SetSocketOptionCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlSocket4V0p1Client::send_set_socket_option_txt(
	const char*	dst_xrl_target_name,
	const string&	sockid,
	const string&	optname,
	const string&	optval,
	const SetSocketOptionTxtCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "socket4/0.1/set_socket_option_txt");
        x->args().add(XrlAtom(sockid));
        x->args().add(XrlAtom(optname));
        x->args().add(XrlAtom(optval));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, sockid);
    x->args().set_arg(1, optname);
    x->args().set_arg(2, optval);

    return _sender->send(*x, callback(this, &XrlSocket4V0p1Client::unmarshall_set_socket_option_txt, cb));
}


/* Unmarshall set_socket_option_txt */
void
XrlSocket4V0p1Client::unmarshall_set_socket_option_txt(
	const XrlError&	e,
	XrlArgs*	a,
	SetSocketOptionTxtCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}
