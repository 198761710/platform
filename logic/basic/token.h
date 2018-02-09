#ifndef __TOKEN_H__
#define __TOKEN_H__
#include <string>
using namespace std;

class Variable;
class Token
{
public:
	signed type;
	double value;
	unsigned line;
	bool bindup;
	string name;
	Variable *var;
public:
	Token(void);
	Token(signed t, const string& n);
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
