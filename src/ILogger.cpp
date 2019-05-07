#include "Logger.h"

void ILogger::Information(std::string message)
{
	if ((std::count(messagesTypes.begin(), messagesTypes.end(), "all"))
	|| (std::count(messagesTypes.begin(), messagesTypes.end(), "information")))
	{
		performWriteLine(message, rang::fg::reset);
	}
}

void ILogger::Warning(std::string message)
{
	if ((std::count(messagesTypes.begin(), messagesTypes.end(), "all"))
	|| (std::count(messagesTypes.begin(), messagesTypes.end(), "warning")))
	{
		performWriteLine(message, rang::fg::green);
	}
}

void ILogger::Fault(std::string message)
{
	if ((std::count(messagesTypes.begin(), messagesTypes.end(), "all"))
	|| (std::count(messagesTypes.begin(), messagesTypes.end(), "fault")))
	{
		performWriteLine(message, rang::fg::red);
	}
}

void ILogger::Fatal(std::string message)
{
	if ((std::count(messagesTypes.begin(), messagesTypes.end(), "all"))
	|| (std::count(messagesTypes.begin(), messagesTypes.end(), "fatal")))
	{
		performWriteLine(message, rang::fg::magenta);
	}
}

void ILogger::writeLine(std::string message, rang::fg color)
{
	std::cout << color << message.c_str() << rang::style::reset << std::endl;
}
