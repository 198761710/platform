#ifndef __CACHE_H__
#define __CACHE_H__
#include <map>
#include <string>
#include "token.h"
#include "variable.h"
using namespace std;

class Cache
{
protected:
	string cachename;
	Variable sudovar;
	TimeOperator outtime;
	map<string,Variable> variablemap;
	typedef map<string,Variable>::iterator Iterator;
public:
	Cache(const string& name):cachename(name){}

public:
	void Show(void);
	void SetToken(Token& token);
	bool GetOutput(map<string,Variable> &);
	Variable& GetVariable(const string& name);
	void SetDefine(const string&, ValueType, VariableType);
};
extern Cache GlobalVariable;

#endif//__CACHE_H__
