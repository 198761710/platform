#ifndef __PACKET_H__
#define __PACKET_H__

/*
 *[type][cmd][auto][double][name]
 */

typedef enum
{
	CmdValueSet  = 0,
	CmdValueGet  = 1,
	CmdSetBasicRun  = 2,
	CmdSetBasicLoad = 3,
	CmdSetBasicDebug= 4,
	CmdGetBasicRun  = 5,
	CmdGetBasicDebug= 6,
}CmdEnumDef;

typedef enum
{
	Auto   = 0,
	Manual = 1,
}AutoEnumDef;

typedef enum
{
	TypeIndex   = 0,
	AutoIndex   = 1,
	ValueIndex0 = 2,
	ValueIndex1 = 3,
	ValueIndex2 = 4,
	ValueIndex3 = 5,
	ValueIndex4 = 6,
	ValueIndex5 = 7,
	ValueIndex6 = 8,
	ValueIndex7 = 9,
	LengthIndex = 10,
	NameIndex	= 11,
	MaxIndex	= 127,
}IndexEnumDef;

class Packet
{
protected:
	unsigned char buffer[MaxIndex+1];

public:
	Packet(void);

public:
	unsigned char* data(void);
	unsigned int   size(void);

public:
	unsigned char type(void);
	unsigned char autx(void);
	const double  dvalue(void);
	unsigned int  uvalue(void);
	unsigned int  length(void);
	const char*	  name(void);

public:
	void type(unsigned char t);
	void autx(unsigned char a);
	void dvalue(const double &v);
	void uvalue(unsigned int v);
	bool name(const char *buf);
};

#endif//__PACKET_H__
