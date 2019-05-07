#pragma once

#include "ILogger.h"

#include <vector>

class LoggerWithFiltering : public ILogger
{
	private:
		std::string textToFilter;

		void performWriteLine(std::string message, rang::fg color);
	public:
		LoggerWithFiltering (std::string textToFilter, std::vector<std::string> messagesTypes);
};
