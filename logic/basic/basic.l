%{
#include <list>
#include <string>
#include <cstring>
#include "parser.h"
extern char *yytext;
extern "C" int yylex(void);
extern "C" int yywrap(void);
extern "C" void* yystring(const char *s);
#define CopyText() strcpy(yylval.t, yytext)
%}

DEF			DEF
DI			(DI)|(di)
DO			(DO)|(do)
DV			(DV)|(dv)
AI			(AI)|(ai)
AO			(AO)|(ao)
AV			(AV)|(av)
LC			[a-z]
LCO			{LC}\.ontime(\(\))?
LCF			{LC}\.offtime(\(\))?
LCBT		{LC}\.bit(([1-2]?[0-9])|(3[0-1]))
LCMK		{LC}\.make
ID			[a-z_A-Z][a-z_A-Z0-9]{1,31}
IDBT		{ID}\.bit(([1-2]?[0-9])|(3[0-1]))
IDRT		{ID}\.runtime(\(\))?
IDOT		{ID}\.ontime(\(\))?
IDFT		{ID}\.offtime(\(\))?
IDVL		{ID}\.invalid(\(\))?
IDMK		{ID}\.make
NUM			([0-9]+(\.[0-9]+)?)|(0x[0-9a-fA-F]{1,16})
YEAR		[0-9]{4,4}
MONTH		(0[0-9])|(1[0-2])
DAY			(0[1-9])|([1-2][0-9])|(3[0-1])
HOUR		([0-1]?[0-9])|([2][0-3])
MINUTE		([0-5]?[0-9])
SECONND		([0-5]?[0-9])
TIME		{HOUR}:{MINUTE}:{SECONND}
DATE		{YEAR}\.{MONTH}\.{DAY}
DATETIME	({DATE}\ {TIME})|({DATE})|({TIME})
LABEL		{ID}[:]

%%

<INITIAL>"if"		{CopyText(); return IF;}
<INITIAL>"then"		{CopyText(); return THEN;}
<INITIAL>"else"		{CopyText(); return ELSE;}
<INITIAL>"goto"		{CopyText(); return GOTO;}
<INITIAL>"DEF" 		{CopyText(); return DEF;}
<INITIAL>"and"		{CopyText(); return AND;}
<INITIAL>"or"		{CopyText(); return OR;}
<INITIAL>"not"		{CopyText(); return NOT;}
<INITIAL>"&&"		{CopyText(); return AND;}
<INITIAL>"||"		{CopyText(); return OR;}
<INITIAL>"!"		{CopyText(); return NOT;}
<INITIAL>">"		{CopyText(); return GT;}
<INITIAL>"<"		{CopyText(); return LT;}
<INITIAL>">="		{CopyText(); return GE;}
<INITIAL>"<="		{CopyText(); return LE;}
<INITIAL>"=="		{CopyText(); return EQ;}
<INITIAL>"!="		{CopyText(); return NE;}
<INITIAL>"+"		{CopyText(); return ADD;}
<INITIAL>"-"		{CopyText(); return MIN;}
<INITIAL>"*"		{CopyText(); return MUL;}
<INITIAL>"/"		{CopyText(); return DIV;}
<INITIAL>"%"		{CopyText(); return MOD;}
<INITIAL>"="		{CopyText(); return SET;}
<INITIAL>"("		{CopyText(); return LP;}
<INITIAL>")"		{CopyText(); return RP;}
<INITIAL>"{"		{CopyText(); return LB;}
<INITIAL>"}"		{CopyText(); return RB;}
<INITIAL>","		{CopyText(); return CM;}
<INITIAL>{DI}		{CopyText(); return DI;}
<INITIAL>{DO}		{CopyText(); return DO;}
<INITIAL>{DV}		{CopyText(); return DV;}
<INITIAL>{AI}		{CopyText(); return AI;}
<INITIAL>{AO}		{CopyText(); return AO;}
<INITIAL>{AV}		{CopyText(); return AV;}
<INITIAL>{ID}		{CopyText(); return ID;}
<INITIAL>{LC}		{CopyText(); return LC;}
<INITIAL>{LCO}		{CopyText(); return LCO;}
<INITIAL>{LCF}		{CopyText(); return LCF;}
<INITIAL>{NUM}		{CopyText(); return NUM;}
<INITIAL>{TIME}		{CopyText(); return TIME;}
<INITIAL>{DATE}		{CopyText(); return DATE;}
<INITIAL>{DATETIME}	{CopyText(); return DATETIME;}
<INITIAL>{LABEL}	{CopyText(); return LABEL;}
<INITIAL>{IDRT}		{CopyText(); return IDR;}
<INITIAL>{IDOT}		{CopyText(); return IDO;}
<INITIAL>{IDFT}		{CopyText(); return IDF;}
<INITIAL>{IDVL}		{CopyText(); return IDV;}
<INITIAL>"\n"		{}
<INITIAL>.			{}

%%

int yywrap(void)
{
	return 1;
}
void* yystring(const char *s)
{
	return (void*)yy_scan_string(s);
}

#ifdef TEST_LEXER
int main(int argc, char **argv)
{
	yylex();
	return 0;
}
#endif//TEST_LEXER
