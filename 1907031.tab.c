
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
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "1907031.y"

#include<stdio.h>
#include <math.h>
#include<stdlib.h>
#include<string.h>
extern FILE *yyin;
//extern FILE *yyout;
int lineNo = 0;
int yylex();
int yyerror(char *s);

// Symbol Table Arrays
char var_name[1000][1000];
int store[1000];
float store_float[1000];
int type[1000];
int ttp = 0; // 0 = int, 1 = float, 2 = string, 3 = function

// Conditional Statement Variables
int ifptr = 0;
int ifdone[1000];

// Variable Counter
int var_cnt = 0;

// Variable Declaration Check
int chkDeclared(char *s){
    int i;
    for(i=0; i<var_cnt; i++){
        if(strcmp(var_name[i], s) == 0)
                return 1;
    }
    return 0;
}

// New Variable Declaration
int init_asn(char *s){
    if(chkDeclared(s) == 1){
        return 0;
    }
    strcpy(var_name[var_cnt], s);
    store[var_cnt] = 0;
    type[var_cnt] = ttp;
    char name[10];
    if(ttp == 0) {
        strcpy(name, "Int");
    }
    else if(ttp == 1) {
        strcpy(name, "Float");
    }
    else if(ttp == 2) {
        strcpy(name, "String");
    }
    printf("\nNew Variable Declared With Name: %s and Type: %s\n", var_name[var_cnt], name);
    var_cnt++;
    return 1;
}

// New Function Declaration
int init_asn_func(char *s){
    if(chkDeclared(s) == 1){
        return 0;
    }
    strcpy(var_name[var_cnt], s);
    store[var_cnt] = 0;
    type[var_cnt] = 3;
    printf("\nNew Function Declared With Name: %s\n", var_name[var_cnt]);
    var_cnt++;
    return 1;
}

// Assigning Value to Variable
int setValue(char *s, int val){
    if(chkDeclared(s) == 0){
        return 0;
    }
    int ok=0, i;
    for(i=0; i<var_cnt; i++){
        if(strcmp(var_name[i], s) == 0){
            ok = i;
            break;
        }
    }
    store[ok] = val;
    printf("\nNew Value Assigned to Variable Name: %s and Value: %d\n", var_name[ok], store[ok]);
    return 1;
}

// Get Variable Value
int getValue(char *s){
    int pos=-1;
    int i;
    for(i=0; i<var_cnt; i++){
        if(strcmp(var_name[i], s) == 0){
            pos=i;
            break;
        }
    }
    return pos;
}


/* Line 189 of yacc.c  */
#line 176 "1907031.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
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
     END = 258,
     INT = 259,
     FLOAT = 260,
     STRING = 261,
     MOD = 262,
     LT = 263,
     GT = 264,
     GEQ = 265,
     LEQ = 266,
     EQ = 267,
     NEQ = 268,
     VARIABLE = 269,
     NUMBER = 270,
     IMPORT = 271,
     HEADER = 272,
     MAIN = 273,
     INC = 274,
     DEC = 275,
     NOT = 276,
     SIN = 277,
     COS = 278,
     LOG = 279,
     TAN = 280,
     LN = 281,
     ODDEVEN = 282,
     FACTORIAL = 283,
     MAX = 284,
     MIN = 285,
     PRIME = 286,
     DEF = 287,
     DISPLAY = 288,
     IF = 289,
     ELSE_IF = 290,
     ELSE = 291
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 104 "1907031.y"

    int num;
    float flt;
    char* string;



/* Line 214 of yacc.c  */
#line 256 "1907031.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 268 "1907031.tab.c"

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
#define YYLAST   548

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNRULES -- Number of states.  */
#define YYNSTATES  166

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      42,    43,    39,    37,    48,    38,     2,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      46,    49,    47,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    41,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,    16,    17,    19,    24,    25,
      33,    34,    37,    42,    45,    47,    50,    51,    53,    55,
      58,    63,    66,    72,    77,    82,    87,    92,    97,    99,
     104,   106,   110,   112,   113,   117,   119,   121,   123,   127,
     133,   135,   139,   141,   143,   147,   151,   155,   159,   163,
     167,   171,   175,   179,   183,   187,   191,   195,   198,   201,
     204,   209,   214,   219,   224,   229,   234,   239,   246,   253
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,    -1,    51,    52,    -1,    54,    55,    53,
      42,    43,    44,    59,    45,    -1,    -1,    18,    -1,    16,
      46,    17,    47,    -1,    -1,    56,    42,    57,    43,    44,
      59,    45,    -1,    -1,    32,    14,    -1,    57,    48,    68,
      58,    -1,    68,    58,    -1,    14,    -1,    59,    60,    -1,
      -1,     3,    -1,    67,    -1,    70,     3,    -1,    14,    49,
      70,     3,    -1,    64,     3,    -1,    33,    42,    14,    43,
       3,    -1,    61,    44,    59,    45,    -1,    62,    44,    59,
      45,    -1,    63,    44,    59,    45,    -1,    34,    42,    70,
      43,    -1,    35,    42,    70,    43,    -1,    36,    -1,    65,
      42,    66,    43,    -1,    14,    -1,    66,    48,    14,    -1,
      14,    -1,    -1,    68,    69,     3,    -1,     4,    -1,     5,
      -1,     6,    -1,    69,    48,    14,    -1,    69,    48,    14,
      49,    70,    -1,    14,    -1,    14,    49,    70,    -1,    15,
      -1,    14,    -1,    70,    37,    70,    -1,    70,    38,    70,
      -1,    70,    39,    70,    -1,    70,    40,    70,    -1,    70,
      41,    70,    -1,    70,     7,    70,    -1,    42,    70,    43,
      -1,    70,     8,    70,    -1,    70,     9,    70,    -1,    70,
      11,    70,    -1,    70,    10,    70,    -1,    70,    12,    70,
      -1,    70,    13,    70,    -1,    14,    19,    -1,    14,    20,
      -1,    21,    14,    -1,    22,    42,    70,    43,    -1,    23,
      42,    70,    43,    -1,    25,    42,    70,    43,    -1,    24,
      42,    70,    43,    -1,    26,    42,    70,    43,    -1,    27,
      42,    70,    43,    -1,    28,    42,    70,    43,    -1,    29,
      42,    70,    48,    70,    43,    -1,    30,    42,    70,    48,
      70,    43,    -1,    31,    42,    70,    43,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   129,   129,   130,   134,   135,   139,   142,   143,   147,
     150,   154,   164,   165,   169,   180,   181,   185,   186,   187,
     188,   196,   197,   205,   208,   211,   217,   229,   240,   251,
     257,   267,   276,   285,   289,   293,   294,   295,   299,   307,
     316,   322,   334,   335,   345,   349,   353,   357,   367,   371,
     375,   376,   380,   384,   388,   392,   396,   400,   413,   426,
     439,   443,   447,   451,   455,   459,   469,   478,   488,   498
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "END", "INT", "FLOAT", "STRING", "MOD",
  "LT", "GT", "GEQ", "LEQ", "EQ", "NEQ", "VARIABLE", "NUMBER", "IMPORT",
  "HEADER", "MAIN", "INC", "DEC", "NOT", "SIN", "COS", "LOG", "TAN", "LN",
  "ODDEVEN", "FACTORIAL", "MAX", "MIN", "PRIME", "DEF", "DISPLAY", "IF",
  "ELSE_IF", "ELSE", "'+'", "'-'", "'*'", "'/'", "'^'", "'('", "')'",
  "'{'", "'}'", "'<'", "'>'", "','", "'='", "$accept", "start", "program",
  "main", "import", "func", "func_head", "param", "pid", "statements",
  "cstatement", "if_condition", "else_if_condition", "else_condition",
  "function_call", "f_var", "call_param", "declare", "type", "id",
  "expression", 0
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
     285,   286,   287,   288,   289,   290,   291,    43,    45,    42,
      47,    94,    40,    41,   123,   125,    60,    62,    44,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    51,    52,    52,    53,    54,    54,    55,
      55,    56,    57,    57,    58,    59,    59,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    61,    62,    63,    64,
      65,    66,    66,    66,    67,    68,    68,    68,    69,    69,
      69,    69,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     8,     0,     1,     4,     0,     7,
       0,     2,     4,     2,     1,     2,     0,     1,     1,     2,
       4,     2,     5,     4,     4,     4,     4,     4,     1,     4,
       1,     3,     1,     0,     3,     1,     1,     1,     3,     5,
       1,     3,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       4,     4,     4,     4,     4,     4,     4,     6,     6,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     5,     1,     0,     3,    10,     0,     0,     0,     0,
       0,    11,     6,     0,     0,     7,     0,    35,    36,    37,
       0,     0,     0,     0,     0,    14,    13,    16,    16,     0,
       0,     0,    12,    17,    43,    42,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      28,     0,     4,    15,     0,     0,     0,     0,     0,    18,
       0,     0,     9,    57,    58,     0,    59,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      43,     0,    16,    16,    16,    21,    33,    40,     0,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,     0,     0,     0,
      32,     0,     0,    34,     0,    49,    51,    52,    54,    53,
      55,    56,    44,    45,    46,    47,    48,    20,    60,    61,
      63,    62,    64,    65,    66,     0,     0,    69,     0,    26,
      27,    23,    24,    25,    29,     0,    41,    38,     0,     0,
      22,    31,     0,    67,    68,    39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     4,    13,     5,     8,     9,    20,    26,    30,
      53,    54,    55,    56,    57,    58,   121,    59,    60,    88,
      61
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -52
static const yytype_int16 yypact[] =
{
     -52,    10,   -52,   -41,   -52,   -25,    -6,    -1,    -3,   -13,
      20,   -52,   -52,    26,    48,   -52,    29,   -52,   -52,   -52,
     -40,    60,    43,    49,    48,   -52,   -52,   -52,   -52,    60,
      55,    98,   -52,   -52,   190,   -52,    78,    54,    56,    57,
      72,    73,    75,    76,    88,    97,    99,   100,   102,   103,
     -52,   506,   -52,   -52,    66,   107,   108,   161,   131,   -52,
     162,   251,   -52,   -52,   -52,   506,   -52,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   164,   506,   506,
      11,   297,   -52,   -52,   -52,   -52,   165,   126,     3,   -52,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   262,   304,   311,   318,   355,   362,   369,   376,
      25,   239,   413,   139,   420,   427,   -52,   132,   166,   200,
     -52,   -39,   506,   -52,   169,   143,    68,    68,    68,    68,
      68,    68,   109,   109,   143,   143,   -52,   -52,   -52,   -52,
     -52,   -52,   -52,   -52,   -52,   506,   506,   -52,   182,   -52,
     -52,   -52,   -52,   -52,   -52,   172,   478,   149,   434,   471,
     -52,   -52,   506,   -52,   -52,   478
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   178,   -27,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -12,   -52,
     -51
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -31
static const yytype_int16 yytable[] =
{
      81,    31,    21,    23,   154,     6,   123,     7,    24,   155,
       2,    10,    29,    11,   102,    12,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,     3,   114,   115,    14,
      63,    64,    90,    91,    92,    93,    94,    95,    96,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   124,    17,    18,    19,   117,   118,   119,    33,    17,
      18,    19,    97,    98,    99,   100,   101,    15,    16,    34,
      35,   156,    22,   145,    25,    90,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    27,    47,    48,
      49,    50,    66,    28,   158,   159,    67,    51,    68,    69,
      52,    33,    17,    18,    19,    97,    98,    99,   100,   101,
      82,   165,    34,    35,    70,    71,    90,    72,    73,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      74,    47,    48,    49,    50,    33,    17,    18,    19,    75,
      51,    76,    77,    62,    78,    79,    34,    35,    99,   100,
     101,    83,    84,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    85,    47,    48,    49,    50,    33,
      17,    18,    19,    86,    51,   122,    87,   151,   113,   120,
      34,    35,   148,   157,   101,   160,   161,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,   162,    47,
      48,    49,    50,    33,    17,    18,    19,    32,    51,    63,
      64,   152,     0,     0,    34,    35,     0,     0,     0,     0,
       0,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,   -30,    47,    48,    49,    50,     0,     0,    65,
       0,     0,    51,     0,     0,   153,    90,    91,    92,    93,
      94,    95,    96,     0,    89,     0,     0,     0,    90,    91,
      92,    93,    94,    95,    96,   137,     0,     0,     0,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,     0,     0,     0,     0,     0,     0,   146,    97,    98,
      99,   100,   101,     0,     0,     0,     0,     0,     0,    97,
      98,    99,   100,   101,    90,    91,    92,    93,    94,    95,
      96,    90,    91,    92,    93,    94,    95,    96,    90,    91,
      92,    93,    94,    95,    96,    90,    91,    92,    93,    94,
      95,    96,     0,     0,    97,    98,    99,   100,   101,     0,
     116,    97,    98,    99,   100,   101,     0,   138,    97,    98,
      99,   100,   101,     0,   139,    97,    98,    99,   100,   101,
       0,   140,    90,    91,    92,    93,    94,    95,    96,    90,
      91,    92,    93,    94,    95,    96,    90,    91,    92,    93,
      94,    95,    96,    90,    91,    92,    93,    94,    95,    96,
       0,     0,    97,    98,    99,   100,   101,     0,   141,    97,
      98,    99,   100,   101,     0,   142,    97,    98,    99,   100,
     101,     0,   143,    97,    98,    99,   100,   101,     0,   144,
      90,    91,    92,    93,    94,    95,    96,    90,    91,    92,
      93,    94,    95,    96,    90,    91,    92,    93,    94,    95,
      96,    90,    91,    92,    93,    94,    95,    96,     0,     0,
      97,    98,    99,   100,   101,     0,   147,    97,    98,    99,
     100,   101,     0,   149,    97,    98,    99,   100,   101,     0,
     150,    97,    98,    99,   100,   101,     0,   163,    90,    91,
      92,    93,    94,    95,    96,    90,    91,    92,    93,    94,
      95,    96,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    97,    98,
      99,   100,   101,     0,   164,    97,    98,    99,   100,   101,
      80,    35,     0,     0,     0,     0,     0,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51
};

static const yytype_int16 yycheck[] =
{
      51,    28,    14,    43,    43,    46,     3,    32,    48,    48,
       0,    17,    24,    14,    65,    18,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    16,    78,    79,    42,
      19,    20,     7,     8,     9,    10,    11,    12,    13,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,    48,     4,     5,     6,    82,    83,    84,     3,     4,
       5,     6,    37,    38,    39,    40,    41,    47,    42,    14,
      15,   122,    43,    48,    14,     7,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    44,    33,    34,
      35,    36,    14,    44,   145,   146,    42,    42,    42,    42,
      45,     3,     4,     5,     6,    37,    38,    39,    40,    41,
      44,   162,    14,    15,    42,    42,     7,    42,    42,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      42,    33,    34,    35,    36,     3,     4,     5,     6,    42,
      42,    42,    42,    45,    42,    42,    14,    15,    39,    40,
      41,    44,    44,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     3,    33,    34,    35,    36,     3,
       4,     5,     6,    42,    42,    49,    14,    45,    14,    14,
      14,    15,    43,    14,    41,     3,    14,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    49,    33,
      34,    35,    36,     3,     4,     5,     6,    29,    42,    19,
      20,    45,    -1,    -1,    14,    15,    -1,    -1,    -1,    -1,
      -1,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    42,    33,    34,    35,    36,    -1,    -1,    49,
      -1,    -1,    42,    -1,    -1,    45,     7,     8,     9,    10,
      11,    12,    13,    -1,     3,    -1,    -1,    -1,     7,     8,
       9,    10,    11,    12,    13,     3,    -1,    -1,    -1,     7,
       8,     9,    10,    11,    12,    13,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    48,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    41,     7,     8,     9,    10,    11,    12,
      13,     7,     8,     9,    10,    11,    12,    13,     7,     8,
       9,    10,    11,    12,    13,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    37,    38,    39,    40,    41,    -1,
      43,    37,    38,    39,    40,    41,    -1,    43,    37,    38,
      39,    40,    41,    -1,    43,    37,    38,    39,    40,    41,
      -1,    43,     7,     8,     9,    10,    11,    12,    13,     7,
       8,     9,    10,    11,    12,    13,     7,     8,     9,    10,
      11,    12,    13,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,    37,    38,    39,    40,    41,    -1,    43,    37,
      38,    39,    40,    41,    -1,    43,    37,    38,    39,    40,
      41,    -1,    43,    37,    38,    39,    40,    41,    -1,    43,
       7,     8,     9,    10,    11,    12,    13,     7,     8,     9,
      10,    11,    12,    13,     7,     8,     9,    10,    11,    12,
      13,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
      37,    38,    39,    40,    41,    -1,    43,    37,    38,    39,
      40,    41,    -1,    43,    37,    38,    39,    40,    41,    -1,
      43,    37,    38,    39,    40,    41,    -1,    43,     7,     8,
       9,    10,    11,    12,    13,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    41,    -1,    43,    37,    38,    39,    40,    41,
      14,    15,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,     0,    16,    52,    54,    46,    32,    55,    56,
      17,    14,    18,    53,    42,    47,    42,     4,     5,     6,
      57,    68,    43,    43,    48,    14,    58,    44,    44,    68,
      59,    59,    58,     3,    14,    15,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    33,    34,    35,
      36,    42,    45,    60,    61,    62,    63,    64,    65,    67,
      68,    70,    45,    19,    20,    49,    14,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      14,    70,    44,    44,    44,     3,    42,    14,    69,     3,
       7,     8,     9,    10,    11,    12,    13,    37,    38,    39,
      40,    41,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    14,    70,    70,    43,    59,    59,    59,
      14,    66,    49,     3,    48,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,     3,    43,    43,
      43,    43,    43,    43,    43,    48,    48,    43,    43,    43,
      43,    45,    45,    45,    43,    48,    70,    14,    70,    70,
       3,    14,    49,    43,    43,    70
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:

/* Line 1455 of yacc.c  */
#line 134 "1907031.y"
    { printf("\nProgram successfully ended\n"); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 139 "1907031.y"
    { printf("\nMain Function Declared!\n"); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 142 "1907031.y"
    { printf("\nHeader File Found!\n"); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 147 "1907031.y"
    {
		printf("\nUser Defined Function Ended!\n");
	;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 154 "1907031.y"
    {
        if(chkDeclared((yyvsp[(2) - (2)].string))==1) {
            printf("\nDuplicate Function Name!\n");
        }
        else {
            init_asn_func((yyvsp[(2) - (2)].string));
        }
    ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 164 "1907031.y"
    { printf("\nValid Function Parameter Declaration!\n"); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 165 "1907031.y"
    { printf("\nValid Function Parameter Declaration!\n"); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 169 "1907031.y"
    {
		if(chkDeclared((yyvsp[(1) - (1)].string))==1) {
      		printf("\nDuplicate Declaration!\n");
        }
   		else {
      	    init_asn((yyvsp[(1) - (1)].string));
		}
    ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 188 "1907031.y"
    {
		if(chkDeclared((yyvsp[(1) - (4)].string)) == 0) {
			printf("\n%s Not Declared!\n", (yyvsp[(1) - (4)].string));
		}
		else {
			setValue((yyvsp[(1) - (4)].string), (yyvsp[(3) - (4)].num));
		}
	;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 197 "1907031.y"
    {
		if(chkDeclared((yyvsp[(3) - (5)].string))==0) {
			printf("\nCan't print, Variable is not declared\n");
        }
        else {
            printf("\nPrinting Value of the variable %s: %d\n", (yyvsp[(3) - (5)].string), store[getValue((yyvsp[(3) - (5)].string))]);
        }
	;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 205 "1907031.y"
    {
		printf("\nIf Block is Successfully Handled\n");
	;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 208 "1907031.y"
    {
		printf("\nElse If Block is Successfully Handled\n");
	;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 211 "1907031.y"
    {
		printf("\nElse Block is Successfully Handled\n");
	;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 217 "1907031.y"
    {
        if( (yyvsp[(3) - (4)].num) == 1 ) {
			ifdone[ifptr] = 1;
			printf("\nIf Block is Executed\n");
		}
        else {
            printf("\nIf Block is Not Executed\n");
        }
        ifptr++;
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 229 "1907031.y"
    {
        if( (yyvsp[(3) - (4)].num) == 1 && ifdone[ifptr] == 0) {
			ifdone[ifptr] = 1;
			printf("\nElse If Block is Executed\n");
		}
        else {
            printf("\nElse If Block is Not Executed\n");
        }
    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 240 "1907031.y"
    {
        if( ifdone[ifptr] == 0) {
			ifdone[ifptr] = 1;
			printf("\nElse Block is Executed \n");
		}
        else {
            printf("\nElse Block is Not Executed\n");
        }
    ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 251 "1907031.y"
    { 
        printf("\nValid Function Call!\n");
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 257 "1907031.y"
    {
        if(chkDeclared((yyvsp[(1) - (1)].string)) == 0) {
			printf("\n%s Function is Not Declared!\n", (yyvsp[(1) - (1)].string));
		}
        else {
            printf("\n%s Function is Called!\n", (yyvsp[(1) - (1)].string));
        }
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 267 "1907031.y"
    {
        if(chkDeclared((yyvsp[(3) - (3)].string)) == 0) {
            printf("\n%s Variable is Not Declared\n", (yyvsp[(3) - (3)].string));
        }
        else {
            printf("\n%s Passed as Parameter For Function!\n", (yyvsp[(3) - (3)].string)); 
                
        }
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 276 "1907031.y"
    {
        if(chkDeclared((yyvsp[(1) - (1)].string)) == 0) {
            printf("\n%s Variable is Not Declared\n", (yyvsp[(1) - (1)].string));
        }
        else {
            printf("\n%s Passed as Parameter For Function!\n", (yyvsp[(1) - (1)].string)); 
                
        }
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 289 "1907031.y"
    { printf("\nValid Syntax!\n"); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 293 "1907031.y"
    { ttp = 0; ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 294 "1907031.y"
    { ttp = 1; ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 295 "1907031.y"
    { ttp = 2; ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 299 "1907031.y"
    {
        if(chkDeclared((yyvsp[(3) - (3)].string))==1) {
            printf("\nDuplicate Declaration!\n");
        }
        else {
            init_asn((yyvsp[(3) - (3)].string));
        }
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 307 "1907031.y"
    {
        if(chkDeclared((yyvsp[(3) - (5)].string))==1) {
            printf("\nDuplicate Declaration!\n");
        }
        else {
            init_asn((yyvsp[(3) - (5)].string));
            setValue((yyvsp[(3) - (5)].string), (yyvsp[(5) - (5)].num)); 
        }
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 316 "1907031.y"
    {
        if(chkDeclared((yyvsp[(1) - (1)].string))==1)
            printf("\nDuplicate Declaration!\n");
        else
            init_asn((yyvsp[(1) - (1)].string));
	;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 322 "1907031.y"
    {
        if(chkDeclared((yyvsp[(1) - (3)].string))==1) {
            printf("\nDuplicate Declaration!\n");
        }
        else {
            init_asn((yyvsp[(1) - (3)].string));
            setValue((yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].num));
        }
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 334 "1907031.y"
    { (yyval.num) = (yyvsp[(1) - (1)].num); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 335 "1907031.y"
    {
        if(chkDeclared((yyvsp[(1) - (1)].string)) == 0) {
            (yyval.num)=0;
            printf("\n%s Not Declared!\n", (yyvsp[(1) - (1)].string));
        }
        else {
            int index = getValue((yyvsp[(1) - (1)].string));
            (yyval.num) = store[index];
        }
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 345 "1907031.y"
    { 	
        (yyval.num) = (yyvsp[(1) - (3)].num) + (yyvsp[(3) - (3)].num); 
        printf("\nAdd Value %d\n", (yyval.num));
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 349 "1907031.y"
    {
        (yyval.num) = (yyvsp[(1) - (3)].num) - (yyvsp[(3) - (3)].num); 
        printf("\nSub Value %d\n", (yyval.num));
	;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 353 "1907031.y"
    {
        (yyval.num) = (yyvsp[(1) - (3)].num) * (yyvsp[(3) - (3)].num);
        printf("\nMul Value %d\n", (yyval.num));
	;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 357 "1907031.y"
    { 	
        if((yyvsp[(3) - (3)].num)) {
                (yyval.num) = (yyvsp[(1) - (3)].num) / (yyvsp[(3) - (3)].num);
                printf("\nDiv Value %d\n", (yyval.num));
        }
        else {
                (yyval.num) = 0;
                printf("\nDiv by Zero\t");
        }
	;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 367 "1907031.y"
    { 	
        (yyval.num)=pow((yyvsp[(1) - (3)].num), (yyvsp[(3) - (3)].num)); 
        printf("\nPower Value %d\n", (yyval.num));
	;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 371 "1907031.y"
    {	 
        (yyval.num)=(yyvsp[(1) - (3)].num) % (yyvsp[(3) - (3)].num); 
        printf("\nRemainder Value %d\n", (yyval.num));
	;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 375 "1907031.y"
    { (yyval.num) = (yyvsp[(2) - (3)].num); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 376 "1907031.y"
    {
        (yyval.num) = (yyvsp[(1) - (3)].num) < (yyvsp[(3) - (3)].num);
        printf("\nLess Than Value is %d\n", (yyval.num));
	;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 380 "1907031.y"
    {
        (yyval.num) = (yyvsp[(1) - (3)].num) > (yyvsp[(3) - (3)].num); 
        printf("\nGreater Than Value is %d\n", (yyval.num));
	;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 384 "1907031.y"
    { 
        (yyval.num) = (yyvsp[(1) - (3)].num) <= (yyvsp[(3) - (3)].num);
        printf("\nLess Than or Equal To Value is %d\n", (yyval.num)); 
	;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 388 "1907031.y"
    { 
        (yyval.num) = (yyvsp[(1) - (3)].num) >= (yyvsp[(3) - (3)].num); 
        printf("\nGreater Than or Equal To Value is %d\n", (yyval.num));
	;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 392 "1907031.y"
    { 
        (yyval.num) = (yyvsp[(1) - (3)].num) == (yyvsp[(3) - (3)].num); 
        printf("\nEqual To Value is %d\n", (yyval.num));
	;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 396 "1907031.y"
    { 
        (yyval.num) = (yyvsp[(1) - (3)].num) != (yyvsp[(3) - (3)].num); 
        printf("\nNot Eqaul To Value is %d\n", (yyval.num));
	;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 400 "1907031.y"
    {
        if( chkDeclared((yyvsp[(1) - (2)].string)) == 0) {
            (yyval.num)=0;
            printf("\n%s Not Declared!\n", (yyvsp[(1) - (2)].string));
        }
        else {
            int tmp = store[getValue((yyvsp[(1) - (2)].string))];
            tmp = tmp+1;
            store[getValue((yyvsp[(1) - (2)].string))] = tmp;
            (yyval.num)=store[getValue((yyvsp[(1) - (2)].string))];
            printf("\nValue After Increment is %d\n", (yyval.num));
        }
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 413 "1907031.y"
    {
  		if( chkDeclared((yyvsp[(1) - (2)].string)) == 0) {
    		(yyval.num)=0;
     		printf("\n%s Not Declared!\n", (yyvsp[(1) - (2)].string));
   		}
    	else {
            int tmp = store[getValue((yyvsp[(1) - (2)].string))];
            tmp = tmp-1;
            store[getValue((yyvsp[(1) - (2)].string))] = tmp;
            (yyval.num)=store[getValue((yyvsp[(1) - (2)].string))];
            printf("\nValue After Decrement is %d\n", (yyval.num));
        }
	;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 426 "1907031.y"
    {
  		if( chkDeclared((yyvsp[(2) - (2)].string)) == 0) {
            (yyval.num)=0;
            printf("\n%s Not Declared!\n", (yyvsp[(2) - (2)].string));
   		}
        else {
            int tmp = store[getValue((yyvsp[(2) - (2)].string))];
            tmp = !tmp;
            store[getValue((yyvsp[(2) - (2)].string))] = tmp;
            (yyval.num)=store[getValue((yyvsp[(2) - (2)].string))];
           printf("\nValue After NOT Operation is %d\n", (yyval.num));
        }
	;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 439 "1907031.y"
    {
		printf("\nValue of Sin(%d) is %lf\n", (yyvsp[(3) - (4)].num), sin((yyvsp[(3) - (4)].num)*3.1416/180)); 
        (yyval.num) = sin((yyvsp[(3) - (4)].num)*3.1416/180);
	;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 443 "1907031.y"
    {
		printf("\nValue of Cos(%d) is %lf\n", (yyvsp[(3) - (4)].num), cos((yyvsp[(3) - (4)].num)*3.1416/180)); 
        (yyval.num) = cos((yyvsp[(3) - (4)].num)*3.1416/180);
	;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 447 "1907031.y"
    {
		printf("\nValue of Tan(%d) is %lf\n", (yyvsp[(3) - (4)].num), tan((yyvsp[(3) - (4)].num)*3.1416/180)); 
        (yyval.num) = tan((yyvsp[(3) - (4)].num)*3.1416/180);
	;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 451 "1907031.y"
    {
		printf("\nValue of Log(%d) is %lf\n", (yyvsp[(3) - (4)].num), (log((yyvsp[(3) - (4)].num)*1.0)/log(10.0))); 
        (yyval.num) = (log((yyvsp[(3) - (4)].num)*1.0)/log(10.0));
	;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 455 "1907031.y"
    {
		printf("\nValue of Ln(%d) is %lf\n", (yyvsp[(3) - (4)].num), (log((yyvsp[(3) - (4)].num)))); 
        (yyval.num)=(log((yyvsp[(3) - (4)].num)));
	;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 459 "1907031.y"
    {
        if((yyvsp[(3) - (4)].num)%2==0) {
            (yyval.num) = 0;
            printf("\n%d is An Even Number\n", (yyvsp[(3) - (4)].num));
        } 
        else {
            (yyval.num) = 1;
            printf("\n%d is An Odd Number\n", (yyvsp[(3) - (4)].num));
        }        
    ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 469 "1907031.y"
    {
        int ans = 1;
        int i;
        for(i=1; i<=(yyvsp[(3) - (4)].num); i++) {
            ans = ans*i;
        }
        printf("\nFactorial of %d is %d\n", (yyvsp[(3) - (4)].num), ans);
        (yyval.num) = ans;
    ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 478 "1907031.y"
    {
        if( (yyvsp[(3) - (6)].num) < (yyvsp[(5) - (6)].num) ) {
            (yyval.num) = (yyvsp[(5) - (6)].num);
            printf("\nMax Number Between %d and %d is %d\n", (yyvsp[(3) - (6)].num), (yyvsp[(5) - (6)].num), (yyvsp[(5) - (6)].num));
        }
        else {
            (yyval.num) = (yyvsp[(3) - (6)].num);
            printf("\nMax Number Between %d and %d is %d\n", (yyvsp[(3) - (6)].num), (yyvsp[(5) - (6)].num), (yyvsp[(3) - (6)].num));
        }
    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 488 "1907031.y"
    {
        if( (yyvsp[(3) - (6)].num) < (yyvsp[(5) - (6)].num) ) {
            (yyval.num) = (yyvsp[(3) - (6)].num);
            printf("\nMin Number Between %d and %d is %d\n", (yyvsp[(3) - (6)].num), (yyvsp[(5) - (6)].num), (yyvsp[(3) - (6)].num));
        }
        else {
            (yyval.num) = (yyvsp[(5) - (6)].num);
            printf("\nMin Number Between %d and %d is %d\n", (yyvsp[(3) - (6)].num), (yyvsp[(5) - (6)].num), (yyvsp[(5) - (6)].num));
        }
    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 498 "1907031.y"
    {
        int x = (yyvsp[(3) - (4)].num);
        int ck = 0;
        int i; 
        for(i=2; i*i<=x; i++) {
            if( x%i == 0 ) {
                ck = 1;
                break;
            }
        }
        if(ck) {
            (yyval.num) = 0;
            printf("\n%d is Not A Prime Number\n", x);
        }
        else {
            (yyval.num) = 1;
            printf("\n%d is A Prime Number\n", x);
        }
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 2331 "1907031.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


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
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 519 "1907031.y"


int yywrap()
{
	return 1;
}

int main()
{	
	yyin = freopen("input.txt","r",stdin);
	//yyout = freopen("output.txt","w",stdout);
	yyparse();
	return 0;	
}

int yyerror(char *s)
{
    printf( "%s\n", s);
}
