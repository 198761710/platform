#ifndef __BASIC_H__
#define __BASIC_H__
#include <string>
#include "context.h"
using namespace std;

class Basic
{
protected:
	bool m_run;
	bool m_debug;
	string m_name;
	unsigned m_line;
	Context m_context;

public:
	Basic(void);

public:
	const bool GetRun(void);
	const bool GetDebug(void);
	const string& GetName(void);

public:
	void SetRun(bool b);
	void SetDebug(bool b);
	void SetName(const string&);

public:
	bool Compile(void);
	void Execute(void);
	Cache& GetCache(void);
};

#endif//__BASIC_H__
