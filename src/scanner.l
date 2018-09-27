%{
#include "parser.tab.h"
int lineno = 0;
%}

%%
[a-zA-Z][a-zA-Z]*	{return ID;}
[0-9]*				{return NUM;}
"+"					{return '+';}
"-"					{return '-';}
"*"					{return '*';}
"/"					{return '/';}
"("					{return '(';}
")"					{return ')';}
"["					{return '[';}
"]"					{return ']';}
"!"					{return "!";}
"=="				{return "==";}
"!="				{return "!=";}
"&&"				{return "&&";}
"||"				{return "||";}
">"					{return ">";}
"<"					{return "<";}
">="				{return ">=";}
"<="				{return "<=";}
[ \t]				{ }
\n		     		{++lineno;}
.					{ printf("Line No %d: Unrecognized Character\n", lineno); }

%%

