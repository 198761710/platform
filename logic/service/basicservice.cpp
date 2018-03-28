#include <stdio.h>
#include "basicservice.h"

BasicService::BasicService(const string& s)
{
	server = s;
}

void BasicService::Run(void)
{
	Reciev();
	basicmanager.Run();
	cachemanager.Run();
}
bool BasicService::Process(void)
{
	switch( packet.type() )
	{
	case Pkt_SetVarABType:
		cachemanager.SetABType(packet.body());
		break;
	case Pkt_SetVarIOType:
		cachemanager.SetIOType(packet.body());
		break;
	case Pkt_SetVarInit:
		cachemanager.SetInit(packet.body());
		break;
	case Pkt_SetVarManual:
		cachemanager.SetManual(packet.body());
		break;
	case Pkt_SetVarRuntime:
		cachemanager.SetRuntime(packet.body());
		break;
	case Pkt_SetVarDeath:
		cachemanager.SetDeath(packet.body());
		break;
	case Pkt_SetBasAdd:
		basicmanager.Add(packet.body());
		break;
	case Pkt_SetBasDel:
		basicmanager.Del(packet.body());
		break;
	case Pkt_SetBasRun:
		basicmanager.SetRun(packet.body());
		break;
	case Pkt_SetBasDebug:
		basicmanager.SetDebug(packet.body());
		break;
	case Pkt_SetBasCompile:
		basicmanager.Compile(packet.body());
		break;
	default:
		return false;
	}
	return true;
}
void BasicService::Show(void)
{
	ShowCache(GlobalVariable);
	for(BasicManager::Iterator i = basicmanager.begin(); i != basicmanager.end(); i++)
	{
		ShowCache(i->second.GetCache());
	}
}
void BasicService::ShowCache(Cache& cache)
{
	printf("%s:\n", cache.GetName().data());
	for(Cache::Iterator i = cache.begin(); i != cache.end(); i++)
	{
		printf("name(%s)", i->second.GetName().data());
		printf(".init(%d)", i->second.GetInit());
		printf(".manual(%d)", i->second.GetManual());
		printf(".death(%.1f)", i->second.GetDeath());
		printf(".valueI(%.1f)", i->second.GetValueI());
		printf(".valueO(%.1f)", i->second.GetValueO());
		printf(".Ontime(%.1f)", i->second.GetOnTime());
		printf(".Offtime(%.1f)", i->second.GetOffTime());
		printf(".Runtime(%.0f)", i->second.GetRuntime());
		printf(".abtype(%d)", i->second.GetABType());
		printf(".iotype(%d)\n", i->second.GetIOType());
	}
}
