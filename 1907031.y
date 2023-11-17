%{
#include<stdio.h>
#include <math.h>
#include<stdlib.h>
#include<string.h>
extern FILE *yyin;
extern FILE *yyout;
int lineNo = 0;
int yylex();
int yyerror(char *s);

// Symbol Table Arrays
char var_name[1000][1000];
int store[1000];
float store_float[1000];
int type[1000];
int ttp = 0; // 0 = int, 1 = float, 2 = string

// Variable Counter
int var_cnt = 0;

// Variable Declaration Check
int chkDeclared(char *s){
    int i;
    for(i=0; i<var_cnt; i++){
        if(strcmp(var_name[i], s) == 0)
                return 1;
    }
    return 0;
}

// New Variable Declaration
int init_asn(char *s){
    if(chkDeclared(s) == 1){
        return 0;
    }
    strcpy(var_name[var_cnt], s);
    store[var_cnt] = 0;
    type[var_cnt] = ttp;
    char name[10];
    if(ttp == 0) {
        strcpy(name, "Int");
    }
    else if(ttp == 1) {
        strcpy(name, "Float");
    }
    else if(ttp == 2) {
        strcpy(name, "String");
    }
    printf("\nNew Variable Declared With Name: %s and Type: %s\n", var_name[var_cnt], name);
    var_cnt++;
    return 1;
}

// Assigning Value to Variable
int setValue(char *s, int val){
    if(chkDeclared(s) == 0){
        return 0;
    }
    int ok=0, i;
    for(i=0; i<var_cnt; i++){
        if(strcmp(var_name[i], s) == 0){
            ok = i;
            break;
        }
    }
    store[ok] = val;
    printf("\nNew Value Assigned to Variable Name: %s and Value: %d\n", var_name[ok], store[ok]);
    return 1;
}

// Get Variable Value
int getValue(char *s){
    int pos=-1;
    int i;
    for(i=0; i<var_cnt; i++){
        if(strcmp(var_name[i], s) == 0){
            pos=i;
            break;
        }
    }
    return pos;
}
%}

%union
{
    int num;
    float flt;
    char* string;
};

%token END INT FLOAT STRING
%token <string> VARIABLE
%token <num> NUMBER
%type <num> expression
%token IMPORT HEADER MAIN

%%

start: 
    | start program
    ;

program:
    import main '(' ')' '{' statements '}'  {printf("\nProgram successfully ended\n");}
    | /* NULL */
    ;

main: MAIN {printf("\nMain Function Declared!\n");}

import: IMPORT '<' HEADER '>' { printf("\nHeader File Found!\n"); }
    | /* NULL */
    ;

statements:  statements cstatement
	| /* NULL */
	;

cstatement: END
	| declare
	| expression END
    | VARIABLE '=' expression END {
		if(chkDeclared($1) == 0) {
			printf("\n%s Not Declared!\n", $1);
		}
		else {
			setValue($1, $3);
		}
	}
    ;

declare	:
	type id END { printf("\nValid Syntax!\n"); } 
	;

type	:
	INT { ttp = 0;}
	| FLOAT  { ttp = 1;}
	| STRING  { ttp = 2;}
	;

id	:
	id ',' VARIABLE {
        if(chkDeclared($3)==1) {
            printf("\nDuplicate Declaration!\n");
        }
        else {
            init_asn($3);
        }
    }
    | id ',' VARIABLE '=' expression {
        if(chkDeclared($3)==1) {
            printf("\nDuplicate Declaration!\n");
        }
        else {
            init_asn($3);
            setValue($3, $5); 
        }
    }
	| VARIABLE {
        if(chkDeclared($1)==1)
            printf("\nDuplicate Declaration!\n");
        else
            init_asn($1);
	}
    | VARIABLE '=' expression {
        if(chkDeclared($1)==1) {
            printf("\nDuplicate Declaration!\n");
        }
        else {
            init_asn($1);
            setValue($1, $3);
        }
    }
    ;

expression:
	NUMBER {
		$$ = $1;
	}

	| VARIABLE {
        if(chkDeclared($1) == 0) {
            $$=0;
            printf("\n%s Not Declared!\n", $1);
        }
        else {
            int index = getValue($1);
            $$ = store[index];
        }
    }
    ;

%%

int yywrap()
{
	return 1;
}

int main()
{	
	yyin = freopen("input.txt","r",stdin);
	//yyout = freopen("output.txt","w",stdout);
	yyparse();
	return 0;	
}

int yyerror(char *s)
{
    printf( "%s\n", s);
}