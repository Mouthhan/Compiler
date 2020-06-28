#include <vector>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;
enum valueType
{
   	 intType,
   	 floatType,
    	boolType,
    	charType,
   	 stringType,
   	 valueTypeError,
};
string idType2String(int idType)
{
    switch (idType)
    {
    case 0:
        return "Array";
    case 1:
        return "Function";
    case 2:
        return "Const";
    case 3:
        return "Variable";
    case 4:
        return "Object";
    case 5:
        return "Error";
    default:
        return ("cant find idtype");
    }
}

string valueType2String(int valueType)
{
    switch (valueType)
    {
    case 0:
        return "int";
    case 1:
        return "float";
    case 2:
        return "boolean";
    case 3:
        return "char";
    case 4:
        return "string";
    case 5:
        return "error";
    default:
        return ("cant find valuetype");
    }
}

typedef struct Value {
	int valueType = valueTypeError;
	int i_value = 0;
	float f_value = 0;
	char c_value = '\0';
	string *s_value = new string;
	bool b_value = false;
}Value;

enum IDType
{
   	 Array,
   	 Function,
   	 Const,
   	 Var,
    	 Object,
  	 idTypeError,
 
};


typedef struct Identifier {
	int index=-1;//stack
	int idType = idTypeError;
	string idName = "";
	Value* idValue= new Value;
	vector<Value*> arrayValue;
	int arraySize =0;
	int arrayValueType = valueTypeError;
	//for function
	int funType = valueTypeError;
	int numOfPara=0;
	vector<Identifier*> parameters;
}Identidier;

class SymbolTable{
public:
	SymbolTable()
	{
	}

	int newID(string name)
	{
		idList.push_back(new Identifier());
		idList[idList.size() - 1]->index = idList.size() - 1;
		idList[idList.size() - 1]->idName = name;
		
		return idList[idList.size() - 1]->index;
	}

	int lookup(string name)//id position
	{
		for (int i = 0; i < idList.size(); i++) {
			if (name==idList[i]->idName) {
				return i;
			}
		}
		return -1;
	}
	
	void dump()
	{
		cout<<"--------------Dump Table----------------"<<endl;
		cout<<"idCount:"<<idList.size()<<endl;
		for (int i = 0; i < idList.size(); i++) {
			cout<<"index:"<<i<<"\t\t";
			cout<<"name:"<<idList[i]->idName<<"\t\t";
			cout<<"idtype:"<<idType2String(idList[i]->idType)<<"\t\t";
			if(idList[i]->idType == Array)
			{
				cout<<"valueType:"<<valueType2String(idList[i]->arrayValueType)<<endl;
			}else{
				cout<<"valueType:"<<valueType2String(idList[i]->idValue->valueType)<<endl;
			}
		}
	}

	vector<Identifier*> idList;
	
};
class SymbolTables
{
public:
	vector<SymbolTable> table_list; 
	int index;
	int table_num; //which Symboltable is
	SymbolTables()
	{
		index=-1;
		table_num=0;
	}
	void push()
	{
		table_list.push_back(SymbolTable());
		index++;
	}
	void pop()
	{
		table_list.pop_back();
		index--;
	}
	int lookup_all(string name)//return which table
	{
		for (int i = index; i >=0; i--) {
			int check=table_list[i].lookup(name);//table
			if(check!=-1)
				return i;
		}
		return -1;//all not exist
	}
	void dump()
	{
		if(index>=0)
		{
			table_list[index].dump();
		}
	}
};


Value *stringValue(string *s)
{
	Value *put = new Value();
	put->valueType = stringType;
   	put->s_value = s;
   	return put;
}

Value *intValue(int i)
{
	Value *put = new Value();
	put->valueType = intType;
   	put->i_value = i;
   	return put;
}

Value *floatValue(float f)
{
	Value *put = new Value();
	put->valueType = floatType;
   	put->f_value = f;
   	return put;
}

Value *boolValue(bool b)
{
	Value *put = new Value();
	put->valueType = boolType;
   	put->b_value = b;
   	return put;
}

Value *charValue(char c)
{
	Value *put = new Value();
	put->valueType = charType;
   	put->c_value = c;
   	return put;
}


