// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001-2003 International Computer Science Institute
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software")
// to deal in the Software without restriction, subject to the conditions
// listed in the XORP LICENSE file. These conditions include: you must
// preserve this copyright notice, and you cannot mention the copyright
// holders in advertising related to the Software without their permission.
// The Software is provided WITHOUT ANY WARRANTY, EXPRESS OR IMPLIED. This
// notice is a summary of the XORP LICENSE file; the license in that file is
// legally binding.

// $XORP: xorp/rtrmgr/xorp_client.hh,v 1.5 2003/03/14 23:18:46 hodson Exp $


#ifndef __RTRMGR_XORP_CLIENT_HH__
#define __RTRMGR_XORP_CLIENT_HH__

#include <list>
#include <string>
#include "libxorp/debug.h"
#include "libxorp/xorp.h"
#include "libxorp/eventloop.hh"
#include "libxorp/xlog.h"
#include "libxorp/ipv4net.hh"
#include "libxorp/timer.hh"
#include "libxipc/xrl_router.hh"
#include "libxipc/xrl_pf_sudp.hh"
#include "unexpanded_xrl.hh"

typedef XrlRouter::XrlCallback XCCommandCallback;

class XorpBatchItem;
class XorpClient;
class ConfigTreeNode;
class ModuleManager;
class Module;

class XorpBatch {
public:
    XorpBatch(XorpClient *xclient, uint tid);
    typedef XorpCallback2<void, int, const string&>::RefPtr CommitCallback;
    int start(CommitCallback ending_cb);
    int add_xrl(const UnexpandedXrl &xrl, XCCommandCallback cb, 
		bool no_execute, uint32_t retries = 0, uint32_t retry_ms = 0);
    int add_module_start(ModuleManager* mmgr, Module* module,
			 XCCommandCallback cb, bool no_execute);
    
    void batch_item_done(XorpBatchItem* tran_xrl, bool status, 
			 const string& errmsg);
    void abort_transaction(const string& errmsg);

    EventLoop& eventloop() const;

    XorpClient* client() const;
    
private:
    uint _tid;
    XorpClient *_xclient;
    list <XorpBatchItem*> _batch_items;
    CommitCallback _list_complete_callback;
};

class XorpBatchItem {
public:
    XorpBatchItem(XrlRouter::XrlCallback cb, bool no_execute);
    virtual ~XorpBatchItem() {};
    virtual int execute(XorpClient *xclient, XorpBatch *batch, 
			string& errmsg) = 0;
protected:
    XCCommandCallback _callback;
    XorpBatch* _batch;
    bool _no_execute;
};

class XorpBatchXrlItem : public XorpBatchItem {
public:
    XorpBatchXrlItem(const UnexpandedXrl&     xrl,
		     const XCCommandCallback& cb,
		     bool		      no_execute,
		     uint32_t		      retries = 0,
		     uint32_t 		      retry_ms = 1000);

    int execute(XorpClient* xclient,
		XorpBatch*  batch, 
		string&	    errmsg);

protected:
    void response_callback(const XrlError& err, 
			   XrlArgs*	   xrlargs);

    void retry_execution();

protected:
    UnexpandedXrl _unexpanded_xrl;

    // Retry related
    XorpTimer _retry_timer;
    uint32_t  _retries;
    uint32_t  _retry_ms;
};

class XorpBatchModuleItem : public XorpBatchItem {
public:
    XorpBatchModuleItem(ModuleManager* mmgr, Module* module,
			bool start,
			XCCommandCallback cb, bool no_execute);
    int execute(XorpClient *xclient, XorpBatch *batch, 
		string& errmsg);
    void response_callback(bool success, string errmsg);
public:
    ModuleManager* _mmgr;
    Module* _module;
    bool _start; //true = start module, false = stop module
    XorpTimer _startup_timer;
};

class XorpClient  {
public:
    XorpClient(EventLoop& eventloop, XrlRouter *xrlrouter);
    ~XorpClient() {};
    int send_xrl(uint tid, 
		 const UnexpandedXrl &xrl, 
		 XrlRouter::XrlCallback cb,
		 bool no_execute,
		 uint32_t retries = 0,
		 uint32_t retry_ms = 0);
    int start_module(uint tid, ModuleManager* mmgr, Module* module,
		     XCCommandCallback cb, bool no_execute);
    int stop_module(uint tid, ModuleManager* mmgr, Module* module,
		    XCCommandCallback cb, bool no_execute);
    int send_now(const Xrl &xrl, XrlRouter::XrlCallback cb, 
		 const string& expected_response, bool no_execute);
    XrlArgs fake_return_args(const string& xrl_return_spec);

    uint begin_transaction();
    int end_transaction(uint tid, XorpBatch::CommitCallback ending_cb);
    void remove_transaction(uint tid);

    EventLoop& eventloop() const { return _eventloop; }
    
private:
    EventLoop& _eventloop;
    XrlRouter *_xrlrouter;
#ifdef OLDWAY
    int _cmd_done;
    int _result;
    XrlError _error;
#endif
    uint _max_tid;
    map <uint, XorpBatch*> _transactions;
};

#endif // __RTRMGR_XORP_CLIENT_HH__
