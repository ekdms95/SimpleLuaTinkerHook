// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once
#include "targetver.h"


#define DIRECTINPUT_VERSION 0x0800
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
#include <Psapi.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <dinput.h>
#include <tchar.h>

// reference additional headers your program requires here
#include "detours.h"
#include "lua.hpp"
#include "Hack.h"
#include "Sigscanner.h"
#include "Lua.h"
#include "Console.h"
#include "Global.h"