// $Id$
// This File starts the Construsting the AST(Abstract Syntax Tree)
// based on the context free grammer provided for the Decaf Language
// written in calc files.... 
#include <iostream>
#include <fstream>
#include "driver.h"
#include "ast.h"
#include "PostFixVisitor.h"


int main()
{
    ASTContext ast;
    decaf::Driver driver(ast);
    PostFixVisitor pfv;
    
    string line;
    while(cout << "input: " && getline(cin, line) && !line.empty())
    {
	    
	    bool result = driver.parse_string(line, "input");
	    if(result)
    	{
            if(ast.pRoot != NULL ) 
            {
            	ProgASTnode *prgnode;
            	cout<< "Building AST......." << endl;
            	prgnode = dynamic_cast<ProgASTnode *>(ast.pRoot);
            	if(prgnode!=NULL)
            	{
            		pfv.visit(*prgnode);
            	}
                cout << "Done..\n" <<endl; 
            }
            ast.clearAST();
	    }
	}
}

