// Count total no. of keywords in a file (taking file from user)

#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
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
    string file_name, word;
    int count = 0;
    unordered_set<string> str_set;
    cout << "Enter file name: ";
    getline(cin, file_name);
    ifstream file(file_name);
    if (!file)
    {
        cerr << "could not open file\n";
        return 1;
    }
    while (file >> word)
        if (isKeyword(word))
            str_set.insert(word);

    for (auto &e : str_set)
        cout << e << " " << endl;
    cout << "Total keywords: " << str_set.size();

    return 0;
}
