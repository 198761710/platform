#ifndef __SERVICE_H__
#define __SERVICE_H__
#include <map>
#include <string>
#include "basic.h"
#include "packet.h"
#include "unix-udp.h"
using namespace std;

class Service
{
protected:
	string peer;
	UnixUdp server;

public:
	Service(void);

public:
	virtual void Run(void);
	virtual void DoReceive(void);
	virtual bool StartServer(const string& path);
public:
	virtual bool ProcPacket(Packet& packet);

public:
	bool SendPacket(const string&, Packet& packet);
};

#endif//__SERVICE_H__
