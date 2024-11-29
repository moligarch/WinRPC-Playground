#include "Plugin1.h"

#include <midl/rpc_plugin_h.h>
#include <iostream>

// Naive security callback.
RPC_STATUS CALLBACK SecurityCallback(RPC_IF_HANDLE /*hInterface*/, void* /*pBindingHandle*/)
{
	return RPC_S_OK; // Always allow anyone.
}


Plugin1::Plugin1()
{
	SetListenState(false);
}

void Plugin1::StartListen()
{
	auto status = RpcServerListen(
		1,						// Recommended minimum number of threads.
		RPC_C_LISTEN_MAX_CALLS_DEFAULT,	// Recommended maximum number of threads.
		FALSE);							// Start listening now.

	if (status) {
		SetListenState(false);
	}

}

Plugin1::~Plugin1()
{
	if (GetListenState())
		Stop();
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
	unsigned char* endpoint{ (unsigned char*)"12345" };
	unsigned char* security{ nullptr };

	// Uses the protocol combined with the endpoint for receiving
	// remote procedure calls.
	status = RpcServerUseProtseqEpA(
		protocol_seq,					// Use TCP/IP protocol.
		RPC_C_PROTSEQ_MAX_REQS_DEFAULT,	// Backlog queue length for TCP/IP.
		endpoint,						// TCP/IP port to use.
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
	listener_ = std::thread(&Plugin1::StartListen, this);
}

void Plugin1::Stop()
{
	RPC_STATUS status;

	status = RpcMgmtStopServerListening(0);

	if (status)
		exit(status);

	status = RpcServerUnregisterIf(NULL, NULL, FALSE);

	if (status)
		exit(status);

	status = RpcBindingFree(&Plugin_v1_0_s_ifspec);

	if (status)
		exit(status);

	if (listener_.joinable()) {
		listener_.join();
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
