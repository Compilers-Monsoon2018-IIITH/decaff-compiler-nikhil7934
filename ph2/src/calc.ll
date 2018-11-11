/* $Id$ -*- mode: c++ -*- */
/** \file scanner.ll Define the example Flex lexical scanner */

%{ /*** C/C++ Declarations ***/

#include <string>
#include "scanner.h"

/* import the parser's token type into a local typedef */
typedef decaf::Parser::token token;
typedef decaf::Parser::token_type token_type;

/* By default yylex returns int, we use token_type. Unfortunately yyterminate
 * by default returns 0, which is not of token_type. */
#define yyterminate() return token::END

/* This disables inclusion of unistd.h, which is not available under Visual C++
 * on Win32. The C++ scanner uses STL streams instead. */
#define YY_NO_UNISTD_H

%}

/*** Flex Declarations and Options ***/

/* enable c++ scanner class generation */
%option c++

/* change the name of the scanner class. results in "decafFlexLexer" */
%option prefix="decaf"

/* the manual says "somewhat more optimized" */
%option batch

/* enable scanner to generate debug output. disable this for release
 * versions. */
%option debug

/* no support for include files is planned */
%option yywrap nounput 

/* enables the use of start condition stacks */
%option stack

/* The following paragraph suffices to track locations accurately. Each time
 * yylex is invoked, the begin position is moved onto the end position. */
%{
    #define YY_USER_ACTION  yylloc->columns(yyleng);
%}

%% /*** Regular Expressions Part ***/

 /* code to place at the beginning of yylex() */
%{
    // reset location
    yylloc->step();
%}

"class"			    {yylval->stgval = new std::string(yytext); 
						return token::CLASS;}
"Program"           {yylval->stgval = new std::string(yytext); 
						return token::PROGRAM;}
"void"			    {yylval->stgval = new std::string(yytext); 
						return token::VOID;}
"callout"			{yylval->stgval = new std::string(yytext); 
						return token::CALLOUT;}
"int"				{yylval->stgval = new std::string(yytext); 
						return token::INT;}
"boolean"			{yylval->stgval = new std::string(yytext); 
						return token::BOOLEAN;}
"for"			    {yylval->stgval = new std::string(yytext); 
						return token::FOR;}
"break"			    {yylval->stgval = new std::string(yytext); 
						return token::BREAK;}
"continue"			{yylval->stgval = new std::string(yytext); 
						return token::CONTINUE;}
"if"			    {yylval->stgval = new std::string(yytext); 
						return token::IF;}
"else"			    {yylval->stgval = new std::string(yytext); 
						return token::ELSE;}
"true"				{yylval->stgval = new std::string(yytext); 
						return token::TRUE;}
"false"				{yylval->stgval = new std::string(yytext); 
						return token::FALSE;}
"return"			{yylval->stgval = new std::string(yytext); 
						return token::RETURN;}
[a-zA-Z]([a-zA-Z]|[0-9])* {yylval->stgval = new std::string(yytext); 
								return token::ID;}
[0-9]+          	{yylval->integerVal = std::atoi(yytext); 
						return token::NUM;}
0x([0-9][a-fA-F])+  {yylval->integerVal = std::atoi(yytext); 
						return token::HEX;}
"("					{yylval->stgval = new std::string(yytext); 
						return token::LB;}
")"					{yylval->stgval = new std::string(yytext); 
						return token::RB;}
"{"					{yylval->stgval = new std::string(yytext); 
						return token::LFB;}
"}"					{yylval->stgval = new std::string(yytext); 
						return token::RFB;}
"["					{yylval->stgval = new std::string(yytext); 
						return token::LSB;}
"]"					{yylval->stgval = new std::string(yytext); 
						return token::RSB;}
"!"					{yylval->stgval = new std::string(yytext); 
						return token::NOT;}
"+"					{yylval->stgval = new std::string(yytext); 
						return token::PLUS;}
"-"					{yylval->stgval = new std::string(yytext); 
						return token::MINUS;}
"*"					{yylval->stgval = new std::string(yytext); 
						return token::MUL;}
"/"					{yylval->stgval = new std::string(yytext); 
						return token::DIV;}
"%"					{yylval->stgval = new std::string(yytext); 
						return token::MOD;}
"<"					{yylval->stgval = new std::string(yytext); 
						return token::LT;}
">"					{yylval->stgval = new std::string(yytext); 
						return token::GT;}
"="					{yylval->stgval = new std::string(yytext); 
						return token::EQ;}
"=="				{yylval->stgval = new std::string(yytext); 
						return token::EQEQ;}
">="				{yylval->stgval = new std::string(yytext); 
						return token::GTEQ;}
"<="				{yylval->stgval = new std::string(yytext); 
						return token::LTEQ;}
"!="				{yylval->stgval = new std::string(yytext); 
						return token::NOTEQ;}
"+="				{yylval->stgval = new std::string(yytext); 
						return token::PLUSEQ;}
"-="				{yylval->stgval = new std::string(yytext); 
						return token::MINUSEQ;}
"&&"				{yylval->stgval = new std::string(yytext); 
						return token::AND;}
"||"				{yylval->stgval = new std::string(yytext); 
						return token::OR;}
","					{yylval->stgval = new std::string(yytext); 
						return token::COMMA;}
";"					{yylval->stgval = new std::string(yytext); 
						return token::SEMICOL;}
\"(\\n|\\t|\\'|\\\\|\\\"|[^\\"'])*\"   {yylval->stgval = new std::string(yytext); 
											return token::STRLIT;}
"'"(\\n|\\t|\\'|\\\\|\\\"|[^\\"'])"'"   {yylval->stgval = new std::string(yytext); 
											return token::CHARLIT;}

 /* gobble up white-spaces */
[ \t\r]+    {
                yylloc->step();
            }

 /* gobble up end-of-lines */
\n          {
                yylloc->lines(yyleng);
                yylloc->step();
                return token::EOL;
            }

 /* pass all other characters up to bison */
.           {
                return static_cast<token_type>(*yytext);
            }


%% /*** Additional Code ***/

namespace decaf {

Scanner::Scanner(std::istream* in,
		         std::ostream* out)
: decafFlexLexer(in, out)
{
}

Scanner::~Scanner()
{
}

void Scanner::set_debug(bool b)
{
    yy_flex_debug = b;
}

}

/* This implementation of DecafFlexLexer::yylex() is required to fill the
 * vtable of the class DecafFlexLexer. We define the scanner's main yylex
 * function via YY_DECL to reside in the Scanner class instead. */

#ifdef yylex
#undef yylex
#endif

int decafFlexLexer::yylex()
{
    std::cerr << "in decafFlexLexer::yylex() !" << std::endl;
    return 0;
}

/* When the scanner receives an end-of-file indication from YY_INPUT, it then
 * checks the yywrap() function. If yywrap() returns false (zero), then it is
 * assumed that the function has gone ahead and set up `yyin' to point to
 * another input file, and scanning continues. If it returns true (non-zero),
 * then the scanner terminates, returning 0 to its caller. */

int decafFlexLexer::yywrap()
{
    return 1;
}

