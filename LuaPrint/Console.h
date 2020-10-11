#pragma once
class Console
{
public:
	Console(bool aOnTop);
	bool SetTitle(std::string title);
	~Console();
private:
	HWND consoleHWND;
};


