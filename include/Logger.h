#pragma once

#include "ILogger.h"

#include <vector>

class Logger : public ILogger
{
	private:
		void performWriteLine(std::string message, rang::fg color);
	public:
		Logger(std::vector<std::string> messagesTypes);
};
