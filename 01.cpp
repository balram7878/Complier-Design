// To identify whether a given string is a keyword or not.

#include <iostream>
#include <string>
using namespace std;

const string keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", "double",
    "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register",
    "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef",
    "union", "unsigned", "void", "volatile", "while"};

bool isKeyword(const string &str)
{
    for (int i = 0; i < 32; i++)
    {
        if (str == keywords[i])
            return true;
    }
    return false;
}

int main()
{
    string str;
    cout << "Enter string: ";
    getline(cin, str);

    if (isKeyword(str))
        cout << str << " is a keyword\n";
    else
        cout << str << " is not a keyword\n";

    return 0;
}
