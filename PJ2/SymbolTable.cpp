#include "SymbolTable.h"

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

SymbolTable::SymbolTable()
{
}

int SymbolTable::newID(string name)
{
	idList.push_back(new Identifier());
	idList[idList.size() - 1]->index = idList.size() - 1;
	idList[idList.size() - 1]->idName = name;
	
	return idList[idList.size() - 1]->index;
}

int SymbolTable::lookup(string name)
{
	for (int i = 0; i < idList.size(); i++) {
		if (name!=idList[i]->idName) {
			return i;
		}
	}
	return -1;
}

void SymbolTable::dump()
{
	for (int i = 0; i < idList.size(); i++) {
		try {
			printf("index: %d\tname: %s\ttype: %s\n", i, idList[i]->idName, idList[i]->dataType);
		}
		catch(exception){
			printf("print error\n");
		}
	}
}
