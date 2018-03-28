#include <stdio.h>
#include "fileoperator.h"
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
bool BasicManager::Load(const string& fname)
{
	filename = fname;
	return false;
}
bool BasicManager::Store(void)
{
	bool change = false;

	for(Iterator i = begin(); i != end(); i++)
	{
		if( i->second.Change() )
		{
			change = true;
		}
	}
	if( change && filename.empty() == false )
	{
		FileOperator filew;
		for(Iterator i = begin(); i != end(); i++)
		{
			filew.AddLine("%d,%s\n", i->second.GetRun(), i->second.GetName().data());
		}
		filew.AddLine("X");
		return (filew.Store(filename + "A") && filew.Store(filename + "B"));
	}
	return false;
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
