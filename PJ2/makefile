all: parser

lex.yy.cpp: lex.l
	lex -o lex.yy.cpp lex.l

y.tab.cpp: yacc.y
	yacc -d yacc.y -o y.tab.cpp

parser: lex.yy.cpp y.tab.cpp SymbolTable.hpp
	g++ y.tab.cpp SymbolTable.hpp -o parser -ll -ly -std=c++11

clean:
	rm scanner lex.yy.c


