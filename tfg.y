%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int yylex(void);
void yyerror(char *);
%}

%union {
    int ival;
    double dval;
    char *sval;
}

%token <sval> TK_IDENTIFICADOR TK_CADENA
%token <ival> TK_ENTERO
%token <double> TK_DOUBLE
%token TK_POW
%token TK_SUMA TK_RESTA TK_MULTIPLICACION TK_DIVISION TK_MODULO
%token TK_IGUAL TK_DIFERENTE TK_MENOR TK_MAYOR TK_MENOR_IGUAL TK_MAYOR_IGUAL
%token TK_AND TK_OR TK_NOT
%token TK_IF TK_ELSE TK_WHILE TK_FOR TK_RETURN
%token TK_INT TK_CHAR TK_VOID

%start programa

%%

programa : /* Regla principal */ 
          declaraciones
          ;

declaraciones : /* Regla para declaraciones de variables o funciones */
                declaracion
              | declaraciones declaracion
              ;

declaracion : tipo lista_variables ';'
            | tipo TK_IDENTIFICADOR '(' parametros ')' bloque
            ;

tipo : TK_INT
     | TK_DOUBLE
     | TK_CHAR
     | TK_VOID
     ;

lista_variables : TK_IDENTIFICADOR
                | lista_variables ',' TK_IDENTIFICADOR
                ;

parametros : /* Regla para lista de parámetros de una función */
             /* Esta regla es opcional, se puede declarar una función sin parámetros */
             tipo TK_IDENTIFICADOR
           | parametros ',' tipo TK_IDENTIFICADOR
           ;

bloque : '{' declaraciones_lista '}' /* Regla para un bloque de código */
       ;

declaraciones_lista : /* Regla para declaraciones dentro de un bloque */
                     /* Esta regla es opcional, se puede tener un bloque vacío */
                     declaracion_lista
                   | declaraciones_lista declaracion_lista
                   ;

declaracion_lista : tipo lista_variables ';' /* Regla para declaraciones de variables */
                  | sentencia                     /* Regla para sentencias */
                  ;

sentencia : asignacion ';'
          | expresion ';'
          | sentencia_if
          | sentencia_while
          | sentencia_for
          | sentencia_return ';'
          | bloque
          ;

asignacion : TK_IDENTIFICADOR '=' expresion
           | TK_IDENTIFICADOR '+' '=' expresion
           | TK_IDENTIFICADOR '-' '=' expresion
           | TK_IDENTIFICADOR '*' '=' expresion
           | TK_IDENTIFICADOR '/' '=' expresion
           | TK_IDENTIFICADOR '%' '=' expresion
           | TK_IDENTIFICADOR TK_POW '=' expresion
           ;

expresion : expresion '+' expresion
          | expresion '-' expresion
          | expresion '*' expresion
          | expresion '/' expresion
          | expresion '%' expresion
          | expresion TK_POW expresion
          | '(' expresion ')'
          | TK_ENTERO
          | TK_DOUBLE
          | TK_IDENTIFICADOR
          | TK_CADENA
          | expresion TK_IGUAL expresion
          | expresion TK_DIFERENTE expresion
          | expresion TK_MENOR expresion
          | expresion TK_MAYOR expresion
          | expresion TK_MENOR_IGUAL expresion

sentencia_if : TK_IF '(' expresion ')' bloque sentencia_else
             ;

sentencia_else : /* Regla opcional para sentencia else */
                /* Esta regla permite tener una sentencia if sin sentencia else */
                /* o tener una sentencia if con sentencia else */
                /* Esta regla puede estar vacía */
                /* Esta regla solo se aplica si se detecta un token TK_ELSE */
                /* por lo que se agrega una regla para evitar conflictos con else if */
                /* en la regla sentencia_if */
                | TK_ELSE bloque
                | TK_ELSE sentencia_if
                ;

sentencia_while : TK_WHILE '(' expresion ')' bloque
                ;

sentencia_for : TK_FOR '(' for_inicial ';' for_condicion ';' for_incremento ')' bloque
              ;

for_inicial : asignacion
            | declaracion ';' /* Declaración opcional */
            ;

for_condicion : /* Expresión opcional */
                /* Si no se especifica una expresión, la condición siempre será verdadera */
                /* La expresión se agrega como parte de la regla para evitar conflictos */
                /* con otras reglas que puedan tener una expresión */
               expresion
             ;

for_incremento : expresion
               ;

sentencia_return : TK_RETURN expresion /* Regla para retorno de valores */
                 | TK_RETURN           /* Regla para retorno sin valor */
                 ;

%%

void yyerror(char *s) {
    printf("%s\n", s);
}

int main(int argc, char *argv[]) {
    yyparse();
    return 0;
}

