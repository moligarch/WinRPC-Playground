#include "Executer.h"
#include <memory>

Executer::Executer() noexcept
{
}

Executer::~Executer()
{
    if(GetListenState())
        Stop();
}

void Executer::Start()
{
    if (GetListenState()) {
        return;
    }

    RPC_STATUS status;

    unsigned char* protocol_seq { (unsigned char*)"ncacn_np" };
    unsigned char* endpoint { (unsigned char*)"\\pipe\\plugin" };
    unsigned char* security{ nullptr };

    status = RpcServerUseProtseqEpA(protocol_seq, RPC_C_LISTEN_MAX_CALLS_DEFAULT, endpoint, security);

    if (status) {
        exit(status);
    }

    // Registers the Example1 interface.
    status = RpcServerRegisterIf2(
        Plugin_v1_0_s_ifspec,						// Interface to register.
        NULL,                             // Use the MIDL generated entry-point vector.
        NULL,									// Use the MIDL generated entry-point vector.
        RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH,	// Forces use of security callback.
        RPC_C_LISTEN_MAX_CALLS_DEFAULT,		// Use default number of concurrent calls.
        (unsigned)-1,						// Infinite max size of incoming data blocks.
        nullptr);				// Naive security callback.

    if (status) {
        exit(status);
    }
    

    // Start to listen for remote procedure
    // calls for all registered interfaces.
    // This call will not return until
    // RpcMgmtStopServerListening is called.
    status = RpcServerListen(
        1,                            // Recommended minimum number of threads.
        RPC_C_LISTEN_MAX_CALLS_DEFAULT,      // Recommended maximum number of threads.
        FALSE);                              // Start listening now.
    
    if (status) {
        exit(status);
    }

    SetListenState(true);
}

void Executer::Stop()
{
    if (!GetListenState()) {
        return;
    }
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

    SetListenState(false);
}

Executer* Executer::Get()
{
    static std::unique_ptr< Executer> instance{ new Executer() };
    return instance.get();
}

bool Executer::GetListenState() const
{
    return started_;
}

void Executer::SetListenState(bool state) noexcept
{
    started_ = state;
}
