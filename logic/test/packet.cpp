#include <stdio.h>
#include "packet.h"

int main(void)
{
	Packet packet;

	packet.type(CmdValueGet);
	packet.autx(Manual);
	packet.value(3.14159);
	packet.name("pi");

	printf("type=%d\n", packet.type());
	printf("audo=%d\n", packet.autx());
	printf("value=%f\n", packet.value());
	printf("name=%s\n", packet.name());

	for(int i = 0; i< NameIndex+3; i++)
	{
		printf("%02X ", packet.data()[i]);
	}
	printf("\n");

	return 0;
}
