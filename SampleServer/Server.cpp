#include <iostream>
#include "Packet.h"
#include "Socket.h"
#include <Windows.h>
#include <vector>

using namespace ReallySimpleProtocolServer;
using namespace ReallySimpleProtocol;

using namespace std;

int main()
{
	int number = 5;
	double packetLength = 1;
	const char* test = "Hello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello World";
	const char* test128 = "Hello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello World 12345";
	Packet RCP;
	const int packetNum = (const int)RCP.CalcPacketSize((char *)test, packetLength);
	vector<Packet::DataPacket> packets;
	//cout << RCP.FlagDebug((Packet::PacketFlags::Flags)(Packet::PacketFlags::NullData | Packet::PacketFlags::TestFlag)) << endl;
	cout << "Packets Need for given data -> " << RCP.CalcPacketSize((char *)test, packetLength) << endl;
	cout << "Packet Data Length (Total) -> " << packetLength << endl;
	for (size_t i = 0; i < packetNum; i++)
	{
		packets.emplace_back(RCP.CreatePackets(128, (Packet::PacketFlags::Flags)(Packet::PacketFlags::NullData | Packet::PacketFlags::TestFlag), test128));
	}
	cout << "Vector Size -> " << packets.size() << endl;

	// Debug Printing
	for (size_t i = 0; i < packets.size(); i++)
	{
		printf_s("Packet %d Data -> %s\n", i, packets[i].data.c_str());
		printf_s("Packet %d Flags -> %s\n", i, RCP.FlagsString(packets[i].flags).c_str()); // Wont print !
		printf_s("Packet %d Packet Length -> %d\n", i, packets[i].packetLength);
	}

	//// Test with baked in server
	//SocketServer server;
	//server.StartServer();
	system("pause");
	return 1;
}