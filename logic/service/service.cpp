#include "service.h"


Service::Service(void)
{
	cmdmap["GetValue"] = CmdGetValue;
	cmdmap["SetValue"] = CmdSetValue;
}
void Service::Run(void)
{
	int len = 0;
	string from;
	Packet packet;

	len = server.RecvFrom(from, (char*)packet.data(), packet.size());
	if( len == packet.size() )
	{
		ProcPacket(packet);
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
	case CmdSetValue:
		SetValue(packet);
		break;
	case CmdGetValue:
		GetValue(packet);
		break;
	}
}
bool Service::SetValue(Packet& packet)
{
	return true;
}
bool Service::GetValue(Packet& packet)
{
	return true;
}
