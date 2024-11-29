#include "controller/controller.h"

#include "midl/rpc_plugin_h.h"
#include <iostream>
#include <plugin/plugin.h>
#include <optional>
#include <iomanip>

Controller::Controller()
{
    SetListenState(false);
}

Controller::~Controller()
{
    if (GetListenState())
        Stop();
}

Controller* Controller::Get()
{
    static std::unique_ptr< Controller> instance{ new Controller() };
    return instance.get();
}

bool Controller::AddPlugin(Plugin plugin_instance)
{
    if (plugin_list_.find(plugin_instance.GetID()) != plugin_list_.end()) {
        plugin_list_.emplace(plugin_instance.GetID(), std::move(plugin_instance) );
        return true;
    }
    return false;
}

std::optional<Plugin> Controller::GetPluginByID(int id)
{
    if (PluginExists(id)) {
        return plugin_list_.at(id);
    }
    return std::nullopt;
}

bool Controller::ShutdownPlugin(int id)
{
    bool state{ false };
    bool done{ true };
    if (id == -1) {
        std::cout << "Shutting down all plugins ..." << std::endl;
        for (auto& plugin : plugin_list_) {
            std::cout << "Shutdown Command Sent to Plugin with ID:  "<< plugin.first << std::endl;
            state = ShutdownPlugin(plugin.first);
            if (state) {
                std::cout << "ID: " << std::setw(15) << std::left << plugin.first << "Accepted shutdown command succesfully." << std::endl;
            }
            else {
                std::cout << "ID: " << std::setw(15) << std::left << plugin.first << "Rejected shutdown command." << std::endl;
            }

            done = done && state;
        }
        return done;
    }


    if (!PluginExists(id)) {
        std::cout << "Plugin with specified ID does not registered in Controller." << std::endl;
        return true;
    }
    if (plugin_list_.at(id).RpcShutdown()) {
        plugin_list_.erase(id);
        state = true;
    }
    return state;
}

void Controller::Start()
{
    if (GetListenState()) {
        return;
    }

    SetListenState(true);

    RPC_STATUS status;

    unsigned char* protocol_seq{ (unsigned char*)"ncacn_ip_tcp" };
    unsigned char* endpoint{ (unsigned char*)"54321" };
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
        Controller_v1_0_s_ifspec,					// Interface to register.
        NULL,									// Use the MIDL generated entry-point vector.
        NULL,									// Use the MIDL generated entry-point vector.
        RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH,	// Forces use of security callback.
        RPC_C_LISTEN_MAX_CALLS_DEFAULT,			// Use default number of concurrent calls.
        (unsigned)-1,							// Infinite max size of incoming data blocks.
        nullptr);						// Naive security callback.

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

    listener_ = std::thread(&Controller::StartListen, this);
}

void Controller::Stop()
{
    RPC_STATUS status;

    status = RpcMgmtStopServerListening(0);

    if (status)
        exit(status);

    status = RpcServerUnregisterIf(NULL, NULL, FALSE);

    if (status)
        exit(status);

    status = RpcBindingFree(&Controller_v1_0_s_ifspec);

    if (status)
        exit(status);

    if (listener_.joinable()) {
        listener_.join();
    }
    SetListenState(false);
}

void Controller::StartListen()
{
    auto status = RpcMgmtWaitServerListen();
    SetListenState(false); // Finishing RpcMgmtWaitServerListen means listening stopped.
    if (status) {
        // to do
    }
}

bool Controller::PluginExists(int id)
{
    std::lock_guard<std::mutex> lock(mtx_lock_);
    return plugin_list_.find(id) != plugin_list_.end();
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