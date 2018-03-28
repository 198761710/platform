#include <stdio.h>
#include <unistd.h>
#include "unix-udp.h"
#include "json.h"

int main(int argc, char **argv)
{
	Json json;
	UnixUdp unixudp;
	string client_path = ".clien";
	string server_path = ".server";

	unixudp.Open();
	if( unixudp.Connect(client_path) )
	{
		return 0;
	}
	else
	{
		unixudp.Unlink(client_path);
	}
	if( unixudp.Bind(client_path) )
	{
		printf("bind(%s) ok\n", client_path.data());
	}
	else
	{
		printf("bind(%s) failed\n", client_path.data());
	}
	unixudp.Unblock();

	json.StartObject();
	json.Key("value1");
	json.Double(1.23456);
	json.Key("value2");
	json.Double(9.23456);
	json.EndObject();

	while(1)
	{
		const char *p = json.GetJsonString();
		if( unixudp.SendTo(server_path, p, strlen(p)) > 0 )
		{
		}
		usleep(100*1000);
	}
	return 0;
}
