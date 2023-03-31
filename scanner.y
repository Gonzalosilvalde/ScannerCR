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
TypeList flist;
//queue será la cola a través de la cual recogeremos y volcaremos las variables de los printf 
NodeList queue;
char printV[20]= "";

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

%left <valString>SEMICOLON
%left <valString>EQ
%left LOWER HIGHER
%left <valString>PLUS HYPHEN
%left PROD DIV
%left DIVINT MOD
%left AND OR
%right EX


%type <valString> vardef args
%type subcabecera
%type <valString>  values
%type <valInt> type
%type <valString> subcabecera cabecera
%type <valString> lines_program line_program
%type <valString> contentWrite programa precontentWrite 
%type <valString> comment
%type <valString> assignation atom
%type <valString> operand 
%type <valString> exp term
%start S 
%%
S : 

        cabecera subcabecera programa { 
                
                FILE *fp = fopen(outputName, "w");
                
                if (fp!=NULL) {
                fputs($3, fp);
                    fclose(fp);  
                }
                
        }
        |cabecera comment subcabecera programa { 
                
                //printf("%s\n", $4);
                FILE *fp = fopen(outputName, "w");
				//char * variables = getVariables(&typelist);
                
                if (fp!=NULL) {
                    fputs($4, fp);
                    fclose(fp);  
                }
        }
        |cabecera subcabecera comment programa { 
                
                //printf("%s\n", $4);//por alguna razon devuelve de la segunda linea, el tercer valor, pasa lo mismo con subcabecera, en cambio en cabecera no pasa eso
                
                FILE *fp = fopen(outputName, "w");
		//char * variables = getVariables(&typelist);
                
                if (fp!=NULL) {
                    //fputs($3, fp);
                    fclose(fp);  
                }
        }
        |cabecera comment subcabecera comment programa { 
                
               /* FILE *fp = fopen(outputName, "w");
				char * variables = getVariables(&typelist);
                
                if (fp!=NULL) {
                    fputs(variables, fp);
                    fclose(fp);    
                }*/
        }

;

comment :
         COMMENTLINE {;
                }
        | MULTILINE {;}

        
;

subcabecera :
        STRINGV SEMICOLON {$$ = "subcabecera";}
        |STRINGV subcabecera {;}

;
cabecera : PROGRAM LOWER STRINGV HIGHER {$$ = "hola";}
		|  PROGRAM STRINGQUOTE {;}
;

constdef : 
        DEFINE STRINGV values SEMICOLON {
                /*Node node;
                strcpy(node.name, $2);
                node.isConstant = 1;
                node.isValue = 1;
                node.type = 0;
                strcpy(node.value, $3);
                InsertElementT(&typelist, &node);
                free($2);
                free($3);
                */}
        |CONST type STRINGV EQ values SEMICOLON {
                /*Node node;
                strcpy(node.name, $3);
                node.isConstant = 1;
                node.isValue = 1;
                node.type = $2;
                strcpy(node.value, $5);
                InsertElementT(&typelist, &node);
                free($3);
                free($5);
               */ }
;


fvardef : 
        type STRINGV SEMICOLON {
                Node node;
                strcpy(node.name, $2);
                node.type = $1;
                node.isValue = 0;
                node.isConstant = 0;
                InsertElementT(&flist, &node);
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
                InsertElementT(&flist, &node);
                free($2);
                free($4);
                }
        | type STRINGV EQ STRINGV SEMICOLON {
                /*Node node;
                strcpy(node.name, $2);
                char value[10];
                node.isConstant = 0;
                node.isValue = 1;
                node.type = $1;
                strcpy(node.value, $4);
                InsertElementT(&typelist, &node);
                free($2);
                free($4);
               */ }
        
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
                /*Node node;
                strcpy(node.name, $2);
                char value[10];
                node.isConstant = 0;
                node.isValue = 1;
                node.type = $1;
                strcpy(node.value, $4);
                InsertElementT(&typelist, &node);
                free($2);
                free($4);
               */ }
        
;

type : 
        INTEGER {$$ = 0;}
        | FLOAT {/*$$ = 1;*/}
        | STRING {/*$$ = 2;*/}
        | CHAR {/*$$ = 3;*/}
        | BOOLEAN {/*$$ = 0;*/}
;



values : 
        TRUEVAL {/*$$ = strdup("1");*/}
        | FALSEVAL {/*$$ = strdup("0");*/}
        | INTNUM {/*$$ = $1;*/}
        | REALNUM {/*$$ = $1;*/}
        | QUOTESTRING {;}
;
programa : 
         type STRINGV LPAREN args RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET comment{
                if($1 == 0){
                        
                        char * variables = getVariables(&flist);
                        char * final = malloc( strlen($4) * sizeof(char) + strlen($7) * sizeof(char)  + strlen(variables) * sizeof(char) + 20*sizeof(char) + sizeof(" -> i16")+ sizeof("fn "));
                        memset(final, 0, sizeof(final));
                        
                        strcat(final, "fn (");
                        strcat(final,$4);
                        strcat(final,") ");
                        strcat(final, $2);
                        strcat(final, "-> i32 {");
                        strcat(final, "\n");
                        strcat(final, variables);
                        strcat(final, "\n");
                        strcat(final, $7);
                        strcat(final, "\n");
                        strcat(final, "}");
                        free($7);
                        free($4);
                        free(variables);
                        DeleteListT (&flist);
                        $$ = final;
                                
                }else{
                        char * variables = getVariables(&flist);
                        char * final = malloc( strlen($7) * sizeof(char)  + strlen(variables) * sizeof(char) + 20*sizeof(char));
                        memset(final, 0, sizeof(final));

                        strcat(final, variables);
                        strcat(final, "\n");
                        strcat(final, $7);
                        free($7);
                        free(variables);
                        $$ = final;
                }
                }

        |type STRINGV LPAREN RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET comment {
                
                if($1 == 0){
                        
                        char * variables = getVariables(&flist);
                        char * final = malloc( strlen($6) * sizeof(char)  + strlen(variables) * sizeof(char) + 20*sizeof(char) + sizeof(" -> i16")+ sizeof("fn "));
                        memset(final, 0, sizeof(final));
                        
                        strcat(final, "fn () ");
                        strcat(final, $2);
                        strcat(final, "-> i32 {");
                        strcat(final, "\n");
                        strcat(final, variables);
                        strcat(final, "\n");
                        strcat(final, $6);
                        strcat(final, "\n");
                        strcat(final, "}");

                        free($6);
                        free(variables);
                        DeleteListT (&flist);
                        $$ = final;
                                
                }else{
                        char * variables = getVariables(&flist);
                        char * final = malloc( strlen($6) * sizeof(char)  + strlen(variables) * sizeof(char) + 20*sizeof(char));
                        memset(final, 0, sizeof(final));

                        strcat(final, variables);
                        strcat(final, "\n");
                        strcat(final, $6);
                        free($6);
                        free(variables);
                        $$ = final;
                }
        }

        | type STRINGV LPAREN RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET comment programa{
                if($1 == 0){
                        
                        char * variables = getVariables(&flist);
                        char * final = malloc( strlen($9) * sizeof(char) + strlen($6) * sizeof(char)  + strlen(variables) * sizeof(char) + 20*sizeof(char) + sizeof(" -> i16")+ sizeof("fn "));
                        memset(final, 0, sizeof(final));
                        
                        
                        strcat(final, "fn () ");
                        strcat(final, $2);
                        strcat(final, "-> i32 {");
                        strcat(final, "\n");
                        strcat(final, variables);
                        strcat(final, "\n");
                        strcat(final, $6);
                        strcat(final, "\n");
                        strcat(final, "}");
                        strcat(final, "\n\n");
                        strcat(final, $9);

                        free($6);
                        free($9);
                        free(variables);
                        DeleteListT (&flist);
                        $$ = final;
                                
                }else{
                        char * variables = getVariables(&flist);
                        char * final = malloc( strlen($6) * sizeof(char)  + strlen(variables) * sizeof(char) + 20*sizeof(char));
                        memset(final, 0, sizeof(final));

                        strcat(final, variables);
                        strcat(final, "\n");
                        strcat(final, $6);
                        free($6);
                        free(variables);
                        $$ = final;
                }
                }
        | type STRINGV LPAREN args RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET comment programa{
                ;
                }
        
        | vardef programa {
                
                $$ = $2;}
        | constdef programa {
                
                $$ = $2;}

;

args : 
	type STRINGV COMMA args {
                char * final;
                if($1 == 0){
                        final = malloc(strlen("i16") * sizeof(char) + strlen($2) * sizeof(char) + strlen($4) * sizeof(char) + sizeof(",") + 3*sizeof(char));

                }
                else{
                        printf("pasa por aqui \n");
                }
                strcat(final, $4);
                strcat(final, ",");
                strcat(final, " ");
                strcat(final, "i16");
                strcat(final, " ");
                strcat(final, $2);
                free($4);
                $$ = final;
                
                }
	|type STRINGV {
                char * final;
                if($1 == 0){
                        final = malloc(strlen("i16") * sizeof(char) + strlen($2) * sizeof(char));
                } else {
                        printf("pasa por aqui \n");

                }
                strcat(final, "i16");
                strcat(final, " ");
                strcat(final, $2);
                $$ = final;
        }
;

lines_program : 
        lines_program line_program {
                
                char * final = malloc(strlen($1) * sizeof(char) + strlen($2) * sizeof(char) + sizeof("\n") + 3*sizeof(char));
                memset(final, 0, sizeof(final));

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
        WRITE LOWER LOWER precontentWrite SEMICOLON {
                
                $$ = $4;
                
        }
        | assignation {
                $$ = $1;
        }
        | IF LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  {
                char * final = malloc(strlen($3)* sizeof(char) + strlen($6)*sizeof(char) + sizeof("if ( ) { } \t \n \n"));
                memset(final, 0, sizeof(final));
                strcat(final, "if (");
                strcat(final, $3);
                strcat(final, "){\n\t");
                strcat(final, $6);
                strcat(final, "\n}");
                free($3);
                free($6);
                $$ = final;

        }
        | ELSE IF LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET {
                char * final = malloc(strlen($4)* sizeof(char) + strlen($7)*sizeof(char) + sizeof("else if ( ) { } \t \n \n"));
                memset(final, 0, sizeof(final));
                strcat(final, "else if (");
                strcat(final, $4);
                strcat(final, "){\n\t");
                strcat(final, $7);
                strcat(final, "\n}");
                free($4);
                free($7);
                $$ = final;
        }
        | ELSE OPENCURLYBRACKET line_program CLOSECURLYBRACKET {
                char* final = malloc(strlen($3)*sizeof(char)+ sizeof("else {} \n \n \t"));
                memset(final, 0, sizeof(final));
                strcat(final, "else{\n\t");
                strcat(final, $3);
                strcat(final, "}\n");
                $$ = final;
        
        }
        | FOR LPAREN type STRINGV EQ INTNUM SEMICOLON exp SEMICOLON STRINGV operand RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET {
                char * final = malloc($3*sizeof(int) + strlen($8)*sizeof(char) +
                                sizeof("for ; ; {}")+strlen($4)*sizeof(char)+ strlen($6)*sizeof(char) + strlen($10)*sizeof(char) + 
                                strlen($11)*sizeof(char) + strlen($14)*sizeof(char));
                memset(final,0, strlen(final));

                int len = strlen($8);
                char* numero = (char*) malloc(len + 1); // Reservar espacio para el nuevo número (+1 por el '\0')
                char* newNumero = (char*) malloc(2); // Reservar espacio para el dígito y el '\0'
                numero[0] = '\0'; // Inicializar la cadena vacía
                for (int i = len - 1; i >= 0; i--) {
                if (!isdigit($8[i])) {
                        break;
                        
                } else {
                        newNumero[0] = $8[i];
                        newNumero[1] = '\0'; // Agregar el '\0' para que sea una cadena válida
                        char* temp = strdup(numero); // Crear una copia temporal de la cadena
                        strcpy(numero, newNumero); // Copiar el dígito al principio de la cadena
                        strcat(numero, temp); // Concatenar el resto de la cadena al final
                        free(temp); // Liberar la memoria de la cadena temporal
                }
                }
                free(newNumero); // Liberar la memoria del dígito

                strcat(final, "for ");
                strcat(final, $4);
                strcat(final, " in ");
                strcat(final, $6);
                strcat(final, "..");
                strcat(final, numero);
                strcat(final, "{\n\t");
                strcat(final, $14);
                strcat(final, "\n}");
                $$=final;
                ;}
        | FOR LPAREN type STRINGV EQ INTNUM SEMICOLON exp SEMICOLON assignation  RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET {;}
        | DO OPENCURLYBRACKET lines_program CLOSECURLYBRACKET WHILE LPAREN exp RPAREN SEMICOLON{;}
        | WHILE LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET{;}
        | comment{;}
        | RETURN exp SEMICOLON {;}
        | fvardef{$$ = strdup("");}

;

precontentWrite:
        contentWrite{
                if(strlen(printV) ==0){
                        char * final = malloc(strlen($1)*sizeof(char) + strlen(printV)*sizeof(char)+strlen("print!();") * sizeof(char) );
                        memset(final, 0, sizeof(final));
                        strcat(final, "print!(");
                        strcat(final,$1);
                        strcat(final, ");");
                        $$ = final;
                }else{
                        char * final = malloc(strlen($1)*sizeof(char) + strlen("{},,,")*sizeof(char) + strlen(printV)*sizeof(char)+strlen("print!(\"") * sizeof(char)+ strlen("\");")*sizeof(char));
                        memset(final, 0, sizeof(final));
                        
                        int contador = 0;
                        int longitud = strlen(printV); // Obtenemos la longitud de la cadena original
                        char* nueva_cadena = (char*) malloc(sizeof(char) * (longitud * 2)); // Reservamos memoria para la nueva cadena

                        for (int i = 0; i < longitud; i++) {
                                nueva_cadena[i*2] = printV[i]; // Copiamos el carácter de la cadena original
                                if (i != longitud - 1) {
                                        nueva_cadena[i*2+1] = ','; // Insertamos una coma entre los caracteres, excepto en el último
                                }
                        }

                        nueva_cadena[longitud*2-1] = '\0'; // Agregamos el terminador nulo al final de la nueva cadena

                        
                        for (int i = 0; $1[i] != '\0'; i++) {
                                if ($1[i] == '}') {
                                        contador++;
                                }
                        }
                        strcat(final, "print!(");
                        if(strlen(printV) == contador){
                                strcat(final, "\"");
                                strcat(final, $1);
                                strcat(final, "\"");
                                strcat(final, ",");
                                strcat(final, nueva_cadena);
                                
                        } else if (strlen(printV) > contador){
                                strcat(final, "\"");
                                strcat(final, $1);
                                strcat(final, "{}");
                                strcat(final, "\"");
                                strcat(final, ",");
                                strcat(final, nueva_cadena);
                                
                        } else {
                                printf("tiene que haber algun error");
                        }
                        strcat(final, ");");
                        memset(printV, 0, sizeof(printV));
                        free($1);
                        $$ = final;
                }



        }
        |contentWrite LOWER LOWER ENDL{
                if(strlen(printV) ==0){
                        char * final = malloc(strlen($1)*sizeof(char) + strlen(printV)*sizeof(char)+strlen("println!();") * sizeof(char) );
                        memset(final, 0, sizeof(final));
                        strcat(final, "println!(");
                        strcat(final,$1);
                        strcat(final, ");");
                        $$ = final;
                }else{
                        char * final = malloc(strlen($1)*sizeof(char) + strlen("{},,,")*sizeof(char) + strlen(printV)*sizeof(char)+strlen("println!(\"") * sizeof(char)+ strlen("\");")*sizeof(char));
                        memset(final, 0, sizeof(final));
                        
                        int contador = 0;
                        int longitud = strlen(printV); // Obtenemos la longitud de la cadena original
                        char* nueva_cadena = (char*) malloc(sizeof(char) * (longitud * 2)); // Reservamos memoria para la nueva cadena

                        for (int i = 0; i < longitud; i++) {
                                nueva_cadena[i*2] = printV[i]; // Copiamos el carácter de la cadena original
                                if (i != longitud - 1) {
                                        nueva_cadena[i*2+1] = ','; // Insertamos una coma entre los caracteres, excepto en el último
                                }
                        }

                        nueva_cadena[longitud*2-1] = '\0'; // Agregamos el terminador nulo al final de la nueva cadena

                        
                        for (int i = 0; $1[i] != '\0'; i++) {
                                if ($1[i] == '}') {
                                        contador++;
                                }
                        }
                        strcat(final, "print!(");
                        if(strlen(printV) == contador){
                                strcat(final, "\"");
                                strcat(final, $1);
                                strcat(final, "\"");
                                strcat(final, ",");
                                strcat(final, nueva_cadena);
                                
                        } else if (strlen(printV) > contador){
                                strcat(final, "\"");
                                strcat(final, $1);
                                strcat(final, "{}");
                                strcat(final, "\"");
                                strcat(final, ",");
                                strcat(final, nueva_cadena);
                                
                        } else {
                                printf("tiene que haber algun error");
                        }
                        strcat(final, ");");
                        memset(printV, 0, sizeof(printV));
                        free($1);
                        $$ = final;
                }
        }
        
;

contentWrite : 
        contentWrite LOWER LOWER QUOTESTRING{
                char * final = malloc(strlen($1) * sizeof(char) + strlen($4) * sizeof(char) + strlen("{}") * sizeof(char)+strlen("println!(\"")); 
                memset(final, 0, sizeof(final));
                char temp[strlen($4)];
                memset(temp,0,strlen($4));

                strcat(temp, $4);
                
                strcat(final, $1);
                strcat(final,"{}");
                deleteQuotes(final);
                deleteQuotes(temp);

                strcat(final, temp);
                free($1);
                $$ = final;
        }
        |contentWrite LOWER LOWER STRINGV{
                char * final = malloc(strlen($1) * sizeof(char) + strlen($4) * sizeof(char) + strlen("{}") * sizeof(char)); 
                memset(final, 0, sizeof(final));

                strcat(printV,$4);
                

                $$ = $1;
        }
        |contentWrite PLUS QUOTESTRING{
                char * final = malloc(strlen($1) * sizeof(char) + strlen($3) * sizeof(char) + strlen("+") * sizeof(char)); 
                memset(final, 0, sizeof(final));

                char temp[strlen($3)];
                memset(temp,0,strlen($3));

                strcat(temp, $3);
                
                strcat(final, $1);
                strcat(final,"{}");
                deleteQuotes(final);
                deleteQuotes(temp);

                strcat(final, temp);
                free($1);
                $$ = final;
        }
        |contentWrite PLUS STRINGV{
                char * final = malloc(strlen($1) * sizeof(char) + strlen($3) * sizeof(char) + strlen("{}") * sizeof(char)); 
                memset(final, 0, sizeof(final));

                strcat(printV,$3);
                

                $$ = $1;
        }
        
        | QUOTESTRING {

                $$ = $1;}
        | STRINGV {
                $$ = $1;}
;

assignation :
        STRINGV EQ exp SEMICOLON {
                char * final = malloc(strlen($1) * sizeof(char) + sizeof(" = ") + strlen($3) * sizeof(char) + sizeof(";") + 1);
                strcpy(final, $1);
                strcat(final, " = ");
                strcat(final, $3);
                strcat(final, ";"); 
                free($3);
                free($1);
                $$ = final;
		/*if ((!checkName(&typelist, $1))){
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
                        if($1 != NULL && $3 != NULL){
                        printf("lines program %s, %s", $1, $3);
                        $$ = "STRINGV EQ exp SEMICOLON primer if";
                        }
                        else if($1 != NULL ){
                        printf("lines program %s" ,$1);
                        $$ = "STRINGV EQ exp SEMICOLON segundo if";}
                        else if($3 != NULL){
                        printf("lines program %s" , $3);
                        $$ = "STRINGV EQ exp SEMICOLON tercer if";}
                        
                }*/
		}

;

exp :   exp operand term {
                
                char * final = malloc(strlen($1) * sizeof(char) +strlen($2) * sizeof(char) + strlen($3) * sizeof(char) + 1);
                strcpy(final, $1);
                strcat(final, $2);
                strcat(final, $3);
                free($1);
                free($2);
                free($3);
                $$ = final;
                
        }
        |term {
        	$$ = $1;
			}

;

term :
        atom {$$ = $1;}
        | LPAREN exp RPAREN {
                /*char * final = malloc(strlen($2) * sizeof(char) + sizeof("()") + 1);
                strcpy(final, "(");
                strcat(final, $2);
                strcat(final, ")");
                free($2);
                $$ = final;*/
                }
        | HYPHEN atom {
                /*char * final = malloc(strlen($2) * sizeof(char) + sizeof("-()") + 1);
                strcpy(final, "-(");
                strcat(final, $2);
                strcat(final, ")");
                free($2);
                $$ = final;
                */}
        | EX exp {
                /*char * final = malloc(strlen($2) * sizeof(char) + sizeof("!()") + 1);
                strcpy(final, "!(");
                strcat(final, $2);
                strcat(final, ")");
                free($2);
                $$ = final;
                */}
;

operand : 
        PLUS {
                $$ = strdup(" + ");
        }
	|PLUS EQ {$$ = strdup(" += ");}
        |HYPHEN {$$ = strdup(" - ");}
	|HYPHEN EQ {$$ = strdup(" -= ");}
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
        |PLUS PLUS {$$ = strdup(" ++ ");}
        |OR{$$ = strdup(" || ");}
;

atom :

        STRINGV {
			/*if (!checkName(&typelist, $1)){
                        printf("Error: Variable %s no declarada\n", $1);
                        yyclearin;
                        exit(0);
            }
            $$ = $1;*/
		}
        | values {
			/*$$ = $1;*/
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