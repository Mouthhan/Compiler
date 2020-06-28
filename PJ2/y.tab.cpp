/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "yacc.y" /* yacc.c:339  */

#include <iostream>
#include <fstream>
#include <string>
#include "math.h"
#include "SymbolTable.hpp"
#include "lex.yy.cpp"

using namespace std;
#define Trace(t)        cout<<t<<endl;
#define IsGLOBAL 0
SymbolTables all_table = SymbolTables();//All SymbolTable
int table_index = 0;
void InsertSymbol(Identifier* n,SymbolTable &ST);
ofstream java;
string funcName = "";
int now_stack = 0;
string now_class = "";
bool has_return = false;
bool const_val = false;
extern "C"
{
	void yyerror(const char *s);
	extern int yylex();
}
void yyerror(string msg)
{
        cout << " (" << msg  << ')' << endl;
        exit(-1);
}
//load
void java_load(int index)
{
	java<<"\t\tiload "<<index<<endl;
}
//store
void java_store(int index)
{
	java<<"\t\tistore "<<index<<endl;
}
//push
void java_push(int i)
{
	java<<"\t\tsipush "<<i<<endl;
}

#line 113 "y.tab.cpp" /* yacc.c:339  */

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
   by #include "y.tab.hpp".  */
#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
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
    OR = 258,
    AND = 259,
    EQUAL = 260,
    LESS = 261,
    NOT_MORE = 262,
    NOT_LESS = 263,
    MORE = 264,
    NOT_EQUAL = 265,
    NOT = 266,
    SEMICOLON = 267,
    BOOLEAN = 268,
    BREAK = 269,
    CHAR = 270,
    CASE = 271,
    CLASS = 272,
    CONTINUE = 273,
    DEF = 274,
    DO = 275,
    ELSE = 276,
    EXIT = 277,
    BOOL_FALSE = 278,
    FLOAT = 279,
    FOR = 280,
    IF = 281,
    INT = 282,
    _NULL = 283,
    OBJECT = 284,
    PRINT = 285,
    PRINTLN = 286,
    READ = 287,
    REPEAT = 288,
    RETURN = 289,
    STRING = 290,
    TO = 291,
    BOOL_TRUE = 292,
    TYPE = 293,
    VAL = 294,
    VAR = 295,
    WHILE = 296,
    INT_VALUE = 297,
    FLOAT_VALUE = 298,
    BOOL_VALUE = 299,
    STRING_VALUE = 300,
    CHAR_VALUE = 301,
    ID = 302,
    UMINUS = 303
  };
#endif
/* Tokens.  */
#define OR 258
#define AND 259
#define EQUAL 260
#define LESS 261
#define NOT_MORE 262
#define NOT_LESS 263
#define MORE 264
#define NOT_EQUAL 265
#define NOT 266
#define SEMICOLON 267
#define BOOLEAN 268
#define BREAK 269
#define CHAR 270
#define CASE 271
#define CLASS 272
#define CONTINUE 273
#define DEF 274
#define DO 275
#define ELSE 276
#define EXIT 277
#define BOOL_FALSE 278
#define FLOAT 279
#define FOR 280
#define IF 281
#define INT 282
#define _NULL 283
#define OBJECT 284
#define PRINT 285
#define PRINTLN 286
#define READ 287
#define REPEAT 288
#define RETURN 289
#define STRING 290
#define TO 291
#define BOOL_TRUE 292
#define TYPE 293
#define VAL 294
#define VAR 295
#define WHILE 296
#define INT_VALUE 297
#define FLOAT_VALUE 298
#define BOOL_VALUE 299
#define STRING_VALUE 300
#define CHAR_VALUE 301
#define ID 302
#define UMINUS 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 48 "yacc.y" /* yacc.c:355  */

	int i_val;
	float f_val;
	bool b_val;
	string* s_val;
	char c_val;
	int valueType;
	Value* value;
	Identifier* idType;

#line 260 "y.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 277 "y.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   323

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,     2,     2,    53,     2,     2,
      59,    60,    51,    49,    63,    50,     2,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    56,     2,
       2,    55,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,     2,    62,     2,     2,     2,     2,
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
      45,    46,    47,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    97,    97,    98,    99,   103,   102,   122,   121,   144,
     171,   199,   225,   256,   286,   288,   306,   308,   327,   347,
     367,   387,   405,   421,   433,   445,   457,   477,   497,   517,
     537,   562,   588,   626,   645,   680,   686,   694,   706,   710,
     718,   724,   727,   728,   731,   734,   737,   740,   743,   744,
     746,   747,   748,   759,   764,   748,   821,   827,   833,   838,
     844,   865,   876,   881,   887,   887,   918,   919,   920,   922,
     923,   924,   925,   925,   936,   937,   939,   939,   946,   946,
     954,   956,   959,   959,   961,   966,   972,   978,   985,  1007,
    1028,  1028,  1037,  1037,  1046,  1048,  1053,  1061,  1060
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OR", "AND", "EQUAL", "LESS", "NOT_MORE",
  "NOT_LESS", "MORE", "NOT_EQUAL", "NOT", "SEMICOLON", "BOOLEAN", "BREAK",
  "CHAR", "CASE", "CLASS", "CONTINUE", "DEF", "DO", "ELSE", "EXIT",
  "BOOL_FALSE", "FLOAT", "FOR", "IF", "INT", "_NULL", "OBJECT", "PRINT",
  "PRINTLN", "READ", "REPEAT", "RETURN", "STRING", "TO", "BOOL_TRUE",
  "TYPE", "VAL", "VAR", "WHILE", "INT_VALUE", "FLOAT_VALUE", "BOOL_VALUE",
  "STRING_VALUE", "CHAR_VALUE", "ID", "'!'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "UMINUS", "'='", "':'", "'['", "']'", "'('", "')'", "'{'", "'}'",
  "','", "$accept", "declarations", "const_dec", "$@1", "$@2", "var_dec",
  "EXPR", "VALUE", "FUNC_TYPE", "DATA_TYPE", "zero_or_more_state",
  "methods", "method", "$@3", "$@4", "@5", "FUNC_BLOCK", "ARGS", "ARG",
  "FUNC_INVOCATION", "$@6", "STATEMENTS", "STATEMENT", "BLOCK", "$@7",
  "CONDITION", "IF_CONDITION", "$@8", "$@9", "ELSE_CONDITION", "LOOP",
  "WHILE_LOOP", "FOR_LOOP", "SIMPLE", "$@10", "$@11", "program", "$@12", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,    33,    43,
      45,    42,    47,    37,   303,    61,    58,    91,    93,    40,
      41,   123,   125,    44
};
# endif

#define YYPACT_NINF -100

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-100)))

#define YYTABLE_NINF -79

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -25,   -31,    65,  -100,  -100,    14,    21,    54,    85,    84,
      21,    21,    32,    61,    87,    -5,  -100,  -100,  -100,  -100,
     268,   254,   268,  -100,  -100,  -100,   254,  -100,  -100,  -100,
    -100,  -100,    88,  -100,  -100,  -100,  -100,  -100,   -42,   254,
     254,   254,   208,  -100,  -100,    -6,    89,   208,  -100,   100,
      90,    86,    95,     3,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   102,
    -100,   254,   106,   108,   264,  -100,   238,    86,    56,    56,
      56,    56,    56,    56,   110,   110,    95,    95,    95,   208,
     208,   114,   264,   208,  -100,  -100,   -27,   208,  -100,    26,
    -100,  -100,    39,   268,  -100,   264,   119,  -100,  -100,   268,
    -100,  -100,   113,    21,  -100,   239,   117,   128,  -100,  -100,
     130,   254,   129,    19,   135,  -100,   239,  -100,   177,  -100,
    -100,  -100,  -100,   157,   254,   254,   254,  -100,   208,   254,
     254,   254,  -100,  -100,    51,  -100,   200,    18,   208,   208,
     118,   208,   176,  -100,  -100,  -100,   158,   146,    51,   154,
      21,   254,    99,   159,  -100,  -100,   254,   239,   186,  -100,
    -100,   208,   161,   254,  -100,   150,    51,  -100,  -100
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    97,     1,     0,     4,     0,     0,     0,
       4,     4,     0,     9,     0,     0,    51,     2,     3,     5,
       0,     0,     0,    52,    98,    50,     0,    46,    43,    47,
      45,    44,     0,    36,    38,    37,    39,    40,    32,     0,
       0,     0,    11,    35,    16,    10,     0,     6,     7,     0,
       0,    25,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,     0,     0,     0,    59,    14,    23,    24,    30,    26,
      27,    29,    28,    31,    17,    18,    19,    20,    21,    15,
      12,     0,    59,     8,    33,    34,    32,    62,    35,     0,
      57,    13,     0,     0,    65,     0,    42,    60,    58,     0,
      54,    41,     0,     4,    55,    49,     0,     0,    90,    92,
       0,    95,     0,     0,     0,    48,    67,    70,    74,    71,
      82,    83,    69,     0,     0,     0,     0,    94,    96,     0,
       0,     0,    56,    66,     0,    75,     0,     0,    91,    93,
       0,    88,     0,    72,    81,    80,     0,    76,     0,     0,
       4,     0,     0,     0,    85,    84,     0,    68,     0,    77,
      79,    89,     0,     0,    73,     0,     0,    87,    86
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -100,    -9,  -100,  -100,  -100,  -100,   -21,     5,  -100,   -19,
    -100,  -100,   204,  -100,  -100,  -100,  -100,   132,   116,  -100,
    -100,   -95,  -100,   -99,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,  -100,   -96,  -100,  -100,  -100,  -100
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    26,    71,    11,    97,    43,   110,    32,
     124,    15,    16,    46,    92,   112,   114,    99,   100,    44,
      50,   125,   126,   154,   160,   127,   128,   162,   163,   145,
     129,   130,   131,   132,   135,   136,     2,     5
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    17,    18,    45,     1,    47,    54,    55,    56,    57,
      58,    59,    60,    61,    14,    49,     3,   -64,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,   103,
      49,   143,   -64,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,   155,    68,
      93,    69,    62,    63,    64,    65,    66,    24,    67,   164,
       7,     8,   165,    75,   170,     4,   169,    62,    63,    64,
      65,    66,   172,    67,   140,     6,   141,   177,   157,    98,
     178,   118,   119,   120,   107,   121,   104,    19,    20,   105,
     111,    56,    57,    58,    59,    60,    61,    98,   123,   106,
     138,    12,   105,    14,   115,    62,    63,    64,    65,    66,
      98,    67,   153,   147,   148,   149,    21,    22,   150,   151,
     152,    54,    55,    56,    57,    58,    59,    60,    61,   118,
     119,   120,    13,   121,    23,    62,    63,    64,    65,    66,
     168,    67,    72,    48,    91,   171,   123,    73,    70,    74,
      67,   167,   175,    54,    55,    56,    57,    58,    59,    60,
      61,    64,    65,    66,    94,    67,    95,    62,    63,    64,
      65,    66,   101,    67,   113,   109,   133,   137,   158,    54,
      55,    56,    57,    58,    59,    60,    61,   134,   139,    54,
      55,    56,    57,    58,    59,    60,    61,   142,   144,    62,
      63,    64,    65,    66,   146,    67,   156,   -78,   161,   166,
     176,    54,    55,    56,    57,    58,    59,    60,    61,    25,
     153,   108,   173,   174,   102,    62,    63,    64,    65,    66,
       0,    67,     0,     0,   159,    62,    63,    64,    65,    66,
       0,    67,    55,    56,    57,    58,    59,    60,    61,     0,
       0,     0,     0,     0,     0,     0,     0,    62,    63,    64,
      65,    66,     0,    67,   116,   117,     0,     0,     0,   118,
     119,   120,     0,   121,     0,     0,     0,     0,     0,     0,
     122,    27,     0,    28,     0,     0,   123,    62,    63,    64,
      65,    66,    29,    67,     0,    30,    33,    34,    35,    36,
      37,    38,    39,    31,    40,     0,    33,    34,    35,    36,
      37,    96,    39,    41,    40,     0,     0,     0,     0,     0,
       0,     0,     0,    41
};

static const yytype_int16 yycheck[] =
{
      21,    10,    11,    22,    29,    26,     3,     4,     5,     6,
       7,     8,     9,    10,    19,    57,    47,    59,    39,    40,
      41,     3,     4,     5,     6,     7,     8,     9,    10,    56,
      57,   126,    59,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,   144,    55,
      71,    57,    49,    50,    51,    52,    53,    62,    55,   158,
      39,    40,   158,    60,   163,     0,   162,    49,    50,    51,
      52,    53,   167,    55,    55,    61,    57,   176,    60,    74,
     176,    30,    31,    32,   103,    34,    60,    55,    56,    63,
     109,     5,     6,     7,     8,     9,    10,    92,    47,    60,
     121,    47,    63,    19,   113,    49,    50,    51,    52,    53,
     105,    55,    61,   134,   135,   136,    55,    56,   139,   140,
     141,     3,     4,     5,     6,     7,     8,     9,    10,    30,
      31,    32,    47,    34,    47,    49,    50,    51,    52,    53,
     161,    55,    42,    55,    42,   166,    47,    47,    59,    59,
      55,   160,   173,     3,     4,     5,     6,     7,     8,     9,
      10,    51,    52,    53,    58,    55,    58,    49,    50,    51,
      52,    53,    58,    55,    61,    56,    59,    47,    60,     3,
       4,     5,     6,     7,     8,     9,    10,    59,    59,     3,
       4,     5,     6,     7,     8,     9,    10,    62,    21,    49,
      50,    51,    52,    53,    47,    55,     6,    61,    50,    55,
      60,     3,     4,     5,     6,     7,     8,     9,    10,    15,
      61,   105,    36,    62,    92,    49,    50,    51,    52,    53,
      -1,    55,    -1,    -1,    58,    49,    50,    51,    52,    53,
      -1,    55,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    -1,    55,    25,    26,    -1,    -1,    -1,    30,
      31,    32,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    13,    -1,    15,    -1,    -1,    47,    49,    50,    51,
      52,    53,    24,    55,    -1,    27,    42,    43,    44,    45,
      46,    47,    48,    35,    50,    -1,    42,    43,    44,    45,
      46,    47,    48,    59,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    29,   100,    47,     0,   101,    61,    39,    40,    65,
      66,    69,    47,    47,    19,    75,    76,    65,    65,    55,
      56,    55,    56,    47,    62,    76,    67,    13,    15,    24,
      27,    35,    73,    42,    43,    44,    45,    46,    47,    48,
      50,    59,    70,    71,    83,    73,    77,    70,    55,    57,
      84,    70,    70,    70,     3,     4,     5,     6,     7,     8,
       9,    10,    49,    50,    51,    52,    53,    55,    55,    57,
      59,    68,    42,    47,    59,    60,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    42,    78,    70,    58,    58,    47,    70,    71,    81,
      82,    58,    81,    56,    60,    63,    60,    73,    82,    56,
      72,    73,    79,    61,    80,    65,    25,    26,    30,    31,
      32,    34,    41,    47,    74,    85,    86,    89,    90,    94,
      95,    96,    97,    59,    59,    98,    99,    47,    70,    59,
      55,    57,    62,    85,    21,    93,    47,    70,    70,    70,
      70,    70,    70,    61,    87,    97,     6,    60,    60,    58,
      88,    50,    91,    92,    87,    97,    55,    65,    70,    97,
      87,    70,    85,    36,    62,    70,    60,    87,    97
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    65,    65,    67,    66,    68,    66,    69,
      69,    69,    69,    69,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    71,    71,    71,    71,
      71,    72,    72,    73,    73,    73,    73,    73,    74,    74,
      75,    75,    77,    78,    79,    76,    80,    81,    81,    81,
      82,    82,    82,    82,    84,    83,    85,    85,    85,    86,
      86,    86,    88,    87,    89,    89,    91,    90,    92,    90,
      93,    93,    94,    94,    95,    95,    96,    96,    97,    97,
      98,    97,    99,    97,    97,    97,    97,   101,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     0,     5,     0,     7,     2,
       4,     4,     6,     7,     3,     3,     1,     3,     3,     3,
       3,     3,     2,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     1,     4,     4,     1,     1,     1,     1,     1,
       1,     2,     0,     1,     1,     1,     1,     1,     1,     0,
       2,     1,     0,     0,     0,    10,     4,     1,     3,     0,
       3,     1,     1,     1,     0,     5,     2,     1,     0,     1,
       1,     1,     0,     5,     1,     2,     0,     6,     0,     6,
       2,     2,     1,     1,     5,     5,    10,    10,     3,     6,
       0,     3,     0,     3,     2,     1,     2,     0,     7
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
        case 5:
#line 103 "yacc.y" /* yacc.c:1646  */
    {
			const_val = true;
		}
#line 1515 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 105 "yacc.y" /* yacc.c:1646  */
    {
			Trace("VAL ID = EXPR");
			int exist = all_table.table_list[table_index].lookup(*(yyvsp[-3].s_val));
			if(exist !=-1){
				yyerror("id already exist");
			}
			else //insert id
			{
				Identifier* put = new Identidier;
				put->idName = *(yyvsp[-3].s_val);
				put->idType = Const;
				put->idValue = (yyvsp[0].value); 
				InsertSymbol(put,all_table.table_list[table_index]);
				Trace("insert id val & value");
			}
		}
#line 1536 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 122 "yacc.y" /* yacc.c:1646  */
    {
			const_val = true;
		}
#line 1544 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 124 "yacc.y" /* yacc.c:1646  */
    {
			Trace("VAL ID :TYPE = EXPR");
			int exist = all_table.table_list[table_index].lookup(*(yyvsp[-5].s_val));
			if(exist !=-1){
				Trace("id already exist");
			}
			if((yyvsp[-3].valueType) != (yyvsp[0].value)->valueType){
				Trace("type different");
			}
			else //insert id
			{
				Identifier* put = new Identidier;
				put->idName = *(yyvsp[-5].s_val);
				put->idType = Const;
				put->idValue = (yyvsp[0].value); 
				InsertSymbol(put,all_table.table_list[table_index]);
				Trace("insert id val & type & value");
			}
		}
#line 1568 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 145 "yacc.y" /* yacc.c:1646  */
    {
			Trace("VAR ID");
			int exist = all_table.table_list[table_index].lookup(*(yyvsp[0].s_val));
			if(exist !=-1){
				yyerror("id already exist");
			}
			else //insert id
			{
				int check = all_table.lookup_all(*(yyvsp[0].s_val));
				Identifier* put = new Identidier;
				put->idName = *(yyvsp[0].s_val);
				put->idType = Var; 
				Trace("insert id var");
				//global
				//cout<<"check:"<<check<<endl;
				if(table_index==0){
					java<<"\tfield static int "<<*(yyvsp[0].s_val)<<endl;
				}
				else{
					java_push(0);
					put->index = now_stack;
					java_store(now_stack++);
				}
				InsertSymbol(put,all_table.table_list[table_index]);
			}
		}
#line 1599 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 172 "yacc.y" /* yacc.c:1646  */
    {
			Trace("VAR ID:TYPE");
			int exist = all_table.table_list[table_index].lookup(*(yyvsp[-2].s_val));
			if(exist !=-1){
				yyerror("id already exist");
			}
			else //insert id
			{
				int check = all_table.lookup_all(*(yyvsp[-2].s_val));
				Identifier* put = new Identidier;
				put->idName = *(yyvsp[-2].s_val);
				put->idType = Var; 
				put->idValue = new Value;
				put->idValue->valueType = (yyvsp[0].valueType);
				Trace("insert id var & type");
				//global
				if(table_index==0){
					java<<"\tfield static int "<<*(yyvsp[-2].s_val)<<endl;
				}
				else{
					java_push(0);
					put->index = now_stack;
					java_store(now_stack++);
				}
				InsertSymbol(put,all_table.table_list[table_index]);
			}
		}
#line 1631 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 200 "yacc.y" /* yacc.c:1646  */
    {
			Trace("VAR ID=EXPR");
			int exist = all_table.table_list[table_index].lookup(*(yyvsp[-2].s_val));
			if(exist !=-1){
				yyerror("id already exist");
			}
			else //insert id
			{
				int check = all_table.lookup_all(*(yyvsp[-2].s_val));
				Identifier* put = new Identidier;
				put->idName = *(yyvsp[-2].s_val);
				put->idType = Var; 
				put->idValue = (yyvsp[0].value);
				Trace("insert id va & value");
				//global
				if(table_index==0){
					java<<"\tfield static int "<<*(yyvsp[-2].s_val)<<" = "<<(yyvsp[0].value)->i_value<<endl;
				}
				else{
					put->index = now_stack;
					java_store(now_stack++);
				}
				InsertSymbol(put,all_table.table_list[table_index]);
			}
		}
#line 1661 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 226 "yacc.y" /* yacc.c:1646  */
    {
			Trace("VAL ID :TYPE = EXPR");
			int exist = all_table.table_list[table_index].lookup(*(yyvsp[-4].s_val));
			if(exist !=-1){
				yyerror("id already exist");
			}else{
				if((yyvsp[-2].valueType) != (yyvsp[0].value)->valueType){
					Trace("type different");
				}
				else //insert id
				{
					int check = all_table.lookup_all(*(yyvsp[-4].s_val));
					Identifier* put = new Identidier;
					put->idName = *(yyvsp[-4].s_val);
					put->idType = Var;
					put->idValue = (yyvsp[0].value); 
					Trace("insert id var & type & value");
					//global
					if(table_index==0){
						java<<"\tfield static int "<<*(yyvsp[-4].s_val)<<" = "<<(yyvsp[0].value)->i_value<<endl;
					}
					else{
						put->index = now_stack;
						java_store(now_stack++);
					}
					InsertSymbol(put,all_table.table_list[table_index]);
				}
			}
		}
#line 1695 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 257 "yacc.y" /* yacc.c:1646  */
    {
			Trace("VAL ID :TYPE = EXPR");
			int exist = all_table.table_list[table_index].lookup(*(yyvsp[-5].s_val));
			if((yyvsp[-1].i_val)<1){
				yyerror("Array length error");
			}
			else if(exist !=-1){
				Trace("id already exist");
			}
			else //insert id
			{
				Identifier* put = new Identidier;
				put->idName = *(yyvsp[-5].s_val);
				put->idType = Array;
				put->arraySize = (yyvsp[-1].i_val); 
				put->arrayValueType = (yyvsp[-3].valueType);
				for (int i = 0; i < put->arraySize; i++)
    				{
					Value* tmp = new Value;
					tmp->valueType = (yyvsp[-3].valueType);
        				put->arrayValue.push_back(tmp);
    				}
				InsertSymbol(put,all_table.table_list[table_index]);
				Trace("insert id(array)");
			}

			
		}
#line 1728 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 286 "yacc.y" /* yacc.c:1646  */
    {
			(yyval.value)=(yyvsp[-1].value);
		}
#line 1736 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 288 "yacc.y" /* yacc.c:1646  */
    {
			Trace("EXPR = EXPR");
			Value* put =new Value;
			if((yyvsp[-2].value)->valueType==intType && (yyvsp[0].value)->valueType==intType){
           			put->valueType = intType;
            			put->i_value = ((yyvsp[-2].value)->i_value + (yyvsp[0].value)->i_value);
        		}else if((yyvsp[-2].value)->valueType==intType && (yyvsp[0].value)->valueType==floatType){
           			put->valueType = floatType;
            			put->f_value = ((float)(yyvsp[-2].value)->i_value + (yyvsp[0].value)->f_value);
        		}else if((yyvsp[-2].value)->valueType==floatType && (yyvsp[0].value)->valueType==intType){
           			put->valueType = floatType;
            			put->f_value = ((yyvsp[-2].value)->f_value + (float)(yyvsp[0].value)->i_value);
        		}else if((yyvsp[-2].value)->valueType==floatType && (yyvsp[0].value)->valueType==floatType){
           			put->valueType = floatType;
            			put->f_value = ((yyvsp[-2].value)->f_value + (yyvsp[0].value)->f_value);
        		}else
				{yyerror("assign type error");}
			(yyval.value)=put;
		}
#line 1760 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 306 "yacc.y" /* yacc.c:1646  */
    {
			Trace("into call function");
		}
#line 1768 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 308 "yacc.y" /* yacc.c:1646  */
    {
			Trace("EXPR + EXPR");
			Value* put =new Value;
			if((yyvsp[-2].value)->valueType==intType && (yyvsp[0].value)->valueType==intType){
           			put->valueType = intType;
            			put->i_value = ((yyvsp[-2].value)->i_value + (yyvsp[0].value)->i_value);
        		}else if((yyvsp[-2].value)->valueType==intType && (yyvsp[0].value)->valueType==floatType){
           			put->valueType = floatType;
            			put->f_value = ((float)(yyvsp[-2].value)->i_value + (yyvsp[0].value)->f_value);
        		}else if((yyvsp[-2].value)->valueType==floatType && (yyvsp[0].value)->valueType==intType){
           			put->valueType = floatType;
            			put->f_value = ((yyvsp[-2].value)->f_value + (float)(yyvsp[0].value)->i_value);
        		}else if((yyvsp[-2].value)->valueType==floatType && (yyvsp[0].value)->valueType==floatType){
           			put->valueType = floatType;
            			put->f_value = ((yyvsp[-2].value)->f_value + (yyvsp[0].value)->f_value);
        		}else
				{yyerror("add type error");}
			(yyval.value)=put;
			java << "\t\tiadd" << endl;
		}
#line 1793 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 327 "yacc.y" /* yacc.c:1646  */
    {
			Trace("EXPR - EXPR");
			Value* put =new Value;
			if((yyvsp[-2].value)->valueType==intType && (yyvsp[0].value)->valueType==intType){
           			put->valueType = intType;
            			put->i_value = ((yyvsp[-2].value)->i_value - (yyvsp[0].value)->i_value);
        		}else if((yyvsp[-2].value)->valueType==intType && (yyvsp[0].value)->valueType==floatType){
           			put->valueType = floatType;
            			put->f_value = ((float)(yyvsp[-2].value)->i_value - (yyvsp[0].value)->f_value);
        		}else if((yyvsp[-2].value)->valueType==floatType && (yyvsp[0].value)->valueType==intType){
           			put->valueType = floatType;
            			put->f_value = ((yyvsp[-2].value)->f_value - (float)(yyvsp[0].value)->i_value);
        		}else if((yyvsp[-2].value)->valueType==floatType && (yyvsp[0].value)->valueType==floatType){
           			put->valueType = floatType;
            			put->f_value = ((yyvsp[-2].value)->f_value - (yyvsp[0].value)->f_value);
        		}else{
				yyerror("minus type error");
			}
			(yyval.value)=put;
			java << "\t\tisub" << endl;
		}
#line 1819 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 347 "yacc.y" /* yacc.c:1646  */
    {
			Trace("EXPR * EXPR");
			Value* put =new Value;
			if((yyvsp[-2].value)->valueType==intType && (yyvsp[0].value)->valueType==intType){
           			put->valueType = intType;
            			put->i_value = ((yyvsp[-2].value)->i_value * (yyvsp[0].value)->i_value);
        		}else if((yyvsp[-2].value)->valueType==intType && (yyvsp[0].value)->valueType==floatType){
           			put->valueType = floatType;
            			put->f_value = ((float)(yyvsp[-2].value)->i_value * (yyvsp[0].value)->f_value);
        		}else if((yyvsp[-2].value)->valueType==floatType && (yyvsp[0].value)->valueType==intType){
           			put->valueType = floatType;
            			put->f_value = ((yyvsp[-2].value)->f_value * (float)(yyvsp[0].value)->i_value);
        		}else if((yyvsp[-2].value)->valueType==floatType && (yyvsp[0].value)->valueType==floatType){
           			put->valueType = floatType;
            			put->f_value = ((yyvsp[-2].value)->f_value * (yyvsp[0].value)->f_value);
        		}else{
				yyerror("product type error");
			}
			(yyval.value)=put;
			java << "\t\timul" << endl;
		}
#line 1845 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 367 "yacc.y" /* yacc.c:1646  */
    {
			Trace("EXPR / EXPR");
			Value* put =new Value;
			if((yyvsp[-2].value)->valueType==intType && (yyvsp[0].value)->valueType==intType){
           			put->valueType = intType;
            			put->i_value = ((yyvsp[-2].value)->i_value / (yyvsp[0].value)->i_value);
        		}else if((yyvsp[-2].value)->valueType==intType && (yyvsp[0].value)->valueType==floatType){
           			put->valueType = floatType;
            			put->f_value = ((float)(yyvsp[-2].value)->i_value / (yyvsp[0].value)->f_value);
        		}else if((yyvsp[-2].value)->valueType==floatType && (yyvsp[0].value)->valueType==intType){
           			put->valueType = floatType;
            			put->f_value = ((yyvsp[-2].value)->f_value / (float)(yyvsp[0].value)->i_value);
        		}else if((yyvsp[-2].value)->valueType==floatType && (yyvsp[0].value)->valueType==floatType){
           			put->valueType = floatType;
            			put->f_value = ((yyvsp[-2].value)->f_value / (yyvsp[0].value)->f_value);
        		}else{
				yyerror("divide type error");
			}
			(yyval.value)=put;
			java << "\t\tidiv" << endl;
		}
#line 1871 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 387 "yacc.y" /* yacc.c:1646  */
    {
			Trace("EXPR mod EXPR");
			Value* put =new Value;
			if((yyvsp[-2].value)->valueType==intType && (yyvsp[0].value)->valueType==intType){
           			put->valueType = intType;
            			put->i_value = ((yyvsp[-2].value)->i_value % (yyvsp[0].value)->i_value);
        		}else if((yyvsp[-2].value)->valueType==intType && (yyvsp[0].value)->valueType==floatType){
           			put->valueType = floatType;
            			put->f_value = fmod((double)(yyvsp[-2].value)->i_value,(double)(yyvsp[0].value)->f_value);
        		}else if((yyvsp[-2].value)->valueType==floatType && (yyvsp[0].value)->valueType==intType){
           			put->valueType = floatType;
            			put->f_value = fmod((double)(yyvsp[-2].value)->f_value,(double)(yyvsp[0].value)->i_value);
        		}else if((yyvsp[-2].value)->valueType==floatType && (yyvsp[0].value)->valueType==floatType){
           			put->valueType = floatType;
            			put->f_value = fmod((double)(yyvsp[-2].value)->f_value,(double)(yyvsp[0].value)->f_value);
        		}else
				yyerror("mod type error");
			(yyval.value)=put;
		}
#line 1895 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 405 "yacc.y" /* yacc.c:1646  */
    {
        		Trace("- EXPR");
        		Value* put = new Value;
        		if ((yyvsp[0].value)->valueType== intType) {
        		    	*put = *(yyvsp[0].value);
        		    	put->i_value = -1 * put->i_value;
        		}
        		else if((yyvsp[0].value)->valueType== floatType){
        		    	*put = *(yyvsp[0].value);
        		    	put->f_value = -1 * put->f_value;
        		}
        		else{
        		    yyerror("- EXPR type error");
        		}
        		(yyval.value) = put;
			java << "\t\tineg" << endl;	
		}
#line 1917 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 421 "yacc.y" /* yacc.c:1646  */
    {
			Trace("EXPR OR EXPR");
        		Value* put = new Value;
       		 	put->valueType = boolType;
        		if((yyvsp[-2].value)->valueType!=boolType || (yyvsp[0].value)->valueType!=boolType){
            		yyerror("OR operation must be bool");
        		}
        		else{
         		  put->b_value = (yyvsp[-2].value)->b_value || (yyvsp[0].value)->b_value;
        		}
        		(yyval.value) = put;
			java << "\t\tior" << endl;
		}
#line 1935 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 433 "yacc.y" /* yacc.c:1646  */
    {
			Trace("EXPR AND EXPR");
        		Value* put = new Value;
       		 	put->valueType = boolType;
        		if((yyvsp[-2].value)->valueType!=boolType || (yyvsp[0].value)->valueType!=boolType){
            		yyerror("AND operation must be bool");
        		}
        		else{
         		  put->b_value = (yyvsp[-2].value)->b_value && (yyvsp[0].value)->b_value;
        		}
        		(yyval.value) = put;
			java << "\t\tiand" << endl;
		}
#line 1953 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 445 "yacc.y" /* yacc.c:1646  */
    {
			Trace("NOT EXPR");
        		Value* put = new Value;
       		 	put->valueType = boolType;
        		if((yyvsp[0].value)->valueType!=boolType){
            		yyerror("NOT operation must be bool");
        		}
        		else{
         		  put->b_value = !((yyvsp[0].value)->b_value);
        		}
        		(yyval.value) = put;
			java << "\t\tldc 1" << endl << "\t\tixor" << endl;
		}
#line 1971 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 457 "yacc.y" /* yacc.c:1646  */
    {
			Trace("EXPR < EXPR");
			Value* put = new Value;
       		 	put->valueType = boolType;
			if((yyvsp[-2].value)->valueType==intType&&(yyvsp[0].value)->valueType==intType)
			{
				put->b_value=((yyvsp[-2].value)->i_value<(yyvsp[0].value)->i_value);
			}else if((yyvsp[-2].value)->valueType==intType&&(yyvsp[0].value)->valueType==floatType)
			{
				put->b_value=((float)(yyvsp[-2].value)->i_value<(yyvsp[0].value)->f_value);
			}else if((yyvsp[-2].value)->valueType==floatType&&(yyvsp[0].value)->valueType==intType)
			{
				put->b_value=((yyvsp[-2].value)->f_value<(float)(yyvsp[0].value)->i_value);
			}else if((yyvsp[-2].value)->valueType==floatType&&(yyvsp[0].value)->valueType==floatType)
			{
				put->b_value=((yyvsp[-2].value)->f_value<(yyvsp[0].value)->f_value);
			}else
				yyerror("< operator type error");
			(yyval.value) =put;
			java << "\t\tiflt" << endl;
		}
#line 1997 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 477 "yacc.y" /* yacc.c:1646  */
    {
			Trace("EXPR <= EXPR");
			Value* put = new Value;
       		 	put->valueType = boolType;
			if((yyvsp[-2].value)->valueType==intType&&(yyvsp[0].value)->valueType==intType)
			{
				put->b_value=((yyvsp[-2].value)->i_value<=(yyvsp[0].value)->i_value);
			}else if((yyvsp[-2].value)->valueType==intType&&(yyvsp[0].value)->valueType==floatType)
			{
				put->b_value=((float)(yyvsp[-2].value)->i_value<=(yyvsp[0].value)->f_value);
			}else if((yyvsp[-2].value)->valueType==floatType&&(yyvsp[0].value)->valueType==intType)
			{
				put->b_value=((yyvsp[-2].value)->f_value<=(float)(yyvsp[0].value)->i_value);
			}else if((yyvsp[-2].value)->valueType==floatType&&(yyvsp[0].value)->valueType==floatType)
			{
				put->b_value=((yyvsp[-2].value)->f_value<=(yyvsp[0].value)->f_value);
			}else
				yyerror("<= operator type error");
			(yyval.value) =put;
			java << "\t\tifle" << endl;
		}
#line 2023 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 497 "yacc.y" /* yacc.c:1646  */
    {
			Trace("EXPR > EXPR");
			Value* put = new Value;
       		 	put->valueType = boolType;
			if((yyvsp[-2].value)->valueType==intType&&(yyvsp[0].value)->valueType==intType)
			{
				put->b_value=((yyvsp[-2].value)->i_value>(yyvsp[0].value)->i_value);
			}else if((yyvsp[-2].value)->valueType==intType&&(yyvsp[0].value)->valueType==floatType)
			{
				put->b_value=((float)(yyvsp[-2].value)->i_value>(yyvsp[0].value)->f_value);
			}else if((yyvsp[-2].value)->valueType==floatType&&(yyvsp[0].value)->valueType==intType)
			{
				put->b_value=((yyvsp[-2].value)->f_value>(float)(yyvsp[0].value)->i_value);
			}else if((yyvsp[-2].value)->valueType==floatType&&(yyvsp[0].value)->valueType==floatType)
			{
				put->b_value=((yyvsp[-2].value)->f_value>(yyvsp[0].value)->f_value);
			}else
				yyerror("> operator type error");
			(yyval.value) =put;
			java << "\t\tifgt" << endl;
		}
#line 2049 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 517 "yacc.y" /* yacc.c:1646  */
    {
			Trace("EXPR >= EXPR");
			Value* put = new Value;
       		 	put->valueType = boolType;
			if((yyvsp[-2].value)->valueType==intType&&(yyvsp[0].value)->valueType==intType)
			{
				put->b_value=((yyvsp[-2].value)->i_value>=(yyvsp[0].value)->i_value);
			}else if((yyvsp[-2].value)->valueType==intType&&(yyvsp[0].value)->valueType==floatType)
			{
				put->b_value=((float)(yyvsp[-2].value)->i_value>=(yyvsp[0].value)->f_value);
			}else if((yyvsp[-2].value)->valueType==floatType&&(yyvsp[0].value)->valueType==intType)
			{
				put->b_value=((yyvsp[-2].value)->f_value>=(float)(yyvsp[0].value)->i_value);
			}else if((yyvsp[-2].value)->valueType==floatType&&(yyvsp[0].value)->valueType==floatType)
			{
				put->b_value=((yyvsp[-2].value)->f_value>=(yyvsp[0].value)->f_value);
			}else
				yyerror(">= operator type error");
			(yyval.value) =put;
			java << "\t\tifge" << endl;
		}
#line 2075 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 537 "yacc.y" /* yacc.c:1646  */
    {
			Trace("EXPR == EXPR");
			Value* put = new Value;
       		 	put->valueType = boolType;
			if((yyvsp[-2].value)->valueType!=(yyvsp[0].value)->valueType){
				yyerror("== operator type not equal");
			}else if((yyvsp[-2].value)->valueType==intType&&(yyvsp[0].value)->valueType==intType)
			{
				put->b_value=((yyvsp[-2].value)->i_value==(yyvsp[0].value)->i_value);
			}else if((yyvsp[-2].value)->valueType==floatType&&(yyvsp[0].value)->valueType==floatType)
			{
				put->b_value=((yyvsp[-2].value)->f_value==(yyvsp[0].value)->f_value);
			}else if((yyvsp[-2].value)->valueType==boolType&&(yyvsp[0].value)->valueType==boolType)
			{
				put->b_value=((yyvsp[-2].value)->b_value==(yyvsp[0].value)->b_value);
			}else if((yyvsp[-2].value)->valueType==stringType&&(yyvsp[0].value)->valueType==stringType)
			{
				put->b_value=(*((yyvsp[-2].value)->s_value)==*((yyvsp[0].value)->s_value));
			}else if((yyvsp[-2].value)->valueType==charType&&(yyvsp[0].value)->valueType==charType)
			{
				put->b_value=(((yyvsp[-2].value)->c_value)==((yyvsp[0].value)->c_value));
			}else
				yyerror("== operator type error");
			(yyval.value)=put;
			java << "\t\tifeq" << endl;
		}
#line 2106 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 562 "yacc.y" /* yacc.c:1646  */
    {
			Trace("EXPR != EXPR");
			Value* put = new Value;
       		 	put->valueType = boolType;
			if((yyvsp[-2].value)->valueType!=(yyvsp[0].value)->valueType){
				//cout<<"$1Type:"<<$1->valueType<<"$3Type:"<<$3->valueType<<endl;
				yyerror("!= operator type not equal");
			}else if((yyvsp[-2].value)->valueType==intType&&(yyvsp[0].value)->valueType==intType)
			{
				put->b_value=((yyvsp[-2].value)->i_value!=(yyvsp[0].value)->i_value);
			}else if((yyvsp[-2].value)->valueType==floatType&&(yyvsp[0].value)->valueType==floatType)
			{
				put->b_value=((yyvsp[-2].value)->f_value!=(yyvsp[0].value)->f_value);
			}else if((yyvsp[-2].value)->valueType==boolType&&(yyvsp[0].value)->valueType==boolType)
			{
				put->b_value=((yyvsp[-2].value)->b_value!=(yyvsp[0].value)->b_value);
			}else if((yyvsp[-2].value)->valueType==stringType&&(yyvsp[0].value)->valueType==stringType)
			{
				put->b_value=(*((yyvsp[-2].value)->s_value)!=*((yyvsp[0].value)->s_value));
			}else if((yyvsp[-2].value)->valueType==charType&&(yyvsp[0].value)->valueType==charType)
			{
				put->b_value=(((yyvsp[-2].value)->c_value)!=((yyvsp[0].value)->c_value));
			}else
				yyerror("!= operator type error");
			(yyval.value)=put;
			java << "\t\tifne" << endl;
		}
#line 2138 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 588 "yacc.y" /* yacc.c:1646  */
    {
			Trace("find a ID");
			int exist = all_table.lookup_all(*(yyvsp[0].s_val));
			if(exist ==-1){
				Trace("id not exist");
			}
			else //take id info
 			{
				int pos = all_table.table_list[exist].lookup(*(yyvsp[0].s_val));
				Identifier* put = all_table.table_list[exist].idList[pos];
				if(put->idType == Array)
				{
					yyerror("expr assign id type is Array");
				}else if(put->idType == Object)
				{
					yyerror("expr assign id type is Object");
				}else
				{
					(yyval.value)=put->idValue;
					Trace("assign id value to expr");
				}
				if(exist==IsGLOBAL){
					if(put->idType == Const){
						if(put->idValue->valueType == intType)
							{java_push(put->idValue->i_value);}
						else if(put->idValue->valueType == boolType){
							if(put->idValue->b_value){
								java<<"\t\ticonst_1"<<endl;
							}
							else{java<<"\t\ticonst_0"<<endl;}
						}
					}else if(put->idType == Var){
						java << "\t\tgetstatic int " << now_class << "." << *(yyvsp[0].s_val) << endl;
					}
				}else{
					java_load(put->index);
				}
			}
		}
#line 2182 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 626 "yacc.y" /* yacc.c:1646  */
    {
			Trace("find a Value(id[int])");
			int exist = all_table.lookup_all(*(yyvsp[-3].s_val));
			if(exist ==-1){
				Trace("id not exist");
			}
			else //take id info
 			{
				int pos = all_table.table_list[exist].lookup(*(yyvsp[-3].s_val));
				Identifier* put = all_table.table_list[exist].idList[pos];
				if(put->idType != Array)
				{
					yyerror("expr assign id type must be Array");
				}else
				{
					(yyval.value)=put->arrayValue[(yyvsp[-1].i_val)];
					Trace("assign id array value to expr");
				}
			}
		}
#line 2207 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 645 "yacc.y" /* yacc.c:1646  */
    {
			Trace("find a Value(id[int])");
			int exist = all_table.lookup_all(*(yyvsp[-3].s_val));
			if(exist ==-1){
				Trace("id not exist");
			}
			else //take id info
 			{
				//a[b]
				int pos = all_table.table_list[exist].lookup(*(yyvsp[-3].s_val));
				Identifier* put = all_table.table_list[exist].idList[pos];//a
				if(put->idType != Array)
				{
					yyerror("expr assign id type must be Array");//b
				}else
				{
					int exist = all_table.lookup_all(*(yyvsp[-1].s_val));
					if(exist ==-1){
						Trace("array index id not exist");
					}
					else{
						int pos = all_table.table_list[exist].lookup(*(yyvsp[-1].s_val));
						Identifier* tmp = all_table.table_list[exist].idList[pos];
						if (tmp->idValue->valueType!=intType){
							Trace("index must be integer");
						}
						else{
							(yyval.value)=put->arrayValue[tmp->idValue->i_value];
							Trace("assign id array value to expr");
						}
						
					}
				}
			}
		}
#line 2247 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 680 "yacc.y" /* yacc.c:1646  */
    {
			(yyval.value)=(yyvsp[0].value);
		}
#line 2255 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 686 "yacc.y" /* yacc.c:1646  */
    {
				Trace("find a int value");
				(yyval.value) = intValue((yyvsp[0].i_val));
				if(!const_val){
					java_push((yyvsp[0].i_val));
				}
				const_val = false;
			}
#line 2268 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 694 "yacc.y" /* yacc.c:1646  */
    {
				Trace("find a bool value");
				(yyval.value) = boolValue((yyvsp[0].b_val));
				if(!const_val){
					if((yyvsp[0].b_val)){
						java<<"\t\ticonst_1"<<endl;
					}else{
						java<<"\t\ticonst_0"<<endl;
					}	
				}
				const_val = false;
			}
#line 2285 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 706 "yacc.y" /* yacc.c:1646  */
    {
				Trace("find a float value");
				(yyval.value) = floatValue((yyvsp[0].f_val));
			}
#line 2294 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 710 "yacc.y" /* yacc.c:1646  */
    {
				Trace("find a string value");
				(yyval.value) = stringValue((yyvsp[0].s_val));
				if(!const_val){
					java << "\t\tldc " << "\"" << *(yyvsp[0].s_val) << "\"" << endl;
				}
				const_val = false;
			}
#line 2307 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 718 "yacc.y" /* yacc.c:1646  */
    {
				Trace("find a char value");
				(yyval.value) = charValue((yyvsp[0].c_val));
			}
#line 2316 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 724 "yacc.y" /* yacc.c:1646  */
    {
			Trace("function has return type");
			(yyval.valueType) = (yyvsp[0].valueType);
		}
#line 2325 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 727 "yacc.y" /* yacc.c:1646  */
    {(yyval.valueType) = valueTypeError;}
#line 2331 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 728 "yacc.y" /* yacc.c:1646  */
    {
           	 	(yyval.valueType) = charType;
       	  	}
#line 2339 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 731 "yacc.y" /* yacc.c:1646  */
    {
          	 	(yyval.valueType) = stringType;
         	}
#line 2347 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 734 "yacc.y" /* yacc.c:1646  */
    {
             	 	(yyval.valueType) = intType;
         	}
#line 2355 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 737 "yacc.y" /* yacc.c:1646  */
    {
             	 	(yyval.valueType) = boolType;
         	}
#line 2363 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 740 "yacc.y" /* yacc.c:1646  */
    {
            		(yyval.valueType) = floatType;
         	}
#line 2371 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 748 "yacc.y" /* yacc.c:1646  */
    {
			has_return = false;
			Trace("Method ID");
			int exist = all_table.table_list[table_index].lookup(*(yyvsp[0].s_val));
			if(exist !=-1&&all_table.table_list[table_index].idList[exist]->idType==Function){
				yyerror("method id already exist");
			}
			else{
				java<<"\tmethod public static ";
				funcName = *(yyvsp[0].s_val);
			}
		}
#line 2388 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 759 "yacc.y" /* yacc.c:1646  */
    {
			Trace("FUNC_BLOCK start");
			SymbolTable put = SymbolTable();
			table_index++;
			all_table.push();
		}
#line 2399 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 764 "yacc.y" /* yacc.c:1646  */
    {
			(yyval.idType) = (yyvsp[-2].idType);
			(yyval.idType)->funType = (yyvsp[0].valueType);
			Trace("before FUNC_BLOCK");
			if((yyval.idType)->funType == valueTypeError){
				java<<"void ";
			}else{
				//cout<<$<idType>$->funType<<endl;
				java<<valueType2String((yyval.idType)->funType)<<" ";
			}
			//name
			java<<funcName;
			//no args
			if((yyval.idType)->numOfPara == 0){
				java<<"(java.lang.String[])"<<endl;
				java<<"\tmax_stack 15"<<endl;
				java<<"\tmax_locals 15"<<endl;
			}else{
				//print args
				java<<"(";
				for(int i = 0;i<(yyval.idType)->numOfPara;i++){
					if(i==(yyval.idType)->numOfPara-1){
						java<<valueType2String((yyval.idType)->parameters[i]->idValue->valueType)<<")"<<endl;
					}else{
						java<<valueType2String((yyval.idType)->parameters[i]->idValue->valueType)<<",";
					}
				}
				java<<"\tmax_stack 15"<<endl;
				java<<"\tmax_locals 15"<<endl;
			}
			java<<"\t{"<<endl;
			/*cout<<$6->numOfPara<<endl;
			cout<<$6->parameters[0]->idName<<endl;
			cout<<$6->parameters[1]->idName<<endl;
			for(int i=0;i<$6->numOfPara;i++){
				int check = all_table.lookup_all($6->parameters[i]->idName);
				if(check == IsGLOBAL){
            				java << "\t\tgetstatic int " <<funcName<<"." <<$6->parameters[i]->idName <<  endl;
       				}
       				else{
           				java_load($6->parameters[i]->index);
        			}
			}*/
		}
#line 2448 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 807 "yacc.y" /* yacc.c:1646  */
    {	
			Trace("done FUNC_BLOCK");
			Identifier* put = (yyvsp[-4].idType);
			put->idName = *(yyvsp[-8].s_val);
			put->funType = (yyvsp[-2].valueType);
			cout<<put->numOfPara<<endl;
			InsertSymbol(put,all_table.table_list[table_index]);
			if((put->funType != valueTypeError )&& (!has_return)){
				java<<"\t\treturn"<<endl;
			}
			java<<"\t}"<<endl;
			Trace("insert ok");
		}
#line 2466 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 821 "yacc.y" /* yacc.c:1646  */
    {
			all_table.table_list[table_index].dump();
			all_table.pop();
			table_index--;
		}
#line 2476 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 827 "yacc.y" /* yacc.c:1646  */
    {
			Identifier* put = (yyvsp[0].idType);
			put->parameters.push_back((yyvsp[0].idType));
			put->numOfPara++;
			(yyval.idType)=put;
		}
#line 2487 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 833 "yacc.y" /* yacc.c:1646  */
    {
			Identifier* put = (yyvsp[-2].idType);
			put->parameters.push_back((yyvsp[0].idType));
			put->numOfPara++;
			(yyvsp[-2].idType)=put;
		}
#line 2498 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 838 "yacc.y" /* yacc.c:1646  */
    {
			Identifier* put =new Identifier;
			put->idType = Function;
			(yyval.idType) = put;
			cout<<(yyval.idType)->idType<<endl;
		}
#line 2509 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 844 "yacc.y" /* yacc.c:1646  */
    {
			int exist = all_table.table_list[table_index].lookup(*(yyvsp[-2].s_val));
			if(exist != -1){
				yyerror("id already exist");
			}else{
				Identifier* put = new Identifier;
				put->idName = *(yyvsp[-2].s_val);
				put->idValue = new Value;
				put->idType = Var;
				put->idValue->valueType = (yyvsp[0].valueType);
				if(exist == IsGLOBAL){
            				
       				}
       				else{
            				put->index = now_stack;
					now_stack++;
        			}
				Trace("insert id(argument)");
				InsertSymbol(put,all_table.table_list[table_index]);
				(yyval.idType)=put;
			}
		}
#line 2536 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 865 "yacc.y" /* yacc.c:1646  */
    {
			Trace("arg = id");
			int exist = all_table.lookup_all(*(yyvsp[0].s_val));
			if(exist ==-1)
				yyerror("arg not exist");
			else 
			{	
				int pos = all_table.table_list[exist].lookup(*(yyvsp[0].s_val));
				Identifier* put = all_table.table_list[exist].idList[pos];
				(yyval.idType)=put;
			}
		}
#line 2553 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 876 "yacc.y" /* yacc.c:1646  */
    {
			Trace("arg = expr");
			Identifier* put = new Identifier;
			put->idValue=(yyvsp[0].value);
			(yyval.idType) = put;
		}
#line 2564 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 881 "yacc.y" /* yacc.c:1646  */
    {
			Trace("arg = value");
			Identifier* put = new Identifier;
			put->idValue=(yyvsp[0].value);
			(yyval.idType)=put;
		}
#line 2575 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 887 "yacc.y" /* yacc.c:1646  */
    {
				Trace("start call function");
			}
#line 2583 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 889 "yacc.y" /* yacc.c:1646  */
    {
				Trace("call function done");
				int exist = all_table.lookup_all(*(yyvsp[-4].s_val));
				cout<<"$1="<<*(yyvsp[-4].s_val)<<endl;
				if(exist ==-1)
					yyerror("function not exist");
				else //insert id
				{	
					int pos = all_table.table_list[exist].lookup(*(yyvsp[-4].s_val));
					Identifier* put = all_table.table_list[exist].idList[pos];
					if(put->idType!=Function){
						yyerror("type must be function");
					}else{
						if(put->numOfPara!=(yyvsp[-1].idType)->numOfPara)
						{
							yyerror("argument number must be the same");
						}
						else{
							for(int i=0;i<put->numOfPara;i++){
								if(put->parameters[i]->idValue->valueType!=(yyvsp[-1].idType)->parameters[i]->idValue->valueType){
									yyerror("argument type error");
								}
							}
							(yyval.value)= put->idValue;
							(yyval.value)->valueType = put->funType;
						}
					}
				}
			}
#line 2617 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 923 "yacc.y" /* yacc.c:1646  */
    {Trace("exit Condition");}
#line 2623 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 924 "yacc.y" /* yacc.c:1646  */
    {Trace("into Loop");}
#line 2629 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 925 "yacc.y" /* yacc.c:1646  */
    {
			Trace("BLOCK start");
			SymbolTable put = SymbolTable();
			table_index++;
			all_table.push();
		}
#line 2640 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 930 "yacc.y" /* yacc.c:1646  */
    {
			Trace("BLOCK end");
			all_table.table_list[table_index].dump();
			all_table.pop();
			table_index--;
		}
#line 2651 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 939 "yacc.y" /* yacc.c:1646  */
    {
			Trace("IF condition");
			if((yyvsp[-1].value)->valueType!=boolType){
				yyerror("if condition expr must be bool");
			}
		}
#line 2662 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 944 "yacc.y" /* yacc.c:1646  */
    {
			Trace("if with simple");
		}
#line 2670 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 946 "yacc.y" /* yacc.c:1646  */
    {
			Trace("IF condition");
				if((yyvsp[-1].value)->valueType!=boolType){
				yyerror("if condition expr must be bool");
			}
		}
#line 2681 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 951 "yacc.y" /* yacc.c:1646  */
    {
			Trace("if with block");
		}
#line 2689 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 954 "yacc.y" /* yacc.c:1646  */
    {
			Trace("else with simple");
		}
#line 2697 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 956 "yacc.y" /* yacc.c:1646  */
    {
			Trace("else with block");
		}
#line 2705 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 961 "yacc.y" /* yacc.c:1646  */
    {
			Trace("while loop with simple");
			if((yyvsp[-2].value)->valueType!=boolType){
				yyerror("while loop expr must be bool");
			}
		}
#line 2716 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 966 "yacc.y" /* yacc.c:1646  */
    {
			Trace("while loop with block");
			if((yyvsp[-2].value)->valueType!=boolType){
				yyerror("while loop expr must be bool");
			}
		}
#line 2727 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 972 "yacc.y" /* yacc.c:1646  */
    {
			Trace("for loop with simple");
			if((yyvsp[-4].value)->valueType!=intType||(yyvsp[-2].value)->valueType!=intType)
			{
				yyerror("for loop args must be int");
			}
		}
#line 2739 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 978 "yacc.y" /* yacc.c:1646  */
    {
			Trace("for loop with simple");
			if((yyvsp[-4].value)->valueType!=intType||(yyvsp[-2].value)->valueType!=intType)
			{
				yyerror("for loop args must be int");
			}
		}
#line 2751 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 985 "yacc.y" /* yacc.c:1646  */
    {
			Trace("assign expr to id");
			int exist = all_table.lookup_all(*(yyvsp[-2].s_val));
			if(exist ==-1)
				yyerror("id not exist");
			else //insert id
			{	
				int pos = all_table.table_list[exist].lookup(*(yyvsp[-2].s_val));
				Identifier* put = all_table.table_list[exist].idList[pos];
				if(put->idValue->valueType!=(yyvsp[0].value)->valueType)
				{
					yyerror("assign error, type error");
				}else{
					put->idValue=(yyvsp[0].value);
					Trace("assign id done");
				}
				if(exist==IsGLOBAL){
					java<<"\t\tputstatic "<<valueType2String(put->idValue->valueType)<<" "<<now_class<<"."<<*(yyvsp[-2].s_val)<<endl;
				}else{
					java_store(put->index);
				}
			}
		}
#line 2779 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 1007 "yacc.y" /* yacc.c:1646  */
    {
			Trace("assign expr to id array's value");
			int exist = all_table.lookup_all(*(yyvsp[-5].s_val));
			if(exist ==-1)
				yyerror("id not exist");
			else //insert id
			{	
				int pos = all_table.table_list[exist].lookup(*(yyvsp[-5].s_val));
				Identifier* put = all_table.table_list[exist].idList[pos];
				if(put->idType!=Array)
				{
					yyerror("must be array");
				}else if(put->arrayValueType!=(yyvsp[0].value)->valueType){
					yyerror("type error");
				}else {
					//array value assign not yet
					//put->arrayValue[$3] = $6;
					Trace("assign to array's value done");
				}
				
			}
		}
#line 2806 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 1028 "yacc.y" /* yacc.c:1646  */
    {
			java<<"getstatic java.io.PrintStream java.lan.System.out"<<endl;
		}
#line 2814 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 1030 "yacc.y" /* yacc.c:1646  */
    {
			if((yyvsp[0].value)->valueType == stringType){
				java<<"invokevirtual void java.io.PrintStream.print(java.lang.String)"<<endl;
			}else{
				java<<"invokevirtual void java.io.PrintStream.print("<<valueType2String((yyvsp[0].value)->valueType)<<")"<<endl;
			}
			Trace("print expr");
		}
#line 2827 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 1037 "yacc.y" /* yacc.c:1646  */
    {
			java<<"getstatic java.io.PrintStream java.lan.System.out"<<endl;
		}
#line 2835 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 1039 "yacc.y" /* yacc.c:1646  */
    {
			if((yyvsp[0].value)->valueType == stringType){
				java<<"invokevirtual void java.io.PrintStream.println(java.lang.String)"<<endl;
			}else{
				java<<"invokevirtual void java.io.PrintStream.println("<<valueType2String((yyvsp[0].value)->valueType)<<")"<<endl;
			}
			Trace("println expr");
		}
#line 2848 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 1046 "yacc.y" /* yacc.c:1646  */
    {
			Trace("read id");
		}
#line 2856 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 1048 "yacc.y" /* yacc.c:1646  */
    {
			Trace("return");
			java<<"\t\tretrun"<<endl;
			has_return = true;
			//return new Value;
		}
#line 2867 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1053 "yacc.y" /* yacc.c:1646  */
    {
			Trace("return expr");
			java<<"\t\tiretrun"<<endl;
			has_return = true;
			//return $2;
		}
#line 2878 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1061 "yacc.y" /* yacc.c:1646  */
    { 
			Trace("program start");
			Identifier* put = new Identidier;
			now_class = *(yyvsp[0].s_val);
			put->idName = *(yyvsp[0].s_val);
			put->idType = Object;
			all_table.push();
			InsertSymbol(put,all_table.table_list[table_index]);
			java<<"class "<<*(yyvsp[0].s_val)<<endl;
			java<<"{"<<endl;
			
                }
#line 2895 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1073 "yacc.y" /* yacc.c:1646  */
    {
			if(all_table.lookup_all("main")==-1){
				yyerror("must have main");
			}
			Trace("program end");
			java<<"}"<<endl;
			all_table.dump();
			all_table.pop();
                }
#line 2909 "y.tab.cpp" /* yacc.c:1646  */
    break;


#line 2913 "y.tab.cpp" /* yacc.c:1646  */
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
#line 1083 "yacc.y" /* yacc.c:1906  */

void InsertSymbol(Identifier* n,SymbolTable &ST)
{
	int index = ST.lookup(n->idName);
	if (index==-1)//not found
	{
		ST.idList.push_back(n);
	}
}



int main(int argc, char *argv[])
{
    // have a file or not
    if(argc > 1){
        yyin = fopen(argv[1], "r");
	string output = argv[1];
	output += ".jasm";
	java.open(output,ios::out);
    }
    else{
        yyin = stdin;
    }
    if(!java){
	cout<<"open error"<<endl;
	exit(1);
    }
	
    if(yyparse() == 1)
		yyerror("parsing error");

    return 0;
}
