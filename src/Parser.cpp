#include "../include/Parser.h"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;
vector<unique_ptr<Statement>> Parser::parse()
{
    vector<unique_ptr<Statement>> statements;

    while (!isAtEnd())
    {
        statements.push_back(parseStatement());
    }

    return statements;
}

unique_ptr<Statement> Parser::parseStatement()
{

    if (check(TOKEN_PRINT))
    {
        advance();

        unique_ptr<Expression> value = parseExpression();
        consume(TOKEN_SEMI, "Expected ; after print value or end of line");

        return make_unique<PrintStatement>(move(value));
    }

    if (check(TOKEN_VAR))
    {
        advance();

        Token name = consume(TOKEN_ID, "Expected variable name");
        consume(TOKEN_ASSIGN, "Expected '=' after variable name");
        unique_ptr<Expression> initializer = parseExpression();

        consume(TOKEN_SEMI, "Expected ';' after vaiable decleartion");

        return make_unique<VarDeclaration>(name.value, move(initializer));
    }
    if (check(TOKEN_IF))
    {
        return parseIfStatement();
    }
    if (check(TOKEN_LBRACE))
    {
        return parseBlock();
    }
    cout << "[Error] Unknown statement parsing logic pending." << endl;
    exit(1);
}

unique_ptr<Statement> Parser::parseIfStatement()
{
    advance();
    consume(TOKEN_LPAREN, "Expected '(' after if ");
    unique_ptr<Expression> condition = parseExpression();
    consume(TOKEN_RPAREN, "Expected ')' after condition");

    unique_ptr<Statement> thenBranch = parseStatement();
    unique_ptr<Statement> elseBranch = nullptr;

    if (check(TOKEN_ELSE))
    {
        advance();
        elseBranch = parseStatement();
    }
    return make_unique<IfStatement>(move(condition), move(thenBranch), move(elseBranch));
}

unique_ptr<Statement> Parser::parseBlock()
{
    advance();
    vector<unique_ptr<Statement>> statements;
    while (!check(TOKEN_RBRACE) && !isAtEnd())
    {
        statements.push_back(parseStatement());
    }
    consume(TOKEN_RBRACE, "Expected '}' after block");
    return make_unique<BlockStatement>(move(statements));
}

unique_ptr<Expression> Parser::parseExpression()
{
    unique_ptr<Expression> expr = parseTerm();

    while (check(TOKEN_PLUS) || check(TOKEN_MINUS))
    {
        TokenType op = advance().type;
        unique_ptr<Expression> right = parseTerm();
        expr = make_unique<BinaryExpr>(move(expr), op, move(right));
    }

    return expr;
}

unique_ptr<Expression> Parser::parseTerm()
{
    unique_ptr<Expression> expr = parsePrimary();

    while (check(TOKEN_STAR) || check(TOKEN_SLASH))
    {
        TokenType op = advance().type;
        unique_ptr<Expression> right = parsePrimary();
        expr = make_unique<BinaryExpr>(move(expr), op, move(right));
    }
    return expr;
}

unique_ptr<Expression> Parser::parsePrimary()
{
    if (check(TOKEN_NUMBER))
        return make_unique<LiteralExpr>(advance().value, TOKEN_NUMBER);
    if (check(TOKEN_STRING))
        return make_unique<LiteralExpr>(advance().value, TOKEN_STRING);
    if (check(TOKEN_TRUE))
        return make_unique<LiteralExpr>("true", TOKEN_TRUE);
    if (check(TOKEN_FALSE))
        return make_unique<LiteralExpr>("false", TOKEN_FALSE);
    if (check(TOKEN_ID))
        return make_unique<VariableExpr>(advance().value);
    if (check(TOKEN_LPAREN))
    {
        advance();
        unique_ptr<Expression> expr = parseExpression();
        consume(TOKEN_RPAREN, "Expected ')'");
        return expr;
    }

    cout << "Parser Error: Expected expression." << endl;
    exit(1);
}
