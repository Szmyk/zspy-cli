#pragma once

#include <include/rang.hpp>

#include <iostream>

class ILogger
{
	public:
		void Information(std::string message)
		{
			performWriteLine(message, rang::fg::reset);
		}

		void Warning(std::string message)
		{
			performWriteLine(message, rang::fg::green);
		}

		void Fault(std::string message)
		{
			performWriteLine(message, rang::fg::red);
		}

		void Fatal(std::string message)
		{
			performWriteLine(message, rang::fg::magenta);
		}

	protected:
		void writeLine(std::string message, rang::fg color)
		{
			std::cout << color << message.c_str() << rang::style::reset << std::endl;
		}

	private:
		virtual void performWriteLine(std::string message, rang::fg color) = 0;
};
