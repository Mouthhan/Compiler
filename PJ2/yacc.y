%{
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
string objName = "";
int now_stack = 0;
int label_count = 0;
int begin_label = 0;
int end_label = 0; 
int else_label = 0;
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
%token OR AND EQUAL LESS NOT_MORE NOT_LESS MORE NOT_EQUAL NOT
/* reserve word  */
%token SEMICOLON BOOLEAN BREAK CHAR CASE CLASS CONTINUE DEF DO ELSE EXIT BOOL_FALSE FLOAT FOR IF INT _NULL OBJECT PRINT PRINTLN READ REPEAT RETURN STRING TO BOOL_TRUE TYPE VAL VAR WHILE
/* value get  */
//%token INTEGER BOOL REAL_NUM ID STR

%token <i_val> INT_VALUE
%token <f_val> FLOAT_VALUE
%token <b_val> BOOL_VALUE BOOL_TRUE BOOL_FALSE
%token <s_val> STRING_VALUE
%token <c_val> CHAR_VALUE
%token <s_val> ID
/* type  */
%type <valueType> DATA_TYPE FUNC_TYPE
%type <idType> ARGS ARG methods 
%type <idType> method
%type <idType> FUNC_BLOCK
%type <value> VALUE EXPR FUNC_INVOCATION
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
const_dec:	VAL ID '='//val a = 10
		{
			const_val = true;
		}EXPR{
			Trace("VAL ID = EXPR");
			int exist = all_table.table_list[table_index].lookup(*$2);
			if(exist !=-1){
				yyerror("id already exist");
			}
			else //insert id
			{
				Identifier* put = new Identidier;
				put->idName = *$2;
				put->idType = Const;
				put->idValue = $5; 
				InsertSymbol(put,all_table.table_list[table_index]);
				Trace("insert id val & value");
			}
		}|
		VAL ID ':' DATA_TYPE '='//val a:int = 10
		{
			const_val = true;
		}EXPR{
			Trace("VAL ID :TYPE = EXPR");
			int exist = all_table.table_list[table_index].lookup(*$2);
			if(exist !=-1){
				Trace("id already exist");
			}
			if($4 != $7->valueType){
				Trace("type different");
			}
			else //insert id
			{
				Identifier* put = new Identidier;
				put->idName = *$2;
				put->idType = Const;
				put->idValue = $7; 
				InsertSymbol(put,all_table.table_list[table_index]);
				Trace("insert id val & type & value");
			}
		};
//var declaration
var_dec:	VAR ID//var a
		{
			Trace("VAR ID");
			int exist = all_table.table_list[table_index].lookup(*$2);
			if(exist !=-1){
				yyerror("id already exist");
			}
			else //insert id
			{
				int check = all_table.lookup_all(*$2);
				Identifier* put = new Identidier;
				put->idName = *$2;
				put->idType = Var; 
				Trace("insert id var");
				//global
				//cout<<"check:"<<check<<endl;
				if(table_index==0){
					java<<"\tfield static int "<<*$2<<endl;
				}
				else{
					java_push(0);
					put->index = now_stack;
					java_store(now_stack++);
				}
				InsertSymbol(put,all_table.table_list[table_index]);
			}
		}|
		VAR ID ':' DATA_TYPE//var a:int
		{
			Trace("VAR ID:TYPE");
			int exist = all_table.table_list[table_index].lookup(*$2);
			if(exist !=-1){
				yyerror("id already exist");
			}
			else //insert id
			{
				int check = all_table.lookup_all(*$2);
				Identifier* put = new Identidier;
				put->idName = *$2;
				put->idType = Var; 
				put->idValue = new Value;
				put->idValue->valueType = $4;
				Trace("insert id var & type");
				//global
				if(table_index==0){
					java<<"\tfield static int "<<*$2<<endl;
				}
				else{
					java_push(0);
					put->index = now_stack;
					java_store(now_stack++);
				}
				InsertSymbol(put,all_table.table_list[table_index]);
			}
		}|
		VAR ID '=' {
			const_val = true;
		}EXPR//var a = 3
		{
			Trace("VAR ID=EXPR");
			int exist = all_table.table_list[table_index].lookup(*$2);
			if(exist !=-1){
				yyerror("id already exist");
			}
			else //insert id
			{
				int check = all_table.lookup_all(*$2);
				Identifier* put = new Identidier;
				put->idName = *$2;
				put->idType = Var; 
				put->idValue = $5;
				Trace("insert id va & value");
				//global
				if(table_index==0){
					java<<"\tfield static int "<<*$2<<endl;
				}
				else{
					put->index = now_stack;
					java_store(now_stack++);
				}
				InsertSymbol(put,all_table.table_list[table_index]);
			}
		}|
		VAR ID ':' DATA_TYPE '=' {
			const_val = true;
		}EXPR//var a:int = 3
		{

			Trace("VAL ID :TYPE = EXPR");
			int exist = all_table.table_list[table_index].lookup(*$2);
			if(exist !=-1){
				yyerror("id already exist");
			}else{
				if($4 != $7->valueType){
					Trace("type different");
				}
				else //insert id
				{
					int check = all_table.lookup_all(*$2);
					Identifier* put = new Identidier;
					put->idName = *$2;
					put->idType = Var;
					put->idValue = $7; 
					Trace("insert id var & type & value");
					//global
					if(table_index==0){
						java<<"\tfield static int "<<*$2<<endl;
					}
					else{
						put->index = now_stack;
						java_store(now_stack++);
					}
					InsertSymbol(put,all_table.table_list[table_index]);
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
					Value* tmp = new Value;
					tmp->valueType = $4;
        				put->arrayValue.push_back(tmp);
    				}
				InsertSymbol(put,all_table.table_list[table_index]);
				Trace("insert id(array)");
			}

			
		};
		;
EXPR:		'(' EXPR ')'{
			$$=$2;
		}/*|EXPR '=' EXPR {
			Trace("EXPR = EXPR");
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
				{yyerror("assign type error");}
			$$=put;
		}*/|FUNC_INVOCATION {
			Trace("into call function");
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
			java << "\t\tiadd" << endl;
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
			java << "\t\tisub" << endl;
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
			java << "\t\timul" << endl;
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
			java << "\t\tidiv" << endl;
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
			java << "\t\tineg" << endl;	
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
			java << "\t\tior" << endl;
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
			java << "\t\tiand" << endl;
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
			java << "\t\tldc 1" << endl << "\t\tixor" << endl;
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
			java << "\t\tisub"<<endl; 
			java << "\t\tiflt L" <<label_count<< endl;
			java << "\t\ticonst_0"<< endl;
			java << "\t\tgoto L"<<label_count+1<<endl;
			java << "L"<<label_count<<":"<<endl;
			java << "\t\ticonst_1"<<endl;
			java << "L"<<label_count+1<<":"<<endl;
			label_count+=2;
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
			java << "\t\tisub"<<endl;
			java << "\t\tifle L"<<label_count << endl;
			java << "\t\ticonst_0"<< endl;
			java << "\t\tgoto L"<<label_count+1<<endl;
			java << "L"<<label_count<<":"<<endl;
			java << "\t\ticonst_1"<<endl;
			java << "L"<<label_count+1<<":"<<endl;
			label_count+=2;
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
			java << "\t\tisub"<<endl;
			java << "\t\tifgt L" <<label_count<< endl;
			java << "\t\ticonst_0"<< endl;
			java << "\t\tgoto L"<<label_count+1<<endl;
			java << "L"<<label_count<<":"<<endl;
			java << "\t\ticonst_1"<<endl;
			java << "L"<<label_count+1<<":"<<endl;
			label_count+=2;
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
			java << "\t\tisub"<<endl;
			java << "\t\tifge L" <<label_count<< endl;
			java << "\t\ticonst_0"<< endl;
			java << "\t\tgoto L"<<label_count+1<<endl;
			java << "L"<<label_count<<":"<<endl;
			java << "\t\ticonst_1"<<endl;
			java << "L"<<label_count+1<<":"<<endl;
			label_count+=2;
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
			java << "\t\tisub"<<endl;
			java << "\t\tifeq L"<<label_count << endl;
			java << "\t\ticonst_0"<< endl;
			java << "\t\tgoto L"<<label_count+1<<endl;
			java << "L"<<label_count<<":"<<endl;
			java << "\t\ticonst_1"<<endl;
			java << "L"<<label_count+1<<":"<<endl;
			label_count+=2;
		}|EXPR NOT_EQUAL EXPR{
			Trace("EXPR != EXPR");
			Value* put = new Value;
       		 	put->valueType = boolType;
			if($1->valueType!=$3->valueType){
				//cout<<"$1Type:"<<$1->valueType<<"$3Type:"<<$3->valueType<<endl;
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
			java << "\t\tisub"<<endl;
			java << "\t\tifne L"<<label_count << endl;
			java << "\t\ticonst_0"<< endl;
			java << "\t\tgoto L"<<label_count+1<<endl;
			java << "L"<<label_count<<":"<<endl;
			java << "\t\ticonst_1"<<endl;
			java << "L"<<label_count+1<<":"<<endl;
			label_count+=2;
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
				}else if(put->idType == Object)
				{
					yyerror("expr assign id type is Object");
				}else
				{
					$$=put->idValue;
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
						java << "\t\tgetstatic int " << now_class << "." << *$1 << endl;
					}
				}else{
					java_load(put->index);
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
		}|ID '[' ID ']'{
			Trace("find a Value(id[int])");
			int exist = all_table.lookup_all(*$1);
			if(exist ==-1){
				Trace("id not exist");
			}
			else //take id info
 			{
				//a[b]
				int pos = all_table.table_list[exist].lookup(*$1);
				Identifier* put = all_table.table_list[exist].idList[pos];//a
				if(put->idType != Array)
				{
					yyerror("expr assign id type must be Array");//b
				}else
				{
					int exist = all_table.lookup_all(*$3);
					if(exist ==-1){
						Trace("array index id not exist");
					}
					else{
						int pos = all_table.table_list[exist].lookup(*$3);
						Identifier* tmp = all_table.table_list[exist].idList[pos];
						if (tmp->idValue->valueType!=intType){
							Trace("index must be integer");
						}
						else{
							$$=put->arrayValue[tmp->idValue->i_value];
							Trace("assign id array value to expr");
						}
						
					}
				}
			}
		}
		|VALUE{
			$$=$1;
		}
		;

//number const
VALUE:		INT_VALUE {
				Trace("find a int value");
				$$ = intValue($1);
				if(!const_val){
					java_push($1);
				}
				const_val = false;
			}
		|BOOL_VALUE {
				Trace("find a bool value");
				$$ = boolValue($1);
				if(!const_val){
					if($1){
						java<<"\t\ticonst_1"<<endl;
					}else{
						java<<"\t\ticonst_0"<<endl;
					}	
				}
				const_val = false;
			}
		|FLOAT_VALUE {
				Trace("find a float value");
				$$ = floatValue($1);
			}
		|STRING_VALUE {
				Trace("find a string value");
				$$ = stringValue($1);
				if(!const_val){
					java << "\t\tldc " << "\"" << *$1 << "\"" << endl;
				}
				const_val = false;
			}	
		|CHAR_VALUE  {
				Trace("find a char value");
				$$ = charValue($1);
			};
//type get ex.int float

FUNC_TYPE:	':' DATA_TYPE{
			Trace("function has return type");
			$$ = $2;
		}|{$$ = valueTypeError;}/*empty*/;
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
zero_or_more_state: 	STATEMENTS
			|/*empty*/
			;
methods :	methods method
		|method;
method	:	DEF ID {
			has_return = false;
			Trace("Method ID");
			now_stack = 0;
			int exist = all_table.table_list[table_index].lookup(*$2);
			if(exist !=-1&&all_table.table_list[table_index].idList[exist]->idType==Function){
				yyerror("method id already exist");
			}
			else{
				java<<"\tmethod public static ";
				funcName = *$2;
			}
		} '(' {
			Trace("FUNC_BLOCK start");
			SymbolTable put = SymbolTable();
			table_index++;
			all_table.push();
		} ARGS ')' FUNC_TYPE	{
			$<idType>$ = $6;
			$<idType>$->funType = $8;
			Trace("before FUNC_BLOCK");
			if($<idType>$->funType == valueTypeError){
				java<<"void ";
			}else{
				//cout<<$<idType>$->funType<<endl;
				java<<valueType2String($<idType>$->funType)<<" ";
			}
			//name
			java<<funcName;
			//no args
			if($<idType>$->numOfPara == 0){
				java<<"(java.lang.String[])"<<endl;
				java<<"\tmax_stack 15"<<endl;
				java<<"\tmax_locals 15"<<endl;
			}else{
				//print args
				java<<"(";
				for(int i = 0;i<$<idType>$->numOfPara;i++){
					if(i==$<idType>$->numOfPara-1){
						java<<valueType2String($<idType>$->parameters[i]->idValue->valueType)<<")"<<endl;
					}else{
						java<<valueType2String($<idType>$->parameters[i]->idValue->valueType)<<",";
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
		}	FUNC_BLOCK{	
			Trace("done FUNC_BLOCK");
			Identifier* put = $6;
			put->idName = *$2;
			put->idType = Function;
			put->funType = $8;
			cout<<put->numOfPara<<endl;
			InsertSymbol(put,all_table.table_list[table_index]);
			if((put->funType == valueTypeError )&& (!has_return)){
				java<<"\t\treturn"<<endl;
			}
			java<<"\t}"<<endl;
			Trace("insert ok");
		};

FUNC_BLOCK:	'{' declarations zero_or_more_state '}'{
			all_table.table_list[table_index].dump();
			all_table.pop();
			table_index--;
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
			$1=put;
		}|/* empty*/ {
			Identifier* put =new Identifier;
			put->idType = Function;
			$$ = put;
			cout<<$$->idType<<endl;
		};
ARG:		ID ':' DATA_TYPE{
			int exist = all_table.table_list[table_index].lookup(*$1);
			if(exist != -1){
				yyerror("id already exist");
			}else{
				Identifier* put = new Identifier;
				put->idName = *$1;
				put->idValue = new Value;
				put->idType = Var;
				put->idValue->valueType = $3;
				if(exist == IsGLOBAL){
            				
       				}
       				else{
            				put->index = now_stack;
					now_stack++;
        			}
				Trace("insert id(argument)");
				InsertSymbol(put,all_table.table_list[table_index]);
				$$=put;
			}
		}|ID{
			Trace("arg = id");
			int exist = all_table.lookup_all(*$1);
			if(exist ==-1)
				yyerror("arg not exist");
			else 
			{	
				int pos = all_table.table_list[exist].lookup(*$1);
				Identifier* put = all_table.table_list[exist].idList[pos];
				$$=put;
			}
		}|EXPR{
			Trace("arg = expr");
			Identifier* put = new Identifier;
			put->idValue=$1;
			$$ = put;
		}|VALUE{
			Trace("arg = value");
			Identifier* put = new Identifier;
			put->idValue=$1;
			$$=put;
		};
FUNC_INVOCATION:	ID {
				Trace("start call function");
			}'(' ARGS ')'{
				Trace("call function done");
				int exist = all_table.lookup_all(*$1);
				cout<<"$1="<<*$1<<endl;
				if(exist ==-1)
					yyerror("function not exist");
				else //insert id
				{	
					int pos = all_table.table_list[exist].lookup(*$1);
					Identifier* put = all_table.table_list[exist].idList[pos];
					if(put->idType!=Function){
						yyerror("type must be function");
					}else{
						if(put->numOfPara!=$4->numOfPara)
						{
							yyerror("argument number must be the same");
						}
						else{
							for(int i=0;i<put->numOfPara;i++){
								if(put->parameters[i]->idValue->valueType!=$4->parameters[i]->idValue->valueType){
									yyerror("argument type error");
								}
							}
							$$= put->idValue;
							$$->valueType = put->funType;
							java<<"\t\tinvokestatic "<<valueType2String(put->funType)<<" "<<objName<<"."<<*$1;
							java<<"(";
							for(int i =0;i<put->numOfPara;i++){
								if(i!=put->numOfPara-1){
									java<<valueType2String(put->parameters[i]->idValue->valueType)<<", ";
								}else{
									java<<valueType2String(put->parameters[i]->idValue->valueType)<<")"<<endl;
								}
							}
						}
					}
				}
			};
STATEMENTS:	STATEMENT STATEMENTS
		|STATEMENT
		|/*empty*/
		;
BLOCK_OR_SIMPLE: BLOCK|SIMPLE;
STATEMENT:	SIMPLE
		|CONDITION{Trace("exit Condition");}
		|LOOP{Trace("into Loop");};
BLOCK:		'{' {
			Trace("123");
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

IF_CONDITION:	IF '(' EXPR ')' {
			Trace("IF condition");
			if($3->valueType!=boolType){
				yyerror("if condition expr must be bool");
			}
			java<<"\t\tifeq L"<<label_count<<endl;
			else_label = label_count;
		}SIMPLE{
			Trace("if with simple");
			java<<"\t\tgoto L"<<label_count+1<<endl;
			label_count+=1;
		}|IF '(' EXPR ')' {
			Trace("IF condition");
				if($3->valueType!=boolType){
				yyerror("if condition expr must be bool");
			}
			java<<"\t\tifeq L"<<label_count<<endl;
			else_label = label_count;
		}BLOCK{
			Trace("if with block");
			java<<"\t\tgoto L"<<label_count+1<<endl;
			label_count+=1;
		};
ELSE_CONDITION:	ELSE {
			java<<"L"<<else_label<<":"<<endl;
		}SIMPLE{
			Trace("else with simple");
			java<<"L"<<label_count<<":"<<endl;
			label_count+=1;
		}|ELSE {
			java<<"L"<<else_label<<":"<<endl;
		}BLOCK{
			Trace("else with block");
			java<<"L"<<label_count<<":"<<endl;
			label_count+=1;
		};
LOOP: 		WHILE_LOOP|FOR_LOOP;

WHILE_LOOP:	WHILE {
			java<<"L"<<label_count<<":"<<endl;
			begin_label = label_count;
			label_count++;
		}'(' EXPR ')' {
			java<<"\t\tifeq L"<<label_count<<endl;
			end_label = label_count;
			label_count++;
		}BLOCK_OR_SIMPLE {
			Trace("while loop with simple");
			if($4->valueType!=boolType){
				yyerror("while loop expr must be bool");
			}
			java<<"\t\tgoto L"<<begin_label<<":"<<endl;
			java<<"L"<<end_label<<":"<<endl;
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
				if(exist==IsGLOBAL){
					java<<"\t\tputstatic "<<valueType2String(put->idValue->valueType)<<" "<<now_class<<"."<<*$1<<endl;
				}else{
					java_store(put->index);
				}
			}
		}|ID '[' EXPR ']' '=' EXPR{
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
					//array value assign not yet
					//put->arrayValue[$3] = $6;
					Trace("assign to array's value done");
				}
				
			}
		}|PRINT  {
			java<<"\t\tgetstatic java.io.PrintStream java.lang.System.out"<<endl;
		}EXPR {
			if($3->valueType == stringType){
				java<<"\t\tinvokevirtual void java.io.PrintStream.print(java.lang.String)"<<endl;
			}else{
				java<<"\t\tinvokevirtual void java.io.PrintStream.print("<<valueType2String($3->valueType)<<")"<<endl;
			}
			Trace("print expr");
		}|PRINTLN {
			java<<"\t\tgetstatic java.io.PrintStream java.lang.System.out"<<endl;
		} EXPR {
			if($3->valueType == stringType){
				java<<"\t\tinvokevirtual void java.io.PrintStream.println(java.lang.String)"<<endl;
			}else{
				java<<"\t\tinvokevirtual void java.io.PrintStream.println("<<valueType2String($3->valueType)<<")"<<endl;
			}
			Trace("println expr");
		}|READ ID{
			Trace("read id");
		}|RETURN{
			Trace("return");
			java<<"\t\tretrun"<<endl;
			has_return = true;
			//return new Value;
		}|RETURN EXPR{
			Trace("return expr");
			java<<"\t\tiretrun"<<endl;
			has_return = true;
			//return $2;
		};
comma_sep_EXPR:;
program:        OBJECT ID
                { 
			Trace("program start");
			Identifier* put = new Identidier;
			now_class = *$2;
			put->idName = *$2;
			objName = *$2;
			put->idType = Object;
			all_table.push();
			InsertSymbol(put,all_table.table_list[table_index]);
			java<<"class "<<*$2<<endl;
			java<<"{"<<endl;
			
                }'{' declarations methods '}'
		{
			if(all_table.lookup_all("main")==-1){
				yyerror("must have main");
			}
			Trace("program end");
			java<<"}"<<endl;
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
