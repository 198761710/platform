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
	map<string,Variable> varmap;
public:
	typedef map<string,Variable>::iterator Iterator;
public:
	Cache(const string& name):cachename(name){}
public:
	map<string,Variable>::iterator begin(void){return varmap.begin();}
	map<string,Variable>::iterator end(void){return varmap.end();}
	map<string,Variable>::iterator find(const string& n){return varmap.find(n);}
public:
	const string& GetName(void){return cachename;}
	void SetName(const string& name){cachename=name;}
public:
	void Add(const string&);
	void Del(const string&);
	void Config(const string&,
				bool,
				ABType,
				IOType,
				bool,
				double,
				double,
				double,
				double);
public:
	void SetTokenFind(Token&);
	void SetTokenForce(Token&);
public:
	void GetInput(map<string,Variable>&);
	void GetOutput(map<string,Variable>&);
	void GetHolding(map<string,Variable>&);
	void Define(const string&, ABType, IOType);
};
extern Cache GlobalVariable;

#endif//__CACHE_H__
