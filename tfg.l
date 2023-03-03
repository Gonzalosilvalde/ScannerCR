%{
#include <stdlib.h>
#include <math.h>
#include "tfg.tab.h"
%}

%option yylineno

blank ^[ \t]*\r?\n
commentwl ^[ \t]*#.*\r?\n
comentario "//"
identacion ^[ \t]+
notidented ^[^ \t\n]+
newline \r?\n
eof "<<EOF>>"
ignorespaces [ \t]
and "and"
break "break"
else "else"
for "for"
if "if"
not "not"
or "or"
return "return"
while "while"
true "True"
false "False"
cout "cout"
stringval \"[A-Z]+|[a-z]+\"
varname [a-zA-Z_][a-zA-Z0-9_]*
int "int"
intnum -?[0-9]+
float "float"
floatnum -?[0-9]*"."[0-9]*
void "void"
bool "bool"
equal "="
add "+"
minus "-"
mult "*"
pow "pow"
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
opencurlybracket "{"
closecurlybracket "}"
comma ","
doublepoint ":"
semicolon ";"
percentage "%"
hashtag "#"
hinclude "#include"

%%
{blank} {;/* Skip blank lines */ }

{commentwl} {;/* Skip whole-line comments. */}

{comentario}  {return COMENTARIO1;/* Skip comments on the same line as a statement. */}

{identacion}  {;}

{notidented}  {;}

{newline} {return NEWLINE;}

{ignorespaces}  {;/* Ignore spaces that haven't been handled above. */ }

{eof} {return ENDOFFILE;}

{and} {return AND;}

{break} {return BREAK;}

{else}  {return ELSE;}

{for} {return FOR;}

{if}  {return IF;}

{not} {return NOT;}

{or}  {return OR;}

{return}  {return RETURN;}

{while} {return WHILE;}

{true}  {return TRUEVAL;}

{false} {return FALSEVAL;}

{cout} {return COUT;}

{void} {return VOID;}

{bool} {return BOOL;}

{int} {return INT;}

{float} {return FLOAT;}

{pow} {return POW;} 

{stringval} {yylval.string=strdup(yytext);return STRINGVAL;}

{varname}  {yylval.string=strdup(yytext);return VARNAME;}

{floatnum} {yylval.valFloat =(float)atof(yytext);return FLOATNUM;}

{intnum} {yylval.valInt = atoi(yytext);return INTNUM;}

{equal} {return EQUAL;}

{add} {return ADD;}

{minus} {return MINUS;}

{mult}  {return MULT;}

{divide}  {return DIVIDE;}

{equalb}  {return EQUALB;}

{notequal}  {return NOTEQUAL;}

{bigger}  {return BIGGER;}

{biggereq}  {return BIGGEREQ;}

{less}  {return LESS;}

{lesseq}  {return LESSEQ;}

{open}  {return OPEN;}

{close} {return CLOSE;}

{openbracket} {return OPENBRACKET;}

{closebracket} {return CLOSEBRACKET;}

{opencurlybracket} {return OPENCURLYBRACKET;}

{closecurlybracket} {return CLOSECURLYBRACKET;}

{comma}  {return COMMA;}

{doublepoint} {return DOUBLEPOINT;}

{semicolon} {return SEMICOLON;}

{percentage}  {return PERCENTAGE;}

{hashtag} {return HASHTAG;}

{hinclude} {return HINCLUDE;}

. {;}
%%