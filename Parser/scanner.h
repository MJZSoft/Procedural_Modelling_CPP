/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_SCANNER_H_INCLUDED
# define YY_YY_SCANNER_H_INCLUDED
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
    START = 258,
    END = 259,
    ENDL = 260,
    ARROW = 261,
    TRANSLATION = 262,
    SIZEV = 263,
    INSTANCE = 264,
    COLOR = 265,
    CUBE = 266,
    CYLINDER = 267,
    QUAD = 268,
    SPHERE = 269,
    PYRAMID = 270,
    CONE = 271,
    TRIANGLE = 272,
    CIRCLE = 273,
    EMPTY = 274,
    ROTATEX = 275,
    ROTATEY = 276,
    ROTATEZ = 277,
    SUBDIV = 278,
    REPEATE = 279,
    COMP = 280,
    NEGATIVE = 281,
    X = 282,
    Y = 283,
    Z = 284,
    XY = 285,
    XZ = 286,
    YZ = 287,
    XYZ = 288,
    TOP = 289,
    BOTTOM = 290,
    LEFT = 291,
    RIGHT = 292,
    FRONT = 293,
    BACK = 294,
    ALL = 295,
    INTF = 296,
    FLOATF = 297,
    SHAPE = 298,
    INTR = 299,
    FLOATR = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 87 "scanner.y" /* yacc.c:1909  */

	int   ival;
	float fval;
	char* sval;
	int   ivalr;
	float fvalr;

#line 108 "scanner.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SCANNER_H_INCLUDED  */
