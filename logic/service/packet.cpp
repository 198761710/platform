#include <string.h>
#include "packet.h"

Packet::Packet(void)
{
	memset(buffer, 0, sizeof(buffer));
}
unsigned char* Packet::data(void)
{
	return buffer;
}
unsigned int Packet::size(void)
{
	return sizeof(buffer);
}
unsigned char Packet::type(void)
{
	return buffer[TypeIndex];
}
const double Packet::value(void)
{
	union{
		unsigned short s;
		unsigned char c[2];
	}endian;
	union{
		double db;
		unsigned char c[sizeof(double)];
	}value;

	endian.s = 0xaabb;

	if( 0xaa == endian.c[0] )
	{
		value.c[ 0 ] = buffer[ ValueIndex0 ];
		value.c[ 1 ] = buffer[ ValueIndex1 ];
		value.c[ 2 ] = buffer[ ValueIndex2 ];
		value.c[ 3 ] = buffer[ ValueIndex3 ];
		value.c[ 4 ] = buffer[ ValueIndex4 ];
		value.c[ 5 ] = buffer[ ValueIndex5 ];
		value.c[ 6 ] = buffer[ ValueIndex6 ];
		value.c[ 7 ] = buffer[ ValueIndex7 ];
	}
	else
	{
		value.c[ 7 ] = buffer[ ValueIndex0 ];
		value.c[ 6 ] = buffer[ ValueIndex1 ];
		value.c[ 5 ] = buffer[ ValueIndex2 ];
		value.c[ 4 ] = buffer[ ValueIndex3 ];
		value.c[ 3 ] = buffer[ ValueIndex4 ];
		value.c[ 2 ] = buffer[ ValueIndex5 ];
		value.c[ 1 ] = buffer[ ValueIndex6 ];
		value.c[ 0 ] = buffer[ ValueIndex7 ];
	}

	return value.db;
}
unsigned int Packet::length(void)
{
	return (unsigned int)buffer[LengthIndex];
}
const char* Packet::name(void)
{
	buffer[MaxIndex] = 0;
	return (const char*)&buffer[NameIndex];
}

void Packet::type(unsigned char t)
{
	buffer[TypeIndex] = t;
}
void Packet::value(const double &v)
{
	union{
		unsigned short s;
		unsigned char c[2];
	}endian;
	union{
		double db;
		unsigned char c[sizeof(double)];
	}value;

	value.db = v;
	endian.s = 0xaabb;	
	if( 0xaa == endian.c[0] )
	{
		buffer[ ValueIndex0 ] = value.c[ 0 ];
		buffer[ ValueIndex1 ] = value.c[ 1 ];
		buffer[ ValueIndex2 ] = value.c[ 2 ];
		buffer[ ValueIndex3 ] = value.c[ 3 ];
		buffer[ ValueIndex4 ] = value.c[ 4 ];
		buffer[ ValueIndex5 ] = value.c[ 5 ];
		buffer[ ValueIndex6 ] = value.c[ 6 ];
		buffer[ ValueIndex7 ] = value.c[ 7 ];
	}
	else
	{
		buffer[ ValueIndex0 ] = value.c[ 7 ];
		buffer[ ValueIndex1 ] = value.c[ 6 ];
		buffer[ ValueIndex2 ] = value.c[ 5 ];
		buffer[ ValueIndex3 ] = value.c[ 4 ];
		buffer[ ValueIndex4 ] = value.c[ 3 ];
		buffer[ ValueIndex5 ] = value.c[ 2 ];
		buffer[ ValueIndex6 ] = value.c[ 1 ];
		buffer[ ValueIndex7 ] = value.c[ 0 ];
	}
}
bool Packet::name(const char *buf)
{
	int len = 0;

	if( NULL == buf )
	{
		return false;
	}
	if( (len = strlen(buf)) < 1 )
	{
		return false;
	}
	if( len > (MaxIndex - NameIndex) )
	{
		len = (MaxIndex - NameIndex);
	}
	memcpy(buffer+NameIndex, buf, len);
	return true;
}

