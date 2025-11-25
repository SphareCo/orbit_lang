#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../include/Lexer.h"

using namespace std;

string readFile(const string& path){
    ifstream file(path);
    if(!file.is_open()){
        cerr<<"Error: file'"<< path<<"'file not found"<<endl;
        exit(1);
    }
    stringstream buffer;
    buffer<<file.rdbuf();
    return buffer.str();

}
int main(int argc, char* argv[]){
    if (argc < 2){
        cout<< "Usage: orbit <script.orb>" << endl;
        return 1;
    }

    string sourceCode = readFile(argv[1]);
    Lexer lexer(sourceCode);
    vector <Token> tokens  =  lexer.tokenize();
    
    cout << "---Orbit Lexer Output(Tokens)---"<<endl;
    for(const auto& token: tokens ){
        cout<< "Token ID: "<< token.type << " || Token value: "<< token.value<<endl;
    }
    return 0;
}


