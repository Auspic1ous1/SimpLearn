%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

int line_number = 1;
int column_number = 1;
%}

DIGIT       [0-9]
LETTER      [a-zA-Z]
IDENTIFIER  {LETTER}({LETTER}|{DIGIT}|_)*
INTEGER     {DIGIT}+
FLOAT       {DIGIT}+\.{DIGIT}+
STRING      \"([^\"\\]|\\.)*\"
WHITESPACE  [ \t]+
NEWLINE     \n

%%

"program"       { return PROGRAM; }
"var"           { return VAR; }
"begin"         { return BEGIN_BLOCK; }
"end"           { return END_BLOCK; }
"int"           { return INT_TYPE; }
"float"         { return FLOAT_TYPE; }
"string"        { return STRING_TYPE; }
"if"            { return IF; }
"then"          { return THEN; }
"else"          { return ELSE; }
"endif"         { return ENDIF; }
"while"         { return WHILE; }
"do"            { return DO; }
"endwhile"      { return ENDWHILE; }
"for"           { return FOR; }
"to"            { return TO; }
"step"          { return STEP; }
"endfor"        { return ENDFOR; }
"print"         { return PRINT; }
"read"          { return READ; }

"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MULTIPLY; }
"/"             { return DIVIDE; }
"%"             { return MODULO; }
":="            { return ASSIGN; }
"="             { return EQUALS; }
"!="            { return NOT_EQUALS; }
"<"             { return LESS_THAN; }
"<="            { return LESS_EQUAL; }
">"             { return GREATER_THAN; }
">="            { return GREATER_EQUAL; }
"and"           { return AND; }
"or"            { return OR; }
"not"           { return NOT; }

"("             { return LPAREN; }
")"             { return RPAREN; }
";"             { return SEMICOLON; }
","             { return COMMA; }
":"             { return COLON; }

{IDENTIFIER}    { yylval.str_val = strdup(yytext); return IDENTIFIER; }
{INTEGER}       { yylval.int_val = atoi(yytext); return INTEGER_LITERAL; }
{FLOAT}         { yylval.float_val = atof(yytext); return FLOAT_LITERAL; }
{STRING}        { yylval.str_val = strdup(yytext); return STRING_LITERAL; }

"//".*          { /* ignore comments */ }
"/*"([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*"\*/"   { /* ignore comments */ }
{WHITESPACE}    { /* ignore space */} 
{NEWLINE}       { line_number++; column_number = 1; }

.               { fprintf(stderr, "Illegal character '%s'\n", yytext); return ERROR_TOKEN; }

%%

int yywrap() { return 1; }
