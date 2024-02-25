#include <string>
#include <map>

#include <windows.h>
#include <tlhelp32.h>

#include <cinttypes>
#include <string>
#include <stdexcept>
#include <cstring>
#include <iostream>
 
 
typedef std::uintptr_t* (*CreateInterfaceFn)(const char*, int*);
static const std::map<std::string, std::string> extension_mapping = {
	{ "engine", ".dll" },
	{"lua_shared", ".dll"}
};


class Library
{
public:
	std::uintptr_t* m_handle = nullptr;
	std::string m_pathname;
	bool debugmode = false;
	std::string GetExtension(const std::string& pathname) const {
		return extension_mapping.at(pathname);
	}

	template <typename T>
	T GetSymbol(const std::string& symname) const {
		std::uintptr_t* sym = reinterpret_cast<std::uintptr_t*>(GetProcAddress(reinterpret_cast<HMODULE>(m_handle),
			symname.c_str()));;
		if (!sym) {
			throw std::runtime_error("failed to get symbol " + symname + " from " + m_pathname);
		}
		return reinterpret_cast<T>(sym);
	}


	template <typename T>
	T* GetInterface(const std::string& ifacename) const {
		const auto& createinterface = GetSymbol<CreateInterfaceFn>("CreateInterface");
		T* iface = reinterpret_cast<T*>(createinterface(ifacename.c_str(), nullptr));

		if (!iface) {
			throw std::runtime_error("failed to get interface " + ifacename + " from " + m_pathname);
		}

		return iface;
	}




	std::uintptr_t* GetModule(const std::string& pathname) {
		
		std::string pathnamext(pathname + GetExtension(pathname));

		MODULEENTRY32 module_entry;
		HANDLE module_snap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, GetCurrentProcessId());
		module_entry.dwSize = sizeof(MODULEENTRY32);

		if (!Module32First(module_snap, &module_entry)) {
			throw std::runtime_error("failed to get process modules");
		}

		do {
			
			WCHAR* w = module_entry.szModule;

			std::wstring_view wideView(w, std::char_traits<WCHAR>::length(w));
			 

			std::string module_name (wideView.begin(), wideView.end());
			std::size_t found = module_name.find(pathnamext);
			if(debugmode)
				std::cout << module_name << std::endl;

			if (found != std::string::npos) {
				m_handle = reinterpret_cast<std::uintptr_t*>(module_entry.hModule);
				break;
			}

		} while (Module32Next(module_snap, &module_entry));
		return m_handle;
	}

};

 