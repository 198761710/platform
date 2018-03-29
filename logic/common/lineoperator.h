#ifndef __LINE_OPERATOR_H__
#define __LINE_OPERATOR_H__
#include <string>
using namespace std;
#define LINE_BUF_SIZE  8192

class LineOperator
{
protected:
	string data;
public:
	LineOperator(void);
	LineOperator(const string&);
public:
	LineOperator& Add(const int);
	LineOperator& Add(const double);
	LineOperator& Add(const string&);
	LineOperator& Set(const string&);
	const string& Get(void)const;
public:
	const string& Trim(void);
	const string& Make(void);
public:
	const string&  Make(const char*,...);
	const int Scan(const char*,...);
public:
	const bool Check(void);
};

#endif//__LINE_OPERATOR_H__
