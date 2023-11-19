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
int ttp = 0; // 0 = int, 1 = float, 2 = string, 3 = function

// Conditional Statement Variables
int ifptr = 0;
int ifdone[1000];

// Switch Handling Variables
int switch_var = 0; 
int switch_case = 0;

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

// New Function Declaration
int init_asn_func(char *s){
    if(chkDeclared(s) == 1){
        return 0;
    }
    strcpy(var_name[var_cnt], s);
    store[var_cnt] = 0;
    type[var_cnt] = 3;
    printf("\nNew Function Declared With Name: %s\n", var_name[var_cnt]);
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
%token DEF DISPLAY
%token IF ELSE_IF ELSE
%token FOR FLINC FLDEC WHILE
%token CASE SWITCH DEFAULT

%left LT GT GEQ LEQ EQ NEQ
%left '+' '-'
%left '*' '/' MOD
%left '^'

%%

program:
    import func main '(' ')' '{' statements '}' { printf("\nProgram Successfully Ended!\n"); }
    | /* NULL */
    ;

main:
    MAIN { printf("\nMain Function Declared!\n"); }

import: /* NULL */
    | import IMPORT '<' HEADER '>' { printf("\nHeader File Found!\n"); }
    ;

func: 
    func_head '(' param ')' '{' statements '}' {
		printf("\nUser Defined Function Ended!\n");
	}
	| /* NULL */
	;

func_head: 
    DEF VARIABLE {
        if(chkDeclared($2)==1) {
            printf("\nDuplicate Function Name!\n");
        }
        else {
            init_asn_func($2);
        }
    }

param:
	param ',' type pid	{ printf("\nValid Function Parameter Declaration!\n"); } 
	| type pid 	{ printf("\nValid Function Parameter Declaration!\n"); } 
	;

pid	:
	 VARIABLE {
		if(chkDeclared($1)==1) {
      		printf("\nDuplicate Declaration!\n");
        }
   		else {
      	    init_asn($1);
		}
    }
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
    | function_call END
    | DISPLAY '(' VARIABLE ')' END {
		if(chkDeclared($3)==0) {
			printf("\nCan't print, Variable is not declared\n");
        }
        else {
            printf("\nPrinting Value of the variable %s: %d\n", $3, store[getValue($3)]);
        }
	}
    | if_condition '{' statements '}' {
		printf("\nIf Block is Successfully Handled!\n");
	}
	| else_if_condition '{' statements '}' {
		printf("\nElse If Block is Successfully Handled!\n");
	}
	| else_condition '{' statements '}' {
		printf("\nElse Block is Successfully Handled!\n");
	}
    | for_start '(' for_loop ')' '{' statements '}' {
        printf("\nFor Loop Execution Finshed!\n");
    }
    | while_start '(' while_loop ')' '{' statements '}' {
        printf("\nWhile Loop Execution Finshed!\n");
    }
    | switch_start '(' switch_exp ')' '{' switch_statement '}' {
        printf("\nSwitch Execution Finshed!\n");
    }
    ;

switch_start:
    SWITCH {
        printf("\nSwitch Case Started!\n");
    }
    ;

switch_exp :
	expression {
        switch_case = 0;
        switch_var = $1;
    }
	;

switch_statement: /* NULL */
	| switch_statement CASE expression ':' '{' statements '}' {
        if($3 == switch_var && switch_case == 0 ) {
            printf("\nSwitch Case Executed is %d!\n", $3);
            switch_case = 1;
        }
        else {
            printf("\nSwitch Case No: %d is Ignored!\n", $3);
        }
    }
	| switch_statement DEFAULT ':' '{' statements '}' {
        if(switch_case == 0) {
            switch_case = 1;
            printf("\nSwitch Default Case is Executed!\n");
        }
    }
	;

while_loop:
    VARIABLE loop_exp loop_assign {
        if(chkDeclared($1) == 0) {
            printf("\n%s Not Declared!\n", $1);
        }
        else {
            printf("\nWhile Loop Variable Declaration is Correct!\n");	
        } 
    }

while_start:
    WHILE {
        printf("\nWhile Loop Started!\n");
    }

for_start:
    FOR {
        printf("\nFor Loop Started!\n");
    }

for_loop:
    | VARIABLE '=' loop_assign ',' VARIABLE loop_exp loop_assign ',' VARIABLE f_state loop_assign {			
        if(chkDeclared($1) == 0) {
            printf("\n%s Not Declared!\n", $1);
        }
        if(strcmp($1, $5) == 0) {
            if(strcmp($1, $9) == 0) {
                printf("\nFor Loop Variable Declaration is Correct!\n");
            }
        }
        else {
            printf("\nDifferent Variables Used: %s %s %s\n", $1, $5, $9);	
        } 			    
    }

loop_assign:
    NUMBER
    | VARIABLE {
        if(chkDeclared($1) == 0) {
            printf("\n%s Not Declared!\n", $1);
        }
        else {
            printf("\nVariable Correctly Assigned to Loop!\n");	
        }
    }
    ;

loop_exp:
    LT
    | GT
    | GEQ
    | LEQ
    | EQ
    | NEQ
    ;

f_state:
    FLINC {
        printf("\nLoop is of Increasing Manner!\n");
    }
    | FLDEC {
        printf("\nLoop is of Decreasing Manner!\n");
    }
    ;

if_condition:
    IF '(' expression ')' {
        if( $3 == 1 ) {
			ifdone[ifptr] = 1;
			printf("\nIf Block is Executed!\n");
		}
        else {
            printf("\nIf Block is Not Executed!\n");
        }
        ifptr++;
    }

else_if_condition:
    ELSE_IF '(' expression ')' {
        if( $3 == 1 && ifdone[ifptr] == 0) {
			ifdone[ifptr] = 1;
			printf("\nElse If Block is Executed!\n");
		}
        else {
            printf("\nElse If Block is Not Executed!\n");
        }
    }

else_condition:
    ELSE {
        if( ifdone[ifptr] == 0) {
			ifdone[ifptr] = 1;
			printf("\nElse Block is Executed!\n");
		}
        else {
            printf("\nElse Block is Not Executed!\n");
        }
    }

function_call: 
    f_var '(' call_param ')' { 
        printf("\nValid Function Call!\n");
    }
    ;

f_var: 
    VARIABLE {
        if(chkDeclared($1) == 0) {
			printf("\n%s Function is Not Declared!\n", $1);
		}
        else {
            printf("\n%s Function is Called!\n", $1);
        }
    }

call_param:
    call_param ',' VARIABLE {
        if(chkDeclared($3) == 0) {
            printf("\n%s Variable is Not Declared\n", $3);
        }
        else {
            printf("\n%s Passed as Parameter For Function!\n", $3); 
                
        }
    }
    | VARIABLE {
        if(chkDeclared($1) == 0) {
            printf("\n%s Variable is Not Declared\n", $1);
        }
        else {
            printf("\n%s Passed as Parameter For Function!\n", $1); 
                
        }
    }
	| /* NULL */
    ;

declare:
    type id END { printf("\nValid Syntax For Variable Declaration!\n"); } 
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
        printf("\nAdd Value: %d\n", $$);
    }
	| expression '-' expression {
        $$ = $1 - $3; 
        printf("\nSub Value: %d\n", $$);
	}
	| expression '*' expression {
        $$ = $1 * $3;
        printf("\nMul Value: %d\n", $$);
	}
	| expression '/' expression { 	
        if($3) {
                $$ = $1 / $3;
                printf("\nDiv Value: %d\n", $$);
        }
        else {
                $$ = 0;
                printf("\nDiv by Zero is Not Possible!\n");
        }
	}
	| expression '^' expression { 	
        $$=pow($1, $3); 
        printf("\nPower Value: %d\n", $$);
	}
	| expression MOD expression {	 
        $$=$1 % $3; 
        printf("\nRemainder Value: %d\n", $$);
	}
	| '(' expression ')' { $$ = $2; }
    | expression LT expression {
        $$ = $1 < $3;
        printf("\nLess Than Value: %d\n", $$);
	}
	| expression GT expression {
        $$ = $1 > $3; 
        printf("\nGreater Than Value: %d\n", $$);
	}
	| expression LEQ expression { 
        $$ = $1 <= $3;
        printf("\nLess Than or Equal To Value: %d\n", $$); 
	}
	| expression GEQ expression { 
        $$ = $1 >= $3; 
        printf("\nGreater Than or Equal To Value: %d\n", $$);
	}	
	| expression EQ expression { 
        $$ = $1 == $3; 
        printf("\nEqual To Value: %d\n", $$);
	}
	| expression NEQ expression { 
        $$ = $1 != $3; 
        printf("\nNot Eqaul To Value: %d\n", $$);
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
            printf("\nValue After Increment: %d\n", $$);
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
            printf("\nValue After Decrement: %d\n", $$);
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
           printf("\nValue After NOT Operation: %d\n", $$);
        }
	}
    | SIN '(' expression ')' {
		printf("\nValue of Sin(%d): %lf\n", $3, sin($3*3.1416/180)); 
        $$ = sin($3*3.1416/180);
	}
	| COS '(' expression ')' {
		printf("\nValue of Cos(%d): %lf\n", $3, cos($3*3.1416/180)); 
        $$ = cos($3*3.1416/180);
	}
	| TAN '(' expression ')' {
		printf("\nValue of Tan(%d): %lf\n", $3, tan($3*3.1416/180)); 
        $$ = tan($3*3.1416/180);
	}
	| LOG '(' expression ')' {
		printf("\nValue of Log(%d): %lf\n", $3, (log($3*1.0)/log(10.0))); 
        $$ = (log($3*1.0)/log(10.0));
	}
	| LN '(' expression ')'	{
		printf("\nValue of Ln(%d): %lf\n", $3, (log($3))); 
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
        printf("\nFactorial of %d is: %d\n", $3, ans);
        $$ = ans;
    }
	| MAX '(' expression ',' expression ')' {
        if( $3 < $5 ) {
            $$ = $5;
            printf("\nMax Number Between %d and %d is: %d\n", $3, $5, $5);
        }
        else {
            $$ = $3;
            printf("\nMax Number Between %d and %d is: %d\n", $3, $5, $3);
        }
    }
	| MIN '(' expression ',' expression ')' {
        if( $3 < $5 ) {
            $$ = $3;
            printf("\nMin Number Between %d and %d is: %d\n", $3, $5, $3);
        }
        else {
            $$ = $5;
            printf("\nMin Number Between %d and %d is: %d\n", $3, $5, $5);
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