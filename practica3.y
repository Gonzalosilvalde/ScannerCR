%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void yyerror (char const *);
extern int yylex();
extern int yylineno;
%}

%union{
	int valInt;
	float valFloat;
	char * string;
}

%token NEWLINE
%token ENDOFFILE
%token AND
%token BREAK
%token DEF
%token ELIF
%token ELSE
%token FOR
%token IF
%token NOT
%token OR
%token RETURN
%token WHILE
%token TRUEVAL
%token FALSEVAL
%token PRINT
%token <string> STRINGVAL1
%token <string> STRINGVAL2
%token <string> VARNAME
%token <valFloat> FLOAT
%token <valInt> INT
%token EQUAL
%token ADD
%token MINUS
%token MULT
%token POW
%token DIVIDE
%token EQUALB
%token NOTEQUAL
%token BIGGER
%token BIGGEREQ
%token LESS
%token LESSEQ
%token OPEN
%token CLOSE
%token OPENBRACKET
%token CLOSEBRACKET
%token COMMA
%token DOUBLEPOINT
%token IN
%token RANGE
%token PERCENTAGE
%start s
%%

s: 	
	|code NEWLINE code {;}
	|code ENDOFFILE {;}
	|error {printf("\033[0;31m");printf("LINE %d: ",yylineno), printf("Error: Something unexpected has happened.\n"),yyclearin;exit(0);}
;

code:
	|/*empty*/ {;}
	|VARNAME EQUAL term {;}
	|VARNAME EQUAL number operation number {;}
	|DEF VARNAME OPEN args CLOSE {;}
	|IF condition DOUBLEPOINT code ifpart2 {;}
	/*casos en los cuales termina en break*/
	|FOR VARNAME IN VARNAME DOUBLEPOINT code BREAK {;}
	/*Caso en el que se hace referencia al nombre de una variable*/
	|FOR VARNAME IN RANGE OPEN VARNAME CLOSE DOUBLEPOINT code BREAK {;}
	/*Caso en el que se hace referencia a un int*/	
	|FOR VARNAME IN RANGE OPEN INT CLOSE DOUBLEPOINT code BREAK {;}
	|WHILE condition DOUBLEPOINT code BREAK {;}
	/*casos en los cuales no termina en break*/
	|FOR VARNAME IN VARNAME DOUBLEPOINT code {;}
	/*Caso en el que se hace referencia al nombre de una variable*/
	|FOR VARNAME IN RANGE OPEN VARNAME CLOSE DOUBLEPOINT code {;}
	/*Caso en el que se hace referencia a un int*/
	|FOR VARNAME IN RANGE OPEN INT CLOSE DOUBLEPOINT code {;}
	|WHILE condition DOUBLEPOINT code {;}
	|PRINT OPEN print_content CLOSE {;}
	|RETURN term {;}
	|RETURN number operation number {;}
	|error {printf("\033[0;31m");printf("LINE %d: ",yylineno),printf("Error: Invalid sintax.\n"),yyclearin;exit(0);}
;

print_content:
	|term {;}
	|VARNAME {;}
	/*nuestra implementacion no se asegura de que se le pasan al print los argumentos necesarios para hacer el print*/
	|STRINGVAL1 PERCENTAGE OPEN args CLOSE {;}
	|STRINGVAL2 PERCENTAGE OPEN args CLOSE {;}
	|error {printf("\033[0;31m");printf("LINE %d: ",yylineno), printf("Error: Can't print this.\n"),yyclearin;exit(0);}

args:
	|/*empty*/ {;}
	|VARNAME {;}
	|VARNAME COMMA args {;}
	|VARNAME EQUAL term {;}
	|VARNAME EQUAL term COMMA args {;}
	|error {printf("\033[0;31m");printf("LINE %d: ",yylineno), printf("Error: Invalid arguments.\n"),yyclearin;exit(0);}
;

term:
	|number {;}
	|STRINGVAL1 {;}
	|STRINGVAL2 {;}
	|boolean {;}
	|list {;}
	|list OPENBRACKET INT CLOSEBRACKET {;}
	|error {printf("\033[0;31m");printf("LINE %d: ",yylineno), printf("Error: Invalid value for a term.\n"),yyclearin;exit(0);}
;

number:
	|INT {;}
	|FLOAT {;}
	|INT operation number {;}
	|FLOAT operation number {;}
	|error {printf("\033[0;31m");printf("LINE %d: ",yylineno), printf("Error:Invalid value for a number.\n"),yyclearin;exit(0);}
;

operation :
	|ADD {;}
	|MINUS {;}
	|MULT {;}
	|DIVIDE {;}
	|POW {;}
	|error {printf("\033[0;31m");printf("LINE %d: ",yylineno), printf("Error: Invalid operator.\n"),yyclearin;exit(0);}
;

boolean:
	|TRUEVAL {;}
	|FALSEVAL {;}
	|error {printf("\033[0;31m");printf("LINE %d: ",yylineno), printf("Error: Invalid boolean value.\n"),yyclearin;exit(0);}
;

list:
	|OPENBRACKET list_elements CLOSEBRACKET {;}
	|error {printf("\033[0;31m");printf("LINE %d: ",yylineno), printf("Error: Invalid sintax for list.\n"),yyclearin;exit(0);}
;

list_elements:
	|/*empty*/ {;}
	|term COMMA list_elements {;}
	|error {printf("\033[0;31m");printf("LINE %d: ",yylineno), printf("Error: Invalid sintax for list elements.\n"),yyclearin;exit(0);}
;

ifpart2:
	|/*empty*/ {;}
	|ELIF statement DOUBLEPOINT code ifpart2 {;}
	|ELSE DOUBLEPOINT code {;}
	|error {printf("\033[0;31m");printf("LINE %d: ",yylineno), printf("Error: Invalid sintax on if.\n"),yyclearin;exit(0);}
;

statement:
	|/*empty*/ {;}
	|boolean {;}
	|INT {;}
	|term logical_operators term
	|error {printf("\033[0;31m");printf("LINE %d: ",yylineno), printf("Error: Invalid statement for condition.\n"),yyclearin;exit(0);}
;

logical_operators:
	|BIGGER {;}
	|BIGGEREQ {;}
	|LESS {;}
	|LESSEQ {;}
	|EQUALB {;}
	|NOTEQUAL {;} 
	|error {printf("\033[0;31m");printf("LINE %d: ",yylineno), printf("Error: Invalid logical operator.\n"),yyclearin;exit(0);}
;


condition:
	|/*empty*/ {;}
	|statement {;}
	|NOT statement condition {;}
	|AND statement condition {;}
	|OR statement condition {;}
	|error {printf("\033[0;31m");printf("LINE %d: ",yylineno), printf("Error: Invalid condition.\n"),yyclearin;exit(0);}
;
%%
int main(int argc, char *argv[]) {
extern FILE *yyin;
extern FILE **yyout;

	switch (argc) {
		case 1:	yyin=stdin;
			yyparse();
			printf("\n");
			printf("\033[0;32m");
			printf("Successful code conversion!\n");
			printf("\n");
			break;
		case 2: yyin = fopen(argv[1], "r");
			if (yyin == NULL) {
				printf("\033[0;31m");
				printf("ERROR: File could not be opened.\n");
			}
			else {
				yyparse();
				fclose(yyin);
			}
			break;
		default: printf("\033[0;31m");printf("ERROR: Too many arguments.\nSintax: %s [fichero_entrada] \n\n", argv[0]);
	}

	return 0;
}
