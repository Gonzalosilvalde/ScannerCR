%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <pthread.h>
#include <unistd.h>
#include <omp.h>
#include "list.h"
#include "scanner.tab.h"

typedef struct yy_buffer_state * YY_BUFFER_STATE;
extern int yylex(void); 
extern int yylineno;
extern char *yytext;
extern void yyrestart( FILE *new_file );
extern void yy_flush_buffer( YY_BUFFER_STATE buffer );
extern void yy_switch_to_buffer( YY_BUFFER_STATE new_buffer );
extern YY_BUFFER_STATE yy_create_buffer( FILE *file, int size );
extern YY_BUFFER_STATE yy_current_buffer();
extern void yypush_buffer_state ( YY_BUFFER_STATE new_buffer  );
extern void yypop_buffer_state ( void );
pthread_mutex_t mutex;
pthread_mutex_t file_mutex;
extern FILE *yyin;
char filePath[100] ;
char filePathOld[100];

int global_argc; // Variable global para almacenar argc
char **global_argv; // Variable global para almacenar argv

char **arrayCabeceras = NULL;
int arraySize = 0;

char sizeS[8] = "200";

char tipoStruct[50] = "";

int inputCount = 0;////////////////por ahora no hace nada, pero en el futuro usar para escribir en el cargo.toml

const char *nombreArchivo = "cabeceras.txt";

//typeList será la tabla de tipos y constantes.
TypeList typelist;
TypeList flist;
char gType[10] = "";
//queue será la cola a través de la cual recogeremos y volcaremos las variables de los printf 
NodeList queue;
char printV[100]= "";
//int comienzo ( int argc, char * argv[]);
void yyerror(char const *);
char * getVariables(TypeList *);
void saveGType(char *tipo);
char *getGType();
char *insertTabsBetweenBraces(char *code);
char * getEndings(NodeList *);
void custom_function();
char * getEndingsR(NodeList *);
char * obtenerTipo(int valor);
void replaceSemicolon(char *string);
char * getRef (int);
void deleteQuotes (char *);
char *reemplazar(const char *cadena, const char *busqueda, const char *reemplazo);
void deleteCurly(char *);
void deleteNewLines(char *);
char* getEndNumber(char* number);
int searchString(char **arr, char *toFind, int size);
char* getStringFromExp(char* str);
%}

%define parse.error verbose 
%verbose
%define parse.trace
  

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
%token LISTCONTENT
%token VALUE
%token LPAREN
%token STRINGQUOTE
%token RPAREN
%token RSQUAREPAREN
%token LSQUAREPAREN
%token COLON
%token SEMICOLON
%token INTEGER
%token SHORT
%token LONG
%token UNSIGNED_INT
%token UNSIGNED_SHORT
%token UNSIGNED_LONG
%token FLOAT
%token DOUBLE
%token VOID
%token OPENCURLYBRACKET
%token CLOSECURLYBRACKET
%token BOOLEAN
%token CHAR
%token PRINTF
%token SCANF
%token <valString> STRING
%token <valString> STRINGV
%token <valString> QUOTESTRING
%token <valString>TRUEVAL
%token <valString>FALSEVAL
%token <valString> INTNUM
%token <valString> REALNUM
%token RETURN
%token STRUCT
%token AMPERSAND

%left <valString>SEMICOLON
%left <valString>EQ
%left LOWER HIGHER
%left <valString>PLUS HYPHEN
%left PROD DIV
%left DIVINT MOD
%left AND OR
%right EX
%right LPAREN
%left RPAREN
%left DOT


%type <valString> vardef constdef args 
%type <valString> preprograma

%type <valString>  values array
%type <valInt> type
%type <valString>  cabecera 
%type <valString> lines_program line_program
%type <valString> contentWrite programa precontentWrite 
%type <valString> comment
%type <valString> atom
%type <valString> operand 
%type <valString> exp term
%start S 
%%
S : 

        cabecera preprograma { 
                char* entrada = (char*)malloc(strlen(filePath) + 1); // Asignar memoria para la cadena
                memset(entrada, 0 , sizeof(entrada));
                printf("filepath: %s\n", filePath );
                
                strcpy(entrada, filePath);
                printf("entrada: %s\n", entrada );
                char salida[100]; // Puedes ajustar el tamaño del buffer según tus necesidades

                // Encontrar la posición del primer '/' desde el final de la cadena
                char* lastSlash = strrchr(entrada, '/');
                printf("lastSlash: %s\n", lastSlash );


                // Si lastSlash no es NULL, significa que se ha encontrado el caracter '/'
                if (lastSlash) {
                        // Calcular la longitud de la subcadena a partir del último '/'
                        size_t length = strlen(lastSlash + 1);
                        
                        // Copiar la subcadena a 'salida' y sustituir la extensión
                        strcpy(salida, "salida"); // Copiar "salida/" a la cadena 'salida'
                        strncat(salida, lastSlash, length - 1); // Agregar la subcadena 'hola' sin la extensión
                        strcat(salida, ".rs"); // Agregar la extensión ".rs" al final

                        printf("sal   %s\n", salida); // Imprimir el resultado
                } else {
                        printf("No se ha encontrado '/' en la cadena de entrada.\n");
                }

                free(entrada);
                printf("%s", salida);
                FILE *fp = fopen(salida, "w");

                if (fp != NULL) {
                        char *resultado = insertTabsBetweenBraces($2);
                        if (resultado != NULL) {

                                fputs(resultado, fp);
                                fclose(fp);
                                
                        }
                }
                
                
        }
        


;

comment :
         COMMENTLINE {
                $$ = $1;
                }
        | MULTILINE {;}

        
;

cabecera : PROGRAM LOWER STRINGV HIGHER {$$ = "";}
                |PROGRAM LOWER STRINGV DOT STRINGV HIGHER {$$ = "";}
		|PROGRAM QUOTESTRING {
                        #pragma omp critical
                        {       
                                char final[100] = "";
                                char fichero[50] = "";
                                strcat(fichero, $2);
                                deleteQuotes(fichero);
                                fichero[strlen(fichero) - 2] = '\0';
                        
                                char ruta[100] = "entrada/";

                                strcat(final, fichero);
                                strcat(final, ".c");
                                printf("-----------------%s------------------ \n", final);
                                strcat(ruta, final);
                                if(searchString(arrayCabeceras, ruta, arraySize ) == 0){
                                        arraySize++;
                                        arrayCabeceras = (char**)realloc(arrayCabeceras, arraySize * sizeof(char*));
                                        arrayCabeceras[arraySize - 1] = (char*)malloc(strlen(ruta) * sizeof(char)); 

                                        strcpy(arrayCabeceras[arraySize - 1], ruta);
                                        printf("array size %i\n\n", arraySize);
                                        printf("array cabeceras %s\n\n", arrayCabeceras[arraySize - 1]);
                                        printf("ruta  %s\n\n", ruta);
                                }
                                

                        }
                        
                        
                        
                }
                |PROGRAM LOWER STRINGV HIGHER cabecera {$$ = "";}
                |PROGRAM LOWER STRINGV DOT STRINGV HIGHER cabecera{$$ = "";}
		|PROGRAM QUOTESTRING cabecera{
                                                
                        #pragma omp critical
                        {       
                                char final[100] = "";
                                char fichero[50] = "";
                                strcat(fichero, $2);
                                deleteQuotes(fichero);
                                fichero[strlen(fichero) - 2] = '\0';
                        
                                char ruta[100] = "entrada/";

                                strcat(final, fichero);
                                strcat(final, ".c");
                                printf("-----------------%s------------------ \n", final);
                                strcat(ruta, final);
                                
                                if(searchString(arrayCabeceras, ruta, arraySize ) == 0){

                                        arraySize++;
                                        arrayCabeceras = (char**)realloc(arrayCabeceras, arraySize * sizeof(char*));
                                        arrayCabeceras[arraySize - 1] = (char*)malloc(strlen(ruta) * sizeof(char)); 

                                        strcpy(arrayCabeceras[arraySize - 1], ruta);
                                        printf("array size %i\n\n", arraySize);
                                        printf("array cabeceras %s\n\n", arrayCabeceras[arraySize - 1]);
                                        printf("ruta  %s\n\n", ruta);
                                }

                        }
                }
;

constdef : 
        DEFINE STRINGV values {
                char * final = malloc(strlen($2)*sizeof(char)+strlen($3)*sizeof(char) + strlen("const: usize = ;\n"));
                memset(final,0, strlen(final));
                strcat(final, "const ");
                strcat(final, $2);
                strcat(final, ": usize = ");
                strcat(final, $3);
                strcat(final, ";\n");
                $$ = final;
                }
        |CONST type STRINGV EQ values SEMICOLON {
                ; }
;




vardef : 
        type STRINGV SEMICOLON {//1
                char *tipo;
                if (strcmp(obtenerTipo($1), "struct") == 0) {
                        printf("\n\n TIPO TIPO %s TIPO TIPO \n \n", obtenerTipo($1));
                        tipo = tipoStruct;
                        
                }else{
                        tipo = obtenerTipo($1);

                }                char * final = malloc(strlen(tipo)*sizeof(char) + strlen($2)*sizeof(char) + strlen("let\n: ;"));
                memset(final,0,sizeof(final));
                strcat(final,"let ");
                strcat(final,$2);
                strcat(final,":");
                strcat(final,tipo);
                strcat(final,";\n");
                $$ = final;

        }
        |type STRINGV LSQUAREPAREN atom RSQUAREPAREN SEMICOLON {
                char *tipo;
                if (strcmp(obtenerTipo($1), "struct") == 0) {
                        tipo = tipoStruct;
                        
                }else{
                        tipo = obtenerTipo($1);

                }
                char * final = malloc(strlen(tipo)* sizeof(char) +strlen($2)* sizeof(char) + strlen($4)*sizeof(char) + sizeof("[]; : ;\n"));
                memset(final, 0 , sizeof(final));
                strcat(final, $2);
                strcat(final, ": [");
                strcat(final, tipo);
                strcat(final, ";");
                strcat(final, $4);
                strcat(final, "];\n");
                $$ = final;
        }
        | type STRINGV EQ exp SEMICOLON {//2
                char *tipo;
                if (strcmp(obtenerTipo($1), "struct") == 0) {
                        tipo = tipoStruct;
                        
                }else{
                        tipo = obtenerTipo($1);

                }                char * final = malloc(strlen(tipo)*sizeof(char) + strlen($4)*sizeof(char) + strlen($2)*sizeof(char) + strlen("=let\n: ;"));
                memset(final,0,sizeof(final));
                strcat(final,"let ");
                strcat(final,$2);
                strcat(final,":");
                strcat(final,tipo);
                strcat(final,"=");
                strcat(final,$4);
                strcat(final,";\n");
                $$ = final;
        }
        
        | type STRINGV LSQUAREPAREN atom RSQUAREPAREN EQ OPENCURLYBRACKET array CLOSECURLYBRACKET SEMICOLON{//4
                char *tipo;
                if (strcmp(obtenerTipo($1), "struct") == 0) {
                        tipo = tipoStruct;
                        
                }else{
                        tipo = obtenerTipo($1);

                }                char * final = malloc(strlen($2)*sizeof(char) + strlen(tipo)*sizeof(char)+ strlen($4)*sizeof(char) + strlen($8)*sizeof(char) + sizeof("let ::[] [] ; \n"));
                memset(final,0,sizeof(final));
                
                strcat(final,"let ");
                strcat(final,$2);
                strcat(final,": [");
                strcat(final,tipo);
                strcat(final,":");
                strcat(final,$4);
                strcat(final,"] =");
                strcat(final,"[");
                strcat(final,$8);
                strcat(final,"];\n");
                $$ = final;
        }
        | type STRINGV LSQUAREPAREN RSQUAREPAREN EQ exp SEMICOLON{//4
                char *tipo;
                if (strcmp(obtenerTipo($1), "struct") == 0) {
                        tipo = tipoStruct;
                        
                }else{
                        tipo = obtenerTipo($1);

                }                char * final = malloc(strlen($2)*sizeof(char) + strlen(tipo)*sizeof(char) + strlen($6)*sizeof(char) + sizeof("let ::[] [] ; \n"));
                memset(final,0,sizeof(final));
                
                strcat(final,"let ");
                strcat(final,$2);
                strcat(final,"=");
                strcat(final,$6);
                strcat(final,";");
                $$ = final;
        }
        | type STRINGV EQ STRINGV LPAREN array RPAREN SEMICOLON{//5
                char *tipo;
                if (strcmp(obtenerTipo($1), "struct") == 0) {
                        tipo = tipoStruct;
                        
                }else{
                        tipo = obtenerTipo($1);

                }                char * final = malloc(strlen($2)*sizeof(char) +strlen($4)*sizeof(char) + strlen(tipo)*sizeof(char) + strlen($6)*sizeof(char) + sizeof("let = ();"));
                memset(final,0, sizeof(final));

                strcat(final, "let ");
                strcat(final, $2);
                strcat(final, "=");
                strcat(final, $4);
                strcat(final,"(");
                strcat(final, $6);
                strcat(final, ");");
                $$ = final;

        }
        | type STRINGV EQ STRINGV LPAREN RPAREN SEMICOLON{//6
                char *tipo;
                if (strcmp(obtenerTipo($1), "struct") == 0) {
                        tipo = tipoStruct;
                        
                }else{
                        tipo = obtenerTipo($1);

                }                char * final = malloc(strlen($2)*sizeof(char) +strlen($4)*sizeof(char) + strlen(tipo)*sizeof(char)  + sizeof("let = ();"));
                memset(final,0, sizeof(final));

                strcat(final, "let ");
                strcat(final, $2);
                strcat(final, "=");
                strcat(final, $4);
                strcat(final,"();");
        

                $$ = final;

        }
        | type STRINGV COMMA vardef{//7
                char *tipo;
                if (strcmp(obtenerTipo($1), "struct") == 0) {
                        tipo = tipoStruct;
                        
                }else{
                        tipo = obtenerTipo($1);

                }                strcpy(gType, tipo);
                char * final = malloc(strlen($2)*sizeof(char) + strlen($4)*sizeof(char)+ strlen(tipo)*sizeof(char) + sizeof(", "));
                memset(final, 0 , sizeof(final));

                strcat(final, "let ");
                strcat(final, $2);
                strcat(final, ":;\n");;
                strcat(final, $4);

                char modTipo1[4 + strlen(tipo) + 2]; // 4 por ":;\n", 2 por ": y ";\n", +1 por el nulo
                char modTipo2[4 + strlen(tipo) + 2]; // 4 por ":=\n", 2 por ": y "=", +1 por el nulo

                if (strstr(final, ":;") != NULL) {
                        memset(modTipo1, 0, sizeof(modTipo1));
                        strcat(modTipo1, ":");
                        strcat(modTipo1, tipo);
                        strcat(modTipo1, ";\n");
                }

                if (strstr(final, ":=") != NULL) {
                        memset(modTipo2, 0, sizeof(modTipo2));
                        strcat(modTipo2, ":");
                        strcat(modTipo2, tipo);
                        strcat(modTipo2, "=");
                }

                char *finalMod = reemplazar(final, ":;", modTipo1);  // Primera llamada a reemplazar

                if (finalMod != NULL) {
                        finalMod = reemplazar(finalMod, ":=", modTipo2);  // Segunda llamada a reemplazar

                        if (finalMod != NULL) {
                                $$ = finalMod;
                        } else {
                                // Manejar el error si la segunda llamada a reemplazar falla
                        }
                } else {
                        // Manejar el error si la primera llamada a reemplazar falla
                }

                
        }
        | type STRINGV EQ exp COMMA vardef{//8
                char *tipo;
                if (strcmp(obtenerTipo($1), "struct") == 0) {
                        tipo = tipoStruct;
                        
                }else{
                        tipo = obtenerTipo($1);

                }                char * final = malloc(strlen($2)*sizeof(char) + strlen($4)*sizeof(char)+ strlen($6)*sizeof(char)+ strlen(tipo)*sizeof(char) + sizeof(", "));
                memset(final, 0 , sizeof(final));

                strcat(final, "let ");
                strcat(final, $2);
                strcat(final, ":=");
                strcat(final, $4);
                strcat(final,";\n");
                strcat(final, $6);

                char modTipo1[4 + strlen(tipo) + 2]; // 4 por ":;\n", 2 por ": y ";\n", +1 por el nulo
                char modTipo2[4 + strlen(tipo) + 2]; // 4 por ":=\n", 2 por ": y "=", +1 por el nulo

                if (strstr(final, ":;") != NULL) {
                        memset(modTipo1, 0, sizeof(modTipo1));
                        strcat(modTipo1, ":");
                        strcat(modTipo1, tipo);
                        strcat(modTipo1, ";\n");
                }

                if (strstr(final, ":=") != NULL) {
                        memset(modTipo2, 0, sizeof(modTipo2));
                        strcat(modTipo2, ":");
                        strcat(modTipo2, tipo);
                        strcat(modTipo2, "=");
                }

                char *finalMod = reemplazar(final, ":;", modTipo1);  // Primera llamada a reemplazar

                if (finalMod != NULL) {
                        finalMod = reemplazar(finalMod, ":=", modTipo2);  // Segunda llamada a reemplazar

                        if (finalMod != NULL) {
                                $$ = finalMod;
                        } else {
                                // Manejar el error si la segunda llamada a reemplazar falla
                        }
                } else {
                        // Manejar el error si la primera llamada a reemplazar falla
                }
        }
        
        /*|STRINGV operand exp COMMA vardef{//9
                char * final = malloc(strlen($1)*sizeof(char) + sizeof("; : let \n") + strlen($3)*sizeof(char)+ strlen($5)*sizeof(char) );
                memset(final, 0, sizeof(final));
                strcat(final, "let ");
                strcat(final, $1);
                strcat(final, ":=");
                strcat(final, $3);
                strcat(final,";\n");
                strcat(final, $5);
                $$ = final;
        }*/
        |STRINGV operand vardef{
                char * final = malloc(strlen($1)*sizeof(char)+strlen($2)*sizeof(char) + sizeof("; : \n") + strlen($3)* sizeof(char));
                memset(final, 0, sizeof(final));
                strcat(final, $1);
                strcat(final, $2);;
                strcat(final, $3);
                $$ = final;
        }
        |STRINGV COMMA vardef{//10
                char * final = malloc(strlen($1)*sizeof(char) + sizeof("; : \n") + strlen($3)* sizeof(char));
                memset(final, 0, sizeof(final));
                strcat(final, "");
                strcat(final, $1);
                strcat(final, ":;\n");;
                strcat(final, $3);
                $$ = final;
        }
        /*|STRINGV SEMICOLON{//11

                char * final = malloc(strlen($1)*sizeof(char) + sizeof("; : let \n") );
                memset(final, 0, sizeof(final));
                strcat(final, "let ");
                strcat(final, $1);
                strcat(final, ":;\n");;
                $$ = final;
        }*/
        |atom SEMICOLON{//11

                char * final = malloc(strlen($1)*sizeof(char) + sizeof(";  \n") );
                memset(final, 0, sizeof(final));
                
                strcat(final, $1);
                strcat(final, ";\n");;
                $$ = final;
        }
        |STRINGV EQ exp SEMICOLON{//12
                char * final = malloc(strlen($1)*sizeof(char) + sizeof("; : let \n") + strlen($3)*sizeof(char) );
                memset(final, 0, sizeof(final));
                strcat(final, "");
                strcat(final, $1);
                strcat(final, ":=");
                strcat(final, $3);
                strcat(final,";\n");
                $$ = final;
        }
        
        
        

        
;


type : 
        INTEGER {$$ = 0;}
        | SHORT {$$ = 1;}
        | LONG {$$ = 2;}
        | UNSIGNED_INT {$$ = 3;}
        | UNSIGNED_SHORT {$$ = 4;}
        | UNSIGNED_LONG {$$ = 5;}
        | FLOAT {$$ = 6;}
        | DOUBLE {$$ = 7;}
        | STRING {$$ = 8;}
        | CHAR {$$ = 9;}
        | BOOLEAN {$$ = 10;}
        | VOID {;}
        | STRUCT STRINGV {
                strcpy(tipoStruct, $2);
                $$ = 11;
        ;}
;



values : 
        TRUEVAL {
                $$ = strdup("true");
        }
        | FALSEVAL {$$ = $1;}
        | INTNUM {$$ = $1;}
        | REALNUM {$$ = $1;}
        | QUOTESTRING {$$ = $1;}
;

preprograma : 
        preprograma programa{
                char * final = malloc(strlen($1)*sizeof(char) + strlen($2)*sizeof(char));
                memset(final,0,sizeof(final));
                strcat(final, $1);
                strcat(final, $2);

                $$ = final;
        }
        |programa{
                char * final = malloc(strlen($1)*sizeof(char));
                memset(final,0,sizeof(final));

                strcat(final, $1);

                $$ = final;
        }
programa : 
        type STRINGV LPAREN args RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET{                        
                        
                        
                        char * final = malloc( strlen($4) * sizeof(char) + strlen($7) * sizeof(char)   + 20*sizeof(char) + sizeof("fn ->String {}"));
                        memset(final, 0, sizeof(final));
                        strcat(final, "fn ");
                        strcat(final, $2);
                        strcat(final, " (");
                        strcat(final,$4);
                        strcat(final,") ");
                        if($1 == 0){
                                strcat(final, "-> i32 {");
                        } else if ($1 == 1){
                                strcat(final, "-> i16 {");
                        }else if ($1 == 2){
                                strcat(final, "-> i64 {");
                        }else if ($1 == 3){
                                strcat(final, "-> u32 {");
                        }else if ($1 == 4){
                                strcat(final, "-> u16 {");
                        }else if ($1 == 5){
                                strcat(final, "-> u64 {");
                        }else if ($1 == 6){
                                strcat(final, "-> f32 {");
                        }else if ($1 == 7){
                                strcat(final, "-> f64 {");
                        }else if ($1 == 8){
                                strcat(final, "-> String {");
                        }else if ($1 == 9){
                                strcat(final, "-> char {");
                        }else if ($1 == 10){
                                strcat(final, "-> bool {");
                        }else{
                                strcat(final, "");
                        }
                        strcat(final, "{\n");
                        strcat(final, $7);
                        strcat(final, "\n");
                        strcat(final, "}\n\n");
                        free($7);
                        free($4);
                        DeleteListT (&flist);
                        
                        $$ = final;
                
        }

        |type STRINGV LPAREN RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  {
                
                        
                char * final = malloc( strlen($6) * sizeof(char)   + 20*sizeof(char) + sizeof(" -> i16")+ sizeof("fn "));
                memset(final, 0, sizeof(final));

                strcat(final, "fn () ");
                strcat(final, $2);
                switch ($1) {
                case 0:strcat(final, "-> i32 {");
                        break;
                case 1:strcat(final, "-> i16 {");
                        break;
                case 2:strcat(final, "-> i64 {");
                        break;
                case 3:strcat(final, "-> u32 {");
                        break;
                case 4:strcat(final, "-> u16 {");
                        break;
                case 5:strcat(final, "-> u64 {");
                        break;
                case 6:strcat(final, "-> f32 {");
                        break;
                case 7:strcat(final, "-> f64 {");
                        break;
                case 8:strcat(final, "-> String {");
                        break;
                case 9:strcat(final, "-> char {");
                        break;
                case 10:strcat(final, "-> bool {");
                        break;
                default:break;
                }

                strcat(final, "\n");
                strcat(final, $6);
                strcat(final, "\n}\n\n");
                
                free($6);
                DeleteListT (&flist);

                $$ = final;
                                
                
        }

        |type STRINGV LPAREN RPAREN SEMICOLON{
                $$ = "";
        }
        | vardef programa {
                char * final = malloc(strlen($1)*sizeof(char) + strlen($2)*sizeof(char) + sizeof("\n\n"));
                strcat(final,$1);
                strcat(final,"\n");
                strcat(final, $2);
                strcat(final,"\n");
                
                $$ = final;
        }
        
        |STRUCT STRINGV OPENCURLYBRACKET lines_program CLOSECURLYBRACKET SEMICOLON{
                char * final = malloc(strlen($2)*sizeof(char) + strlen($4)*sizeof(char) + strlen("struct { } \n\n"));
                memset(final, 0 , sizeof(final));
                strcat(final, "struct ");
                strcat(final, $2);
                strcat(final, " {\n");
                strcat(final, $4);
                strcat(final, "}\n");
                replaceSemicolon(final);
                $$ = final; 
        }
        | constdef programa {
                char * final = malloc(strlen($2)*sizeof(char) + strlen($1)*sizeof(char) );
                memset(final,0, strlen(final));
                strcat(final, $1);
                strcat(final, $2);
                $$ = final;}
        |comment{;}

;

args : 
	type STRINGV COMMA args {
                char * final;
                
                char *tipo;
                if (strcmp(obtenerTipo($1), "struct") == 0) {
                        tipo = tipoStruct;
                        
                        
                }else{
                        tipo = obtenerTipo($1);

                }                final = malloc(strlen(tipo)  + strlen($2) * sizeof(char) + strlen($4) * sizeof(char) + sizeof(",  ") + 3*sizeof(char));
                memset(final, 0, sizeof(final));
                strcat(final, $4);
                strcat(final, ",");
                strcat(final, " ");
                strcat(final, tipo);
                strcat(final, " ");
                strcat(final, $2);
                free($4);
                $$ = final;
                
                }
	|type STRINGV {
                char * final;
                char *tipo;
                if (strcmp(obtenerTipo($1), "struct") == 0) {
                        tipo = malloc(strlen(tipoStruct)*sizeof(char) + strlen($2) * sizeof(char) + sizeof(": &mut "));
                        strcat(tipo, $2);
                        strcat(tipo, ": &mut ");
                        strcat(tipo, tipoStruct);
                        $$ = tipo;

                }else{
                        tipo = obtenerTipo($1);
                        final = malloc(strlen(tipo) * sizeof(char) + strlen($2) * sizeof(char) );
                        memset(final, 0, sizeof(final));
                        strcat(final, tipo);
                        strcat(final, " ");
                        strcat(final, $2);
                        $$ = final;

                }                
        }
        | type PROD STRINGV COMMA args{
                char * final;
                
                char *tipo;
                if (strcmp(obtenerTipo($1), "struct") == 0) {
                        tipo = tipoStruct;
                        
                }else{
                        tipo = obtenerTipo($1);

                }                final = malloc(strlen(tipo)  + strlen($3) * sizeof(char) + strlen($5) * sizeof(char) + sizeof(",  ") + 3*sizeof(char));
                memset(final, 0, sizeof(final));
                strcat(final, $5);
                strcat(final, ",");
                strcat(final, " ");
                strcat(final, tipo);
                strcat(final, " ");
                strcat(final, $3);
                free($5);
                $$ = final;
        }
        |type PROD STRINGV {
                
                char * final;
                char *tipo;
                if (strcmp(obtenerTipo($1), "struct") == 0) {
                        tipo = malloc(strlen(tipoStruct)*sizeof(char) + strlen($3) * sizeof(char) + sizeof(": &mut "));
                        strcat(tipo, $3);
                        strcat(tipo, ": &mut ");
                        strcat(tipo, tipoStruct);
                        $$ = tipo;

                }else{
                        tipo = obtenerTipo($1);
                        final = malloc(strlen(tipo) * sizeof(char) + strlen($3) * sizeof(char) );
                        memset(final, 0, sizeof(final));
                        strcat(final, tipo);
                        strcat(final, " ");
                        strcat(final, $3);
                        $$ = final;

                } 
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
        | PRINTF LPAREN precontentWrite RPAREN SEMICOLON {
                char * final = malloc(strlen($3)*sizeof(char)+ sizeof("print!"));
                memset(final, 0, sizeof(final));
                strcat(final, "print!");
                strcat(final, $3);
                $$ = final;
        }
        | SCANF LPAREN precontentWrite RPAREN SEMICOLON{
                char * final = malloc(strlen($3)*sizeof(char)+ sizeof("let mut input = String::new();\nio::stdin()\n.read_line(&mut input)\n.expect(\"Failed to read line\");"));
                memset(final, 0, sizeof(final));
                strcpy(final, "let mut input = String::new();\nio::stdin()\n.read_line(&mut input)\n.expect(\"Failed to read line\");");
                inputCount = inputCount + 1;
                $$ = final;
        }
        
        |STRINGV LPAREN array RPAREN SEMICOLON{
                char * final = malloc(strlen($1)* sizeof(char) + strlen($3)*sizeof(char) + sizeof("quiere();") + 1);
                memset(final,0, sizeof(final));
                strcat(final, $1);
                strcat(final, "(");
                strcat(final,$3);
                strcat(final,");");
                $$ = final;

        }
        |STRINGV LPAREN RPAREN SEMICOLON{
                char * final = malloc(strlen($1)* sizeof(char) +  sizeof("();") + 1);
                memset(final,0, sizeof(final));
                strcat(final, $1);
                strcat(final, "(");
                strcat(final,");");
                $$ = final;

        }
        
        | IF LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  {
                char * final = malloc(strlen($3)* sizeof(char) + strlen($6)*sizeof(char) + sizeof("if ( ) { } \t \n \n"));
                memset(final, 0, sizeof(final));
                strcat(final, "if (");
                strcat(final, $3);
                strcat(final, "){\n");
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
                                sizeof("for ; ; {}")+strlen($4)*sizeof(char)+ strlen($6)*sizeof(char) + strlen($9)*sizeof(char) + 
                                strlen($10)*sizeof(char) + strlen($14)*sizeof(char));
                memset(final,0, strlen(final));

                char * numero = getEndNumber($8);
                char* octavo;
                if(!strcmp(numero,"")){
                        octavo =  getStringFromExp($8);
                }
                
                strcat(final, "for ");
                strcat(final, $4);
                strcat(final, " in ");
                strcat(final, $6);
                strcat(final, "..");
                strcat(final, octavo);
                strcat(final, "{\n");
                strcat(final, $14);
                strcat(final, "\n}");
                $$=final;
                ;}
        //for ( int i = 8 ; i<20 ; i = i + 1) { lines}
        | FOR LPAREN type STRINGV EQ INTNUM SEMICOLON exp SEMICOLON vardef  RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET {
                char * final = malloc ($3*sizeof(int) + strlen($4)*sizeof(char) + strlen($6)*sizeof(char) + strlen($8)*sizeof(char)  +
                                        strlen($10)*sizeof(char) + strlen($13)*sizeof(char)+ sizeof("for ; ; {} .step_by( )"));
                memset(final,0, strlen(final));
                char * numero = getEndNumber($8);
                char * numero2 = getEndNumber($10);
                
                strcat(final, "for ");
                strcat(final, $4);
                strcat(final, " in ");
                strcat(final, $6);
                strcat(final, "..");
                strcat(final, numero);
                strcat(final, ".step_by(");
                strcat(final, numero2);
                strcat(final, ")");
                strcat(final, "{\n");
                strcat(final, $13);
                strcat(final, "\n}");
                $$=final;
        
        
        }
        | DO OPENCURLYBRACKET lines_program CLOSECURLYBRACKET WHILE LPAREN exp RPAREN SEMICOLON{
                char * final = malloc( strlen($3)*sizeof(char) + strlen($7)*sizeof(char) + sizeof("loop {} if() == {} break; \n") );
                memset(final, 0 , sizeof(final));

                strcat(final, "loop{\n");
                strcat(final, $3);
                strcat(final, "if(");
                strcat(final, $7);
                strcat(final, "){\n");
                strcat(final, "break;\n");
                strcat(final, "}\n}");

                $$ = final;
        
        }
        | WHILE LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET{
                char * final = malloc(strlen($3)*sizeof(char) + strlen($6)*sizeof(char) + sizeof("while () {} \n\n"));
                memset(final, 0, sizeof(final));

                strcat(final, "while(");
                strcat(final, $3);
                strcat(final, "){\n");
                strcat(final, $6);
                strcat(final, "\n}");
                $$ = final;
                
        }
        
        | comment{;}
        | STRINGV operand SEMICOLON{
                char * final = malloc (strlen($2)*sizeof(char) + strlen($1)*sizeof(char));
                memset(final, 0, sizeof(final));
                strcat(final, $1);
                strcat(final, $2);
                strcat(final, ";");

                $$ = final;
        }
        | RETURN exp SEMICOLON {
                char * final = malloc(strlen($2)*sizeof(char) );
                memset(final, 0 , sizeof(final));
                
                strcat(final, $2);
                $$=final;
                
        }
        | RETURN SEMICOLON {
                char * final = malloc(sizeof("return;"));
                memset(final, 0 , sizeof(final));
                strcat(final, "return;");
                $$ = final;
                
        }
        | vardef{
                char * final = malloc(strlen($1)*sizeof(char)  + sizeof("\n"));
                memset(final,0,sizeof(final));
                strcat(final,$1);
                strcat(final,"\n");

                
                $$ = final;
                
        }
        /*| term  {
                printf("\n\nAQUI\n\n");
                char * final = malloc(strlen($1)*sizeof(char)  + sizeof("\n;"));
                memset(final,0,sizeof(final));
                strcat(final,$1);
                strcat(final,";\n");

                
                $$ = final;
        }*/
        |STRUCT STRINGV OPENCURLYBRACKET lines_program CLOSECURLYBRACKET SEMICOLON{
                char * final = malloc(strlen($2)*sizeof(char) + strlen($4)*sizeof(char) + strlen("struct { } \n\n"));
                memset(final, 0 , sizeof(final));
                strcat(final, "struct ");
                strcat(final, $2);
                strcat(final, " {\n");
                strcat(final, $4);
                strcat(final, "}\n");
                replaceSemicolon(final);

                $$ = final; 
        }
        

;

array :
       
        exp COMMA array{
                char * final = malloc(strlen($1)*sizeof(char) + strlen($3)*sizeof(char)) ;
                memset(final,0,sizeof(final));

                strcat(final,$1);
                strcat(final,",");
                strcat(final,$3);
                $$ = final;
        }
        |exp{
                $$ = $1;
        }
        

precontentWrite :
        contentWrite{
                if(strlen(printV) ==0){
                        char * final = malloc(strlen($1)*sizeof(char) + strlen(printV)*sizeof(char)+strlen("();") * sizeof(char) );
                        memset(final, 0, sizeof(final));
                        strcat(final, "(");
                        strcat(final,$1);
                        strcat(final, ");");
                        $$ = final;
                }else{
                        int longitud = strlen(printV);
                        char * final = malloc(strlen($1)*sizeof(char) + strlen("{},,,")*sizeof(char) + longitud*sizeof(char)+strlen("(\"") * sizeof(char)+ strlen("\");")*sizeof(char));
                        memset(final, 0, sizeof(final));
                        
                        int contador = 0;
                         // Obtenemos la longitud de la cadena original
                        char* nueva_cadena =malloc(sizeof(char) * (longitud)); // Reservamos memoria para la nueva cadena
                        memset(nueva_cadena, 0, sizeof(nueva_cadena));


                        for (int i = longitud - 1; i >= 0; i--) {
                                if (printV[i] == ',') {
                                        // Reemplazar la última coma por el carácter nulo
                                        printV[i] = '\0';
                                        break;
                                }
                        }
                        strcpy(nueva_cadena, printV);
                        nueva_cadena[longitud*2-1] = '\0'; // Agregamos el terminador nulo al final de la nueva cadena

                        
                        for (int i = 0; $1[i] != '\0'; i++) {
                                if ($1[i] == '}') {
                                        contador++;
                                }
                        }
                        strcat(final, "(");
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
                        free(nueva_cadena);
                        $$ = final;
                }



        }
        /*|contentWrite LOWER LOWER ENDL{
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
                        for (int i = longitud - 1; i >= 0; i--) {
                                if (printV[i] == ',') {
                                        // Reemplazar la última coma por el carácter nulo
                                        printV[i] = '\0';
                                        break;
                                }
                        }
                        strcpy(nueva_cadena, printV);

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
                        free(nueva_cadena);

                        $$ = final;
                }
        }*/
        
;

contentWrite : 
        /*contentWrite COMMA QUOTESTRING{
                char * final = malloc(strlen($1) * sizeof(char) + strlen($3) * sizeof(char) + strlen("{}") * sizeof(char)+strlen("println!(\"")); 
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
        }*/
        contentWrite COMMA exp{
                printf("aqui");
                char * final = malloc(strlen($1) * sizeof(char) + strlen($3) * sizeof(char) + strlen("{}") * sizeof(char)); 
                memset(final, 0, sizeof(final));

                strcat(printV,$3);
                strcat(printV,",");

                
                strcat(final, $1);
                deleteQuotes(final);
                $$ = final;
        }
        
        | QUOTESTRING {

                $$ = $1;}
        | STRINGV {
                $$ = $1;}
;



exp :   exp operand term {
                
                char * final = malloc(strlen($1) * sizeof(char) +strlen($2) * sizeof(char) + strlen($3) * sizeof(char) + 1);
                memset(final, 0, sizeof(final));
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
        atom {

                $$ = $1;}
        | LPAREN exp RPAREN {
                char * final = malloc(strlen($2) * sizeof(char) + sizeof("()") + 1);
                memset(final, 0, sizeof(final));
                strcpy(final, "(");
                strcat(final, $2);
                strcat(final, ")");
                free($2);
                $$ = final;
                }
        /*| HYPHEN atom {
                char * final = malloc(strlen($2) * sizeof(char) + sizeof("-()") + 1);
                memset(final, 0, sizeof(final));
                strcpy(final, "-(");
                strcat(final, $2);
                strcat(final, ")");
                free($2);
                $$ = final;
                }*/
        | EX exp {
                char * final = malloc(strlen($2) * sizeof(char) + sizeof("!()") + 1);
                memset(final, 0, sizeof(final));
                strcpy(final, "!(");
                strcat(final, $2);
                strcat(final, ")");
                free($2);
                $$ = final;
                }
        /*| term operand term SEMICOLON{
                char * final = malloc(strlen($1) * sizeof(char) + strlen($3) * sizeof(char) + strlen($2) * sizeof(char));
                memset(final, 0 , sizeof(final));
                strcat(final, $1);
                strcat(final, $2);
                strcat(final, $3);
                $$ = final;
        }*/
;

operand : 
        PLUS {
                $$ = strdup(" + ");
        }
	|PLUS EQ {$$ = strdup(" += ");}
        |HYPHEN {$$ = strdup(" - ");}
	|HYPHEN EQ {$$ = strdup(" -= ");}
        |HYPHEN HIGHER{$$ = strdup(".");}
        |PROD {$$ = strdup(" * ");}
        |DIV {$$ = strdup(" / ");}
        |DIVINT {$$ = strdup(" / ");}
        |MOD {$$ = strdup(" % ");}
        |LOWER {$$ = strdup(" < ");}
        |HIGHER {$$ = strdup(" > ");}
        |LOWER EQ {$$ = strdup(" <= ");}
        |HIGHER EQ {$$ = strdup(" >= ");}
        |EQ EQ {$$ = strdup(" == ");}
        |AND {$$ = strdup(" && ");}
        |PLUS PLUS {$$ = strdup(" ++ ");}
        |OR{$$ = strdup(" || ");}
        |DOT {$$ = strdup(".");}
;

atom :

        STRINGV {

            $$ = $1;
		}
        | values {

                        
			$$ = $1;
		}
        |STRINGV LSQUAREPAREN atom RSQUAREPAREN{

                char * final = malloc(strlen($1)* sizeof(char) + strlen($3)*sizeof(char) + sizeof("[]"));
                memset(final, 0 , sizeof(final));
                strcat(final, $1);
                strcat(final, "[");
                strcat(final, $3);
                strcat(final, "]");
                $$ = final;
        }
;

%%

char * obtenerTipo(int valor) {
    char * tipo;
    switch (valor) {
        case 0: tipo = "i32 "; break;
        case 1: tipo = "i16 "; break;
        case 2: tipo = "i64 "; break;
        case 3: tipo = "u32 "; break;
        case 4: tipo = "u16 "; break;
        case 5: tipo = "u64 "; break;
        case 6: tipo = "f32 "; break;
        case 7: tipo = "f64 "; break;
        case 8: tipo = "String "; break;
        case 9: tipo = "char "; break;
        case 10: tipo = "bool "; break;
        case 11: tipo = "struct" ; break;
        default: tipo = ""; break;
    }
    return tipo;
}

char* getEndNumber(char* number){
                int len = strlen(number);
                char* numero = (char*) malloc(len + 1); // Reservar espacio para el nuevo número (+1 por el '\0')
                char* newNumero = (char*) malloc(2); // Reservar espacio para el dígito y el '\0'
                numero[0] = '\0'; // Inicializar la cadena vacía
                for (int i = len - 1; i >= 0; i--) {
                        if (!isdigit(number[i])) {
                                break;
                                
                        } else {
                                newNumero[0] = number[i];
                                newNumero[1] = '\0'; // Agregar el '\0' para que sea una cadena válida
                                char* temp = strdup(numero); // Crear una copia temporal de la cadena
                                strcpy(numero, newNumero); // Copiar el dígito al principio de la cadena
                                strcat(numero, temp); // Concatenar el resto de la cadena al final
                                free(temp); // Liberar la memoria de la cadena temporal
                        }
                }
                free(newNumero); // Liberar la memoria del dígito
                return numero;
}


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

char *reemplazar(const char *cadena, const char *busqueda, const char *reemplazo) {
    if (cadena == NULL || busqueda == NULL || reemplazo == NULL) {
        return NULL;
    }

    int longitudBusqueda = strlen(busqueda);
    int longitudReemplazo = strlen(reemplazo);
    const char *posicion;
    const char *inicio = cadena;
    int nuevaLongitud = 0;

    // Calcular la longitud del nuevo string
    while ((posicion = strstr(inicio, busqueda)) != NULL) {
        nuevaLongitud += posicion - inicio + longitudReemplazo;
        inicio = posicion + longitudBusqueda;
    }
    nuevaLongitud += strlen(inicio); // Agregar el resto de la cadena

    // Asignar memoria para el nuevo string
    char *nuevoString = (char *)malloc(nuevaLongitud + 1);

    if (nuevoString == NULL) {
        return NULL; // Error en la asignación de memoria
    }

    char *destino = nuevoString;
    inicio = cadena;

    // Construir el nuevo string
    while ((posicion = strstr(inicio, busqueda)) != NULL) {
        int longitudSegmento = posicion - inicio;
        strncpy(destino, inicio, longitudSegmento);
        destino += longitudSegmento;
        strcpy(destino, reemplazo);
        destino += longitudReemplazo;
        inicio = posicion + longitudBusqueda;
    }

    strcpy(destino, inicio); // Copiar el resto de la cadena

    return nuevoString;
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


void saveGType(char *tipo) {
    strncpy(gType, tipo, sizeof(gType) - 1); // Copiar tipo en gType
    gType[sizeof(gType) - 1] = '\0'; // Asegurarse de que gType esté terminado en null
}

char *getGType() {
    return gType;
}


void replaceSemicolon(char *string) {
    if (string == NULL) {
        return; // Verificar si la cadena es nula
    }

    int length = strlen(string);

    for (int i = 0; i < length; i++) {
        if (string[i] == ';' && string[i + 1] == '\n') {
            string[i] = ','; // Reemplazar el punto y coma por una coma
        }
    }
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
                        case 0: strcat(temp, "i32 ");break;
                        case 1: strcat(temp, "i16 ");break;
                        case 2: strcat(temp, "i64 ");break;
                        case 3: strcat(temp, "u32 ");break;
                        case 4: strcat(temp, "u16 ");break;
                        case 5: strcat(temp, "u64 ");break;
                        case 6: strcat(temp, "f32 ");break;
                        case 7: strcat(temp, "f64 ");break;
                        case 8: strcat(temp, "String ");break;
                        case 9: strcat(temp, "char ");break;
                        case 10: strcat(temp, "bool ");break;
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
void yyerror(const char *msg) {
        fprintf(stderr, "Error: %s\n", msg);
        fprintf(stderr, "Error at line %d: %s\n", yylineno, msg);
        fprintf(stderr, "Syntax error: %s. Expected token: %d\n", msg, yychar);
        fprintf(stderr, "   %s\n", yytext); // Imprime el token que causó el error
}



int searchString(char **arr, char *toFind, int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i], toFind) == 0) {
            return 1; // Se encontró la cadena
        }
    }
    return 0; // No se encontró la cadena
}

char *insertTabsBetweenBraces( char *input) {
    if (input == NULL) {
        return NULL;
    }

    int input_length = strlen(input);
    int countCurly = 0;
    int count = 0;

    // Calcula una estimación inicial de la longitud de salida
    int max_output_length = input_length * 2;
    char *output = (char *)malloc((max_output_length + 1) * sizeof(char));

    if (output == NULL) {
        return NULL; // Comprueba si malloc falla
    }

    for (int i = 0; i < input_length; i++) {
        if (input[i] == '{') {
            countCurly++;
        } else if (input[i] == '}') {
            countCurly--;
        }

        if (input[i] != '\\' && input[i] != '\n') {
            output[count++] = input[i];

        }  else if (input[i] == '\n' && input[i + 1] == '}') {
            output[count++] = input[i];
            // Inserta tabulaciones según countCurly
            for (int j = 0; j < countCurly-1; j++) {
                output[count++] = '\t';
            }
        } else if (input[i] == '\n') {
            output[count++] = input[i];
            // Inserta tabulaciones según countCurly
            for (int j = 0; j < countCurly; j++) {
                output[count++] = '\t';
            }
        } else {
            // Copia el carácter de escape y el siguiente carácter
            output[count++] = input[i];
            output[count++] = input[i + 1];
            i++; // Salta el siguiente carácter
        }
    }

    output[count] = '\0'; // Agrega el carácter nulo al final

    return output;
}

char* getStringFromExp(char* str) {
    int len = strlen(str);
    char* subcadena = NULL;
    char* delimitadores[4] = {"<", ">", ">=", "<="};
    int i, j, k, pos;
    for (i = 0; i < 4; i++) {
        char* ptr = strstr(str, delimitadores[i]);
        if (ptr != NULL) {
            pos = ptr - str + strlen(delimitadores[i]);
            subcadena = (char*)malloc(len - pos + 1);
            if (subcadena == NULL) {
                printf("Error de asignación de memoria\n");
                exit(1);
            }
            for (j = pos, k = 0; j < len; j++, k++) {
                subcadena[k] = str[j];
            }
            subcadena[k] = '\0';
            break;
        }
    }
    return subcadena;
}

int main(int argc, char *argv[]) {
       
        printf("Número de argumentos (argc): %d\n", argc);

        printf("Argumentos (argv):\n");
        for (int i = 0; i < argc; ++i) {
                printf("argv[%d] = %s\n", i, argv[i]);
        }
        char ruta[100] = "entrada/";
        char *archivo_c = argv[1];

        strcat(ruta, archivo_c);
        
        
        InitializeListT(&typelist);
        InitializeListN(&queue);
	//pthread_mutex_lock(&file_mutex);
	switch (argc) {
		case 1:	printf("Syntax : ./traductorP <archivoC> [-s size_string]\n");
			exit(-1);
                        break;
		case 2: int i = 0;
                        arraySize++;
                        YY_BUFFER_STATE bufferState = NULL;
                        arrayCabeceras = (char**)realloc(arrayCabeceras, arraySize * sizeof(char*));
                        arrayCabeceras[arraySize - 1] = (char*)malloc(strlen(ruta) * sizeof(char));
                        strcpy(arrayCabeceras[arraySize - 1], ruta);
                        strcpy(filePath, ruta);
                        
                        #pragma omp parallel shared(arrayCabeceras, arraySize, yyin, filePath) private(i)
                        {
                                #pragma omp for
                                for (i = 0; i < arraySize; i++) {
                                        printf("\n-------%i--------\n", arraySize);
                                        #pragma omp critical
                                        {/*     extern void yy_flush_buffer( YY_BUFFER_STATE buffer );
                                                extern void yy_switch_to_buffer( YY_BUFFER_STATE new_buffer );
                                                extern YY_BUFFER_STATE yy_create_buffer( FILE *file, int size );
                                                extern YY_BUFFER_STATE yy_current_buffer();*/
                                                bufferState = yy_current_buffer();
                                                yy_flush_buffer(bufferState);
                                                yyin = fopen(arrayCabeceras[i], "r");
                                                bufferState = yy_create_buffer(yyin, 1024);
                                                yy_switch_to_buffer(bufferState);
                                        }
                                        // Ejecutar la función que trabaja con el array
                                        if (yyin == NULL) {
                                                printf("ERROR: No se ha podido abrir el fichero.\n");
                                        } else {
                                                #pragma omp critical
                                                {
                                                strcpy(filePath, arrayCabeceras[i]);
                                                }
                                                yyparse();
                                                #pragma omp critical
                                                {
                                                fclose(yyin);
                                                }
                                        }

                                        // Hacer algo después de la función
                                        #pragma omp critical
                                        {
                                                printf("Thread %d realizando manipulaciones posteriores.\n", omp_get_thread_num());
                                        }
                                }
                        }

                                



                        printf("array size final %i", arraySize);
                        
                        
                        
                
                        break;
                
                
                case 4 : if((strcmp(argv[2], "-s") != 0) || (isNumber(argv[3])==0)) {
                                printf("Syntax : ./traductorP <archivoC> [-s size_string]\n");
			        exit(-1);
                        }
                        else {
                                strcpy(sizeS, argv[3]);
                                yyin = fopen(ruta, "r");
			        if (yyin == NULL) {
				        printf("ERROR: No se ha podido abrir el fichero.\n");
			        }
			        else {
				        yyparse();
				        fclose(yyin);
			        }
                        }
                        break;
		default: printf("ERROR: Demasiados argumentos.\nSyntax : ./traductorP <archivoC> [-s size_string]\n\n");
	}
        //pthread_mutex_unlock(&file_mutex);
        //ShowListT(&typelist);
        
	return 0;
}
/*#pragma omp parallel private(yyin) shared(z)
                {
                        int tid = omp_get_thread_num();

                        // Definir las variables threadprivate
                        #pragma omp threadprivate(yyin, filepath)


                        #pragma omp sections
                        {
                                #pragma omp section
                                {
                                        printf("hola esta es la cuarta section\n");
                                        strcpy(filePath, "entrada/archivo4.c");
                                        yyin = fopen(filePath, "r");
                                        if (yyin == NULL) {
                                                printf("ERROR: No se ha podido abrir el fichero.\n");
                                        }
                                        else {
                                                yyparse();
                                                fclose(yyin);
                                        }    
                                        
                                }

                                #pragma omp section
                                {
                                        printf("hola esta es la segunda section\n");
                                        strcpy(filePath, "entrada/archivo1.c");
                                        yyin = fopen(filePath, "r");
                                        if (yyin == NULL) {
                                                printf("ERROR: No se ha podido abrir el fichero.\n");
                                        }
                                        else {
                                                yyparse();
                                                fclose(yyin);
                                        }
                                        
                                }
                        }
                        {
                                #pragma omp section
                                {
                                        printf("hola esta es la primera section\n");
                                        strcpy(filePath, "entrada/archivo2.c");
                                        yyin = fopen(filePath, "r");
                                        if (yyin == NULL) {
                                                printf("ERROR: No se ha podido abrir el fichero.\n");
                                        }
                                        else { 
                                                yyparse();
                                                fclose(yyin);
                                        }
                                        
                                }

                                #pragma omp section
                                {
                                        printf("hola esta es la segunda section\n");
                                        strcpy(filePath, "entrada/archivo3.c");
                                        yyin = fopen(filePath, "r");
                                        if (yyin == NULL) {
                                                printf("ERROR: No se ha podido abrir el fichero.\n");
                                        }
                                        else {
                                                yyparse();
                                                fclose(yyin);
                                        }
                                        
                                }
                        }
                }*/