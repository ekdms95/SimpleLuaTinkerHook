// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

BOOL APIPRIVATE DllMain(HMODULE hModule,
	DWORD  dw,
	LPVOID lpReserved
)
{
	switch (dw)
	{
	case DLL_PROCESS_ATTACH:
	{
		//MessageBoxA(NULL, "Attach", "Attach", NULL);
		// Load our hack.
		Hack h = Hack::Hack(hModule);
		//MessageBoxA(NULL, "Attach2", "Attach2", NULL);
		CreateThread(0, 0, h.Start, hModule, 0, 0);
		//MessageBoxA(NULL, "Attach3", "Attach3", NULL);
		return TRUE;
	}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		return TRUE;
	}
}

