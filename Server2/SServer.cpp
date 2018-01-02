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

	ULONG ulBlock;
	ulBlock = 1;
	if (ioctlsocket(listening, FIONBIO, &ulBlock) == SOCKET_ERROR)
	{
		return;
	}

	if (listening == SOCKET_ERROR 
		|| listening == INVALID_SOCKET
		) {
		printf("Socket not created\n");
		return;
	}

	if (::bind(listening, (sockaddr*)&addr, sizeof(addr)) != SOCKET_ERROR) {
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
	FD_SET ReadSet;
	int ReadySock;
	int	iSize;
	SOCKADDR_IN clientaddr;
	SOCKET sClient;

	while (true) {
		FD_ZERO(&ReadSet);
		FD_SET(listening, &ReadSet);

		if ((ReadySock = select(0, &ReadSet, NULL, NULL, NULL)) == SOCKET_ERROR
			) {
			cout << "Invalid socket. Skipping!" << endl;
		}

		if (FD_ISSET(listening, &ReadSet))
		{
			iSize = sizeof(clientaddr);
			sClient = accept(listening,
				(struct sockaddr *)&clientaddr, &iSize);
			if (sClient == INVALID_SOCKET)
			{
				cout << "Socket can't be created!" << endl;
				break;
			}

			SClient* client_instance = new SClient(sClient, clientaddr);
		}
	}
}