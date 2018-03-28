#include <stdio.h>
#include <string.h>
#include "basic.h"
#include "parser.h"
#include "basiccc.h"

extern int yyparse();
extern int yylex_destroy(void);
extern "C" void* yystring(const char *s);
extern "C" void* yysetlinenumber(unsigned);
extern "C" void* yysetlinestring(const char*);
extern "C" void* yysetfilename(const char*);

Basic::Basic(void):m_run(0),m_debug(0),m_line(0)
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
	GetCache().SetName(m_name);
	yysetfilename(m_name.data());
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
		m_line++;
		//data += p;
		yysetlinenumber(m_line);
		yysetlinestring(p);
		if( strlen(p) < 3 )
		{
			continue;
		}
		yystring( p );
		BasicCC::SetLineNumber(m_line);
		if( yyparse() != 0 )
		{
			fclose(fp);
			yylex_destroy();
			yysetlinenumber(0);
			yysetlinestring(0);
			return false;
		}
		yylex_destroy();
		yysetlinenumber(0);
		yysetlinestring(0);
	}
	fclose(fp);
	/*
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
	*/
	m_context.Clear();

	if( BasicCC::MakeContext( m_context ) == false )
	{
		Token &token = m_context.SymbelNotFound();
		printf("symbel '%s' not found at file '%s' line %d.\n", 
				token.name.data(), m_name.data(), token.line);
		return false;
	}
	return true;
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
Cache& Basic::GetCache(void)
{
	return m_context.GetCache();
}
