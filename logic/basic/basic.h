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
	Context m_context;

public:
	Basic(void);

public:
	const bool run(void);
	const bool debug(void);
	const string& name(void);

public:
	void run(bool b);
	void debug(bool b);
	void name(const string&);

public:
	bool load(void);
	void execute(void);
	void show(void);
};

#endif//__BASIC_H__
