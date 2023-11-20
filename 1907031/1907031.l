digits [0-9]
Datatype "int"|"float"|"void"|"string"
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

{S_comment} { printf("\nSingle Line Comment\n"); }
{M_comment} { printf("\nMultiple Line Comment\n"); }

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
":" { return ':'; }

"+"	{ return '+'; }
"-"	{ return '-'; }
"*"	{ return '*'; }
"/"	{ return '/'; }
"^"	{ return '^'; }
"mod" { return MOD; }

"less" { return LT; }
"great"	{ return GT; }
"equal"	{ return EQ; }
"great_eq" { return GEQ; }
"less_eq" { return LEQ; }
"not_eq" { return NEQ; }

"++" { return INC; }
"--" { return DEC; }
"!"	{ return NOT; }

"sin" { return SIN; }
"cos" { return COS; }
"tan" { return TAN; }
"ln" { return LN; }
"log" { return LOG; }
"isOddEven" { return ODDEVEN; }
"factorial"	{ return FACTORIAL; }
"max" { return MAX; }
"min" { return MIN; }
"isPrime" { return PRIME; }

"print" { return DISPLAY; }

"if" { return IF; }
"else_if" { return ELSE_IF; }
"else" { return ELSE; }

"for" { return FOR; }
"inc" { return FLINC; }
"dec" { return FLDEC; }
"while" { return WHILE; }

"case" { return CASE; }
"switch" { return SWITCH; }
"default" { return DEFAULT; }

"-"?{digits}+ {
	yylval.string = strdup(yytext);
	return NUMBER;
}

"-"?({digits}+)?"."{digits}+ {
	yylval.string = strdup(yytext);
	return NUMBER;
}

"\""[^"]*"\"" {
	yylval.string = strdup(yytext);
	return STR;
}

{Datatype}[ ]+"main" { return MAIN; }
"#include" { return IMPORT; }
{Identifiers}".h" { return HEADER; }

"function" { return DEF; }

{Identifiers} { 
	yylval.string = strdup(yytext);
	return VARIABLE; 
}

[ \t\n]*

. {yyerror("Unknown Character.\n");}

%%