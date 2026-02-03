#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <iostream>
#include <memory>
#include "TokenType.h"
#include "AST.h"
#include "Lexer.h"

using namespace std;

class Parser
{
private:
    vector<Token> tokens;
    int current;

    bool isAtEnd()
    {
        return peek().type == TOKEN_EOF;
    }

    Token peek()
    {
        return tokens[current];
    }

    Token advance()
    {
        if (!isAtEnd())
            current++;
        return tokens[current - 1];
    }

    bool check(TokenType type)
    {
        if (isAtEnd())
            return false;
        return peek().type == type;
    }

    // bool match(TokenType type)
    // {
    //     if (check(type))
    //     {
    //         advance();
    //         return true;
    //     }
    //     return false;
    // }

    Token consume(TokenType type, string message)
    {
        if (check(type))
            return advance();
        cout << "Parsor Error" << message << endl;
        exit(1);
    }

public:
    Parser(vector<Token> t) : tokens(t), current(0) {}

    vector<unique_ptr<Statement>> parse();

    unique_ptr<Statement> parseStatement();
    unique_ptr<Statement> parseIfStatement();
    unique_ptr<Statement> parseBlock();
    unique_ptr<Expression> parseExpression();
    unique_ptr<Expression> parseTerm();
    unique_ptr<Expression> parsePrimary();
};

#endif