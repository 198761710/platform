#ifndef __VAR_OPERATOR_H__
#define __VAR_OPERATOR_H__
#include <map>
#include <string>
#include "packet.h"
using namespace std;

class VarOperator
{
protected:
	Packet packet;
	map<string,int> typemap;

public:
	VarOperator(void);

public:
	Packet& GetPacket(void);

public:
	bool ProcRequest(const string&, const string&, const string&);

public:
	bool SetInit(const string& name, const string& value);
	bool SetValue(const string& name, const string& value);
	bool SetManual(const string& name, const string& value);
	bool SetRuntime(const string& name, const string& value);
	bool SetThreshold(const string& name, const string& value);
};
#endif//__VAR_OPERATOR_H__
