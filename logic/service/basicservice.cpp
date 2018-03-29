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
	case Pkt_LoadBasic:
		basicmanager.Load(packet.body());
		break;
	case Pkt_StoreBasic:
		basicmanager.Store(packet.body());
		break;

	case Pkt_LoadVarible:
		cachemanager.Load(packet.body());
		break;
	case Pkt_StoreVarible:
		cachemanager.Store(packet.body());
		break;
	case Pkt_SetVarAdd:
		cachemanager.Add(packet.body());
		break;
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
	printf("%20s|", "name");
	printf("%s|", "init");
	printf("%s|", "manual");
	printf("%6s|", "abtype");
	printf("%6s|", "iotype");
	printf("%6s|", "death");
	printf("%12s|", "valueI");
	printf("%12s|", "valueO");
	printf("%12s|", "ontime");
	printf("%12s|", "offtime");
	printf("%12s\n", "runtime");
	for(Cache::Iterator i = cache.begin(); i != cache.end(); i++)
	{
		printf("%20s|", i->second.GetName().data());
		printf("%4d|", i->second.GetInit());
		printf("%6d|", i->second.GetManual());
		switch(i->second.GetABType())
		{
			case AB_Binary:
				printf("%6s|", "Binary");
				break;
			case AB_Analog:
				printf("%6s|", "Analog");
				break;
		}
		switch(i->second.GetIOType())
		{
			case IO_Holding:
				printf("%6s|", "Holdin");
				break;
			case IO_Input:
				printf("%6s|", "Input");
				break;
			case IO_Output:
				printf("%6s|", "Output");
				break;
		}
		printf("%.4f|", i->second.GetDeath());
		printf("%12.1f|", i->second.GetValueI());
		printf("%12.1f|", i->second.GetValueO());
		printf("%12.0f|", i->second.GetOnTime());
		printf("%12.0f|", i->second.GetOffTime());
		printf("%12.0f\n", i->second.GetRuntime());
	}
}
