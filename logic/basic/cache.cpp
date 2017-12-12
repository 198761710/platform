#include <stdio.h>
#include "token.h"
#include "cache.h"
#include "variable.h"

Cache GlobalVariable("GlobalVariable");

void Cache::SetToken(Token& token)
{
	token.SetVariable( variablemap[token.name] );
}
void Cache::SetDefine(const string &name, ValueType val, VariableType var)
{
	variablemap[name].SetDefine(val, var);
}
Variable& Cache::GetVariable(const string& name)
{
	map<string,Variable>::iterator i = variablemap.find(name);
	if( variablemap.end() == i )
	{
		return sudovar;
	}
	return i->second;
}
bool Cache::GetOutput(map<string,Variable> &outmap)
{
	if( outtime.mdiff() < 100 )
	{
		return false;
	}
	outtime.init();
	for(Iterator i = variablemap.begin(); i != variablemap.end(); i++)
	{
		if( i->second.Output() )
		{
			outmap[i->first] = i->second;
		}
	}
	return (outmap.empty() == false);
}
void Cache::Show(void)
{
	printf("_______________________________________________________________\n");
	printf("|*********************** %14s **********************|\n", cachename.data());
	printf("|-------------------------------------------------------------|\n");
	printf("|     name     |      value      | runtime | ontime | offtime |\n");
	printf("|-------------------------------------------------------------|\n");
	for(Iterator i = variablemap.begin(); i != variablemap.end(); i++)
	{
		printf("| %-12s | ", i->first.data());
		printf(" %-14.1f |", i->second.GetValue());
		printf(" %-7d |", (int)i->second.GetRuntime());
		printf(" %-7d |", (int)i->second.GetOnTime());
		printf(" %-6d |\n", (int)i->second.GetOffTime());
	}
}
