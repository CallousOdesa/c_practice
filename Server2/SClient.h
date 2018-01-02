#pragma once
#include "includes.h"
class SClient
{
public:
	SClient(SOCKET s, SOCKADDR_IN sock_in);
	~SClient();
	void handle();
private:
	SOCKET clientSocket;
	SOCKADDR_IN c_addr;
	char buf[4096];
};
