
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"

#include <stdio.h>
#include <string.h>
#include <list>
#include <Lewis/Data.h>
#include <Lewis/MeshNew.h>
#include <Lewis/Session.h>
#include <Lewis/Reader.h>
#include <Lewis/TransformationNew.h>
#include <Lewis/PolylineNew.h>
#include <Lewis/CircleNew.h>
#include <Lewis/FunnelNew.h>
#include <Lewis/TunnelNew.h>

extern int yylineno;
extern char* yytext;
extern FILE *yyin;
int yylex(void);
int yyerror(char *s) {
  printf("%s on line %d - %s\n", s, yylineno, yytext);
}
extern "C" int yyparse (void);

int yywrap() {
    return 1;
}

Session* currSession = createSession();
Reader* currReader = createReader(currSession);

map<string,QColor> surfaces;
map<string,Vertex*> vertices;
std::vector<string> tempVariables;
std::vector<string> tempFaceDelete;
string currentSetName;
std::list<SetNew *> currentSetList;
map<string,std::vector<double>> currentBank;
std::vector<string> currentInstanceList;
std::list<InstanceNew *> currentGroup;
std::list<FaceNew *> currentMeshFaces;
std::list<Vert *> currentMeshVertices;
std::list<EdgeNew *> currentMeshEdges;

std::list<TransformationNew *> currentTransformations;

double *getBankValue(std::string str){
    unsigned first = str.find("$") + 1;
    unsigned last = str.find(".");
    string strNew = str.substr (first,last-first);

    for(auto b : currSession->banks) {
        if (b->name == strNew){
            for(auto s : b->sets) {
                if (s->name == str.substr(last + 1)){
                    return &s->value;
                }
            }
        }
    }
    return NULL;
}





/* Line 189 of yacc.c  */
#line 140 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     COLOR = 258,
     VARIABLE = 259,
     MULTI_LINE_COMMENT = 260,
     COMMENT = 261,
     NEWLINE = 262,
     OMULTI_LINE_COMMENT = 263,
     EMULTI_LINE_COMMENT = 264,
     SURFACE = 265,
     END_SURFACE = 266,
     MESH = 267,
     END_MESH = 268,
     FACE = 269,
     END_FACE = 270,
     BEG_POINT = 271,
     END_POINT = 272,
     OBJECT = 273,
     END_OBJECT = 274,
     BANK = 275,
     END_BANK = 276,
     TUNNEL = 277,
     END_TUNNEL = 278,
     FUNNEL = 279,
     END_FUNNEL = 280,
     POLYLINE = 281,
     END_POLYLINE = 282,
     INSTANCE = 283,
     END_INSTANCE = 284,
     CIRCLE = 285,
     END_CIRCLE = 286,
     BEG_DELETE = 287,
     END_DELETE = 288,
     GROUP = 289,
     END_GROUP = 290,
     TRANSLATE = 291,
     ROTATE = 292,
     MIRROR = 293,
     SET = 294,
     OPARENTHESES = 295,
     EPARENTHESES = 296,
     OBRACE = 297,
     EXPR = 298,
     DOLLAR = 299,
     EBRACE = 300,
     NUMBER = 301,
     PERIOD = 302,
     TOKHEAT = 303,
     STATE = 304,
     TOKTARGET = 305,
     TOKTEMPERATURE = 306,
     BANK_EXPR = 307,
     SCALE = 308
   };
#endif
/* Tokens.  */
#define COLOR 258
#define VARIABLE 259
#define MULTI_LINE_COMMENT 260
#define COMMENT 261
#define NEWLINE 262
#define OMULTI_LINE_COMMENT 263
#define EMULTI_LINE_COMMENT 264
#define SURFACE 265
#define END_SURFACE 266
#define MESH 267
#define END_MESH 268
#define FACE 269
#define END_FACE 270
#define BEG_POINT 271
#define END_POINT 272
#define OBJECT 273
#define END_OBJECT 274
#define BANK 275
#define END_BANK 276
#define TUNNEL 277
#define END_TUNNEL 278
#define FUNNEL 279
#define END_FUNNEL 280
#define POLYLINE 281
#define END_POLYLINE 282
#define INSTANCE 283
#define END_INSTANCE 284
#define CIRCLE 285
#define END_CIRCLE 286
#define BEG_DELETE 287
#define END_DELETE 288
#define GROUP 289
#define END_GROUP 290
#define TRANSLATE 291
#define ROTATE 292
#define MIRROR 293
#define SET 294
#define OPARENTHESES 295
#define EPARENTHESES 296
#define OBRACE 297
#define EXPR 298
#define DOLLAR 299
#define EBRACE 300
#define NUMBER 301
#define PERIOD 302
#define TOKHEAT 303
#define STATE 304
#define TOKTARGET 305
#define TOKTEMPERATURE 306
#define BANK_EXPR 307
#define SCALE 308




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 78 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"

    double number;
    char *string;
    struct {
        char *string; // char *strVal;
        double number;   // int posVal;
    } numPos;



/* Line 214 of yacc.c  */
#line 293 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 318 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   137

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNRULES -- Number of states.  */
#define YYNSTATES  168

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    41,    43,    45,    47,    48,    51,    52,    55,    56,
      59,    62,    65,    68,    78,    85,    92,   100,   101,   104,
     105,   108,   115,   116,   119,   124,   129,   134,   138,   145,
     146,   149,   152,   158,   163,   171,   181,   191,   195,   201,
     205,   210,   217,   222,   232,   234
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    -1,    55,    56,    -1,    60,    -1,    90,
      -1,    72,    -1,    89,    -1,    91,    -1,    84,    -1,    88,
      -1,    79,    -1,    81,    -1,    82,    -1,    86,    -1,    87,
      -1,    75,    -1,    73,    -1,    80,    -1,    58,    -1,    74,
      -1,    46,    -1,    46,    -1,     6,    -1,    -1,    61,     4,
      -1,    -1,    10,     4,    -1,    -1,    63,    64,    -1,    63,
      65,    -1,    63,    66,    -1,    63,    67,    -1,    37,    40,
      57,    57,    57,    41,    40,    57,    41,    -1,    36,    40,
      57,    57,    57,    41,    -1,    53,    40,    57,    57,    57,
      41,    -1,    38,    40,    57,    57,    57,    57,    41,    -1,
      -1,    68,    78,    -1,    -1,    69,    70,    -1,    28,     4,
       4,    62,    63,    29,    -1,    -1,    71,    85,    -1,    12,
       4,    68,    13,    -1,    34,     4,    69,    35,    -1,    42,
      43,    52,    45,    -1,    32,    71,    33,    -1,    39,     4,
      59,    57,    57,    57,    -1,    -1,    77,    76,    -1,    77,
      60,    -1,    14,     4,    83,    62,    15,    -1,    20,     4,
      77,    21,    -1,    30,     4,    40,    57,    57,    41,    31,
      -1,    22,     4,    40,    57,    57,    57,    57,    41,    23,
      -1,    24,     4,    40,    57,    57,    57,    57,    41,    25,
      -1,    40,    61,    41,    -1,    14,     4,    83,    62,    15,
      -1,    14,     4,    15,    -1,    26,     4,    83,    27,    -1,
      28,     4,     4,    62,    63,    29,    -1,    18,     4,    83,
      19,    -1,    10,     4,     3,    40,    57,    57,    57,    41,
      11,    -1,     5,    -1,    16,     4,    40,    57,    57,    57,
      41,    17,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    95,    95,    96,   101,   101,   101,   101,   101,   101,
     101,   101,   102,   102,   102,   102,   102,   102,   102,   106,
     109,   118,   125,   133,   139,   141,   147,   148,   153,   154,
     154,   154,   154,   158,   200,   233,   266,   276,   277,   280,
     281,   285,   326,   327,   331,   358,   368,   374,   385,   403,
     404,   404,   408,   455,   466,   494,   539,   584,   590,   629,
     636,   660,   706,   733,   765,   771
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COLOR", "VARIABLE",
  "MULTI_LINE_COMMENT", "COMMENT", "NEWLINE", "OMULTI_LINE_COMMENT",
  "EMULTI_LINE_COMMENT", "SURFACE", "END_SURFACE", "MESH", "END_MESH",
  "FACE", "END_FACE", "BEG_POINT", "END_POINT", "OBJECT", "END_OBJECT",
  "BANK", "END_BANK", "TUNNEL", "END_TUNNEL", "FUNNEL", "END_FUNNEL",
  "POLYLINE", "END_POLYLINE", "INSTANCE", "END_INSTANCE", "CIRCLE",
  "END_CIRCLE", "BEG_DELETE", "END_DELETE", "GROUP", "END_GROUP",
  "TRANSLATE", "ROTATE", "MIRROR", "SET", "OPARENTHESES", "EPARENTHESES",
  "OBRACE", "EXPR", "DOLLAR", "EBRACE", "NUMBER", "PERIOD", "TOKHEAT",
  "STATE", "TOKTARGET", "TOKTEMPERATURE", "BANK_EXPR", "SCALE", "$accept",
  "commands", "command", "numberValue", "num", "numPosTok", "comment",
  "variables", "surfaceArgs", "transformArgs", "rotateArgs",
  "translateArgs", "scaleArgs", "mirrorArgs", "faceArgs", "instanceArgs",
  "instanceGroup", "faceDeleteArgs", "mesh", "group", "expr", "delete",
  "set", "setArgs", "faceMesh", "bank", "circle", "tunnel", "funnel",
  "parenthesisName", "face", "faceDelete", "polyline", "instance",
  "object", "surface", "multi_line_comment", "point", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    57,
      57,    58,    59,    60,    61,    61,    62,    62,    63,    63,
      63,    63,    63,    64,    65,    66,    67,    68,    68,    69,
      69,    70,    71,    71,    72,    73,    74,    75,    76,    77,
      77,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     2,     0,     2,     0,     2,
       2,     2,     2,     9,     6,     6,     7,     0,     2,     0,
       2,     6,     0,     2,     4,     4,     4,     3,     6,     0,
       2,     2,     5,     4,     7,     9,     9,     3,     5,     3,
       4,     6,     4,     9,     1,     8
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    64,    23,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    42,     0,     3,     4,
       6,    17,    16,    11,    18,    12,    13,     9,    14,    15,
      10,     7,     5,     8,     0,    37,     0,     0,     0,    49,
       0,     0,     0,     0,     0,     0,    39,     0,     0,    24,
      26,     0,     0,     0,     0,     0,     0,    26,     0,     0,
      47,    43,     0,     0,    44,     0,    38,     0,     0,     0,
       0,    21,     0,    19,    20,    62,    53,     0,    51,    50,
       0,     0,    60,    28,     0,     0,     0,    45,    40,     0,
       0,    25,    57,    27,    58,     0,     0,     0,     0,     0,
       0,     0,    59,     0,     0,    26,     0,     0,    22,     0,
       0,     0,    61,     0,     0,     0,     0,    29,    30,    31,
      32,     0,    26,     0,     0,    46,     0,     0,     0,     0,
       0,     0,     0,     0,    54,    28,     0,    52,    65,     0,
       0,     0,     0,     0,     0,     0,     0,    63,    48,    55,
      56,     0,     0,     0,     0,    41,     0,     0,     0,     0,
      34,     0,     0,    35,     0,    36,     0,    33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    18,    72,    73,   109,    19,    67,    69,   100,
     117,   118,   119,   120,    48,    62,    88,    45,    20,    21,
      74,    22,    79,    53,    66,    23,    24,    25,    26,    50,
      27,    61,    28,    29,    30,    31,    32,    33
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -55
static const yytype_int8 yypact[] =
{
     -55,   101,   -55,   -55,   -55,     7,     9,    18,    21,    33,
      34,    35,    39,    42,    43,    44,   -55,    45,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,   -55,    48,   -55,    12,    19,    12,   -55,
      22,    23,    12,    54,    24,    -4,   -55,    25,    20,   -55,
      50,   -14,    47,     2,   -14,   -14,    40,    50,   -14,    57,
     -55,   -55,   -11,   -14,   -55,    64,   -55,    -1,    65,    56,
      29,   -55,   -14,   -55,   -55,   -55,   -55,    70,   -55,   -55,
     -14,   -14,   -55,   -55,   -14,    60,    76,   -55,   -55,   -14,
      12,   -55,   -55,   -55,   -55,    30,   -14,    37,   -14,   -14,
     -22,    46,   -55,    77,   -14,    50,    41,    51,   -55,   -14,
     -14,   -14,   -55,    53,    55,    62,    63,   -55,   -55,   -55,
     -55,    74,    50,    67,    69,   -55,    79,   -14,    68,    71,
     -14,   -14,   -14,   -14,   -55,   -55,    83,   -55,   -55,   -14,
      91,    93,   -14,   -14,   -14,   -14,   -17,   -55,   -55,   -55,
     -55,   -14,   -14,   -14,   -14,   -55,    75,    81,   -14,    85,
     -55,    80,    87,   -55,   -14,   -55,    89,   -55
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -55,   -55,   -55,   -54,   -55,   -55,    84,   -55,   -52,    -3,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -36,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      80,    81,    52,    91,    84,    83,    56,   112,     4,    89,
      59,    34,   155,    35,   113,   114,   115,    86,    96,   113,
     114,   115,    36,    76,    87,    37,    98,    99,    70,    60,
     101,   116,    71,    64,    65,   104,   116,    38,    39,    40,
      92,    77,   107,    41,   110,   111,    42,    43,    44,    46,
     123,    47,    49,   124,   105,   127,   128,   129,    57,    51,
      68,    85,    54,    55,    58,    63,    75,    82,    90,    93,
     135,    94,    95,   139,    97,   102,   142,   143,   144,   145,
     103,   122,   106,   108,   137,   148,   125,   121,   151,   152,
     153,   154,   126,   130,   147,   131,   138,   156,   157,   158,
     159,     2,   132,   133,   162,   134,     3,     4,   136,   140,
     166,     5,   141,     6,   149,     7,   160,     8,   150,     9,
     164,    10,   161,    11,     0,    12,   163,    13,   165,    14,
     167,    15,   146,    16,     0,    17,     0,    78
};

static const yytype_int16 yycheck[] =
{
      54,    55,    38,     4,    58,    57,    42,    29,     6,    63,
      14,     4,    29,     4,    36,    37,    38,    28,    72,    36,
      37,    38,     4,    21,    35,     4,    80,    81,    42,    33,
      84,    53,    46,    13,    14,    89,    53,     4,     4,     4,
      41,    39,    96,     4,    98,    99,     4,     4,     4,     4,
     104,     3,    40,   105,    90,   109,   110,   111,     4,    40,
      10,     4,    40,    40,    40,    40,    19,    27,     4,     4,
     122,    15,    43,   127,     4,    15,   130,   131,   132,   133,
       4,     4,    52,    46,    15,   139,    45,    41,   142,   143,
     144,   145,    41,    40,    11,    40,    17,   151,   152,   153,
     154,     0,    40,    40,   158,    31,     5,     6,    41,    41,
     164,    10,    41,    12,    23,    14,    41,    16,    25,    18,
      40,    20,    41,    22,    -1,    24,    41,    26,    41,    28,
      41,    30,   135,    32,    -1,    34,    -1,    53
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    55,     0,     5,     6,    10,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    56,    60,
      72,    73,    75,    79,    80,    81,    82,    84,    86,    87,
      88,    89,    90,    91,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,    71,     4,     3,    68,    40,
      83,    40,    83,    77,    40,    40,    83,     4,    40,    14,
      33,    85,    69,    40,    13,    14,    78,    61,    10,    62,
      42,    46,    57,    58,    74,    19,    21,    39,    60,    76,
      57,    57,    27,    62,    57,     4,    28,    35,    70,    57,
       4,     4,    41,     4,    15,    43,    57,     4,    57,    57,
      63,    57,    15,     4,    57,    83,    52,    57,    46,    59,
      57,    57,    29,    36,    37,    38,    53,    64,    65,    66,
      67,    41,     4,    57,    62,    45,    41,    57,    57,    57,
      40,    40,    40,    40,    31,    62,    41,    15,    17,    57,
      41,    41,    57,    57,    57,    57,    63,    11,    57,    23,
      25,    57,    57,    57,    57,    29,    57,    57,    57,    57,
      41,    41,    57,    41,    40,    41,    57,    41
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 19:

/* Line 1455 of yacc.c  */
#line 106 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {
        (yyval.numPos.number) = (yyvsp[(1) - (1)].number);
        (yyval.numPos.string) = NULL;
    }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 110 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {
        (yyval.numPos.string) = (yyvsp[(1) - (1)].string);
        (yyval.numPos.number) = 0;
    }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 119 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {
        (yyval.number) = (double)atof((yyvsp[(1) - (1)].string));
    }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 126 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {
        (yyval.numPos.string) = strdup((yyvsp[(1) - (1)].string));
        (yyval.numPos.number) = yycolumn;
    }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 134 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {
    }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 141 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {
        tempVariables.push_back((yyvsp[(2) - (2)].string));
    }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 147 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {(yyval.string) = "";}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 148 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {
        (yyval.string) = (yyvsp[(2) - (2)].string);
    }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 159 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {
        double *x = (double*) malloc(sizeof(double));
        double *y = (double*) malloc(sizeof(double));
        double *z = (double*) malloc(sizeof(double));
        double *angle = (double*) malloc(sizeof(double));


        if ((yyvsp[(3) - (9)].numPos.string) == NULL){
            *x = (yyvsp[(3) - (9)].numPos.number);
        }
        else{
            x = getBankValue((yyvsp[(3) - (9)].numPos.string));
        }

        if ((yyvsp[(4) - (9)].numPos.string) == NULL){
            *y = (yyvsp[(4) - (9)].numPos.number);
        }
        else{
            y = getBankValue((yyvsp[(4) - (9)].numPos.string));
        }

        if ((yyvsp[(5) - (9)].numPos.string) == NULL){
            *z = (yyvsp[(5) - (9)].numPos.number);
        }
        else{
            z = getBankValue((yyvsp[(5) - (9)].numPos.string));
        }

        if ((yyvsp[(8) - (9)].numPos.string) == NULL){
            *angle = (yyvsp[(8) - (9)].numPos.number);
        }
        else{
            angle = getBankValue((yyvsp[(8) - (9)].numPos.string));
        }

        currentTransformations.push_back(createRotate(x, y, z, angle));

    }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 201 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {
        double *x = (double*) malloc(sizeof(double));
        double *y = (double*) malloc(sizeof(double));
        double *z = (double*) malloc(sizeof(double));


        if ((yyvsp[(3) - (6)].numPos.string) == NULL){
            *x = (yyvsp[(3) - (6)].numPos.number);
        }
        else{
            x = getBankValue((yyvsp[(3) - (6)].numPos.string));
        }

        if ((yyvsp[(4) - (6)].numPos.string) == NULL){
            *y = (yyvsp[(4) - (6)].numPos.number);
        }
        else{
            y = getBankValue((yyvsp[(4) - (6)].numPos.string));
        }

        if ((yyvsp[(5) - (6)].numPos.string) == NULL){
            *z = (yyvsp[(5) - (6)].numPos.number);
        }
        else{
            z = getBankValue((yyvsp[(5) - (6)].numPos.string));
        }

        currentTransformations.push_back(createTranslate(x, y, z));
    }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 234 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {
        double *x = (double*) malloc(sizeof(double));
        double *y = (double*) malloc(sizeof(double));
        double *z = (double*) malloc(sizeof(double));


        if ((yyvsp[(3) - (6)].numPos.string) == NULL){
            *x = (yyvsp[(3) - (6)].numPos.number);
        }
        else{
            x = getBankValue((yyvsp[(3) - (6)].numPos.string));
        }

        if ((yyvsp[(4) - (6)].numPos.string) == NULL){
            *y = (yyvsp[(4) - (6)].numPos.number);
        }
        else{
            y = getBankValue((yyvsp[(4) - (6)].numPos.string));
        }

        if ((yyvsp[(5) - (6)].numPos.string) == NULL){
            *z = (yyvsp[(5) - (6)].numPos.number);
        }
        else{
            z = getBankValue((yyvsp[(5) - (6)].numPos.string));
        }

        currentTransformations.push_back(createScale(x, y, z));
    }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 267 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {
        double x = (yyvsp[(3) - (7)].numPos.number);
        double y = (yyvsp[(4) - (7)].numPos.number);
        double z = (yyvsp[(5) - (7)].numPos.number);
        double w = (yyvsp[(5) - (7)].numPos.number);

    }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 286 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {
        string instanceName = strdup((yyvsp[(2) - (6)].string));
        string lookFor = strdup((yyvsp[(3) - (6)].string));

        MeshNew * currentMesh = currReader->mesh((yyvsp[(3) - (6)].string));

        InstanceNew* newInstance;
        if (currentMesh != NULL) {
            newInstance = createInstance(currentMesh, currSession->verts);
            newInstance->setName(strdup((yyvsp[(2) - (6)].string)));
        }
        else{
            yyerror("Incorrect vertex, face, or mesh name");
            YYABORT;
        }

        newInstance->transformations = currentTransformations;
        currentTransformations.clear();

        for (TransformationNew * t : newInstance->transformations){
            newInstance->applyTransformation(t);
        }

        string surfaceName = (yyvsp[(4) - (6)].string);
        // Check if a surface has been applied.
        if (surfaceName.length() != 0){
            Surface * currentSurface = currReader->surf((yyvsp[(4) - (6)].string));
            if (currentSurface != NULL) {
                setSurface(newInstance, currentSurface);
            }
            else{
                yyerror("Incorrect surface name");
                YYABORT;
            }
        }

        currentGroup.push_back(newInstance);
    }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 332 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {

        MeshNew* currMesh = createMesh();

        for (std::list<FaceNew*>::iterator it=currentMeshFaces.begin(); it != currentMeshFaces.end(); ++it){
            currMesh->faces.push_back(*it);
        }

        for (std::list<Vert*>::iterator it=currentMeshVertices.begin(); it != currentMeshVertices.end(); ++it){
            currMesh->verts.push_back(*it);
        }

        for (std::list<EdgeNew*>::iterator it=currentMeshEdges.begin(); it != currentMeshEdges.end(); ++it){
            currMesh->edges.push_back(*it);
        }

        currMesh->setName(strdup((yyvsp[(2) - (4)].string)));
        currSession->meshes.push_back(currMesh);

        currentMeshFaces.clear();
        currentMeshEdges.clear();
        currentMeshVertices.clear();
	}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 359 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {
        GroupNew* currGroup = createGroup(currentGroup);
        currGroup->setName(strdup((yyvsp[(2) - (4)].string)));
        currSession->groups.push_back(currGroup);
        currentGroup.clear();
	}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 369 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {
        (yyval.string) = (yyvsp[(3) - (4)].string);
    }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 375 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {
        for (std::string currFace : tempFaceDelete){
            currReader->deleteFace(currReader->getFace(currFace));
        }

        tempFaceDelete.clear();
	}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 386 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {
        string currentSetName = (yyvsp[(2) - (6)].string);
        double currentSetValue = (double)atof((yyvsp[(3) - (6)].numPos.string));
        double currentSetStart = (yyvsp[(4) - (6)].numPos.number);
        double currentSetEnd = (yyvsp[(5) - (6)].numPos.number);
        double currentSetStepSize = (yyvsp[(6) - (6)].numPos.number);
        string currentSetValueString = (yyvsp[(3) - (6)].numPos.string);

        int begPos = (yyvsp[(3) - (6)].numPos.number)-currentSetValueString.length();
        int lengthValChar = currentSetValueString.length();

        SetNew * currentSet = createSet(currentSetName, currentSetValue, currentSetStart, currentSetEnd, currentSetStepSize, begPos, lengthValChar);

        currentSetList.push_back(currentSet);
	}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 409 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {
        std::list<Vert*> verticesFace;

        for (std::vector<string>::iterator it = tempVariables.begin() ; it != tempVariables.end(); ++it){
            Vert * currentVertex = currReader->getVert(*it);
            if (currentVertex != NULL) {
                verticesFace.push_back(currentVertex);
                bool found = false;
                for (Vert* currentMeshVertex: currentMeshVertices){
                    if (currentMeshVertex->index == currentVertex->index){
                        found = true;
                    }
                }
                if (found == false){
                    currentMeshVertices.push_back(currentVertex);
                }

            }
            else{
                yyerror("Incorrect vertex name");
                YYABORT;
            }
        }
        FaceNew * newFace = createFace(verticesFace, &currentMeshEdges);
        setName(newFace, strdup((yyvsp[(2) - (5)].string)));

        string surfaceName = (yyvsp[(4) - (5)].string);
        // Check if a surface has been applied.
        if (surfaceName.length() != 0){
            Surface * currentSurface = currReader->surf((yyvsp[(4) - (5)].string));
            if (currentSurface != NULL) {
                setSurface(newFace, currentSurface);
            }
            else{
                yyerror("Incorrect surface name");
                YYABORT;
            }
        }

        currentMeshFaces.push_back(newFace);

        tempVariables.clear();
    }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 456 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {
        BankNew * currentBank = createBank();
        currentBank->name = strdup((yyvsp[(2) - (4)].string));
        currentBank->sets = currentSetList;
        currSession->banks.push_back(currentBank);
        currentSetList.clear();
	}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 467 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {
        string name = (yyvsp[(2) - (7)].string);
        double *num = (double*) malloc(sizeof(double));
        double *rad = (double*) malloc(sizeof(double));


        if ((yyvsp[(4) - (7)].numPos.string) == NULL){
            *num = (yyvsp[(4) - (7)].numPos.number);
        }
        else{
            num = getBankValue((yyvsp[(4) - (7)].numPos.string));
        }

        if ((yyvsp[(5) - (7)].numPos.string) == NULL){
            *rad = (yyvsp[(5) - (7)].numPos.number);
        }
        else{
            rad = getBankValue((yyvsp[(5) - (7)].numPos.string));
        }

        CircleNew* currCircle = createCircle(num, rad);
        currCircle->setName(strdup((yyvsp[(2) - (7)].string)));

        currSession->circles.push_back(currCircle);
    }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 496 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {
        string name = (yyvsp[(2) - (9)].string);
        double *n = (double*) malloc(sizeof(double));
        double *ro = (double*) malloc(sizeof(double));
        double *ratio = (double*) malloc(sizeof(double));
        double *h = (double*) malloc(sizeof(double));

        if ((yyvsp[(4) - (9)].numPos.string) == NULL){
            *n = (yyvsp[(4) - (9)].numPos.number);
        }
        else{
            n = getBankValue((yyvsp[(4) - (9)].numPos.string));
        }

        if ((yyvsp[(5) - (9)].numPos.string) == NULL){
            *ro = (yyvsp[(5) - (9)].numPos.number);
        }
        else{
            ro = getBankValue((yyvsp[(5) - (9)].numPos.string));
        }

        if ((yyvsp[(6) - (9)].numPos.string) == NULL){
            *ratio = (yyvsp[(6) - (9)].numPos.number);
        }
        else{
            ratio = getBankValue((yyvsp[(6) - (9)].numPos.string));
        }

        if ((yyvsp[(7) - (9)].numPos.string) == NULL){
            *h = (yyvsp[(7) - (9)].numPos.number);
        }
        else{
            h = getBankValue((yyvsp[(7) - (9)].numPos.string));
        }

        TunnelNew* currTunnel = createTunnel(n, ro, ratio, h);
        currTunnel->setName(strdup((yyvsp[(2) - (9)].string)));

        currSession->tunnels.push_back(currTunnel);
	}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 541 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {
        string name = (yyvsp[(2) - (9)].string);
        double *n = (double*) malloc(sizeof(double));
        double *ro = (double*) malloc(sizeof(double));
        double *ratio = (double*) malloc(sizeof(double));
        double *h = (double*) malloc(sizeof(double));

        if ((yyvsp[(4) - (9)].numPos.string) == NULL){
            *n = (yyvsp[(4) - (9)].numPos.number);
        }
        else{
            n = getBankValue((yyvsp[(4) - (9)].numPos.string));
        }

        if ((yyvsp[(5) - (9)].numPos.string) == NULL){
            *ro = (yyvsp[(5) - (9)].numPos.number);
        }
        else{
            ro = getBankValue((yyvsp[(5) - (9)].numPos.string));
        }

        if ((yyvsp[(6) - (9)].numPos.string) == NULL){
            *ratio = (yyvsp[(6) - (9)].numPos.number);
        }
        else{
            ratio = getBankValue((yyvsp[(6) - (9)].numPos.string));
        }

        if ((yyvsp[(7) - (9)].numPos.string) == NULL){
            *h = (yyvsp[(7) - (9)].number);
        }
        else{
            h = getBankValue((yyvsp[(7) - (9)].numPos.string));
        }

        FunnelNew* currFunnel = createFunnel(n, ro, ratio, h);
        currFunnel->setName(strdup((yyvsp[(2) - (9)].string)));

        currSession->funnels.push_back(currFunnel);
	}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 585 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {
	}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 591 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {
        std::list<Vert*> verticesFace;
        for (std::vector<string>::iterator it = tempVariables.begin() ; it != tempVariables.end(); ++it){
            Vert * currentVertex = currReader->vert(*it);
            if (currentVertex != NULL) {
                verticesFace.push_back(currentVertex);
            }
            else{
                yyerror("Incorrect vertex name");
                YYABORT;
            }
        }

        FaceNew * newFace = createFace(verticesFace, &(currSession->edges));

        setName(newFace, strdup((yyvsp[(2) - (5)].string)));


        string surfaceName = (yyvsp[(4) - (5)].string);
        // Check if a surface has been applied.
        if (surfaceName.length() != 0){
            Surface * currentSurface = currReader->surf((yyvsp[(4) - (5)].string));
            if (currentSurface != NULL) {
                setSurface(newFace, currentSurface);
            }
            else{
                yyerror("Incorrect surface name");
                YYABORT;
            }
        }

        currSession->faces.push_back(newFace);

        tempVariables.clear();
	}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 630 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {
        tempFaceDelete.push_back((yyvsp[(2) - (3)].string));
	}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 637 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {
        // Create list of vertices of face.
        std::list<Vert*> verticesPolyline;
        for (std::vector<string>::iterator it = tempVariables.begin() ; it != tempVariables.end(); ++it){
            Vert * currentVertex = currReader->getVert(*it);
            if (currentVertex != NULL) {
                verticesPolyline.push_back(currentVertex);
            }
            else{
                yyerror("Incorrect vertex name");
                YYABORT;
            }
        }

        PolylineNew* currPolyline = createPolylineNew(verticesPolyline);
        currPolyline->setName(strdup((yyvsp[(2) - (4)].string)));

        currSession->polylines.push_back(currPolyline);
        tempVariables.clear();
	}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 661 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {

        string instanceName = strdup((yyvsp[(2) - (6)].string));
        string lookFor = strdup((yyvsp[(3) - (6)].string));

        //MeshNew * currentMesh = currReader->mesh($<string>3);
        MeshNew * currentMesh = currReader->getMesh((yyvsp[(3) - (6)].string));

        InstanceNew* newInstance;
        if (currentMesh != NULL) {
            newInstance = createInstance(currentMesh, currSession->verts);
            newInstance->setName(strdup((yyvsp[(2) - (6)].string)));
        }
        else{
            yyerror("Incorrect vertex, face, or mesh name");
            YYABORT;
        }

        newInstance->transformations = currentTransformations;
        currentTransformations.clear();

        for (TransformationNew * t : newInstance->transformations){
            newInstance->applyTransformation(t);

            //copyStateTransformation(t, &(newInstance->appliedTransformations));
        }

        string surfaceName = (yyvsp[(4) - (6)].string);
        // Check if a surface has been applied.
        if (surfaceName.length() != 0){
            Surface * currentSurface = currReader->surf((yyvsp[(4) - (6)].string));
            if (currentSurface != NULL) {
                setSurface(newInstance, currentSurface);
            }
            else{
                yyerror("Incorrect surface name");
                YYABORT;
            }
        }

        currSession->instances.push_back(newInstance);
	}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 707 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {
        /*std::list<FaceNew*> facesObject;
        for (std::vector<string>::iterator it = tempVariables.begin() ; it != tempVariables.end(); ++it){
            FaceNew * currentFace = currReader->face(*it);
            if (currentFace != NULL) {
                facesObject.push_back(currentFace);
            }
            else{
                yyerror("Incorrect vertex name");
                YYABORT;
            }
        }

        MeshNew * newObject = createMesh(facesObject);

        newObject->setName(strdup($<string>2));

        currSession->objects.push_back(newObject);

        tempVariables.clear();*/

        //printf("Created an object\n");
	}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 734 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {
        double *r = (double*) malloc(sizeof(double));
        double *g = (double*) malloc(sizeof(double));
        double *b = (double*) malloc(sizeof(double));

        if ((yyvsp[(5) - (9)].numPos.string) == NULL){
            *r = (yyvsp[(5) - (9)].numPos.number);
        }
        else{
            r = getBankValue((yyvsp[(5) - (9)].numPos.string));
        }

        if ((yyvsp[(6) - (9)].numPos.string) == NULL){
            *g = (yyvsp[(6) - (9)].numPos.number);
        }
        else{
            g = getBankValue((yyvsp[(6) - (9)].numPos.string));
        }

        if ((yyvsp[(7) - (9)].numPos.string) == NULL){
            *b = (yyvsp[(7) - (9)].numPos.number);
        }
        else{
            b = getBankValue((yyvsp[(7) - (9)].numPos.string));
        }

        currSession->surfaces.push_back(createSurface(r, g, b, strdup((yyvsp[(2) - (9)].string))));
	}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 766 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {
	}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 772 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.y"
    {
        double *x = (double*) malloc(sizeof(double));
        double *y = (double*) malloc(sizeof(double));
        double *z = (double*) malloc(sizeof(double));


        if ((yyvsp[(4) - (8)].numPos.string) == NULL){
            *x = (yyvsp[(4) - (8)].numPos.number);
        }
        else{
            x = getBankValue((yyvsp[(4) - (8)].numPos.string));
        }

        if ((yyvsp[(5) - (8)].numPos.string) == NULL){
            *y = (yyvsp[(5) - (8)].numPos.number);
        }
        else{
            y = getBankValue((yyvsp[(5) - (8)].numPos.string));
        }

        if ((yyvsp[(6) - (8)].numPos.string) == NULL){
            *z = (yyvsp[(6) - (8)].numPos.number);
        }
        else{
            z = getBankValue((yyvsp[(6) - (8)].numPos.string));
        }

        Vert * newVertex = createVert (x, y, z);
        newVertex->setName(strdup((yyvsp[(2) - (8)].string)));
        currSession->verts.push_back(newVertex);
	}
    break;



/* Line 1455 of yacc.c  */
#line 2437 "C:\\Users\\dieppedalle\\Documents\\nomeProject\\nome\\parser.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



