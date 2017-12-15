#include <stdio.h>
#include <time.h>
#include "packet.h"

int main(void)
{
	Packet packet;

	packet.type(VarGetValue);
	packet.guid((uint64_t)time(0));
	packet.dvalue(3.14159);
	packet.name("pi");

	printf("type=%d\n", packet.type());
	printf("guid=%X\n", packet.guid());
	printf("value=%f\n", packet.dvalue());
	printf("name=%s\n", packet.name());

	for(int i = 0; i < NameIndex; i++)
	{
		printf("%02X ", packet.data()[i]);
	}
	printf("\n");

	return 0;
}
