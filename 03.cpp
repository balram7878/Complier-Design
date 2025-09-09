// Count total no of operators in a file (taking file from user).

#include <iostream>
#include <string>
#include <unordered_set>
#include <fstream>
using namespace std;

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

int main()
{
    string file_name,word;
    unordered_set<char> op_set;

    cout << "Enter file name: ";
    getline(cin, file_name);

    ifstream file(file_name);
    if (!file)
    {
        cerr << "Could not open file\n";
        return 1;
    }

    while (file >> word)
    {
   
        for (char ch : word)
        {
            if (isOperator(ch))
                op_set.insert(ch);
        }
    }

    cout << "Unique operators found = " << op_set.size() << "\n";
    for (auto &op : op_set)
    {
        cout << op << endl;
    }

    return 0;
}
