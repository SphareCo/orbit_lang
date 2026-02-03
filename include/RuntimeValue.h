// This is header to insure that a file include only once
#ifndef RUNTIME_VALUE_H
#define RUNTIME_VALUE_H

#include <string>
#include <iostream>
#include <cmath>

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

    RuntimeValue()
    {
        type = VAL_NULL;
        numberVal = 0;
        boolVal = false;
    }

    RuntimeValue(double val)
    {
        type = VAL_NUMBER;
        numberVal = val;
        boolVal = false;
    }

    RuntimeValue(string val)
    {
        type = VAL_STRING;
        stringVal = val;
        numberVal = 0;
        boolVal = false;
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
        {
            string s = to_string(numberVal);
            s.erase(s.find_last_not_of('0') + 1, string::npos);
            if (s.back() == '.')
                s.pop_back();
            return s;
        }

        else if (type == VAL_STRING)
        {
            return stringVal;
        }
        else if (type == VAL_BOOL)
        {
            return boolVal ? "true" : "false";
        }
        else
        {
            return "empty";
        }
    }
};

#endif