/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "scanner.y" /* yacc.c:339  */

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


#line 143 "scanner.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "scanner.h".  */
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
#line 87 "scanner.y" /* yacc.c:355  */

	int   ival;
	float fval;
	char* sval;
	int   ivalr;
	float fvalr;

#line 237 "scanner.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SCANNER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 252 "scanner.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   130

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  170

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      48,    50,     2,     2,    49,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    46,    47,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,    53,    52,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   149,   149,   153,   157,   161,   162,   165,   185,   187,
     188,   192,   319,   412,   500,   594,   598,   599,   603,   604,
     608,   609,   613,   617,   618,   622,   623,   624,   625,   629,
     630,   631,   632,   636,   639,   642,   645,   648,   651,   654,
     657,   660,   663,   666,   667,   668,   669,   670,   671,   672,
     673,   674,   678,   682,   685,   686,   689,   690,   693,   694,
     698,   702,   706,   710,   713,   717,   720,   725,   728,   732,
     733,   734,   735,   736,   737,   738,   742,   743,   744,   745,
     746,   747,   748,   752,   756,   757,   761,   762,   773,   777,
     778,   781,   787,   790,   791
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "START", "END", "ENDL", "ARROW",
  "TRANSLATION", "SIZEV", "INSTANCE", "COLOR", "CUBE", "CYLINDER", "QUAD",
  "SPHERE", "PYRAMID", "CONE", "TRIANGLE", "CIRCLE", "EMPTY", "ROTATEX",
  "ROTATEY", "ROTATEZ", "SUBDIV", "REPEATE", "COMP", "NEGATIVE", "X", "Y",
  "Z", "XY", "XZ", "YZ", "XYZ", "TOP", "BOTTOM", "LEFT", "RIGHT", "FRONT",
  "BACK", "ALL", "INTF", "FLOATF", "SHAPE", "INTR", "FLOATR", "':'", "';'",
  "'('", "','", "')'", "'{'", "'}'", "'|'", "$accept", "input", "header",
  "body_section", "body_lines", "body_line", "successor", "rules", "rule",
  "scope_rule", "translation", "size", "color", "instance", "probability",
  "number", "numberr", "numberTx", "numberTy", "numberTz", "numberSx",
  "numberSy", "numberSz", "numberPr", "numberCr", "numberCg", "numberCb",
  "type_of_shape", "rotation", "rotates", "rotatex", "rotatey", "rotatez",
  "numberRx", "numberRy", "numberRz", "split_rule", "subdivation",
  "repeat_rule", "repeatation", "comp_rule", "component", "face", "axis",
  "split_size_section", "section_sizes", "section_size",
  "shape_list_section", "shape_names", "shape_name", "footer", "ENDLS", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    58,    59,    40,    44,
      41,   123,   125,   124
};
# endif

#define YYPACT_NINF -75

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-75)))

#define YYTABLE_NINF -9

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       5,   -32,    39,     1,    41,   -75,     2,    43,     1,   -75,
     -75,    44,     8,    41,   -75,   -75,   -75,    46,    44,    47,
       9,     6,    -6,   -75,   -75,    48,   -75,   -75,   -75,   -14,
      41,   -75,    10,    49,     3,   -75,   -75,   -75,    27,    44,
     -14,    20,    57,   -75,   -75,   -14,   -75,    29,   -14,    31,
       0,   -75,    59,   -75,    32,   -14,   -75,    33,   -14,    36,
      37,    38,    40,    45,    45,    45,    45,    42,    61,   -14,
     -75,    51,   -14,   -75,    53,    19,    34,    34,    35,   -14,
     -75,   -75,   -75,   -75,   -14,    50,   -75,   -75,    54,   -14,
     -75,    52,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,   -75,    55,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
      58,    60,   -75,   -75,   -75,   -75,   -75,   -75,   -75,    56,
     -75,   -75,   -75,    62,   -14,   -75,   -75,    63,   -14,   -75,
     -24,   -14,    64,   -75,   -75,    66,   -75,   -75,    67,   -38,
     -75,   -75,   -75,   -75,    68,    65,   -75,    69,    77,   -75,
     -75,   -75,   -75,    70,   -24,    71,    72,    80,   -75,    82,
     -75,   -75,    74,    75,   -75,    78,   -75,    80,   -75,   -75
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     0,     4,     6,
      94,     3,     0,     0,     2,     5,    93,     0,    92,    17,
       0,     0,    17,    10,    13,    19,    11,    12,    14,     0,
       0,     9,     0,    21,     0,    27,    28,    33,     0,     7,
       0,     0,    54,    25,    26,     0,    36,     0,     0,     0,
       0,    52,    56,    34,     0,     0,    40,     0,     0,     0,
       0,     0,     0,    24,    24,    24,    24,     0,    58,     0,
      37,     0,     0,    60,     0,     0,     0,     0,     0,     0,
      15,    63,    65,    67,     0,     0,    53,    35,     0,     0,
      41,     0,    55,    44,    43,    45,    46,    47,    48,    49,
      50,    51,     0,    76,    77,    78,    79,    80,    81,    82,
       0,     0,    69,    70,    71,    72,    73,    74,    75,     0,
      39,    23,    61,     0,     0,    16,    38,     0,     0,    22,
       0,     0,     0,    57,    62,     0,    18,    42,     0,     0,
      31,    32,    86,    87,     0,    83,    85,     0,     0,    59,
      20,    29,    30,     0,     0,     0,     0,     0,    84,     0,
      68,    91,     0,    88,    90,     0,    64,     0,    66,    89
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -75,   -75,   -75,   -75,   -75,    79,   -75,   -75,    86,   -75,
     -75,   -75,   -75,   -75,   -51,   -29,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,    12,   -75,   -75,   -62,   -75,   -75,   -74,
     -75,    -8
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,     8,     9,    21,    22,    23,    24,
      25,    33,    42,    63,    80,   142,   143,    38,    54,    88,
      47,    71,   127,   121,    57,    91,   138,   102,    50,    51,
      52,    68,    86,    74,   123,   135,    26,    64,    27,    65,
      28,    66,   119,   110,   144,   145,   146,   162,   163,   164,
      14,    11
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,    20,   139,    43,    44,    18,   151,   152,     1,    59,
       4,    46,    34,    81,    82,    83,    53,    35,    36,    56,
     140,   141,    39,    60,    61,    62,    70,    35,    36,    73,
      93,    94,    95,    96,    97,    98,    99,   100,   101,     5,
      87,    -8,     6,    90,    43,    44,    10,    13,    12,    16,
     120,    17,    19,    30,    20,   122,    32,    29,    40,    41,
     126,   103,   104,   105,   106,   107,   108,   109,    48,   112,
     113,   114,   115,   116,   117,   118,    45,    49,    55,    58,
      67,    69,    72,    85,    75,    76,    77,    15,    78,   111,
      84,    79,   158,   169,     0,   134,     0,     0,   124,   137,
      89,   128,   147,    92,   125,   129,   132,   130,    31,   131,
       0,     0,   133,   136,   154,   148,   149,   150,   153,   155,
     156,   157,   159,   161,   160,   165,   166,     0,   167,     0,
     168
};

static const yytype_int16 yycheck[] =
{
      29,     7,    26,    41,    42,    13,    44,    45,     3,     9,
      42,    40,    26,    64,    65,    66,    45,    41,    42,    48,
      44,    45,    30,    23,    24,    25,    55,    41,    42,    58,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      69,    47,    41,    72,    41,    42,     5,     4,    46,     5,
      79,    43,     6,    47,     7,    84,     8,    48,    48,    10,
      89,    27,    28,    29,    30,    31,    32,    33,    48,    34,
      35,    36,    37,    38,    39,    40,    49,    20,    49,    48,
      21,    49,    49,    22,    48,    48,    48,     8,    48,    77,
      48,    46,   154,   167,    -1,   124,    -1,    -1,    48,   128,
      49,    49,   131,    50,    50,    50,    50,    49,    22,    49,
      -1,    -1,    50,    50,    49,    51,    50,    50,    50,    50,
      43,    51,    51,    43,    52,    43,    52,    -1,    53,    -1,
      52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    55,    56,    42,     0,    41,    57,    58,    59,
       5,   105,    46,     4,   104,    59,     5,    43,   105,     6,
       7,    60,    61,    62,    63,    64,    90,    92,    94,    48,
      47,    62,     8,    65,    26,    41,    42,    69,    71,   105,
      48,    10,    66,    41,    42,    49,    69,    74,    48,    20,
      82,    83,    84,    69,    72,    49,    69,    78,    48,     9,
      23,    24,    25,    67,    91,    93,    95,    21,    85,    49,
      69,    75,    49,    69,    87,    48,    48,    48,    48,    46,
      68,    68,    68,    68,    48,    22,    86,    69,    73,    49,
      69,    79,    50,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    81,    27,    28,    29,    30,    31,    32,    33,
      97,    97,    34,    35,    36,    37,    38,    39,    40,    96,
      69,    77,    69,    88,    48,    50,    69,    76,    49,    50,
      49,    49,    50,    50,    69,    89,    50,    69,    80,    26,
      44,    45,    69,    70,    98,    99,   100,    69,    51,    50,
      50,    44,    45,    50,    49,    50,    43,    51,   100,    51,
      52,    43,   101,   102,   103,    43,    52,    53,    52,   103
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    57,    58,    58,    59,    60,    61,
      61,    62,    62,    62,    62,    63,    64,    64,    65,    65,
      66,    66,    67,    68,    68,    69,    69,    69,    69,    70,
      70,    70,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    82,    83,    84,    84,    85,    85,    86,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      96,    96,    96,    96,    96,    96,    97,    97,    97,    97,
      97,    97,    97,    98,    99,    99,   100,   100,   101,   102,
     102,   103,   104,   105,   105
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     1,     2,     1,     7,     1,     2,
       1,     1,     1,     1,     1,     6,     8,     0,     8,     0,
       8,     0,     4,     2,     0,     2,     2,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     0,     4,     0,     4,     0,     4,
       1,     1,     1,     6,     9,     6,     9,     6,     7,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     2,     2,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 149 "scanner.y" /* yacc.c:1646  */
    {  parsingResults.push_back("END"); }
#line 1452 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 153 "scanner.y" /* yacc.c:1646  */
    { parsingResults.push_back("BEGIN"); }
#line 1458 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 166 "scanner.y" /* yacc.c:1646  */
    { 
		parsingResults.push_back("ID");
		parsingResults.push_back("(");
		parsingResults.push_back(to_string((yyvsp[-6].ival)));
		parsingResults.push_back(")");
		parsingResults.push_back(":");
		parsingResults.push_back("SHAPE");
		parsingResults.push_back("(");
		string str_name = (yyvsp[-4].sval);
		parsingResults.push_back(str_name);
		parsingResults.push_back(")");
		parsingResults.push_back("ARROW"); 
		transFerTempVectorToFinalVector(successorsV);
		parsingResults.push_back("ENDR");
		successorsV.clear();
	}
#line 1479 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 193 "scanner.y" /* yacc.c:1646  */
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
#line 1610 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 320 "scanner.y" /* yacc.c:1646  */
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
#line 1707 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 413 "scanner.y" /* yacc.c:1646  */
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
		}
#line 1799 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 501 "scanner.y" /* yacc.c:1646  */
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
		}
#line 1894 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 599 "scanner.y" /* yacc.c:1646  */
    {tx=0; ty=0; tz=0;}
#line 1900 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 604 "scanner.y" /* yacc.c:1646  */
    {sx=-1; sy= -1; sz=-1;}
#line 1906 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 609 "scanner.y" /* yacc.c:1646  */
    {cr=-1; cg=-1; cb=-1;}
#line 1912 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 618 "scanner.y" /* yacc.c:1646  */
    {pr = -1.0;}
#line 1918 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 622 "scanner.y" /* yacc.c:1646  */
    {number = (yyvsp[0].ival); negative = true;}
#line 1924 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 623 "scanner.y" /* yacc.c:1646  */
    {number = (yyvsp[0].fval); negative = true;}
#line 1930 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 624 "scanner.y" /* yacc.c:1646  */
    {number = (yyvsp[0].ival); negative = false;}
#line 1936 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 625 "scanner.y" /* yacc.c:1646  */
    {number = (yyvsp[0].fval); negative = false;}
#line 1942 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 629 "scanner.y" /* yacc.c:1646  */
    {number = (yyvsp[0].ivalr); negative = true;}
#line 1948 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 630 "scanner.y" /* yacc.c:1646  */
    {number = (yyvsp[0].fvalr); negative = true;}
#line 1954 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 631 "scanner.y" /* yacc.c:1646  */
    {number = (yyvsp[0].ivalr); negative = false;}
#line 1960 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 632 "scanner.y" /* yacc.c:1646  */
    {number = (yyvsp[0].fvalr); negative = false;}
#line 1966 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 636 "scanner.y" /* yacc.c:1646  */
    {tx = negative ? (-1)*number : number;}
#line 1972 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 639 "scanner.y" /* yacc.c:1646  */
    {ty = negative ? (-1)*number : number;}
#line 1978 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 642 "scanner.y" /* yacc.c:1646  */
    {tz = negative ? (-1)*number : number;}
#line 1984 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 645 "scanner.y" /* yacc.c:1646  */
    {sx = negative ? (-1)*number : number;}
#line 1990 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 648 "scanner.y" /* yacc.c:1646  */
    {sy = negative ? (-1)*number : number;}
#line 1996 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 651 "scanner.y" /* yacc.c:1646  */
    {sz = negative ? (-1)*number : number;}
#line 2002 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 654 "scanner.y" /* yacc.c:1646  */
    {pr = negative ? (-1)*number : number;}
#line 2008 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 657 "scanner.y" /* yacc.c:1646  */
    {cr = negative ? (-1)*number : number;}
#line 2014 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 660 "scanner.y" /* yacc.c:1646  */
    {cg = negative ? (-1)*number : number;}
#line 2020 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 663 "scanner.y" /* yacc.c:1646  */
    {cb = negative ? (-1)*number : number;}
#line 2026 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 666 "scanner.y" /* yacc.c:1646  */
    {typeOfShape = "CYLINDER";}
#line 2032 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 667 "scanner.y" /* yacc.c:1646  */
    {typeOfShape = "CUBE";}
#line 2038 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 668 "scanner.y" /* yacc.c:1646  */
    {typeOfShape = "QUAD";}
#line 2044 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 669 "scanner.y" /* yacc.c:1646  */
    {typeOfShape = "SPHERE";}
#line 2050 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 670 "scanner.y" /* yacc.c:1646  */
    {typeOfShape = "PYRAMID";}
#line 2056 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 671 "scanner.y" /* yacc.c:1646  */
    {typeOfShape = "CONE";}
#line 2062 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 672 "scanner.y" /* yacc.c:1646  */
    {typeOfShape = "TRIANGLE";}
#line 2068 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 673 "scanner.y" /* yacc.c:1646  */
    {typeOfShape = "CIRCLE";}
#line 2074 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 674 "scanner.y" /* yacc.c:1646  */
    {typeOfShape = "EMPTY";}
#line 2080 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 685 "scanner.y" /* yacc.c:1646  */
    {rx=0;}
#line 2086 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 689 "scanner.y" /* yacc.c:1646  */
    {ry=0;}
#line 2092 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 693 "scanner.y" /* yacc.c:1646  */
    {rz=0;}
#line 2098 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 698 "scanner.y" /* yacc.c:1646  */
    {rx = negative ? (-1)*number : number;}
#line 2104 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 702 "scanner.y" /* yacc.c:1646  */
    {ry = negative ? (-1)*number : number;}
#line 2110 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 706 "scanner.y" /* yacc.c:1646  */
    {rz = negative ? (-1)*number : number;}
#line 2116 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 720 "scanner.y" /* yacc.c:1646  */
    { repeatWidth = to_string(number); shapeName = (yyvsp[-1].sval); }
#line 2122 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 728 "scanner.y" /* yacc.c:1646  */
    { shapeName = (yyvsp[-1].sval); }
#line 2128 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 732 "scanner.y" /* yacc.c:1646  */
    {faceName="TOP";}
#line 2134 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 733 "scanner.y" /* yacc.c:1646  */
    {faceName="BOTTOM";}
#line 2140 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 734 "scanner.y" /* yacc.c:1646  */
    {faceName="LEFT";}
#line 2146 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 735 "scanner.y" /* yacc.c:1646  */
    {faceName="RIGHT";}
#line 2152 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 736 "scanner.y" /* yacc.c:1646  */
    {faceName="FRONT";}
#line 2158 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 737 "scanner.y" /* yacc.c:1646  */
    {faceName="BACK";}
#line 2164 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 738 "scanner.y" /* yacc.c:1646  */
    {faceName="ALL";}
#line 2170 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 742 "scanner.y" /* yacc.c:1646  */
    {axisName = "X";}
#line 2176 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 743 "scanner.y" /* yacc.c:1646  */
    {axisName = "Y";}
#line 2182 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 744 "scanner.y" /* yacc.c:1646  */
    {axisName = "Z";}
#line 2188 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 745 "scanner.y" /* yacc.c:1646  */
    {axisName = "XY";}
#line 2194 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 746 "scanner.y" /* yacc.c:1646  */
    {axisName = "XZ";}
#line 2200 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 747 "scanner.y" /* yacc.c:1646  */
    {axisName = "YZ";}
#line 2206 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 748 "scanner.y" /* yacc.c:1646  */
    {axisName = "XYZ";}
#line 2212 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 761 "scanner.y" /* yacc.c:1646  */
    {string str = to_string((negative ? (-1)*number : number)); sectionSizes.push_back(str);}
#line 2218 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 762 "scanner.y" /* yacc.c:1646  */
    {
						sectionSizes.push_back("RELATIVE");
						sectionSizes.push_back("(");
						string str = to_string((negative ? (-1)*number : number));
						sectionSizes.push_back(str);
						sectionSizes.push_back(")");
					}
#line 2230 "scanner.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 781 "scanner.y" /* yacc.c:1646  */
    {sectionNames.push_back((yyvsp[0].sval));}
#line 2236 "scanner.cpp" /* yacc.c:1646  */
    break;


#line 2240 "scanner.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 792 "scanner.y" /* yacc.c:1906  */

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
