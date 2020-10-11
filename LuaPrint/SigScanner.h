#pragma once
class SigScanner
{
public:
	SigScanner();
	DWORD Scan(std::vector<std::string> signatureInfo);
	~SigScanner();
private:
	// For getting information about the executing module.
	MODULEINFO GetModuleInfo(char *szModule);

	// For finding a signature/pattern in memory of given module name.
	DWORD FindPattern(char *module, const char *pattern, const char *mask);
};

