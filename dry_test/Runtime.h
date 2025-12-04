#ifndef RUNTIME_H
#define RUNTIME_H

#include <iostream>
#include <string>

using namespace std;

enum ValueType
{
    VAL_NULL,
    VAL_NUMBER,
    VAL_STRING,
    VAL_BOOL
};
struct RuntimeValue
{
    ValueType type;
    double numberVal;
    string stringVal;
    bool boolVal;

    // for nulltype value
    RuntimeValue()
    {
        type = VAL_NULL;
        numberVal = 0;
    }
    // for double type value
    RuntimeValue(double val)
    {
        type = VAL_NUMBER;
        numberVal = val;
    }
    // for string type value
    RuntimeValue(string val)
    {
        type = VAL_STRING;
        stringVal = val;
    }

    RuntimeValue(bool val)
    {
        type = VAL_BOOL;
        boolVal = val;
        numberVal = 0;
    }

    string asString() const
    {
        if (type == VAL_NUMBER)
            return to_string(numberVal);
        if (type == VAL_STRING)
            return stringVal;
        if (type == VAL_BOOL)
            return boolVal ? "true" : "false";
        return "empty";
    }
};

#endif