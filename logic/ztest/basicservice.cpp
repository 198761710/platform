#include <assert.h>
#include <unistd.h>
#include "basic.h"
#include "basicservice.h"

extern Cache GlobalVariable;

int main(void)
{
	TimeOperator timer;
	BasicService service(".basic.server");

	assert( service.Start() );
	service.Send(".basic.server", Packet(Pkt_SetBasAdd, "example.bas"));
	service.Send(".basic.server", Packet(Pkt_SetBasRun, "1,example.bas"));
	service.Send(".basic.server", Packet(Pkt_SetBasCompile, "example.bas"));
	service.Send(".basic.server", Packet(Pkt_SetBasAdd, "example2.bas"));
	service.Send(".basic.server", Packet(Pkt_SetBasRun, "1,example2.bas"));
	service.Send(".basic.server", Packet(Pkt_SetBasCompile, "example2.bas"));
	service.Send(".basic.server", Packet(Pkt_SetVarAdd, "example"));
	service.Send(".basic.server", Packet(Pkt_SetVarInit, "1,example"));
	service.Send(".basic.server", Packet(Pkt_SetVarABType, "1,example"));
	service.Send(".basic.server", Packet(Pkt_SetVarIOType, "2,example"));

	while(1)
	{
		if( timer.sdiff() > 1 )
		{
			timer.init();
			service.Show();
		}
		usleep(100);
		service.Run();
	}

	return 0;
}
