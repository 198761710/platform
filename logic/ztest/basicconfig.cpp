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

#if 1
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

	TimeOperator t;
	while(1)
	{
		if( t.sdiff() != 0 )
		{
			t.init();
			packet.type( VarGetInputList );
			packet.svalue( "inputlist.html" );
			service.SendPacket(to, packet);

			packet.type( VarGetOutputList);
			packet.svalue( "outputlist.html" );
			service.SendPacket(to, packet);

			packet.type( VarGetValueList );
			packet.svalue( "variablelist.html" );
			service.SendPacket(to, packet);
		}
	}

	return 0;
}
