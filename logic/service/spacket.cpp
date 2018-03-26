#include <stdio.h>
#include <string.h>
#include "spacket.h"


SPacket::SPacket(void)
{
	memset(buffer, 0, sizeof(buffer));
}
SPacket::SPacket(int type, const string& body)
{
	memset(buffer, 0, sizeof(buffer));
	SetType(type);
	SetBody(body);
}

unsigned char* SPacket::data(void)
{
	return (unsigned char*)buffer;
}
unsigned int   SPacket::length(void)
{
	return sizeof(buffer);
}
char SPacket::GetType(void)
{
	return buffer[0];
}
const string SPacket::GetBody(void)
{
	return string(&buffer[1]);
}
void SPacket::SetType(char type)
{
	buffer[0] = type;
}
void SPacket::SetBody(const string& body)
{
	if( body.empty() == false )
	{
		snprintf(buffer+1, sizeof(buffer)-1, "%s", body.data());
	}
}

