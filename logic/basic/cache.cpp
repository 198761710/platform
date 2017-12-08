#include <stdio.h>
#include "token.h"
#include "cache.h"
#include "variable.h"

Cache GlobalVariable("GlobalVariable");

void Cache::SetToken(Token& token)
{
	token.SetVariable( variablemap[token.name] );
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
		printf(" %-14.1f |", i->second.Value());
		printf(" %-7d |", (int)i->second.Runtime());
		printf(" %-7d |", (int)i->second.OnTime());
		printf(" %-6d |\n", (int)i->second.OffTime());
	}
}
