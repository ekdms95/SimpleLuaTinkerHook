#include "stdafx.h"
#include "Hack.h"
#include "Hooks.h"


Hack::Hack(HMODULE hModule)
{
}

DWORD WINAPI Hack::Start(LPVOID param)
{
	// Create our Console on inject for output.
	Console _Console = new Console(true);
	std::cout << "[INFO] Injected! Loading up Hack\n";

	// Load up our Global Variables.
	Global _Global;

	// Scan for signatures.
	SigScanner _Scanner;
	std::cout << "[INFO] Scanning for signatures\n";
	_Global.addresses["DoString"] = _Scanner.Scan(_Global.doString);
	_Global.addresses["GetTop"] = _Scanner.Scan(_Global.getTop);

	// Hooking stuff.
	Hooks hooker = Hooks(_Global);
	if (hooker.setHooks()) {
		std::cout << "[INFO] Hooked all functions!\n";
	}

	//// Logic loop.
	//while (true) {

	//	if (GetAsyncKeyState(VK_NUMPAD5)) {
	//		std::string cmd = "Inventory_SlotLClick(1)";
	//		hooker.oDoString(hooker._Global.luaState, cmd.c_str(), cmd.size());
	//		Sleep(150);
	//		cmd = "Inventory_SlotDrag(1)";
	//		hooker.oDoString(hooker._Global.luaState, cmd.c_str(), cmd.size());
	//		Sleep(150);
	//		cmd = "Inventory_SlotLClick(2)";
	//		hooker.oDoString(hooker._Global.luaState, cmd.c_str(), cmd.size());
	//		Sleep(150);
	//		cmd = "Inventory_DropHandler(2)";
	//		hooker.oDoString(hooker._Global.luaState, cmd.c_str(), cmd.size());
	//		Sleep(500);
	//	}
	//}
}

Hack::~Hack()
{
}
