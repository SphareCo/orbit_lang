#ifndef AST_H
#define AST_H

#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include "TokenType.h"

using namespace std;

// It's a forward declearation to tell the compiler that visitor is coming now
struct Visitor;

class Visitor
{
public:
    virtual void visit(LiteralExpr *expr) = 0;
    virtual void visit(VariableExpr *expr) = 0;
    virtual void visit(BinaryExpr *expr) = 0;
    virtual void visit(PrintStatement *expr) = 0;
    virtual void visit(VarDeclaration *expr) = 0;
};
// Abstract Syntax Tree node = Base node
struct ASTNode
{

    virtual ~ASTNode() = default;

    virtual void accept(Visitor &v) = 0;
};

// These are the categories
struct Statement : public ASTNode
{
};
struct Expression : public ASTNode
{
};

struct LiteralExpr : public Expression
{
    string value;
    TokenType type;

    LiteralExpr(string val, TokenType t) : value(val), type(t) {}
    void accept(Visitor &v) override { v.visit(this); }
};

struct VariableExpr : public Expression
{
    string name;
    VariableExpr(string n) : name(n) {}
    void accept(Visitor &v) override { v.visit(this); }
};

struct BinaryExpr : public Expression
{
    unique_ptr<Expression> left;
    TokenType op;
    unique_ptr<Expression> right;

    BinaryExpr(unique_ptr<Expression> l, TokenType o, unique_ptr<Expression> r) : left(move(l)), op(o), right(move(r)) {}

    void accept(Visitor &v) override { v.visit(this); }
};

struct PrintStatement : public Statement
{
    unique_ptr<Expression> expression;

    PrintStatement(unique_ptr<Expression> expr) : expression(move(expr)) {}
    void accept(Visitor &v) override { v.visit(this); }
};

struct VarDeclaration : public Statement
{
    string name;
    unique_ptr<Expression> initializer;

    VarDeclaration(string n, unique_ptr<Expression> init) : name(n), initializer(move(init)) {}
    void accept(Visitor &v) override { v.visit(this); }
};

#endif