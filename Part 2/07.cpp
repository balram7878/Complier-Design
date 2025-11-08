#include <iostream>
#include <string>
#include "helper_functions.h"
using namespace std;

int main()
{
    string input;
    cout << "Enter an IF statement:\n";
    getline(cin, input);

    cout << "Tokens:\n";
    string token = "";
    for (int i = 0; i < input.size(); i++)
    {
        char ch = input[i];
        if (isspace(ch))
        {
            if (!token.empty())
            {

                if (isKeyword(token))
                    cout << "Keyword: " << token << endl;
                else
                    cout << "Identifier: " << token << endl;
                token = "";
            }
            continue;
        }

        if (isOperator(ch))
        {
            if (!token.empty())
            {
                if (isKeyword(token))
                    cout << "Keyword: " << token << endl;
                else
                    cout << "Identifier: " << token << endl;
                token = "";
            }
            string op(1, ch);
            if (i + 1 < input.size() && isOperator(input[i + 1]))
            {
                op += input[i + 1];
                i++;
            }
            cout << "Operator: " << op << "\n";
        }

        else if (isSymbol(ch))
        {
            if (!token.empty())
            {
                if (isKeyword(token))
                    cout << "Keyword: " << token << endl;
                else
                    cout << "Identifier: " << token << endl;
                token = "";
            }
            cout << "Symbol: " << ch << "\n";
        }
        else
            token += ch;
    }

    if (!token.empty())
    {
        if (isKeyword(token))
            cout << "Keyword: " << token << endl;
        else
            cout << "Identifier: " << token << endl;
        token = "";
    }

    return 0;
}