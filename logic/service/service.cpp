#include <stdio.h>
#include "service.h"

Service::Service(void)
{
}
void Service::Run(void)
{
}
void Service::DoReceive(void)
{
	int len = 0;
	Packet packet;

	len = server.RecvFrom(peer, (char*)packet.data(), packet.size());
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
	return false;
}
bool Service::SendPacket(const string& to, Packet& packet)
{
	int ret = 0;

	ret = server.SendTo(to, (char*)packet.data(), packet.size());

	return (packet.size() == ret);
}
