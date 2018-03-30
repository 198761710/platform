#include <stdio.h>
#include "lineoperator.h"
#include "fileoperator.h"
#include "cachemanager.h"

void CacheManager::Run(void)
{
}
bool CacheManager::Load(const string& fname)
{
	if( DoLoad(fname + "A") )
	{
		return true;
	}
	return DoLoad(fname + "B");
}
bool CacheManager::DoLoad(const string& fname)
{
	FileOperator file;

	if( file.Load(fname) == false )
	{
		return false;
	}
	for(FileOperator::Iterator i = file.begin(); i != file.end(); i++)
	{
		Config(i->second);
	}
	return true;
}
bool CacheManager::Store(const string& fname)
{
	bool change = false;

	for(Cache::Iterator i = begin(); i != end(); i++)
	{
		switch( i->second.GetChange() )
		{
			case Chg_Chnage:
				change = true;
				i->second.SetChange(Chg_Unchange);
				break;
			case Chg_Delete:
				change = true;
				i->second.SetChange(Chg_Deleted);
				break;
		}
	}
	if( false == change )
	{
		return true;
	}
	if( DoStore(fname + "A") )
	{
		return DoStore(fname + "B");
	}
	return false;
}
bool CacheManager::DoStore(const string& fname)
{
	FileOperator file;

	for(Cache::Iterator i = begin(); i != end(); i++)
	{
		if( i->second.GetChange() == Chg_Deleted )
		{
			continue;
		}
		LineOperator line;

		line.Add( i->second.GetInit() );
		line.Add( i->second.GetABType() );
		line.Add( i->second.GetIOType() );
		line.Add( i->second.GetManual() );
		line.Add( i->second.GetDeath() );
		line.Add( i->second.GetValueI() );
		line.Add( i->second.GetValueO() );
		line.Add( i->second.GetRuntime() );
		line.Add( i->second.GetName() );

		file.AddLine( line.Make() );
	}

	return file.Store(fname);
}
void CacheManager::Add(const string& args)
{
	return GlobalVariable.Add(args);
}
void CacheManager::Del(const string& args)
{
	GlobalVariable.Del(args);
}
void CacheManager::Config(const string& args)
{
	int init = 0;
	int abtype = 0;
	int iotype = 0;
	int manual = 0;
	char name[64];
	double death = 0.0;
	double valueI = 0.0;
	double valueO = 0.0;
	double runtime = 0.0;
	LineOperator line(args);

	line.Trim();
	line.Scan("%d,%d,%d,%d,%lf,%lf,%lf,%lf,%s",
			&init,
			&abtype,
			&iotype,
			&manual,
			&death,
			&valueI,
			&valueO,
			&runtime,
			name);
	name[sizeof(name)-1] = 0;
	GlobalVariable.Config(name,
						  !!init,
						  (ABType)abtype,
						  (IOType)iotype,
						  !!manual,
						  death,
						  valueI,
						  valueO,
						  runtime);
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
