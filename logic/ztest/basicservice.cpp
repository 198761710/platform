#include <unistd.h>
#include "basic.h"
#include "basicservice.h"

extern Cache GlobalVariable;

int main(void)
{
	Packet packet;
	BasicService service;

	if( !service.StartServer("basicservice.unix") )
	{
		return -1;
	}
#if 0
	packet.type(BasicAddFile);
	packet.name("example.bas");
	packet.svalue("example.bas");
	service.ProcPacket(packet);

	packet.type(BasicCompile);
	packet.uvalue(true);
	service.ProcPacket(packet);

	packet.type(BasicSetRun);
	packet.uvalue(true);
	service.ProcPacket(packet);

#endif
	while(1)
	{
		service.Run();
		usleep(100);
		static TimeOperator t;
		if( t.sdiff() != 0 )
		{
			t.init();
			//GlobalVariable.Show();
		}
	}

	return 0;
}
