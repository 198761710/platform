#include <stdio.h>
#include "varoperator.h"
#include "service.h"
#include "cgi.h"

int main(void)
{
	Cgi cgi;
	Service service;
	VarOperator var;
	string to = "basicservice.unix";

	cout << "Content-Type:text/html\r\n"  << endl;

	string type = cgi["type"];
	string name = cgi["name"];
	string value= cgi["value"];

	if( var.ProcRequest(type, name, value) == false )
	{
		return -1;
	}
	if( !service.StartServer("varoperator.unix") )
	{
		return -2;
	}
	service.SendPacket(to, var.GetPacket());

	return 0;
}
