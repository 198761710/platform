#include <stdio.h>
#include "service.h"

Service::Service(void)
{
}
Service::Service(const string& s):server(s)
{
}
void Service::Run(void)
{
}
void Service::Reciev(void)
{
	int len = socket.RecvFrom(client, (char*)packet.data(), packet.length());
	if( packet.length() == len )
	{
		Process();
	}
}
bool Service::Start(void)
{
	if( socket.Open() == false )
	{
		return false;
	}
	if( socket.Connect(server) )
	{
		return false;
	}
	socket.Unlink(server);
	if( socket.Bind(server) == false )
	{
		return false;
	}
	return socket.Unblock();
}
bool Service::Process(void)
{
	return false;
}
bool Service::Send(const string& to, const Packet& p)
{
	return (socket.SendTo(to, p.data(), p.length()) == p.length());
}
