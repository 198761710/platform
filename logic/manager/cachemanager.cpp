#include <stdio.h>
#include "cachemanager.h"


void CacheManager::Run(void)
{
}
bool CacheManager::Load(const string& fname)
{
	filename = fname;
	return false;
}
bool CacheManager::Store(void)
{
	return true;
}
void CacheManager::Add(const string& args)
{
	GlobalVariable.Add(args);
}
void CacheManager::Del(const string& args)
{
	GlobalVariable.Del(args);
}
void CacheManager::SetInit(const string& args)
{
	if( args.empty() == false )
	{
		Cache::Iterator i;
		int init = 0;
		char name[256] = {0};

		sscanf(args.data(), "%d,%s", &init, name);

		if( (i = find(string(name))) == end() )
		{
			return;
		}
		i->second.SetInit( init );
	}
}
void CacheManager::SetValue(const string& args)
{
	if( args.empty() == false )
	{
		Cache::Iterator i;
		double value = 0.0;
		char name[256] = {0};

		sscanf(args.data(), "%lf,%s", &value, name);

		if( (i = find(string(name))) == end() )
		{
			return;
		}
		i->second.SetReal( value );
	}
}
void CacheManager::SetDeath(const string& args)
{
	if( args.empty() == false )
	{
		Cache::Iterator i;
		double death = 0.0;
		char name[256] = {0};

		sscanf(args.data(), "%lf,%s", &death, name);

		if( (i = find(string(name))) == end() )
		{
			return;
		}
		i->second.SetDeath( death );
	}
}
void CacheManager::SetManual(const string& args)
{
	if( args.empty() == false )
	{
		Cache::Iterator i;
		int manual = 0;
		char name[256] = {0};

		sscanf(args.data(), "%d,%s", &manual, name);

		if( (i = find(string(name))) == end() )
		{
			return;
		}
		i->second.SetManual( manual );
	}
}
void CacheManager::SetRuntime(const string& args)
{
	if( args.empty() == false )
	{
		Cache::Iterator i;
		int runtime = 0;
		char name[256] = {0};

		sscanf(args.data(), "%d,%s", &runtime, name);

		if( (i = find(string(name))) == end() )
		{
			return;
		}
		i->second.SetRuntime( runtime );
	}
}
void CacheManager::SetIOType(const string& args)
{
	if( args.empty() == false )
	{
		Cache::Iterator i;
		int type = 0;
		char name[256] = {0};

		sscanf(args.data(), "%d,%s", &type, name);

		if( (i = find(string(name))) == end() )
		{
			return;
		}
		i->second.SetIOType( (IOType)type );
	}
}
void CacheManager::SetABType(const string& args)
{
	if( args.empty() == false )
	{
		Cache::Iterator i;
		int type = 0;
		char name[256] = {0};

		sscanf(args.data(), "%d,%s", &type, name);

		if( (i = find(string(name))) == end() )
		{
			return;
		}
		i->second.SetABType( (ABType)type );
	}
}
void CacheManager::GetInput(map<string,Variable>& m)
{
	GlobalVariable.GetInput(m);
}
void CacheManager::GetOutput(map<string,Variable>& m)
{
	GlobalVariable.GetOutput(m);
}
void CacheManager::GetHolding(map<string,Variable>& m)
{
	GlobalVariable.GetHolding(m);
}
