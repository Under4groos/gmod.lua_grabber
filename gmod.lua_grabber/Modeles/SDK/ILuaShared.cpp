






#include "ILuaInterface.cpp"

class ILuaShared {
public:
	virtual void pad_0() = 0;
	virtual void pad_1() = 0;
	virtual void pad_2() = 0;
	virtual void pad_3() = 0;
	virtual ILuaInterface* CreateLuaInterface(unsigned char, bool) = 0;
	virtual void CloseLuaInterface(ILuaInterface*) = 0;
	virtual ILuaInterface* GetLuaInterface(unsigned char) = 0;
};

extern ILuaShared* g_luashared;