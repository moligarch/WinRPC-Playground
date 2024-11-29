#include <midl/rpc_controller_h.h>
#include "controller/controller.h"
#include <iostream>


boolean RpcControllerHealthCheck(
    /* [in] */ handle_t pluginHandle,
    /* [in] */ int pluginID,
    /* [range][in] */ unsigned char* port) {
    auto controller = Controller::Get();
    Plugin p{ pluginHandle, pluginID, port };

    if (controller->AddPlugin(p)) {
        std::cout << "Plugin with ID [" << p.GetID() << "] Registered successfully.";
        return true;
    }
    
    std::cout << "Plugin with ID [" << p.GetID() << "] Already exists.";
    return false;
}
