%{
#include <string>
#include "scanner.h"
using namespace std;
#define YY_DECL extern "C" int yylex()
int line_num = 1;
%}
%option noyywrap
%option never-interactive
%option outfile="lexer.cpp" 
%%
[ \t]          			{/*Detect white spaces and ignore them*/}

\/\/.*					{/*Detect single line comments and ignore them*/}

ArezooParser       		{ return START; }

end            			{ return END; }

T 						{return TRANSLATION;}

S 						{return SIZEV;}

I 						{return INSTANCE;}

C 						{return COLOR;}

'cylinder'				{return CYLINDER;}
"cylinder"				{return CYLINDER;}

'cube'					{return CUBE;}
"cube"					{return CUBE;}

'quad'					{return QUAD;}
"quad"					{return QUAD;}

'sphere'				{return SPHERE;}
"sphere"				{return SPHERE;}

'pyramid'				{return PYRAMID;}
"pyramid"				{return PYRAMID;}

'cone'					{return CONE;}
"cone"					{return CONE;}

'triangle'				{return TRIANGLE;}
"triangle"				{return TRIANGLE;}

'circle'				{return CIRCLE;}
"circle"				{return CIRCLE;}

'empty'					{return EMPTY;}
"empty"					{return EMPTY;}

Rx						{return ROTATEX;}

Ry						{return ROTATEY;}

Rz						{return ROTATEZ;}

Subdiv					{return SUBDIV;}

Repeat 					{return REPEATE;}

Comp					{return COMP;}

'top'					{return TOP;}
"top"					{return TOP;}

'bottom'				{return BOTTOM;}
"bottom"				{return BOTTOM;}

'left'					{return LEFT;}
"left"					{return LEFT;}

'right'					{return RIGHT;}
"right"					{return RIGHT;}

'front'					{return FRONT;}
"front"					{return FRONT;}

'back'					{return BACK;}
"back"					{return BACK;}

'all'					{return ALL;}
"all"					{return ALL;}

'X'						{return X;}
"X"						{return X;}

'Y'						{return Y;}
"Y"						{return Y;}

'Z'						{return Z;}
"Z"						{return Z;}

'XY'					{return XY;}
"XY"					{return XY;}
'YX'					{return XY;}
"YX"					{return XY;}

'XZ'					{return XZ;}
"XZ"					{return XZ;}
'ZX'					{return XZ;}
"ZX"					{return XZ;}

'YZ'					{return YZ;}
"YZ"					{return YZ;}
'ZY'					{return YZ;}
"ZY"					{return YZ;}

'XYZ'					{return XYZ;}
"XYZ"					{return XYZ;}
'XZY'					{return XYZ;}
"XZY"					{return XYZ;}

'YXZ'					{return XYZ;}
"YXZ"					{return XYZ;}
'YZX'					{return XYZ;}
"YZX"					{return XYZ;}

'ZXY'					{return XYZ;}
"ZXY"					{return XYZ;}
'ZYX'					{return XYZ;}
"ZYX"					{return XYZ;}

[0-9]+\.[0-9]+r 		{ string str = yytext; int end = str.size()-1; yylval.fvalr = (float) atof(str.substr(0,end).c_str()); return FLOATR; }

[0-9]+r         		{ string str = yytext; int end = str.size()-1; yylval.ivalr = atoi(str.substr(0,end).c_str()); return INTR; }

[0-9]+\.[0-9]+ 			{ yylval.fval = (float) atof(yytext); return FLOATF; }

[0-9]+         			{ yylval.ival = atoi(yytext); return INTF; }

[a-zA-Z_][a-zA-Z0-9_]*	{ yylval.sval = strdup(yytext);	return SHAPE; }

[\(\)\{\}:,;|]	    	{ return yytext[0]; }

->						{return ARROW;}

- 						{return NEGATIVE;}

\n         				{ ++line_num; return ENDL;}

.              			;
%%
