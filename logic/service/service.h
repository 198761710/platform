#ifndef __SERVICE_H__
#define __SERVICE_H__
#include <map>
#include <string>
#include "packet.h"
#include "unix-udp.h"
using namespace std;

class Service
{
protected:
	UnixUdp server;
	map<string,CmdType> cmdmap;
	typedef map<string,CmdType>::iterator iterator;

public:
	Service(void);

public:
	void Run(void);
	bool StartServer(const string& path);
	bool ProcPacket(Packet& packet);
	bool SetValue(Packet& packet);
	bool GetValue(Packet& packet);
};

#endif//__SERVICE_H__
