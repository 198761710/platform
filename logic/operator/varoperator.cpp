#include <stdlib.h>
#include "varoperator.h"

VarOperator::VarOperator(void)
{
	typemap["setinit"] = VarSetInit;
	typemap["setvalue"] = VarHardValue;
	typemap["setmanual"] = VarSetManual;
	typemap["setruntime"] = VarSetRuntime;
	typemap["setthreshold"] = VarSetThreshold;
}
Packet& VarOperator::GetPacket(void)
{
	return packet;
}
bool VarOperator::ProcRequest(const string& type, const string& name, const string& value)
{
	if( type.empty() )
	{
		return false;
	}
	if( name.empty() )
	{
		return false;
	}
	if( value.empty() )
	{
		return false;
	}
	map<string,int>::iterator i = typemap.find(type);

	if( typemap.end() == i )
	{
		return false;
	}
	switch(i->second)
	{
		case VarSetInit:
			return SetInit(name, value);

		case VarHardValue:
			return SetValue(name, value);

		case VarSetManual:
			return SetManual(name, value);

		case VarSetRuntime:
			return SetRuntime(name, value);

		case VarSetThreshold:
			return SetThreshold(name, value);
	}
	return false;
}
bool VarOperator::SetInit(const string& name, const string& value)
{
	packet.name( name.data() );
	packet.type( VarSetInit );
	packet.uvalue( value == "1" );
	return true;
}
bool VarOperator::SetValue(const string& name, const string& value)
{
	packet.name( name.data() );
	packet.type( VarHardValue );
	packet.dvalue( strtod(value.data(), 0) );
	return true;
}
bool VarOperator::SetManual(const string& name, const string& value)
{
	packet.name( name.data() );
	packet.type( VarSetManual );
	packet.dvalue( value == "1" );
	return true;
}
bool VarOperator::SetRuntime(const string& name, const string& value)
{
	packet.name( name.data() );
	packet.type( VarSetRuntime );
	packet.uvalue( strtol(value.data(), 0, 10) );
	return true;
}
bool VarOperator::SetThreshold(const string& name, const string& value)
{
	packet.name( name.data() );
	packet.type( VarSetThreshold );
	packet.dvalue( strtod(value.data(), 0) );
	return true;
}
