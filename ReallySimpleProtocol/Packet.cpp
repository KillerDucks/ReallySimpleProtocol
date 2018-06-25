#include "Packet.h"

namespace ReallySimpleProtocol
{
	Packet::Packet()
	{
	}


	Packet::~Packet()
	{
	}

	int Packet::FlagDebugSum(PacketFlags::Flags flags) 
	{
		return flags;
	}

	std::string Packet::FlagsString(PacketFlags::Flags flags)
	{
		std::stringstream flagString;

		if (flags & ReallySimpleProtocol::Packet::PacketFlags::SecureData)
		{
			flagString << "Secure Data -> Set!";
		}
		if (flags & ReallySimpleProtocol::Packet::PacketFlags::SecureTransport)
		{
			flagString << "Secure Transport -> Set! ";
		}
		if (flags & ReallySimpleProtocol::Packet::PacketFlags::NullData)
		{
			flagString << "Null Data -> Set! ";
		}
		if (flags & ReallySimpleProtocol::Packet::PacketFlags::TestFlag)
		{
			flagString << "Test Flag -> Set! ";
		}
		if (flags & ReallySimpleProtocol::Packet::PacketFlags::InitialHandshake)
		{
			flagString << "Initial Handshake -> Set! ";
		}
		if (flags & ReallySimpleProtocol::Packet::PacketFlags::StartOfData)
		{
			flagString << "Start Of Data -> Set! ";
		}

		return flagString.str();

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

	Packet::DataPacket Packet::CreatePackets(int packetLength, PacketFlags::Flags packetFlags, std::string packetData, IPv4Address sourceIP, IPv4Address destIP)
	{
		// TODO: need to add validation to inputs
		Packet::DataPacket tmpPacket;
		tmpPacket.data = packetData;
		tmpPacket.packetLength = packetLength;
		tmpPacket.flags = packetFlags;
		tmpPacket.SourceIP = sourceIP;
		tmpPacket.DestIP = destIP;
		return tmpPacket;
	}
	char* Packet::ConvertToBytes(DataPacket packet)
	{
		// Convert the DataPacket to bytes
		//char* buffer = reinterpret_cast<char*>(&packet);
		//char* my_s_bytes = static_cast<char*>(static_cast<void*>(&packet));
		char buffer[sizeof(packet)];
		memcpy(buffer, &packet, sizeof(packet));
		return buffer;
	}
}
