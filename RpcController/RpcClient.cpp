#include "RpcClient.h"

#include "midl/rpc_plugin_h.h"
#include <iostream>

RpcClient::RpcClient()
{
    unsigned char* uuid{ nullptr };
    unsigned char* protocol_seq{ (unsigned char*)"ncacn_ip_tcp" };
    unsigned char* network_address{ (unsigned char*)"localhost" };
    unsigned char* endpoint{ (unsigned char*)"12345" };
    unsigned char* option{ nullptr };

    status_ = RpcStringBindingComposeA(uuid, protocol_seq, network_address, endpoint, option, &str_bind_);

    if (status_)
        exit(status_);

    status_ = RpcBindingFromStringBindingA(str_bind_, &Plugin_v1_0_c_ifspec);

    if (status_)
        exit(status_);
}

RpcClient::~RpcClient()
{
    // Free the memory allocated by a string.
    if (str_bind_ != nullptr) {
        status_ = RpcStringFreeA(&str_bind_); // String to be freed.
        str_bind_ = nullptr;
    }

    if (status_) {
        exit(status_);
    }

    // Releases binding handle resources and disconnects from the server.
    status_ = RpcBindingFree(&Plugin_v1_0_c_ifspec);

    if (status_) {
        exit(status_);
    }
}

int RpcClient::Terminate()
{
    int result{ 0 };
    RpcTryExcept
    {
        // Calls the RPC function. The hExample1Binding binding handle
        // is used implicitly.
        // Connection is done here.
        return RpcShutdown(Plugin_v1_0_c_ifspec);
    }
        RpcExcept(1)
    {
        std::cout << "Runtime reported exception " << RpcExceptionCode() << std::endl;
        return 0;
    }
    RpcEndExcept
}

int RpcClient::SendPluginCommand(int command, std::string& result)
{
    RpcTryExcept
    {
        RpcCommandPlugin(Plugin_v1_0_c_ifspec, command, reinterpret_cast<unsigned char*>(const_cast<char*>(result.c_str())));
    }
        RpcExcept(1)
    {
        std::cout << "Runtime reported exception " << RpcExceptionCode() << std::endl;
        return 0;
    }
    RpcEndExcept
        return 1;
}


void* __RPC_USER midl_user_allocate(size_t size)
{
    return malloc(size);
}

// Memory deallocation function for RPC.
void __RPC_USER midl_user_free(void* p)
{
    free(p);
}