/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DI = 258,
    DO = 259,
    DV = 260,
    AI = 261,
    AO = 262,
    AV = 263,
    LC = 264,
    LCO = 265,
    LCF = 266,
    LCB = 267,
    LCM = 268,
    ID = 269,
    IDR = 270,
    IDO = 271,
    IDF = 272,
    IDV = 273,
    IDB = 274,
    IDM = 275,
    NUM = 276,
    DATE = 277,
    TIME = 278,
    DATETIME = 279,
    IF = 280,
    THEN = 281,
    ELSE = 282,
    AND = 283,
    OR = 284,
    NOT = 285,
    EQ = 286,
    NE = 287,
    GE = 288,
    LE = 289,
    GT = 290,
    LT = 291,
    ADD = 292,
    MIN = 293,
    MUL = 294,
    DIV = 295,
    MOD = 296,
    LP = 297,
    RP = 298,
    LB = 299,
    RB = 300,
    CM = 301,
    SET = 302,
    GOTO = 303,
    LABEL = 304,
    DEF = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 18 "basic.y" /* yacc.c:1909  */

	struct
	{
		double v;
		char t[128];
	};

#line 113 "parser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
