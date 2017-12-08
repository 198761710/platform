#include <unistd.h>
#include "basic.h"
#include "service.h"

int main(void)
{
	Service service;

	if( !service.StartServer("service.unix") )
	{
		return -1;
	}
	while(1)
	{
		service.Run();
		usleep(100);
	}

	return 0;
}
