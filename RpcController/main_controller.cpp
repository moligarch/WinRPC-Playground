// RpcController.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "RpcClient.h"

int main()
{
    char temp;
    auto plugin{ RpcClient() };
    std::cout << "Kill Plugin?(y or n)\n";
    std::cin >> temp;

    if (temp == 'y' || temp == 'Y') {
        auto state = plugin.Terminate();
        if (state == 1) {
            std::cout << "Plugin Successfully Terminated." << std::endl;
            exit(0);
        }
    }

    do {
        std::cout << "Initiating command to server. enter command number (write -1 o exit): ";
        std::cin >> temp;
        std::string res;
        auto state = plugin.SendPluginCommand(temp - '0', res);
        
    } while (temp != -1);
    std::cout << "Exiting Controller ..." << std::endl;
    return 0;
}