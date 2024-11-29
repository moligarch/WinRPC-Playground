#pragma once

#include <midl/rpc_controller_h.h>
#include <string>

#include <midl/rpc_plugin_h.h>


class Plugin
{
public:
    Plugin() = delete;
    explicit Plugin(handle_t handle, int id, unsigned char*  endpoint);
	~Plugin();

    bool RpcShutdown();

    bool RpcPluginHealthCheck();

    std::string RpcCommandPlugin(int command);

    int GetID() const;
private:
    unsigned char* str_bind_{ nullptr };
    RPC_STATUS status_{ 0 };

    int id_;
    unsigned char* endpoint_;
    handle_t plugin_binding_handle_;
};