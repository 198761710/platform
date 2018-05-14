#ifndef __TOKEN_H__
#define __TOKEN_H__
#include "xstring.h"

class Variable;
class Token
{
public:
	xstring name;
	bool bindup;
	double value;
	unsigned type;
	unsigned comid;
	unsigned keyid;
	unsigned line;
	Variable *var;
public:
	Token(void);
	Token(unsigned t, const xstring& n);
	Token(unsigned t, const xstring& c, const xstring& s, const xstring& f, const xstring& o, const string& n);
	~Token(void);
public:
	bool SetContext(class Context&);
	void SetVariable(class Variable&);
public:
	const double GetValue(void);
	const double GetOnTime(void);
	const double GetOffTime(void);
	const double GetRuntime(void);
	const unsigned GetLineNumber(void);
public:
	bool Check(void);
	bool Invalid(void);
	bool SetValue(const double&);
	void SetLineNumber(unsigned);
private:
	void TokenValue(void);
};
#endif//__TOKEN_H__
