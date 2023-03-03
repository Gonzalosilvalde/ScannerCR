%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void yyerror (char const *);
extern int yylex();
extern int yylineno;
%}
%define parse.error verbose

%union{
	int valInt;
	float valFloat;
	char * string;
}

%token NEWLINE
%token ENDOFFILE
%token AND
%token BREAK
%token ELIF
%token ELSE
%token FOR
%token IF
%token COMENTARIO1
%token NOT
%token OR
%token RETURN
%token WHILE
%token TRUEVAL
%token FALSEVAL
%token COUT
%token <string> STRINGVAL
%token <string> VARNAME
%token <valFloat> FLOATNUM
%token <valInt> INTNUM
%token <valVoid> VOID
%token <valBool> BOOL
%token INT 
%token FLOAT
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
%token OPENCURLYBRACKET
%token CLOSECURLYBRACKET
%token COMMA
%token DOUBLEPOINT
%token SEMICOLON
%token PERCENTAGE
%token HASHTAG
%token HINCLUDE
%start s

%%
s: 	
	code NEWLINE code {return 0;}
	|code ENDOFFILE {return 0;}
	|error {printf("\033[0;31m");printf("LINE %d: ",yylineno), printf("Error: Something unexpected has happened.\n"),yyclearin;exit(0);}
;
code:
  	HINCLUDE LESS VARNAME BIGGER {;}
  	|HINCLUDE STRINGVAL{;}
	|VARNAME EQUAL term SEMICOLON code{printf("aqui llega?");}
	|vartypes VARNAME OPEN args CLOSE OPENCURLYBRACKET code CLOSECURLYBRACKET{;}
	|vartypes VARNAME OPEN CLOSE OPENCURLYBRACKET code CLOSECURLYBRACKET{;}
	|IF OPEN condition CLOSE OPENCURLYBRACKET code CLOSECURLYBRACKET ifpart2 {;}
	/*casos en los cuales termina en break*/
	|FOR OPEN code SEMICOLON condition SEMICOLON code CLOSE OPENCURLYBRACKET BREAK CLOSECURLYBRACKET {;}
	/*Caso en el que se hace referencia al nombre de una variable*/
	|FOR OPEN code SEMICOLON condition SEMICOLON code CLOSE OPENCURLYBRACKET code BREAK CLOSECURLYBRACKET {;}
	|WHILE OPEN condition CLOSE OPENCURLYBRACKET code BREAK CLOSECURLYBRACKET{;}
	/*casos en los cuales no termina en break*/
	|FOR OPEN code SEMICOLON condition SEMICOLON code CLOSE OPENCURLYBRACKET code CLOSECURLYBRACKET {;}
	|WHILE OPEN condition CLOSE OPENCURLYBRACKET code CLOSECURLYBRACKET{;}
	|COUT LESS LESS print_content SEMICOLON code{;}
  	/*añado aqui la potencia porque no funciona igual que las otras funciones*/
  	|POW OPEN number COMMA number CLOSE SEMICOLON{;}
	/*|RETURN term {;}*/
	|RETURN number  {;}
	|error {printf("\033[0;31m");printf("LINE %d: ",yylineno),printf("Error: Invalid sintax.\n"),yyclearin;exit(0);}
;

print_content:
	term {printf("aqui llega?");}
	|VARNAME {;}
	/*por ahora no se asegura de que se le pasan al print los argumentos necesarios para hacer el print*/
	/*|STRINGVAL PERCENTAGE OPEN args CLOSE {;}*/
	/*|error {printf("\033[0;31m");printf("LINE %d: ",yylineno), printf("Error: Can't print this.\n"),yyclearin;exit(0);}*/

args:
	VARNAME {;}
	|VARNAME COMMA args {;}
	|VARNAME EQUAL term {printf("aqui llega?");}
	|VARNAME EQUAL term COMMA args {printf("aqui llega?");}
	|error {printf("\033[0;31m");printf("LINE %d: ",yylineno), printf("Error: Invalid arguments.\n"),yyclearin;exit(0);}
;

boolean:
	TRUEVAL {;}
	|FALSEVAL {;}
	/*|error {printf("\033[0;31m");printf("LINE %d: ",yylineno), printf("Error: Invalid boolean value.\n"),yyclearin;exit(0);}*/
;

term:
	number {;}
	|STRINGVAL {;}
	|boolean {;}
	|error {printf("\033[0;31m");printf("LINE %d: ",yylineno), printf("Error: Invalid value for a term.\n"),yyclearin;exit(0);}
;

operation:
	MULT {;}
	|DIVIDE {;}	
  	|ADD {;}
	|MINUS {;}
	/*|error {printf("\033[0;31m");printf("LINE %d: ",yylineno), printf("Error: Invalid operator.\n"),yyclearin;exit(0);}*/
;

number:
	INTNUM {;}
	|FLOATNUM {;}
  	/*|DOUBLE {;}*/
	|INTNUM operation number {;}
	|FLOATNUM operation number {;}
  	/*|DOUBLE operation number {;}*/
	/*|error {printf("\033[0;31m");printf("LINE %d: ",yylineno), printf("Error:Invalid value for a number.\n"),yyclearin;exit(0);}*/
;

/*
list:
	|OPENBRACKET list_elements CLOSEBRACKET {;}
	|error {printf("\033[0;31m");printf("LINE %d: ",yylineno), printf("Error: Invalid sintax for list.\n"),yyclearin;exit(0);}
;

list_elements:
	|/*empty {;}
	|term COMMA list_elements {;}
	|error {printf("\033[0;31m");printf("LINE %d: ",yylineno), printf("Error: Invalid sintax for list elements.\n"),yyclearin;exit(0);}
;
*/
ifpart2:
	ELSE IF OPEN statement CLOSE OPENCURLYBRACKET code CLOSECURLYBRACKET ifpart2 {;}
	|ELSE OPENCURLYBRACKET code CLOSECURLYBRACKET{;}
	/*|error {printf("\033[0;31m");printf("LINE %d: ",yylineno), printf("Error: Invalid sintax on if.\n"),yyclearin;exit(0);}*/
;

statement:
	boolean {;}
	|INTNUM{;}
	|term logical_operators term {printf("aqui llega?");}
	/*|error {printf("\033[0;31m");printf("LINE %d: ",yylineno), printf("Error: Invalid statement for condition.\n"),yyclearin;exit(0);}*/
;

logical_operators:
	BIGGER {;}
	|BIGGEREQ {;}
	|LESS {;}
	|LESSEQ {;}
	|EQUALB {;}
	|NOTEQUAL {;} 
	/*|error {printf("\033[0;31m");printf("LINE %d: ",yylineno), printf("Error: Invalid logical operator.\n"),yyclearin;exit(0);}*/
;

vartypes:
	INT{;}
	|FLOAT{;}
	|BOOL {;}
	|VOID {;}
;

condition:
	statement {;}
	|NOT statement condition {;}
	|AND statement condition {;}
	|OR statement condition {;}
	/*|error {printf("\033[0;31m");printf("LINE %d: ",yylineno), printf("Error: Invalid condition.\n"),yyclearin;exit(0);}*/
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