#include <stdio.h>
#include "cgi.h"

int main(void)
{
	Cgi cgi;
	string cmd = "echo '";

	cmd += cgi.getEnvironment().getPostData();
	cmd += "' > example.bas";
	system(cmd.data());

	printf("Access-Control-Allow-Origin:*\r\n");
	printf("Content-Type:text/plain\r\n");
	printf("\r\n");
	printf("\r\n");
	printf("200 OK");

	return 0;
}
