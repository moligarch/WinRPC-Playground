#include "Plugin1.h"

#include <iostream>

#include <midl/rpc_controller_h.h>
#include <midl/rpc_plugin_h.h>
#include <string>

// Naive security callback.
RPC_STATUS CALLBACK SecurityCallback(RPC_IF_HANDLE /*hInterface*/, void* /*pBindingHandle*/)
{
	return RPC_S_OK; // Always allow anyone.
}


Plugin1::Plugin1() : 
	plugin_handle_(NULL),
	id_(29),
	endpoint_((unsigned char*)"12345")
{
	SetListenState(false);

	RPC_STATUS status;

	status = RpcStringBindingComposeA(
		NULL,                            
		(unsigned char*)("ncacn_ip_tcp"),
		(unsigned char*)("localhost"),   
		(unsigned char*)("54321"),       
		NULL,                            
		&str_bind_);                     

	if (status)
		exit(status);

	status = RpcBindingFromStringBindingA(str_bind_, &hController);

	if (status)
		exit(status);

}

void Plugin1::Register()
{
	while (true) {
		RpcTryExcept
		{
			auto state = ::RpcControllerHealthCheck(plugin_handle_, id_, endpoint_);
			if (state) {
				break;
			}
		}
			RpcExcept(1)
		{
			std::cerr << "Failed to communicate with Controller: " << RpcExceptionCode()	<< std::endl;
			std::cout << "Trying to register on controller ..." << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(5));
		}
		RpcEndExcept
	}
	std::cout << "Successfully registered." << std::endl;
}

void Plugin1::StartListen()
{
	std::lock_guard<std::mutex> lk(mtx_);
	auto status = RpcMgmtWaitServerListen();
	SetListenState(false); // Finishing RpcMgmtWaitServerListen means listening stopped.

	if (status) {
		// to do
	}
}

Plugin1::~Plugin1()
{
	if (GetListenState())
		Stop();

	// Free the memory allocated by a string.
	auto status = RpcStringFreeA(
		&str_bind_); // String to be freed.

	if (status)
		exit(status);

	// Releases binding handle resources and disconnects from the server.
	status = RpcBindingFree(
		&hController); // Frees the implicit binding handle defined in the IDL file.

	if (status)
		exit(status);
}

Plugin1* Plugin1::Get()
{
	static std::unique_ptr<Plugin1> instance{ new Plugin1() };
	return instance.get();
}

void Plugin1::Start()
{
	if (GetListenState()) {
		return;
	}

	SetListenState(true);

	RPC_STATUS status;

	unsigned char* protocol_seq{ (unsigned char*)"ncacn_ip_tcp" };
	unsigned char* security{ nullptr };

	// Uses the protocol combined with the endpoint for receiving
	// remote procedure calls.
	status = RpcServerUseProtseqEpA(
		protocol_seq,					// Use TCP/IP protocol.
		RPC_C_PROTSEQ_MAX_REQS_DEFAULT,	// Backlog queue length for TCP/IP.
		endpoint_,						// TCP/IP port to use.
		NULL);							// No security.


	if (status) {
		exit(status);
	}

	// Registers the Plugin interface.
	status = RpcServerRegisterIf2(
		Plugin_v1_0_s_ifspec,					// Interface to register.
		NULL,									// Use the MIDL generated entry-point vector.
		NULL,									// Use the MIDL generated entry-point vector.
		RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH,	// Forces use of security callback.
		RPC_C_LISTEN_MAX_CALLS_DEFAULT,			// Use default number of concurrent calls.
		(unsigned)-1,							// Infinite max size of incoming data blocks.
		SecurityCallback);						// Naive security callback.

	if (status) {
		exit(status);
	}

	status = RpcServerListen(
		1,						// Recommended minimum number of threads.
		RPC_C_LISTEN_MAX_CALLS_DEFAULT,	// Recommended maximum number of threads.
		TRUE);							// Do Not start listening now.

	if (status) {
		exit(status);
	}

	listener_ = std::thread(&Plugin1::StartListen, this);

	Register();
}

void Plugin1::Stop()
{
	RPC_STATUS status;

	status = RpcMgmtStopServerListening(0);

	if (status)
		exit(status);

	if (listener_.joinable()) {
		listener_.join();
	}
	
	status = RpcServerUnregisterIf(NULL, NULL, FALSE);

	if (status)
		exit(status);

	if (plugin_handle_) {
		status = RpcBindingFree(&plugin_handle_);

		if (status)
			exit(status);
	}

	SetListenState(false);
}

int Plugin1::DoCommand(int command, unsigned char* result)
{
	std::string out{ "Command \"" + std::to_string(command) + "\" Called."};
	std::cout << out << std::endl;
	result = reinterpret_cast<unsigned char*>(const_cast<char*>(out.c_str()));
	return 0;
}
