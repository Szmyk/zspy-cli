#include <include/rang.hpp>
#include <args.hxx>

#include "Logger.h"
#include "LoggerWithFiltering.h"
#include "LoggerWithHighlighting.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

ILogger* logger;

bool registerFakeZSpyClass()
{
	WNDCLASSEX fakeZSpy;

	fakeZSpy.hInstance = NULL;
	fakeZSpy.lpszClassName = "[zSpy]";
	fakeZSpy.lpfnWndProc = WndProc;
	fakeZSpy.style = 0;
	fakeZSpy.cbSize = sizeof(WNDCLASSEX);

	fakeZSpy.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	fakeZSpy.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	fakeZSpy.hCursor = LoadCursor(NULL, IDC_ARROW);
	fakeZSpy.lpszMenuName = NULL;
	fakeZSpy.cbClsExtra = 0;
	fakeZSpy.cbWndExtra = 0;

	fakeZSpy.hbrBackground = (HBRUSH)COLOR_BACKGROUND;

	return RegisterClassEx(&fakeZSpy);
}

HWND createFakeZSpyWindow()
{
	return CreateWindowEx(0, "[zSpy]", "[zSpy]", 0, 0, 0, 0, 0, NULL, NULL, NULL, NULL);
}

void receiveCopyData(PCOPYDATASTRUCT pMyCDS)
{
	std::string message = std::string((LPCSTR)(pMyCDS->lpData));

	std::string fatalStart = "Fatal:";
	std::string warnStart = "Warn:";
	std::string faultStart = "Fault:";

	if (message.substr(0, fatalStart.length()) == fatalStart)
	{
		logger->Fatal(message);
	}
	else if (message.substr(0, warnStart.length()) == warnStart)
	{
		logger->Warning(message);
	}
	else if (message.substr(0, faultStart.length()) == faultStart)
	{
		logger->Fault(message);
	}
	else
	{
		logger->Information(message);
	}
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		case WM_ACTIVATE:
			break;

		case WM_COPYDATA:
			receiveCopyData((PCOPYDATASTRUCT)lParam);

			break;
		case WM_CLOSE:
			DestroyWindow(hwnd);
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
	}

	return 0;
}

int main(int argc, char *argv[])
{
	args::ArgumentParser parser("zSpy in command line.");

	args::HelpFlag help(parser, "help", "", { 'h', "help" });
	args::ValueFlag<std::string> textToFilter(parser, "text", "", { "filter" });
	args::ValueFlag<std::string> textToHighlight(parser, "text", "", { "highlight" });
	args::ValueFlagList<std::string> messages(parser, "all|information|warning|fault|fatal", "default: all", { "messages" }, { "all" });

	try
	{
		parser.ParseCLI(argc, argv);
	}
	catch (const args::Help&)
	{
		std::cout << parser;

		return 0;
	}
	catch (const args::ParseError& e)
	{
		std::cerr << rang::fgB::red;
		std::cerr << e.what() << std::endl;
		std::cerr << rang::style::reset;

		std::cerr << parser;

		return 1;
	}

	if (args::get(textToFilter).empty() == false)
	{
		logger = new LoggerWithFiltering(args::get(textToFilter), args::get(messages));
	}
	else if (args::get(textToHighlight).empty() == false)
	{
		logger = new LoggerWithHighlighting(args::get(textToHighlight), args::get(messages));
	}
	else
	{
		logger = new Logger(args::get(messages));
	}

	if (!registerFakeZSpyClass())
	{
		return 1;
	}

	HWND fakeZSpy = createFakeZSpyWindow();

	if (fakeZSpy == NULL)
	{
		return 1;
	}

	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}
