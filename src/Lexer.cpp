#include "Lexer.h"
#include <cctype>

vector<Token> Lexer::tokenize()
{
    vector<Token> tokens;

    while (pos < source.length())
    {
        char current = source[pos];

        if (isspace(current))
        {
            pos++;
            continue;
        }

        if (current == '+')
        {
            tokens.push_back({TOKEN_PLUS, "+"});
            pos++;
        }
        else if (current == '=')
        {
            tokens.push_back({TOKEN_ASSIGN, "="});
            pos++;
        }
        else if (current == ';')
        {
            tokens.push_back({TOKEN_SEMI, ";"});
            pos++;
        }
        // else if(current == '-'){
        //     tokens.push_back({TOKEN_MINUS,"-"});
        //     pos++;
        // }

        else if (current == '(')
        {
            tokens.push_back({TOKEN_LPAREN, "("});
            pos++;
        }
        else if (current == ')')
        {
            tokens.push_back({TOKEN_RPAREN, ")"});
            pos++;
        }
        else if (current == '"')
        {
            pos++;
            string value = "";
            while (pos < source.length() && source[pos] != '"')
            {
                value += source[pos];
                pos++;
            }
            pos++;
            tokens.push_back({TOKEN_STRING, value});
        }
        else if (isdigit(current))
        {
            string value = "";
            while (pos < source.length() && isdigit(source[pos]))
            {
                value += source[pos];
                pos++;
            }
            tokens.push_back({TOKEN_NUMBER, value});
        }
        else if (isalpha(current))
        {
            string value = "";
            while (pos < source.length() && isalnum(source[pos]))
            {
                value += source[pos];
                pos++;
            }
            if (keywords.count(value))
            {
                tokens.push_back({keywords[value], value});
            }
            else
            {
            }
        }
    }
}
