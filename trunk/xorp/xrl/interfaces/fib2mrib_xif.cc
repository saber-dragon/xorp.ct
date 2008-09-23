/*
 * Copyright (c) 2001-2008 XORP, Inc.
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP: xorp/xrl/interfaces/fib2mrib_xif.cc,v 1.14 2008/07/23 11:55:15 bms Exp $"

#include "fib2mrib_xif.hh"

bool
XrlFib2mribV0p1Client::send_enable_fib2mrib(
	const char*	dst_xrl_target_name,
	const bool&	enable,
	const EnableFib2MribCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "fib2mrib/0.1/enable_fib2mrib");
        x->args().add(XrlAtom(enable));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, enable);

    return _sender->send(*x, callback(this, &XrlFib2mribV0p1Client::unmarshall_enable_fib2mrib, cb));
}


/* Unmarshall enable_fib2mrib */
void
XrlFib2mribV0p1Client::unmarshall_enable_fib2mrib(
	const XrlError&	e,
	XrlArgs*	a,
	EnableFib2MribCB		cb
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
XrlFib2mribV0p1Client::send_start_fib2mrib(
	const char*	dst_xrl_target_name,
	const StartFib2MribCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "fib2mrib/0.1/start_fib2mrib");
    }

    x->set_target(dst_xrl_target_name);


    return _sender->send(*x, callback(this, &XrlFib2mribV0p1Client::unmarshall_start_fib2mrib, cb));
}


/* Unmarshall start_fib2mrib */
void
XrlFib2mribV0p1Client::unmarshall_start_fib2mrib(
	const XrlError&	e,
	XrlArgs*	a,
	StartFib2MribCB		cb
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
XrlFib2mribV0p1Client::send_stop_fib2mrib(
	const char*	dst_xrl_target_name,
	const StopFib2MribCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "fib2mrib/0.1/stop_fib2mrib");
    }

    x->set_target(dst_xrl_target_name);


    return _sender->send(*x, callback(this, &XrlFib2mribV0p1Client::unmarshall_stop_fib2mrib, cb));
}


/* Unmarshall stop_fib2mrib */
void
XrlFib2mribV0p1Client::unmarshall_stop_fib2mrib(
	const XrlError&	e,
	XrlArgs*	a,
	StopFib2MribCB		cb
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
XrlFib2mribV0p1Client::send_enable_log_trace_all(
	const char*	dst_xrl_target_name,
	const bool&	enable,
	const EnableLogTraceAllCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "fib2mrib/0.1/enable_log_trace_all");
        x->args().add(XrlAtom(enable));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, enable);

    return _sender->send(*x, callback(this, &XrlFib2mribV0p1Client::unmarshall_enable_log_trace_all, cb));
}


/* Unmarshall enable_log_trace_all */
void
XrlFib2mribV0p1Client::unmarshall_enable_log_trace_all(
	const XrlError&	e,
	XrlArgs*	a,
	EnableLogTraceAllCB		cb
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
