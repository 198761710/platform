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
#if 0
	service.Send(".basic.server", Packet(Pkt_SetBasAdd, "1,example1.bas"));
	service.Send(".basic.server", Packet(Pkt_SetBasRun, "1,example1.bas"));
	service.Send(".basic.server", Packet(Pkt_SetBasCompile, "1,example1.bas"));
	service.Send(".basic.server", Packet(Pkt_SetBasAdd, "1,example2.bas"));
	service.Send(".basic.server", Packet(Pkt_SetBasRun, "1,example2.bas"));
	service.Send(".basic.server", Packet(Pkt_SetBasCompile, "1,example2.bas"));
	service.Send(".basic.server", Packet(Pkt_SetVarAdd, "example"));
	service.Send(".basic.server", Packet(Pkt_SetVarInit, "1,example"));
	service.Send(".basic.server", Packet(Pkt_SetVarABType, "1,example"));
	service.Send(".basic.server", Packet(Pkt_SetVarIOType, "2,example"));
#endif
	service.Send(".basic.server", Packet(Pkt_LoadBasic, "basic.config"));
	service.Send(".basic.server", Packet(Pkt_LoadVarible, "variable.config"));

	while(1)
	{
		if( timer.sdiff() > 1 )
		{
			//service.Send(".basic.server", Packet(Pkt_StoreBasic, "basic.config"));
			service.Send(".basic.server", Packet(Pkt_StoreVarible, "variable.config"));
			timer.init();
			service.Show();
		}
		usleep(100);
		service.Run();
	}

	return 0;
}
