#ifndef __BASIC_MANAGER_H__
#define __BASIC_MANAGER_H__
#include <map>
#include "basic.h"
using namespace std;

class BasicManager
{
protected:
	map<string,Basic> basicmap;
	typedef map<string,Basic>::iterator Iterator;

protected:
	map<string,Basic>::iterator begin(void);
	map<string,Basic>::iterator end(void);
	map<string,Basic>::iterator find(const string&);

public:
	void Run(void);
	void Add(const string&);
	void Del(const string&);
	void SetRun(const string&);
	void SetDebug(const string&);
	void Compile(const string&);
};

#endif//__BASIC_MANAGER_H__
