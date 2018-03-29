#ifndef __BASIC_MANAGER_H__
#define __BASIC_MANAGER_H__
#include <map>
#include "basic.h"
using namespace std;

class BasicManager
{
protected:
	TimeOperator timer;
	map<string,Basic> basicmap;
public:
	typedef map<string,Basic>::iterator Iterator;
public:
	map<string,Basic>::iterator end(void){return basicmap.end();}
	map<string,Basic>::iterator begin(void){return basicmap.begin();}
	map<string,Basic>::iterator find(const string& n){return basicmap.find(n);}
public:
	void Run(void);
	void Add(const string&);
	void Del(const string&);
	void SetRun(const string&);
	void SetDebug(const string&);
	void Compile(const string&);
public:
	bool Load(const string&);
	bool Store(const string&);
protected:
	bool DoLoad(const string&);
	bool DoStore(const string&);
};

#endif//__BASIC_MANAGER_H__
