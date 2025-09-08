#include <iostream>
#include<string>
#include<fstream>
#include<unordered_set>
using namespace std;

class Characters

int main()
{

    string file_name;
    char ch;
    unordered_set<char>

    cout<<"Enter file name: ";
    getline(cin,file_name);
    fstream file(file_name);
    if(!file){
        cerr<<"could not open file\n";
        return 1;
    }
    while(file.get(ch))
    unordered_set


    return 0;
}