#include "stdafx.h"
#include "SigScanner.h"


SigScanner::SigScanner()
{
}

SigScanner::~SigScanner()
{
}

DWORD SigScanner::Scan(std::vector<std::string> sig)
{
	DWORD address = -1;

	// Scanning.
	// NULL because we are searching for memory inside our own process.
	address = FindPattern(NULL, sig[0].c_str(), sig[1].c_str());

	// Output.
	if (address == -1) {
		std::cout << "[SIG] : Failed at scanning " << sig[2] << std::endl;
	}
	else {
		std::cout << "[SIG] : Succeeded at scanning " << sig[2] << std::endl << "[SIG] : Address -> 0x" << std::hex << address << std::endl;
	}
	return address;
}

DWORD SigScanner::FindPattern(char * module, const char * pattern, const char * mask)
{
	MODULEINFO mInfo = GetModuleInfo(module);
	DWORD base = (DWORD)mInfo.lpBaseOfDll;
	DWORD size = (DWORD)mInfo.SizeOfImage;
	DWORD patternLength = (DWORD)strlen(mask);

	for (DWORD i = 0; i < size - patternLength; i++)
	{
		bool found = true;
		for (DWORD j = 0; j < patternLength; j++)
		{
			found &= mask[j] == '?' || pattern[j] == *(char*)(base + i + j);
		}
		if (found)
		{
			return base + i;
		}
	}
	return NULL;
}

MODULEINFO SigScanner::GetModuleInfo(char * szModule)
{
	MODULEINFO modinfo = { 0 };
	HMODULE hModule = GetModuleHandle(szModule);
	if (hModule == 0)
		return modinfo;
	GetModuleInformation(GetCurrentProcess(), hModule, &modinfo, sizeof(MODULEINFO));
	return modinfo;
}
