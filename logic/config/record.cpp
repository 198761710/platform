#include <stdlib.h>
#include <string.h>
#include "record.h"
#include "crc16.h"

Record::Record(void)
{
	buffer = 0;
	offset = -1;
}
Record::~Record(void)
{
	if( buffer )
	{
		free(buffer);
	}
	offset = -1;
}
const int Record::GetOffset(void)const
{
	return offset;
}
const int Record::GetDataLength(void)const
{
	if( NULL == buffer )
	{
		return 0;
	}
	int len = 0;

	len += (buffer[0] << 24);
	len += (buffer[1] << 16);
	len += (buffer[2] <<  8);
	len += (buffer[3] <<  0);

	return len;
}
const int Record::GetBufferLength(void)const
{
	if( NULL == buffer )
	{
		return 0;
	}
	return (4 + GetDataLength() + 2);
}
const unsigned char* Record::GetData(void)const
{
	if( NULL == buffer )
	{
		return 0;
	}
	return (buffer + 4);
}
const unsigned char* Record::GetBuffer(void)const
{
	return buffer;
}
const unsigned short Record::GetCrc(void)const
{
	if( NULL == buffer )
	{
		return 0;
	}
	int len = GetDataLength();
	unsigned short crc16 = 0;

	crc16 += (buffer[ (4 + len + 0) ] << 8);
	crc16 += (buffer[ (4 + len + 1) ] << 0);

	return crc16;
}
const bool Record::Check(void)const
{
	if( NULL == buffer )
	{
		return 0;
	}
	return (CRC16(GetData(), GetDataLength()) == GetCrc());
}
void Record::SetOffset(int offs)
{
	offset = offs;
}
void Record::SetData(const unsigned char *p, int len)
{
	if( NULL == p )
	{
		return;
	}
	if( len < MIN_RECORD_DATA_LEN )
	{
		return;
	}
	if( len > MAX_RECORD_DATA_LEN )
	{
		return;
	}
	if( Malloc(4 + len + 2) == false )
	{
		return;
	}
	buffer[0] = 0xff & (len >> 24);
	buffer[1] = 0xff & (len >> 16);
	buffer[2] = 0xff & (len >>  8);
	buffer[3] = 0xff & (len >>  0);
	memcpy(buffer + 4, p, len);
	int crc16 = CRC16(p, len);
	buffer[ (4 + len + 0) ] = 0xff & (crc16 >> 8);
	buffer[ (4 + len + 1) ] = 0xff & (crc16 >> 0);
}
bool Record::Malloc(int size)
{
	if( NULL != buffer )
	{
		free(buffer);
	}
	buffer = (unsigned char*)malloc(size);
	return (NULL != buffer);
}
void Record::Show(void)
{
	printf("%08X:[", GetOffset());
	for(int i = 0; i < GetBufferLength(); i++)
	{
		printf("%02X ", buffer[i]);
	}
	printf("\b].check(%d)\n", Check());
}
