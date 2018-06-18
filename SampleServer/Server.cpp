#include <iostream>
#include "Packet.h"
#include "Socket.h"
#include <Windows.h>
#include <vector>

using namespace ReallySimpleProtocolServer;
using namespace ReallySimpleProtocol;

int main()
{
	int number = 5;
	double packetLength = 1;
	const char* test = "Hello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello World";
	const char* test128 = "Hello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello World 12345";
	Packet RCP;
	const int packetNum = (const int)RCP.CalcPacketSize((char *)test, packetLength);
	std::vector<Packet::DataPacket> packets;
	std::cout << RCP.FlagDebug((Packet::PacketFlags::Flags)(Packet::PacketFlags::NullData | Packet::PacketFlags::TestFlag)) << std::endl;
	std::cout << "Packets Need for given data -> " << RCP.CalcPacketSize((char *)test, packetLength) << std::endl;
	std::cout << "Packet Data Length (Total) -> " << packetLength << std::endl;
	for (size_t i = 0; i < packetNum; i++)
	{
		packets.emplace_back(RCP.CreatePackets(128, (Packet::PacketFlags::Flags)(Packet::PacketFlags::NullData | Packet::PacketFlags::TestFlag), test128));
	}
	std::cout << "Vector Size -> " << packets.size() << std::endl;
	system("pause");
	return 1;
}