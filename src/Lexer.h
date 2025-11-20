#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <map>
#include <vector>
#include "../include/TokenType.h"

using namespace std;

struct Token
{
    TokenType type;
    string value;
};

class Lexer
{
private:
    string source;
    int pos;
    map<string, TokenType> keywords;

    void initKeywords()
    {
        keywords["print"] = TOKEN_PRINT;
        keywords["let"] = TOKEN_VAR;
        keywords["if"] = TOKEN_IF;
        keywords["else"] = TOKEN_ELSE;

        keywords["bolo"] = TOKEN_PRINT;
        keywords["manlo"] = TOKEN_VAR;
        keywords["agar"] = TOKEN_IF;
        keywords["warna"] = TOKEN_ELSE;
    }

public:
    Lexer(string src)
    {
        source = src;
        pos = 0;
        initKeywords();
    }

    vector<Token> tokenize();
};

#endif
