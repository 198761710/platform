#include <unistd.h>
#include "basic.h"
#include "cache.h"

extern Cache GlobalVariable;

int main(int argc, char **argv)
{
	time_t t = 0;
	Basic basic;
	string file = "example.bas";

	if( argc > 1 )
	{
		file = argv[1];
	}
	basic.run(1);
	basic.name(file);
	while( basic.load() )
	{
		if( time(0) - t != 0 )
		{
			t = time(0);
			basic.show();
			GlobalVariable.Show();
		}
		basic.execute();
		usleep(1);
	}
	return 0;
}
