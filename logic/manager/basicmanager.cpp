#include <stdio.h>
#include "basicmanager.h"

void BasicManager::Run(void)
{
	for(Iterator i = begin(); i != end(); i++)
	{
		if( i->second.GetRun() )
		{
			i->second.Execute();
		}
	}
}
void BasicManager::Add(const string& args)
{
	basicmap[args].SetName(args);
}
void BasicManager::Del(const string& args)
{
	basicmap.erase(args);
}
void BasicManager::SetDebug(const string& args)
{
	int debug = 0;
	char name[256] = {0};

	if( args.empty() )
	{
		return;
	}

	sscanf(args.data(), "%d,%s", &debug, name);

	Iterator i = find( string(name) );

	if( end() != i )
	{
		i->second.SetDebug(!!debug);
	}
}
void BasicManager::SetRun(const string& args)
{
	int run = 0;
	char name[256] = {0};

	if( args.empty() )
	{
		return;
	}

	sscanf(args.data(), "%d,%s", &run, name);

	Iterator i = find( string(name) );

	if( end() != i )
	{
		i->second.SetRun(run);
	}
}
void BasicManager::Compile(const string& args)
{
	Iterator i = find( args );

	if( end() != i )
	{
		printf("%s.Compile\n", i->second.GetName().data());
		i->second.Compile();
	}
}
