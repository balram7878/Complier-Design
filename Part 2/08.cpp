#include <iostream>
#include <stack>
#include <map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// Grammar:
// E  -> T E'
// E' -> + T E' | ε
// T  -> F T'
// T' -> * F T' | ε
// F  -> (E) | id

map<pair<string, string>, vector<string>> parsingTable;

void initParsingTable() {
    // E rules
    parsingTable[{"E", "id"}] = {"T", "E'"};
    parsingTable[{"E", "("}] = {"T", "E'"};

    // E' rules
    parsingTable[{"E'", "+"}] = {"+", "T", "E'"};
    parsingTable[{"E'", ")"}] = {"ε"};
    parsingTable[{"E'", "$"}] = {"ε"};

    // T rules
    parsingTable[{"T", "id"}] = {"F", "T'"};
    parsingTable[{"T", "("}] = {"F", "T'"};

    // T' rules
    parsingTable[{"T'", "+"}] = {"ε"};
    parsingTable[{"T'", "*"}] = {"*", "F", "T'"};
    parsingTable[{"T'", ")"}] = {"ε"};
    parsingTable[{"T'", "$"}] = {"ε"};

    // F rules
    parsingTable[{"F", "id"}] = {"id"};
    parsingTable[{"F", "("}] = {"(", "E", ")"};
}

vector<string> tokenize(string input) {
    vector<string> tokens;
    stringstream ss(input);
    string tok;
    while (ss >> tok) tokens.push_back(tok);
    tokens.push_back("$");
    return tokens;
}

bool isTerminal(const string &symbol) {
    return !(symbol == "E" || symbol == "E'" || symbol == "T" || symbol == "T'" || symbol == "F");
}

void printStack(stack<string> s) {
    vector<string> v;
    while (!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
    for (int i = v.size() - 1; i >= 0; i--)
        cout << v[i] << " ";
}

int main() {
    initParsingTable();

    cout << "Enter input (tokens separated by space, e.g., 'id + id * id'):\n";
    string inputLine;
    getline(cin, inputLine);

    vector<string> tokens = tokenize(inputLine);

    stack<string> parseStack;
    parseStack.push("$");
    parseStack.push("E");

    int index = 0;
    string currentToken = tokens[index];

    cout << "\n--- Parsing Process ---\n";
    while (!parseStack.empty()) {
        string top = parseStack.top();
        cout << "\nStack: ";
        printStack(parseStack);
        cout << "\tCurrent Token: " << currentToken << endl;

        if (top == currentToken) {
            parseStack.pop();
            index++;
            currentToken = tokens[index];
        } else if (isTerminal(top)) {
            cout << "Error: Unexpected token '" << currentToken << "' after terminal '" << top << "'\n";
            return 0;
        } else {
            auto rule = parsingTable.find({top, currentToken});
            if (rule == parsingTable.end()) {
                cout << "Error: No rule for [" << top << ", " << currentToken << "]\n";
                return 0;
            }
            parseStack.pop();
            vector<string> production = rule->second;
            if (!(production.size() == 1 && production[0] == "ε")) {
                for (int i = production.size() - 1; i >= 0; i--) {
                    parseStack.push(production[i]);
                }
            }
        }
    }

    if (currentToken == "$")
        cout << "\nInput successfully parsed (Accepted)\n";
    else
        cout << "\nParsing failed (Extra tokens left)\n";

    return 0;
}
