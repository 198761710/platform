#include <stdio.h>
#include "token.h"
#include "cache.h"
#include "variable.h"

Cache GlobalVariable("GlobalVariable");

void Cache::Add(const string& name)
{
	varmap[name].SetName(name);
}
void Cache::Del(const string& name)
{
	Iterator i = find(name);
	if( end() != i )
	{
		i->second.SetChange(2);
	}
}
void Cache::SetTokenFind(Token& token)
{
	Iterator i = find(token.name);

	if( end() != i )
	{
		token.SetVariable( varmap[token.name] );
	}
	else
	{
		token.bindup = false;
	}
}
void Cache::SetTokenForce(Token& token)
{
	Variable& var = varmap[token.name];
	var.SetName(token.name);
	token.SetVariable( var );
}
void Cache::Define(const string &name, ABType ab, IOType io)
{
	varmap[name].SetName(name);
	varmap[name].Define(ab, io);
}
void Cache::GetInput(map<string,Variable>& m)
{
	for(Iterator i = varmap.begin(); i != varmap.end(); i++)
	{
		if( i->second.GetIOType() == IO_Input )
		{
			m[i->first] = i->second;
		}
	}
}
void Cache::GetOutput(map<string,Variable>& m)
{
	for(Iterator i = begin(); i != varmap.end(); i++)
	{
		if( i->second.GetIOType() == IO_Output )
		{
			m[i->first] = i->second;
		}
	}
}
void Cache::GetHolding(map<string,Variable>& m)
{
	for(Iterator i = begin(); i != varmap.end(); i++)
	{
		if( i->second.GetIOType() == IO_Holding)
		{
			m[i->first] = i->second;
		}
	}
}
