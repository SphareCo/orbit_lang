#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "AST.h"
#include "Environment.h"
#include "RuntimeValue.h"
#include <vector>

class Interpreter : public Visitor
{
private:
    Environment *env;
    RuntimeValue lastEvaluated;

public:
    Interpreter()
    {
        env = new Environment();
    }

    void interpret(vector<unique_ptr<Statement>> &statements)
    {
        for (const auto &stmt : statements)
        {
            stmt->accept(*this);
        }
    }

    void visit(LiteralExpr *expr) override
    {
        if (expr->type == TOKEN_NUMBER)
            lastEvaluated = RuntimeValue(stod(expr->value));
        else if (expr->type == TOKEN_STRING)
            lastEvaluated = RuntimeValue(expr->value);
        else if (expr->type == TOKEN_TRUE)
            lastEvaluated = RuntimeValue(true);
        else if (expr->type == TOKEN_FALSE)
            lastEvaluated = RuntimeValue(false);
        else
            lastEvaluated = RuntimeValue();
    }

    void visit(VariableExpr *expr) override
    {
        lastEvaluated = env->get(expr->name);
    }

    void visit(BinaryExpr *expr) override
    {
        expr->left->accept(*this);
        RuntimeValue left = lastEvaluated;
        expr->right->accept(*this);
        RuntimeValue right = lastEvaluated;

        if (left.type == VAL_NUMBER && right.type == VAL_NUMBER)
        {
            if (expr->op == TOKEN_PLUS)
                lastEvaluated = RuntimeValue(left.numberVal + right.numberVal);
            else if (expr->op == TOKEN_MINUS)
                lastEvaluated = RuntimeValue(left.numberVal - right.numberVal);
            else if (expr->op == TOKEN_STAR)
                lastEvaluated = RuntimeValue(left.numberVal * right.numberVal);
            else if (expr->op == TOKEN_SLASH)
                lastEvaluated = RuntimeValue(left.numberVal / right.numberVal);
        }
        else if (left.type == VAL_STRING && expr->op == TOKEN_PLUS)
        {
            lastEvaluated = RuntimeValue(left.stringVal + right.asString());
        }
    }

    void visit(PrintStatement *stmt) override
    {
        stmt->expression->accept(*this);
        cout << lastEvaluated.asString() << endl;
    }

    void visit(VarDeclaration *stmt) override
    {
        stmt->initializer->accept(*this);
        env->define(stmt->name, lastEvaluated);
    }

    void visit(BlockStatement *stmt) override
    {
        Environment *previous = env;
        env = new Environment(previous);

        for (const auto &s : stmt->statements)
        {
            s->accept(*this);
        }

        delete env;
        env = previous;
    }

    void visit(IfStatement *stmt) override
    {
        stmt->condition->accept(*this);
        bool isTrue = false;
        if (lastEvaluated.type == VAL_BOOL)
            isTrue = lastEvaluated.boolVal;
        else if (lastEvaluated.type == VAL_NUMBER)
            isTrue = (lastEvaluated.numberVal != 0);

        if (isTrue)
        {
            stmt->thenBranch->accept(*this);
        }
        else if (stmt->elseBranch != nullptr)
        {
            stmt->elseBranch->accept(*this);
        }
    }
};

#endif