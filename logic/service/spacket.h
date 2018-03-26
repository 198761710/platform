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
	SPkt_SetBasDel,
	SPkt_SetBasRun,
	SPkt_SetBasDebug,
	SPkt_SetBasCompile,

	SPkt_SetVarType,
	SPkt_SetVarInit,
	SPkt_SetVarValue,
	SPkt_SetVarDeath,
	SPkt_SetVarManual,
	SPkt_SetVarRuntime,
	SPkt_SetBasAdd,
}SCommandType;

class SPacket
{
protected:
	char buffer[256];

public:
	SPacket(void);
	SPacket(int, const string&);

public:
	unsigned char* data(void);
	unsigned int   length(void);

public:
	char  GetType();
	const string GetBody();
public:
	void SetType(char);
	void SetBody(const string&);
};

#endif//__SPACKET_H__
