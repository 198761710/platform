#include "cache.h"
#include "service.h"

extern Cache GlobalVariable;

Service::Service(void)
{
}
void Service::Run(void)
{
	int len = 0;
	Packet packet;

	len = server.RecvFrom(peer, (char*)packet.data(), packet.size());
	if( len == packet.size() )
	{
		ProcPacket(packet);
	}
}
void Service::RunBasic(void)
{
	for(map<string,Basic>::iterator i = basicmap.begin(); i != basicmap.end(); i++)
	{
		if( i->second.run() )
		{
			i->second.execute();
		}
	}
}
bool Service::StartServer(const string& path)
{
	if( server.Open() == false )
	{
		return false;
	}
	if( server.Connect(path) )
	{
		return false;
	}
	server.Unlink(path);
	if( server.Bind(path) == false )
	{
		return false;
	}
	return server.Unblock();
}
bool Service::ProcPacket(Packet& packet)
{
	switch( packet.type() )
	{
	case CmdValueSet:
		SetValue(packet);
		break;
	case CmdValueGet:
		GetValue(packet);
		break;
	case CmdBasicRun:
		BasicRun(packet);
		break;
	case CmdBasicLoad:
		BasicLoad(packet);
		break;
	case CmdBasicDebug:
		BasicDebug(packet);
		break;
	}
}
bool Service::SetValue(Packet& packet)
{
	string name = packet.name();
	Variable &v = GlobalVariable.GetVariable( name );
	double value = v.GetValue();

	switch( packet.autx() )
	{
		case Auto:
			v.SetValueAuto( value );
			break;
		case Manual:
			v.SetValueManual( value );
			break;
	}
	return true;
}
bool Service::GetValue(Packet& packet)
{
	string name = packet.name();
	Variable &v = GlobalVariable.GetVariable( name );
	packet.dvalue( v.GetValue() );
	return server.SendTo(peer, (char*)packet.data(), packet.size());
}
bool Service::BasicRun(Packet& packet)
{
	string name = packet.name();
	map<string,Basic>::iterator i;
	
	if( name.empty() )
	{
		return false;
	}
	i = basicmap.find(name);
	if(basicmap.end() == i )
	{
		return false;
	}
	i->second.run( packet.uvalue() );
	return true;
}
bool Service::BasicLoad(Packet& packet)
{
	string name = packet.name();
	map<string,Basic>::iterator i;
	
	if( name.empty() )
	{
		return false;
	}
	i = basicmap.find(name);
	if(basicmap.end() == i )
	{
		return false;
	}
	i->second.name( packet.name() );
	return i->second.load();
}
bool Service::BasicDebug(Packet& packet)
{
	string name = packet.name();
	map<string,Basic>::iterator i;
	
	if( name.empty() )
	{
		return false;
	}
	i = basicmap.find(name);
	if(basicmap.end() == i )
	{
		return false;
	}
	i->second.debug( packet.uvalue() );
	return true;
}
