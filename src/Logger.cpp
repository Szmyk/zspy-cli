#include "Logger.h"

Logger::Logger(std::vector<std::string> messagesTypes)
{
	this->messagesTypes = messagesTypes;
}

void Logger::performWriteLine(std::string message, rang::fg color)
{
	writeLine(message, color);
}
