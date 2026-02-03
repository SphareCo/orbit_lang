#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <map>
#include <string>
#include <iostream>
#include "RuntimeValue.h"

using namespace std;

class Environment
{
private:
    map<string, RuntimeValue> values;
    Environment *enclosing;

public:
    Environment() : enclosing(nullptr) {}
    Environment(Environment *parent) : enclosing(parent) {}

    void define(string name, RuntimeValue val)
    {
        values[name] = val;
    }

    RuntimeValue get(string name)
    {
        if (values.count(name))
        {
            return values[name];
        }

        if (enclosing != nullptr)
        {
            return enclosing->get(name);
        }
        cout << "RunTime Error: Variable ' " << name << " ' not defined." << endl;
        exit(1);
    }
};

#endif