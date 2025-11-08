%{
#include <iostream>
#include <cstdio>
using namespace std;

int keywords = 0;
%}

%%
\bfloat\b        { keywords++; }
\bdouble\b       { keywords++; }
\bint\b          { keywords++; }
\bclass\b        { keywords++; }
\bchar\b         { keywords++; }
\bbool\b         { keywords++; }
\bif\b           { keywords++; }
\belse\b         { keywords++; }
\breturn\b       { keywords++; }
\btrue\b         { keywords++; }
\bfalse\b        { keywords++; }
\busing\b        { keywords++; }
\bnamespace\b    { keywords++; }

.|\n             { /* ignore everything else */ }
%%

int main(int argc, char* argv[])
{
    if (argc > 1)
        yyin = fopen(argv[1], "r");
    else
        yyin = stdin;

    yylex();
    cout << "Total keywords: " << keywords << endl;
    return 0;
}

int yywrap() {
    return 1;
}
