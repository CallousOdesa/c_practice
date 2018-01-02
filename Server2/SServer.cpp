#include "SServer.h"
#include "includes.h"


SServer::SServer() {
}

SServer::~SServer() {
}

void SServer::startServer() {
	if (WSAStartup(MAKEWORD(2, 2), &wData) == 0)
	{
		printf("WSA Startup succes\n");
	}
	SOCKADDR_IN addr;
	int addrl = sizeof(addr);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.S_un.S_addr = INADDR_ANY;

	listening = socket(AF_INET, SOCK_STREAM, 0);

	if (listening == SOCKET_ERROR 
		|| listening == INVALID_SOCKET
		) {
		printf("Socket not created\n");
		return;
	}

	if (bind(listening, (sockaddr*)&addr, sizeof(addr)) != SOCKET_ERROR) {
		printf("Socket succed binded\n");
	}

	if (listen(listening, SOMAXCONN) != SOCKET_ERROR) {
		printf("Start listenin at port %u\n", ntohs(addr.sin_port));
	}
	handle();
}

void SServer::closeServer() {
	closesocket(listening);
	WSACleanup();
	cout << "Server was stoped. You can close app" << endl;
}


void SServer::handle() {
	while (true) {

		SOCKADDR_IN client;
		int clientSize = sizeof(client);
		SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientSize);
		
		if (clientSocket != 0) {
			printf("Client connected from 0  %u.%u.%u.%u:%u\n",
				(unsigned char)client.sin_addr.S_un.S_un_b.s_b1,
				(unsigned char)client.sin_addr.S_un.S_un_b.s_b2,
				(unsigned char)client.sin_addr.S_un.S_un_b.s_b3,
				(unsigned char)client.sin_addr.S_un.S_un_b.s_b4,
				ntohs(client.sin_port));
			SClient* client_instance = new SClient(clientSocket, client);
		}
		Sleep(500);
	}
}