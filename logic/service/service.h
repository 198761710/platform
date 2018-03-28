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
	string client;
	string server;
	Packet packet;
	UnixUdp socket;

public:
	Service(void);
	Service(const string&);

public:
	virtual void Run(void);
	virtual bool Start(void);
	virtual void Reciev(void);
	virtual bool Process(void);
	virtual bool Send(const string&, const Packet& packet);
};

#endif//__SERVICE_H__
