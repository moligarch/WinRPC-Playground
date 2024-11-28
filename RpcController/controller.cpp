// RpcController.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "RpcClient.h"

int main()
{
    int temp;
    auto plugin{ RpcClient() };
    std::cout << "Kill Plugin?(0 for no / 1 for yes)\n";
    std::cin >> temp;

    switch (temp)
    {
    case 1:
        temp = plugin.Terminate();
        if (temp == 1) {
            std::cout << "Plugin Successfully Terminated." << std::endl;
        }
        break;
    default:
        std::cout << "Exiting Controller ..." << std::endl;
        break;
    }

    return 0;
}