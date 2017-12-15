#include <unistd.h>
#include "basic.h"
#include "service.h"

int main(void)
{
	Packet packet;
	Service service;
	string to = "basicservice.unix";

	if( !service.StartServer("basicconfig.unix") )
	{
		return -1;
	}

#if 0
	packet.type(BasicAddFile);
	packet.name("example.bas");
	packet.svalue("example.bas");
	service.SendPacket(to, packet);

	packet.type(BasicCompile);
	packet.uvalue(true);
	service.SendPacket(to, packet);
#endif
	packet.type(BasicSetRun);
	packet.uvalue(true);
	service.SendPacket(to, packet);

	return 0;
}
