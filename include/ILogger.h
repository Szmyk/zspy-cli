#pragma once

#include <include/rang.hpp>

#include <iostream>
#include <vector>

class ILogger
{
	public:
		void Information(std::string message);
		void Warning(std::string message);
		void Fault(std::string message);
		void Fatal(std::string message);
		
	protected:
		void writeLine(std::string message, rang::fg color);
		
		std::vector<std::string> messagesTypes;

	private:
		virtual void performWriteLine(std::string message, rang::fg color) = 0;
};
