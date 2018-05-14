#ifndef __XSTRING_H__
#define __XSTRING_H__
#include <time.h>
#include <string>
using namespace std;

#define BUFFER_SIZE (32 * 1024)

class xstring : public string
{
public:
    xstring(void);
    xstring(const string&);
    xstring(const xstring&);
	xstring(const char*,...);
public:
	const char* trim(void)const;
	const int toint(void) const;
    const bool tobool(void) const;
	const float tofloat(void) const;
	const double todouble(void) const;
    const time_t totime(const char*) const;
	const xstring& format(const char*,...);
	const xstring& tformat(const char*, const time_t);
	const int scanf(const char*, ...);
public:
    xstring& operator=(const xstring& xs);
	string& operator()(void);
};

#endif//__XSTRING_H__
