#include <stdio.h>
#include <unistd.h>
#include "unix-udp.h"
#include "json.h"

int main(void)
{
	string path;
	UnixUdp unixudp;
	string server_path = "unixudp.udp.server.socket";

	unixudp.Open();
	if( unixudp.Connect(server_path) )
	{
		return 0;
	}
	unixudp.Unlink(server_path);
	if( unixudp.Bind(server_path) )
	{
		printf("bind(%s) ok\n", server_path.data());
	}
	unixudp.Unblock();
	while(1)
	{
		char buf[1024] = {0};
		static int i = 0;i++;
		int len = unixudp.RecvFrom(path, buf, sizeof(buf));
		if( len > 0 )
		{
			buf[len] = 0;
			Json json;
			json.Parse(buf);
			printf("value1:%f\n", json["value1"].GetDouble());
			printf("value2:%f\n", json["value2"].GetDouble());
		}
		path.clear();
		usleep(1);
	}
	return 0;
}
