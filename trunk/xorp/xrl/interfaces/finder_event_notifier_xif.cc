/*
 * Copyright (c) 2001-2008 XORP, Inc.
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP: xorp/xrl/interfaces/finder_event_notifier_xif.cc,v 1.18 2008/07/23 11:55:16 bms Exp $"

#include "finder_event_notifier_xif.hh"

bool
XrlFinderEventNotifierV0p1Client::send_register_class_event_interest(
	const char*	dst_xrl_target_name,
	const string&	requester_instance,
	const string&	class_name,
	const RegisterClassEventInterestCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "finder_event_notifier/0.1/register_class_event_interest");
        x->args().add(XrlAtom(requester_instance));
        x->args().add(XrlAtom(class_name));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, requester_instance);
    x->args().set_arg(1, class_name);

    return _sender->send(*x, callback(this, &XrlFinderEventNotifierV0p1Client::unmarshall_register_class_event_interest, cb));
}


/* Unmarshall register_class_event_interest */
void
XrlFinderEventNotifierV0p1Client::unmarshall_register_class_event_interest(
	const XrlError&	e,
	XrlArgs*	a,
	RegisterClassEventInterestCB		cb
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
XrlFinderEventNotifierV0p1Client::send_deregister_class_event_interest(
	const char*	dst_xrl_target_name,
	const string&	requester_instance,
	const string&	class_name,
	const DeregisterClassEventInterestCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "finder_event_notifier/0.1/deregister_class_event_interest");
        x->args().add(XrlAtom(requester_instance));
        x->args().add(XrlAtom(class_name));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, requester_instance);
    x->args().set_arg(1, class_name);

    return _sender->send(*x, callback(this, &XrlFinderEventNotifierV0p1Client::unmarshall_deregister_class_event_interest, cb));
}


/* Unmarshall deregister_class_event_interest */
void
XrlFinderEventNotifierV0p1Client::unmarshall_deregister_class_event_interest(
	const XrlError&	e,
	XrlArgs*	a,
	DeregisterClassEventInterestCB		cb
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
XrlFinderEventNotifierV0p1Client::send_register_instance_event_interest(
	const char*	dst_xrl_target_name,
	const string&	requester_instance,
	const string&	instance_name,
	const RegisterInstanceEventInterestCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "finder_event_notifier/0.1/register_instance_event_interest");
        x->args().add(XrlAtom(requester_instance));
        x->args().add(XrlAtom(instance_name));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, requester_instance);
    x->args().set_arg(1, instance_name);

    return _sender->send(*x, callback(this, &XrlFinderEventNotifierV0p1Client::unmarshall_register_instance_event_interest, cb));
}


/* Unmarshall register_instance_event_interest */
void
XrlFinderEventNotifierV0p1Client::unmarshall_register_instance_event_interest(
	const XrlError&	e,
	XrlArgs*	a,
	RegisterInstanceEventInterestCB		cb
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
XrlFinderEventNotifierV0p1Client::send_deregister_instance_event_interest(
	const char*	dst_xrl_target_name,
	const string&	requester_instance,
	const string&	instance_name,
	const DeregisterInstanceEventInterestCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "finder_event_notifier/0.1/deregister_instance_event_interest");
        x->args().add(XrlAtom(requester_instance));
        x->args().add(XrlAtom(instance_name));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, requester_instance);
    x->args().set_arg(1, instance_name);

    return _sender->send(*x, callback(this, &XrlFinderEventNotifierV0p1Client::unmarshall_deregister_instance_event_interest, cb));
}


/* Unmarshall deregister_instance_event_interest */
void
XrlFinderEventNotifierV0p1Client::unmarshall_deregister_instance_event_interest(
	const XrlError&	e,
	XrlArgs*	a,
	DeregisterInstanceEventInterestCB		cb
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
