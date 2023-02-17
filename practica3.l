%{
#include <stdlib.h>
#include "practica3.tab.h"
%}

%option yylineno

blank ^[ \t]*\r?\n
commentwl ^[ \t]*#.*\r?\n
comentario #.*$
identacion ^[ \t]+
notidented ^[^ \t\n]+
newline \r?\n
eof <<EOF>>
ignorespaces [ \t]
and "and"
break "break"
def "def"
elif "elif"
else "else"
for "for"
if "if"
not "not"
or "or"
return "return"
while "while"
true "True"
false "False"
print "print"
/*Dos posibles notaciones para un valor tipo string "string" o 'string', ambas soportadas por python*/
stringval1 \"[^\t\n]*\"
stringval2 '[^\t\n]*'
varname [a-zA-Z_][a-zA-Z0-9_]*
float -?[0-9]*"."[0-9]*
int -?[0-9]+
equal "="
add "+"
minus "-"
mult "*"
pow "**"
divide "/"
equalb "=="
notequal "!="
bigger ">"
biggereq ">="
less "<"
lesseq "<="
open "("
close ")"
openbracket "["
closebracket "]"
comma ","
doublepoint ":"
in "in"
range "range"
percentage "%"

%%

blank {;/* Skip blank lines */ }

commentwl {;/* Skip whole-line comments. */}

comentario  {;/* Skip comments on the same line as a statement. */}

identacion  {;}

notidented  {;}

newline {return NEWLINE;}

eof {return ENDOFFILE;}

ignorespaces  {;/* Ignore spaces that haven't been handled above. */ }

and {return AND;}

break {return BREAK;}

def {return DEF;}

elif  {return ELIF;}

else  {return ELSE;}

for {return FOR;}

if  {return IF;}

not {return NOT;}

or  {return OR;}

return  {return RETURN;}

while {return WHILE;}

true  {return TRUEVAL;}

false {return FALSEVAL;}

print {return PRINT;}

stringval1 {yylval.string=strdup(yytext);return STRINGVAL1;}

stringval2 {yylval.string=strdup(yytext);return STRINGVAL2;}

varname  {yylval.string=strdup(yytext);return VARNAME;}

float {yylval.valFloat =(float)atof(yytext);return FLOAT;}

int {yylval.valInt = atoi(yytext);return INT;}

equal {return EQUAL;}

add {return ADD;}

minus {return MINUS;}

mult  {return MULT;}

pow {return POW;}

divide  {return DIVIDE;}

equalb  {return EQUALB;}

notequal  {return NOTEQUAL;}

bigger  {return BIGGER;}

biggereq  {return BIGGEREQ;}

less  {return LESS;}

lesseq  {return LESSEQ;}

open  {return OPEN;}

close {return CLOSE;}

openbracket {return OPENBRACKET;}

closebracket {return CLOSEBRACKET;}

comma  {return COMMA;}

doublepoint {return DOUBLEPOINT;}

in  {return IN;}

range   {return RANGE;}

percentage  {return PERCENTAGE;}

. {;}
%%
