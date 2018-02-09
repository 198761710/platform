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
	map<string,Variable>::iterator begin(void);
	map<string,Variable>::iterator end(void);
public:
	void Show(void);
	void SetTokenFind(Token& token);
	void SetTokenForce(Token& token);
	bool GetOutput(map<string,Variable> &);
	void GetInputList(map<string,Variable>& varmap);
	void GetOutputList(map<string,Variable>& varmap);
	void GetValueList(map<string,Variable>& varmap);
	void SetDefine(const string&, ValueType, VariableType);
	Variable& GetVariable(const string& name);
};
extern Cache GlobalVariable;

#endif//__CACHE_H__
