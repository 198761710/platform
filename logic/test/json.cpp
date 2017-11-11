#include <stdio.h>
#include "json.h"

int main(int argc, char **argv)
{
	Json json;

	json.StartObject();
	json.Key("pres");
	json.Double(31.23456);
	json.Key("temp");
	json.Double(23.23456);
	json.EndObject();
	printf("%s\n", json.GetJsonString());

	return 0;
}
