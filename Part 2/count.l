%{
#include <iostream>
#include <cstdio>
using namespace std;

int space_count = 0;
int word_count = 0;
int line_count = 0;
%}

%%
[ \t]+           { space_count++; }
\n               { line_count++; }
[a-zA-Z0-9_]+    { word_count++; }
.                { /* ignore other chars */ }
%%

int main(int argc, char* argv[])
{
    if (argc > 1)
        yyin = fopen(argv[1], "r");
    else
        yyin = stdin;  // default input

    yylex();  // run the lexer

    cout << "Lines: "  << line_count  << endl;
    cout << "Words: "  << word_count  << endl;
    cout << "Spaces: " << space_count << endl;

    return 0;
}

int yywrap() {
    return 1;
}

