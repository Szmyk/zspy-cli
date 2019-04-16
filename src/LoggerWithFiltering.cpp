#include "LoggerWithFiltering.h"

void LoggerWithFiltering::performWriteLine(std::string message, rang::fg color)
{
	if (message.find(textToFilter) != std::string::npos)
	{
		writeLine(message, color);
	}
}

LoggerWithFiltering::LoggerWithFiltering (std::string textToFilter)
{
	this->textToFilter = textToFilter;
}
