#ifndef __PACKET_H__
#define __PACKET_H__

/*---[type][double][name]---*/

typedef enum
{
	CmdSetValue=0,
	CmdGetValue=1,
}CmdType;

typedef enum
{
	TypeIndex=0,
	ValueIndex0 = 1,
	ValueIndex1 = 2,
	ValueIndex2 = 3,
	ValueIndex3 = 4,
	ValueIndex4 = 5,
	ValueIndex5 = 6,
	ValueIndex6 = 7,
	ValueIndex7 = 8,
	LengthIndex = 9,
	NameIndex	= 10,
	MaxIndex	= 127,
}IndexType;

class Packet
{
protected:
	unsigned char buffer[MaxIndex+1];

public:
	Packet(void);

public:
	unsigned char*  data(void);
	unsigned int    size(void);

public:
	unsigned char	type(void);
	const double	value(void);
	unsigned int	length(void);
	const char*		name(void);

public:
	void type(unsigned char t);
	void value(const double &v);
	bool name(const char *buf);
};

#endif//__PACKET_H__
