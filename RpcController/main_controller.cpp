// RpcController.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "controller/controller.h"

int main()
{
    auto controller = Controller::Get();
    
    while (controller->GetPluginList().size() == 0) {
        std::cout << "Wait for Plugin ..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
   }


    std::cout << "Exiting Controller ..." << std::endl;
    return 0;
}