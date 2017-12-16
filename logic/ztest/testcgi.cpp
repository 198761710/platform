#include <stdio.h>
#include "cgi.h"

int main(void)
{
	Cgi cgi;

	cout << "Content-Type:text/html\r\n"  << endl;

	printf("<h1>cgi fields</h1>");
	for(Cgi::Qiterator i = cgi.begin(); i != cgi.end(); i++)
	{
		printf("<h1>%s = %s</h1>", i->first.data(), i->second.data());
	}

	return 0;
}
