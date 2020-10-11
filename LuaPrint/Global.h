#pragma once

class Global
{
public:
	lua_State *luaState;

	std::unordered_map<std::string, DWORD> addresses;

	std::vector<std::string> doString =
	{ "\xE8\xFB\x35\x00\x00", "xxx??", "DoString" };
	// 8B EC 56 8B 75 08 57 6A 00 68 ? ? ? ? 56 E8 ? ? ? ? 56 E8 ? ? ? ? 8B 4D 0C 
	// xxxxxxxx?x????xx????xx????xxx
	// 68 10 02 A9 00
	std::vector<std::string> getTop =
	{ "\xE8\xFB\x35\x00\x00", "xxx??", "GetTop" };
	// \xE8\x05\x2E\x00\x00

};

