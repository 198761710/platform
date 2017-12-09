#include <stdio.h>
#include "basic.h"
#include "parser.h"
#include "basiccc.h"

extern int yyparse();
extern int yylex_destroy(void);
extern "C" void* yystring(const char *s);

Basic::Basic(void):m_run(0),m_debug(0)
{
}
const bool Basic::run(void)
{
	return m_run;
}
const bool Basic::debug(void)
{
	return m_debug;
}
const string& Basic::name(void)
{
	return m_name;
}
void Basic::run(bool b)
{
	m_run = b;
}
void Basic::debug(bool b)
{
	m_debug = b;
}
void Basic::name(const string& n)
{
	m_name = n;
}
bool Basic::load(void)
{
	string data;
	char *p = 0;
	char buf[1024] = {0};
	FILE *fp = fopen(m_name.data(), "r");

	if( NULL == fp )
	{
		return false;
	}
	while( p = fgets(buf, sizeof(buf), fp) )
	{
		data += p;
	}
	fclose(fp);
	if( data.empty() )
	{
		return false;
	}
	yystring( data.data() );
	if( yyparse() != 0 )
	{
		yylex_destroy();
		return false;
	}
	yylex_destroy();
	m_context.Clear();

	return BasicCC::MakeContext( m_context );
}
void Basic::execute(void)
{
	if( false == m_run )
	{
		return;
	}
	if( m_context.Check() )
	{
		m_context.Execute();
	}
}
void Basic::show(void)
{
	m_context.GetLocalVariable().Show();
}
