#include "plugin/plugin.h"

#include <midl/rpc_controller_h.h>


#include <iostream>

Plugin::Plugin(handle_t handle, int id, unsigned char* endpoint) :
    plugin_binding_handle_(handle),
    id_(id),
    endpoint_(endpoint)
{
    unsigned char* uuid{ nullptr };
    unsigned char* protocol_seq{ (unsigned char*)"ncacn_ip_tcp" };
    unsigned char* network_address{ (unsigned char*)"localhost" };
    unsigned char* option{ nullptr };

    status_ = RpcStringBindingComposeA(uuid, protocol_seq, network_address, endpoint_, option, &str_bind_);

    if (status_)
        exit(status_);

    status_ = RpcBindingFromStringBindingA(str_bind_, &plugin_binding_handle_);

    if (status_)
        exit(status_);
}

Plugin::~Plugin()
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
    status_ = RpcBindingFree(&plugin_binding_handle_);

    if (status_) {
        exit(status_);
    }
}

bool Plugin::RpcShutdown()
{
    bool state{ false };
    RpcTryExcept
    {
        ::RpcShutdown(plugin_binding_handle_, (boolean*)&state);
        return state;

    } RpcExcept(1)
    {
        std::cout << "Runtime reported exception " << RpcExceptionCode() << std::endl;
        return false;
    }
    RpcEndExcept
}

bool Plugin::RpcPluginHealthCheck()
{
	return true;
}



void DoPluginCommand(handle_t handle, int command, unsigned char* result) {
    RpcTryExcept
    {
        ::RpcCommandPlugin(handle, command, result);
    }
        RpcExcept(1)
    {
        std::cout << "Runtime reported exception " << RpcExceptionCode() << std::endl;
        result = (unsigned char*)"Failed To Get Result";
    }
    RpcEndExcept
}

std::string Plugin::RpcCommandPlugin(int command)
{
    std::string result;
    DoPluginCommand(plugin_binding_handle_, command, reinterpret_cast<unsigned char*>(result.data()));
    return result;
}

int Plugin::GetID() const
{
    return id_;
}
