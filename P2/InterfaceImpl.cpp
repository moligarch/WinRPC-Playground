#include "rpc_plugin_h.h"
#include "rpc_controller_h.h"

#include <iostream>
#include <thread>
#include "Executer.h"
#include <iomanip>




int RpcStart(
    /* [in] */ handle_t IDL_handl)
{
    return 0;
}

int RpcShutdown(
    /* [in] */ handle_t IDL_handle)
{
    auto server = Executer::Get();
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
        return 1;
    }
    
    return 0;
}

boolean RpcPluginHealthCheck(
    /* [in] */ handle_t IDL_handle) {
    if (true) {

    }
}

void RpcCommandPlugin(
    /* [in] */ handle_t h,
    /* [in] */ int command,
    /* [string][out][in] */ unsigned char* result)
{

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