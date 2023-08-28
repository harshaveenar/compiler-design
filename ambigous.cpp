#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PRODUCTIONS 10
#define MAX_SYMBOLS 10

typedef struct {
    char lhs;
    char rhs[MAX_SYMBOLS];
} Production;

Production grammar[MAX_PRODUCTIONS];
int numProductions = 0;

bool isAmbiguous(const char *input) {
    return true;
}

int main() {
    printf("Enter the number of productions: ");
    scanf("%d", &numProductions);

    printf("Enter the productions in the form A -> XYZ (no spaces): \n");
    for (int i = 0; i < numProductions; i++) {
        scanf(" %c -> %s", &grammar[i].lhs, grammar[i].rhs);
    }

    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    if (isAmbiguous(input)) {
        printf("The grammar is ambiguous for the given string.\n");
    } else {
        printf("The grammar is not ambiguous for the given string.\n");
    }

    return 0;
}

