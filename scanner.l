%{
#include <stdlib.h>
#include <math.h>
#include "scanner.tab.h"
%}

letter [a-zA-Z]
digit [0-9]
stringquote \"[^\'\n]*\"
cs #{digit}+

%%
int {return INTEGER;}
float {return FLOAT;}
string {return STRING;}
bool {return BOOLEAN;}
char {return CHAR;}
true {return TRUEVAL;}
false {return FALSEVAL;}
(\-)?{digit}+ {yylval.valString = strdup(yytext); return INTNUM;}
(\-)?{digit}+(\.{digit}+)?([eE][+\-]{digit}+)? {yylval.valString = strdup(yytext); return REALNUM;}
"#include" {return PROGRAM;}
VAR {return VAR;}
(?i:value) {return VALUE;}
\( {return LPAREN;}
\) {return RPAREN;}
"//"[^\/\n]*\n {yylval.valString = strdup(yytext); return COMMENTLINE;}
"/*"[^\{\}]*"*/" {yylval.valString = strdup(yytext); return MULTILINE;}
\{ {return OPENCURLYBRACKET;}
\} {return CLOSECURLYBRACKET;}
\= {return EQ;}
\: {return COLON;}
\; {return SEMICOLON;}
\, {return COMMA;}
\. {return DOT;}
! {return EX;}
(?i:if) {return IF;}
(?i:then) {return THEN;}
(?i:else) {return ELSE;}
and {return AND;}
or {return OR;}
\< {return LOWER;}
\> {return HIGHER;}
(?i:for) {return FOR;}
(?i:do) {return DO;}
(?i:while) {return WHILE;}
\+ {return PLUS;}
\- {return HYPHEN;}
\* {return PROD;}
\/ {return DIV;}
div {return DIVINT;}
mod {return MOD;}
(?i:cout) {return WRITE;}
(?i:endl) {return ENDL;}
stringquote {return STRINGQUOTE;}
(?i:return) {return RETURN;}
"#define" {return DEFINE;}
const {return CONST;}
({letter}|\_)({letter}|{digit}|\_)* {yylval.valString = strdup(yytext); return STRINGV;}
({stringquote}|{cs})+ {yylval.valString = strdup(yytext); return QUOTESTRING;}
\n ;
. ;
%%