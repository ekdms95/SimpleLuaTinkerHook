#pragma once
#include "Global.h"

class Hooks
{
public:
	Hooks(Global _g);
	~Hooks();
	bool setHooks();
	static Global _Global;
	typedef INT(CALLBACK* _DoString)(lua_State *L, CONST CHAR *s, size_t size);
	typedef INT(CALLBACK* _GetTop)(lua_State *L);
	static _DoString oDoString;
	static _GetTop oGetTop;

private:
	const void * DetourFuncVTable(SIZE_T * src, const BYTE * dest, const DWORD index);
	bool hook_function(PVOID & t1, PBYTE t2, const char * s = NULL);
};

