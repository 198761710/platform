#include <math.h>
#include "parser.h"
#include "context.h"
#include "expression.h"
#include "statement.h"


unsigned Statement::GetLineNumber(void)
{
	if( statement.begin() == statement.end() )
	{
		return unsigned(0);
	}
	return statement.front().GetLineNumber();
}
bool Statement::SetContext(Context& context)
{
	if( statement.empty() )
	{
		return false;
	}
	Expression& expression = statement.front();
	if( expression.GetType() == LABEL )
	{
		context.AddLabel(expression.GetName());
	}
	for(Iterator i = statement.begin(); i != statement.end(); i++)
	{
		if( i->SetContext(context) == false )
		{
			return false;
		}
	}
	return true;
}
void Statement::AddExpression(Expression& expression)
{
	statement.push_back(expression);
	expression_count++;
}
void Statement::Execute(void)
{
	switch(expression_count)
	{
		case 1:
			statement.back().Execute();
			break;
		case 2:
			if( fabs(statement.back().Execute()) > 0.9999 )
			{
				statement.front().Execute();
			}
			break;
		case 3:
			if( fabs(statement.back().Execute()) > 0.9999 )
			{
				Iterator i = statement.begin();
				i++;i->Execute();
			}
			else
			{
				statement.front().Execute();
			}
			break;
	}
}
bool Statement::Check(void)
{
	for(Iterator i = statement.begin(); i != statement.end(); i++)
	{
		if( i->Check() == false )
		{
			return false;
		}
	}
	return true;
}
Statement& Statement::operator=(Statement& s)
{
	statement = s.statement;
	expression_count = s.expression_count;
}
