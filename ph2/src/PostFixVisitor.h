
#ifndef POSTFIXVISITOR_H
#define POSTFIXVISITOR_H

#include "ast.h"

class PostFixVisitor: public ASTvisitor
{
  public:

    virtual void visit(ProgASTnode& node)
    {
        std::cout << "Program Started Here....\n";
        if(node.getNode())
            node.getNode()->accept(*this);
        std::cout << "Program Ended Successfully (<-).....\n";
    }
    virtual void visit(VarbDeclnode& node)
    {
        std::cout << "Declaration of Varibales Started...\n";
        if(node.getNode())
            node.getNode()->accept(*this);
        std::cout << "Declaration Ended...\n";
    }
    virtual void visit(Statement& node)
    {
        std::cout << "Statement Started...\n";
        if(node.getNode())
            node.getNode()->accept(*this);
        std::cout << "Statement Ended\n";
    }
    virtual void visit(FieldDeclnode& node)
    {
        std::cout << "Declaration of Field Started...\n";
        if(node.getNode())
            node.getNode()->accept(*this);
        std::cout << "Declaration of Field Ended\n";
    }
    virtual void visit(StatementlocASTnode& node)
    {
        std::cout << "Statement Location Field Started...\n";
        if(node.getlocation())
            node.getlocation()->accept(*this);
        if(node.getexpr())
            node.getexpr()->accept(*this);
        std::cout << "Statement Location Field Ended.\n";
    }
    virtual void visit(StatementifASTnode& node)
    {
        std::cout << "Statement IF Field Started...\n";
        if(node.getblock())
            node.getblock()->accept(*this);
        if(node.getexpr())
            node.getexpr()->accept(*this);
        std::cout << "Statement IF Field Ended\n";
    }
    virtual void visit(BlockASTnode& node)
    {
        std::cout << "Block Started..\n";
        if(node.getvardecl())
            node.getvardecl()->accept(*this);
        if(node.getstatements())
            node.getstatements()->accept(*this);
        std::cout << "Block Field Ended\n";
    }
    virtual void visit(Expr& node)
    {
        std::cout << "Expression Started...\n";
        if(node.getNode())
            node.getNode()->accept(*this);
        std::cout << "Expression Ended...\n";
    }
    virtual void visit(MethoddeclASTnode& node)
    {
        std::cout << "Method Declaration Started...\n";
        if(node.getblock())
            node.getblock()->accept(*this);
        if(node.getarg())
            node.getarg()->accept(*this);
        std::cout << "Method Declaration Ended...\n";
    }
    virtual void visit(StatementreturnexprASTnode& node)
    {
        std::cout << "Statement RETURN Started...\n";
        if(node.getexpr())
            node.getexpr()->accept(*this);
        std::cout << "Statement RETURN Ended...\n";
    }
    virtual void visit(StatementblockASTnode& node)
    {
        std::cout << "STATEMENT BLOCK Started...\n";
        if(node.getblock())
            node.getblock()->accept(*this);
        std::cout << "STATEMENT BLOCK Ended...\n";
    }
    virtual void visit(StatementterminateASTnode& node)
    {
        std::cout << "Statement Termination Started...\n Statement Termination Ended...\n";
        
    }
    virtual void visit(StatementifelseASTnode& node)
    {
        std::cout << "Statement IfElse Started...\n";
        if(node.getblock1())
            node.getblock1()->accept(*this);
        if(node.getexpr())
            node.getexpr()->accept(*this);
        if(node.getblock2())
            node.getblock2()->accept(*this);
        std::cout << "Statement IfElse Ended...\n";
    }
    virtual void visit(StatementforASTnode& node)
    {
        std::cout << "Statement FOR Started...\n";
        if(node.getblock())
            node.getblock()->accept(*this);
        if(node.getexpr2())
            node.getexpr2()->accept(*this);
        if(node.getexpr1())
            node.getexpr1()->accept(*this);
        // std::cout << "statement for field ended\n";
    }
    virtual void visit(MethodstatASTnode& node)
    {
        std::cout << "Statement METHOD Started...\n";
        if(node.getmethodcall())
            node.getmethodcall()->accept(*this);
        std::cout << "Statement METHOD Ended...\n";
    }
    virtual void visit(VarbASTnode& node)
    {
        std::cout << "Varibale List Started...\n";
        vector <string> temp = node.getlist();
        for(int i=0;i<temp.size();i++){
            std::cout << "VarStart" <<"\n";
            std::cout << temp[i];
            std::cout <<"VarEnd\n";
        }
        std::cout <<"Varibale List Ended...\n";
    }
    virtual void visit(VarbDeclsnode& node)
    {
        std::cout << "Var Declarations List Started...\n";
        vector <ASTnode*> temp = node.getlist();
        for(int i=0;i<temp.size();i++){
            std::cout << "Var Declaration Start." <<"\n";
            temp[i]->accept(*this);
            std::cout <<"Var Declaration End.\n";
        }
        std::cout <<"Var Declarations List Ended...\n";
    }
    virtual void visit(FunctionASTnode& node)
    {
        std::cout << "Function Declarations Started...\n";
        vector <ASTnode*> temp = node.getlist();
        for(int i=0;i<temp.size();i++){
            std::cout << "function start" <<"\n";
            temp[i]->accept(*this);
            std::cout <<"function end\n";
        }
        std::cout <<"Function Declarations Ended...\n";
    }

    virtual void visit(StringLitASTnode& node)
    {
        std::cout << "StringNode Started...";
        std::cout << node.getString() << " ";
        std::cout << "StringNode Ended...\n";
    }
    virtual void visit(VariableASTnode& node)
    {
        std::cout << "VaribaleNode Started...";
        if(node.getNode())
            node.getNode()->accept(*this);
        std::cout << node.getVariable() << " ";
        std::cout << "VaribaleNode Ended...\n";
    }

    virtual void visit(UnaryASTnode& node)
    {
        std::cout << "UnaryOp Started...\n";
        if(node.getexpr())
            node.getexpr()->accept(*this);
        std::cout << node.getUnaryOperator() << " ";
        std::cout << "UnaryOp Ended...\n";
    }
    
    virtual void visit(LocationASTnode& node)
    {
        std::cout << "Location Started...";
        if (node.getNode())
            node.getNode()->accept(*this);
        std::cout << node.getLocation() << " ";
        std::cout << "Location Ended...\n";
    }
    virtual void visit(MethodNameASTnode& node)
    {
        std::cout << "MethodName Started...";
        std::cout << node.getString() << " ";
        std::cout << "MethodName Ended...\n";
    }
    
    virtual void visit(CalloutargASTnode& node)
    {
        std::cout << "CallOut Node Started...\n";
        if(node.getNode())
            node.getNode()->accept(*this);
        std::cout << "CallOut Node Ended...\n";
    }
    virtual void visit(MethodcallASTnode& node)
    {
        std::cout << "MethodCall Node Started...";
        if(node.getname())
            node.getname()->accept(*this);
        if(node.getarg())
            node.getarg()->accept(*this);
        if(node.getcall())
            node.getcall()->accept(*this);
        if(node.getstr())
            node.getstr()->accept(*this);
        std::cout << "MethodCall Node Ended...\n";
    }
    virtual void visit(VariablesASTnode& node)
    {
        std::cout << "Varibales List Started...\n";
        vector <ASTnode*> temp = node.getlist();
        for(int i=0;i<temp.size();i++){
            std::cout << "Varibale Start" <<"\n";
            std::cout << temp.size() <<"\n";
            temp[i]->accept(*this);
            std::cout <<"Varibale End\n";
        }
        std::cout <<"Varibale List Ended...\n";
    }
    virtual void visit(StatementsASTnode& node)
    {
        std::cout << "Statements List Started...\n";
        vector <ASTnode*> temp = node.getlist();
        for(int i=0;i<temp.size();i++){
            std::cout << "Statement Start" <<"\n";
            std::cout << temp.size() <<"\n";
            temp[i]->accept(*this);
            std::cout <<"Statement End\n";
        }
        std::cout <<"Statements List Ended...\n";
    }
    

    virtual void visit(BinaryASTnode& node)
    {
        node.getLeft()->accept(*this);
        node.getRight()->accept(*this);
        std::cout << node.getBinOperator() << " ";
    }
    virtual void visit(TernaryASTnode& node)
    {
        node.getFirst()->accept(*this);
        node.getSecond()->accept(*this);
        node.getThird()->accept(*this);
        std::cout << "? ";
    }
    virtual void visit(BoolLitASTnode& node) 
    {
        std::cout << node.getBoolLit() << " ";
    }
    virtual void visit(CharLitASTnode& node) 
    {
        std::cout << node.getCharLit() << " ";
    }
    virtual void visit(IntLitASTnode& node) 
    {
        std::cout << node.getIntLit() << " ";
    }
    
    virtual void visit(CalloutASTnode& node)
    {
        std::cout << "Callout Started...\n";
        vector <ASTnode*> temp = node.getlist();
        for(int i=0;i<temp.size();i++){
            std::cout << "Callout Start." <<"\n";
            std::cout << temp.size() <<"\n";
            temp[i]->accept(*this);
            std::cout <<"Callout End.\n";
        }
        std::cout <<"Callout Ended...\n";
    }
    virtual void visit(MethodargASTnode& node)
    {
        std::cout << "Method Argu List Started...\n";
        vector <ASTnode*> temp = node.getlist();
        for(int i=0;i<temp.size();i++){
            std::cout << "Method Start" <<"\n";
            std::cout << temp.size() <<"\n";
            temp[i]->accept(*this);
            std::cout <<"Method End\n";
        }
        std::cout <<"Method Argu List Ended...\n";
    }
    virtual void visit(ArgumentsASTnode& node)
    {
        std::cout << "Arguments List Started...\n";
        vector <ASTnode*> temp = node.getlist();
        for(int i=0;i<temp.size();i++){
            std::cout << "Arguments Started..." <<"\n";
            // std::cout << temp.size() <<"\n";
            temp[i]->accept(*this);
            std::cout <<"Arguments Ended...\n";
        }
        std::cout <<"Arguments List Ended...\n";
    }

};

#endif /* POSTFIXVISITOR_H */

