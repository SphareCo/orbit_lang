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
        else if(current == '='){
            tokens.push_back({TOKEN_ASSIGN,"="});
            pos++;
        }
        else if(current == ';'){
            tokens.push_back({TOKEN_SEMI,";"});
            pos++;
        }
        // else if(current == '-'){
        //     tokens.push_back({TOKEN_MINUS,"-"});
        //     pos++;
        // }

        else if(current == '('){
            tokens.push_back({TOKEN_LPAREN,"("});
            pos++;
        }
        else if(current == ')'){
            tokens.push_back({TOKEN_RPAREN,")"});
            pos++;
        }
    }
}
