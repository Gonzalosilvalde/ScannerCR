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
extern void yy_delete_buffer ( YY_BUFFER_STATE b  );
extern void yypush_buffer_state ( YY_BUFFER_STATE new_buffer  );
extern void yypop_buffer_state ( void );
extern FILE *yyin;
void yyerror(char const *);

int arraySize = 0;

char filePath[100] ;
char sizeS[8] = "200";
char tipoStruct[50] = "";
char **arrayCabeceras = NULL;
char gType[10] = "";
char printV[100]= "";

TypeList typelist;
TypeList flist;

NodeList queue;

char * insertTabsBetweenBraces(char *code);
char * getType(int valor);
void replaceSemicolon(char *string);
void deleteQuotes (char *);
char * replace(const char *cadena, const char *busqueda, const char *reemplazo);
char * getEndNumber(char* number);
int searchString(char **arr, char *toFind, int size);
char * getStringFromExp(char* str);
void ifCreation(char* final, char* in, char* out);
void funCreation(char* final, char* name, char* in);
void typeSwitch(char*final, int type);
char * resolveType(int parametro);
void concatenateArray(char *final, char *strings[], int n);


//macros


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
%token SWITCH 
%token CASE
%token DEFAULT
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
%token PERCENT
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
%token LONG_LONG
%token UNSIGNED_INT
%token UNSIGNED_SHORT
%token UNSIGNED_LONG
%token UNSIGNED_LONG_LONG
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
%left <valString>PLUS HYPHEN PERCENT
%left DIV
%left DIVINT MOD
%left AND OR
%left PROD
%right EX
%left LPAREN RPAREN
%left STRINGV 
%left DOT
%left IF
%left SWITCH
%right COMMENTLINE
%right MULTILINE
%left INTEGER
%right ELSE


%type <valString> vardef constdef args if_statement fun_cre 
%type <valString> preprograma case_chain 

%type <valString>  values array prod
%type <valInt> type types
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
                // printf("filepath: %s\n", filePath );
                
                strcpy(entrada, filePath);
                // printf("entrada: %s\n", entrada );
                char salida[100]; // Puedes ajustar el tamaño del buffer según tus necesidades

                char* lastSlash = strrchr(entrada, '/');
                printf("%s\n", lastSlash );


                // Si lastSlash no es NULL, significa que se ha encontrado el caracter '/'
                if (lastSlash) {
                        // Calcular la longitud de la subcadena a partir del último '/'
                        size_t length = strlen(lastSlash + 1);
                        
                        // Copiar la subcadena a 'salida' y sustituir la extensión
                        strcpy(salida, "salida"); // Copiar "salida/" a la cadena 'salida'
                        strncat(salida, lastSlash, length - 1); // Agregar la subcadena 'hola' sin la extensión
                        strcat(salida, ".rs"); // Agregar la extensión ".rs" al final

                        // printf("sal   %s\n", salida); // Imprimir el resultado
                } else {
                        printf("No se ha encontrado '/' en la cadena de entrada.\n");
                }

                free(entrada);
                // printf("%s", salida);
                FILE *fp = fopen(salida, "w");

                if (fp != NULL) {
		    	char *resultado = insertTabsBetweenBraces($2);
    			if (resultado != NULL) {
        			fputs(resultado, fp);
        			free(resultado); // Libera la memoria asignada por insertTabsBetweenBraces
        			fclose(fp);
    			}
		}

                free($2);
                
        }
        


;

comment :
         COMMENTLINE {
                $$ = $1;
                }
        | MULTILINE {;}

        
;

cabecera : 	PROGRAM LOWER STRINGV HIGHER {
	 		free($3);
			$$ = "";

		}
        |PROGRAM LOWER STRINGV DOT STRINGV HIGHER {
			
			free($3);
			free($5);
			$$ = "";
		}
		|PROGRAM QUOTESTRING {
            #pragma omp critical
			{       
                char final[100] = "";
                char fichero[50] = "";

   	 			strcat(fichero, $2);
                free($2);
    				deleteQuotes(fichero);

    				// Asegurarse de que no se elimina más caracteres de los necesarios
    				if (strlen(fichero) > 2) {
        				fichero[strlen(fichero) - 2] = '\0';
    				}

    				char ruta[100] = "entrada/";

    				strcat(final, fichero);
    				strcat(final, ".c");
    				// printf("-----------------%s------------------ \n", final);

    				strcat(ruta, final);
    				if (searchString(arrayCabeceras, ruta, arraySize) == 0) {
        				arraySize++;
        				arrayCabeceras = (char**)realloc(arrayCabeceras, arraySize * sizeof(char*));
        
        				// Asignar espacio suficiente para ruta con terminador nulo
        				arrayCabeceras[arraySize - 1] = (char*)malloc((strlen(ruta) + 1) * sizeof(char)); 
        				if (arrayCabeceras[arraySize - 1] == NULL) {
            					printf("Error al asignar memoria para arrayCabeceras[%d]\n", arraySize - 1);
            					exit(1);
        				}

        				strcpy(arrayCabeceras[arraySize - 1], ruta);

        				// printf("array size %i\n\n", arraySize);
        				// printf("array cabeceras %s\n\n", arrayCabeceras[arraySize - 1]);
        				// printf("ruta  %s\n\n", ruta);
    				}
			}
		}
        |PROGRAM LOWER STRINGV HIGHER cabecera {
			free($3);	
			$$ = "";
		}
        |PROGRAM LOWER STRINGV DOT STRINGV HIGHER cabecera{
			free($3);
			free($5);
			$$ = "";
		}
		|PROGRAM QUOTESTRING cabecera{
                                                
			#pragma omp critical
			{       
				char final[100] = "";
				char fichero[50] = "";
				strcat(fichero, $2);
				free($2);
				deleteQuotes(fichero);
				fichero[strlen(fichero) - 2] = '\0';

				char ruta[100] = "entrada/";

				strcat(final, fichero);
				strcat(final, ".c");
				// printf("-----------------%s------------------ \n", final);
				strcat(ruta, final);

				if (searchString(arrayCabeceras, ruta, arraySize) == 0) {
					arraySize++;
					arrayCabeceras = (char**)realloc(arrayCabeceras, arraySize * sizeof(char*));

					// Cambiado para incluir el espacio del terminador nulo
					arrayCabeceras[arraySize - 1] = (char*)malloc((strlen(ruta) + 1) * sizeof(char)); 

					strcpy(arrayCabeceras[arraySize - 1], ruta);
					// printf("array size %i\n\n", arraySize);
					// printf("array cabeceras %s\n\n", arrayCabeceras[arraySize - 1]);
					// printf("ruta  %s\n\n", ruta);
				}
			}

                }
;

constdef : 
	DEFINE STRINGV values {
		// Calcular el tamaño total necesario para `final`
		size_t size_final = strlen($2) + strlen($3) + 6 + 10 + 2 + 1; // +1 para el terminador nulo
		char *final = malloc(size_final * sizeof(char));

		// Inicializar toda la memoria asignada con ceros
		memset(final, 0, size_final * sizeof(char));
        char* parts[] = {"const ", $2, ": usize = ", $3, ";\n"};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);
		free($3);
		free($2);
		$$ = final;
	}


        |CONST types STRINGV EQ values SEMICOLON {
                
		free($3);
		free($5);
	}
;




vardef : 
        types STRINGV SEMICOLON {
            char *tipo;
            tipo = resolveType($1);
            // Asigna espacio suficiente para `final` y el terminador nulo
            char *final = malloc(strlen(tipo) + strlen($2) + strlen("let\n: ;") + 1);

            // Inicializa la memoria asignada
            memset(final, 0, strlen(tipo) + strlen($2) + strlen("let\n: ;") + 1);

            // Concatenación de strings
            char* parts[] = {"let ", $2, ":", tipo, ";\n"};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            free($2);
            $$ = final;
        }

        |types STRINGV LSQUAREPAREN atom RSQUAREPAREN SEMICOLON {
            char *tipo;
            tipo = resolveType($1);

            char * final = malloc(strlen(tipo)* sizeof(char) +strlen($2)* sizeof(char) + strlen($4)*sizeof(char) + sizeof("[]; : ;\n"));
            memset(final, 0 , sizeof(final));
            char* parts[] = {$2, ": [", tipo, ";", $4, "];\n"};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            free($2);
            free($4);
            $$ = final;
        }
	

        | types STRINGV EQ exp SEMICOLON {//2
            char *tipo;
            tipo = resolveType($1);


            // Calcular el tamaño correctamente para `final` e incluir el terminador nulo
            char *final = malloc(strlen(tipo) + strlen($4) + strlen($2) + strlen("=let\n: ;") + 1);

            // Inicializar `final` correctamente
            final[0] = '\0';
            char* parts[] = {"let ", $2, ":", tipo, "=", $4, ";\n"};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            // Liberar la memoria de las variables temporales
            free($2);
            //free($4);
            
            $$ = final;
        }
           
        | types STRINGV LSQUAREPAREN atom RSQUAREPAREN EQ OPENCURLYBRACKET array CLOSECURLYBRACKET SEMICOLON{//4
            char *tipo;
            tipo = resolveType($1);


            // Calcular correctamente el tamaño de `malloc` y asegurar espacio para el terminador nulo
            char *final = malloc(strlen($2) + strlen(tipo) + strlen($4) + strlen($8) + strlen("let ::[] [] ; \n") + 1);

            // Inicializar `final`
            final[0] = '\0';
            char* parts[] = {"let ", $2, ": [", tipo, ":", $4, "] = [", $8, "];\n"};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            
            // Liberar la memoria de las variables temporales
            free($2);
            free($4);
            free($8);
            $$ = final;
        }
        | types STRINGV LSQUAREPAREN RSQUAREPAREN EQ exp SEMICOLON{//4
            char *tipo;
            tipo = resolveType($1);

                
            char * final = malloc(strlen($2)*sizeof(char) + strlen(tipo)*sizeof(char) + strlen($6)*sizeof(char) + sizeof("let ::[] [] ; \n"));
            memset(final,0,sizeof(final));
            char* parts[] = {"let ", $2, "=", $6, ";"};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            free($2);
            free($6);
            $$ = final;
        }
               
        | types STRINGV COMMA vardef {  //7
            char *tipo;
            tipo = resolveType($1);
                
            strcpy(gType, tipo);

            // Reserva memoria suficiente para la cadena final
            size_t longitud_final = strlen($2) + strlen($4) + strlen(tipo) + strlen("let :;\n") + 1;
            char *final = malloc(longitud_final * sizeof(char));
            
            final[0] = '\0';  // Inicializa final con el terminador nulo
            char* parts[] = {"let ", $2, ":;\n", $4};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            free($2);
            free($4);

            char modTipo1[4 + strlen(tipo) + 3]; // Buffer para reemplazo de ":;\n" (3 caracteres adicionales para '\0')
            char modTipo2[4 + strlen(tipo) + 2]; // Buffer para reemplazo de ":=" (2 caracteres adicionales para '\0')

            // Inicializa modTipo1 y modTipo2 antes de concatenar en ellos
            modTipo1[0] = '\0';
            modTipo2[0] = '\0';

            if (strstr(final, ":;") != NULL) {
                char* partsMT1[] = {":", tipo, ";\n"};
                int nMT1 = sizeof(partsMT1)/sizeof(partsMT1[0]);
                concatenateArray(modTipo1, partsMT1, nMT1);
            }

            if (strstr(final, ":=") != NULL) {
                char* partsMT2[] = {":", tipo, "="};
                int nMT2 = sizeof(partsMT2)/sizeof(partsMT2[0]);
                concatenateArray(modTipo2, partsMT2, nMT2);
            }

            // Primera llamada a replace
            char *finalMod = replace(final, ":;", modTipo1);

            if (finalMod != NULL) {
                char *temp = replace(finalMod, ":=", modTipo2);  // Segunda llamada a replace
                free(finalMod);  // Liberar la memoria asignada por la primera llamada

                if (temp != NULL) {
                        $$ = temp;
                } else {
                        $$ = final;  // Usar el resultado de la primera llamada si la segunda falla
                }
            } else {
                // Manejar el error si la primera llamada a replace falla
                $$ = final;  // Devolver la cadena original si falla
            }
        }
        | types STRINGV EQ exp COMMA vardef{//8
            char *tipo;
            tipo = resolveType($1);

            // Asignación y verificación de memoria para 'final'
            size_t size_final = strlen("let ") + strlen($2) + strlen(":=") + strlen($4) + strlen(";\n") + strlen($6) + 1;
            char *final = malloc(size_final);

            if (final) {
                final[0] = '\0';  // Inicializa el string como vacío
                char* parts[] = {"let ", $2, ":=", $4, ";\n", $6};
                int n = sizeof(parts)/sizeof(parts[0]);
                concatenateArray(final, parts, n);
            }

            // Liberar las variables temporales
            free($2);
            free($4);
            free($6);

            // Inicializar y construir `modTipo1` y `modTipo2` sin asignación dinámica
            char modTipo1[4 + strlen(tipo) + 2];
            char modTipo2[4 + strlen(tipo) + 2];
            modTipo1[0] = '\0';
            modTipo2[0] = '\0';

            if (strstr(final, ":;") != NULL) {
                char* partsMT1[] = {":", tipo, ";\n"};
                int nMT1 = sizeof(partsMT1)/sizeof(partsMT1[0]);
                concatenateArray(modTipo1, partsMT1, nMT1);
            }

            if (strstr(final, ":=") != NULL) {
                char* partsMT2[] = {":", tipo, "="};
                int nMT2 = sizeof(partsMT2)/sizeof(partsMT2[0]);
                concatenateArray(modTipo2, partsMT2, nMT2);
            }
            
            // Reemplazo de patrones en `final`
            char *finalMod = replace(final, ":;", modTipo1);
            if (finalMod != NULL) {
                finalMod = replace(finalMod, ":=", modTipo2);
                if (finalMod != NULL) {
                    $$ = finalMod;
                } else {
                    // Manejar el error si la segunda llamada a replace falla
                }
            } else {
                // Manejar el error si la primera llamada a replace falla
            }
    }        
	| STRINGV operand vardef {
    		

            char * final = malloc(strlen($1)*sizeof(char) + strlen($2)*sizeof(char)+ strlen($3)*sizeof(char) + strlen("; : \n")*sizeof(char) + 1);
            memset(final, 0, sizeof(final));
    		if (final) {  // Siempre es buena práctica verificar si malloc fue exitoso
                char* parts[] = {"\0", $1, $2, $3};
                int n = sizeof(parts)/sizeof(parts[0]);
                concatenateArray(final, parts, n);
    		}

    		free($1); // Libera $1 después de usarlo
            free($2);
            free($3);
    		$$ = final; // Asigna el resultado a $$
	}
    |STRINGV COMMA vardef{//10
        char * final = malloc(strlen($1)*sizeof(char) + sizeof("; : \n") + strlen($3)* sizeof(char));
        memset(final, 0, sizeof(final));
        char* parts[] = {"\0", $1, ":;\n", $3};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);
        free($1);
        free($3);
        $$ = final;
    }
    |atom SEMICOLON{//11

        size_t total_size = strlen($1) + strlen(";\n") + 1;
        char *final = malloc(total_size);
        if (final == NULL) {
            // Manejo del error...
        }
        memset(final, 0, total_size);
        char* parts[] = {$1, ";\n"};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);
        free($1);
        $$ = final;
    }
    |atom EQ exp SEMICOLON{//12
        char * final = malloc(strlen($1)*sizeof(char) + sizeof("; : let \n") + strlen($3)*sizeof(char) );
        memset(final, 0, sizeof(final));
        char * parts[] = {"\0", $1, ":=", $3, ";\n"};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);        
        free($1);
        free($3);
        $$ = final;
    }
       
;
types :
	type {
		$$=$1;
	}
	|type prod{
		$$ = $1;
	}
;

type : 
        INTEGER {$$ = 0;}
        | SHORT {$$ = 1;}
        | LONG {$$ = 2;}
        | LONG_LONG {$$ = 2;}
        | UNSIGNED_INT {$$ = 3;}
        | UNSIGNED_SHORT {$$ = 4;}
        | UNSIGNED_LONG {$$ = 5;}
        | UNSIGNED_LONG_LONG {$$ = 5;}
        | FLOAT {$$ = 6;}
        | DOUBLE {$$ = 7;}
        | STRING {$$ = 8;}
        | CHAR {$$ = 9;}
        | BOOLEAN {$$ = 10;}
        | VOID {;}
        | STRUCT STRINGV {
                strcpy(tipoStruct, $2);
		free($2);
                $$ = 11;
        }
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
            char *final = calloc(strlen($1) + strlen($2) + 1, sizeof(char));

            char * parts[] = {"\0", $1, $2};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);

            free($2);
            free($1);
            $$ = final; // Asegúrate de liberar $$ cuando ya no se necesite
        }
        | programa {
            char *final = calloc(strlen($1) + 1, sizeof(char)); // Reservar espacio suficiente incluyendo el terminador nulo
            char * parts[] = {"\0", $1};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);

    		free($1); // Liberar memoria de $1
    		$$ = final; // Asignar el resultado a $$
	}

programa : 
        types STRINGV LPAREN args RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET{                        
                        
            // Reservar memoria inicial
            size_t size = strlen($4) + strlen($7) + strlen($2) + strlen("{\n") + strlen("\n") + strlen("}\n\n") + 1;
            char *final = malloc(size * sizeof(char));
            if (!final) {
                // Manejo de error: memoria no asignada
            }
            memset(final, 0, size);

            // Se realizan operaciones que modifican 'final'
            funCreation(final, $2, $4);
            typeSwitch(final, $1);

            // Calcular la longitud actual de 'final'
            size_t current_length = strlen(final);

            // Calcular la cantidad de memoria adicional necesaria para las nuevas partes
            size_t extra = strlen("{\n") + strlen($7) + strlen("\n") + strlen("}\n\n");

            // Calcular el nuevo tamaño total (longitud actual + extra + 1 para el carácter nulo)
            size_t new_size = current_length + extra + 1;

            // Realizar realloc para aumentar el tamaño de 'final'
            char *temp = realloc(final, new_size * sizeof(char));
            if (temp == NULL) {
                // Manejo de error: realloc falló. 'final' sigue siendo válido.
                // Se podría optar por liberar 'final' o gestionar el error adecuadamente.
            } else {
                final = temp;
            }

            // Concatenar las nuevas partes
            char *parts[] = {"{\n", $7, "\n", "}\n\n"};
            int n = sizeof(parts) / sizeof(parts[0]);
            concatenateArray(final, parts, n);

            // Liberar la memoria que ya no se necesite
            free($7);
            free($4);
            free($2);
            DeleteListT(&flist);

            $$ = final;

                
        }

        |types STRINGV LPAREN RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  {
                
                        
            char * final = malloc( strlen($6) * sizeof(char)   + 20*sizeof(char) + sizeof(" -> i16")+ sizeof("fn "));
            memset(final, 0, sizeof(final));
            funCreation(final, $2, "");
            
            typeSwitch(final, $1);
            char * parts[] = {"\n", $6, "\n}\n\n"};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            free($2);
            free($6);
            DeleteListT (&flist);

            $$ = final;
                            
                
        }

        |types STRINGV LPAREN RPAREN SEMICOLON{
            free($2);
            $$ = "";
        }

        | vardef programa {
            char * final = calloc(strlen($1) + strlen($2) + sizeof("\n\n"), sizeof(char));
            char * parts[] = {$1, "\n", $2, "\n"};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            free($1);
            free($2);
            $$ = final;
        }
        
        |types OPENCURLYBRACKET lines_program CLOSECURLYBRACKET SEMICOLON{
		char *tipo;

		if (strcmp(getType($1), "struct") == 0) {
			// Calcular el tamaño total y asignar memoria para el caso de "struct"
			tipo = malloc((strlen(tipoStruct) + 1) * sizeof(char));

			if (tipo == NULL) {
				// Manejar error de asignación
				exit(1);
			}

			// Copiar el contenido de tipoStruct a tipo
			strcpy(tipo, tipoStruct);

			// printf("\n\n TIPO TIPO %s TIPO TIPO \n \n", tipo);
		} else {
			// Calcular el tamaño total y asignar memoria para el caso general
			const char *tipo_obtenido = getType($1);
			tipo = malloc((strlen(tipo_obtenido) + 1) * sizeof(char));

			if (tipo == NULL) {
				// Manejar error de asignación
				exit(1);
			}

			// Copiar el contenido de tipo_obtenido a tipo
			strcpy(tipo, tipo_obtenido);
		}

        char * final = malloc(strlen(tipo) + strlen($3)*sizeof(char) + strlen("struct { } \n\n"));
        memset(final, 0 , sizeof(final));
        char * parts[] = {"struct ", tipo, " {\n", $3, "}\n"};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);
        replaceSemicolon(final);
		free(tipo);
		free($3);
        $$ = final; 
        }
	| constdef programa {
		// Asigna espacio suficiente para `final` y el terminador nulo
		char * final = malloc(strlen($2) + strlen($1) + 1);

		// Inicializa la memoria asignada con ceros
		memset(final, 0, strlen($2) + strlen($1) + 1);
        char * parts[] = {$1, $2};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);

		free($1);
		free($2);
		$$ = final;
	}

        |comment{;}

;

prod :
	PROD prod{
		$$="";

	}
	| PROD{
		$$="";
	}
;

args : 
	types STRINGV COMMA args {
        char * final;
        
        char *tipo;
        tipo = resolveType($1);
                
		final = malloc(strlen(tipo)  + strlen($2) * sizeof(char) + strlen($4) * sizeof(char) + sizeof(",  ") + 3*sizeof(char));
        memset(final, 0, sizeof(final));
        char * parts[] = {$4, ", ", tipo, " ", $2};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);
        free($2);
		free($4);
        $$ = final;
                
    }
	|types STRINGV {
		char *final;
		char *tipo;
		char *parts[4];
        int n = 4;      

        if (strcmp(getType($1), "struct") == 0) {
            // Calcular el tamaño total y asignar memoria a 'tipo'
            tipo = calloc(strlen(tipoStruct) + strlen($2) + strlen(": &mut ") + 1 , sizeof(char));
            if (tipo == NULL) {
                exit(1);
            }
            
            // Asignar valores al arreglo parts para el caso 'struct'
            parts[0] = "\0";
            parts[1] = $2;
            parts[2] = ": &mut ";
            parts[3] = tipoStruct;
            
            // Llamada a la función de concatenación
            concatenateArray(tipo, parts, n);
            
            free($2);
            $$ = tipo;
        } else {
            tipo = getType($1);
            // Calcular el tamaño total y asignar memoria a 'final'
            final = calloc(strlen(tipo) + strlen($2) + 2, sizeof(char)); // +2 para " " y '\0'
            if (final == NULL) {
                exit(1);
            }
            
            // Asignar valores al arreglo parts para el otro caso
            parts[0] = "\0";
            parts[1] = tipo;
            parts[2] = " ";
            parts[3] = $2;
            
            // Llamada a la función de concatenación
            concatenateArray(final, parts, n);
            
            free($2);
            $$ = final;
        }

			
        }
        |types STRINGV LSQUAREPAREN RSQUAREPAREN COMMA args{
            
            char *tipo;
            tipo = resolveType($1);
            char * final = malloc(strlen(tipo)* sizeof(char) +strlen($2)* sizeof(char) +strlen($6)*sizeof(char) + sizeof("[] : ,\n"));
            memset(final, 0 , sizeof(final));
            char * parts[] = {$2, ": [", tipo, "], ", $6};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            free($2);
            free($6);
            $$ = final;
        }
        |types STRINGV LSQUAREPAREN RSQUAREPAREN{
           
            char *tipo;
            tipo = resolveType($1);
            char * final = malloc(strlen(tipo)* sizeof(char) +strlen($2)* sizeof(char) + sizeof("[] : ,\n"));
            memset(final, 0 , sizeof(final));
            char * parts[] = {$2, ": [", tipo, "]"};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            free($2);
            $$ = final;
        }


;

lines_program : 
        lines_program line_program {
	// Calcular el tamaño total necesario para el buffer
		char *final = malloc(strlen($1) + strlen($2) + 1); // +2 para "\n" y '\0'
        memset(final, 0 , sizeof(final));

        char * parts[] = {"\0", $1, $2};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);
		// Liberar las cadenas individuales
		free($1);
		free($2);

		// Asignar el resultado a $$
		$$ = final;
        }
        | line_program {
                $$ = $1;
                
        }
        
        
;

if_statement :
       	 IF LPAREN exp RPAREN line_program {
                char * final = malloc(strlen($3)* sizeof(char) + strlen($5)*sizeof(char) + sizeof("if ( ) { } \t \n \n"));                
                ifCreation(final, $3, $5);
                free($3);
                free($5);
                $$ = final;

        } 
        | IF LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  {
                char * final = malloc(strlen($3)* sizeof(char) + strlen($6)*sizeof(char) + sizeof("if ( ) { } \t \n \n"));
                ifCreation(final, $3, $6);
                free($3);
                free($6);
                $$ = final;

        }
        | ELSE IF LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET {
                char * final = malloc(strlen($4)* sizeof(char) + strlen($7)*sizeof(char) + sizeof("else if ( ) { } \t \n \n"));
                memset(final, 0, sizeof(final));
                char* parts[] = {"else "};
                int n = sizeof(parts)/sizeof(parts[0]);
                concatenateArray(final, parts, n);
                ifCreation(final, $4, $7);
                free($4);
                free($7);
                $$ = final;
        }
        | ELSE OPENCURLYBRACKET lines_program CLOSECURLYBRACKET {
                char* final = malloc(strlen($3)*sizeof(char)+ sizeof("else {} \n \n \t"));
                memset(final, 0, sizeof(final));

                char* parts[] = {"else{\n\t", $3, "}\n"};
                int n = sizeof(parts)/sizeof(parts[0]);
                concatenateArray(final, parts, n);
                free($3);
                $$ = final;
        
        }
        | SWITCH exp OPENCURLYBRACKET case_chain CLOSECURLYBRACKET{
            char *final = malloc(strlen("match {}\n\n") + strlen($2) + strlen($4) + 1);
            memset(final, 0, sizeof(final));
            
            char * parts[] = {"\0", "match ", $2, "{\n", $4, "}\n"};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            free($2);
            free($4);
            $$ = final;
     
        }


;

case_chain :
	CASE values COLON lines_program case_chain {
		// Cálculo de la longitud total necesaria para `final`
		size_t longitud_final = strlen(" => {\n") + strlen($2) + strlen($4) + strlen("\n}, ") + strlen($5) + 1;
		char *final = malloc(longitud_final);
		if (final == NULL) {
			// Manejar error de asignación de memoria
			$$ = "";
		}
        final[0] = '\0'; // Inicializa `final` como una cadena vacía

        char * parts[] = {$2, " => {\n", $4, "\n}, ", $5};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);

		// Liberación de memoria de las variables temporales
		free($2);
		free($4);
		free($5);

		// Asignación del resultado a $$
		$$ = final;
	}

	| CASE values COLON lines_program{
		char *final = malloc(strlen("=> ,  \n") + strlen($2) + strlen($4) + 1);
		final[0] = '\0';
        char * parts[] = {$2, " => {\n", $4, "\n"};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);
	
		free($2);
		free($4);
		$$ = final;
	}
	| CASE STRINGV COLON lines_program case_chain{
		char *final = malloc(strlen("=> ,  \n\n") + strlen($2) + strlen($4) + strlen($5)+ 1);
		final[0] = '\0';
        char * parts[] = {$2, " => {\n", $4, "\n}, ", $5};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);
		strcat(final, $2);
		strcat(final, " => {\n");
		strcat(final, $4);
		strcat(final, "\n}, ");
		strcat(final, $5);
		free($2);
		free($4);
		free($5);
		$$ = final;

	}
	| CASE STRINGV COLON lines_program{
		char *final = malloc(strlen("=> ,  \n") + strlen($2) + strlen($4) + 1);
		final[0] = '\0';
        char * parts[] = {$2, " => {\n", $4, "\n"};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);

		free($2);
		free($4);
		$$ = final;

	}
	| DEFAULT COLON lines_program{
		char *final = malloc(strlen("_ => ,  \n") + strlen($3) + 1);
		final[0] = '\0';
        char * parts[] = {"_ => {\n", $3, "\n"};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);
		free($3);
		$$ = final;

	}
;





fun_cre :
        
         STRINGV LPAREN array RPAREN{
                char * final = malloc(strlen($1)* sizeof(char) + strlen($3)*sizeof(char) + sizeof("()") + 1);
                memset(final,0, sizeof(final));
                funCreation(final, $1, $3);
                
                free($1);
                free($3);
                $$ = final;

        }
        |STRINGV LPAREN RPAREN{
                char * final = malloc(strlen($1)* sizeof(char) +  sizeof("()") + 1);
                memset(final,0, sizeof(final));
                funCreation(final, $1, "");
                free($1);
                $$ = final;

        }
        |LPAREN types RPAREN fun_cre{
            $$ = ""	;
        } 

;

line_program :
        PRINTF LPAREN precontentWrite RPAREN SEMICOLON {
            char * final = malloc(strlen($3)*sizeof(char)+ sizeof("print!"));
            memset(final, 0, sizeof(final));
            char* parts[] = {"print!", $3};
            int n = sizeof(parts)/sizeof(parts[0]);

            concatenateArray(final, parts,n );
            free($3);
            $$ = final;
        }
        | SCANF LPAREN precontentWrite RPAREN SEMICOLON{
            char * final = malloc(strlen($3)*sizeof(char)+ sizeof("let mut input = String::new();\nio::stdin()\n.read_line(&mut input)\n.expect(\"Failed to read line\");"));
            memset(final, 0, sizeof(final));
            strcpy(final, "let mut input = String::new();\nio::stdin()\n.read_line(&mut input)\n.expect(\"Failed to read line\");");
            free($3);
            $$ = final;
        }
       	| fun_cre{
            $$ = $1;
        } 
        | if_statement{
            $$ = $1;
        }
        | FOR LPAREN types STRINGV EQ INTNUM SEMICOLON exp SEMICOLON STRINGV operand RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET {
            // Calcular el tamaño de `final` correctamente y asegurar espacio para el terminador nulo
            char *final = malloc(strlen("for in .. {} \n\n") + strlen($4) +
             strlen($6) + strlen($9) + strlen($10) + strlen($14) + 1);
            // Inicializar `final` correctamente
            final[0] = '\0';

            // Obtener valor de `octavo`
            char *numero = getEndNumber($8);
            char *octavo;
            if (strcmp(numero, "") == 0) {
                octavo = getStringFromExp($8);
            } else {
                octavo = strdup(numero);  // Asegurar que octavo siempre esté inicializado
            }

            // Concatenación de las cadenas en `final`
            char * parts[] = {"for ", $4, " in ", $6, "..", octavo, "{\n", $14, "\n"};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            
            // Liberar la memoria de las variables temporales
            free($4);
            free($6);
            free($8);
            free($10);
            free($11);
            free($14);
            free(numero);
            free(octavo);  // Asegurarse de liberar `octavo` después de usarlo
            $$ = final;
        }        //for ( int i = 8 ; i<20 ; i = i + 1) { lines}
        | FOR LPAREN types STRINGV EQ INTNUM SEMICOLON exp SEMICOLON vardef RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET {
                size_t size = $3*sizeof(int) + strlen($4)*sizeof(char) + strlen($6)*sizeof(char) +
                  strlen($8)*sizeof(char) + strlen($10)*sizeof(char) + strlen($13)*sizeof(char) +
                sizeof("for ; ; {} .step_by( )");
                char *final = malloc(size);
                memset(final, 0, size);

                char * numero = getEndNumber($8);
                char * numero2 = getEndNumber($10);
                
                char * parts[] = {"for ", $4, " in ", $6, "..", numero, ".step_by(", numero2, "){\n", $13, "\n"};
                int n = sizeof(parts)/sizeof(parts[0]);
                concatenateArray(final, parts, n);

                free($4);
                free($6);
                free($8);
                free($10);
                free($13);
                free(numero);
                free(numero2);
                $$=final;
        
        
        }
        | DO OPENCURLYBRACKET lines_program CLOSECURLYBRACKET WHILE LPAREN exp RPAREN SEMICOLON{
                char * final = malloc( strlen($3)*sizeof(char) + strlen($7)*sizeof(char) + sizeof("loop {} if() == {} break; \n") );
                memset(final, 0 , sizeof(final));
                char * parts[] = {"loop{\n", $3, "if(", $7, "){\nbreak;\n", "}\n}"};
                int n = sizeof(parts)/sizeof(parts[0]);
                concatenateArray(final, parts, n);
                
                free($3);
                free($7);
                $$ = final;
        
        }
        | WHILE LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET{
                char * final = malloc(strlen($3)*sizeof(char) + strlen($6)*sizeof(char) + sizeof("while () {} \n\n"));
                memset(final, 0, sizeof(final));
                char * parts[] = {"while(", $3, "){\n", $6, "\n}"};
                int n = sizeof(parts)/sizeof(parts[0]);
                concatenateArray(final, parts, n);

                free($3);
                free($6);
                $$ = final;
                
        }
        
        | comment{;}
        | STRINGV operand SEMICOLON{
                char * final = malloc (strlen($2)*sizeof(char) + strlen($1)*sizeof(char));
                memset(final, 0, sizeof(final));
                char * parts[] = {$1, $2, ";"};
                int n = sizeof(parts)/sizeof(parts[0]);
                concatenateArray(final, parts, n);
                free($1);
                free($2);
                $$ = final;
        }
        | LPAREN prod STRINGV RPAREN operand SEMICOLON{
                size_t total_length = strlen($3) + strlen($5) + strlen(";") + 1;
                char *final = malloc(total_length);
                if (final == NULL) {
                    // Manejar error de asignación
                }
                final[0] = '\0';  // Inicializar la cadena vacía
                char *parts[] = { $3, $5, ";" };
                int n = sizeof(parts) / sizeof(parts[0]);
                concatenateArray(final, parts, n);

                free($3);
                free($5);
                $$ = final;

        } 
        | RETURN exp SEMICOLON {
                char *final = malloc((strlen($2) + 1) * sizeof(char)); // Reservar espacio para $2 y el terminador nulo
                if (final == NULL) {
                    // Manejo de error de asignación
                    exit(1);
                }

                final[0] = '\0';
                char * parts[] = {$2};
                int n = sizeof(parts)/sizeof(parts[0]);
                concatenateArray(final, parts, n);
                 
                $$ = final; // Asignar `final` a $$
                
        }
        | RETURN SEMICOLON {
                char * final = malloc(sizeof("return;"));
                memset(final, 0 , sizeof(final));
                char * parts[] = {"return;"};
                int n = sizeof(parts)/sizeof(parts[0]);
                concatenateArray(final, parts, n);
                
                $$ = final;
                
        }
        | vardef{
                char * final = malloc(strlen($1)*sizeof(char)  + sizeof("\n"));
                memset(final,0,sizeof(final));
                char * parts[] = {$1, "\n"};
                int n = sizeof(parts)/sizeof(parts[0]);
                concatenateArray(final, parts, n);
                free($1);      
                $$ = final;
                
        }
        |types OPENCURLYBRACKET lines_program CLOSECURLYBRACKET SEMICOLON{
                char *tipo;
                tipo = resolveType($1);


                char * final = malloc(strlen(tipo) + strlen($3)*sizeof(char) + strlen("struct { } \n\n"));
                memset(final, 0 , sizeof(final));
                char * parts[] = {"struct ", tipo, " {\n", $3, "}\n"};
                int n = sizeof(parts)/sizeof(parts[0]);
                concatenateArray(final, parts, n);

                replaceSemicolon(final);
                free(tipo);
                free($3);
                $$ = final; 
        }
        

;

array :
       
        exp COMMA array{
                // Calcular el tamaño total necesario para `final`
                size_t size_final = strlen($1) * sizeof(char) + strlen($3) * sizeof(char) + sizeof(","); // +1 para la coma

                // Asignar memoria para `final` y asegurar que se incluye espacio para el terminador nulo
                char *final = malloc(size_final + 1);  // +1 para '\0'

                // Inicializar toda la memoria asignada con ceros
                memset(final, 0, size_final + 1);
                char * parts[] = {$1, "," ,$3};
                int n = sizeof(parts)/sizeof(parts[0]);
                concatenateArray(final, parts, n);
                free($1);
                free($3);
                $$ = final;

        }
        |exp{
                $$ = $1;
        }
        | types {
            // Obtener el tipo y asignarlo a una nueva cadena con malloc
            const char *obtenido = getType($1);
            if (obtenido == NULL) {
                perror("Error: getType devolvió NULL");
                exit(1);  // Manejo de error si getType falla
            }

            // Reservar memoria suficiente para el tipo
            char *tipo = malloc(strlen(obtenido) + 1);  // +1 para el terminador nulo
            if (tipo == NULL) {
                perror("Error al asignar memoria para 'tipo'");
                exit(1);
            }
            strcpy(tipo, obtenido);

            // Modificar `tipo` si es necesario
            if (strcmp(tipo, "struct") == 0) {
                free(tipo);  // Liberar memoria previamente asignada
                tipo = malloc(strlen(tipoStruct) + 1);  // Reservar nueva memoria
                if (tipo == NULL) {
                    perror("Error al asignar memoria para 'tipoStruct'");
                    exit(1);
                }
                strcpy(tipo, tipoStruct);
            }
            // Asignar el valor a $$
            $$ = tipo;
        }        
;
precontentWrite :
        contentWrite {
	    	if (strlen(printV) == 0) {
        		char *final = malloc(strlen($1) + strlen(printV) + strlen("();") + 1);  // +1 para '\0'
        		if (final) {
            			final[0] = '\0';  // Inicializa la cadena a vacía
                        char * parts[] = {"(", $1, ")"};
                        int n = sizeof(parts)/sizeof(parts[0]);
                        concatenateArray(final, parts, n);
                        $$ = final;
        		}
    		} else {
	        	int longitud = strlen(printV);
        		char *final = malloc(strlen($1) + strlen("{},,,") + longitud + strlen("(\"") + strlen("\");") + 1);
        		if (final) {
            			final[0] = '\0';  // Inicializa a vacío

            			// Reservamos memoria para nueva_cadena y la inicializamos
            			char *nueva_cadena = malloc(longitud + 1);
            			if (nueva_cadena) {
                			nueva_cadena[0] = '\0';  // Inicializa a vacío

                			// Quita la última coma en printV
                			for (int i = longitud - 1; i >= 0; i--) {
                    				if (printV[i] == ',') {
                        				printV[i] = '\0';
                        				break;
                    				}
                			}
                			strcpy(nueva_cadena, printV);

                			// Conteo de '{' en $1
                			int contador = 0;
                			for (int i = 0; $1[i] != '\0'; i++) {
                    				if ($1[i] == '}') {
                        				contador++;
                    				}
                			}

                			strcat(final, "(");
                			if (strlen(printV) == contador) {
                                    char * parts[] = {"\"", $1, "\"", ",", nueva_cadena};
                                    int n = sizeof(parts)/sizeof(parts[0]);
                                    concatenateArray(final, parts, n);
                			} else if (strlen(printV) > contador) {
                    				char * parts[] = {"\"", $1, "{}", "\"", ",", nueva_cadena};
                                    int n = sizeof(parts)/sizeof(parts[0]);
                                    concatenateArray(final, parts, n);
                            } else {
                    				printf("Error: valores no coinciden\n");
                			}
                			strcat(final, ");");

                			// Liberación de memoria
                			memset(printV, 0, strlen(printV));  // Limpia printV pero sin liberar
                			free(nueva_cadena);  // Libera nueva_cadena
            			}
            			$$ = final;  // Asigna el resultado final
        		}
        		free($1);  // Libera $1 en ambas ramas
    		}
	}

       
;

contentWrite : 
       contentWrite COMMA exp{
            char * final = malloc(strlen($1) * sizeof(char) + strlen($3) * sizeof(char) + strlen("{}") * sizeof(char)); 
            memset(final, 0, sizeof(final));
            char * parts[] = {$3, ",", $1};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            deleteQuotes(final);
            free($1);
            free($3);
            $$ = final;
        }
        
        | QUOTESTRING {

                $$ = $1;}
        | STRINGV {
                $$ = $1;
	}
;



exp :   
        exp operand term {
            char *final = malloc(strlen($1) + strlen($2) + strlen($3) + 1); // +1 para el terminador nulo

            // Inicializar el bloque de memoria completo
            memset(final, 0, strlen($1) + strlen($2) + strlen($3) + 1);
            char * parts[] = {$1, $2, $3};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            
            // Liberar las variables temporales
            free($1);
            free($2);
            $$ = final;
        }
        |term {
                                

        	$$ = $1;
		
        }

;

term :
        atom {

                $$ = $1;
        }

        | LPAREN exp RPAREN {
                char * final = malloc(strlen($2) * sizeof(char) + sizeof("()") + 1);
                memset(final, 0, sizeof(final));
                char * parts[] = {"(", $2, ")"};
                int n = sizeof(parts)/sizeof(parts[0]);
                concatenateArray(final, parts, n);
                
                free($2);
                $$ = final;
        }
        | EX exp {
                char * final = malloc(strlen($2) * sizeof(char) + sizeof("!()") + 1);
                memset(final, 0, sizeof(final));
                char * parts[] = {"!(", $2, ")"};
                int n = sizeof(parts)/sizeof(parts[0]);
                concatenateArray(final, parts, n);
                free($2);
                $$ = final;
        }
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
        |PERCENT {$$ = strdup(" % ");}
        |EX EQ {$$ = strdup(" != ");}
;

atom :

    STRINGV {

		$$ = $1;
	}
	|prod STRINGV {
	
		$$ = $2;
	}
    | values {

		$$ = $1;		
	}
    |STRINGV LSQUAREPAREN exp RSQUAREPAREN{

        char *final = malloc(strlen($1) * sizeof(char) + strlen($3) * sizeof(char) + sizeof("[]"));

		// Usar el tamaño total asignado en `malloc` para `memset`
		memset(final, 0, strlen($1) * sizeof(char) + strlen($3) * sizeof(char) + sizeof("[]"));
        char * parts[] = {$1, "[", $3, "]"};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);
        free($1);
		free($3);
		$$ = final;
    }
	

	| fun_cre{
		$$ = $1;
	}


;

%%

char * getType(int valor) {
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

void typeSwitch(char*final, int type){
    
    strcat(final, "-> ");
    strcat(final, getType(type));
    strcat(final, " {");

}

char* getEndNumber(char* number) {
	int len = strlen(number);
	char* numero = (char*) malloc(len + 1); // Reservar espacio para el nuevo número (+1 por el '\0')
    	if (numero == NULL) return NULL; // Verificar si la asignación fue exitosa

    		int j = 0;
    		// Recorremos `number` desde el final para encontrar los dígitos
    		for (int i = len - 1; i >= 0; i--) {
        		if (!isdigit(number[i])) {
          	  		break;
        		} else {
        	    		numero[j++] = number[i]; // Guardar el dígito en `numero`
        		}
    		}
    		numero[j] = '\0'; // Terminar la cadena con '\0'

    		// Invertir `numero` para obtener los dígitos en el orden correcto
    		for (int k = 0; k < j / 2; k++) {
        		char temp = numero[k];
        		numero[k] = numero[j - k - 1];
        		numero[j - k - 1] = temp;
    		}

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

char *replace(const char *cadena, const char *busqueda, const char *reemplazo) {
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
    char *nuevoString = (char *)malloc(nuevaLongitud + 1); // +1 para el terminador nulo
    if (nuevoString == NULL) {
        return NULL; // Error en la asignación de memoria
    }
    
    nuevoString[0] = '\0';  // Inicializar `nuevoString` con terminador nulo para evitar valores no inicializados.

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

    // Copiar el resto de la cadena y asegurar el terminador nulo
    strcpy(destino, inicio);

    return nuevoString;
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

void ifCreation(char* final, char* in, char* out){
    memset(final, 0, sizeof(final));
    char* parts[] = {"if (", in, "){\n", out, "\n}"};
    int n = sizeof(parts)/sizeof(parts[0]);
    concatenateArray(final, parts, n);
}

void funCreation(char* final, char* name, char* in){
    char* parts[] = {name, "(", in, ")"};
    int n = sizeof(parts)/sizeof(parts[0]);
    concatenateArray(final, parts, n);

}

char* resolveType(int parametro) {
    char* tipo = getType(parametro);
    if (strcmp(tipo, "struct") == 0) {
        // Si tipoStruct es un puntero a memoria estática o se maneja de forma distinta,
        // asegúrate de que la memoria asignada en 'tipo' se libere si es necesario.
        return tipoStruct;
    } else {
        return tipo;
    }
}

void concatenateArray(char *final, char *strings[], int n) {
    for (int i = 0; i < n; i++) {
        strcat(final, strings[i]);
    }
}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Syntax:\n");
        printf("  Para un archivo: ./traductorP <archivoC>\n");
        printf("  Para múltiples archivos: ./traductorP -r <archivo1> <archivo2> ...\n");
        exit(-1);
    }

    // Inicializar listas
    InitializeListT(&typelist);
    InitializeListN(&queue);

    // Caso de procesamiento múltiple de archivos
    if (strcmp(argv[1], "-r") == 0) {
        if (argc < 3) {
            printf("ERROR: Debes proporcionar al menos un archivo tras el flag -r.\n");
            exit(-1);
        }

        int num_files = argc - 2;
        arraySize = num_files;

        // Reservar memoria para arrayCabeceras
        arrayCabeceras = (char**)malloc(arraySize * sizeof(char*));
        if (arrayCabeceras == NULL) {
            printf("Error al asignar memoria para arrayCabeceras\n");
            exit(1);
        }

        // Para cada archivo, construir la ruta y reservar espacio
        for (int i = 0; i < num_files; i++) {
            char ruta[100] = "entrada/";
            strcat(ruta, argv[i + 2]);

            arrayCabeceras[i] = (char*)malloc((strlen(ruta) + 1) * sizeof(char));
            if (arrayCabeceras[i] == NULL) {
                printf("Error al asignar memoria para arrayCabeceras[%d]\n", i);
                exit(1);
            }
            strcpy(arrayCabeceras[i], ruta);
        }

        // Procesar cada archivo en paralelo
        #pragma omp parallel for shared(arrayCabeceras, arraySize) 
        for (int i = 0; i < arraySize; i++) {
            YY_BUFFER_STATE bufferState = NULL;

            #pragma omp critical
            {
                bufferState = yy_current_buffer();
                yy_flush_buffer(bufferState);
                yyin = fopen(arrayCabeceras[i], "r");
                if (yyin == NULL) {
                    printf("ERROR: No se ha podido abrir el fichero %s.\n", arrayCabeceras[i]);
                    continue; // Saltar si no se puede abrir el archivo
                }
                bufferState = yy_create_buffer(yyin, 1024);
                yy_switch_to_buffer(bufferState);
            }

            // Actualizar filePath para el archivo actual
            strcpy(filePath, arrayCabeceras[i]);
            yyparse();

            #pragma omp critical
            {
                fclose(yyin);
            }
            yy_delete_buffer(bufferState);
        }
    } 
    // Caso de procesamiento de un único archivo
    else {
        char ruta[100] = "entrada/";
        strcat(ruta, argv[1]);
        strcpy(filePath, ruta);

        yyin = fopen(ruta, "r");
        if (yyin == NULL) {
            printf("ERROR: No se ha podido abrir el fichero %s.\n", ruta);
            exit(1);
        }
        yyparse();
        fclose(yyin);
    }
    
    return 0;
}

