#include "Packet.h"

namespace ReallySimpleProtocol
{
	Packet::Packet()
	{
	}


	Packet::~Packet()
	{
	}

	int Packet::FlagDebug(PacketFlags::Flags flags)
	{

		if (flags & ReallySimpleProtocol::Packet::PacketFlags::SecureData)
		{
			printf_s("Secure Data -> Set!\n");
		}
		if (flags & ReallySimpleProtocol::Packet::PacketFlags::SecureTransport)
		{
			printf_s("Secure Transport -> Set!\n");
		}
		if (flags & ReallySimpleProtocol::Packet::PacketFlags::NullData)
		{
			printf_s("Null Data -> Set!\n");
		}
		if (flags & ReallySimpleProtocol::Packet::PacketFlags::TestFlag)
		{
			printf_s("Test Flag -> Set!\n");
		}
		if (flags & ReallySimpleProtocol::Packet::PacketFlags::InitialHandshake)
		{
			printf_s("Initial Handshake -> Set!\n");
		}
		if (flags & ReallySimpleProtocol::Packet::PacketFlags::StartOfData)
		{
			printf_s("Start Of Data -> Set!\n");
		}

		printf_s("Flags Sum -> %d \n", flags);
		return flags;

	}

	int Packet::FlagDebug(PacketFlags::Flags flags, int expectedSum)
	{
		if(flags == expectedSum)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	int Packet::CalcPacketSize(std::string data, double &length)
	{
		// Get char size
		double size = data.length();
		double packetsDecimal = 0.00;
		int packets = 0;

		// Optional data length OUT
		if (floor(length) != 0)
		{
			length = size;
		}

		// How many into 256
		packetsDecimal = size / 128;
		if (floor(packetsDecimal) == packetsDecimal)
		{
			// Whole Number
			packets = ((int)packetsDecimal + 0);
		}
		else
		{
			// Not whole number add one
			packets = ((int)packetsDecimal + 1);
		}
		return packets;
	}

	bool Packet::ValidatePacketSize(DataPacket data, int calcSize)
	{
		return false;
	}

	Packet::DataPacket Packet::CreatePackets(int packetLength, PacketFlags::Flags packetFlags, std::string packetData)
	{
		Packet::DataPacket tmpPacket;
		tmpPacket.data = packetData;
		tmpPacket.packetLength = packetLength;
		tmpPacket.flags = packetFlags;
		return tmpPacket;
	}
}
