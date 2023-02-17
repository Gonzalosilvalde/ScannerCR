%{
#include <stdlib.h>
#include <math.h>
#include "tfg.tab.h"
%}

%%
[ \t\n]  /* Ignorar espacios en blanco y saltos de línea */

"+" {return '+';}
"-" {return '-';}
"*" {return '*';}
"pow"   { return TK_POW; }
"/" {return '/';}
"%" {return '%';}

"=="    { return TK_IGUAL; }
"!="    { return TK_DIFERENTE; }
"<"     { return TK_MENOR; }
"<="    { return TK_MENOR_IGUAL; }
">"     { return TK_MAYOR; }
">="    { return TK_MAYOR_IGUAL; }

int     { return TK_INT; }
double  { return TK_DOUBLE; }
char    { return TK_CHAR; }
void    { return TK_VOID; }
if      { return TK_IF; }
else    { return TK_ELSE; }
while   { return TK_WHILE; }
for     { return TK_FOR; }
return  { return TK_RETURN; }

[a-zA-Z][a-zA-Z0-9_]*    { yylval.sval = strdup(yytext); return TK_IDENTIFICADOR; }
[0-9]+                  { yylval.ival = atoi(yytext); return TK_ENTERO; }
[0-9]+"."[0-9]+         { yylval.dval = atof(yytext); return TK_DOUBLE; }
\".*\"                  { yylval.sval = strdup(yytext); return TK_CADENA; }

.       { printf("Caracter desconocido: %c\n", yytext[0]); }
