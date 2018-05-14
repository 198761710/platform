#include <math.h>
#include <stdlib.h>
#include <strings.h>
#include "token.h"
#include "parser.h"
#include "cache.h"
#include "context.h"
#include "variable.h"

extern Cache GlobalVariable;

Token::Token(void)
:type(-1)
,var(0x0)
,line(0x0)
,value(0.0)
,bindup(false)
,comid(0x000000)
,keyid(0x000000)
{
	name = "unknow-token";
}
Token::Token(unsigned t, const xstring& n)
:name(n)
,type(t)
,var(0x0)
,line(0x0)
,value(0.0)
,bindup(false)
,comid(0x000000)
,keyid(0x000000)
{
	TokenValue();
}
Token::Token(unsigned t, const xstring& c, const xstring& s, const xstring& f, const xstring& o, const string& n)
:name(n)
,type(t)
,var(0x0)
,line(0x0)
,value(0.0)
,bindup(false)
,comid(c.toint())
,keyid(0x00000000)
{
	uint8_t slave = s.toint();
	uint8_t fcode = f.toint();
	uint16_t offset = o.toint();

	keyid = (((unsigned)slave) << 24)
		  | (((unsigned)fcode) << 16)
		  | (((unsigned)offset) << 0);
	TokenValue();
}
Token::~Token(void)
{

	//GlobalVariable.DelTokon(*this);
	var = NULL;
}
bool Token::SetContext(Context& context)
{
	switch(type)
	{
	case ID:
		GlobalVariable.SetTokenFind(*this);
		break;
	case IDR:
	case IDO:
	case IDF:
	case IDV:
		name[name.find_first_of(".")] = 0;
		name = name.data();
		GlobalVariable.SetTokenFind(*this);
		break;
	case LC:
		context.GetCache().SetTokenForce(*this);
		break;
	case LCO:
	case LCF:
		name[name.find_first_of(".")] = 0;
		name = name.data();
		context.GetCache().SetTokenForce(*this);
		break;
	default:
		bindup = true;
	}
	if( false == bindup )
	{
		context.SymbelNotFound(*this);
	}
	return bindup;
}
void Token::SetVariable(Variable& variable)
{
	var = &variable;
	bindup = true;
}
const double Token::GetValue(void)
{
	switch(type)
	{
	case NUM:
	case TIME:
	case DATE:
	case DATETIME:
		return value;
	case LCO:
	case LCF:
	case IDO:
	case IDF:
	case IDR:
		string idname;
		for(const char *p = name.data(); p && *p; p++)
		{
			if( '.' == *p )
				break;
			idname += *p;
		}
		name = idname;
	}
	if( var )
	{
		return var->GetValueI();
	}
	return value;
}
bool Token::Check(void)
{
	if( NULL == var )
	{
		return true;
	}
	return var->GetInit();
}
bool Token::Invalid(void)
{
	if( NULL == var )
	{
		return false;
	}
	return (var->GetInit() == false);
}
bool Token::SetValue(const double& v)
{
	if( var )
	{
		var->SetValue((double&)v);
		return true;
	}
	return false;
}
void Token::SetLineNumber(unsigned l)
{
	line = l;
}
const unsigned Token::GetLineNumber(void)
{
	return line;
}
const double Token::GetRuntime(void)
{
	if( var )
	{
		return var->GetRuntime();
	}
	return double(0.0000);
}
const double Token::GetOnTime(void)
{
	if( var )
	{
		return var->GetOnTime();
	}
	return double(0.0000);
}
const double Token::GetOffTime(void)
{
	if( var )
	{
		return var->GetOffTime();
	}
	return double(0.0000);
}
void Token::TokenValue(void)
{
	if( name.empty() )
	{
		return;
	}
	switch(type)
	{
	case NUM:
	{
		int base = strncasecmp(name.data(), "0x", 0x2);
		value = strtol(name.data(), 0, !base ? 16 : 10);
		break;
	}
	case TIME:
	{
		struct tm t = {0,0,0,0,0,0,0,0,0,0,0};
		strptime(name.data(), "%H:%M:%S", &t);
		value = (t.tm_hour * 60 * 60);
		value += (t.tm_min * 60);
		value += (t.tm_sec);
	}
	break;
	case DATE:
	{
		struct tm t = {0,0,0,0,0,0,0,0,0,0,0};
		strptime(name.data(), "%Y-%m:%d", &t);
		value = mktime(&t);
	}
	break;
	case DATETIME:
	{
		struct tm t = {0,0,0,0,0,0,0,0,0,0,0};
		strptime(name.data(), "%Y-%m:%d %H:%M:%S", &t);
		value = mktime(&t);
	}
	break;
	}
}
