// CppTempate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>


// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
#include "ReceiveDTO.cpp"
#include "BotInput.cpp"
#include <thread>
#include <vector>

// Socket
#define PORT_PLAYER_1 "8081"
#define PORT_PLAYER_2 "8082"
#define FORMAT "utf-8"
#define SERVER "127.0.0.1"

#define PLAYER_NUM 2
#define TEAM_NAME "TEAM 1"
#define AMOUNT_OF_GAMES 10
#define RESTART true
#define RESTART_TURN 10
#define DEFAULT_BUFLEN 8


using namespace std;

class ClientSocket {
public:
	const char* serverIp;
	PCSTR serverPort;
	pair<string, string> addr;
	string client;
	SOCKET ConnectSocket;
	int iResult;
	char* recvMsg;
	ClientSocket(const char* serverIp, PCSTR serverPort) {
		this->serverIp = serverIp;
		this->serverPort = serverPort;
		this->startConnection();
	}

	void startConnection() {
		printf("Creating socket\n");
		WSADATA wsaData;
		ConnectSocket = INVALID_SOCKET;
		struct addrinfo* result = NULL, * ptr = NULL, hints;

		// Initialize Winsock
		iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (iResult != 0) {
			printf("WSAStartup failed with error: %d\n", iResult);
		}

		ZeroMemory(&hints, sizeof(hints));
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;

		// Resolve the server address and port

		iResult = getaddrinfo(serverIp, serverPort, &hints, &result);
		if (iResult != 0) {
			printf("getaddrinfo failed with error: %d\n", iResult);
			WSACleanup();
		}
		// Attempt to connect to an address until one succeeds
		for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {
			// Create a SOCKET for connecting to server
			ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
				ptr->ai_protocol);
			if (ConnectSocket == INVALID_SOCKET) {
				printf("socket failed with error: %ld\n", WSAGetLastError());
				WSACleanup();
			}

			// Connect to server.
			iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
			if (iResult == SOCKET_ERROR) {
				closesocket(ConnectSocket);
				ConnectSocket = INVALID_SOCKET;
				continue;
			}
			break;
		}

		freeaddrinfo(result);

		if (ConnectSocket == INVALID_SOCKET) {
			printf("Unable to connect to server!\n");
			WSACleanup();
		}
		else {
			printf("Socket was successfully created!\n");
		}
	}

	void sendMessage(const char* msg) {
		int x;
		iResult = send(this->ConnectSocket, msg, (int)strlen(msg), 0);
		if (iResult == SOCKET_ERROR) {
			printf("send failed: %d\n", WSAGetLastError());
			closesocket(ConnectSocket);
			WSACleanup();
		}
		else {
			printf("Bytes Sent: %ld\n", iResult);
		}
	}
	void shutDownConnectionSending() {
		iResult = shutdown(ConnectSocket, SD_SEND);
		if (iResult == SOCKET_ERROR) {
			printf("shutdown failed: %d\n", WSAGetLastError());
			closesocket(ConnectSocket);
			WSACleanup();
		}
	}

	void receive() {
		for (int game = 0; game < AMOUNT_OF_GAMES; game++) {
			startPlaying(game);
		}
		shutDownConnectionSending();
	}

	void setTeamName() {
		const char* botMsg = TEAM_NAME;
		sendMessage(botMsg);
		getMessage();
		if (recvMsg[0] == 'I') {
			std::this_thread::sleep_for(std::chrono::seconds(1));
			setTeamName();
		}
	}

	void startPlaying(int game) {
		setTeamName();
		sendMessage(BotInput::botInput(recvMsg));
		int turn = 2;
		while (turn < RESTART_TURN + 1) {
			if (PLAYER_NUM != 2 || turn != RESTART_TURN) {
				getMessage();
			}

			bool isLastGame = game == AMOUNT_OF_GAMES - 1;

			if (RESTART == true && turn == RESTART_TURN && isLastGame == false) {
				if (PLAYER_NUM == 1) {
					sendMessage(&("restart"[0]));
				}
				printf("Restarting...\n");
				attemptReconnect();
			}
			else {
				const char* botMsg = BotInput::botInput(recvMsg);
				this->sendMessage(botMsg);
			}
			turn += 1;
		}
	}

	void getMessage() {
		delete recvMsg;
		char recvbuf[DEFAULT_BUFLEN];
		int recvbuflen = DEFAULT_BUFLEN;
		try {
			iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
			if (iResult > 0)
				printf("Bytes received: %d\n", iResult);
			else if (iResult == 0)
				printf("Connection closed\n");
			else
				printf("recv failed: %d\n", WSAGetLastError());

			int recvbuflen2 = stoi(string(recvbuf));
			recvMsg = new char[recvbuflen2];
			iResult = recv(ConnectSocket, recvMsg, recvbuflen2, 0);

			printf("Bytes received: %d\n", iResult);
			printf("Message received: %s\n", recvMsg);
		}

		catch (exception) {
			printf(recvbuf);
			std::this_thread::sleep_for(std::chrono::seconds(2));
			getMessage();
		}
	}

	void attemptReconnect() {
		shutDownConnectionSending();
		if (PLAYER_NUM == 1)
			std::this_thread::sleep_for(std::chrono::seconds(1));
		else
			std::this_thread::sleep_for(std::chrono::seconds(2));
		this->startConnection();
	}
};

ClientSocket selectPlayer()
{
	if (PLAYER_NUM == 1) {
		return ClientSocket(SERVER, PORT_PLAYER_1);
	}
	else {
		return ClientSocket(SERVER, PORT_PLAYER_2);
	}
}

int main(void)
{
	ClientSocket client = selectPlayer();
	client.receive();
	return 0;
}
