#ifndef _MIDL_PLUGIN_BASE_H_
#define _MIDL_PLUGIN_BASE_H_
#include <atomic>
#include <memory>
#include <string>
#include <unordered_map>

class PluginBase
{
public:
	PluginBase() : started_(false) {};
	virtual ~PluginBase() = default;
	PluginBase(const PluginBase&) = delete;
	PluginBase(PluginBase&&) = delete;
	PluginBase& operator=(const PluginBase&) = delete;
	PluginBase& operator=(PluginBase&&) = delete;

	virtual void Start() = 0; // Call to RpcStart
	virtual void Stop() = 0; // Call to RpcShutdown

	//virtual bool HealthCheck(); // Call to RpcPluginHealthCheck
	virtual int DoCommand(int command, unsigned char* result) = 0;	// Call to RpcCommandPlugin

	bool GetListenState() const 
	{
		return started_;
	}

protected:
	void SetListenState(bool state) noexcept
	{
		started_ = state;
	}

protected:
	std::atomic<bool> started_;
	std::unordered_map<int, void*> command_list_;
};

#endif