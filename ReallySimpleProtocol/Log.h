#pragma once

#include <string>

namespace ReallySimpleProtocol
{
	class Log
	{
	public:

		struct LogData
		{
			bool SaveToDisk;
			std::string Message;
		};

		Log();
		~Log();
	};
}

