parser: parser.y scanner.l
		bison -d parser.y
		flex scanner.l
		gcc parser.tab.c lex.yy.c -ll -o parser
