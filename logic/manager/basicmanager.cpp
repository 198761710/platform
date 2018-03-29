#include <stdio.h>
#include "lineoperator.h"
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
	if( DoLoad(fname + "A") )
	{
		return true;
	}
	return DoLoad(fname + "B");
}
bool BasicManager::DoLoad(const string& fname)
{
	FileOperator file;

	if( file.Load(fname) )
	{
		for(FileOperator::Iterator i = file.begin(); i != file.end(); i++)
		{
			if( LineOperator(i->second).Check() == false )
			{
				return false;
			}
		}
		for(FileOperator::Iterator i = file.begin(); i != file.end(); i++)
		{
			Add(LineOperator(i->second).Trim());
			SetRun(LineOperator(i->second).Trim());
			Compile(LineOperator(i->second).Trim());
		}
		for(Iterator i = begin(); i != end(); i++)
		{
			i->second.SetChange(false);
		}
		return true;
	}
	return false;
}
bool BasicManager::Store(const string& filename)
{
	bool change = false;

	for(Iterator i = begin(); i != end(); i++)
	{
		if( i->second.GetChange() )
		{
			change = true;
			i->second.SetChange(false);
		}
	}
	DoStore(filename + "A");
	DoStore(filename + "B");
	return change;
}
bool BasicManager::DoStore(const string& filename)
{
	FileOperator file;
	for(Iterator i = begin(); i != end(); i++)
	{
		LineOperator line;
		line.Add(i->second.GetRun());
		line.Add(i->second.GetName());
		file.AddLine(line.Make());
	}
	return file.Store(filename);
}
void BasicManager::Add(const string& args)
{
	int x = 0;
	char name[256] = {0};
	LineOperator line(args);


	if( line.Scan("%d,%s", &x, name) == 2 )
	{
		basicmap[name].SetName(name);
	}
}
void BasicManager::Del(const string& args)
{
	int x = 0;
	char name[256] = {0};
	LineOperator line(args);


	if( line.Scan("%d,%s", &x, name) == 2 )
	{
		basicmap.erase(name);
	}
}
void BasicManager::SetDebug(const string& args)
{
	int x = 0;
	char name[256] = {0};
	LineOperator line(args);


	if( line.Scan("%d,%s", &x, name) == 2 )
	{
		Iterator i = find( string(name) );

		if( end() != i )
		{
			i->second.SetDebug(x);
		}
	}
}
void BasicManager::SetRun(const string& args)
{
	int x = 0;
	char name[256] = {0};
	LineOperator line(args);


	if( line.Scan("%d,%s", &x, name) == 2 )
	{
		Iterator i = find( string(name) );

		if( end() != i )
		{
			i->second.SetRun(x);
		}
	}
}
void BasicManager::Compile(const string& args)
{
	int x = 0;
	char name[256] = {0};
	LineOperator line(args);


	if( line.Scan("%d,%s", &x, name) == 2 )
	{
		Iterator i = find( string(name) );

		if( end() != i )
		{
			i->second.Compile();
		}
	}
}
