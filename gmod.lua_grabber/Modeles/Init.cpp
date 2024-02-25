
#include "../Headers/Init.h"

#include <shlobj_core.h>
#include <iostream>
 


 
 
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
	

	std::cout << "Debug mode" << std::endl;
	Sleep(5000);
	

	if (hModule) {
		FreeConsole();
		Beep(750, 100);
		FreeLibraryAndExitThread((HMODULE)hModule, 0);
	}
	
}