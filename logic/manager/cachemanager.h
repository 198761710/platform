#ifndef __CACHE_MANAGER_H__
#define __CACHE_MANAGER_H__
#include "cache.h"
using namespace std;

class CacheManager
{
protected:
	typedef map<string,Variable>::iterator Iterator;
protected:
	map<string,Variable>::iterator begin(void);
	map<string,Variable>::iterator end(void);
	map<string,Variable>::iterator find(const string&);

public:
	void Run(void);
	void Add(const string&);
	void Del(const string&);
	void SetInit(const string&);
	void SetValue(const string&);
	void SetDeath(const string&);
	void SetManual(const string&);
	void SetRuntime(const string&);
	void SetValueType(const string&);
	void SetVariableType(const string&);
};

#endif//__CACHE_MANAGER_H__
