#include <stdio.h>
#include <string.h>
#include <ctype.h>

char prod[10][10];
char firstSet[10][10];
int n;

void findFirst(char *res, char c) {
    if (!isupper(c)) {
        strncat(res, &c, 1);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (prod[i][0] == c) {
            if (prod[i][3] == '#') {
                strncat(res, "#", 1);
            } else {
                findFirst(res, prod[i][3]);
            }
        }
    }
}

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter production %d (e.g., E->E+T): ", i + 1);
        scanf("%s", prod[i]);
    }

    for (int i = 0; i < n; i++) {
        char lhs = prod[i][0];
        char res[20] = "";
        findFirst(res, lhs);
        printf("FIRST(%c) = { %s }\n", lhs, res);
    }
    return 0;
}
