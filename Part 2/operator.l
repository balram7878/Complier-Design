%{
#include <iostream>
#include <cstdio>
using namespace std;

int op = 0;
%}

%%
 
"<="           { op++; }
">="           { op++; }
"=="           { op++; }
"!="           { op++; }
"+="          { op++; }
"-="           { op++; }
"/="           { op++; }
"%="           { op++; }
"&&"    { op++; }
"||"    { op++; }
"!"     { op++; }

[+\-*/%=<>^]   { op++; } 
.              { /* ignore anything else */ }
%%

int main(int argc, char* argv[]) {
    if (argc > 1)
        yyin = fopen(argv[1], "r");
    else
        yyin = stdin;

    yylex();

    cout << "Operators: " << op << "\n";
    return 0;
}

int yywrap() {
    return 1;
}
