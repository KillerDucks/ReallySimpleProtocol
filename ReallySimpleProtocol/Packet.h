#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

namespace ReallySimpleProtocol 
{
	class __declspec(dllexport) Packet
	{
	public:

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

		struct DataPacket
		{
			int packetLength;
			PacketFlags::Flags flags;
			std::string data;
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
		DataPacket CreatePackets(int packetLength, PacketFlags::Flags packetFlags, std::string packetData);

		// Prepare packet transport
		//std::vector<bool> SendPackets(std::vector<DataPacket>, //SourceIP, //DestIP);
	};
}

