chars [a-zA-Z]
digits [0-9]
special [$_@]
space " "
newline "\n"
Datatype "int"|"float"|"char"|"double"|"void"|"string"
Arithmatic_operator "+"|"-"|"/"|"*"|"&"|"|"|"mod"
Logical_operator "&&"|"||"|"!!"|"^^"
Unary_operator "#++"|"#--"|"!#"
Relation_operator "less"|"great"|"eqeq"|"great_eq"|"less_eq"|"noteq"
Assignment_operator "="|"+="|"-="|"/="|"*="
integer (-|+)?[0-9]+
char [A-Za-z]+
Identifiers [a-zA-Z][a-zA-Z0-9]*
S_comment \/\/[^\n]*
M_comment \/\*([^*]|\*[^\/])*\*\/

%{
	#include "1907031.tab.h"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	int varindex(char *var);
	extern int yylex();
	extern int yyparse();
	extern FILE *yyin;
	extern FILE *yyout;
	int yyerror(char *s);
	//int lineNo = 1;
%}

%%

{S_comment} { printf("Single Line Comment\n"); }
{M_comment} { printf("Multiple Line Comment\n"); }

"int" { return INT; }
"float"	{ return FLOAT; }
"string" { return STRING; }

"(" { return '('; }
")"	{ return ')'; }
"<" { return '<'; }
">"	{ return '>'; }
"{"	{ return '{'; }
"}"	{ return '}'; }
";" { return END; }
"," { return ','; }
"="	{ return '='; }

"-"?{digits}+ {
	yylval.num = atoi(yytext);
	return NUMBER;
}
"-"?({digits}+)?"."{digits}+ {
	yylval.num = atof(yytext);
	return NUMBER;
}

{Identifiers} { 
	yylval.string = strdup(yytext);
	return VARIABLE; 
}

{Datatype}[ ]+"main" { return MAIN; }
"#include" { return IMPORT; }
{Identifiers}".h" { return HEADER; }

[ \t\n]*

. {yyerror("Unknown Character.\n");}

%%