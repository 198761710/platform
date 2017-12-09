#include <math.h>
#include <stdio.h>
#include "token.h"
#include "parser.h"
#include "basiccc.h"
#include "cache.h"

extern Cache GlobalVariable;
TokenLmap BasicCC::tokenlmap;
TokenList BasicCC::tokenlist;

void BasicCC::AddToken(const Token& node)
{
	switch( node.type )
	{
		case DI:
			GlobalVariable.SetDefine(node.name, Binary, VarInput);
			return;
		case DO:
			GlobalVariable.SetDefine(node.name, Binary, VarOutput);
			return;
		case DV:
			GlobalVariable.SetDefine(node.name, Binary, VarValue);
			return;
		case AI:
			GlobalVariable.SetDefine(node.name, Analog, VarInput);
			return;
		case AO:
			GlobalVariable.SetDefine(node.name, Analog, VarOutput);
			return;
		case AV:
			GlobalVariable.SetDefine(node.name, Analog, VarValue);
			return;
	}
	tokenlist.push_back(node);
}
void BasicCC::AddList(void)
{
	static int i = 0;
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
			statement.SetContext(context);
		}
		context.AddStatement(statement);
	}
	tokenlist.clear();
	tokenlmap.clear();

	return true;
}
