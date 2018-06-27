#include <iostream>
#include "Packet.h"
#include "Socket.h"
#include <Windows.h>
#include <vector>
#include <cstring>

using namespace ReallySimpleProtocolServer;
using namespace ReallySimpleProtocol;

using namespace std;

int main()
{
	// Test with baked in server
	SocketServer server;
	server.StartServer();
	system("pause");
	return 1;
}