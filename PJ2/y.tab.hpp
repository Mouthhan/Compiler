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
#line 26 "yacc.y" /* yacc.c:1909  */

	int i_val;
	float f_val;
	bool b_val;
	string* s_val;
	char c_val;
	int valueType;
	Value* value;
	Identifier* idType;

#line 161 "y.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */
