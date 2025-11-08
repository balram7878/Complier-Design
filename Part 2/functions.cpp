#include <string>
using namespace std;

// To identify whether a given string is a keyword or not.
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

// To identify whether a given character is a operator or not.

const char operators[] = {'+', '-', '*', '/', '%', '<', '>', '=', '!', '&', '|'};

bool isOperator(const char &op)
{
    int n = sizeof(operators) / sizeof(operators[0]);
    for (int i = 0; i < n; i++)
    {
        if (op == operators[i])
            return true;
    }
    return false;
}

// to indentify whether a given character is symbol or not

const char symbols[] = {'(', ')', '{', '}', '[', ']',';',':','"','"'};

bool isSymbol(const char &ch)
{
    int n = sizeof(symbols) / sizeof(symbols[0]);
    for (int i = 0; i < n; i++)
    {
        if (ch == symbols[i])
            return true;
    }
    return false;
}
