#ifndef __CACHE_MANAGER_H__
#define __CACHE_MANAGER_H__
#include "cache.h"
using namespace std;

class CacheManager
{
protected:
	string filename;
	TimeOperator timer;
protected:
	Cache::Iterator end(void){return GlobalVariable.end();}
	Cache::Iterator begin(void){return GlobalVariable.begin();}
	Cache::Iterator find(const string& n){return GlobalVariable.find(n);}

public:
	void Run(void);
	bool Store(void);
	bool Load(const string&);
public:
	void Add(const string&);
	void Del(const string&);
	void SetInit(const string&);
	void SetValue(const string&);
	void SetDeath(const string&);
	void SetManual(const string&);
	void SetRuntime(const string&);
	void SetIOType(const string&);
	void SetABType(const string&);
public:
	void GetInput(map<string,Variable>&);
	void GetOutput(map<string,Variable>&);
	void GetHolding(map<string,Variable>&);
};

#endif//__CACHE_MANAGER_H__
