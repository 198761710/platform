#include <stdio.h>
#include "cachemanager.h"


map<string,Variable>::iterator CacheManager::begin(void)
{
	return GlobalVariable.begin();
}
map<string,Variable>::iterator CacheManager::end(void)
{
	return GlobalVariable.end();
}
map<string,Variable>::iterator CacheManager::find(const string& name)
{
	return GlobalVariable.find(name);
}
void CacheManager::Run(void)
{
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
		Iterator i;
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
		Iterator i;
		double value = 0.0;
		char name[256] = {0};

		sscanf(args.data(), "%lf,%s", &value, name);

		if( (i = find(string(name))) == end() )
		{
			return;
		}
		i->second.HardSetValue( value );
	}
}
void CacheManager::SetDeath(const string& args)
{
	if( args.empty() == false )
	{
		Iterator i;
		double death = 0.0;
		char name[256] = {0};

		sscanf(args.data(), "%lf,%s", &death, name);

		if( (i = find(string(name))) == end() )
		{
			return;
		}
		i->second.SetThreshold( death );
	}
}
void CacheManager::SetManual(const string& args)
{
	if( args.empty() == false )
	{
		Iterator i;
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
		Iterator i;
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
void CacheManager::SetValueType(const string& args)
{
	if( args.empty() == false )
	{
		Iterator i;
		int type = 0;
		char name[256] = {0};

		sscanf(args.data(), "%d,%s", &type, name);

		if( (i = find(string(name))) == end() )
		{
			return;
		}
		i->second.SetValueType( (ValueType)type );
	}
}
void CacheManager::SetVariableType(const string& args)
{
	if( args.empty() == false )
	{
		Iterator i;
		int type = 0;
		char name[256] = {0};

		sscanf(args.data(), "%d,%s", &type, name);

		if( (i = find(string(name))) == end() )
		{
			return;
		}
		i->second.SetVariableType( (VariableType)type );
	}
}
