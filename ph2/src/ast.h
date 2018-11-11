
#ifndef AST_H
#define AST_H

#include <string>
using namespace std;

class IntLitASTnode;
class ProgASTnode;
class VarbASTnode;
class VarbDeclnode;
class VarbDeclsnode;
class FieldDeclnode;
class VariableASTnode;
class VariablesASTnode;
class MethodNameASTnode;
class StringLitASTnode;
class CalloutargASTnode;
class CalloutASTnode;
class LocationASTnode;
class BoolLitASTnode;
class CharLitASTnode;
class MethodargASTnode;
class ArgumentsASTnode;
class MethodcallASTnode;
class StatementlocASTnode;
class MethodstatASTnode;
class StatementifASTnode;
class StatementifelseASTnode;
class StatementforASTnode;
class BlockASTnode;
class MethoddeclASTnode;
class FunctionASTnode;
class Statement;
class StatementreturnexprASTnode;
class StatementterminateASTnode;
class StatementblockASTnode;
class StatementsASTnode;
class Expr;
class BinaryASTnode;
class TernaryASTnode;
class IntLitASTnode;
class UnaryASTnode;

class ASTvisitor
{
  public:
    virtual void visit(BinaryASTnode& node) = 0;
    virtual void visit(UnaryASTnode& node) = 0;
    virtual void visit(TernaryASTnode& node) = 0;
    virtual void visit(IntLitASTnode& node) = 0;
    virtual void visit(ProgASTnode& node) = 0;
    virtual void visit(VarbASTnode& node) = 0;
    virtual void visit(VarbDeclnode& node) = 0;
    virtual void visit(VarbDeclsnode& node) = 0;
    virtual void visit(LocationASTnode& node) = 0;
    virtual void visit(BoolLitASTnode& node) = 0;
    virtual void visit(CharLitASTnode& node) = 0;
    virtual void visit(FieldDeclnode& node) = 0;
    virtual void visit(StatementlocASTnode& node) = 0;
    virtual void visit(MethodstatASTnode& node) = 0;
    virtual void visit(StatementifASTnode& node) = 0;
    virtual void visit(StatementifelseASTnode& node) = 0;
    virtual void visit(VariableASTnode& node) = 0;
    virtual void visit(VariablesASTnode& node) = 0;
    virtual void visit(MethodNameASTnode& node) = 0;
    virtual void visit(StringLitASTnode& node) = 0;
    virtual void visit(CalloutargASTnode& node) = 0;
    virtual void visit(CalloutASTnode& node) =0;
    virtual void visit(ArgumentsASTnode& node) = 0;
    virtual void visit(MethodcallASTnode& node) = 0;
    virtual void visit(MethodargASTnode& node) = 0;
    virtual void visit(StatementforASTnode& node) = 0;
    virtual void visit(StatementreturnexprASTnode& node) =0;
    virtual void visit(StatementterminateASTnode& node) = 0;
    virtual void visit(StatementblockASTnode& node) = 0;
    virtual void visit(StatementsASTnode& node) = 0;
    virtual void visit(BlockASTnode& node) = 0;
    virtual void visit(MethoddeclASTnode& node) = 0;
    virtual void visit(FunctionASTnode& node) =0;
    virtual void visit(Statement& node) = 0;
    virtual void visit(Expr& node) = 0;
};


class ASTnode
{
  public :
    virtual ~ASTnode()
    {
    }

    //  virtual void printPostFix() const = 0;
    virtual void accept(ASTvisitor& V) = 0;
};

class ProgASTnode : public ASTnode
{
    public:
    ProgASTnode (ASTnode* cParam) {
        this->node = cParam;
    }

    ASTnode* getNode() {
        return node;
    }
    
    virtual void accept(ASTvisitor& v) {
        v.visit(*this);
    }

  private:
    ASTnode* node;
};
class VarbASTnode : public ASTnode
{
    public:
    VarbASTnode () {

    }
    void push_back(string s)
    {
        vars.push_back(s);
        return;
    }
    vector  <string> getlist(){
        return vars;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    vector <string> vars;
};

class VariableASTnode : public ASTnode
{
    public:
    // Constructor to initialize binary operator, 
    // left node and right node of the binary expression.
    VariableASTnode (string variableid,ASTnode* intlit){
        this->node = intlit;
        this->variableid = variableid;
    }
    VariableASTnode (string variableid){
        this->node = NULL;
        this->variableid = variableid;
    }
    /*  virtual void printPostFix() const 
    {
        lhs->printPostFix();
        rhs->printPostFix();
        std::cout << bin_operator << " "; 
    } */

    ASTnode* getNode() {
        return node;
    }
    

    string getVariable()
    {
        return variableid;
    }
    
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    ASTnode* node;
    string   variableid;
};
class VarbDeclsnode : public ASTnode
{
    public:
    VarbDeclsnode () {

    }
    void push_back(ASTnode *temp)
    {
        vardecls.push_back(temp);
        return;
    }
    vector  <ASTnode*> getlist(){
        return vardecls;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    vector <ASTnode*> vardecls;
};
class FunctionASTnode : public ASTnode
{
    public:
    FunctionASTnode () {

    }
    void push_back(ASTnode *temp)
    {
        functions.push_back(temp);
        return;
    }
    vector  <ASTnode*> getlist(){
        return functions;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    vector <ASTnode*> functions;
};
class VariablesASTnode : public ASTnode
{
    public:
    VariablesASTnode (){
        
    }
    void push_back(ASTnode *temp){
        var.push_back(temp);
    }
    vector <ASTnode*> getlist(){
        return var;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    vector <ASTnode*> var;
};
class StatementsASTnode : public ASTnode
{
    public:
    StatementsASTnode (){
        
    }
    void push_back(ASTnode *temp){
        statements.push_back(temp);
    }
    vector <ASTnode*> getlist(){
        return statements;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    vector <ASTnode*> statements;
};
class ArgumentsASTnode : public ASTnode
{
    public:
    ArgumentsASTnode(){
        this->str1 = "";
        this->str2 = "";
    }
    ArgumentsASTnode(string type,string id){
        this->str1 = type;
        this->str2 = id;
    }
    void push_back(ASTnode *temp){
        arg.push_back(temp);
    }
    vector <ASTnode*> getlist(){
        return arg;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    vector <ASTnode*> arg;
    string str1;
    string str2;
};
class CalloutASTnode : public ASTnode
{
    public:
    CalloutASTnode (){
        
    }
    void push_back(ASTnode *temp){
        callout.push_back(temp);
    }
    vector <ASTnode*> getlist(){
        return callout;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    vector <ASTnode*> callout;
};
class MethodargASTnode : public ASTnode
{
    public:
    MethodargASTnode (){
        
    }
    void push_back(ASTnode *temp){
        methodarg.push_back(temp);
    }
    vector <ASTnode*> getlist(){
        return methodarg;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    vector <ASTnode*> methodarg;
};
class VarbDeclnode : public ASTnode
{
    public:
    VarbDeclnode (string typevar,ASTnode* variables, string semi){
        this->node = variables;
        this->typevariable = typevar;
    }

    ASTnode* getNode() {
        return node;
    }
    

    string getVariabletype()
    {
        return typevariable;
    }
    
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    ASTnode* node;
    string   typevariable;
};
class Statement : public ASTnode
{
    public:
    Statement (ASTnode* statement){
        this->statement = statement;
    }

    ASTnode* getNode() {
        return statement;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    ASTnode* statement;
};
class Expr : public ASTnode
{
    public:
    Expr (ASTnode* expr){
        this->expr = expr;
    }

    ASTnode* getNode() {
        return expr;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    ASTnode* expr;
};
class MethodstatASTnode : public ASTnode
{
    public:
    MethodstatASTnode (ASTnode* method_call){
        this->methodcall = method_call;
    }
    ASTnode* getmethodcall() {
        return methodcall;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    ASTnode* methodcall;
};
class StatementlocASTnode : public ASTnode
{
    public:
    StatementlocASTnode (ASTnode* location, string op,ASTnode* expr){
        this->location = location;
        this->op = op;
        this->expr = expr;
    }
    ASTnode* getlocation() {
        return location;
    }
    string getop()
    {
        return op;
    }
    ASTnode* getexpr(){return expr;}
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
  private:
    ASTnode* expr;
    ASTnode* location;
    string   op;
};
class CalloutargASTnode : public ASTnode{
    public:
    CalloutargASTnode(ASTnode* callout){
        this->node = callout;
    }
    ASTnode* getNode() {
        return node;
    }
    virtual void accept(ASTvisitor& v){
        v.visit(*this);
    }
    private:
    ASTnode* node;
};
class MethodNameASTnode : public ASTnode
{
    public:
    MethodNameASTnode(string s1){
        this->str = s1;
    }
    string getString(){
        return str;
    }
    virtual void accept(ASTvisitor& v){
        v.visit(*this);
    }
    private:
        string str;
};
class StatementifASTnode : public ASTnode
{
    public:
    StatementifASTnode(ASTnode* expr,ASTnode* block){
        this->expr = expr;
        this->block = block;
    }
    ASTnode* getexpr(){return expr;}
    ASTnode* getblock(){return block;}
    virtual void accept(ASTvisitor& v){
        v.visit(*this);
    }
    private:
        ASTnode* expr;
        ASTnode* block;
};
class BlockASTnode : public ASTnode
{
    public:
    BlockASTnode(ASTnode* vardecl,ASTnode* statements){
        this->statements = statements;
        this->vardecl = vardecl;
    }
    ASTnode* getvardecl(){return vardecl;}
    ASTnode* getstatements(){return statements;}
    virtual void accept(ASTvisitor& v){
        v.visit(*this);
    }
    private:
        ASTnode* vardecl;
        ASTnode* statements;
};
class StatementreturnexprASTnode : public ASTnode
{
    public:
    StatementreturnexprASTnode(ASTnode* expr){
        this->expr = expr;
    }
    ASTnode* getexpr(){return expr;}
    virtual void accept(ASTvisitor& v){
        v.visit(*this);
    }
    private:
        ASTnode* expr;
};
class StatementblockASTnode : public ASTnode
{
    public:
    StatementblockASTnode(ASTnode* block){
        this->block = block;
    }
    ASTnode* getblock(){return block;}
    virtual void accept(ASTvisitor& v){
        v.visit(*this);
    }
    private:
        ASTnode* block;
};
class StatementterminateASTnode : public ASTnode
{
    public:
    StatementterminateASTnode(string s1){
        this->str = s1;
    }
    string getstr(){return str;}
    virtual void accept(ASTvisitor& v){
        v.visit(*this);
    }
    private:
        string str;
};
class StatementifelseASTnode : public ASTnode
{
    public:
    StatementifelseASTnode(ASTnode* expr,ASTnode* block1,ASTnode* block2){
        this->expr = expr;
        this->block1 = block1;
        this->block2 = block2;
    }
    ASTnode* getexpr(){return expr;}
    ASTnode* getblock1(){return block1;}
    ASTnode* getblock2(){return block2;}    
    virtual void accept(ASTvisitor& v){
        v.visit(*this);
    }
    private:
        ASTnode* expr;
        ASTnode* block1;
        ASTnode* block2;
};
class MethoddeclASTnode : public ASTnode
{
    public:
    MethoddeclASTnode(string type,string id,ASTnode* arg,ASTnode* block){
        this->type = type;
        this->block = block;
        this->arg = arg;
    }
    string gettype(){return type;}
    ASTnode* getblock(){return block;}
    ASTnode* getarg(){return arg;}    
    virtual void accept(ASTvisitor& v){
        v.visit(*this);
    }
    private:
        ASTnode* arg;
        ASTnode* block;
        string type;
};

class StatementforASTnode : public ASTnode
{
    public:
    StatementforASTnode(string s1,ASTnode* expr1,ASTnode* expr2,ASTnode* block){
        this->expr1 = expr1;
        this->block = block;
        this->expr2 = expr2;
        this->str = s1;
    }
    ASTnode* getexpr1(){return expr1;}
    ASTnode* getblock(){return block;}
    ASTnode* getexpr2(){return expr2;}
    string getstr(){return str;}    
    virtual void accept(ASTvisitor& v){
        v.visit(*this);
    }
    private:
        ASTnode* expr1;
        ASTnode* block;
        ASTnode* expr2;
        string str;
};
class StringLitASTnode : public ASTnode
{
    public:
    StringLitASTnode(string s1){
        this->str = s1;
    }
    string getString(){
        return str;
    }
    virtual void accept(ASTvisitor& v){
        v.visit(*this);
    }
    private:
        string str;
};
class FieldDeclnode : public ASTnode
{
    public:
    FieldDeclnode (string typefield,ASTnode* variable, string semi){
        this->node = variable;
        this->typefield = typefield;
    }
    ASTnode* getNode() {
        return node;
    }
    string getFieldtype()
    {
        return typefield;
    }   
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    ASTnode* node;
    string   typefield;
};


class LocationASTnode : public ASTnode
{
    public:
    LocationASTnode (string locationid,ASTnode* expression){
        this->node = expression;
        this->location = locationid;
    }
    LocationASTnode (string locationid){
        this->node = NULL;
        this->location = locationid;
    }
    ASTnode* getNode() {
        return node;
    }
    string getLocation()
    {
        return location;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
  private:
    ASTnode* node;
    string   location;
};
class MethodcallASTnode : public ASTnode
{
    public:
    MethodcallASTnode(ASTnode* methodname,ASTnode* methodarg){
        this->name = methodname;
        this->arg = methodarg;
        this->callout = "";
        this->str = NULL;
        this->call = NULL;
    }
    MethodcallASTnode(string callout,ASTnode* stringlit){
        this->callout = callout;
        this->str = stringlit;
        this->call = NULL;
        this->name = NULL;
        this->arg = NULL;
    }
    MethodcallASTnode(string callout,ASTnode* stringlit,ASTnode* call){
        this->callout = callout;
        this->str = stringlit;
        this->call = call;
        this->name = NULL;
        this->arg = NULL;
    }
    ASTnode* getname() {return name;}
    ASTnode* getarg(){return arg;}
    ASTnode* getcall(){return call;}
    ASTnode* getstr(){return str;}
    string getcallout(){return callout;}
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
    private:
    ASTnode* name;
    ASTnode* arg;
    ASTnode* call;
    ASTnode*   str;
    string callout;
};

class BinaryASTnode : public ASTnode
{
    public:
    // Constructor to initialize binary operator, 
    // left node and right node of the binary expression.
    BinaryASTnode (string binOperatorParm,
                   ASTnode* pLeftParm,
                   ASTnode* pRightParm)
    :pLeft(pLeftParm)
    ,pRight(pRightParm)
    ,mBinaryOperator(binOperatorParm)
    {
    }  

    /*  virtual void printPostFix() const 
    {
    	lhs->printPostFix();
    	rhs->printPostFix();
    	std::cout << bin_operator << " "; 
    } */

    ASTnode* getLeft()
    {
        return pLeft;
    }

    ASTnode* getRight()
    {
        return pRight;
    }

    string getBinOperator()
    {
        return mBinaryOperator;
    }
    
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    // left node and right node can be of any type. 
    // So we need to use Base ASTnode type
    ASTnode* pLeft;
    ASTnode* pRight;
    string   mBinaryOperator;
};

class UnaryASTnode : public ASTnode
{
    public:
    UnaryASTnode (string unaryOperatorParm,ASTnode* thisexpr){
                       this->node = thisexpr;
                       this->operatorun = unaryOperatorParm;
                   }

    /*  virtual void printPostFix() const 
    {
        lhs->printPostFix();
        rhs->printPostFix();
        std::cout << bin_operator << " "; 
    } */

    ASTnode* getexpr()
    {
        return node;
    }
    string getUnaryOperator()
    {
        return operatorun;
    }
    
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    // left node and right node can be of any type. 
    // So we need to use Base ASTnode type
    ASTnode* node;
    string  operatorun;
};
class TernaryASTnode : public ASTnode
{
    public:

    TernaryASTnode (ASTnode* pFirstParm,
                    ASTnode* pSecondParm,
                    ASTnode* pThirdParm)
    :pFirst(pFirstParm)
    ,pSecond(pSecondParm)
    ,pThird(pThirdParm)
    {
    }

    /*
    virtual void printPostFix() const
    {
     	first->printPostFix();
     	second->printPostFix();
     	third->printPostFix();
     	std::cout << "? " << std::endl; 
    }
    */

    ASTnode* getFirst()
    {
        return pFirst;
    }

    ASTnode* getSecond()
    {
        return pSecond;
    }

    ASTnode* getThird()
    {
        return pThird;
    }

     virtual void accept(ASTvisitor& v) 
    {
      v.visit(*this);
    }

  private:
    ASTnode* pFirst;
    ASTnode* pSecond;
    ASTnode* pThird;
};


class IntLitASTnode: public ASTnode
{
	public:
	IntLitASTnode(int intlit)
    : intlit(intlit)
    {
    }

    int getIntLit()
    {
        return intlit;
    }

    virtual void accept(ASTvisitor& v) 
    {
        v.visit(*this);
    }
    
	/*
    virtual void printPostFix() const
	{
		std::cout << intlit << " " ;
	}
    */

  private:
	int intlit;
};

class BoolLitASTnode: public ASTnode
{
    public:
    BoolLitASTnode(bool boollit)
    : boollit(boollit)
    {
    }

    bool getBoolLit()
    {
        return boollit;
    }

    virtual void accept(ASTvisitor& v) 
    {
        v.visit(*this);
    }
    
    /*
    virtual void printPostFix() const
    {
        std::cout << intlit << " " ;
    }
    */

  private:
    bool boollit;
};
class CharLitASTnode: public ASTnode
{
    public:
    CharLitASTnode(string s)
    {this->str = s[1];
    }

    char getCharLit()
    {
        return str;
    }

    virtual void accept(ASTvisitor& v) 
    {
        v.visit(*this);
    }
    
    /*
    virtual void printPostFix() const
    {
        std::cout << intlit << " " ;
    }
    */

  private:
    char str;
};

class ASTContext
{
  public:
    ASTnode* pRoot;
    ~ASTContext()
    {
	    clearAST();
    }

    // free all saved expression trees
    void clearAST()
    {
        delete pRoot;
    }
};

#endif /* End of AST_H */

