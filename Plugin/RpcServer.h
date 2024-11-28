#ifndef _PLUGIN_SERVER_H_
#define _PLUGIN_SERVER_H_

#include "rpc_plugin_h.h"


class RpcServer
{
public:
	~RpcServer();
	RpcServer(const RpcServer&) = delete;
	RpcServer(RpcServer&&) = delete;
	RpcServer& operator=(const RpcServer&) = delete;
	RpcServer& operator=(RpcServer&&) = delete;

	void Start();
	void Stop();

	static RpcServer* Get();
	bool GetListenState() const;
private:
	RpcServer() noexcept;
	void SetListenState(bool state) noexcept;

private:
	static inline bool started_{ false };
};

#endif