%{

#include "quad.h"
#include "list.h"
#include "symbol_table.h"
#include "yacc_util.h"
#include "yacc.tab.h"
void yyerror (char *s);

%}

%option noyywrap
%option noinput
%option nounput

NB (0|[1-9][0-9]*)
COMM \(\*([^*]|\*+[^*)]|\n)*\*+\)
ID [_a-zA-Z][_a-zA-Z0-9]*
STR \"[_a-zA-Z0-9\\ ]*\"

%%

"program"    {return PROGRAM;}
"begin"      {return BEG;}
"end"        {return END;}
"write"      {return WRITE;}
"read"       {return READ;}

"function"   {return FUNCTION;}
"array"      {return ARRAY;}
"of"         {return OF;}

":"          {return TWO_POINT;}
";"          {return SEP;}
","          {return COMMA;}
".."         {return SEPIND;}

"var"        {return VAR;}
"bool"       {return BOOL;}
"int"        {return INT;}
"unit"       {return UNIT;}
"string"     {return STRING;}

"while"      {return WHILE;}
"do"         {return DO;}
"if"         {return IF;}
"then"       {return THEN;}
"else"       {return ELSE;}
"or"         {return OR;}
"xor"        {return XOR;}
"and"        {return AND;}
"not"        {return NOT;}
">"          {return SUP;}
">="         {return SUPEQ;}
"<"          {return INF;}
"<="         {return INFEQ;}
"="          {return EQ;}
"<>"         {return DIFF;}

":="         {return AFFECT;}
"+"          {return PLUS;}
"-"          {return MOINS;}
"*"          {return FOIS;}
"/"          {return DIV;}
"^"          {return POW;}
"("          {return OPAR;}
")"          {return CPAR;}
"["          {return yytext[0];}
"]"          {return yytext[0];}

"true"       {return TRUE;}
"false"      {return FALSE;}
{NB}         {yylval.intval = atoi(yytext); return NOMBRE;}
{ID}         {yylval.strval = strdup(yytext); return IDENT;}
{STR}        {yylval.strval = strdup(yytext); return STR;}


[ ]          {;}
[\n\r]       {;}
{COMM}       {printf("%s\n", yytext);}
.            {printf("%c\n", yytext[0]);yyerror("regexp inconnu");}
%%

