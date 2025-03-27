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
#include "functions.h"
#include "scannerCR.tab.h"

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
char preSlash[100] = "";
char sizeS[8] = "200";
char structType[50] = "";
char ** headersArray = NULL;
char gType[10] = "";
char printV[100]= "";

TypeList typelist;
TypeList flist;

NodeList queue;

char * resolveType(int parameter);

//macros


%}

%define parse.error verbose 
%verbose
%define parse.trace
%locations  

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
%token QUESTION
%token <valString>COMMENTLINE
%token <valString>MULTILINE
%token VAR
%token CONST
%token VOLATILE
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
%token <valString>TRUEVAL
%token <valString>FALSEVAL
%token <valString> INTNUM
%token <valString> REALNUM
%token RETURN
%token STRUCT
%token AMPERSAND
%token ASM


%left <valString>SEMICOLON
%left <valString>EQ
%left LOWER HIGHER
%left <valString>PLUS HYPHEN PERCENT QUOTESTRING
%left DIV
%left DIVINT MOD
%left AND OR
%left COLON QUESTION 
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

%nonassoc LOWPREC

%type <valString> vardef constdef macroargs args if_statement fun_cre 
%type <valString> preprogram case_chain 

%type <valString>  values array prod ms_inline 
%type <valInt> type types
%type <valString> header asm_fun asm_string asm_input_output 
%type <valString> lines_program line_program
%type <valString> contentWrite program precontentWrite 
%type <valString> comment
%type <valString> atom
%type <valString> operand 
%type <valString> exp term exp_macro
%start S 
%%
S : 

        header preprogram { 
                char* input = (char*)malloc(strlen(filePath) + 1);
                memset(input, 0 , sizeof(input));
                
                strcpy(input, filePath);
                char output[100];
                free($1);

                char* lastSlash = strrchr(input, '/');
                if(lastSlash != NULL) {
                    char original = *lastSlash;
                    *lastSlash = '\0';
                    *lastSlash = original;
                }
                if (lastSlash) {
                        size_t length = strlen(lastSlash + 1);
                        
                        strcpy(output, "output");
                        strncat(output, lastSlash, length - 1);
                        strcat(output, ".rs");

                } else {
                        printf("No '/' found in input string.\n");
                }

                free(input);
                FILE *fp = fopen(output, "w");

                if (fp != NULL) {
                    char *result = insertTabsBetweenBraces($2);
                    if (result != NULL) {
                        fputs(result, fp);
                        free(result);
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

header : 	
        PROGRAM LOWER STRINGV HIGHER {
	 		free($3);
			$$ = strdup("");

		}
        |PROGRAM LOWER STRINGV DOT STRINGV HIGHER {
			free($3);
			free($5);
			$$ = strdup("");
		}
		|PROGRAM QUOTESTRING {
            #pragma omp critical
			{       
                char final[100] = "";
                char file[50] = "";

   	 			strcat(file, $2);
                free($2);
    				deleteQuotes(file);

    				if (strlen(file) > 2) {
        				file[strlen(file) - 2] = '\0';
    				}

    				char route[100] = "";
                    strcat(final, preSlash);
                    strcat(final, "/");
    				strcat(final, file);
    				strcat(final, ".c");

    				strcat(route, final);
                    printf("%s\n",route);
    				if (searchString(headersArray, route, arraySize) == 0) {
        				arraySize++;
        				headersArray = (char**)realloc(headersArray, arraySize * sizeof(char*));
        
        				headersArray[arraySize - 1] = (char*)malloc((strlen(route) + 1) * sizeof(char)); 
        				if (headersArray[arraySize - 1] == NULL) {
            					printf("Error allocating memory for headersArray[%d].\n", arraySize - 1);
            					exit(1);
        				}

        				strcpy(headersArray[arraySize - 1], route);
    				}
			}
		}
        |PROGRAM LOWER STRINGV HIGHER header {
			free($3);	
            free($5);
			$$ = strdup("");
		}
        |PROGRAM LOWER STRINGV DOT STRINGV HIGHER header{
			free($3);
            if($5 != $7){
                free($7);
            }
            free($5);
			$$ = strdup("");
		}
		|PROGRAM QUOTESTRING header{
                                                
			#pragma omp critical
			{       
				char final[100] = "";
				char file[50] = "";
				strcat(file, $2);
				free($2);
				deleteQuotes(file);
				file[strlen(file) - 2] = '\0';

				char route[100] = "";

				strcat(final, preSlash);
                strcat(final, "/");
                strcat(final, file);
                strcat(final, ".c");
				strcat(route, final);

				if (searchString(headersArray, route, arraySize) == 0) {
					arraySize++;
					headersArray = (char**)realloc(headersArray, arraySize * sizeof(char*));

					headersArray[arraySize - 1] = (char*)malloc((strlen(route) + 1) * sizeof(char)); 

					strcpy(headersArray[arraySize - 1], route);
				}
			}

        }
;

exp_macro :   
        exp_macro operand term {
            if(!strcmp($2," ? ")){
                char * mod1 = replace($3, "(", "");
                char * mod2 = replace(mod1, ")", "_val");
                free(mod1);

                char * final = malloc(strlen($1) + strlen(mod2) + strlen("if( ){}"));
                memset(final, 0, sizeof(final));
                char * parts[] = {"if(", $1, "){", mod2, "}"};
                int n = sizeof(parts)/sizeof(parts[0]);
                concatenateArray(final, parts, n);
                
                free($1);
                free($2);
                free($3);
                free(mod2);

                $$ = final;

            }else if(!strcmp($2," : ")){
                char * mod1 = replace($3, "(", "");
                char * mod2 = replace(mod1, ")", "_val");
                free(mod1);

                char * final = malloc(strlen($1) + strlen(mod2) + strlen("else{}") + 1);
                memset(final, 0, sizeof(final));
                char * parts[] = {$1, "else{", mod2, "}"};
                int n = sizeof(parts)/sizeof(parts[0]);
                concatenateArray(final, parts, n);
                free($1);
                free($2);
                free($3);
                free(mod2);
                $$ = final;

            }else{
                char * mod1 = replace($1, "(", "");
                char * mod2 = replace(mod1, ")", "_val");
                char * mod3 = replace($3, "(", "");
                char * mod4 = replace(mod3, ")", "_val");
                free(mod1);
                free(mod3);

                
                char * final = malloc(strlen(mod2) + strlen($2) + strlen(mod4) + 1);
                memset(final, 0, sizeof(final));
                char * parts[] = {mod2, $2, mod4};
                int n = sizeof(parts)/sizeof(parts[0]);
                concatenateArray(final, parts, n);

                free($1);
                free($2);
                free($3);
                free(mod2);
                free(mod4);
                $$ = final;
            }

        }
        |term {
        	char *final = malloc(strlen($1) * sizeof(char) + 1);

            memset(final, 0, strlen($1) * sizeof(char));
            char * parts[] = {$1};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            free($1);
            $$ = final;
        }

;

constdef : 
        DEFINE STRINGV values {
            size_t size_final = strlen($2) + strlen($3) + 6 + 10 + 2 + 1;
            char *final = malloc(size_final * sizeof(char));

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
        |DEFINE STRINGV LPAREN macroargs RPAREN LPAREN exp_macro RPAREN{
            char * temp = wrapInParentheses($4);            
            char * vars = transformDollarVarsInsideParentheses(temp);
            size_t longitud_final = strlen($2) + strlen(temp) + strlen(vars) + strlen($7) + strlen("macro_rules!  {\n => {{\n\n}}\n};\n") + 1;
            char * final = malloc(longitud_final * sizeof(char));
            final[0] = '\0';
            toLowercase($2); 
            char * parts[] = {"macro_rules! ", $2, "{\n", temp, " => {{\n", vars, $7, "\n}};\n}\n"};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            free(temp);
            free(vars);
            free($2);
            free($4);
            free($7);
            $$ = final;

        }//#define PRINT(fmt, ...) printf(fmt, __VA_ARGS__)
        |DEFINE STRINGV LPAREN macroargs RPAREN STRINGV LPAREN macroargs RPAREN{
            char * temp = wrapInParentheses($4);            
            char * vars = transformVariadic($8);
            size_t longitud_final = strlen($2) + strlen(temp) + strlen($6) + strlen(vars) + strlen("macro_rules!()  {\n => {{\n\n}}\n};\n") + 1;
            char * final = malloc(longitud_final * sizeof(char));
            final[0] = '\0';
            toLowercase($2); 
            char * parts[] = {"macro_rules! ", $2, "{\n", temp, " => {\n", $6,"(", vars, ");\n}};\n}\n"};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            free($4);
            free($2);
            free($6);
            free($8);
            free(temp);
            free(vars);
            $$ = final;
        }
        |DEFINE STRINGV LPAREN macroargs RPAREN PRINTF LPAREN macroargs RPAREN{
            char * temp = wrapInParentheses($4);            
            char * vars = transformVariadic($8);
            size_t longitud_final = strlen($2) + strlen(temp) + strlen(vars) + strlen("macro_rules!println!()  {\n => {\n\n}}\n};\n") + 1;
            char * final = malloc(longitud_final * sizeof(char));
            final[0] = '\0';
            toLowercase($2); 
            char * parts[] = {"macro_rules! ", $2, "{\n", temp, " => {\nprintln!(" , vars, ");\n};\n}\n"};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            free($2);
            free($4);
            free($8);
            free(temp);
            free(vars);
            $$ = final;

        }
        
;

macroargs:
        STRINGV COMMA macroargs{
            size_t longitud_final = strlen($1) + strlen($3) + strlen("$:, expr ") + 1;
            char *final = malloc(longitud_final * sizeof(char));
            final[0] = '\0'; 
            char * parts[] = {"$", $1, ": expr, ", $3};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            free($1);
            free($3);
            $$ = final;

        } 
        
        |STRINGV{
            size_t longitud_final = strlen($1) + strlen("$: expr") + 1;
            char *final = malloc(longitud_final * sizeof(char));
            final[0] = '\0'; 
            char * parts[] = {"$", $1, ": expr"};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            free($1);
            $$ = final;
        }
        |DOT DOT DOT{
            size_t longitud_final = strlen("$($args: tt)*") + 1;
            char *final = malloc(longitud_final * sizeof(char));
            final[0] = '\0'; 
            char * parts[] = {"$($args: tt)*"};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            $$ = final;
        }

;

vardef : 
        types STRINGV SEMICOLON {
            char *type;
            type = resolveType($1);
            char *final = malloc(strlen(type) + strlen($2) + strlen("let\n: ;") + 1);

            memset(final, 0, strlen(type) + strlen($2) + strlen("let\n: ;") + 1);

            char* parts[] = {"let ", $2, ":", type, ";\n"};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            free($2);
            $$ = final;
        }

        |types STRINGV LSQUAREPAREN atom RSQUAREPAREN SEMICOLON {
            char *type;
            type = resolveType($1);

            char * final = malloc(strlen(type)* sizeof(char) +strlen($2)* sizeof(char) + strlen($4)*sizeof(char) + sizeof("[]; : ;\n"));
            memset(final, 0 , sizeof(final));
            char* parts[] = {$2, ": [", type, ";", $4, "];\n"};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            free($2);
            free($4);
            $$ = final;
        }
	

        | types STRINGV EQ exp SEMICOLON {//2
            char *type;
            type = resolveType($1);


            char *final = malloc(strlen(type) + strlen($4) + strlen($2) + strlen("=let\n: ;") + 1);

            final[0] = '\0';
            char* parts[] = {"let ", $2, ":", type, "=", $4, ";\n"};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            free($2);
            free($4);
            
            $$ = final;
        }
           
        | types STRINGV LSQUAREPAREN atom RSQUAREPAREN EQ OPENCURLYBRACKET array CLOSECURLYBRACKET SEMICOLON{//4
            char *type;
            type = resolveType($1);


            char *final = malloc(strlen($2) + strlen(type) + strlen($4) + strlen($8) + strlen("let ::[] [] ; \n") + 1);

            final[0] = '\0';
            char* parts[] = {"let ", $2, ": [", type, ":", $4, "] = [", $8, "];\n"};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            
            free($2);
            free($4);
            free($8);
            $$ = final;
        }
        | types STRINGV LSQUAREPAREN RSQUAREPAREN EQ exp SEMICOLON{//4
            char *type;
            type = resolveType($1);

                
            char * final = malloc(strlen($2)*sizeof(char) + strlen(type)*sizeof(char) + strlen($6)*sizeof(char) + sizeof("let ::[] [] ; \n"));
            memset(final,0,sizeof(final));
            char* parts[] = {"let ", $2, "=", $6, ";"};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            free($2);
            free($6);
            $$ = final;
        }
               
        | types STRINGV COMMA vardef {  //7
            char *type;
            type = resolveType($1);
                
            strcpy(gType, type);

            size_t longitud_final = strlen($2) + strlen($4) + strlen(type) + strlen("let :;\n") + 1;
            char *final = malloc(longitud_final * sizeof(char));
            
            final[0] = '\0'; 
            char* parts[] = {"let ", $2, ":;\n", $4};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            free($2);
            free($4);

            char modType1[4 + strlen(type) + 3];
            char modType2[4 + strlen(type) + 2];

            modType1[0] = '\0';
            modType2[0] = '\0';

            if (strstr(final, ":;") != NULL) {
                char* partsMT1[] = {":", type, ";\n"};
                int nMT1 = sizeof(partsMT1)/sizeof(partsMT1[0]);
                concatenateArray(modType1, partsMT1, nMT1);
            }

            if (strstr(final, ":=") != NULL) {
                char* partsMT2[] = {":", type, "="};
                int nMT2 = sizeof(partsMT2)/sizeof(partsMT2[0]);
                concatenateArray(modType2, partsMT2, nMT2);
            }

            char *finalMod = replace(final, ":;", modType1);

            if (finalMod != NULL) {
                char *temp = replace(finalMod, ":=", modType2); 
                free(finalMod);

                if (temp != NULL) {
                        free(final);
                        $$ = temp;
                } else {
                        $$ = final;
                }
            } else {
                $$ = final; 
            }
        }
        | types STRINGV EQ exp COMMA vardef{//8
            char *type;
            type = resolveType($1);

            size_t size_final = strlen("let ") + strlen($2) + strlen(":=") + strlen($4) + strlen(";\n") + strlen($6) + 1;
            char *final = malloc(size_final);

            if (final) {
                final[0] = '\0';
                char* parts[] = {"let ", $2, ":=", $4, ";\n", $6};
                int n = sizeof(parts)/sizeof(parts[0]);
                concatenateArray(final, parts, n);
            }
            free($2);
            free($4);
            free($6);

            char modType1[4 + strlen(type) + 2];
            char modType2[4 + strlen(type) + 2];
            modType1[0] = '\0';
            modType2[0] = '\0';

            if (strstr(final, ":;") != NULL) {
                char* partsMT1[] = {":", type, ";\n"};
                int nMT1 = sizeof(partsMT1)/sizeof(partsMT1[0]);
                concatenateArray(modType1, partsMT1, nMT1);
            }

            if (strstr(final, ":=") != NULL) {
                char* partsMT2[] = {":", type, "="};
                int nMT2 = sizeof(partsMT2)/sizeof(partsMT2[0]);
                concatenateArray(modType2, partsMT2, nMT2);
            }
            
            char *finalMod = replace(final, ":;", modType1);
            if (finalMod != NULL) {
                
                char *temp = replace(finalMod, ":=", modType2);
                if (temp != NULL) {
                    free(finalMod);
                    finalMod = temp;
                    free(final);
                    $$ = finalMod;
                } else {
                    free(temp);
                    $$ = final;
                }

            } else {
                free(finalMod);
                $$ = final;
            }
    }        
	| STRINGV operand vardef {
    		

            char * final = malloc(strlen($1)*sizeof(char) + strlen($2)*sizeof(char)+ strlen($3)*sizeof(char) + strlen("; : \n")*sizeof(char) + 1);
            memset(final, 0, sizeof(final));
    		if (final) {
                char* parts[] = {"\0", $1, $2, $3};
                int n = sizeof(parts)/sizeof(parts[0]);
                concatenateArray(final, parts, n);
                
    		}
            free($1);
            free($2);
            free($3);

   
    		$$ = final;
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
        free($2);
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
            strcpy(structType, $2);
            free($2);
            $$ = 11;
        }
;



values : 
        TRUEVAL {
            $$ = strdup("true");
        }
        | FALSEVAL {$$ = strdup("false");}
        | INTNUM {
            char *final = malloc(strlen($1) * sizeof(char) + 1);

            memset(final, 0, strlen($1) * sizeof(char));
            char * parts[] = {$1};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            free($1);
            $$ = final;
        }
        | REALNUM {
            char *final = malloc(strlen($1) * sizeof(char) + 1);

            memset(final, 0, strlen($1) * sizeof(char));
            char * parts[] = {$1};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            free($1);
            $$ = final;       
        }
        | QUOTESTRING {
            char *final = malloc(strlen($1) * sizeof(char) + 1);

            memset(final, 0, strlen($1) * sizeof(char));
            char * parts[] = {$1};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            free($1);
            $$ = final;}
;

preprogram : 
        preprogram program{
            char *final = calloc(strlen($1) + strlen($2) + 1, sizeof(char));

            char * parts[] = {"\0", $1, $2};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);

            free($2);
            free($1);
            $$ = final;
        }
        | program {
            char *final = calloc(strlen($1) + 1, sizeof(char));
            char * parts[] = {"\0", $1};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);

    		free($1);
    		$$ = final;
	}

program : 
        types STRINGV LPAREN args RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET{                        
                        
            
            size_t size = strlen($4) + strlen($7) + strlen($2) +
                          strlen("{\n") + strlen("\n") + strlen("}\n\n") + 2;
            char *final = malloc(size * sizeof(char));
            if (final == NULL) {
                fprintf(stderr, "Error en la asignación de memoria\n");
                exit(EXIT_FAILURE);
            }
            final[0] = '\0';

            funCreation(final, $2, $4);
            typeSwitch(final, $1);

            size_t current_length = strlen(final);

            size_t extra = strlen("{\n") + strlen($7) + strlen("\n") + strlen("}\n\n");

            size_t new_size = current_length + extra + 1;
            char *temp = realloc(final, new_size * sizeof(char));
            if (temp == NULL) {
                fprintf(stderr, "Error en la realocación de memoria\n");
                free(final);
                exit(EXIT_FAILURE);
            } else {
                final = temp;
            }

            char *parts[] = {"{\n", $7, "\n", "}\n\n"};
            int n = sizeof(parts) / sizeof(parts[0]);
            concatenateArray(final, parts, n);

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
            $$ = strdup("");
        }

        | vardef program {
            char * final = calloc(strlen($1) + strlen($2) + sizeof("\n\n"), sizeof(char));
            char * parts[] = {$1, "\n", $2, "\n"};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            free($1);
            free($2);
            $$ = final;
        }
        
        |types OPENCURLYBRACKET lines_program CLOSECURLYBRACKET SEMICOLON{
            char *type;

            if (strcmp(getType($1), "struct") == 0) {
                type = malloc((strlen(structType) + 1) * sizeof(char));

                if (type == NULL) {
                    exit(1);
                }

                strcpy(type, structType);

            } else {
                const char *type_obtenido = getType($1);
                type = malloc((strlen(type_obtenido) + 1) * sizeof(char));

                if (type == NULL) {
                    exit(1);
                }

                strcpy(type, type_obtenido);
            }

            char * final = malloc(strlen(type) + strlen($3)*sizeof(char) + strlen("struct { } \n\n"));
            memset(final, 0 , sizeof(final));
            char * parts[] = {"struct ", type, " {\n", $3, "}\n"};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            replaceSemicolon(final);
            free(type);
            free($3);
            $$ = final; 
            }
        | constdef program {
            char * final = malloc(strlen($2) + strlen($1) + 1);

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
        free($2);
		$$=strdup("");

	}
	| PROD{
		$$=strdup("");
	}
;

args : 
	types STRINGV COMMA args {
        char * final;
        
        char *type;
        type = resolveType($1);
                
		final = malloc(strlen(type)  + strlen($2) * sizeof(char) + strlen($4) * sizeof(char) + sizeof(",  ") + 3*sizeof(char));
        memset(final, 0, sizeof(final));
        char * parts[] = {$4, ", ", type, " ", $2};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);
        free($2);
		free($4);
        $$ = final;
                
    }
	|types STRINGV {
		char *final;
		char *type;
		char *parts[4];
        int n = 4;      

        if (strcmp(getType($1), "struct") == 0) {
            type = calloc(strlen(structType) + strlen($2) + strlen(": &mut ") + 1 , sizeof(char));
            if (type == NULL) {
                exit(1);
            }
            
            parts[0] = "\0";
            parts[1] = $2;
            parts[2] = ": &mut ";
            parts[3] = structType;
            
            concatenateArray(type, parts, n);
            
            free($2);
            $$ = type;
        } else {
            type = getType($1);
            final = calloc(strlen(type) + strlen($2) + 2, sizeof(char));
            if (final == NULL) {
                exit(1);
            }
            
            parts[0] = "\0";
            parts[1] = type;
            parts[2] = " ";
            parts[3] = $2;
            
            concatenateArray(final, parts, n);
            
            free($2);
            $$ = final;
        }

			
    }
    |types STRINGV LSQUAREPAREN RSQUAREPAREN COMMA args{
        
        char *type;
        type = resolveType($1);
        char * final = malloc(strlen(type)* sizeof(char) +strlen($2)* sizeof(char) +strlen($6)*sizeof(char) + sizeof("[] : ,\n"));
        memset(final, 0 , sizeof(final));
        char * parts[] = {$2, ": [", type, "], ", $6};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);
        free($2);
        free($6);
        $$ = final;
    }
    |types STRINGV LSQUAREPAREN RSQUAREPAREN{
       
        char *type;
        type = resolveType($1);
        char * final = malloc(strlen(type)* sizeof(char) +strlen($2)* sizeof(char) + sizeof("[] : ,\n"));
        memset(final, 0 , sizeof(final));
        char * parts[] = {$2, ": [", type, "]"};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);
        free($2);
        $$ = final;
    }


;

lines_program : 
        lines_program line_program {
            char *final = malloc(strlen($1) + strlen($2) + 1);
            memset(final, 0 , sizeof(final));

            char * parts[] = {"\0", $1, $2};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            free($1);
            free($2);

            $$ = final;
        }
        | line_program {
            $$ = $1;
        }
        
;

if_statement :
       	 IF LPAREN exp RPAREN line_program {
            char * final = malloc(strlen($3)* sizeof(char) + strlen($5)*sizeof(char) + sizeof("if ( ) { } \t \n \n"));                
            memset(final, 0, sizeof(final));
            ifCreation(final, $3, $5);
            free($3);
            free($5);
            $$ = final;

        } 
        | IF LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  {
            char * final = malloc(strlen($3)* sizeof(char) + strlen($6)*sizeof(char) + sizeof("if ( ) { } \t \n \n"));
            memset(final, 0, sizeof(final));
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
		size_t longitud_final = strlen(" => {\n") + strlen($2) + strlen($4) + strlen("\n}, ") + strlen($5) + 1;
		char *final = malloc(longitud_final);
		if (final == NULL) {
			$$ = strdup("");
		}
        final[0] = '\0';

        char * parts[] = {$2, " => {\n", $4, "\n}, ", $5};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);

		free($2);
		free($4);
		free($5);

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
        free($4);
        $$ = strdup("")	;
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
        

        char *numero = getEndNumber($8);
        char *octavo;
        if (strcmp(numero, "") == 0) {
            octavo = getStringFromExp($8);
        } else {
            octavo = strdup(numero);
        }

        char *final = malloc(strlen("for  in .. {} \n\n") + strlen($4)*sizeof(char) +
         strlen($6)*sizeof(char)+ strlen(octavo)*sizeof(char) + strlen($14)*sizeof(char) + 1);
        final[0] = '\0';
        char * parts[] = {"for ", $4, " in ", $6, "..", octavo, "{\n", $14, "\n"};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);
        
        free($4);
        free($6);
        free($8);
        free($10);
        free($11);
        free($14);
        free(numero);
        free(octavo);
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
        free($8);
        free($10);
        
        char * parts[] = {"for ", $4, " in ", $6, "..", numero, ".step_by(", numero2, "){\n", $13, "\n"};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);

        free($4);
        free($6);

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
        }
        final[0] = '\0'; 
        char *parts[] = { $3, $5, ";" };
        int n = sizeof(parts) / sizeof(parts[0]);
        concatenateArray(final, parts, n);
        
        free($2);
        free($3);
        free($5);
        $$ = final;

    } 
    | RETURN exp SEMICOLON {
        char *final = malloc((strlen($2) + 1) * sizeof(char));
        if (final == NULL) {
            exit(1);
        }

        final[0] = '\0';
        char * parts[] = {$2};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);
        free($2); 
        $$ = final;
            
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
        char *type;
        type = resolveType($1);


        char * final = malloc(strlen(type) + strlen($3)*sizeof(char) + strlen("struct { } \n\n"));
        memset(final, 0 , sizeof(final));
        char * parts[] = {"struct ", type, " {\n", $3, "}\n"};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);

        replaceSemicolon(final);
        free($3);
        $$ = final; 
    }
    |asm_fun{
        char * final = malloc(strlen($1)*sizeof(char) + 1);
        memset(final, 0, sizeof(final));
        char * parts[] = {$1};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);
        
        free($1);
        $$=final;
    }    

;

asm_fun :
        //__asm__("movl %ecx, %eax");
    ASM LPAREN asm_string RPAREN SEMICOLON{
        char * final = malloc(strlen($3)*sizeof(char) + strlen("unsafe{\nasm!();\n}\n") + 1);
        memset(final, 0, sizeof(final));
        char * parts[] = {"unsafe{\nasm!(", $3,");\n}\n"};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);

        free($3);

        $$ = final;
    }
    |ASM LPAREN asm_string COLON asm_input_output COLON asm_input_output COLON asm_string RPAREN SEMICOLON{
        char * modOut = transformStringOutput($5);   
        char * modIn = transformStringInput($7);
        memmove($9, $9 + 1, strlen($9));
        free($5);
        free($7);
        size_t finalSize = strlen($3) + strlen(modOut) + strlen(modIn) + strlen($9) +
                    strlen("unsafe{\nasm!(\n\n// );\n}\n\n") + 1;
        char *final = malloc(finalSize);
        final[0]='\0';
        char * parts[] = {"unsafe{\nasm!(", $3,"\n", modOut, modIn, "\n// ", $9, "\n);\n}\n"};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);

        free($3);
        free($9);
        free(modOut);
        free(modIn);

        $$ = final;

    }
    |ASM VOLATILE LPAREN asm_string RPAREN SEMICOLON{
        char * final = malloc(strlen($4)*sizeof(char) + strlen("unsafe{\nasm!();\n}\n") + 1);
        memset(final, 0, sizeof(final));
        char * parts[] = {"unsafe{\nasm!(", $4,");\n}\n"};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);

        free($4);

        $$ = final;

    }
    |ASM VOLATILE LPAREN asm_string COLON asm_input_output COLON asm_input_output COLON asm_string RPAREN SEMICOLON{
        char * modOut = transformStringOutput($6);   
        char * modIn = transformStringInput($8);
        memmove($10, $10 + 1, strlen($10));
        free($6);
        free($8);

        size_t finalSize = strlen($4) + strlen(modOut) + strlen(modIn) + strlen($10) +
                    strlen("unsafe{\nasm!(\n\n// );\n}\n\n") + 1;
        char *final = malloc(finalSize);
        final[0]='\0';
        char * parts[] = {"unsafe{\nasm!(", $4,"\n", modOut, modIn, "\n// ", $10, "\n);\n}\n"};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);

        free($4);
        free($10);
        free(modOut);
        free(modIn);

        $$ = final;
    }
    |ASM OPENCURLYBRACKET ms_inline CLOSECURLYBRACKET {
        size_t totalSize = strlen($3) + strlen("ASM{/**/}\n") + 1;
        char * final = malloc(totalSize);
        memset(final, 0, totalSize);

        char * parts[] = {"/*ASM{",$3, "}*/\n"};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);
        free($3);
        $$ = final;

    }
;

ms_inline :
    STRINGV ms_inline{
            
        size_t totalSize = strlen($1) + strlen($2) + strlen("\n") + 1;
        char * final = malloc(totalSize);
        memset(final, 0, totalSize);

        char * parts[] = {$1,"\n", $2};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);
        free($1);
        free($2);
        $$ = final;
    }
    |STRINGV COMMA ms_inline{
        size_t totalSize = strlen($1) + strlen($3) + strlen(",") + 1;
        char * final = malloc(totalSize);
        memset(final, 0, totalSize);

        char * parts[] = {$1,",", $3};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);
        free($1);
        free($3);
        $$ = final;

    }
    |/*empty*/{$$=strdup("");} %prec LOWPREC

;

asm_input_output :
    LSQUAREPAREN STRINGV RSQUAREPAREN QUOTESTRING LPAREN STRINGV RPAREN COMMA asm_input_output{
        char * final = malloc(strlen($2)*sizeof(char)+ strlen($6)*sizeof(char)+ strlen($9)*sizeof(char) + strlen("\n\n") + 1);
        memset(final, 0, sizeof(final));
        char * parts[] = {$2," ", $6, " ", $9};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);
        free($2);
        free($4);
        free($6);
        free($9);

        $$ = final;
    }
    |LSQUAREPAREN STRINGV RSQUAREPAREN QUOTESTRING LPAREN STRINGV RPAREN {
        char * final = malloc(strlen($2)*sizeof(char)+ strlen($6)*sizeof(char) + strlen("\n") + 1);
        memset(final, 0, sizeof(final));
        char * parts[] = {$2," ", $6};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);
        free($2);
        free($4);
        free($6);
        $$ = final;
    }
    |/*empty*/{$$=strdup("");} %prec LOWPREC

;


asm_string:
    asm_string QUOTESTRING{
        
        size_t totalSize = strlen($1) + strlen($2) + strlen("\n") + 1;
        char * final = malloc(totalSize);
        memset(final, 0, totalSize);

        char * parts[] = {$1,"\n", $2};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);
        free($1);
        free($2);
        $$ = final;
    }
    |asm_string COMMA QUOTESTRING{
        size_t totalSize = strlen($1) + strlen($3) + strlen(",") + 1;
        char * final = malloc(totalSize);
        memset(final, 0, totalSize);

        char * parts[] = {$1,",", $3};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);
        free($1);
        free($3);
        $$ = final;

    }
    |/*empty*/{$$=strdup("");} %prec LOWPREC
    
;

array :
       
        exp COMMA array{
            size_t size_final = strlen($1) * sizeof(char) + strlen($3) * sizeof(char) + sizeof(",");

            char *final = malloc(size_final + 1); 

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
            const char *obtenido = getType($1);
            if (obtenido == NULL) {
                perror("Error: getType returned NULL");
                exit(1);
            }

            char *type = malloc(strlen(obtenido) + 1); 
            if (type == NULL) {
                perror("Error allocating memory for 'type'");
                exit(1);
            }
            strcpy(type, obtenido);

            if (strcmp(type, "struct") == 0) {
                free(type); 
                type = malloc(strlen(structType) + 1); 
                if (type == NULL) {
                    perror("Error allocating memory for 'structType'");
                    exit(1);
                }
                strcpy(type, structType);
            }
            $$ = type;
        }        
;
precontentWrite :
        contentWrite {
	    	if (strlen(printV) == 0) {
        		char *final = malloc(strlen($1) + strlen(printV) + strlen("();") + 1);
        		if (final) {
            			final[0] = '\0'; 
                        char * parts[] = {"(", $1, ")"};
                        int n = sizeof(parts)/sizeof(parts[0]);
                        concatenateArray(final, parts, n);
                        free($1);
                        $$ = final;
        		}
    		} else {
	        	int longitud = strlen(printV);
        		char *final = malloc(strlen($1) + strlen("{},,,") + longitud + strlen("(\"") + strlen("\");") + 1);
        		if (final) {
            			final[0] = '\0';

            			char *newString = malloc(longitud + 1);
            			if (newString) {
                			newString[0] = '\0';

                			for (int i = longitud - 1; i >= 0; i--) {
                    				if (printV[i] == ',') {
                        				printV[i] = '\0';
                        				break;
                    				}
                			}
                			strcpy(newString, printV);

                			int contador = 0;
                			for (int i = 0; $1[i] != '\0'; i++) {
                    				if ($1[i] == '}') {
                        				contador++;
                    				}
                			}

                			strcat(final, "(");
                			if (strlen(printV) == contador) {
                                    char * parts[] = {"\"", $1, "\"", ",", newString};
                                    int n = sizeof(parts)/sizeof(parts[0]);
                                    concatenateArray(final, parts, n);
                			} else if (strlen(printV) > contador) {
                    				char * parts[] = {"\"", $1, "{}", "\"", ",", newString};
                                    int n = sizeof(parts)/sizeof(parts[0]);
                                    concatenateArray(final, parts, n);
                            } else {
                    				printf("Error: valores no coinciden\n");
                			}
                			strcat(final, ");");

                			memset(printV, 0, strlen(printV));
                			free(newString);
            			}
                        free($1);
            			$$ = final;
        		}
        		free($1);
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
            char *final = malloc(strlen($1) * sizeof(char) + 1);

            memset(final, 0, strlen($1) * sizeof(char));
            char * parts[] = {$1};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            free($1);
            $$ = final;
        }
        | STRINGV {
            char *final = malloc(strlen($1) * sizeof(char) + 1);

            memset(final, 0, strlen($1) * sizeof(char));
            char * parts[] = {$1};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            free($1);
            $$ = final;	
        }
;



exp :   
        exp operand term {
            char *final = malloc(strlen($1) + strlen($2) + strlen($3) + 1);

            memset(final, 0, strlen($1) + strlen($2) + strlen($3) + 1);
            char * parts[] = {$1, $2, $3};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            
            free($1);
            free($2);
            free($3);
            $$ = final;
        }
        |term {
            size_t size = strlen($1) * sizeof(char) + 1;
            char * final = malloc(size);
            memset(final, 0, size);
            char * parts[] = {$1};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            free($1);
            $$ = final;
        }

;

term :
        atom {
            size_t size = strlen($1) * sizeof(char) + 1;
            char * final = malloc(size);
            memset(final, 0, size);
            char * parts[] = {$1};
            int n = sizeof(parts)/sizeof(parts[0]);
            concatenateArray(final, parts, n);
            free($1);
            $$ = final;
        }

        | LPAREN exp RPAREN {
            size_t size = strlen($2) + sizeof("()") + 1;
            char *final = malloc(size);
            memset(final, 0, size);

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
        |COLON {$$ = strdup(" : ");}
        |QUESTION {$$ = strdup(" ? ");}
;

atom :

    STRINGV {

		char *final = malloc(strlen($1) * sizeof(char) + 1);

		memset(final, 0, strlen($1) * sizeof(char));
        char * parts[] = {$1};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);
        free($1);
		$$ = final;
    }
	|prod STRINGV {
		char *final = malloc(strlen($2) * sizeof(char) + 1);

		memset(final, 0, strlen($2) * sizeof(char));
        char * parts[] = {$2};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);
        free($1);
        free($2);
		$$ = final;		

	}
    | values {
        char *final = malloc(strlen($1) * sizeof(char) + 1);

		memset(final, 0, strlen($1) * sizeof(char));
        char * parts[] = {$1};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);
        free($1);
		$$ = final;		
	}
    |STRINGV LSQUAREPAREN exp RSQUAREPAREN{

        char *final = malloc(strlen($1) * sizeof(char) + strlen($3) * sizeof(char) + sizeof("[]"));

		memset(final, 0, strlen($1) * sizeof(char) + strlen($3) * sizeof(char) + sizeof("[]"));
        char * parts[] = {$1, "[", $3, "]"};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);
        free($1);
		free($3);
		$$ = final;
    }
	

	| fun_cre{
        char *final = malloc(strlen($1) * sizeof(char) + sizeof("[]"));

		memset(final, 0, strlen($1) * sizeof(char)  + sizeof("[]"));
        char * parts[] = {$1};
        int n = sizeof(parts)/sizeof(parts[0]);
        concatenateArray(final, parts, n);
        free($1);
		$$ = final;
	}


;

%%

void yyerror(const char *msg) {
        fprintf(stderr, "Error: %s\n", msg);
        fprintf(stderr, "Error at line %d: %s\n", yylineno, msg);
        fprintf(stderr, "Syntax error: %s. Expected token: %d\n", msg, yychar);
        fprintf(stderr, "   %s\n", yytext);
}

char* resolveType(int parameter) {
    char* type = getType(parameter);
    if (strcmp(type, "struct") == 0) {
        return structType;
    } else {
        return type;
    }
}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Syntax:\n");
        printf("  For a file: ./translatorP <filenameC>\n");
        printf("  For multiple files: ./scanner -r <filenameC>\n");
        exit(-1);
    }

    InitializeListT(&typelist);
    InitializeListN(&queue);

    if (strcmp(argv[1], "-r") == 0) {
        if (argc < 3) {
            printf("ERROR: You must provide at least one file after the -r flag.\n");
            exit(-1);
        }

        int num_files = argc - 2;
        arraySize = num_files;

        headersArray = (char**)malloc(arraySize * sizeof(char*));
        if (headersArray == NULL) {
            printf("Error when allocating memory for headersArray\n");
            exit(1);
        }

        for (int i = 0; i < num_files; i++) {
            char route[100] = "";
            strcat(route, argv[i + 2]);

            headersArray[i] = (char*)malloc((strlen(route) + 1) * sizeof(char));
            if (headersArray[i] == NULL) {
                printf("Error when allocating memory for headersArray[%d]\n", i);
                exit(1);
            }
            strcpy(headersArray[i], route);
            
            char buffer[256]; 
            strcpy(buffer, route);

            char* lastSlash = strrchr(buffer, '/');
            if(lastSlash != NULL) {
                *lastSlash = '\0';
                strcat(preSlash, buffer);
            }

        }

        #pragma omp parallel for shared(headersArray, arraySize) 
        for (int i = 0; i < arraySize; i++) {
            YY_BUFFER_STATE bufferState = NULL;

            #pragma omp critical
            {
                bufferState = yy_current_buffer();
                yy_flush_buffer(bufferState);
                yyin = fopen(headersArray[i], "r");
                if (yyin == NULL) {
                    printf("ERROR: Could not open the file %s.\n", headersArray[i]);
                    continue;
                }
                bufferState = yy_create_buffer(yyin, 1024);
                yy_switch_to_buffer(bufferState);
            }

            strcpy(filePath, headersArray[i]);
            yyparse();

            #pragma omp critical
            {
                fclose(yyin);
            }
            yy_delete_buffer(bufferState);
        }
    } 
    else {
        char route[100] = "";
        strcat(route, argv[1]);
        strcpy(filePath, route);

        yyin = fopen(route, "r");
        if (yyin == NULL) {
            printf("ERROR: Could not open the file %s.\n", route);
            exit(1);
        }
        yyparse();
        fclose(yyin);
    }
    
    return 0;
}

