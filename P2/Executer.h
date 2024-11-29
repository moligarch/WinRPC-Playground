#ifndef _PLUGIN_SERVER_H_
#define _PLUGIN_SERVER_H_

#include "midl/rpc_plugin_h.h"


class Executer
{
public:
	~Executer();
	Executer(const Executer&) = delete;
	Executer(Executer&&) = delete;
	Executer& operator=(const Executer&) = delete;
	Executer& operator=(Executer&&) = delete;

	void Start();
	void Stop();

	static Executer* Get();
	bool GetListenState() const;
private:
	Executer() noexcept;
	void SetListenState(bool state) noexcept;

private:
	static inline bool started_{ false };
};

#endif