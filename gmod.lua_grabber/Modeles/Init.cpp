
#include "../Headers/Init.h"

#include <shlobj_core.h>
#include <iostream>
#include "Library.cpp"
#include "SDK/IVEngineClient.cpp"
using namespace std;

Library Lib;
 
 
void BASE::Init(int hModule) {
	 
	if (AllocConsole()) {
		FILE* fDummy;
		freopen_s(&fDummy, "CONOUT$", "w", stdout);
		freopen_s(&fDummy, "CONOUT$", "w", stderr);
		freopen_s(&fDummy, "CONIN$", "r", stdin);
		std::cout.clear();
		std::clog.clear();
		std::cerr.clear();
		std::cin.clear();
	}
	

	auto* addres = Lib.GetModule("engine");
	IVEngineClient* g_engineclient = Lib.GetInterface<IVEngineClient>("VEngineClient015");
	cout << "IVEngineClient: " << g_engineclient << endl;
	cout << addres << endl;





	//Lib.GetModule("lua_shared");

	std::cout << "Debug mode" << std::endl;
	 
	

	if (hModule) {
		FreeConsole();
		Beep(750, 100);
		FreeLibraryAndExitThread((HMODULE)hModule, 0);
	}
	
}