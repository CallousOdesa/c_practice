#pragma once
#include "includes.h"
class SServer
{
public:
	SServer();
	~SServer();
	void startServer();
	void closeServer();
	void handle();
	unsigned short port;
private:
	SOCKET listening;
	WSAData wData;
};