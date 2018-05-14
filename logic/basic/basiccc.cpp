#include <math.h>
#include <stdio.h>
#include "token.h"
#include "parser.h"
#include "basiccc.h"
#include "cache.h"

extern Cache GlobalVariable;
TokenLmap BasicCC::tokenlmap;
TokenList BasicCC::tokenlist;
unsigned BasicCC::linenumber = 0;

void BasicCC::SetLineNumber(unsigned line)
{
	linenumber = line;
}
void BasicCC::AddToken(const Token& node)
{
	switch( node.type )
	{
		case DI:
			GlobalVariable.Define(node, AB_Binary, IO_Input);
			return;
		case DO:
			GlobalVariable.Define(node, AB_Binary, IO_Output);
			return;
		case DV:
			GlobalVariable.Define(node, AB_Binary, IO_Holding);
			return;
		case AI:
			GlobalVariable.Define(node, AB_Analog, IO_Input);
			return;
		case AO:
			GlobalVariable.Define(node, AB_Analog, IO_Output);
			return;
		case AV:
			GlobalVariable.Define(node, AB_Analog, IO_Holding);
			return;
	}
	tokenlist.push_back(node);
	tokenlist.back().SetLineNumber(linenumber);
}
void BasicCC::AddList(void)
{
	static int i = 0;
	if( tokenlmap.empty() )
	{
		i = 0;
	}
	tokenlmap[i++] = tokenlist;
	tokenlist.clear();
}
void BasicCC::ShowList(void)
{
	while( tokenlist.end() != tokenlist.begin() )
	{
		Token &node = tokenlist.back();
		printf("%s\n", node.name.data());
		tokenlist.pop_back();
	}
}
bool BasicCC::MakeContext(Context& context)
{
	int linecout = tokenlmap.size();

	if( linecout < 1 )
	{
		return false;
	}
	for(int i = 0; i < linecout; i++)
	{
		Statement statement;
		tokenlist = tokenlmap[i];
		while( !tokenlist.empty() )
		{
			Expression expression;
			expression.CreateTree(tokenlist);
			statement.AddExpression(expression);
			if( statement.SetContext(context) == false )
			{
				return false;
			}
		}
		context.AddStatement(statement);
	}
	tokenlist.clear();
	tokenlmap.clear();

	return true;
}
