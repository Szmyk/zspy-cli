#pragma once

#include "ILogger.h"

class Logger : public ILogger
{
	void performWriteLine(std::string message, rang::fg color);
};
