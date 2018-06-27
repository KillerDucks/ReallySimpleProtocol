#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

#include <vector>
#include <iostream>
#include <iterator>

#include "Packet.h"

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"

using namespace ReallySimpleProtocol;

namespace ReallySimpleProtocolServer
{
	class __declspec(dllexport) SocketServer
	{
	public:
		SocketServer();
		~SocketServer();

		struct SocketData
		{
			char buffer[512];
		};

		// Server Start
		int StartServer();

		// Buffer Manip
		static SocketData RemovePadding(char *buffer, int dataSize);
		static void GetData(char *buffer, int dataSize);
	};
}

