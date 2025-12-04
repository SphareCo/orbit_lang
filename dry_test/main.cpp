#include "Runtime.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Runtime value for number like decimal or integer
    RuntimeValue v1(234.34);
    cout << "Number : " << v1.asString() << endl;

    // Runtime value for string like "Sphare CO." or "Orbit Programming lanugage"
    RuntimeValue v2("shubham kumar");
    cout << "String : " << v2.asString() << endl;

    // Runtime value for bool value like "ture" or "false" or empty
    RuntimeValue v3(false);
    cout << "Boolean : " << v3.asString() << endl;
    return 0;
}