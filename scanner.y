%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "list.h"

extern int yylex(void);

char outputName[100] = "salida.rs";
char sizeS[8] = "200";

//typeList será la tabla de tipos y constantes.
TypeList typelist;
//queue será la cola a través de la cual recogeremos y volcaremos las variables de los printf 
NodeList queue;

void yyerror(char const *);
char * getVariables(TypeList *);
char * getEndings(NodeList *);
char * getEndingsR(NodeList *);
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
%token DO
%token TO
%token DOWNTO
%token WRITE
%token ENDL
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
%token DEFINE
%token VALUE
%token LPAREN
%token STRINGQUOTE
%token RPAREN
%token COLON
%token SEMICOLON
%token INTEGER
%token FLOAT
%token EX
%token OPENCURLYBRACKET
%token CLOSECURLYBRACKET
%token BOOLEAN
%token CHAR
%token <valString> STRING
%token <valString> STRINGV
%token <valString> QUOTESTRING
%token TRUEVAL
%token FALSEVAL
%token <valString> INTNUM
%token <valString> REALNUM
%token RETURN

%left SEMICOLON
%left EQ
%left LOWER HIGHER
%left PLUS HYPHEN
%left PROD DIV
%left DIVINT MOD
%left AND OR


%type cabecera vardef
%type <valString>  values
%type <valInt> type
%type <valString> lines_program line_program
%type <valString> contentWrite programa 
%type <valString> comment
%type <valString> assignation atom
%type <valString> operand 
%type <valString> exp term
%start S 
%%
S : 
        /*cabecera subcabecera constantes vardef programa {;}
        | cabecera subcabecera constantes programa {;}
        | cabecera subcabecera vardef programa {;}
        cabecera subcabecera programa {; }*/
        cabecera comment subcabecera comment programa { 
                
                FILE *fp = fopen(outputName, "w");
				char * variables = getVariables(&typelist);
                
                if (fp!=NULL) {
                    fputs(strcat($2,"\n"),fp);
                    fputs(variables, fp);
                    fclose(fp);    
                }
                free($5);
        }
        

;

comment:
         COMMENTLINE {
                deleteNewLines($1);
                $$ = $1;
                }
        | MULTILINE {;}
        | {;}
        
;

subcabecera:
        STRINGV SEMICOLON {;}
        |STRINGV subcabecera {;}

;
cabecera : PROGRAM LOWER STRINGV HIGHER {;}
		|  PROGRAM STRINGQUOTE {;}
;

constdef : 
        DEFINE STRINGV values SEMICOLON {
                Node node;
                strcpy(node.name, $2);
                node.isConstant = 1;
                node.isValue = 1;
                node.type = 0;
                strcpy(node.value, $3);
                InsertElementT(&typelist, &node);
                free($2);
                free($3);
                }
        |CONST type STRINGV EQ values SEMICOLON {
                Node node;
                strcpy(node.name, $3);
                node.isConstant = 1;
                node.isValue = 1;
                node.type = $2;
                strcpy(node.value, $5);
                InsertElementT(&typelist, &node);
                free($3);
                free($5);
                }
;

vardef : 
        type STRINGV SEMICOLON {
                Node node;
                strcpy(node.name, $2);
                node.type = $1;
                node.isValue = 0;
                node.isConstant = 0;
                InsertElementT(&typelist, &node);
                free($2);
                }
        | type STRINGV EQ values SEMICOLON {
                Node node;
                strcpy(node.name, $2);
                char value[10];
                node.isConstant = 0;
                node.isValue = 1;
                node.type = $1;
                strcpy(node.value, $4);
                InsertElementT(&typelist, &node);
                free($2);
                free($4);
                }
        | type STRINGV EQ STRINGV SEMICOLON {
                Node node;
                strcpy(node.name, $2);
                char value[10];
                node.isConstant = 0;
                node.isValue = 1;
                node.type = $1;
                strcpy(node.value, $4);
                InsertElementT(&typelist, &node);
                free($2);
                free($4);
                }
        
;

type : 
        INTEGER {$$ = 0;}
        | FLOAT {$$ = 1;}
        | STRING {$$ = 2;}
        | CHAR {$$ = 3;}
        | BOOLEAN {$$ = 0;}
;



values : 
        TRUEVAL {$$ = strdup("1");}
        | FALSEVAL {$$ = strdup("0");}
        | INTNUM {$$ = $1;}
        | REALNUM {$$ = $1;}
        | QUOTESTRING {;}
;
programa : type STRINGV LPAREN RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET comment {
                ;
                
                
                }
        | type STRINGV LPAREN args RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET comment{
                ;
                }
        | type STRINGV LPAREN RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET comment programa{
                ;
                }
        | type STRINGV LPAREN args RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET comment programa{
                ;
                }
        | type STRINGV LPAREN args RPAREN OPENCURLYBRACKET CLOSECURLYBRACKET comment programa {
                ;
                }
        | type STRINGV LPAREN RPAREN OPENCURLYBRACKET CLOSECURLYBRACKET comment programa {
                ;
        }
        | type STRINGV LPAREN args RPAREN OPENCURLYBRACKET CLOSECURLYBRACKET comment  {
                ;
        }
        | type STRINGV LPAREN RPAREN OPENCURLYBRACKET CLOSECURLYBRACKET comment  {
                ;
        }
        | vardef programa {;}
        | constdef programa {;}
        

;

args : 
	type STRINGV COMMA args {;}
	|type STRINGV {;}
;

lines_program : 
        line_program lines_program {
                char * final = malloc(strlen($1) * sizeof(char) + strlen($2) * sizeof(char) + sizeof("\n") + 3);
                strcpy(final, $1);
                strcat(final, "\n");
                strcat(final, $2);
                free($1);
                free($2);
                $$ = final;
                }
        | line_program {
                $$ = $1;
                }
;



line_program : 
        WRITE LOWER LOWER contentWrite SEMICOLON {;}
        |WRITE LOWER LOWER contentWrite LOWER LOWER ENDL SEMICOLON{;}
        /*
        | READ LPAREN contentRead RPAREN SEMICOLON {;}
        | READLN LPAREN contentRead RPAREN SEMICOLON {;}*/
        | assignation {;}
        | IF LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET /*line_program*/ {;}
        | ELSE IF LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET /*line_program */{;}
        | ELSE OPENCURLYBRACKET line_program CLOSECURLYBRACKET {;}
        /*| IF LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET ELSE OPENCURLYBRACKET lines_program CLOSECURLYBRACKET {;}
        | IF LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET ELSE IF LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET {;}
        | IF LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET {;}*/
        | FOR LPAREN type STRINGV EQ INTNUM SEMICOLON exp SEMICOLON STRINGV operand RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET {
                
                ;}
        | FOR LPAREN type STRINGV EQ INTNUM SEMICOLON exp SEMICOLON assignation  RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET {;}
        | DO OPENCURLYBRACKET lines_program CLOSECURLYBRACKET WHILE LPAREN exp RPAREN SEMICOLON{;}
        | WHILE LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET{;}
        | COMMENTLINE {;}
        | MULTILINE {;}
        | vardef {;}
        | constdef {;}
        | RETURN exp SEMICOLON {;}
        
;

contentWrite : 
        contentWrite COMMA QUOTESTRING {
			deleteQuotes($3);
			char * final = malloc ( strlen($1) * sizeof(char) + strlen($3) * sizeof(char) +1);
			strcpy(final, $1);
			strcat(final, $3);
			free($1);
			free($3);
			$$ = final;
		}//para los printf
        | contentWrite PLUS STRINGV {
			deleteQuotes($3);
			char * final = malloc ( strlen($1) * sizeof(char) + strlen($3) * sizeof(char) +1);
			strcpy(final, $1);
			strcat(final, $3);
			free($1);
			free($3);
			$$ = final;
		}//para los cout
		| contentWrite COMMA STRINGV {
			if(!checkName(&typelist,$3)) {
					printf("Error: Variable %s no declarada\n", $3);
					yyclearin;
					exit(0); 
			}     
			NameNode node;
			strcpy(node.name, $3);
			InsertElementN (&queue, &node);
			int type = SearchType(&typelist, $3);
			char * typeref = malloc(strlen($1) * sizeof(char) + sizeof("%lf") + 1);
			char * ty = getRef(type);
			strcpy(typeref, $1);
			strcat(typeref, ty);
			free($1);
			free(ty);
			$$ = typeref;
		}//para los printf
        | QUOTESTRING {;}
        | STRINGV {$$ = strdup($1);}
;
/*contentRead : 
         STRINGV {; }
;*/

assignation :
//STRINGV COLON EQ exp SEMICOLON
        STRINGV EQ exp SEMICOLON {
			if ((!checkName(&typelist, $1))){
                        printf("Error: Variable %s no declarada\n", $1);
                        yyclearin;
                        exit(0);
                }
                if(checkConstant(&typelist, $1)) {
                        printf("Error: %s es una constante, no puedes reasignar su valor\n", $1);
                        yyclearin;
                        exit(0);  
                }
                if((($3[0] == '\"') && ($3[strlen($3)-1] == '\"')) || ((checkName(&typelist, $3)) && SearchType(&typelist, $3))){
                        char * final = malloc(strlen($1) * sizeof(char) + sizeof("strcpy(,)") + strlen($3) * sizeof(char) + sizeof(";") + 1);
                        strcpy(final, "strcpy(");
                        strcat(final, $1);
                        strcat(final, ",");
                        strcat(final, $3);
                        strcat(final, ");");
                        $$ = final;
                }else{
                        char * final = malloc(strlen($1) * sizeof(char) + sizeof(" = ") + strlen($3) * sizeof(char) + sizeof(";") + 1);
                        strcpy(final, $1);
                        strcat(final, " = ");
                        strcat(final, $3);
                        strcat(final, ";"); 
                        $$ = final;
                }
		}

;

exp : //exp operand term {;}
        term {
			$$ = $1;	
			}

;

term :
        atom {
			$$ = $1;
			}
        | LPAREN exp RPAREN {
			char * final = malloc(strlen($2) * sizeof(char) + sizeof("()") + 1);
			strcpy(final, "(");
			strcat(final, $2);
			strcat(final, ")");
			free($2);
			$$ = final;
		}
        | HYPHEN atom {
			char * final = malloc(strlen($2) * sizeof(char) + sizeof("-()") + 1);
                strcpy(final, "-(");
                strcat(final, $2);
                strcat(final, ")");
                free($2);
                $$ = final;
		}
        | EX exp {
			char * final = malloc(strlen($2) * sizeof(char) + sizeof("!()") + 1);
                strcpy(final, "!(");
                strcat(final, $2);
                strcat(final, ")");
                free($2);
                $$ = final;
		}
;

operand : 
        PLUS {$$ = strdup(" + ");}
		|PLUS EQ {$$ = strdup(" += ");;}
        |HYPHEN {$$ = strdup(" - ");}
		|HYPHEN EQ {$$ = strdup(" -= ");;}
        |PROD {$$ = strdup(" * ");}
        |DIV {$$ = strdup(" / ");}
        |DIVINT {$$ = strdup(" / ");}
        |MOD {$$ = strdup(" % ");}
        |LOWER {$$ = strdup(" < ");}
        |HIGHER {$$ = strdup(" > ");}
        |LOWER EQ {$$ = strdup(" <= ");}
        |HIGHER EQ {$$ = strdup(" >= ");}
        |EQ {$$ = strdup(" == ");}
        |AND {$$ = strdup(" && ");}
        |OR{$$ = strdup(" || ");;}
;

atom :

        STRINGV {
			if (!checkName(&typelist, $1)){
                        printf("Error: Variable %s no declarada\n", $1);
                        yyclearin;
                        exit(0);
            }
            $$ = $1;
		}
        | values {
			$$ = $1;
		}
;

%%


/* Funciones auxiliares de borrado de caracteres */
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

/* Procesa los elementos a incluir en el string de Write */
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

/* Procesa los elementos a incluir en el string de Read */
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

/* Recupera las variables declaradas */
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

/*0=int, 1=double, 2=string, 3=char*/
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
        FILE *fp = fopen(outputName, "w");
        if(fp!=NULL){
                        
                        fputs("", fp);
                        fclose(fp);
                }

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
        //ShowListT(&typelist);
	return 0;
}