#ifndef _PLUGIN_1_H_
#define _PLUGIN_1_H_

#include <midl/PluginBase.h>

#include <thread>
#include <mutex>

#include <midl/rpc_plugin_h.h>
#include <midl/rpc_controller_h.h>

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
	void Register();
	void StartListen();

private:
	int id_;
	unsigned char* endpoint_;
	handle_t plugin_handle_;
	std::thread listener_;
	std::mutex mtx_;
	unsigned char* str_bind_ = nullptr;
};


#endif