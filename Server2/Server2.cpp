#include "SServer.h"

int main()
{
	unsigned short port;
	cout << "Enter TCP port number" << endl;
	cin >> port;
	SServer server;
	server.port = port;
	server.startServer();
	return 0;
}