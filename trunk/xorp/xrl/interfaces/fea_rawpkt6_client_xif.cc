/*
 * Copyright (c) 2001-2009 XORP, Inc.
 * See the XORP LICENSE.lgpl file for licensing, conditions, and warranties
 * on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP: xorp/xrl/interfaces/fea_rawpkt6_client_xif.cc,v 1.18 2008/10/02 21:58:35 bms Exp $"

#include "fea_rawpkt6_client_xif.hh"

bool
XrlRawPacket6ClientV0p1Client::send_recv(
	const char*	dst_xrl_target_name,
	const string&	if_name,
	const string&	vif_name,
	const IPv6&	src_address,
	const IPv6&	dst_address,
	const uint32_t&	ip_protocol,
	const int32_t&	ip_ttl,
	const int32_t&	ip_tos,
	const bool&	ip_router_alert,
	const bool&	ip_internet_control,
	const XrlAtomList&	ext_headers_type,
	const XrlAtomList&	ext_headers_payload,
	const vector<uint8_t>&	payload,
	const RecvCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "raw_packet6_client/0.1/recv");
        x->args().add(XrlAtom(if_name));
        x->args().add(XrlAtom(vif_name));
        x->args().add(XrlAtom(src_address));
        x->args().add(XrlAtom(dst_address));
        x->args().add(XrlAtom(ip_protocol));
        x->args().add(XrlAtom(ip_ttl));
        x->args().add(XrlAtom(ip_tos));
        x->args().add(XrlAtom(ip_router_alert));
        x->args().add(XrlAtom(ip_internet_control));
        x->args().add(XrlAtom(ext_headers_type));
        x->args().add(XrlAtom(ext_headers_payload));
        x->args().add(XrlAtom(payload));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, if_name);
    x->args().set_arg(1, vif_name);
    x->args().set_arg(2, src_address);
    x->args().set_arg(3, dst_address);
    x->args().set_arg(4, ip_protocol);
    x->args().set_arg(5, ip_ttl);
    x->args().set_arg(6, ip_tos);
    x->args().set_arg(7, ip_router_alert);
    x->args().set_arg(8, ip_internet_control);
    x->args().set_arg(9, ext_headers_type);
    x->args().set_arg(10, ext_headers_payload);
    x->args().set_arg(11, payload);

    return _sender->send(*x, callback(this, &XrlRawPacket6ClientV0p1Client::unmarshall_recv, cb));
}


/* Unmarshall recv */
void
XrlRawPacket6ClientV0p1Client::unmarshall_recv(
	const XrlError&	e,
	XrlArgs*	a,
	RecvCB		cb
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
