/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DI = 258,
     DO = 259,
     DV = 260,
     AI = 261,
     AO = 262,
     AV = 263,
     ID = 264,
     IDR = 265,
     IDO = 266,
     IDF = 267,
     IDV = 268,
     LC = 269,
     LCO = 270,
     LCF = 271,
     NUM = 272,
     HEX = 273,
     DATE = 274,
     TIME = 275,
     DATETIME = 276,
     IF = 277,
     THEN = 278,
     ELSE = 279,
     AND = 280,
     OR = 281,
     NOT = 282,
     EQ = 283,
     NE = 284,
     GE = 285,
     LE = 286,
     GT = 287,
     LT = 288,
     ADD = 289,
     MIN = 290,
     MUL = 291,
     DIV = 292,
     MOD = 293,
     LP = 294,
     RP = 295,
     LB = 296,
     RB = 297,
     CM = 298,
     SET = 299,
     GOTO = 300,
     LABEL = 301
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 11 "basic.y"

	struct
	{
		double v;
		char t[128];
	};



/* Line 2068 of yacc.c  */
#line 106 "parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


