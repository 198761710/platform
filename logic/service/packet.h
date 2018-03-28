#ifndef __SPACKET_H__
#define __SPACKET_H__
#include <string>
using namespace std;

/*
 *[type][cmd][auto][double][name]
 */
 typedef unsigned char	uint8_t;
 typedef unsigned short	uint16_t;
 typedef unsigned int	uint32_t;
 typedef unsigned long	long uint64_t;

typedef enum
{
	Pkt_SetBasDel,
	Pkt_SetBasRun,
	Pkt_SetBasDebug,
	Pkt_SetBasCompile,

	Pkt_SetVarABType,
	Pkt_SetVarIOType,
	Pkt_SetVarInit,
	Pkt_SetVarValue,
	Pkt_SetVarDeath,
	Pkt_SetVarManual,
	Pkt_SetVarRuntime,
	Pkt_SetBasAdd,
}SCommandType;

class Packet
{
protected:
	char buffer[256];
public:
	Packet(void);
	Packet(int, const string&);
public:
	const char* data(void)const;
	const int   length(void)const;
public:
	const char  type(void)const;
	const string body(void)const;
public:
	void type(const char);
	void body(const string&);
};

#endif//__SPACKET_H__
