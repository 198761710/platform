#ifndef __STATEMENT_H__
#define __STATEMENT_H__
#include <list>
#include "context.h"
#include "expression.h"
using namespace std;


class Expression;
class Statement
{
protected:
	int expression_count;
	list<Expression> statement;
	typedef list<Expression>::iterator Iterator;
public:
	Statement(void):expression_count(0){}
public:
	unsigned GetLineNumber(void);
	bool SetContext(Context& context);
	void AddExpression(Expression& expression);
	void Execute(void);
	bool Check(void);
public:
	Statement& operator=(Statement&);
};

#endif//__STATEMENT_H__
