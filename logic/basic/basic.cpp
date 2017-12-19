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
const bool Basic::GetRun(void)
{
	return m_run;
}
const bool Basic::GetDebug(void)
{
	return m_debug;
}
const string& Basic::GetName(void)
{
	return m_name;
}
void Basic::SetRun(bool b)
{
	m_run = b;
}
void Basic::SetDebug(bool b)
{
	m_debug = b;
}
void Basic::SetName(const string& n)
{
	m_name = n;
}
bool Basic::Compile(void)
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
void Basic::Execute(void)
{
	if( false == m_run )
	{
		return;
	}
	//if( m_context.Check() )
	{
		m_context.Execute();
	}
}
void Basic::Show(void)
{
	m_context.GetLocalVariable().Show();
}
