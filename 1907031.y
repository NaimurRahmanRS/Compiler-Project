%{
#include<stdio.h>
#include <math.h>
#include<stdlib.h>
#include<string.h>
extern FILE *yyin;
//extern FILE *yyout;
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

%token END INT FLOAT STRING MOD
%token LT GT GEQ LEQ EQ NEQ
%token <string> VARIABLE
%token <num> NUMBER
%type <num> expression
%token IMPORT HEADER MAIN
%token INC DEC NOT
%token SIN COS LOG TAN LN
%token ODDEVEN FACTORIAL MAX MIN PRIME

%left LT GT GEQ LEQ EQ NEQ
%left '+' '-'
%left '*' '/' MOD
%left '^'

%%

start: 
    | start program
    ;

program:
    import main '(' ')' '{' statements '}' { printf("\nProgram successfully ended\n"); }
    | /* NULL */
    ;

main:
    MAIN { printf("\nMain Function Declared!\n"); }

import:
    IMPORT '<' HEADER '>' { printf("\nHeader File Found!\n"); }
    | /* NULL */
    ;

statements:
    statements cstatement
	| /* NULL */
	;

cstatement:
    END
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

declare:
    type id END { printf("\nValid Syntax!\n"); } 
	;

type:
    INT { ttp = 0; }
	| FLOAT  { ttp = 1; }
	| STRING  { ttp = 2; }
	;

id:
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
    NUMBER { $$ = $1; }
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
    | expression '+' expression { 	
        $$ = $1 + $3; 
        printf("\nAdd Value %d\n", $$);
    }
	| expression '-' expression {
        $$ = $1 - $3; 
        printf("\nSub Value %d\n", $$);
	}
	| expression '*' expression {
        $$ = $1 * $3;
        printf("\nMul Value %d\n", $$);
	}
	| expression '/' expression { 	
        if($3) {
                $$ = $1 / $3;
                printf("\nDiv Value %d\n", $$);
        }
        else {
                $$ = 0;
                printf("\nDiv by Zero\t");
        }
	}
	| expression '^' expression { 	
        $$=pow($1, $3); 
        printf("\nPower Value %d\n", $$);
	}
	| expression MOD expression {	 
        $$=$1 % $3; 
        printf("\nRemainder Value %d\n", $$);
	}
	| '(' expression ')' { $$ = $2; }
    | expression LT expression {
        $$ = $1 < $3;
        printf("\nLess Than Value is %d\n", $$);
	}
	| expression GT expression {
        $$ = $1 > $3; 
        printf("\nGreater Than Value is %d\n", $$);
	}
	| expression LEQ expression { 
        $$ = $1 <= $3;
        printf("\nLess Than or Equal To Value is %d\n", $$); 
	}
	| expression GEQ expression { 
        $$ = $1 >= $3; 
        printf("\nGreater Than or Equal To Value is %d\n", $$);
	}	
	| expression EQ expression { 
        $$ = $1 == $3; 
        printf("\nEqual To Value is %d\n", $$);
	}
	| expression NEQ expression { 
        $$ = $1 != $3; 
        printf("\nNot Eqaul To Value is %d\n", $$);
	}
    | VARIABLE INC {
        if( chkDeclared($1) == 0) {
            $$=0;
            printf("\n%s Not Declared!\n", $1);
        }
        else {
            int tmp = store[getValue($1)];
            tmp = tmp+1;
            store[getValue($1)] = tmp;
            $$=store[getValue($1)];
            printf("\nValue After Increment is %d\n", $$);
        }
    }
	| VARIABLE DEC {
  		if( chkDeclared($1) == 0) {
    		$$=0;
     		printf("\n%s Not Declared!\n", $1);
   		}
    	else {
            int tmp = store[getValue($1)];
            tmp = tmp-1;
            store[getValue($1)] = tmp;
            $$=store[getValue($1)];
            printf("\nValue After Decrement is %d\n", $$);
        }
	}
	| NOT VARIABLE {
  		if( chkDeclared($2) == 0) {
            $$=0;
            printf("\n%s Not Declared!\n", $2);
   		}
        else {
            int tmp = store[getValue($2)];
            tmp = !tmp;
            store[getValue($2)] = tmp;
            $$=store[getValue($2)];
           printf("\nValue After NOT Operation is %d\n", $$);
        }
	}
    | SIN '(' expression ')' {
		printf("\nValue of Sin(%d) is %lf\n", $3, sin($3*3.1416/180)); 
        $$ = sin($3*3.1416/180);
	}
	| COS '(' expression ')' {
		printf("\nValue of Cos(%d) is %lf\n", $3, cos($3*3.1416/180)); 
        $$ = cos($3*3.1416/180);
	}
	| TAN '(' expression ')' {
		printf("\nValue of Tan(%d) is %lf\n", $3, tan($3*3.1416/180)); 
        $$ = tan($3*3.1416/180);
	}
	| LOG '(' expression ')' {
		printf("\nValue of Log(%d) is %lf\n", $3, (log($3*1.0)/log(10.0))); 
        $$ = (log($3*1.0)/log(10.0));
	}
	| LN '(' expression ')'	{
		printf("\nValue of Ln(%d) is %lf\n", $3, (log($3))); 
        $$=(log($3));
	}
    | ODDEVEN '(' expression ')' {
        if($3%2==0) {
            $$ = 0;
            printf("\n%d is An Even Number\n", $3);
        } 
        else {
            $$ = 1;
            printf("\n%d is An Odd Number\n", $3);
        }        
    }
	| FACTORIAL '(' expression ')' {
        int ans = 1;
        int i;
        for(i=1; i<=$3; i++) {
            ans = ans*i;
        }
        printf("\nFactorial of %d is %d\n", $3, ans);
        $$ = ans;
    }
	| MAX '(' expression ',' expression ')' {
        if( $3 < $5 ) {
            $$ = $5;
            printf("\nMax Number Between %d and %d is %d\n", $3, $5, $5);
        }
        else {
            $$ = $3;
            printf("\nMax Number Between %d and %d is %d\n", $3, $5, $3);
        }
    }
	| MIN '(' expression ',' expression ')' {
        if( $3 < $5 ) {
            $$ = $3;
            printf("\nMin Number Between %d and %d is %d\n", $3, $5, $3);
        }
        else {
            $$ = $5;
            printf("\nMin Number Between %d and %d is %d\n", $3, $5, $5);
        }
    }
	| PRIME '(' expression ')' {
        int x = $3;
        int ck = 0;
        int i; 
        for(i=2; i*i<=x; i++) {
            if( x%i == 0 ) {
                ck = 1;
                break;
            }
        }
        if(ck) {
            $$ = 0;
            printf("\n%d is Not A Prime Number\n", x);
        }
        else {
            $$ = 1;
            printf("\n%d is A Prime Number\n", x);
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