#ifndef _PLUGIN_1_H_
#define _PLUGIN_1_H_

#include <midl/PluginBase.h>

#include <thread>
#include <mutex>

class Plugin1 : public PluginBase
{
public:
	~Plugin1();

	static Plugin1* Get();

	void Start() override; // Call to RpcStart
	void Stop() override; // Call to RpcShutdown

	//bool HealthCheck() override; // Call to RpcPluginHealthCheck
	int DoCommand(int command, unsigned char* result) override;	// Call to RpcCommandPlugin
	
private:
	Plugin1();
	void StartListen();

private:
	std::thread listener_;
};


#endif