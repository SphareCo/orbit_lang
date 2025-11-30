#ifndef AST_H
#define AST_H

#include <string>
#include <memory>
#include <vector>

#include <iostream>

#include "TokenType.h"

using namespace std;

struct ASTNode
{
    virtual ~ASTNode() = default;
};

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
};

struct VariableExpr : public Expression
{
    string name;
    VariableExpr(string n) : name(n) {}
};

struct BinaryExpr : public Expression
{
    unique_ptr<Expression> left;
    TokenType op;
    unique_ptr<Expression> right;

    BinaryExpr(unique_ptr<Expression> l, TokenType o, unique_ptr<Expression> r) : left(move(l)), op(o), right(move(r)) {}
};

struct PrintStatement : public Statement
{
    unique_ptr<Expression> expression;

    PrintStatement(unique_ptr<Expression> expr) : expression(move(expr)) {}
};

struct VarDeclaration : public Statement
{
    string name;
    unique_ptr<Statement> initializer;

    VarDeclaration(string n, unique_ptr<Statement> init) : name(n), initializer(move(init)) {}
};

#endif