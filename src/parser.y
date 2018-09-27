%{
#include <stdio.h>	
%}

%token ID
%left '+' '-'
%left '*' '/'

%%

expr : '(' expr ')'
	 |  expr '+' expr
	 |  expr '-' expr
	 |  expr '*' expr
	 |  expr '/' expr
	 |  ID
	 ;

expr : location
	 | method_call
	 | literal
	 | expr bin_op expr
	 | '-' expr
	 | '!' expr
	 | '(' expr ')'
	 ;
location : id
		 | id '[' expr ']'
		 ;
literal : int_literal
		| char_literal
		| bool_literal
		;
bin_op : arith_op
		| rel_op
		| eq_op
		| cond_op
		;
arith_op : '+'
		 |	'-'
		 |	'*'
		 |	'/'
		 |	'%'
		 ;
rel_op : '<'
		| '>'
		| '<='
		| '>='
		;
eq_op : '=='
		| '!='
		;
cond_op : '&&'
		| '||'
		;
id : ID 
	| ID NUM
	;


%%

main(int argc, char **argv)
{
	yyparse();
	printf("Parsing Over\n");
}

yyerror(char *s)
{
	fprintf(stderr, "error: %s\n", s);
}