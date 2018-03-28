#include <stdio.h>
#include <unistd.h>
#include "basic.h"
#include "cache.h"

extern Cache GlobalVariable;

void ShowCache(Cache&);

int main(int argc, char **argv)
{
	time_t t = 0;
	Basic basic;
	string file = "example.bas";

	if( argc > 1 )
	{
		file = argv[1];
	}
	basic.SetRun(1);
	basic.SetName(file);
	if( basic.Compile() )
	{
		while(1)
		{
			if( time(0) - t != 0 )
			{
				t = time(0);
				ShowCache(GlobalVariable);
				ShowCache(basic.GetCache());
			}
			basic.Execute();
			usleep(1000);
		}
	}
	return 0;
}

void ShowCache(Cache& cache)
{
	printf("%s:\n", cache.GetName().data());
	for(Cache::Iterator i = cache.begin(); i != cache.end(); i++)
	{
		printf("name(%s)", i->second.GetName().data());
		printf(".init(%d)", i->second.GetInit());
		printf(".manual(%d)", i->second.GetManual());
		printf(".death(%.1f)", i->second.GetDeath());
		printf(".valueI(%.1f)", i->second.GetValueI());
		printf(".valueO(%.1f)", i->second.GetValueO());
		printf(".Ontime(%.1f)", i->second.GetOnTime());
		printf(".Offtime(%.1f)", i->second.GetOffTime());
		printf(".Runtime(%.0f)", i->second.GetRuntime());
		printf(".abtype(%d)", i->second.GetABType());
		printf(".iotype(%d)\n", i->second.GetIOType());
	}
}
