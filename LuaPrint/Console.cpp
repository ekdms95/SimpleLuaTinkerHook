#include "stdafx.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

Console::Console(bool alwaysOnTop)
{
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	consoleHWND = GetConsoleWindow();

	if (consoleHWND && alwaysOnTop) {
		SetWindowPos(
			consoleHWND, // window handle
			HWND_TOPMOST, // "handle to the window to precede
						  // the positioned window in the Z order
						  // OR one of the following:"
						  // HWND_BOTTOM or HWND_NOTOPMOST or HWND_TOP or HWND_TOPMOST
			0, 0, // X, Y position of the window (in client coordinates)
			0, 0, // cx, cy => width & height of the window in pixels
			SWP_DRAWFRAME | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW // The window sizing and positioning flags.
		);
		// OPTIONAL ! - SET WINDOW'S "SHOW STATE"
		ShowWindow(
			consoleHWND, // window handle
			SW_NORMAL // how the window is to be shown
					  // SW_NORMAL => "Activates and displays a window.
					  // If the window is minimized or maximized,
					  // the system restores it to its original size and position.
					  // An application should specify this flag
					  // when displaying the window for the first time."
		);
	}
}

bool Console::SetTitle(std::string title)
{
	return SetConsoleTitle(title.c_str());
}


Console::~Console()
{
}
