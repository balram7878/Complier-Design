// Count total occurrence of each character in a given file (taking file from user).

#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
using namespace std;

int main()
{

    // string file_name;
    char ch;
    int arr[255] = {0};
    // cout << "Enter file name: ";
    // getline(cin, file_name);
    fstream file("sample.txt");
    if (!file)
    {
        cerr << "could not open file\n";
        return 1;
    }
    while (file.get(ch))
        arr[(int)ch]++;

    cout << "Character frequencies:\n";
    for (int i = 0; i < 256; i++)
    {
        if (arr[i] > 0)
            cout << (char)i << " : " << arr[i] << endl;
    }
    return 0;
}