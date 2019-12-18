%{
#include <stdio.h>
#include "parser.tab.h"
extern int yylex();
int linenum=0;
%}

alphabet [a-zA-Z]
digit [0-9]
number {digit}+
id ({alphabet}|_)({alphabet}|{digit}|_)*
hexnumber 0x({digit}[a-fA-F])+
character (\\n|\\t|\\'|\\\\|\\\"|[^\\"'])
charlit [']{character}[']
strlit ["]{character}*["]
comments "//".*

%%

"class" 			{return CLASS;}
"void"			    {return VOID;}
"callout"			{return CALLOUT;}
"if"			    {return IF;}
"else"			    {return ELSE;}
"for"			    {return FOR;}
"break"			    {return BREAK;}
"continue"			{return CONTINUE;}
"int"				{return INT;}
"boolean"			{return BOOL;}
"true"				{return TRUE;}
"false"				{return FALSE;}
"return"			{return RETURN;}
{id}                {return ID;}
{number}          	{return NUM;}
{hexnumber}         {return HEX;}
{strlit}	    	{return STRLIT;}
{charlit}       	{return CHARLIT;}
"("					{return '(';}
")"					{return ')';}
"{"					{return '{';}
"}"					{return '}';}
"["					{return '[';}
"]"					{return ']';}
"!"					{return '!';}
"+"					{return '+';}
"-"					{return '-';}
"*"					{return '*';}
"/"					{return '/';}
"%"					{return '%';}
"<"					{return '<';}
">"					{return '>';}
"="					{return '=';}
"=="				{return EQEQ;}
">="				{return GTEQ;}
"<="				{return LTEQ;}
"!="				{return NOTEQ;}
"+="				{return PLUSEQ;}
"-="				{return MINUSEQ;}
"&&"				{return AND;}
"||"				{return OR;}
"\""				{return '"';}
"'"					{return '\'';}
","					{return ',';}
";"					{return ';';}
{comments}			return COMMENTS;
[ \t]				{ }
\n		     		{++linenum;}
.					{ printf("Line No %d: Unrecognized Character\n",linenum);}

%%

