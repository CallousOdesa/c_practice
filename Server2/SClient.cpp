#pragma once
#include "includes.h"

SClient::SClient(SOCKET s, SOCKADDR_IN sock_in): the_thread()
{
	clientSocket = s;
	c_addr = sock_in;
	printf("Client created\n");
	the_thread = std::thread(&SClient::handle, this);
}


SClient::~SClient()
{
	stop_thread = true;
	if (the_thread.joinable()) the_thread.join();
	cout << "Client socket handler destroyed!" << endl;
}

void SClient::handle()
{
	while (true)
	{
		ZeroMemory(buf, 4096);
		int bytesReceived = recv(clientSocket, buf, sizeof(buf), 0);
		if (bytesReceived == SOCKET_ERROR) {
			// cout << "Error in recv(). Quitting" << endl;
			// break;
		}

		if (bytesReceived == 0) {
			cout << "Client disconnected. Quitting" << endl;
			break;
		}

		if (strlen(buf) != 0) {
			printf("Received message from Client 0  %u.%u.%u.%u:%u\n",
				(unsigned char)c_addr.sin_addr.S_un.S_un_b.s_b1,
				(unsigned char)c_addr.sin_addr.S_un.S_un_b.s_b2,
				(unsigned char)c_addr.sin_addr.S_un.S_un_b.s_b3,
				(unsigned char)c_addr.sin_addr.S_un.S_un_b.s_b4,
				ntohs(c_addr.sin_port));
			cout << buf << endl;
		}

		send(clientSocket, buf, sizeof(buf), 0);
		Sleep(500);
	}
}