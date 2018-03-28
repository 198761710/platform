#ifndef __BASIC_SERVICE_H__
#define __BASIC_SERVICE_H__
#include "service.h"
#include "cachemanager.h"
#include "basicmanager.h"

class BasicService : public Service
{
protected:
	CacheManager cachemanager;
	BasicManager basicmanager;
public:
	BasicService(const string&);
public:
	void Run(void);
	void Show(void);
	bool Process(void);
	void ShowCache(Cache&);
};

#endif//__BASIC_SERVICE_H__
