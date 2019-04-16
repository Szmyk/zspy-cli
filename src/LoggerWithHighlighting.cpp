#include "LoggerWithHighlighting.h"

void LoggerWithHighlighting::performWriteLine(std::string message, rang::fg color)
{
	if (message.find(textToHighlight) == std::string::npos)
	{
		writeLine(message, color);
	}
	else
	{
		size_t index = message.find(textToHighlight);

		std::cout << color
			<< message.substr(0, index).c_str()
			<< rang::bgB::yellow
			<< textToHighlight.c_str()
			<< rang::style::reset
			<< message.substr(index + textToHighlight.length()).c_str()
			<< rang::style::reset
			<< std::endl;
	}
}

LoggerWithHighlighting::LoggerWithHighlighting(std::string textToHighlight)
{
	this->textToHighlight = textToHighlight;
}