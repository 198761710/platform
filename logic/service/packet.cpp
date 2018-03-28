#include <stdio.h>
#include <string.h>
#include "packet.h"


Packet::Packet(void)
{
	memset(buffer, 0, sizeof(buffer));
}
Packet::Packet(int t, const string& b)
{
	memset(buffer, 0, sizeof(buffer));
	type(t);
	body(b);
}
const char* Packet::data(void)const
{
	return (const char*)buffer;
}
const int   Packet::length(void)const
{
	return sizeof(buffer);
}
const char Packet::type(void)const
{
	return buffer[0];
}
const string Packet::body(void)const
{
	return string(&buffer[1]);
}
void Packet::type(const char t)
{
	buffer[0] = t;
}
void Packet::body(const string& b)
{
	if( b.empty() == false )
	{
		snprintf(buffer+1, sizeof(buffer)-1, "%s", b.data());
	}
}

