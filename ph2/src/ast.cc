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
            	ProgramASTnode *pnode;
            	cout<< "Construsting AST......." << endl;
            	pnode = dynamic_cast<ProgramASTnode *>(ast.pRoot);
            	if(pnode!=NULL)
            	{
            		pfv.visit(*pnode);
            	}
                cout <<  endl; 
            }
            ast.clearAST();
	    }
	}
}

