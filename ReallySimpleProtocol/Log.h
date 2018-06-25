#pragma once

#include <string>

namespace ReallySimpleProtocol
{
	class __declspec(dllexport) Log
	{
	public:

		struct LogData
		{
			bool SaveToDisk;
			int timeStamp;
			std::string Message;
		};

		Log();
		~Log();
	};
}

