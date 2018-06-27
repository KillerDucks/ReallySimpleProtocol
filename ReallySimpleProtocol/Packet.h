#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

typedef unsigned char BYTE;

namespace ReallySimpleProtocol 
{
	class __declspec(dllexport) Packet
	{
	public:

		static const int PACKET_MAX_SIZE = 512;
		static const int DATA_MAX_SIZE = 128;

		struct PacketFlags
		{
			enum Flags
			{
				SecureData			= (1 << 0),
				SecureTransport		= (1 << 1),
				NullData			= (1 << 2),
				TestFlag			= (1 << 3),
				InitialHandshake	= (1 << 4),
				StartOfData			= (1 << 5)
			};
		};

		struct IPv4Address
		{
			BYTE b0; 
			BYTE b1;
			BYTE b2;
			BYTE b3;
		};

		struct DataPacket
		{
			int packetLength;
			PacketFlags::Flags flags;
			char data[DATA_MAX_SIZE];
			IPv4Address SourceIP;
			IPv4Address DestIP;
		};

		Packet();
		~Packet();

		// Flag Checks / Debug
		int FlagDebugSum(PacketFlags::Flags flags);
		std::string FlagsString(PacketFlags::Flags flags);
		int FlagDebug(PacketFlags::Flags flags, int expectedSum);

		// Packet Size Calc
		int CalcPacketSize(std::string data, double &length);
		bool ValidatePacketSize(DataPacket data, int calcSize); // Not needed as extra data is padded

		// Packet Struct Creation
		DataPacket CreatePackets(int packetLength, PacketFlags::Flags packetFlags, char* packetData, IPv4Address sourceIP, IPv4Address destIP);
		//DataPacket CreatePackets(int packetLength, PacketFlags::Flags packetFlags, std::string packetData, IPv4Address sourceIP, IPv4Address destIP);

		// Prepare packet transport
		char* ConvertToBytes(DataPacket packet);

		// Convert Packet to DataStruct
		// DataPacket ConvertToDataPacket(char* packet);
	};
}

