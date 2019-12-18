%{
#include <stdio.h>
int yylex();
void yyerror(char * s);	
%}

%token CLASS VOID IF ELSE BREAK CONTINUE FOR RETURN
%token ID CHARLIT STRLIT INT BOOL NUM HEX CHAR
%token AND OR MINUSEQ PLUSEQ LTEQ GTEQ NOTEQ EQEQ
%token CALLOUT FALSE TRUE COMMENTS

%left AND OR 
%left '<' '>' 
%left LTEQ GTEQ 
%left EQEQ NOTEQ
%left '+' '-'
%left '*' '/'


%% 
program: CLASS ID '{' body '}'

body: | field_dec body | method_dec body

field_dec: type var ';'

var: variable | var ',' variable

variable: ID | ID '[' int_lit ']'

method_dec: type ID '(' argums ')' block | VOID ID '(' argums ')' block 

argums: | type ID | argums ',' type ID

block: '{' var_dec statements '}'

var_dec: | var_decl | var_dec

var_decl: type vars ';'

vars: ID | vars ',' ID

type: INT | BOOL

statements: | stment statements

stment: location assign_opr expr ';'
          | method_call ';'
          | IF '(' expr ')' block
          | IF '(' expr ')' block ELSE block
          | CONTINUE ';'
          | BREAK ';'
          | FOR ID '=' expr ',' expr block
          | RETURN expr ';'
          | RETURN ';'
          | block
assign_opr: '=' | PLUSEQ | MINUSEQ
method_call: method_name'(' method_argu ')'
               | CALLOUT '(' string_lit ',' callout  ')'
               | CALLOUT '(' string_lit ')'
method_name: ID
callout: call_args | callout ',' call_args
call_args: expr | string_lit
method_argu: | expr | method_argu ',' expr

expr: location | method_call
               | literal
               | expr bin_opr expr
               | '-' expr
               | '+' expr
               | '!' expr
               | '(' expr ')'
bin_opr: ari_opr | rel_opr | equ_opr | con_opr

ari_opr: '+' | '-' | '*' | '%' | '/'

rel_opr: '<' | '>' | LTEQ | GTEQ

equ_opr: EQEQ | NOTEQ

con_opr: AND | OR

location: ID | ID '[' expr ']'

literal: int_lit | char_lit | bool_lit

int_lit: NUM | HEX

bool_lit: TRUE | FALSE

char_lit: CHARLIT

string_lit: STRLIT

%%

int main(int argc, char **argv)
{
	yyparse();
	printf("Parsing Over\n");
}

void yyerror(char *s)
{
	fprintf(stderr, "error: %s\n", s);
}