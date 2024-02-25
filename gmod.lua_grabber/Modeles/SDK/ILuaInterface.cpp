
#include "../../Headers/LuaBase.h"

class lua_State;

class ILuaInterface : public GarrysMod::Lua::ILuaBase {
public:
	lua_State* GetLuaState() {
		return *reinterpret_cast<lua_State**>(this + 1);
	}
};

extern ILuaInterface* g_clientluainterface;