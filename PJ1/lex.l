%{
#include "stdio.h"
#include "memory.h"
#define LIST     strcat(buf,yytext)
#define token(t) {LIST; printf("<%s>\n",t);return(t);}
#define tokenInteger(t,i) {LIST; printf("<%s:%d>\n",t,i);}
#define tokenFloat(t,f) {LIST; printf("<%s:%f>\n",t,f);}
#define tokenString(t,s) {LIST; printf("<%s:%s>\n",t,s);}

#define MAX_LINE_LENG 256
#define TABLE_SIZE 37

int linenum = 1;
char buf[MAX_LINE_LENG];
/* Symbol node */
typedef struct{
	char *name;
	void *pre;
	void *next;
}Node;
/* SymbolTable */
typedef struct{
	Node **Table;
}SymbolTable;


unsigned long hash(char *input);
SymbolTable *create();
int lookup(char *input,SymbolTable *ST);
int insert(char *input,SymbolTable *ST);
void dump(SymbolTable* ST);

//Global SymbolTable
SymbolTable *Root_ST;

%}
/*Defination*/
integer [0-9]+
norm_real {integer}"."{integer}
exp_real {integer}"."{integer}[Ee][+-]?{integer}
real    [+-]?{norm_real}|{exp_real}
identifier      [a-zA-Z]([0-9a-zA-Z]*)
boolean "true"|"false"
string  \"(\"\"|[^\"\n])*\"
%x comment
single_comment	"//"[^\n]*
area_comment_s	"/*"
area_comment_e	"*/"

%%
","	{return("COMMA");}

":"	{return("COLON");}

";"	{return("SEMICOLON");}

"("     {return("L_PAREN");}

")"	{return("R_PAREN");}

"["	{return("L_SQUARE");}

"]"	{return("R_SQUARE");}

"{"	{return("L_BRACKET");}

"}"	{return("R_BRACKET");}

"+"	{return("ADD");}

"-"	{return("MINUS");}

"*"	{return("PRODUCT");}

"/"	{return("DIVIDE");}

"%"	{return("MOD");}

"="	{return("ASSIGN");}

"<"	{return("LESS");}

"<="	{return("NOT_MORE");}

">="	{return("NOT_LESS");}

">"	{return("MORE");}

"=="	{return("EQUAL");}

"!="	{return("NOT_EQUAL");}

"&&"	{return("AND");}

"||"	{return("OR");}

"!"	{return("NOT");}

"boolean"	{token("BOOLEAN");}

"break"	{token("BREAK");}

"char"	{token("CHAR");}

"case"	{token("CASE");}

"class"	{token("CLASS");}

"continue"	{token("CONTINUE");}

"def"	{token("DEF");}

"do"	{token("DO");}

"else"	{token("ELSE");}

"exit"	{token("EXIT");}

"false"	{tokenString("boolean","FALSE");}

"float"	{token("FLOAT");}

"for"	{token("FOR");}

"if"	{token("IF");}

"int"	{token("INT");}

"null"	{token("NULL");}

"object"	{token("OBJECT");}

"print"	{token("PRINT");}

"println"	{token("PRINTLN");}

"repeat"	{token("REPEAT");}

"return"	{token("RETURN");}

"string"	{token("STRING");}

"to"	{token("TO");}

"true"	{tokenString("boolean","TRUE");}

"type"	{token("TYPE");}

"val"	{token("VAL");}

"var"	{token("VAR");}

"while"	{token("WHILE");}

{integer}	{
	int put;
	sscanf(yytext,"%d",&put);
	tokenInteger("integer",put);
	yylval.i_val = atoi(yytext);
	}
{real}	{
	float put;
	sscanf(yytext,"%f",&put);
	tokenFloat("float",put);
	yylval.f_val = atof(yytext);
	}
{boolean}	{
	tokenString("boolean",yytext);
	}
{identifier}	{
	tokenString("id",yytext);
	insert(yytext,Root_ST);
	}
{string}	{
	int count = 0;
	char put =input();
	if(put=='"'){
		unput(put);
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
		tokenString("string",result);
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
unsigned long hash(char *input)
{
	unsigned long result = 5381;
	int c;
	
	while(c= *input++)
	{
		result = ((result << 5) + result) + c;//result = result*33 + c
	}
	return result % TABLE_SIZE;
}

SymbolTable *create()
{
	SymbolTable *put = malloc(sizeof(SymbolTable));
	put->Table = malloc(sizeof(Node)*TABLE_SIZE);
	
	memset(put->Table,0,sizeof(Node)*TABLE_SIZE);
	return put;
}
int lookup(char *input,SymbolTable *ST)
{
	unsigned long hash_num=hash(input);
	Node *find =ST->Table[hash_num];
	for(Node *find = ST->Table[hash_num];find!=NULL;find->next)
	{
		if(strcmp(input,find->name)==0)
		{
			return 1;//find
		}
	}
	return 2;
}

int insert(char *input,SymbolTable *ST)
{
	unsigned long hash_num=hash(input);
	//check if SymbolTable[hash_num] NULL
	Node *now_Node = ST->Table[hash_num];
	Node *new_Node = malloc(sizeof(Node));
	if(now_Node==NULL)
	{
		new_Node->name=malloc(yyleng+1);
		strcpy(new_Node->name,input);
		new_Node->pre=NULL;
		new_Node->next=NULL;
		ST->Table[hash_num]=new_Node;
		return 1;//empty
	}
	else
	{
		//check if already exist
		for(;now_Node!=NULL;now_Node=now_Node->next)
		{
			if(strcmp(now_Node->name,input)==0)
			{
				return 0;//already exist
			}
			if(now_Node->next==NULL)//now_Node is end of LIST
			{
				break;
			}
		}
		new_Node->name=malloc(yyleng+1);
		strcpy(new_Node->name,input);
		new_Node->pre=now_Node;
		new_Node->next=NULL;
		now_Node->next=new_Node;
		return 2;
	}
}
void dump(SymbolTable *ST)
{
	printf("=========Symbol Table=========\n");
	for(int i=0;i<TABLE_SIZE;i++)
	{
		for(Node *out=ST->Table[i];out!=NULL;out=out->next)
		{
			printf("%s\n",out->name);
		}
	}
}
int main(int argc,char *argv[])
{
	Root_ST=create();
	FILE *f;
	if(argc==2){
		if(!(f=fopen(argv[1],"r")))
		{
			printf("Error.\n");
			return(-1);
		}
		yyset_in(f);
		yylex();
		fclose(f);
	}
	else{
		printf("run scanner.\n");
	}
	dump(Root_ST);
	return(0);
}
