#ifndef _PLUGIN_SERVER_H_
#define _PLUGIN_SERVER_H_
#include <rpc.h>

class RpcClient
{
public:
	RpcClient();
	~RpcClient();

	int Terminate();
private:
	unsigned char* str_bind_{ nullptr };
	RPC_STATUS status_{ 0 };
};



#endif