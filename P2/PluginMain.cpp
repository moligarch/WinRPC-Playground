// Plugin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>

#include "Executer.h"

int main()
{
	auto server = Executer::Get();
	server->Start();

	while (server->GetListenState())
	{
		std::cout << "Waiting to get command..." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(5));
	}
	
	return 0;
}