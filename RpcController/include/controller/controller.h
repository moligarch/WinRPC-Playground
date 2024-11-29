#ifndef _PLUGIN_SERVER_H_
#define _PLUGIN_SERVER_H_
#include <string>
#include <unordered_map>
#include <optional>
#include <mutex>

#include <rpc.h>

#include "midl/rpc_controller_h.h"
#include "plugin/plugin.h"

class Controller
{
public:
	~Controller();
	Controller(const Controller&) = delete;
	Controller(Controller&&) = delete;
	Controller& operator=(const Controller&) = delete;
	Controller& operator=(Controller&&) = delete;

	static Controller* Get();

	bool AddPlugin(Plugin plugin_instance);
	std::optional<Plugin> GetPluginByID(int id);

	bool ShutdownPlugin(int id = -1);


	void Start();
	void Stop();

	bool GetListenState() const
	{
		return started_;
	}
	std::unordered_map<int, Plugin> GetPluginList() const {
		return plugin_list_;
	}
	
private:
	Controller();
	void SetListenState(bool state) noexcept
	{
		started_ = state;
	}
	void StartListen();
	bool PluginExists(int id);

private:
	std::atomic<bool> started_;
	std::thread listener_;
	std::mutex mtx_lock_;
	std::unordered_map<int, Plugin> plugin_list_;
};



#endif