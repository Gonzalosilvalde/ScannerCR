%{
#include <stdlib.h>
#include <math.h>
#include "scannerCR.tab.h"
 //int i = 0;
%}

letter [a-zA-Z]
digit [0-9]
stringquote   (["'][^"'\n]*["'])
cs #{digit}+
realnum (\-)?{digit}+(\.{digit}+)?([eE][+\-]{digit}+)?
intnum (\-)?{digit}+

%%
int {return INTEGER;}//32
short {return SHORT;}//16
long {return LONG;}//64
"long long" {return LONG_LONG;}//64
"unsigned long long" {return UNSIGNED_LONG_LONG;}
"unsigned int" {return UNSIGNED_INT;}
"unsigned short" {return UNSIGNED_SHORT;}
"unsigned long" {return UNSIGNED_LONG;}
float {return FLOAT;}//32
double {return DOUBLE;}//64
string {return STRING;}
bool {return BOOLEAN;}
void {return VOID;}
printf {return PRINTF;}
scanf {return SCANF;}
char {return CHAR;}
true {return TRUEVAL;}
false {return FALSEVAL;}
{intnum} {yylval.valString = strdup(yytext); return INTNUM;}
{realnum} {yylval.valString = strdup(yytext); return REALNUM;}
"#include" {return PROGRAM;}
VAR {return VAR;}
(?i:value) {return VALUE;}
\( {return LPAREN;}
\) {return RPAREN;}
\[ {return LSQUAREPAREN;}
\] {return RSQUAREPAREN;}
struct {return STRUCT;}
"//"[^\/\n]*\n {yylval.valString = strdup(yytext); return COMMENTLINE;}
"/*"[^\{\}]*"*/" {yylval.valString = strdup(yytext); return MULTILINE;}
\{ {return OPENCURLYBRACKET;}
\} {return CLOSECURLYBRACKET;}
\= {return EQ;}
\: {return COLON;}
\; {return SEMICOLON;}
\, {return COMMA;}
\. {return DOT;}
\? {return QUESTION;}
! {return EX;}
if {return IF;}
(?i:then) {return THEN;}
(?i:else) {return ELSE;}
switch {return SWITCH;}
case {return CASE;}
default {return DEFAULT;}
&& {return AND;}//& {return AMPERSAND;}

"||" {return OR;}
\< {return LOWER;}
\> {return HIGHER;}
(?i:for) {return FOR;}
(?i:do) {return DO;}
(?i:while) {return WHILE;}
\+ {return PLUS;}
\- {return HYPHEN;}
\* {return PROD;}
\% {return PERCENT;}
\/ {return DIV;}
div {return DIVINT;}
mod {return MOD;}
(?i:cout) {return WRITE;}
(?i:endl) {return ENDL;}
stringquote {return STRINGQUOTE;}
(?i:return) {return RETURN;}
"#define" {return DEFINE;}
const {return CONST;}

({letter}|\_|&)({letter}|{digit}|\_)*  {
    	yylval.valString = strdup(yytext);
        return STRINGV;
}
({stringquote}|{cs})+ {
	yylval.valString = strdup(yytext); 
	return QUOTESTRING;
}
\n {
    yylineno++;
} 

. ;
%%
YY_BUFFER_STATE yy_current_buffer(){
    return YY_CURRENT_BUFFER;
}


