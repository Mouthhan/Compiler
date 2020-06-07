%{
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string>
using namespace std;
#include "y.tab.hpp"

#define LIST     strcat(buf,yytext)
#define token(t) {LIST; return t;}
//printf("<%s>\n",yytext);
#define MAX_LINE_LENG 256
#define TABLE_SIZE 37

int linenum = 1;
char buf[MAX_LINE_LENG];
extern "C"
{
	int yylex();
	int yywrap();
}
%}
/*Defination*/
integer [0-9]+
norm_real {integer}"."{integer}
exp_real {integer}"."{integer}[Ee][+-]?{integer}
real    [+-]?{norm_real}|{exp_real}
identifier      [a-zA-Z]([0-9a-zA-Z]*)
boolean "true"|"false"
char '([^'\\\n]|\\.)'
string  \"(\"\"|[^\"\n])*\"
%x comment
single_comment	"//"[^\n]*
area_comment_s	"/*"
area_comment_e	"*/"

%%
","	{token(',');}

":"	{token(':');}

";"	{token(';');}

"("     {token('(');}

")"	{token(')');}

"["	{token('[');}

"]"	{token(']');}

"{"	{token('{');}

"}"	{token('}');}

"+"	{token('+');}

"-"	{token('-');}

"*"	{token('*');}

"/"	{token('/');}

"%"	{token('%');}

"="	{token('=');}

"<"	{token(LESS);}

"<="	{token(NOT_MORE);}

">="	{token(NOT_LESS);}

">"	{token(MORE);}

"=="	{token(EQUAL);}

"!="	{token(NOT_EQUAL);}

"&&"	{token(AND);}

"||"	{token(OR);}

"!"	{token('!');}

"boolean"	{token(BOOLEAN);}

"break"	{token(BREAK);}

"char"	{token(CHAR);}

"case"	{token(CASE);}

"class"	{token(CLASS);}

"continue"	{token(CONTINUE);}

"def"	{token(DEF);}

"do"	{token(DO);}

"else"	{token(ELSE);}

"exit"	{token(EXIT);}

"false"	{yylval.b_val = false;token(FALSE);}

"float"	{token(FLOAT);}

"for"	{token(FOR);}

"if"	{token(IF);}

"int"	{token(INT);}

"null"	{token(_NULL);;}

"object"	{token(OBJECT);}

"print"	{token(PRINT);}

"println"	{token(PRINTLN);}

"repeat"	{token(REPEAT);}

"return"	{token(RETURN);}

"string"	{token(STRING);}

"to"	{token(TO);}

"true"	{yylval.b_val = true;token(TRUE);}

"type"	{token(TYPE);}

"val"	{token(VAL);}

"var"	{token(VAR);}

"while"	{token(WHILE);}

{integer}	{
	int put;
	sscanf(yytext,"%d",&put);
	yylval.i_val = put;
	token(INT_VALUE);
	}
{real}	{
	float put;
	sscanf(yytext,"%f",&put);
	yylval.f_val = put;
	token(FLOAT_VALUE);
	}
{boolean}	{
	yylval.b_val = yytext;
	token(BOOL_VALUE);
	}
{identifier}	{
	yylval.s_val = new string(yytext);
	token(ID);
	}
{char} {
    char tmp[10];
    LIST;
    sscanf(yytext,"%s",tmp);
    yylval.c_val = tmp[1];
    token(CHAR_VALUE);

}
{string}	{
	int count = 0;
	char put = getc(yyin);
	if(put=='"'){
		ungetc(put, yyin);
		yymore();
	}
	else {
		int pos=0;//position
		char *result = (char*)malloc(yyleng-1);
		for(int i=1;i<yyleng-1;i++)
		{
			if(yytext[i]=='"')
			{
				count++;
			}
			if(count%2==0&&count>0)
			{
				count=0;
				continue;
			}
			else
			{
				result[pos]=yytext[i];
				pos++;
			}
		}

		yylval.s_val = new string(result);
		token(STRING_VALUE);
		unput(put);
		free(result);
	}
	}
{single_comment}	{
	LIST;
	}
{area_comment_s}	{LIST;BEGIN(comment);}

<comment>{area_comment_e}	{LIST;BEGIN(INITIAL);}

<comment>\n	{
	LIST;
        printf("%d: %s", linenum++, buf);
        buf[0] = '\0';
	}

<comment>.	{LIST;}

\n      {
        LIST;
        printf("%d: %s", linenum++, buf);
        buf[0] = '\0';
        }

[ \t]*  {LIST;}

.       {
        LIST;
        printf("%d:%s\n", linenum+1, buf);
        printf("bad character:'%s'\n",yytext);
        exit(-1);
        }
%%
int yywrap()
{
	return 1;
}

