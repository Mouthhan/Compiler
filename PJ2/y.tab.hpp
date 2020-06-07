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
#line 26 "yacc.y" /* yacc.c:1909  */

	int i_val;
	float f_val;
	bool b_val;
	string* s_val;
	char c_val;
	int valueType;
	Value* value;
	Identifier* idType;

#line 159 "y.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */
