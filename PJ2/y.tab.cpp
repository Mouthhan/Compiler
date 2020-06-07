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
#include <string>
#include "math.h"
#include "SymbolTable.hpp"
#include "lex.yy.cpp"

using namespace std;
#define Trace(t)        cout<<t<<endl;
SymbolTables all_table = SymbolTables();//All SymbolTable
int table_index = 0;
void InsertSymbol(Identifier* n,SymbolTable &ST);

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

#line 91 "y.tab.cpp" /* yacc.c:339  */

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
    SEMICOLON = 258,
    BOOLEAN = 259,
    BREAK = 260,
    CHAR = 261,
    CASE = 262,
    CLASS = 263,
    CONTINUE = 264,
    DEF = 265,
    DO = 266,
    ELSE = 267,
    EXIT = 268,
    FALSE = 269,
    FLOAT = 270,
    FOR = 271,
    IF = 272,
    INT = 273,
    _NULL = 274,
    OBJECT = 275,
    PRINT = 276,
    PRINTLN = 277,
    READ = 278,
    REPEAT = 279,
    RETURN = 280,
    STRING = 281,
    TO = 282,
    TRUE = 283,
    TYPE = 284,
    VAL = 285,
    VAR = 286,
    WHILE = 287,
    INT_VALUE = 288,
    FLOAT_VALUE = 289,
    BOOL_VALUE = 290,
    STRING_VALUE = 291,
    CHAR_VALUE = 292,
    ID = 293,
    OR = 294,
    AND = 295,
    LESS = 296,
    NOT_MORE = 297,
    NOT_LESS = 298,
    MORE = 299,
    NOT_EQUAL = 300,
    EQUAL = 301,
    UMINUS = 302
  };
#endif
/* Tokens.  */
#define SEMICOLON 258
#define BOOLEAN 259
#define BREAK 260
#define CHAR 261
#define CASE 262
#define CLASS 263
#define CONTINUE 264
#define DEF 265
#define DO 266
#define ELSE 267
#define EXIT 268
#define FALSE 269
#define FLOAT 270
#define FOR 271
#define IF 272
#define INT 273
#define _NULL 274
#define OBJECT 275
#define PRINT 276
#define PRINTLN 277
#define READ 278
#define REPEAT 279
#define RETURN 280
#define STRING 281
#define TO 282
#define TRUE 283
#define TYPE 284
#define VAL 285
#define VAR 286
#define WHILE 287
#define INT_VALUE 288
#define FLOAT_VALUE 289
#define BOOL_VALUE 290
#define STRING_VALUE 291
#define CHAR_VALUE 292
#define ID 293
#define OR 294
#define AND 295
#define LESS 296
#define NOT_MORE 297
#define NOT_LESS 298
#define MORE 299
#define NOT_EQUAL 300
#define EQUAL 301
#define UMINUS 302

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 26 "yacc.y" /* yacc.c:355  */

	int i_val;
	float f_val;
	bool b_val;
	string* s_val;
	char c_val;
	int valueType;
	Value* value;
	Identifier* idType;

#line 236 "y.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 253 "y.tab.cpp" /* yacc.c:358  */

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
#define YYLAST   271

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  170

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,     2,     2,    52,     2,     2,
      58,    59,    50,    48,    62,    49,     2,    51,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    55,     2,
       2,    54,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    57,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    60,     2,    61,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    42,    43,    44,    45,
      46,    47,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    74,    74,    75,    76,    79,    96,   117,   133,   151,
     168,   190,   218,   220,   238,   240,   258,   277,   296,   315,
     333,   348,   359,   370,   381,   400,   419,   438,   457,   481,
     505,   530,   550,   554,   558,   562,   566,   570,   576,   578,
     579,   582,   585,   588,   591,   594,   595,   597,   598,   599,
     599,   613,   613,   628,   634,   639,   644,   653,   665,   671,
     671,   699,   700,   701,   703,   704,   705,   706,   706,   717,
     718,   720,   720,   724,   727,   729,   732,   732,   734,   736,
     739,   745,   752,   770,   790,   792,   794,   796,   799,   805,
     804
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMICOLON", "BOOLEAN", "BREAK", "CHAR",
  "CASE", "CLASS", "CONTINUE", "DEF", "DO", "ELSE", "EXIT", "FALSE",
  "FLOAT", "FOR", "IF", "INT", "_NULL", "OBJECT", "PRINT", "PRINTLN",
  "READ", "REPEAT", "RETURN", "STRING", "TO", "TRUE", "TYPE", "VAL", "VAR",
  "WHILE", "INT_VALUE", "FLOAT_VALUE", "BOOL_VALUE", "STRING_VALUE",
  "CHAR_VALUE", "ID", "OR", "AND", "'!'", "LESS", "NOT_MORE", "NOT_LESS",
  "MORE", "NOT_EQUAL", "EQUAL", "'+'", "'-'", "'*'", "'/'", "'%'",
  "UMINUS", "'='", "':'", "'['", "']'", "'('", "')'", "'{'", "'}'", "','",
  "$accept", "declarations", "const_dec", "var_dec", "EXPR", "VALUE",
  "FUNC_TYPE", "DATA_TYPE", "zero_or_more_state", "methods", "method",
  "$@1", "FUNC_BLOCK", "$@2", "ARGS", "ARG", "FUNC_INVOCATION", "$@3",
  "STATEMENTS", "STATEMENT", "BLOCK", "$@4", "CONDITION", "IF_CONDITION",
  "$@5", "ELSE_CONDITION", "LOOP", "WHILE_LOOP", "FOR_LOOP", "SIMPLE",
  "program", "$@6", YY_NULLPTR
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
     295,    33,   296,   297,   298,   299,   300,   301,    43,    45,
      42,    47,    37,   302,    61,    58,    91,    93,    40,    41,
     123,   125,    44
};
# endif

#define YYPACT_NINF -102

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-102)))

#define YYTABLE_NINF -60

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -5,   -20,    29,  -102,  -102,   -39,    23,    10,    12,    56,
      23,    23,    34,    57,    36,    -6,  -102,  -102,  -102,    69,
       1,    69,     1,  -102,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,   -48,    69,    69,    69,   191,  -102,  -102,  -102,  -102,
    -102,  -102,  -102,    28,   191,    21,    26,    60,    38,   217,
      44,   119,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    68,  -102,
    -102,    51,    86,  -102,   204,   217,   -26,   -26,   -26,   -26,
     -26,   -26,    82,    82,    44,    44,    44,   191,   191,   191,
      59,    86,  -102,    58,  -102,   -53,  -102,  -102,   -45,     1,
    -102,    86,    62,  -102,  -102,     1,    65,  -102,    23,    35,
      70,    73,    69,    69,    88,    69,    79,    25,  -102,    77,
    -102,    35,  -102,  -102,   128,  -102,  -102,  -102,  -102,   118,
      69,   191,   191,  -102,   191,    69,    69,   108,    23,  -102,
    -102,    40,  -102,   130,   137,   155,   191,   117,    35,  -102,
    -102,   111,  -102,    40,   121,   129,    69,    47,  -102,  -102,
      69,  -102,   103,  -102,   191,    69,   173,    40,  -102,  -102
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    89,     1,     0,     4,     0,     0,     0,
       4,     4,     0,     7,     0,     0,    48,     2,     3,     0,
       0,     0,     0,    49,    90,    47,    33,    35,    34,    36,
      37,    30,     0,     0,     0,     5,    32,    14,    43,    40,
      44,    42,    41,     0,     9,     8,     0,     0,     0,    23,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    51,
      50,     0,    55,    12,    21,    22,    24,    25,    27,    26,
      29,    28,    15,    16,    17,    18,    19,    13,     6,    10,
       0,    55,    31,    57,    58,     0,    53,    11,     0,     0,
      60,     0,    39,    56,    54,     0,     0,    38,     4,    46,
       0,     0,     0,     0,     0,    87,     0,     0,    67,     0,
      45,    62,    73,    65,    69,    66,    76,    77,    64,     0,
       0,    84,    85,    86,    88,     0,     0,     0,     4,    52,
      61,     0,    70,     0,     0,     0,    82,     0,    63,    75,
      74,     0,    71,     0,     0,     0,     0,     0,    79,    78,
       0,    68,     0,    72,    83,     0,     0,     0,    81,    80
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -102,    -9,  -102,  -102,   -21,   -42,  -102,   -19,  -102,  -102,
     177,  -102,  -102,  -102,   102,   107,  -102,  -102,  -101,  -102,
     -77,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,   -70,
    -102,  -102
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    35,    36,   106,    43,   119,    15,
      16,    46,    70,    91,    95,    96,    37,    48,   120,   121,
     122,   138,   123,   124,   157,   142,   125,   126,   127,   128,
       2,     5
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,    17,    18,    45,    14,    38,   100,    39,    47,   101,
     -59,    49,    50,    51,   102,     1,    40,   101,     3,    41,
     140,     6,    60,    61,    62,    63,    64,    42,    65,     4,
      94,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,   155,    12,    94,
      13,   110,   111,     7,     8,    24,   112,   113,   114,    94,
     115,   112,   113,   114,   149,   115,    14,   116,   112,   113,
     114,   150,   115,   117,    23,    67,   158,    68,   117,   136,
     103,   137,    66,   159,    69,   117,   107,   163,    19,    20,
     168,   131,   132,    71,   134,   118,    72,   169,    65,   109,
     118,    90,    26,    27,    28,    29,    30,    31,    92,   144,
      32,    21,    22,    99,   145,   146,    97,   105,    33,    26,
      27,    28,    29,    30,    93,   108,   133,    34,   129,   148,
     165,   130,    62,    63,    64,   162,    65,   135,   139,   164,
     141,   147,    52,    53,   166,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   143,    65,    52,    53,
     156,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,   151,    65,   154,   160,    52,    53,    73,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
     161,    65,    25,    98,    52,    53,   152,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,   104,    65,
       0,     0,    52,    53,   153,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,    65,     0,     0,
      52,    53,   167,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    53,    65,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,     0,    65,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,    65
};

static const yytype_int16 yycheck[] =
{
      21,    10,    11,    22,    10,     4,    59,     6,    56,    62,
      58,    32,    33,    34,    59,    20,    15,    62,    38,    18,
     121,    60,    48,    49,    50,    51,    52,    26,    54,     0,
      72,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,   148,    38,    91,
      38,    16,    17,    30,    31,    61,    21,    22,    23,   101,
      25,    21,    22,    23,   141,    25,    10,    32,    21,    22,
      23,   141,    25,    38,    38,    54,   153,    56,    38,    54,
      99,    56,    54,   153,    58,    38,   105,   157,    54,    55,
     167,   112,   113,    33,   115,    60,    58,   167,    54,   108,
      60,    33,    33,    34,    35,    36,    37,    38,    57,   130,
      41,    54,    55,    55,   135,   136,    57,    55,    49,    33,
      34,    35,    36,    37,    38,    60,    38,    58,    58,   138,
      27,    58,    50,    51,    52,   156,    54,    58,    61,   160,
      12,    33,    39,    40,   165,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    38,    54,    39,    40,
      49,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    42,    54,    57,    54,    39,    40,    59,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      61,    54,    15,    91,    39,    40,    59,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,   101,    54,
      -1,    -1,    39,    40,    59,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    -1,    -1,
      39,    40,    59,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    40,    54,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    93,    38,     0,    94,    60,    30,    31,    64,
      65,    66,    38,    38,    10,    72,    73,    64,    64,    54,
      55,    54,    55,    38,    61,    73,    33,    34,    35,    36,
      37,    38,    41,    49,    58,    67,    68,    79,     4,     6,
      15,    18,    26,    70,    67,    70,    74,    56,    80,    67,
      67,    67,    39,    40,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    54,    54,    54,    56,    58,
      75,    33,    58,    59,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      33,    76,    57,    38,    68,    77,    78,    57,    77,    55,
      59,    62,    59,    70,    78,    55,    69,    70,    60,    64,
      16,    17,    21,    22,    23,    25,    32,    38,    60,    71,
      81,    82,    83,    85,    86,    89,    90,    91,    92,    58,
      58,    67,    67,    38,    67,    58,    54,    56,    84,    61,
      81,    12,    88,    38,    67,    67,    67,    33,    64,    83,
      92,    42,    59,    59,    57,    81,    49,    87,    83,    92,
      54,    61,    67,    92,    67,    27,    67,    59,    83,    92
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    64,    64,    65,    65,    66,    66,    66,
      66,    66,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    68,    68,    68,    68,    68,    69,    69,
      70,    70,    70,    70,    70,    71,    71,    72,    72,    74,
      73,    76,    75,    77,    77,    77,    78,    78,    78,    80,
      79,    81,    81,    81,    82,    82,    82,    84,    83,    85,
      85,    87,    86,    86,    88,    88,    89,    89,    90,    90,
      91,    91,    92,    92,    92,    92,    92,    92,    92,    94,
      93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     4,     6,     2,     4,     4,
       6,     7,     3,     3,     1,     3,     3,     3,     3,     3,
       2,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       1,     4,     1,     1,     1,     1,     1,     1,     2,     0,
       1,     1,     1,     1,     1,     1,     0,     2,     1,     0,
       4,     0,     9,     1,     3,     0,     3,     1,     1,     0,
       5,     2,     1,     0,     1,     1,     1,     0,     5,     1,
       2,     0,     6,     1,     2,     2,     1,     1,     5,     5,
      10,    10,     3,     6,     2,     2,     2,     1,     2,     0,
       7
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
#line 80 "yacc.y" /* yacc.c:1646  */
    {
			Trace("VAL ID = EXPR");
			int exist = all_table.table_list[table_index].lookup(*(yyvsp[-2].s_val));
			if(exist !=-1){
				Trace("id already exist");
			}
			else //insert id
			{
				Identifier* put = new Identidier;
				put->idName = *(yyvsp[-2].s_val);
				put->idType = Const;
				put->idValue = (yyvsp[0].value); 
				InsertSymbol(put,all_table.table_list[table_index]);
				Trace("insert id val & value");
			}
		}
#line 1491 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 97 "yacc.y" /* yacc.c:1646  */
    {
			Trace("VAL ID :TYPE = EXPR");
			int exist = all_table.table_list[table_index].lookup(*(yyvsp[-4].s_val));
			if(exist !=-1){
				Trace("id already exist");
			}
			if((yyvsp[-2].valueType) != (yyvsp[0].value)->valueType){
				Trace("type different");
			}
			else //insert id
			{
				Identifier* put = new Identidier;
				put->idName = *(yyvsp[-4].s_val);
				put->idType = Const;
				put->idValue = (yyvsp[0].value); 
				InsertSymbol(put,all_table.table_list[table_index]);
				Trace("insert id val & type & value");
			}
		}
#line 1515 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 118 "yacc.y" /* yacc.c:1646  */
    {
			Trace("VAR ID");
			int exist = all_table.table_list[table_index].lookup(*(yyvsp[0].s_val));
			if(exist !=-1){
				Trace("id already exist");
			}
			else //insert id
			{
				Identifier* put = new Identidier;
				put->idName = *(yyvsp[0].s_val);
				put->idType = Var; 
				InsertSymbol(put,all_table.table_list[table_index]);
				Trace("insert id var");
			}
		}
#line 1535 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 134 "yacc.y" /* yacc.c:1646  */
    {
			Trace("VAR ID:TYPE");
			int exist = all_table.table_list[table_index].lookup(*(yyvsp[-2].s_val));
			if(exist !=-1){
				Trace("id already exist");
			}
			else //insert id
			{
				Identifier* put = new Identidier;
				put->idName = *(yyvsp[-2].s_val);
				put->idType = Var; 
				put->idValue = new Value;
				put->idValue->valueType = (yyvsp[0].valueType);
				InsertSymbol(put,all_table.table_list[table_index]);
				Trace("insert id var & type");
			}
		}
#line 1557 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 152 "yacc.y" /* yacc.c:1646  */
    {
			Trace("VAR ID=EXPR");
			int exist = all_table.table_list[table_index].lookup(*(yyvsp[-2].s_val));
			if(exist !=-1){
				Trace("id already exist");
			}
			else //insert id
			{
				Identifier* put = new Identidier;
				put->idName = *(yyvsp[-2].s_val);
				put->idType = Var; 
				put->idValue = (yyvsp[0].value);
				InsertSymbol(put,all_table.table_list[table_index]);
				Trace("insert id va & value");
			}
		}
#line 1578 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 169 "yacc.y" /* yacc.c:1646  */
    {
			Trace("VAL ID :TYPE = EXPR");
			int exist = all_table.table_list[table_index].lookup(*(yyvsp[-4].s_val));
			if(exist !=-1){
				Trace("id already exist");
			}else{
				if((yyvsp[-2].valueType) != (yyvsp[0].value)->valueType){
					Trace("type different");
				}
				else //insert id
				{
					Identifier* put = new Identidier;
					put->idName = *(yyvsp[-4].s_val);
					put->idType = Var;
					put->idValue = (yyvsp[0].value); 
					InsertSymbol(put,all_table.table_list[table_index]);
					Trace("insert id var & type & value");
				}
			}
		}
#line 1603 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 191 "yacc.y" /* yacc.c:1646  */
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
        				put->arrayValue.push_back(new Value);
    				}
				InsertSymbol(put,all_table.table_list[table_index]);
				Trace("insert id(array)");
			}

			
		}
#line 1634 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 218 "yacc.y" /* yacc.c:1646  */
    {
			(yyval.value)=(yyvsp[-1].value);
		}
#line 1642 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 220 "yacc.y" /* yacc.c:1646  */
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
#line 1666 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 238 "yacc.y" /* yacc.c:1646  */
    {
			Trace("into call function");
		}
#line 1674 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 240 "yacc.y" /* yacc.c:1646  */
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
		}
#line 1698 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 258 "yacc.y" /* yacc.c:1646  */
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
		}
#line 1723 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 277 "yacc.y" /* yacc.c:1646  */
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
		}
#line 1748 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 296 "yacc.y" /* yacc.c:1646  */
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
		}
#line 1773 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 315 "yacc.y" /* yacc.c:1646  */
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
#line 1797 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 333 "yacc.y" /* yacc.c:1646  */
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
		}
#line 1818 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 348 "yacc.y" /* yacc.c:1646  */
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
		}
#line 1835 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 359 "yacc.y" /* yacc.c:1646  */
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
		}
#line 1852 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 370 "yacc.y" /* yacc.c:1646  */
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
		}
#line 1869 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 381 "yacc.y" /* yacc.c:1646  */
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
		}
#line 1894 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 400 "yacc.y" /* yacc.c:1646  */
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
		}
#line 1919 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 419 "yacc.y" /* yacc.c:1646  */
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
		}
#line 1944 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 438 "yacc.y" /* yacc.c:1646  */
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
		}
#line 1969 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 457 "yacc.y" /* yacc.c:1646  */
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
		}
#line 1999 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 481 "yacc.y" /* yacc.c:1646  */
    {
			Trace("EXPR != EXPR");
			Value* put = new Value;
       		 	put->valueType = boolType;
			if((yyvsp[-2].value)->valueType!=(yyvsp[0].value)->valueType){
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
		}
#line 2029 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 505 "yacc.y" /* yacc.c:1646  */
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
				}else if(put->idType == Function)
				{
					yyerror("expr assign id type is Function");
				}else if(put->idType == Object)
				{
					yyerror("expr assign id type is Object");
				}else
				{
					(yyval.value)=put->idValue;
					Trace("assign id value to expr");
				}
			}
		}
#line 2060 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 530 "yacc.y" /* yacc.c:1646  */
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
#line 2085 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 550 "yacc.y" /* yacc.c:1646  */
    {(yyval.value)=(yyvsp[0].value);}
#line 2091 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 554 "yacc.y" /* yacc.c:1646  */
    {
				Trace("find a int value");
				(yyval.value) = intValue((yyvsp[0].i_val));
			}
#line 2100 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 558 "yacc.y" /* yacc.c:1646  */
    {
				Trace("find a bool value");
				(yyval.value) = boolValue((yyvsp[0].b_val));
			}
#line 2109 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 562 "yacc.y" /* yacc.c:1646  */
    {
				Trace("find a float value");
				(yyval.value) = floatValue((yyvsp[0].f_val));
			}
#line 2118 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 566 "yacc.y" /* yacc.c:1646  */
    {
				Trace("find a string value");
				(yyval.value) = stringValue((yyvsp[0].s_val));
			}
#line 2127 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 570 "yacc.y" /* yacc.c:1646  */
    {
				Trace("find a char value");
				(yyval.value) = charValue((yyvsp[0].c_val));
			}
#line 2136 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 576 "yacc.y" /* yacc.c:1646  */
    {
			(yyval.valueType) = (yyvsp[0].valueType);
		}
#line 2144 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 579 "yacc.y" /* yacc.c:1646  */
    {
           	 	(yyval.valueType) = charType;
       	  	}
#line 2152 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 582 "yacc.y" /* yacc.c:1646  */
    {
          	 	(yyval.valueType) = stringType;
         	}
#line 2160 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 585 "yacc.y" /* yacc.c:1646  */
    {
             	 	(yyval.valueType) = intType;
         	}
#line 2168 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 588 "yacc.y" /* yacc.c:1646  */
    {
             	 	(yyval.valueType) = boolType;
         	}
#line 2176 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 591 "yacc.y" /* yacc.c:1646  */
    {
            		(yyval.valueType) = floatType;
         	}
#line 2184 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 599 "yacc.y" /* yacc.c:1646  */
    {
			Trace("Method ID");
			int exist = all_table.table_list[table_index].lookup(*(yyvsp[0].s_val));
			if(exist !=-1&&all_table.table_list[table_index].idList[exist]->idType==Function){
				Trace("method id already exist");
			}
		}
#line 2196 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 605 "yacc.y" /* yacc.c:1646  */
    {
			Trace("done FUNC_BLOCK");
			Identifier* put = (yyvsp[0].idType);
			put->idName = *(yyvsp[-2].s_val);
			put->idType = Function;
			InsertSymbol(put,all_table.table_list[table_index]);
		}
#line 2208 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 613 "yacc.y" /* yacc.c:1646  */
    {
			Trace("FUNC_BLOCK start");
			SymbolTable put = SymbolTable();
			table_index++;
			all_table.push();
		}
#line 2219 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 618 "yacc.y" /* yacc.c:1646  */
    {
			//cout<<"$3="<<$3<<endl;
			(yyval.idType)=(yyvsp[-6].idType);
			Trace("FUNC_BLOCK end");
			
			all_table.table_list[table_index].dump();
			all_table.pop();
			table_index--;
		}
#line 2233 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 628 "yacc.y" /* yacc.c:1646  */
    {
			Identifier* put = (yyvsp[0].idType);
			put->parameters.push_back((yyvsp[0].idType));
			put->numOfPara++;
			(yyval.idType)=put;
		}
#line 2244 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 634 "yacc.y" /* yacc.c:1646  */
    {
			Identifier* put = (yyvsp[-2].idType);
			put->parameters.push_back((yyvsp[0].idType));
			put->numOfPara++;
			(yyvsp[-2].idType)=put;
		}
#line 2255 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 639 "yacc.y" /* yacc.c:1646  */
    {
			Identifier* put =new Identifier;
			put->idType = Function;
			(yyval.idType) = put;
		}
#line 2265 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 644 "yacc.y" /* yacc.c:1646  */
    {
			Identifier* put = new Identifier;
			put->idName = *(yyvsp[-2].s_val);
			put->idValue = new Value;
			put->idType = Var;
			put->idValue->valueType = (yyvsp[0].valueType);
			InsertSymbol(put,all_table.table_list[table_index]);
			Trace("insert id(argument)");
			(yyval.idType)=put;
		}
#line 2280 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 653 "yacc.y" /* yacc.c:1646  */
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
#line 2297 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 665 "yacc.y" /* yacc.c:1646  */
    {
			Trace("arg = value");
			Identifier* put = new Identifier;
			put->idValue=(yyvsp[0].value);
			(yyval.idType)=put;
		}
#line 2308 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 671 "yacc.y" /* yacc.c:1646  */
    {
				Trace("start call function");
			}
#line 2316 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 673 "yacc.y" /* yacc.c:1646  */
    {
				Trace("call function done");
				int exist = all_table.lookup_all(*(yyvsp[-4].s_val));
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
						}
					}
				}
			}
#line 2347 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 704 "yacc.y" /* yacc.c:1646  */
    {Trace("exit Condition");}
#line 2353 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 705 "yacc.y" /* yacc.c:1646  */
    {Trace("into Loop");}
#line 2359 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 706 "yacc.y" /* yacc.c:1646  */
    {
			Trace("BLOCK start");
			SymbolTable put = SymbolTable();
			table_index++;
			all_table.push();
		}
#line 2370 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 711 "yacc.y" /* yacc.c:1646  */
    {
			Trace("BLOCK end");
			all_table.table_list[table_index].dump();
			all_table.pop();
			table_index--;
		}
#line 2381 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 720 "yacc.y" /* yacc.c:1646  */
    {
			Trace("IF condition");
		}
#line 2389 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 722 "yacc.y" /* yacc.c:1646  */
    {
			Trace("if with simple");
		}
#line 2397 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 724 "yacc.y" /* yacc.c:1646  */
    {
			Trace("if with block");
		}
#line 2405 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 727 "yacc.y" /* yacc.c:1646  */
    {
			Trace("else with simple");
		}
#line 2413 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 729 "yacc.y" /* yacc.c:1646  */
    {
			Trace("else with block");
		}
#line 2421 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 734 "yacc.y" /* yacc.c:1646  */
    {
			Trace("while loop with simple");
		}
#line 2429 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 736 "yacc.y" /* yacc.c:1646  */
    {
			Trace("while loop with block");
		}
#line 2437 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 739 "yacc.y" /* yacc.c:1646  */
    {
			Trace("for loop with simple");
			if((yyvsp[-4].value)->valueType!=intType||(yyvsp[-2].value)->valueType!=intType)
			{
				yyerror("for loop args must be int");
			}
		}
#line 2449 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 745 "yacc.y" /* yacc.c:1646  */
    {
			Trace("for loop with simple");
			if((yyvsp[-4].value)->valueType!=intType||(yyvsp[-2].value)->valueType!=intType)
			{
				yyerror("for loop args must be int");
			}
		}
#line 2461 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 752 "yacc.y" /* yacc.c:1646  */
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
				
			}
		}
#line 2485 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 770 "yacc.y" /* yacc.c:1646  */
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
					put->arrayValue[(yyvsp[-3].i_val)] = (yyvsp[0].value);
					Trace("assign to array's value done");
				}
				
			}
		}
#line 2511 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 790 "yacc.y" /* yacc.c:1646  */
    {
			Trace("print expr");
		}
#line 2519 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 792 "yacc.y" /* yacc.c:1646  */
    {
			Trace("println expr");
		}
#line 2527 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 794 "yacc.y" /* yacc.c:1646  */
    {
			Trace("read id");
		}
#line 2535 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 796 "yacc.y" /* yacc.c:1646  */
    {
			Trace("return");
			//return new Value;
		}
#line 2544 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 799 "yacc.y" /* yacc.c:1646  */
    {
			Trace("return expr");
			//return $2;
		}
#line 2553 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 805 "yacc.y" /* yacc.c:1646  */
    { 
			Trace("program start");
			Identifier* put = new Identidier;
			put->idName = *(yyvsp[0].s_val);
			put->idType = Object;
			all_table.push();
			InsertSymbol(put,all_table.table_list[table_index]);
			
                }
#line 2567 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 814 "yacc.y" /* yacc.c:1646  */
    {
			Trace("program end");
			all_table.dump();
			all_table.pop();
                }
#line 2577 "y.tab.cpp" /* yacc.c:1646  */
    break;


#line 2581 "y.tab.cpp" /* yacc.c:1646  */
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
#line 820 "yacc.y" /* yacc.c:1906  */

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
    if(argc > 1)
        yyin = fopen(argv[1], "r");
    else
        yyin = stdin;

    if(yyparse() == 1)
		yyerror("parsing error");

    return 0;
}
