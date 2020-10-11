#pragma once
class Hack
{
public:
	Hack(HMODULE hM);
	static DWORD WINAPI Start(LPVOID param);
	~Hack();
};

