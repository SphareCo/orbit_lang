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

    LiteralExpr(string val, TokenType t) : value(val), type(t) {};
};

struct VariableExpr : public Expression
{
    string name;

    VariableExpr(string n) : name(n){};
};
#endif