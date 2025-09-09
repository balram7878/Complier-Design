// Write a C program to insert, delete and display the entries in Symbol Table.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Symbol
{
public:
    string name, type;
    int addr;
};

class SymbolTable
{
    vector<Symbol> table;

public:
    void insert()
    {
        cout << "Enter name, type, and address: \n";
        Symbol s;
        cin >> s.name >> s.type >> s.addr;
        table.push_back(s);
        cout << "Inserted.\n";
    }

    void display()
    {
        if (table.empty())
        {
            cout << "Symbol table is empty.\n";
            return;
        }
        cout << "\nSymbol Table:\n";
        cout << "Name\tType\tAddress\n";
        for (auto s : table)
            cout << s.name << "\t" << s.type << "\t" << s.addr << "\n";
    }

    void del()
    {
        string symbol;
        cout << "Enter symbol to delete: ";
        cin >> symbol;
        for (auto i = table.begin(); i != table.end(); i++)
        {
            if (i->name == symbol)
            {
                table.erase(i);
                cout << "deleted\n";
                return;
            }
        }
        cout << "not found";
        return;
    }
};

int main()
{
    int choice;
    SymbolTable ob;
    while (1)
    {
        cout << "\n1.Insert\n2.Delete\n3.Display\n4.Exit\nChoice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            ob.insert();
            break;
        case 2:
            ob.del();
            break;
        case 3:
            ob.display();
            break;
        case 4:
            return 0;
        default:
            cout << "invalid choice\n";
        }
    }
    return 0;
}