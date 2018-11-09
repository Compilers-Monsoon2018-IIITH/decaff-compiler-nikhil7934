/* $Id$ -*- mode: c++ -*- */
/** \file parser.yy Contains the example Bison parser source */

%{ /*** C/C++ Declarations ***/

#include <stdio.h>
#include <string>
#include <vector>
#include "ast.h"
#include "scanner.h"
#include "driver.h"

%}

/*** yacc/bison Declarations ***/

/* Require bison 2.3 or later */
%require "2.3"

/* add debug output code to generated parser. disable this for release
 * versions. */
%debug

/* start symbol is named "start" */
%start line

/* write out a header file containing the token defines */
%defines

/* use newer C++ skeleton file */
%skeleton "lalr1.cc"

/* namespace to enclose parser in */
%name-prefix="decaf"

/* set the parser's class identifier */
%define "parser_class_name" "Parser"

/* keep track of the current position within the input */
%locations
%initial-action
{
    // initialize the initial location object
    @$.begin.filename = @$.end.filename = &driver.streamname;
};

/* The driver is passed by reference to the parser and to the scanner. This
 * provides a simple but effective pure interface, not relying on global
 * variables. */
%parse-param { class Driver& driver }

/* verbose error messages */
%error-verbose

/*** BEGIN EXAMPLE - Change the example grammar's tokens below ***/

%union
{
	int integerVal;
    class ASTnode* astnode;
    std::string *sval;
    class ProgramASTnode* prnode;
	class VarASTnode* varnode;
	class VarDeclnode* vardeclnode;
	class VarDeclsnode* vardeclsnode;
	class UnaryASTnode* unarynode;
	class LocationASTnode* locationnode;
	class BoolLitASTnode* boolnode;
	class CharLitASTnode* charnode;
	class IntLitASTnode* intnode;
	class FieldDeclnode* fieldnode;
	class VariableASTnode* variablenode;
	class VariablesASTnode* variablesnode;
	class MethodNameASTnode* methodnamenode;
	class StringLitASTnode* stringnode;
	class CalloutargASTnode* calloutargnode;
	class CalloutASTnode* calloutnode;
	class MethodargASTnode* methodargnode;
	class ArgumentsASTnode* argumentnode;
	class MethodcallASTnode* methodcallnode;
	class StatementlocASTnode* statlocnode;
	class MethodstatASTnode* methodstatnode;
	class StatementifASTnode* ifnode;
	class StatementifelseASTnode* ifelsenode;
	class StatementforASTnode* fornode;
	class StatementreturnexprASTnode* returnnode;
	class StatementterminateASTnode* termnode;
	class StatementblockASTnode* blocknode;
	class StatementsASTnode* statementsnode;
	class BlockASTnode* block;
	class MethoddeclASTnode* method_declnode;
	class FunctionASTnode* functionnode;
	class Statement* statenode;
	class Expr* expnode;
}

%type <astnode>	line expr 
%type <prnode> program
%type <varnode> vars 
%type <locationnode> location
%type <vardeclnode> var_declaration
%type <vardeclsnode> var_declarations
%type <boolnode> bool_literal
%type <charnode> char_literal
%type <intnode> int_literal
%type <fieldnode> field_decl
%type <variablenode> variable
%type <variablesnode> var
%type <methodnamenode> method_name
%type <stringnode> string_literal
%type <calloutargnode> calloutarg
%type <calloutnode> callout
%type <methodargnode> method_arg
%type <argumentnode> arguments
%type <methodcallnode> method_call
%type <statlocnode> statement1
%type <methodstatnode> statement2
%type <ifnode> statement3
%type <ifelsenode> statement4
%type <fornode> statement5
%type <returnnode> statement6
%type <termnode> statement7
%type <blocknode> statement8
%type <statementsnode> statements
%type <block> block
%type <method_declnode> method_decl
%type <functionnode> function
%type <statenode> statement
%type <expnode> expr

//%destructor { delete $$; } expr

 /*** END EXAMPLE - Change the example grammar's tokens above ***/

%{

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex

%}

%token END 0
%token EOL
%token<integerVal> NUM HEX
%token<sval> ID INT BOOLEAN CHAR
%token<sval> CALLOUT TRUE FALSE CHARLIT STRLIT
%token<sval> LFB RFB SEMICOL COMMA LB RB LSB RSB PROGRAM
%token<sval> CONTINUE IF FOR RETURN BREAK ELSE CLASS VOID
%token<sval> PLUS MINUS MUL EQ DIV LT GT MOD NOT
%token<sval> AND OR EQEQ NOTEQ GTEQ LTEQ PLUSEQ MINUSEQ
%left PLUS MINUS
%left MUL DIV
%left AND OR 
%left LT GT 
%left LTEQ GTEQ 
%left EQEQ NOTEQ
%left LT LTEQ
%left GT GTEQ

%%

program : CLASS PROGRAM LFB function RFB {$$=new ProgramASTnode($4);driver.ast.pRoot=$$;}

var : variable 					{ $$ = new VariablesASTnode();$$->push_back($1);}
	| var COMMA variable		{ $$ = $1;$$->push_back($3);}

variable : ID 						{ $$ = new VariableASTnode(*$1);}
		 | ID LSB int_literal RSB	{ $$ = new VariableASTnode(*$1,$3);}

vars : ID 						{ $$ = new VarASTnode();$$->push_back(*$1);}
	 | vars COMMA ID			{ $$ = $1;$$->push_back(*$3);}

var_declaration : INT vars SEMICOL {$$ = new VarDeclnode(*$1,$2,";");}
				| BOOLEAN vars SEMICOL {$$ = new VarDeclnode(*$1,$2,";");}

var_declarations : 					{$$ = new VarDeclsnode();}	
		 		 | var_declaration var_declarations {$2->push_back($1);$$ = $2;}
				 

location : ID 						{ $$ = new LocationASTnode(*$1);}
		 | ID LSB expr RSB			{ $$ = new LocationASTnode(*$1,$3);}

literal :int_literal				{$$ = $1;}
		|bool_literal				{$$ = $1;}
		|char_literal				{$$ = $1;}

int_literal : NUM 					{$$ = new IntLitASTnode($1);}
 			| HEX					{$$ = new IntLitASTnode($1);}

bool_literal : TRUE 				{$$ = new BoolLitASTnode(true);}
			 | FALSE				{$$ = new BoolLitASTnode(false);}

char_literal : CHARLIT				{$$ = new CharLitASTnode(*$1);}


expr : location						{ $$ = new Expr($1); }
	 | literal						{ $$ = new Expr($1);}
	 | method_call					{ $$ = new Expr($1);}
	 | expr PLUS expr				{ $$ = new Expr(new BinaryASTnode("+", $1, $3)); }
	 | expr MINUS expr				{ $$ = new Expr(new BinaryASTnode("-", $1, $3)); }
	 | expr MUL expr				{ $$ = new Expr(new BinaryASTnode("*", $1, $3)); }
	 | expr MOD expr				{ $$ = new Expr(new BinaryASTnode("%", $1, $3)); }
	 | expr DIV expr				{ $$ = new Expr(new BinaryASTnode("/", $1, $3)); }
	 | expr LT expr					{ $$ = new Expr(new BinaryASTnode("<", $1, $3)); }
	 | expr GT expr					{ $$ = new Expr(new BinaryASTnode(">", $1, $3)); }
	 | expr LTEQ expr				{ $$ = new Expr(new BinaryASTnode("<=", $1, $3)); }
	 | expr GTEQ expr				{ $$ = new Expr(new BinaryASTnode(">=", $1, $3)); }
	 | expr EQEQ expr				{ $$ = new Expr(new BinaryASTnode("==", $1, $3)); }
	 | expr NOTEQ expr				{ $$ = new Expr(new BinaryASTnode("!=", $1, $3)); }
	 | expr AND expr				{ $$ = new Expr(new BinaryASTnode("&&", $1, $3)); }
	 | expr OR expr					{ $$ = new Expr(new BinaryASTnode("||", $1, $3)); }
	 | MINUS expr					{ $$ = new Expr(new UnaryASTnode("-", $2)); }
	 | NOT expr						{ $$ = new Expr(new UnaryASTnode("!", $2)); }
	 | LB expr RB					{ $$ = new Expr($2);}

field_decl : INT var SEMICOL		{ $$ = new FieldDeclnode(*$1,$2,";");}
			| BOOLEAN var SEMICOL	{ $$ = new FieldDeclnode(*$1,$2,";");}

method_name : ID					{$$ = new MethodNameASTnode(*$1);}

string_literal : STRLIT 			{$$=new StringLitASTnode(*$1);}

calloutarg : expr 								{$$ = new CalloutargASTnode($1);}
		   | string_literal						{$$ = new CalloutargASTnode($1);}

callout : calloutarg 						{ $$ = new CalloutASTnode();$$->push_back($1);}
		| callout COMMA calloutarg			{ $$ = $1;$$->push_back($3);}

method_arg : 								{$$ = new MethodargASTnode();}
			 | expr 						{$$ = new MethodargASTnode();
			 								 $$->push_back($1);}
			 | method_arg COMMA expr		{$$ = $1;$$->push_back($3);}

arguments : 									{$$ = new ArgumentsASTnode();}
			| INT ID							{$$ = new ArgumentsASTnode(*$1,*$2);}
			| BOOLEAN ID						{$$ = new ArgumentsASTnode(*$1,*$2);}
			| arguments COMMA INT ID			{$$ = new ArgumentsASTnode(*$3,*$4);
													$$->push_back($1);}
		    | arguments COMMA BOOLEAN ID		{$$ = new ArgumentsASTnode(*$3,*$4);
		    										$$->push_back($1);}

method_call : method_name LB method_arg RB				{$$ = new MethodcallASTnode($1,$3);}
		   | CALLOUT LB string_literal COMMA callout RB	{$$ = new MethodcallASTnode(*$1,$3,$5);}
		   | CALLOUT LB string_literal RB				{$$ = new MethodcallASTnode(*$1,$3);}

statement : statement1				{$$ = new Statement($1);}
			|statement2				{$$ = new Statement($1);}
			|statement3				{$$ = new Statement($1);}
			|statement4				{$$ = new Statement($1);}
			|statement5				{$$ = new Statement($1);}
			|statement6				{$$ = new Statement($1);}
			|statement7				{$$ = new Statement($1);}
			|statement8				{$$ = new Statement($1);}

statement1 :location EQ expr SEMICOL		{$$ = new StatementlocASTnode($1,*$2,$3);}
		  | location PLUSEQ expr SEMICOL	{$$ = new StatementlocASTnode($1,*$2,$3);}
		  | location MINUSEQ expr SEMICOL	{$$ = new StatementlocASTnode($1,*$2,$3);}

statement2 :method_call SEMICOL				{$$ = new MethodstatASTnode($1);}

statement3 :IF LB expr RB block				{$$ = new StatementifASTnode($3,$5);}

statement4 :IF LB expr RB block ELSE block	{$$ = new StatementifelseASTnode($3,$5,$7);}

statement5 :FOR ID EQ expr COMMA expr block	{$$ = new StatementforASTnode(*$2,$4,$6,$7);}

statement6 :RETURN expr SEMICOL				{$$ = new StatementreturnexprASTnode($2);}

statement7 :RETURN SEMICOL					{$$ = new StatementterminateASTnode(*$1);}
		  | BREAK SEMICOL					{$$ = new StatementterminateASTnode(*$1);}
		  | CONTINUE SEMICOL				{$$ = new StatementterminateASTnode(*$1);}

statement8:block							{$$ = new StatementblockASTnode($1);}


statements : 								{$$ = new StatementsASTnode();}
			| statement statements			{$$ = $2;$$->push_back($1);}

block : LFB var_declarations statements RFB		{$$ = new BlockASTnode($2,$3);}

method_decl : INT ID LB arguments RB block		{$$ = new MethoddeclASTnode(*$1,*$2,$4,$6);}
			| BOOLEAN ID LB arguments RB block	{$$ = new MethoddeclASTnode(*$1,*$2,$4,$6);}
			| VOID ID LB arguments RB block		{$$ = new MethoddeclASTnode(*$1,*$2,$4,$6);}

function : 										{$$ = new FunctionASTnode();}
		   | field_decl function 				{$$ = $2;$$->push_back($1);}
		   | method_decl function				{$$ = $2;$$->push_back($1);}


%%


void decaf::Parser::error(const Parser::location_type& l,
			    		  const std::string& m)
{
    driver.error(l, m);
}
