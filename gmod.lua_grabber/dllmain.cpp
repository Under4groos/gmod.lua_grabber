

#include "Headers/main_header.h"
#include <stdio.h>
 
#ifdef OS_WINDOWS

HMODULE _hModule;
void _CreateThread() {
	BASE::Init((int)_hModule);
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	


		_hModule = hModule;
		 
		CreateThread(NULL , NULL , (LPTHREAD_START_ROUTINE)_CreateThread, NULL, NULL, NULL);
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
#endif  


