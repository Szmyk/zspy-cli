#pragma once

#include "ILogger.h"

#include <vector>

class LoggerWithHighlighting : public ILogger
{
	private:
		std::string textToHighlight;

		void performWriteLine(std::string message, rang::fg color);
	public:
		LoggerWithHighlighting(std::string textToHighlight, std::vector<std::string> messagesTypes);
};
