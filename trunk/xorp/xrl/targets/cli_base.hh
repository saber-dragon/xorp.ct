/*
 * Copyright (c) 2002 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by '../scripts/tgt-gen'.
 *
 * $XORP: xorp/xrl/targets/cli_base.hh,v 1.4 2003/01/28 00:37:56 hodson Exp $
 */


#ifndef __XRL_INTERFACES_CLI_BASE_HH__
#define __XRL_INTERFACES_CLI_BASE_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XrlCliTarget"

#include "libxorp/xlog.h"
#include "libxipc/xrl_cmd_map.hh"

class XrlCliTargetBase {
protected:
    XrlCmdMap* _cmds;
    
public:
    XrlCliTargetBase(XrlCmdMap* cmds) : _cmds(cmds) { add_handlers(); }
    virtual ~XrlCliTargetBase() { remove_handlers(); }

    inline const string& name() const { return _cmds->name(); }
    inline const char* version() const { return "cli/0.0"; }

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

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Enable/disable/start/stop the CLI.
     *  
     *  @param fail true if failure has occured.
     *  
     *  @param reason contains failure reason if it occured.
     */
    virtual XrlCmdError cli_manager_0_1_enable_cli(
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError cli_manager_0_1_disable_cli(
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError cli_manager_0_1_start_cli(
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError cli_manager_0_1_stop_cli(
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Add a subnet address to the list of subnet addresses enabled for CLI
     *  access. This method can be called more than once to add a number of
     *  subnet addresses.
     *  
     *  @param subnet_addr the subnet address to add.
     *  
     *  @param fail true if failure has occured.
     *  
     *  @param reason contains failure reason if it occured.
     */
    virtual XrlCmdError cli_manager_0_1_add_enable_cli_access_from_subnet4(
	// Input values, 
	const IPv4Net&	subnet_addr, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError cli_manager_0_1_add_enable_cli_access_from_subnet6(
	// Input values, 
	const IPv6Net&	subnet_addr, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Delete a subnet address from the list of subnet addresses enabled for
     *  CLI access.
     *  
     *  @param subnet_addr the subnet address to delete.
     *  
     *  @param fail true if failure has occured.
     *  
     *  @param reason contains failure reason if it occured.
     */
    virtual XrlCmdError cli_manager_0_1_delete_enable_cli_access_from_subnet4(
	// Input values, 
	const IPv4Net&	subnet_addr, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError cli_manager_0_1_delete_enable_cli_access_from_subnet6(
	// Input values, 
	const IPv6Net&	subnet_addr, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Add a subnet address to the list of subnet addresses disabled for CLI
     *  access. This method can be called more than once to add a number of
     *  subnet addresses.
     *  
     *  @param subnet_addr the subnet address to add.
     *  
     *  @param fail true if failure has occured.
     *  
     *  @param reason contains failure reason if it occured.
     */
    virtual XrlCmdError cli_manager_0_1_add_disable_cli_access_from_subnet4(
	// Input values, 
	const IPv4Net&	subnet_addr, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError cli_manager_0_1_add_disable_cli_access_from_subnet6(
	// Input values, 
	const IPv6Net&	subnet_addr, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Delete a subnet address from the list of subnet addresses disabled for
     *  CLI access.
     *  
     *  @param subnet_addr the subnet address to delete.
     *  
     *  @param fail true if failure has occured.
     *  
     *  @param reason contains failure reason if it occured.
     */
    virtual XrlCmdError cli_manager_0_1_delete_disable_cli_access_from_subnet4(
	// Input values, 
	const IPv4Net&	subnet_addr, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError cli_manager_0_1_delete_disable_cli_access_from_subnet6(
	// Input values, 
	const IPv6Net&	subnet_addr, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Add a CLI command to the CLI manager
     *  
     *  @param processor_name the name of the module that will process that
     *  command.
     *  
     *  @param command_name the name of the command to add.
     *  
     *  @param command_help the help for the command to add.
     *  
     *  @param is_command_cd is true, the string that will replace the CLI
     *  prompt after we "cd" to that level of the CLI command-tree.
     *  
     *  @param command_cd_prompt if
     *  
     *  @param is_command_processor if true, this is a processing command that
     *  would be performed by processor_name.
     *  
     *  @param fail true if failure has occured.
     *  
     *  @param reason contains failure reason if it occured.
     */
    virtual XrlCmdError cli_manager_0_1_add_cli_command(
	// Input values, 
	const string&	processor_name, 
	const string&	command_name, 
	const string&	command_help, 
	const bool&	is_command_cd, 
	const string&	command_cd_prompt, 
	const bool&	is_command_processor, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Delete a CLI command from the CLI manager
     *  
     *  @param processor_name the name of the module that sends the request.
     *  
     *  @param command_name the name of the command to delete.
     *  
     *  @param fail true if failure has occured.
     *  
     *  @param reason contains failure reason if it occured.
     */
    virtual XrlCmdError cli_manager_0_1_delete_cli_command(
	// Input values, 
	const string&	processor_name, 
	const string&	command_name, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

private:
    const XrlCmdError handle_common_0_1_get_target_name(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_common_0_1_get_version(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_cli_manager_0_1_enable_cli(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_cli_manager_0_1_disable_cli(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_cli_manager_0_1_start_cli(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_cli_manager_0_1_stop_cli(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_cli_manager_0_1_add_enable_cli_access_from_subnet4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_cli_manager_0_1_add_enable_cli_access_from_subnet6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_cli_manager_0_1_delete_enable_cli_access_from_subnet4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_cli_manager_0_1_delete_enable_cli_access_from_subnet6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_cli_manager_0_1_add_disable_cli_access_from_subnet4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_cli_manager_0_1_add_disable_cli_access_from_subnet6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_cli_manager_0_1_delete_disable_cli_access_from_subnet4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_cli_manager_0_1_delete_disable_cli_access_from_subnet6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_cli_manager_0_1_add_cli_command(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_cli_manager_0_1_delete_cli_command(const Xrl& x, XrlArgs* a);

    void add_handlers()
    {
	if (_cmds->add_handler("common/0.1/get_target_name", 
	    callback(this, &XrlCliTargetBase::handle_common_0_1_get_target_name)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://cli/common/0.1/get_target_name");
	}
	if (_cmds->add_handler("common/0.1/get_version", 
	    callback(this, &XrlCliTargetBase::handle_common_0_1_get_version)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://cli/common/0.1/get_version");
	}
	if (_cmds->add_handler("cli_manager/0.1/enable_cli", 
	    callback(this, &XrlCliTargetBase::handle_cli_manager_0_1_enable_cli)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://cli/cli_manager/0.1/enable_cli");
	}
	if (_cmds->add_handler("cli_manager/0.1/disable_cli", 
	    callback(this, &XrlCliTargetBase::handle_cli_manager_0_1_disable_cli)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://cli/cli_manager/0.1/disable_cli");
	}
	if (_cmds->add_handler("cli_manager/0.1/start_cli", 
	    callback(this, &XrlCliTargetBase::handle_cli_manager_0_1_start_cli)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://cli/cli_manager/0.1/start_cli");
	}
	if (_cmds->add_handler("cli_manager/0.1/stop_cli", 
	    callback(this, &XrlCliTargetBase::handle_cli_manager_0_1_stop_cli)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://cli/cli_manager/0.1/stop_cli");
	}
	if (_cmds->add_handler("cli_manager/0.1/add_enable_cli_access_from_subnet4", 
	    callback(this, &XrlCliTargetBase::handle_cli_manager_0_1_add_enable_cli_access_from_subnet4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://cli/cli_manager/0.1/add_enable_cli_access_from_subnet4");
	}
	if (_cmds->add_handler("cli_manager/0.1/add_enable_cli_access_from_subnet6", 
	    callback(this, &XrlCliTargetBase::handle_cli_manager_0_1_add_enable_cli_access_from_subnet6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://cli/cli_manager/0.1/add_enable_cli_access_from_subnet6");
	}
	if (_cmds->add_handler("cli_manager/0.1/delete_enable_cli_access_from_subnet4", 
	    callback(this, &XrlCliTargetBase::handle_cli_manager_0_1_delete_enable_cli_access_from_subnet4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://cli/cli_manager/0.1/delete_enable_cli_access_from_subnet4");
	}
	if (_cmds->add_handler("cli_manager/0.1/delete_enable_cli_access_from_subnet6", 
	    callback(this, &XrlCliTargetBase::handle_cli_manager_0_1_delete_enable_cli_access_from_subnet6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://cli/cli_manager/0.1/delete_enable_cli_access_from_subnet6");
	}
	if (_cmds->add_handler("cli_manager/0.1/add_disable_cli_access_from_subnet4", 
	    callback(this, &XrlCliTargetBase::handle_cli_manager_0_1_add_disable_cli_access_from_subnet4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://cli/cli_manager/0.1/add_disable_cli_access_from_subnet4");
	}
	if (_cmds->add_handler("cli_manager/0.1/add_disable_cli_access_from_subnet6", 
	    callback(this, &XrlCliTargetBase::handle_cli_manager_0_1_add_disable_cli_access_from_subnet6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://cli/cli_manager/0.1/add_disable_cli_access_from_subnet6");
	}
	if (_cmds->add_handler("cli_manager/0.1/delete_disable_cli_access_from_subnet4", 
	    callback(this, &XrlCliTargetBase::handle_cli_manager_0_1_delete_disable_cli_access_from_subnet4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://cli/cli_manager/0.1/delete_disable_cli_access_from_subnet4");
	}
	if (_cmds->add_handler("cli_manager/0.1/delete_disable_cli_access_from_subnet6", 
	    callback(this, &XrlCliTargetBase::handle_cli_manager_0_1_delete_disable_cli_access_from_subnet6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://cli/cli_manager/0.1/delete_disable_cli_access_from_subnet6");
	}
	if (_cmds->add_handler("cli_manager/0.1/add_cli_command", 
	    callback(this, &XrlCliTargetBase::handle_cli_manager_0_1_add_cli_command)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://cli/cli_manager/0.1/add_cli_command");
	}
	if (_cmds->add_handler("cli_manager/0.1/delete_cli_command", 
	    callback(this, &XrlCliTargetBase::handle_cli_manager_0_1_delete_cli_command)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://cli/cli_manager/0.1/delete_cli_command");
	}
    }

    void remove_handlers()
    {
	_cmds->remove_handler("common/0.1/get_target_name");
	_cmds->remove_handler("common/0.1/get_version");
	_cmds->remove_handler("cli_manager/0.1/enable_cli");
	_cmds->remove_handler("cli_manager/0.1/disable_cli");
	_cmds->remove_handler("cli_manager/0.1/start_cli");
	_cmds->remove_handler("cli_manager/0.1/stop_cli");
	_cmds->remove_handler("cli_manager/0.1/add_enable_cli_access_from_subnet4");
	_cmds->remove_handler("cli_manager/0.1/add_enable_cli_access_from_subnet6");
	_cmds->remove_handler("cli_manager/0.1/delete_enable_cli_access_from_subnet4");
	_cmds->remove_handler("cli_manager/0.1/delete_enable_cli_access_from_subnet6");
	_cmds->remove_handler("cli_manager/0.1/add_disable_cli_access_from_subnet4");
	_cmds->remove_handler("cli_manager/0.1/add_disable_cli_access_from_subnet6");
	_cmds->remove_handler("cli_manager/0.1/delete_disable_cli_access_from_subnet4");
	_cmds->remove_handler("cli_manager/0.1/delete_disable_cli_access_from_subnet6");
	_cmds->remove_handler("cli_manager/0.1/add_cli_command");
	_cmds->remove_handler("cli_manager/0.1/delete_cli_command");
    }
};

#endif /* __XRL_INTERFACES_CLI_BASE_HH__ */
