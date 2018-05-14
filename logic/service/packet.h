#ifndef __SPACKET_H__
#define __SPACKET_H__
#include <string>
#include <stdint.h>
using namespace std;

/*
 *[type][cmd][auto][double][name]
 */

typedef enum
{
	Pkt_SetBasAdd,
	Pkt_SetBasDel,
	Pkt_SetBasRun,
	Pkt_SetBasDebug,
	Pkt_SetBasCompile,

	Pkt_SetVarAdd,
	Pkt_SetVarDel,
	Pkt_SetVarABType,
	Pkt_SetVarIOType,
	Pkt_SetVarInit,
	Pkt_SetVarValue,
	Pkt_SetVarDeath,
	Pkt_SetVarManual,
	Pkt_SetVarRuntime,

	Pkt_LoadBasic,
	Pkt_StoreBasic,
	Pkt_LoadVarible,
	Pkt_StoreVarible,
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
