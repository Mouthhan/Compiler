%{
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
%}

%union {
	int i_val;
	float f_val;
	bool b_val;
	string* s_val;
	char c_val;
	int valueType;
	Value* value;
	Identifier* idType;
}

/* tokens */
//%token COLON SEMICOLON L_PAREN R_PAREN L_SQUARE R_SQUARE START END COMMA
/* operator */
//%token ADD MINUS PRODUCT DIVIDE MOD ASSIGN
/* logic  */
//%token OR AND EQUAL LESS NOT_MORE NOT_LESS MORE NOT_EQUAL NOT
/* reserve word  */
%token SEMICOLON BOOLEAN BREAK CHAR CASE CLASS CONTINUE DEF DO ELSE EXIT FALSE FLOAT FOR IF INT _NULL OBJECT PRINT PRINTLN READ REPEAT RETURN STRING TO TRUE TYPE VAL VAR WHILE
/* value get  */
//%token INTEGER BOOL REAL_NUM ID STR

%token <i_val> INT_VALUE
%token <f_val> FLOAT_VALUE
%token <b_val> BOOL_VALUE
%token <s_val> STRING_VALUE
%token <c_val> CHAR_VALUE
%token <s_val> ID
/* type  */
%type <valueType> DATA_TYPE FUNC_TYPE
%type <idType> ARGS ARG method methods
%type <value> VALUE EXPR 
/* precedence  */
%left OR 
%left AND
%left '!'
%left LESS NOT_MORE NOT_LESS MORE NOT_EQUAL EQUAL
%left '+' '-'
%left '*' '/' '%'
%nonassoc UMINUS

%start program


%%
/* All Declarations(dec) */
//zero or more declaration
declarations:	const_dec declarations
		| var_dec declarations
		| /*empty*/;

// val declaration
const_dec:	VAL ID '=' EXPR //val a = 10
		{
			Trace("VAL ID = EXPR");
			int exist = all_table.table_list[table_index].lookup(*$2);
			if(exist !=-1){
				Trace("id already exist");
			}
			else //insert id
			{
				Identifier* put = new Identidier;
				put->idName = *$2;
				put->idType = Const;
				put->idValue = $4; 
				InsertSymbol(put,all_table.table_list[table_index]);
				Trace("insert id");
			}
		}|
		VAL ID ':' DATA_TYPE '=' EXPR//val a:int = 10
		{
			Trace("VAL ID :TYPE = EXPR");
			int exist = all_table.table_list[table_index].lookup(*$2);
			if(exist !=-1){
				Trace("id already exist");
			}
			if($4 != $6->valueType){
				Trace("type different");
			}
			else //insert id
			{
				Identifier* put = new Identidier;
				put->idName = *$2;
				put->idType = Const;
				put->idValue = $6; 
				InsertSymbol(put,all_table.table_list[table_index]);
				Trace("insert id");
			}
		};
//var declaration
var_dec:	VAR ID//var a
		{
			Trace("VAR ID");
			int exist = all_table.table_list[table_index].lookup(*$2);
			if(exist !=-1){
				Trace("id already exist");
			}
			else //insert id
			{
				Identifier* put = new Identidier;
				put->idName = *$2;
				put->idType = Var; 
				InsertSymbol(put,all_table.table_list[table_index]);
				Trace("insert id");
			}
		}|
		VAR ID ':' DATA_TYPE//var a:int
		{
			Trace("VAR ID:TYPE");
			int exist = all_table.table_list[table_index].lookup(*$2);
			if(exist !=-1){
				Trace("id already exist");
			}
			else //insert id
			{
				Identifier* put = new Identidier;
				put->idName = *$2;
				put->idType = Var; 
				put->idValue = new Value;
				put->idValue->valueType = $4;
				InsertSymbol(put,all_table.table_list[table_index]);
				Trace("insert id");
			}
		}|
		VAR ID '=' EXPR//var a = 3
		{
			Trace("VAR ID=EXPR");
			int exist = all_table.table_list[table_index].lookup(*$2);
			if(exist !=-1){
				Trace("id already exist");
			}
			else //insert id
			{
				Identifier* put = new Identidier;
				put->idName = *$2;
				put->idType = Var; 
				put->idValue = $4;
				InsertSymbol(put,all_table.table_list[table_index]);
				Trace("insert id");
			}
		}|
		VAR ID ':' DATA_TYPE '=' EXPR//var a:int = 3
		{
			Trace("VAL ID :TYPE = EXPR");
			int exist = all_table.table_list[table_index].lookup(*$2);
			if(exist !=-1){
				Trace("id already exist");
			}else{
				if($4 != $6->valueType){
					Trace("type different");
				}
				else //insert id
				{
					Identifier* put = new Identidier;
					put->idName = *$2;
					put->idType = Var;
					put->idValue = $6; 
					InsertSymbol(put,all_table.table_list[table_index]);
					Trace("insert id");
				}
			}
		}|
		//var a:int[10]
		VAR ID ':' DATA_TYPE '[' INT_VALUE ']'
		{
			Trace("VAL ID :TYPE = EXPR");
			int exist = all_table.table_list[table_index].lookup(*$2);
			if($6<1){
				yyerror("Array length error");
			}
			else if(exist !=-1){
				Trace("id already exist");
			}
			else //insert id
			{
				Identifier* put = new Identidier;
				put->idName = *$2;
				put->idType = Array;
				put->arraySize = $6; 
				put->arrayValueType = $4;
				for (int i = 0; i < put->arraySize; i++)
    				{
        				put->arrayValue.push_back(new Value);
    				}
				InsertSymbol(put,all_table.table_list[table_index]);
				Trace("insert id");
			}

			
		};
		;
EXPR:		'(' EXPR ')'{
			$$=$2;
		}|FUNC_INVOCATION {
			//not yet
		}|EXPR '+' EXPR {
			Trace("EXPR + EXPR");
			Value* put =new Value;
			if($1->valueType==intType && $3->valueType==intType){
           			put->valueType = intType;
            			put->i_value = ($1->i_value + $3->i_value);
        		}else if($1->valueType==intType && $3->valueType==floatType){
           			put->valueType = floatType;
            			put->f_value = ((float)$1->i_value + $3->f_value);
        		}else if($1->valueType==floatType && $3->valueType==intType){
           			put->valueType = floatType;
            			put->f_value = ($1->f_value + (float)$3->i_value);
        		}else if($1->valueType==floatType && $3->valueType==floatType){
           			put->valueType = floatType;
            			put->f_value = ($1->f_value + $3->f_value);
        		}else
				{yyerror("add type error");}
			$$=put;
		}|EXPR '-' EXPR {
			Trace("EXPR - EXPR");
			Value* put =new Value;
			if($1->valueType==intType && $3->valueType==intType){
           			put->valueType = intType;
            			put->i_value = ($1->i_value - $3->i_value);
        		}else if($1->valueType==intType && $3->valueType==floatType){
           			put->valueType = floatType;
            			put->f_value = ((float)$1->i_value - $3->f_value);
        		}else if($1->valueType==floatType && $3->valueType==intType){
           			put->valueType = floatType;
            			put->f_value = ($1->f_value - (float)$3->i_value);
        		}else if($1->valueType==floatType && $3->valueType==floatType){
           			put->valueType = floatType;
            			put->f_value = ($1->f_value - $3->f_value);
        		}else{
				yyerror("minus type error");
			}
			$$=put;
		}|EXPR '*' EXPR {
			Trace("EXPR * EXPR");
			Value* put =new Value;
			if($1->valueType==intType && $3->valueType==intType){
           			put->valueType = intType;
            			put->i_value = ($1->i_value * $3->i_value);
        		}else if($1->valueType==intType && $3->valueType==floatType){
           			put->valueType = floatType;
            			put->f_value = ((float)$1->i_value * $3->f_value);
        		}else if($1->valueType==floatType && $3->valueType==intType){
           			put->valueType = floatType;
            			put->f_value = ($1->f_value * (float)$3->i_value);
        		}else if($1->valueType==floatType && $3->valueType==floatType){
           			put->valueType = floatType;
            			put->f_value = ($1->f_value * $3->f_value);
        		}else{
				yyerror("product type error");
			}
			$$=put;
		}|EXPR '/' EXPR {
			Trace("EXPR / EXPR");
			Value* put =new Value;
			if($1->valueType==intType && $3->valueType==intType){
           			put->valueType = intType;
            			put->i_value = ($1->i_value / $3->i_value);
        		}else if($1->valueType==intType && $3->valueType==floatType){
           			put->valueType = floatType;
            			put->f_value = ((float)$1->i_value / $3->f_value);
        		}else if($1->valueType==floatType && $3->valueType==intType){
           			put->valueType = floatType;
            			put->f_value = ($1->f_value / (float)$3->i_value);
        		}else if($1->valueType==floatType && $3->valueType==floatType){
           			put->valueType = floatType;
            			put->f_value = ($1->f_value / $3->f_value);
        		}else{
				yyerror("divide type error");
			}
			$$=put;
		}|EXPR '%' EXPR {
			Trace("EXPR mod EXPR");
			Value* put =new Value;
			if($1->valueType==intType && $3->valueType==intType){
           			put->valueType = intType;
            			put->i_value = ($1->i_value % $3->i_value);
        		}else if($1->valueType==intType && $3->valueType==floatType){
           			put->valueType = floatType;
            			put->f_value = fmod((double)$1->i_value,(double)$3->f_value);
        		}else if($1->valueType==floatType && $3->valueType==intType){
           			put->valueType = floatType;
            			put->f_value = fmod((double)$1->f_value,(double)$3->i_value);
        		}else if($1->valueType==floatType && $3->valueType==floatType){
           			put->valueType = floatType;
            			put->f_value = fmod((double)$1->f_value,(double)$3->f_value);
        		}else
				yyerror("mod type error");
			$$=put;
		}|'-' EXPR %prec UMINUS {
        		Trace("- EXPR");
        		Value* put = new Value;
        		if ($2->valueType== intType) {
        		    	*put = *$2;
        		    	put->i_value = -1 * put->i_value;
        		}
        		else if($2->valueType== floatType){
        		    	*put = *$2;
        		    	put->f_value = -1 * put->f_value;
        		}
        		else{
        		    yyerror("- EXPR type error");
        		}
        		$$ = put;	
		}|EXPR OR EXPR{
			Trace("EXPR OR EXPR");
        		Value* put = new Value;
       		 	put->valueType = boolType;
        		if($1->valueType!=boolType || $3->valueType!=boolType){
            		yyerror("OR operation must be bool");
        		}
        		else{
         		  put->b_value = $1->b_value || $3->b_value;
        		}
        		$$ = put;
		}|EXPR AND EXPR{
			Trace("EXPR AND EXPR");
        		Value* put = new Value;
       		 	put->valueType = boolType;
        		if($1->valueType!=boolType || $3->valueType!=boolType){
            		yyerror("AND operation must be bool");
        		}
        		else{
         		  put->b_value = $1->b_value && $3->b_value;
        		}
        		$$ = put;
		}|'!' EXPR{
			Trace("NOT EXPR");
        		Value* put = new Value;
       		 	put->valueType = boolType;
        		if($2->valueType!=boolType){
            		yyerror("NOT operation must be bool");
        		}
        		else{
         		  put->b_value = !($2->b_value);
        		}
        		$$ = put;
		}|EXPR LESS EXPR{
			Trace("EXPR < EXPR");
			Value* put = new Value;
       		 	put->valueType = boolType;
			if($1->valueType==intType&&$3->valueType==intType)
			{
				put->b_value=($1->i_value<$3->i_value);
			}else if($1->valueType==intType&&$3->valueType==floatType)
			{
				put->b_value=((float)$1->i_value<$3->f_value);
			}else if($1->valueType==floatType&&$3->valueType==intType)
			{
				put->b_value=($1->f_value<(float)$3->i_value);
			}else if($1->valueType==floatType&&$3->valueType==floatType)
			{
				put->b_value=($1->f_value<$3->f_value);
			}else
				yyerror("< operator type error");
			$$ =put;
		}|EXPR NOT_MORE EXPR{
			Trace("EXPR <= EXPR");
			Value* put = new Value;
       		 	put->valueType = boolType;
			if($1->valueType==intType&&$3->valueType==intType)
			{
				put->b_value=($1->i_value<=$3->i_value);
			}else if($1->valueType==intType&&$3->valueType==floatType)
			{
				put->b_value=((float)$1->i_value<=$3->f_value);
			}else if($1->valueType==floatType&&$3->valueType==intType)
			{
				put->b_value=($1->f_value<=(float)$3->i_value);
			}else if($1->valueType==floatType&&$3->valueType==floatType)
			{
				put->b_value=($1->f_value<=$3->f_value);
			}else
				yyerror("<= operator type error");
			$$ =put;
		}|EXPR MORE EXPR{
			Trace("EXPR > EXPR");
			Value* put = new Value;
       		 	put->valueType = boolType;
			if($1->valueType==intType&&$3->valueType==intType)
			{
				put->b_value=($1->i_value>$3->i_value);
			}else if($1->valueType==intType&&$3->valueType==floatType)
			{
				put->b_value=((float)$1->i_value>$3->f_value);
			}else if($1->valueType==floatType&&$3->valueType==intType)
			{
				put->b_value=($1->f_value>(float)$3->i_value);
			}else if($1->valueType==floatType&&$3->valueType==floatType)
			{
				put->b_value=($1->f_value>$3->f_value);
			}else
				yyerror("> operator type error");
			$$ =put;
		}|EXPR NOT_LESS EXPR{
			Trace("EXPR >= EXPR");
			Value* put = new Value;
       		 	put->valueType = boolType;
			if($1->valueType==intType&&$3->valueType==intType)
			{
				put->b_value=($1->i_value>=$3->i_value);
			}else if($1->valueType==intType&&$3->valueType==floatType)
			{
				put->b_value=((float)$1->i_value>=$3->f_value);
			}else if($1->valueType==floatType&&$3->valueType==intType)
			{
				put->b_value=($1->f_value>=(float)$3->i_value);
			}else if($1->valueType==floatType&&$3->valueType==floatType)
			{
				put->b_value=($1->f_value>=$3->f_value);
			}else
				yyerror(">= operator type error");
			$$ =put;
		}|EXPR EQUAL EXPR{
			Trace("EXPR == EXPR");
			Value* put = new Value;
       		 	put->valueType = boolType;
			if($1->valueType!=$3->valueType){
				yyerror("== operator type not equal");
			}else if($1->valueType==intType&&$3->valueType==intType)
			{
				put->b_value=($1->i_value==$3->i_value);
			}else if($1->valueType==floatType&&$3->valueType==floatType)
			{
				put->b_value=($1->f_value==$3->f_value);
			}else if($1->valueType==boolType&&$3->valueType==boolType)
			{
				put->b_value=($1->b_value==$3->b_value);
			}else if($1->valueType==stringType&&$3->valueType==stringType)
			{
				put->b_value=(*($1->s_value)==*($3->s_value));
			}else if($1->valueType==charType&&$3->valueType==charType)
			{
				put->b_value=(($1->c_value)==($3->c_value));
			}else
				yyerror("== operator type error");
			$$=put;
		}|EXPR NOT_EQUAL EXPR{
			Trace("EXPR != EXPR");
			Value* put = new Value;
       		 	put->valueType = boolType;
			if($1->valueType!=$3->valueType){
				yyerror("!= operator type not equal");
			}else if($1->valueType==intType&&$3->valueType==intType)
			{
				put->b_value=($1->i_value!=$3->i_value);
			}else if($1->valueType==floatType&&$3->valueType==floatType)
			{
				put->b_value=($1->f_value!=$3->f_value);
			}else if($1->valueType==boolType&&$3->valueType==boolType)
			{
				put->b_value=($1->b_value!=$3->b_value);
			}else if($1->valueType==stringType&&$3->valueType==stringType)
			{
				put->b_value=(*($1->s_value)!=*($3->s_value));
			}else if($1->valueType==charType&&$3->valueType==charType)
			{
				put->b_value=(($1->c_value)!=($3->c_value));
			}else
				yyerror("!= operator type error");
			$$=put;
		}|ID{
			Trace("find a ID");
			int exist = all_table.lookup_all(*$1);
			if(exist ==-1){
				Trace("id not exist");
			}
			else //take id info
 			{
				int pos = all_table.table_list[exist].lookup(*$1);
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
					$$=put->idValue;
					Trace("assign id value to expr");
				}
			}
		}|ID '[' INT_VALUE ']'{
			Trace("find a Value(id[int])");
			int exist = all_table.lookup_all(*$1);
			if(exist ==-1){
				Trace("id not exist");
			}
			else //take id info
 			{
				int pos = all_table.table_list[exist].lookup(*$1);
				Identifier* put = all_table.table_list[exist].idList[pos];
				if(put->idType != Array)
				{
					yyerror("expr assign id type must be Array");
				}else
				{
					$$=put->arrayValue[$3];
					Trace("assign id array value to expr");
				}
			}
		}
		|VALUE{$$=$1;}
		;

//number const
VALUE:		INT_VALUE {
				Trace("find a int value");
				$$ = intValue($1);
			}
		|BOOL_VALUE {
				Trace("find a bool value");
				$$ = boolValue($1);
			}
		|FLOAT_VALUE {
				Trace("find a float value");
				$$ = floatValue($1);
			}
		|STRING_VALUE {
				Trace("find a string value");
				$$ = stringValue($1);
			}
		|CHAR_VALUE  {
				Trace("find a char value");
				$$ = charValue($1);
			};
//type get ex.int float

FUNC_TYPE:	':' DATA_TYPE{
			$$ = $2;
		};
DATA_TYPE:	CHAR {
           	 	$$ = charType;
       	  	}
        	| STRING {
          	 	$$ = stringType;
         	}
         	| INT {
             	 	$$ = intType;
         	}
         	| BOOLEAN {
             	 	$$ = boolType;
         	}
         	| FLOAT {
            		$$ = floatType;
         	};
// not yet
zero_or_more_state: ;
methods :	methods method
		|method;
method	:	DEF ID {
			Trace("Method ID");
			int exist = all_table.table_list[table_index].lookup(*$2);
			if(exist !=-1){
				Trace("method id already exist");
			}
		}'(' ARGS ')' BLOCK{
			
			//Identifier* put = $4;//args assign to ID
			//put->idName = *$2;
			//InsertSymbol(put,all_table.table_list[table_index]);
			//Trace("insert  method id");
			//$$ = put;
		}|DEF ID {
			Trace("Method ID with type");
			int exist = all_table.table_list[table_index].lookup(*$2);
			if(exist !=-1){
				Trace("method id already exist");
			}
		}'(' ARGS ')' BLOCK FUNC_TYPE{
			//Identifier* put = $4;//args assign to ID
			//put->idName = *$2;
			//put->funType = $7;
			//InsertSymbol(put,all_table.table_list[table_index]);
			//Trace("insert  method id");
		};
//a:int,b:int
ARGS:		ARG{
			Identifier* put = $1;
			put->parameters.push_back($1);
			put->numOfPara++;
			$$=put;
		}
		|ARGS ',' ARG{
			Identifier* put = $1;
			put->parameters.push_back($3);
			put->numOfPara++;
			$$=put;
		}|/* empty*/
		;
ARG:		ID ':' DATA_TYPE{
			Identifier* put = new Identifier;
			put->idName = *$1;
			put->idValue = new Value;
			put->idType = Function;
			put->idValue->valueType = $3;
			InsertSymbol(put,all_table.table_list[table_index]);
			Trace("insert id");
		};
FUNC_INVOCATION:;
STATEMENTS:	STATEMENT STATEMENTS
		|/*empty*/
		;
STATEMENT:	SIMPLE
		|CONDITION
		|LOOP;
BLOCK:		'{' {
			Trace("BLOCK start");
			SymbolTable put = SymbolTable();
			table_index++;
			all_table.push();
		} declarations STATEMENTS '}'{
			Trace("BLOCK end");
			all_table.table_list[table_index].dump();
			all_table.pop();
			table_index--;
		};
CONDITION: 	IF_CONDITION
		|IF_CONDITION ELSE_CONDITION;

IF_CONDITION:	IF '(' EXPR ')' SIMPLE{
			Trace("IF with simple");
		}|IF '(' EXPR ')' BLOCK{
			Trace("IF with block");
		};
ELSE_CONDITION:	ELSE SIMPLE{
			Trace("else with simple");
		}|ELSE BLOCK{
			Trace("else with block");
		};
LOOP: 		WHILE_LOOP|FOR_LOOP;

WHILE_LOOP:	WHILE '(' EXPR ')' SIMPLE{
			Trace("while loop with simple");
		}|WHILE '(' EXPR ')' BLOCK{
			Trace("while loop with block");
		};
FOR_LOOP:	FOR '(' ID LESS '-' EXPR TO EXPR ')' SIMPLE{
			Trace("for loop with simple");
			if($6->valueType!=intType||$8->valueType!=intType)
			{
				yyerror("for loop args must be int");
			}
		}|FOR '(' ID LESS '-' EXPR TO EXPR ')' BLOCK{
			Trace("for loop with simple");
			if($6->valueType!=intType||$8->valueType!=intType)
			{
				yyerror("for loop args must be int");
			}
		};
SIMPLE: 	ID '=' EXPR{
			Trace("assign expr to id");
			int exist = all_table.lookup_all(*$1);
			if(exist ==-1)
				yyerror("id not exist");
			else //insert id
			{	
				int pos = all_table.table_list[exist].lookup(*$1);
				Identifier* put = all_table.table_list[exist].idList[pos];
				if(put->idValue->valueType!=$3->valueType)
				{
					yyerror("assign error, type error");
				}else{
					put->idValue=$3;
					Trace("assign id done");
				}
				
			}
		}|ID '[' INT_VALUE ']' '=' EXPR{
			Trace("assign expr to id array's value");
			int exist = all_table.lookup_all(*$1);
			if(exist ==-1)
				yyerror("id not exist");
			else //insert id
			{	
				int pos = all_table.table_list[exist].lookup(*$1);
				Identifier* put = all_table.table_list[exist].idList[pos];
				if(put->idType!=Array)
				{
					yyerror("must be array");
				}else if(put->arrayValueType!=$6->valueType){
					yyerror("type error");
				}else {
					put->arrayValue[$3] = $6;
					Trace("assign to array's value done");
				}
				
			}
		}|PRINT '(' EXPR ')'{
			Trace("print expr");
		}|PRINTLN '(' EXPR ')'{
			Trace("println expr");
		}|READ ID{
			Trace("read id");
		}|RETURN{
			Trace("return");
			//return new Value;
		}|RETURN EXPR{
			Trace("return expr");
			//return $2;
		};
comma_sep_EXPR:;
program:        OBJECT ID
                { 
			Trace("program start");
			Identifier* put = new Identidier;
			put->idName = *$2;
			put->idType = Object;
			all_table.push();
			InsertSymbol(put,all_table.table_list[table_index]);
			
                }'{' declarations methods '}'
		{
			Trace("program end");
			all_table.dump();
			all_table.pop();
                };

%%
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
