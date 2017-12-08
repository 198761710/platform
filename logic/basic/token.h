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
	string name;
	Variable *var;
public:
	Token(void);
	Token(signed t, const string& n);
	~Token(void);
public:
	void SetContext(class Context&);
	void SetVariable(class Variable&);
public:
	const double Value(void);
	const double OnTime(void);
	const double OffTime(void);
	const double Runtime(void);
	const double GetValue(void);
public:
	bool SetValue(const double&);
private:
	void TokenValue(void);
};
#endif//__TOKEN_H__
