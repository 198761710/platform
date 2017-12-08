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
	map<string,Basic> basicmap;

public:
	Service(void);

public:
	void Run(void);
	void RunBasic(void);
	bool StartServer(const string& path);
public:
	bool ProcPacket(Packet& packet);

	bool SoftSetValue(Packet& packet);
	bool HardSetValue(Packet& packet);
	bool GetValue(Packet& packet);

	bool SetBasicRun(Packet& packet);
	bool SetBasicLoad(Packet& packet);
	bool SetBasicDebug(Packet& packet);
	bool GetBasicRun(Packet& packet);
	bool GetBasicDebug(Packet& packet);
};

#endif//__SERVICE_H__
