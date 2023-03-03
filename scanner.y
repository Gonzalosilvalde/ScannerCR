%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
extern int yylex(void);

char outputName[100] = "salida.c";
char sizeS[8] = "200";
/*
//typeList será la tabla de tipos y constantes.
TypeList typelist;
//queue será la cola a través de la cual recogeremos y volcaremos las variables de los printf 
NodeList queue;
*/
void yyerror(char const *);
/*char * getVariables(TypeList *);
char * getEndings(NodeList *);
char * getEndingsR(NodeList *);*/
char * getRef (int);
void deleteQuotes (char *);
void deleteCurly(char *);
void deleteNewLines(char *);

%}
%define parse.error verbose
%union {
    char * valString;
    int valInt;
    double valDouble;
}
%token WHILE
%token FOR
%token TO
%token DOWNTO
%token DO
%token REPEAT
%token UNTIL
%token WRITE
%token WRITELN
%token READ
%token READLN
%token PROGRAM
%token BEG
%token END
%token IF
%token THEN
%token ELSE
%token AND
%token OR
%token NOT
%token LOWER
%token HIGHER
%token PLUS
%token HYPHEN
%token PROD
%token DIV
%token DIVINT
%token MOD
%token COMMA
%token DOT
%token EQ
%token <valString>COMMENTLINE
%token <valString>MULTILINE
%token VAR
%token CONST
%token VALUE
%token LPAREN
%token STRINGQUOTE
%token RPAREN
%token COLON
%token SEMICOLON
%token INTEGER
%token FLOAT
%token OPENCURLYBRACKET
%token CLOSECURLYBRACKET
%token BOOLEAN
%token CHAR
%token COUT
%token <valString> STRING
%token <valString> STRINGV
%token <valString> QUOTESTRING
%token TRUEVAL
%token FALSEVAL
%token <valString> INTNUM
%token <valString> REALNUM

%left SEMICOLON
%left EQ
%left LOWER HIGHER
%left PLUS HYPHEN
%left PROD DIV
%left DIVINT MOD
%left AND OR
%right NOT

%type constantes constdef
%type cabecera variables vardef
%type <valString> names values
%type <valInt> type
%type <valString> lines_program line_program
%type <valString> contentWrite programa
%type <valString> assignation atom
%type <valString> operand 
%type <valString> exp term
%start S 
%%
S : 
        cabecera constantes variables programa {;}
        | cabecera constantes programa {;}
        | cabecera variables programa {;}
        | cabecera programa {; }
;

cabecera : PROGRAM LOWER STRINGV HIGHER {;}
		|  PROGRAM STRINGQUOTE {;}
;

constantes : 
        CONST constdef {;}
;
constdef : 
        names EQ TRUEVAL SEMICOLON constdef{;}
        | names EQ FALSEVAL SEMICOLON constdef{;}
        | names EQ INTNUM SEMICOLON constdef{;}
        | names EQ REALNUM SEMICOLON constdef{;}
        | names EQ QUOTESTRING SEMICOLON constdef{;}
        | {;}
;
variables : 
        VAR vardef {}
;
vardef : 
        /*type names VALUE values SEMICOLON vardef{;}
        | type names SEMICOLON vardef {;}
        | */type names SEMICOLON {;}
        | type names VALUE values SEMICOLON {;}
;

type : 
        INTEGER {;}
        | FLOAT {;}
        | STRING {;}
        | CHAR {;}
        | BOOLEAN {;}
;

names : STRINGV {;}
;

values : 
        TRUEVAL {;}
        | FALSEVAL {;}
        | INTNUM {;}
        | REALNUM {;}
        | QUOTESTRING {;}
;
programa : type STRINGV LPAREN RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET {;}
        |type STRINGV LPAREN args RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET{;}
        |type STRINGV LPAREN RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET programa{;}
        |type STRINGV LPAREN args RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET programa{;}
;

args : 
		type STRINGV COMMA args
		|type STRINGV
;

lines_program : 
        lines_program line_program {;}
        | line_program {;}
;

line_program : 
        COUT LOWER LOWER contentWrite SEMICOLON {;}
        /*| WRITELN LPAREN contentWrite RPAREN SEMICOLON {;}
        | READ LPAREN contentRead RPAREN SEMICOLON {;}
        | READLN LPAREN contentRead RPAREN SEMICOLON {;}*/
        | assignation {;}
        | IF LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET ELSE OPENCURLYBRACKET lines_program CLOSECURLYBRACKET {;}
        | IF LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET {;}
        | FOR LPAREN type STRINGV EQ INTNUM SEMICOLON exp SEMICOLON STRINGV operand OPENCURLYBRACKET lines_program CLOSECURLYBRACKET {;}
        | WHILE LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET{;}
        | COMMENTLINE {;}
        | MULTILINE {;}
;

contentWrite : 
        contentWrite COMMA QUOTESTRING {;}
        | contentWrite COMMA STRINGV {;}
        | QUOTESTRING {;}
        | STRINGV {;}
;
/*contentRead : 
         STRINGV {; }
;*/

assignation :
        STRINGV EQ exp SEMICOLON {;}
;

exp : 
        exp operand term {;}
        | term {;}
;

term :
        atom {;}
        | LPAREN exp RPAREN {;}
        | HYPHEN atom {;}
        | NOT exp {;}
;

operand : 
        PLUS {;}
		|PLUS operand {;}
        |HYPHEN {;}
		|HYPHEN operand {;}
        |PROD {;}
        |DIV {;}
        |DIVINT {;}
        |MOD {;}
        |LOWER {;}
        |HIGHER {;}
        |LOWER EQ {;}
        |HIGHER EQ {;}
        |EQ {;}
        |LOWER HIGHER { ;}
        |AND {;}
        |OR{;}
;

atom :

        STRINGV {;}
        | values {;}
;

%%


/* Funciones auxiliares de borrado de caracteres */
/*
void deleteQuotes(char * stringq) {
        int reader = 0; int writer = 0;

        while(stringq[reader]) {
                if (!((stringq[reader] == '\'') || (stringq[reader] == '\"')) ){
                stringq[writer++] = stringq[reader];
                }
                reader++;
        }

        stringq[writer] = 0;
        return;
}

void deleteCurly(char * stringq) {
        int reader = 0; int writer = 0;

        while(stringq[reader]) {
                if (!((stringq[reader] == '{') || (stringq[reader] == '}')) ){
                stringq[writer++] = stringq[reader];
                }
                reader++;
        }

        stringq[writer] = 0;
        return;
}

void deleteNewLines(char * stringq){
        int reader = 0; int writer = 0;

        while(stringq[reader]) {
                if (!((stringq[reader] == '\n')) ){
                stringq[writer++] = stringq[reader];
                }
                reader++;
        }

        stringq[writer] = 0;
        return;
}
*/
/* Procesa los elementos a incluir en el string de Write */
/*
char * getEndings (NodeList * queue) {
        int size = (*queue).end;
        char * final = malloc(size*100*sizeof(char) + size * sizeof("&") + 1);
        strcpy(final,""); 
        char * variable;
        while(!isEmptyListN(queue)){
                variable = getElementN(queue);
                strcat(final,",");
                strcat(final, variable);
                free(variable);
                DeleteElementN(queue);
        }
        return final;
}
*/
/* Procesa los elementos a incluir en el string de Read */
/*
char * getEndingsR (NodeList * queue) {
        int size = (*queue).end;
        char * final = malloc(size*100*sizeof(char) + size * sizeof("&") + 1);
        strcpy(final,""); 
        char * variable;
        while(!isEmptyListN(queue)){
                variable = getElementN(queue);
                strcat(final,",");
                if (SearchType(&typelist, variable) != 2) {
                        strcat(final, "&");
                }
                strcat(final, variable);
                free(variable);
                DeleteElementN(queue);
        }
        return final;
}
*/
/* Recupera las variables declaradas */
/*
char * getVariables (TypeList * queue) {
        int size = (*queue).end;
        char * final = malloc(size * (109*sizeof(char) + sizeof("=;\n") + 100 *sizeof(char) + sizeof("[100]") + sizeof("const ")) +1);
        char * varlist = malloc(size * (109*sizeof(char) + sizeof("=;\n") + 100 *sizeof(char) + sizeof("[100]")) +1);
        char * constlist = malloc(size * (109*sizeof(char) + sizeof("=;\n") + 100 *sizeof(char) + sizeof("[100]") + sizeof("const ")) +1);
        char * temp = malloc (size * (109*sizeof(char) + sizeof("=;\n") + 100 *sizeof(char) + sizeof("[100]") + sizeof("const ")) +1);
        strcpy(varlist,"");
        strcpy(constlist,"");
        strcpy(final, "");
        char * variable;
        Node * node;
        while(!isEmptyListT(queue)){
                strcpy(temp, "");
                node = getElementT(queue);
                if ((*node).isConstant) {
                        strcat(temp, "const ");
                }
                switch ((*node).type){
                        case 0: strcat(temp, "int ");break;
                        case 1: strcat(temp, "double ");break;
                        case 2: strcat(temp, "char ");break;
                        case 3: strcat(temp, "char ");break;
                        default: break;
                }
                strcat(temp, (*node).name);
                if ((*node).type == 2) {
                        strcat(temp, "[");
                        strcat(temp, sizeS);
                        strcat(temp, "]");
                }
                if ((*node).isValue) {
                        strcat(temp, "=");
                        if( (*node).type == 3) {
                                deleteQuotes((*node).value);
                                strcat(temp, "\'");
                                strcat(temp, (*node).value);
                                strcat(temp, "\'");
                        }
                        else {
                                strcat(temp, (*node).value);
                        }
                }
                strcat(temp,";\n");
                if ((*node).isConstant) {
                        strcat(constlist, temp);
                }else{
                        strcat(varlist, temp);
                }
                free(node);
                DeleteElementT(queue);
        }
        strcat(final, constlist);
        strcat(final, varlist);
        free(varlist);
        free(constlist);
        free(temp);
        return final;
}
*/
/*0=int, 1=double, 2=string, 3=char*/
/*
char * getRef (int type){
        char * ref = malloc (sizeof("%lf") + 1);
        switch (type){
                case 0: strcpy(ref, "%d");break;
                case 1: strcpy(ref, "%lf");break;
                case 2: strcpy(ref, "%s");break;
                case 3: strcpy(ref, "%c");break; 
                default: break;
        }
        return ref;
}

int isNumber(char * stringq) {
        for (int i = 0; stringq[i]!='\0';i++){
                if(isdigit(stringq[i]) == 0){
                        return 0;
                }
        }
        return 1;
}

int main(int argc, char *argv[]){
        extern FILE *yyin;
        InitializeListT(&typelist);
        InitializeListN(&queue);
	
	switch (argc) {
		case 1:	printf("Syntax : ./traductorP <archivoPascal> [-s size_string]\n");
			exit(-1);
                        break;
		case 2: yyin = fopen(argv[1], "r");
			if (yyin == NULL) {
				printf("ERROR: No se ha podido abrir el fichero.\n");
			}
			else {
				yyparse();
				fclose(yyin);
			}
                        break;
                case 4 : if((strcmp(argv[2], "-s") != 0) || (isNumber(argv[3])==0)) {
                                printf("Syntax : ./traductorP <archivoPascal> [-s size_string]\n");
			        exit(-1);
                        }
                        else {
                                strcpy(sizeS, argv[3]);
                                yyin = fopen(argv[1], "r");
			        if (yyin == NULL) {
				        printf("ERROR: No se ha podido abrir el fichero.\n");
			        }
			        else {
				        yyparse();
				        fclose(yyin);
			        }
                        }
                        break;
		default: printf("ERROR: Demasiados argumentos.\nSyntax : ./traductorP <archivoPascal> [-s size_string]\n\n");
	}

	return 0;
}*/
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