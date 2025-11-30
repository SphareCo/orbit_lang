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
    cout << "[Error] Unknown statement parsing logic pending." << endl;
    exit(1);
}

unique_ptr<Expression> Parser::parseExpression()
{
    return parsePrimary();
}

unique_ptr<Expression> Parser::parsePrimary()
{
    if (check(TOKEN_NUMBER))
    {
        Token t = advance();
        return make_unique<LiteralExpr>(t.value, TOKEN_NUMBER);
    }

    if (check(TOKEN_STRING))
    {
        Token t = advance();
        return make_unique<LiteralExpr>(t.value, TOKEN_STRING);
    }

    if(check(TOKEN_ID)){
        Token t  = advance();

        return make_unique<VariableExpr>(t.value);
    }

    cout<<"[ERROR] Expected expression (Number, Stirng and Vaiable)"<<endl;
    exit(1);
}
