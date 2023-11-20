%{
#include<stdio.h>
#include <math.h>
#include<stdlib.h>
#include<string.h>
extern FILE *yyin;
extern FILE *yyout;
int yylex();
int yyerror(char *s);

// Symbol Table Arrays
char var_name[1000][100];
int store[1000];
float store_float[1000];
char store_String[1000][100];
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
    store_float[var_cnt] = 0.0;
    strcpy(store_String[var_cnt], "");
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
    store_float[var_cnt] = 0.0;
    strcpy(store_String[var_cnt], "");
    type[var_cnt] = 3;
    printf("\nNew Function Declared With Name: %s\n", var_name[var_cnt]);
    var_cnt++;
    return 1;
}

// Assigning Value to Variable
int setValue(char *s, char* val){
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
    if(type[ok] == 0){
        store[ok] = atoi(val);
        printf("\nNew Value Assigned to Variable Name: %s and Value: %d\n", var_name[ok], store[ok]);
    }
    else if(type[ok] == 1){
        store_float[ok] = atof(val);
        printf("\nNew Value Assigned to Variable Name: %s and Value: %f\n", var_name[ok], store_float[ok]);
    }
    else if(type[ok] == 2){
        strcpy(store_String[ok], val);
        //store_String[ok] = val;
        printf("\nNew Value Assigned to Variable Name: %s and Value: %s\n", var_name[ok], store_String[ok]);
    }
    else{
        printf("\nCan't Assign Value as Variable is a Function!\n");
    }
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
%token <string> NUMBER
%type <string> expression
%token <string> STR 
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
            int index = getValue($3);
            if(type[index] == 0){
                printf("\nPrinting Value of the variable %s: %d\n", $3, store[index]);
            }
            else if(type[index] == 1){
                printf("\nPrinting Value of the variable %s: %f\n", $3, store_float[index]);
            }
            else if(type[index] == 2){
                printf("\nPrinting Value of the variable %s: %s\n", $3, store_String[index]);
            }
            else{
                printf("\nCan't Display Value as Variable is a Function!\n");
            }
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
        switch_var = atoi($1);
    }
	;

switch_statement: /* NULL */
	| switch_statement CASE expression ':' '{' statements '}' {
        int x = atoi($3);
        if(x == switch_var && switch_case == 0 ) {
            printf("\nSwitch Case Executed is %d!\n", x);
            switch_case = 1;
        }
        else {
            printf("\nSwitch Case No: %d is Ignored!\n", x);
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
        int x = atoi($3);
        if( x >= 1 ) {
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
        int x = atoi($3);
        if( x >= 1 && ifdone[ifptr] == 0) {
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
    NUMBER {
        $$ = malloc(20);
        strcpy($$, $1); 
    }
    | STR {
        $$ = malloc(20);
        strcpy($$, $1); 
    }
	| VARIABLE {
        $$ = malloc(20);
        if(chkDeclared($1) == 0) {
            sprintf($$, "%d", 0);
            printf("\n%s Not Declared!\n", $1);
        }
        else {
            int index = getValue($1);
            if(type[index] == 0){
                sprintf($$, "%d", store[index]);
            }
            else if(type[index] == 1){
                sprintf($$, "%f", store_float[index]);
            }
            else if(type[index] == 2){
                strcpy($$, store_String[index]);
            }
            else{
                printf("\nCan't Process Value as Variable is a Function or Invalid!\n");
            }
        }
    }
    | expression '+' expression { 
        $$ = malloc(20);
        float num1 = atof($1);
        float num2 = atof($3);
        float num3 = num1 + num2;
        sprintf($$, "%f", num3);	 
        printf("\nAdd Value: %f\n", num3);
    }
	| expression '-' expression {
        $$ = malloc(20);
        float num1 = atof($1);
        float num2 = atof($3);
        float num3 = num1 - num2;
        sprintf($$, "%f", num3);
        printf("\nSub Value: %f\n", num3);
	}
	| expression '*' expression {
        $$ = malloc(20);
        float num1 = atof($1);
        float num2 = atof($3);
        float num3 = num1 * num2;
        sprintf($$, "%f", num3);
        printf("\nMul Value: %f\n", num3);
	}
	| expression '/' expression {
        $$ = malloc(20);
        float num1 = atof($1);
        float num2 = atof($3); 	
        if(num2!=0.0) {
            float num3 = num1 / num2;
            sprintf($$, "%f", num3);
            printf("\nDiv Value: %f\n", num3);
        }
        else {
            sprintf($$, "%f", 0);
            printf("\nDiv by Zero is Not Possible!\n");
        }
	}
	| expression '^' expression {
        $$ = malloc(20);
        float num1 = atof($1);
        float num2 = atof($3);
        float num3 = pow(num1, num2);
        sprintf($$, "%f", num3);
        printf("\nPower Value: %f\n", num3);
	}
	| expression MOD expression {
        $$ = malloc(20);
        int num1 = atoi($1);
        int num2 = atoi($3);
        int num3 = num1 % num2;
        sprintf($$, "%d", num3);	 
        printf("\nRemainder Value: %d\n", num3);
	}
	| '(' expression ')' {
        $$ = malloc(20);
        strcpy($$, $2); 
    }
    | expression LT expression {
        $$ = malloc(20);
        float num1 = atof($1);
        float num2 = atof($3);
        int num3 = num1 < num2;
        sprintf($$, "%d", num3);
        printf("\nLess Than Value: %d\n", num3);
	}
	| expression GT expression {
        $$ = malloc(20);
        float num1 = atof($1);
        float num2 = atof($3);
        int num3 = num1 > num2;
        sprintf($$, "%d", num3);
        printf("\nGreater Than Value: %d\n", num3);
	}
	| expression LEQ expression {
        $$ = malloc(20); 
        float num1 = atof($1);
        float num2 = atof($3);
        int num3 = num1 <= num2;
        sprintf($$, "%d", num3);
        printf("\nLess Than or Equal To Value: %d\n", num3); 
	}
	| expression GEQ expression {
        $$ = malloc(20); 
        float num1 = atof($1);
        float num2 = atof($3);
        int num3 = num1 >= num2;
        sprintf($$, "%d", num3);
        printf("\nGreater Than or Equal To Value: %d\n", num3);
	}	
	| expression EQ expression {
        $$ = malloc(20);
        float num1 = atof($1);
        float num2 = atof($3);
        int num3 = num1 == num2;
        sprintf($$, "%d", num3);
        printf("\nEqual To Value: %d\n", num3);
	}
	| expression NEQ expression {
        $$ = malloc(20);
        float num1 = atof($1);
        float num2 = atof($3);
        int num3 = num1 != num2;
        sprintf($$, "%d", num3);
        printf("\nNot Eqaul To Value: %d\n", num3);
	}
    | VARIABLE INC {
        $$ = malloc(20);
        if( chkDeclared($1) == 0) {
            sprintf($$, "%d", 0);
            printf("\n%s is Not Declared!\n", $1);
        }
        else {
            int index = getValue($1);
            if(type[index] == 0){
                int tmp = store[index];
                tmp = tmp+1;
                store[index] = tmp;
                sprintf($$, "%d", tmp);
                printf("\nValue After Increment: %d\n", tmp);
            }
            else if(type[index] == 1){
                float tmp = store_float[index];
                tmp = tmp+1;
                store_float[index] = tmp;
                sprintf($$, "%f", tmp);
                printf("\nValue After Increment: %f\n", tmp);
            }
            else{
                printf("\nCan't Process Increament as Variable is a String or a Function!\n");
            }
        }
    }
	| VARIABLE DEC {
        $$ = malloc(20);
  		if( chkDeclared($1) == 0) {
            sprintf($$, "%d", 0);
     		printf("\n%s Not Declared!\n", $1);
   		}
    	else {
            int index = getValue($1);
            if(type[index] == 0){
                int tmp = store[index];
                tmp = tmp-1;
                store[index] = tmp;
                sprintf($$, "%d", tmp);
                printf("\nValue After Decrement: %d\n", tmp);
            }
            else if(type[index] == 1){
                float tmp = store_float[index];
                tmp = tmp-1;
                store_float[index] = tmp;
                sprintf($$, "%f", tmp);
                printf("\nValue After Decrement: %f\n", tmp);
            }
            else{
                printf("\nCan't Process Decrement as Variable is a String or a Function!\n");
            }
        }
	}
    | NOT VARIABLE {
        $$ = malloc(20);
  		if( chkDeclared($2) == 0) {
            sprintf($$, "%d", 0);
            printf("\n%s Not Declared!\n", $2);
   		}
        else {
            int index = getValue($2);
            if(type[index] == 0){
                int tmp = store[index];
                tmp = !tmp;
                store[index] = tmp;
                sprintf($$, "%d", tmp);
                printf("\nValue After NOT Operation: %d\n", tmp);
            }
            else if(type[index] == 1){
                int tmp = store_float[index];
                tmp = !tmp;
                store_float[index] = tmp;
                sprintf($$, "%d", tmp);
                printf("\nValue After NOT Operation: %d\n", tmp);
            }
            else{
                printf("\nCan't Process NOT Operation as Variable is a String or a Function!\n");
            }
        }
	}
    | SIN '(' expression ')' {
        $$ = malloc(20);
        float x = atof($3);
		printf("\nValue of Sin(%f): %lf\n", x, sin(x*3.1416/180));
        sprintf($$, "%lf", sin(x*3.1416/180));
	}
	| COS '(' expression ')' {
        $$ = malloc(20);
        float x = atof($3);
		printf("\nValue of Cos(%f): %lf\n", x, cos(x*3.1416/180));
        sprintf($$, "%lf", cos(x*3.1416/180));
	}
	| TAN '(' expression ')' {
        $$ = malloc(20);
        float x = atof($3);
		printf("\nValue of Tan(%f): %lf\n", x, tan(x*3.1416/180));
        sprintf($$, "%lf", tan(x*3.1416/180));
	}
	| LOG '(' expression ')' {
        $$ = malloc(20);
        float x = atof($3);
		printf("\nValue of Log(%f): %lf\n", x, (log(x*1.0)/log(10.0)));
        sprintf($$, "%lf", (log(x*1.0)/log(10.0)));
	}
	| LN '(' expression ')'	{
        $$ = malloc(20);
        float x = atof($3);
		printf("\nValue of Ln(%f): %lf\n", x, (log(x)));
        sprintf($$, "%lf", (log(x)));
	}
    | ODDEVEN '(' expression ')' {
        $$ = malloc(20);
        int x = atoi($3);
        if(x%2==0) {
            sprintf($$, "%d", 0);
            printf("\n%d is An Even Number\n", x);
        } 
        else {
            sprintf($$, "%d", 1);
            printf("\n%d is An Odd Number\n", x);
        }        
    }
	| FACTORIAL '(' expression ')' {
        $$ = malloc(20);
        int ans = 1;
        int i;
        int x = atoi($3);
        for(i=1; i<=x; i++) {
            ans = ans*i;
        }
        printf("\nFactorial of %d is: %d\n", x, ans);
        sprintf($$, "%d", ans);
    }
	| MAX '(' expression ',' expression ')' {
        $$ = malloc(20);
        float num1 = atof($3);
        float num2 = atof($5);
        if( num1 < num2 ) {
            sprintf($$, "%f", num2);
            printf("\nMax Number Between %f and %f is: %f\n", num1, num2, num2);
        }
        else {
            sprintf($$, "%f", num1);
            printf("\nMax Number Between %f and %f is: %f\n", num1, num2, num1);
        }
    }
	| MIN '(' expression ',' expression ')' {
        $$ = malloc(20);
        float num1 = atof($3);
        float num2 = atof($5);
        if( num1 < num2 ) {
            sprintf($$, "%f", num1);
            printf("\nMin Number Between %f and %f is: %f\n", num1, num2, num1);
        }
        else {
            sprintf($$, "%f", num2);
            printf("\nMin Number Between %f and %f is: %f\n", num1, num2, num2);
        }
    }
	| PRIME '(' expression ')' {
        $$ = malloc(20);
        int x = atoi($3);
        int ck = 0;
        int i; 
        for(i=2; i*i<=x; i++) {
            if( x%i == 0 ) {
                ck = 1;
                break;
            }
        }
        if(ck || x==1) {
            sprintf($$, "%d", 0);
            printf("\n%d is Not A Prime Number\n", x);
        }
        else {
            sprintf($$, "%d", 1);
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
	yyout = freopen("output.txt","w",stdout);
    yyparse();
	return 0;	
}

int yyerror(char *s)
{
    printf( "%s\n", s);
}