#include "cache.h"
#include "basicservice.h"

extern Cache GlobalVariable;

void BasicService::Run(void)
{
	for(map<string,Basic>::iterator i = basicmap.begin(); i != basicmap.end(); i++)
	{
		if( i->second.GetRun() )
		{
			i->second.Execute();
		}
	}
	DoReceive();
}
bool BasicService::ProcPacket(Packet& packet)
{
	switch( packet.type() )
	{
	case VarGetType:
		return ProcVarGetType(packet);

	case VarSetType:
		return ProcVarSetType(packet);

	case VarGetInit:
		return ProcVarGetInit(packet);

	case VarSetInit:
		return ProcVarSetInit(packet);

	case VarGetValue:
		return ProcVarGetValue(packet);

	case VarSoftValue:
		return ProcVarSoftValue(packet);

	case VarHardValue:
		return ProcVarHardValue(packet);

	case VarGetManual:
		return ProcVarGetManual(packet);

	case VarSetManual:
		return ProcVarSetManual(packet);

	case VarGetRuntime:
		return ProcVarGetRuntime(packet);

	case VarSetRuntime:
		return ProcVarSetRuntime(packet);

	case VarGetThreshold:
		return ProcVarGetThreshold(packet);

	case VarSetThreshold:
		return ProcVarSetThreshold(packet);

	case VarSetListener:
		return ProcVarSetListener(packet);

	case BasicAddFile:
		return ProcBasicAddFile(packet);

	case BasicDelFile:
		return ProcBasicDelFile(packet);

	case BasicGetRun:
		return ProcBasicGetRun(packet);

	case BasicSetRun:
		return ProcBasicSetRun(packet);

	case BasicSetDebug:
		return ProcBasicSetDebug(packet);

	case BasicCompile:
		return ProcBasicCompile(packet);
	}
	return false;
}
bool BasicService::ProcVarGetType(Packet &packet)
{
	Variable& var = GlobalVariable.GetVariable( packet.name() );

	packet.uvalue( var.GetVariableType() );

	return true;
}
bool BasicService::ProcVarSetType(Packet &packet)
{
	Variable& var = GlobalVariable.GetVariable( packet.name() );

	var.SetVariableType( (VariableType)packet.uvalue() );

	return true;
}
bool BasicService::ProcVarGetInit(Packet &packet)
{
	Variable& var = GlobalVariable.GetVariable( packet.name() );

	packet.uvalue( var.GetInit() );

	return true;
}
bool BasicService::ProcVarSetInit(Packet &packet)
{
	Variable& var = GlobalVariable.GetVariable( packet.name() );

	var.SetInit( packet.uvalue() != 0 );

	return true;
}
bool BasicService::ProcVarGetValue(Packet &packet)
{
	Variable& var = GlobalVariable.GetVariable( packet.name() );

	packet.dvalue( var.GetValue() );

	return true;
}
bool BasicService::ProcVarSoftValue(Packet &packet)
{
	Variable& var = GlobalVariable.GetVariable( packet.name() );

	var.SoftSetValue( packet.dvalue() );

	return true;
}
bool BasicService::ProcVarHardValue(Packet &packet)
{
	Variable& var = GlobalVariable.GetVariable( packet.name() );

	var.HardSetValue( packet.dvalue() );

	return true;
}
bool BasicService::ProcVarGetManual(Packet &packet)
{
	Variable& var = GlobalVariable.GetVariable( packet.name() );

	packet.uvalue( var.GetManual() );

	return true;
}
bool BasicService::ProcVarSetManual(Packet &packet)
{
	Variable& var = GlobalVariable.GetVariable( packet.name() );

	var.SetManual( (AutoType)packet.uvalue() );

	return true;
}
bool BasicService::ProcVarGetRuntime(Packet &packet)
{
	Variable& var = GlobalVariable.GetVariable( packet.name() );

	packet.uvalue( (unsigned)var.GetRuntime() );

	return true;
}
bool BasicService::ProcVarSetRuntime(Packet &packet)
{
	Variable& var = GlobalVariable.GetVariable( packet.name() );

	var.SetRuntime( (double)packet.uvalue() );

	return true;
}
bool BasicService::ProcVarGetThreshold(Packet &packet)
{
	Variable& var = GlobalVariable.GetVariable( packet.name() );

	packet.dvalue( var.GetThreshold() );

	return true;
}
bool BasicService::ProcVarSetThreshold(Packet &packet)
{
	Variable& var = GlobalVariable.GetVariable( packet.name() );

	var.SetThreshold( packet.dvalue() );

	return true;
}
bool BasicService::ProcVarSetListener(Packet &packet)
{
	Variable& var = GlobalVariable.GetVariable( packet.name() );

	var.SetListener( packet.svalue() );

	return true;
}
bool BasicService::ProcBasicAddFile(Packet &packet)
{
	string name = packet.svalue();
	basicmap[name].SetName(name);
	return true;
}
bool BasicService::ProcBasicDelFile(Packet &packet)
{
	string name = packet.svalue();
	basicmap.erase(name);
	return true;
}
bool BasicService::ProcBasicGetRun(Packet &packet)
{
	Biterator i = basicmap.find( packet.name() );

	if( basicmap.end() == i )
	{
		return false;
	}
	packet.uvalue( i->second.GetRun() );

	return true;
}
bool BasicService::ProcBasicSetRun(Packet &packet)
{
	Biterator i = basicmap.find( packet.name() );

	if( basicmap.end() == i )
	{
		return false;
	}
	i->second.SetRun( packet.uvalue() );

	return true;
}
bool BasicService::ProcBasicSetDebug(Packet &packet)
{
	Biterator i = basicmap.find( packet.name() );

	if( basicmap.end() == i )
	{
		return false;
	}
	i->second.SetDebug( packet.uvalue() );

	return true;
}
bool BasicService::ProcBasicCompile(Packet &packet)
{
	Biterator i = basicmap.find( packet.name() );

	if( basicmap.end() == i )
	{
		return false;
	}
	i->second.SetName( i->first );
	i->second.Compile();

	return true;
}
