#include "midl/rpc_plugin_h.h"
#include "midl/rpc_controller_h.h"

#include <iostream>
#include <iomanip>
#include <thread>

#include "Plugin1.h"

void RpcShutdown(
    /* [in] */ handle_t IDL_handle,
    /* [out] */ boolean* state)
{
    auto server = Plugin1::Get();
    std::cout << "RpcController wants to terminate you. Is it OK?\n1.Yes\n2.No\n";
    char verify{};
    std::cin >> verify;
    int choice = verify - '0';
    if (choice == 1) {
        std::cout << "\nGoodbye.";
        std::thread stop_thread([&server]() {
            std::this_thread::sleep_for(std::chrono::seconds(5));
            server->Stop();
            });
        *state = true;
    }
    
    *state = false;
}

boolean RpcPluginHealthCheck(
    /* [in] */ handle_t IDL_handle) {
    return true;
}

void RpcCommandPlugin(
    /* [in] */ handle_t h,
    /* [in] */ int command,
    /* [string][out][in] */ unsigned char* result)
{

    auto server = Plugin1::Get();
    server->DoCommand(command, result);
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