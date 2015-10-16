%{
#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
using namespace std;

string to_string(int number){
    std::ostringstream buff;
    buff<<number;
    return buff.str();   
}
string to_string(float number){
    std::ostringstream buff;
    buff<<number;
    return buff.str();   
}
string to_string(double number){
    std::ostringstream buff;
    buff<<number;
    return buff.str();   
}

// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE* yyin; 
extern int line_num;
void yyerror(const char *s);
// general variables
float tx,ty,tz,sx,sy,sz,rx,ry,rz,number,pr,cr,cg,cb;
bool negative = false;
vector<string> successorsV;

string typeOfShape;
vector<string> scopeRuleV;


string axisName;
vector<string> sectionSizes; 
vector<string> sectionNames;
vector<string> splitRuleV;

string repeatWidth;
string shapeName;
vector<string> repeatRuleV;

string faceName;
vector<string> compRuleV;



vector<string> parsingResults; // final tokens will be store here.

void transFerTempVectorToFinalVector(vector<string> v){
	int size = v.size();
	for(int i=0;i<size;i++)
		if(v[i].size()>0) 
		{
			//because it is not possible to resize a vectore downward it maybe happen that 
		    //have some empty elements at the end of the verctore, thus we need to check the elements.
			parsingResults.push_back(v[i]);
		}
}

void transferToSuccessor(vector<string> v)
{
	int i = successorsV.size();
	int s= v.size();
	successorsV.resize(i+s);
	for(int j=0;j<s;j++)
		successorsV[i++] = v[j];
}

%}


%output  "scanner.cpp"
%defines "scanner.h"

// Bison fundamentally works by asking flex to get the next token, which it
// returns as an object of type "yystype".  But tokens could be of any
// arbitrary data type!  So we deal with that in Bison by defining a C union
// holding each of the types of tokens that Flex could return, and have Bison
// use that union instead of "int" for the definition of "yystype":
%union {
	int   ival;
	float fval;
	char* sval;
	int   ivalr;
	float fvalr;
}

// define the constant-string tokens:
// token for begin of file
%token START 
%token END 
%token ENDL
%token ARROW
%token TRANSLATION
%token SIZEV
%token INSTANCE
%token COLOR
%token CUBE
%token CYLINDER
%token QUAD
%token SPHERE
%token PYRAMID
%token CONE
%token TRIANGLE
%token CIRCLE
%token EMPTY
%token ROTATEX
%token ROTATEY
%token ROTATEZ
%token SUBDIV
%token REPEATE
%token COMP
%token NEGATIVE
%token X
%token Y
%token Z
%token XY
%token XZ
%token YZ
%token XYZ
%token TOP
%token BOTTOM
%token LEFT
%token RIGHT
%token FRONT
%token BACK
%token ALL


// define the "terminal symbol" token types I'm going to use (in CAPS
// by convention), and associate each with a field of the union:
%token <ival> INTF
%token <fval> FLOATF
%token <sval> SHAPE
%token <ivalr> INTR
%token <fvalr> FLOATR

%%
// the first rule defined is the highest-level rule, which in our
// case is just the concept of a whole "input file":
input:
	header body_section footer {  parsingResults.push_back("END"); }
	;

header:
	START FLOATF ENDLS { parsingResults.push_back("BEGIN"); }
	;

body_section:
	body_lines
	;

body_lines:
	body_lines body_line
	| body_line
	;
body_line:
	INTF ':' SHAPE ARROW successor ';' ENDLS
	{ 
		parsingResults.push_back("ID");
		parsingResults.push_back("(");
		parsingResults.push_back(to_string($1));
		parsingResults.push_back(")");
		parsingResults.push_back(":");
		parsingResults.push_back("SHAPE");
		parsingResults.push_back("(");
		string str_name = $3;
		parsingResults.push_back(str_name);
		parsingResults.push_back(")");
		parsingResults.push_back("ARROW"); 
		transFerTempVectorToFinalVector(successorsV);
		parsingResults.push_back("ENDR");
		successorsV.clear();
	}
	;
	
successor:
	rules
	;
rules: rules rule
	| rule 
	;

rule: 
	split_rule 
	  {
	  		splitRuleV.clear();
			splitRuleV.resize(14);
			int i = 0;
			splitRuleV.at(i++) = "#";
			if(tx!=0 || ty!=0 || tz!=0)
			{
				int size = splitRuleV.size();
				splitRuleV.resize(size+8);
				splitRuleV.at(i++) = "TRANSLATE";
				splitRuleV.at(i++) = "(";
				splitRuleV.at(i++) = to_string(tx);
				splitRuleV.at(i++) = ",";
				splitRuleV.at(i++) = to_string(ty);
				splitRuleV.at(i++) = ",";
				splitRuleV.at(i++) = to_string(tz);
				splitRuleV.at(i++) = ")";
			}
			if(sx!=-1 && sy!=-1 && sz!=-1)
			{
				int size = splitRuleV.size();
				splitRuleV.resize(size+8);
				splitRuleV.at(i++) = "SIZEV";
				splitRuleV.at(i++) = "(";
				splitRuleV.at(i++) = to_string(sx);
				splitRuleV.at(i++) = ",";
				splitRuleV.at(i++) = to_string(sy);
				splitRuleV.at(i++) = ",";
				splitRuleV.at(i++) = to_string(sz);
				splitRuleV.at(i++) = ")";
			}
			if(cr>=0 && cg>=0 && cb>=0)
			{
				int size = splitRuleV.size();
				splitRuleV.resize(size+8);
				splitRuleV.at(i++) = "COLOR";
				splitRuleV.at(i++) = "(";
				splitRuleV.at(i++) = to_string(cr);
				splitRuleV.at(i++) = ",";
				splitRuleV.at(i++) = to_string(cg);
				splitRuleV.at(i++) = ",";
				splitRuleV.at(i++) = to_string(cb);
				splitRuleV.at(i++) = ")";
			}
			if(rx!=0)
			{
				int size = splitRuleV.size();
				splitRuleV.resize(size+4);
				splitRuleV.at(i++) = "ROTATEX";
				splitRuleV.at(i++) = "(";
				splitRuleV.at(i++) = to_string(rx);
				splitRuleV.at(i++) = ")";
			}
			if(ry!=0)
			{
				int size = splitRuleV.size();
				splitRuleV.resize(size+4);
				splitRuleV.at(i++) = "ROTATEY";
				splitRuleV.at(i++) = "(";
				splitRuleV.at(i++) = to_string(ry);
				splitRuleV.at(i++) = ")";
			}
			if(rz!=0)
			{
				int size = splitRuleV.size();
				splitRuleV.resize(size+4);
				splitRuleV.at(i++) = "ROTATEZ";
				splitRuleV.at(i++) = "(";
				splitRuleV.at(i++) = to_string(rz);
				splitRuleV.at(i++) = ")";
			}
			splitRuleV.at(i++) = "SUBDIV";
			splitRuleV.at(i++) = "(";
			splitRuleV.at(i++) = axisName;
			splitRuleV.at(i++) = ",";
			//insert sizes
			splitRuleV.at(i++) = "SIZES";
			splitRuleV.at(i++) = "(";
			int size = splitRuleV.size();
			int size1= sectionSizes.size();
			splitRuleV.resize(size+(size1-1)*2);
			bool flag = false;
			for(int j=0;j<size1-1;j++)
			{
				splitRuleV.at(i++) = sectionSizes[j];
				if(sectionSizes[j].compare("RELATIVE")==0)
					flag = true;
				else if(flag != true)
					splitRuleV.at(i++) = ",";
				else if (flag && sectionSizes[j].compare(")")==0)
				{
					flag = false;
					splitRuleV.at(i++) = ",";
				}
			}
			splitRuleV.at(i++) = sectionSizes[size1-1];
			sectionSizes.clear();
			splitRuleV.at(i++) = ")";
			// end of inserting
			splitRuleV.at(i++) = ")";
			splitRuleV.at(i++) = "{";
			//insert names
			size = splitRuleV.size();
			int size2= sectionNames.size();
			splitRuleV.resize(size+(size2-1)*2);
			for(int j=0;j<size2-1;j++)
			{
				splitRuleV.at(i++) = sectionNames[j];
				splitRuleV.at(i++) = "|";
			}
			splitRuleV.at(i++) = sectionNames[size2-1];
			sectionNames.clear();
			// end of inserting
			splitRuleV.at(i++) = "}";
			if(pr!=-1)
			{
				int size = splitRuleV.size();
				splitRuleV.resize(size+4);
				splitRuleV.at(i++) = "PROBABILITY";
				splitRuleV.at(i++) = "(";
				splitRuleV.at(i++) = to_string(pr);
				splitRuleV.at(i++) = ")";
			}
			splitRuleV.at(i++) = "$";
			transferToSuccessor(splitRuleV);
	  }
	| repeat_rule
		{
	  		repeatRuleV.clear();
			repeatRuleV.resize(14);
			int i = 0;
			repeatRuleV.at(i++) = "#";
			if(tx!=0 || ty!=0 || tz!=0)
			{
				int size = repeatRuleV.size();
				repeatRuleV.resize(size+8);
				repeatRuleV.at(i++) = "TRANSLATE";
				repeatRuleV.at(i++) = "(";
				repeatRuleV.at(i++) = to_string(tx);
				repeatRuleV.at(i++) = ",";
				repeatRuleV.at(i++) = to_string(ty);
				repeatRuleV.at(i++) = ",";
				repeatRuleV.at(i++) = to_string(tz);
				repeatRuleV.at(i++) = ")";
			}
			if(sx!=-1 && sy!=-1 && sz!=-1)
			{
				int size = repeatRuleV.size();
				repeatRuleV.resize(size+8);
				repeatRuleV.at(i++) = "SIZEV";
				repeatRuleV.at(i++) = "(";
				repeatRuleV.at(i++) = to_string(sx);
				repeatRuleV.at(i++) = ",";
				repeatRuleV.at(i++) = to_string(sy);
				repeatRuleV.at(i++) = ",";
				repeatRuleV.at(i++) = to_string(sz);
				repeatRuleV.at(i++) = ")";
			}
			if(cr>=0 && cg>=0 && cb>=0)
			{
				int size = repeatRuleV.size();
				repeatRuleV.resize(size+8);
				repeatRuleV.at(i++) = "COLOR";
				repeatRuleV.at(i++) = "(";
				repeatRuleV.at(i++) = to_string(cr);
				repeatRuleV.at(i++) = ",";
				repeatRuleV.at(i++) = to_string(cg);
				repeatRuleV.at(i++) = ",";
				repeatRuleV.at(i++) = to_string(cb);
				repeatRuleV.at(i++) = ")";
			}
			if(rx!=0)
			{
				int size = repeatRuleV.size();
				repeatRuleV.resize(size+4);
				repeatRuleV.at(i++) = "ROTATEX";
				repeatRuleV.at(i++) = "(";
				repeatRuleV.at(i++) = to_string(rx);
				repeatRuleV.at(i++) = ")";
			}
			if(ry!=0)
			{
				int size = repeatRuleV.size();
				repeatRuleV.resize(size+4);
				repeatRuleV.at(i++) = "ROTATEY";
				repeatRuleV.at(i++) = "(";
				repeatRuleV.at(i++) = to_string(ry);
				repeatRuleV.at(i++) = ")";
			}
			if(rz!=0)
			{
				int size = repeatRuleV.size();
				repeatRuleV.resize(size+4);
				repeatRuleV.at(i++) = "ROTATEZ";
				repeatRuleV.at(i++) = "(";
				repeatRuleV.at(i++) = to_string(rz);
				repeatRuleV.at(i++) = ")";
			}
			repeatRuleV.at(i++) = "REPEAT";
			repeatRuleV.at(i++) = "(";
			repeatRuleV.at(i++) = axisName;
			repeatRuleV.at(i++) = ",";
			repeatRuleV.at(i++) = repeatWidth;
			repeatRuleV.at(i++) = ")";
			repeatRuleV.at(i++) = "{";
			repeatRuleV.at(i++) = shapeName;
			repeatRuleV.at(i++) = "}";
			if(pr!=-1)
			{
				int size = repeatRuleV.size();
				repeatRuleV.resize(size+4);
				repeatRuleV.at(i++) = "PROBABILITY";
				repeatRuleV.at(i++) = "(";
				repeatRuleV.at(i++) = to_string(pr);
				repeatRuleV.at(i++) = ")";
			}
			repeatRuleV.at(i++) = "$";
			transferToSuccessor(repeatRuleV);
	  }
	| scope_rule 
		{
			scopeRuleV.clear();
			scopeRuleV.resize(6);
			int i = 0;
			scopeRuleV.at(i++) = "#";
			if(tx!=0 || ty!=0 || tz!=0)
			{
				int size = scopeRuleV.size();
				scopeRuleV.resize(size+8);
				scopeRuleV.at(i++) = "TRANSLATE";
				scopeRuleV.at(i++) = "(";
				scopeRuleV.at(i++) = to_string(tx);
				scopeRuleV.at(i++) = ",";
				scopeRuleV.at(i++) = to_string(ty);
				scopeRuleV.at(i++) = ",";
				scopeRuleV.at(i++) = to_string(tz);
				scopeRuleV.at(i++) = ")";
			}
			if(sx!=-1 && sy!=-1 && sz!=-1)
			{
				int size = scopeRuleV.size();
				scopeRuleV.resize(size+8);
				scopeRuleV.at(i++) = "SIZEV";
				scopeRuleV.at(i++) = "(";
				scopeRuleV.at(i++) = to_string(sx);
				scopeRuleV.at(i++) = ",";
				scopeRuleV.at(i++) = to_string(sy);
				scopeRuleV.at(i++) = ",";
				scopeRuleV.at(i++) = to_string(sz);
				scopeRuleV.at(i++) = ")";
			}
			if(cr>=0 && cg>=0 && cb>=0)
			{
				int size = scopeRuleV.size();
				scopeRuleV.resize(size+8);
				scopeRuleV.at(i++) = "COLOR";
				scopeRuleV.at(i++) = "(";
				scopeRuleV.at(i++) = to_string(cr);
				scopeRuleV.at(i++) = ",";
				scopeRuleV.at(i++) = to_string(cg);
				scopeRuleV.at(i++) = ",";
				scopeRuleV.at(i++) = to_string(cb);
				scopeRuleV.at(i++) = ")";
			}
			if(rx!=0)
			{
				int size = scopeRuleV.size();
				scopeRuleV.resize(size+4);
				scopeRuleV.at(i++) = "ROTATEX";
				scopeRuleV.at(i++) = "(";
				scopeRuleV.at(i++) = to_string(rx);
				scopeRuleV.at(i++) = ")";
			}
			if(ry!=0)
			{
				int size = scopeRuleV.size();
				scopeRuleV.resize(size+4);
				scopeRuleV.at(i++) = "ROTATEY";
				scopeRuleV.at(i++) = "(";
				scopeRuleV.at(i++) = to_string(ry);
				scopeRuleV.at(i++) = ")";
			}
			if(rz!=0)
			{
				int size = scopeRuleV.size();
				scopeRuleV.resize(size+4);
				scopeRuleV.at(i++) = "ROTATEZ";
				scopeRuleV.at(i++) = "(";
				scopeRuleV.at(i++) = to_string(rz);
				scopeRuleV.at(i++) = ")";
			}
			scopeRuleV.at(i++) = "INSTANCE";
			scopeRuleV.at(i++) = "(";
			scopeRuleV.at(i++) = typeOfShape;
			scopeRuleV.at(i++) = ")";			
			if(pr!=-1)
			{
				int size = scopeRuleV.size();
				scopeRuleV.resize(size+4);
				scopeRuleV.at(i++) = "PROBABILITY";
				scopeRuleV.at(i++) = "(";
				scopeRuleV.at(i++) = to_string(pr);
				scopeRuleV.at(i++) = ")";
			}
			scopeRuleV.at(i++) = "$";
			transferToSuccessor(scopeRuleV);
		} /* end of scope_rule action*/
	| comp_rule 
		{
			compRuleV.clear();
			compRuleV.resize(9);
			int i = 0;
			compRuleV.at(i++) = "#";
			if(tx!=0 || ty!=0 || tz!=0)
			{
				int size = compRuleV.size();
				compRuleV.resize(size+8);
				compRuleV.at(i++) = "TRANSLATE";
				compRuleV.at(i++) = "(";
				compRuleV.at(i++) = to_string(tx);
				compRuleV.at(i++) = ",";
				compRuleV.at(i++) = to_string(ty);
				compRuleV.at(i++) = ",";
				compRuleV.at(i++) = to_string(tz);
				compRuleV.at(i++) = ")";
			}
			if(sx!=-1 && sy!=-1 && sz!=-1)
			{
				int size = compRuleV.size();
				compRuleV.resize(size+8);
				compRuleV.at(i++) = "SIZEV";
				compRuleV.at(i++) = "(";
				compRuleV.at(i++) = to_string(sx);
				compRuleV.at(i++) = ",";
				compRuleV.at(i++) = to_string(sy);
				compRuleV.at(i++) = ",";
				compRuleV.at(i++) = to_string(sz);
				compRuleV.at(i++) = ")";
			}
			if(cr>=0 && cg>=0 && cb>=0)
			{
				int size = compRuleV.size();
				compRuleV.resize(size+8);
				compRuleV.at(i++) = "COLOR";
				compRuleV.at(i++) = "(";
				compRuleV.at(i++) = to_string(cr);
				compRuleV.at(i++) = ",";
				compRuleV.at(i++) = to_string(cg);
				compRuleV.at(i++) = ",";
				compRuleV.at(i++) = to_string(cb);
				compRuleV.at(i++) = ")";
			}
			if(rx!=0)
			{
				int size = compRuleV.size();
				compRuleV.resize(size+4);
				compRuleV.at(i++) = "ROTATEX";
				compRuleV.at(i++) = "(";
				compRuleV.at(i++) = to_string(rx);
				compRuleV.at(i++) = ")";
			}
			if(ry!=0)
			{
				int size = compRuleV.size();
				compRuleV.resize(size+4);
				compRuleV.at(i++) = "ROTATEY";
				compRuleV.at(i++) = "(";
				compRuleV.at(i++) = to_string(ry);
				compRuleV.at(i++) = ")";
			}
			if(rz!=0)
			{
				int size = compRuleV.size();
				compRuleV.resize(size+4);
				compRuleV.at(i++) = "ROTATEZ";
				compRuleV.at(i++) = "(";
				compRuleV.at(i++) = to_string(rz);
				compRuleV.at(i++) = ")";
			}
			compRuleV.at(i++) = "COMP";
			compRuleV.at(i++) = "(";
			compRuleV.at(i++) = faceName;
			compRuleV.at(i++) = ")";
			compRuleV.at(i++) = "{";
			compRuleV.at(i++) = shapeName;
			compRuleV.at(i++) = "}";			
			if(pr!=-1)
			{
				int size = compRuleV.size();
				compRuleV.resize(size+4);
				compRuleV.at(i++) = "PROBABILITY";
				compRuleV.at(i++) = "(";
				compRuleV.at(i++) = to_string(pr);
				compRuleV.at(i++) = ")";
			}
			compRuleV.at(i++) = "$";
			transferToSuccessor(compRuleV);
		} /* end of comp_rule action*/
	;

scope_rule: 
	translation size color rotation instance probability
	;

translation:
	TRANSLATION '(' numberTx ',' numberTy ',' numberTz ')'
	|			{tx=0; ty=0; tz=0;}
	;

size:
	SIZEV '(' numberSx ',' numberSy ',' numberSz ')'
	|			{sx=-1; sy= -1; sz=-1;}
	;

color:
	COLOR '(' numberCr ',' numberCg ',' numberCb ')'
	| 			{cr=-1; cg=-1; cb=-1;}
	;

instance:
	INSTANCE '(' type_of_shape ')'
	;

probability:
	':' numberPr
	|			{pr = -1.0;}
	;

number:
	  NEGATIVE INTF       {number = $2; negative = true;}
	| NEGATIVE FLOATF   {number = $2; negative = true;}
	| INTF       {number = $1; negative = false;}
	| FLOATF   {number = $1; negative = false;}
	;

numberr:
	  NEGATIVE INTR       {number = $2; negative = true;}
	| NEGATIVE FLOATR   {number = $2; negative = true;}
	| INTR       {number = $1; negative = false;}
	| FLOATR   {number = $1; negative = false;}
	;

numberTx:
	number 	  {tx = negative ? (-1)*number : number;}
	;
numberTy:
	number 	  {ty = negative ? (-1)*number : number;}
	;
numberTz:
	number 	  {tz = negative ? (-1)*number : number;}
	;
numberSx:
	number 	  {sx = negative ? (-1)*number : number;}
	;
numberSy:
	number 	  {sy = negative ? (-1)*number : number;}
	;
numberSz:
	number 	  {sz = negative ? (-1)*number : number;}
	;
numberPr:
	number 	  {pr = negative ? (-1)*number : number;}
	;
numberCr:
	number 	  {cr = negative ? (-1)*number : number;}
	;
numberCg:
	number 	  {cg = negative ? (-1)*number : number;}
	;
numberCb:
	number 	  {cb = negative ? (-1)*number : number;}
	;
type_of_shape: 
	CYLINDER	{typeOfShape = "CYLINDER";}
	| CUBE		{typeOfShape = "CUBE";}
	| QUAD		{typeOfShape = "QUAD";}
	| SPHERE	{typeOfShape = "SPHERE";}
	| PYRAMID	{typeOfShape = "PYRAMID";}
	| CONE 		{typeOfShape = "CONE";}
	| TRIANGLE 	{typeOfShape = "TRIANGLE";}
	| CIRCLE 	{typeOfShape = "CIRCLE";}
	| EMPTY 	{typeOfShape = "EMPTY";}
	;

rotation: 
	rotates
	;

rotates:
	 rotatex rotatey rotatez
	;

rotatex:     {rx=0;} // It has to be set to zero to check whether it has Rx or do not have. 
	| ROTATEX '(' numberRx ')'
	;

rotatey:     {ry=0;}
	| ROTATEY '(' numberRy ')'
	;

rotatez:     {rz=0;}
	| ROTATEZ '(' numberRz ')'
	;

numberRx:
	number 	  {rx = negative ? (-1)*number : number;}
	;

numberRy:
	number 	  {ry = negative ? (-1)*number : number;}
	;

numberRz:
	number 	  {rz = negative ? (-1)*number : number;}
	;

split_rule: 
    translation size color rotation subdivation probability
    ;
subdivation:
	SUBDIV '(' axis ',' split_size_section ')' '{' shape_list_section '}'
	;

repeat_rule:
	translation size color rotation repeatation probability
    ;
repeatation:
	REPEATE '(' axis ',' FLOATF ')' '{' SHAPE '}'    { repeatWidth = to_string($5); shapeName = $8; }
	;


comp_rule:
	translation size color rotation component probability
    ;
component:
	COMP '(' face ')' '{' SHAPE '}'    { shapeName = $6; }
	;

face:
	  TOP     	 {faceName="TOP";}
	| BOTTOM     {faceName="BOTTOM";}
	| LEFT		 {faceName="LEFT";}
	| RIGHT		 {faceName="RIGHT";}
	| FRONT      {faceName="FRONT";}
	| BACK 		 {faceName="BACK";}
	| ALL 		 {faceName="ALL";}
	;

axis:
	  X 	{axisName = "X";}
	| Y 	{axisName = "Y";}
	| Z 	{axisName = "Z";}
	| XY 	{axisName = "XY";}
	| XZ 	{axisName = "XZ";}
	| YZ 	{axisName = "YZ";}
	| XYZ 	{axisName = "XYZ";}
	;

split_size_section:
	section_sizes
	;

section_sizes:
	section_sizes ',' section_size
	| section_size
	;

section_size:
	  number       {string str = to_string((negative ? (-1)*number : number)); sectionSizes.push_back(str);}
	| numberr      {
						sectionSizes.push_back("RELATIVE");
						sectionSizes.push_back("(");
						string str = to_string((negative ? (-1)*number : number));
						sectionSizes.push_back(str);
						sectionSizes.push_back(")");
					}
	;


shape_list_section:
	shape_names
	;

shape_names:
	shape_names '|' shape_name
	| shape_name;

shape_name:
	SHAPE 		{sectionNames.push_back($1);}
	;



footer:
	END ENDLS
	;
ENDLS:
	ENDLS ENDL
	| ENDL ;
%%
vector<string> startParsing(FILE* myfile){
	// set lex to read from it instead of defaulting to STDIN:
	yyin = myfile;

	// parse through the input until there is no more:
	
	do {
		yyparse();
	} while (!feof(yyin));

	return parsingResults;
}

void yyerror(const char *s) {
	string str_msg = "EEK, parse error on line " + to_string(line_num) + "!\nMessage: " + s;
	cout << str_msg << endl;
	// might as well halt now:
	exit(-1);
}
