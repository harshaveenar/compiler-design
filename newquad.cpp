#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char op[10];
    char arg1[10];
    char arg2[10];
    char result[10];
} Quadruple;

void generateThreeAddressCode(const char *expression, Quadruple *quadruples, int *quadCount) {
	
    char temp[10];
    int tempCounter = 0;
    char operatorStack[10];
    int operatorTop = -1;

    for (int i = 0; i < strlen(expression); i++) {
        if (expression[i] >= 'a' && expression[i] <= 'z') {
            temp[tempCounter++] = expression[i];
            temp[tempCounter] = '\0';
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            if (operatorTop != -1) {
                if (operatorStack[operatorTop] == '*' || operatorStack[operatorTop] == '/') {
                    sprintf(quadruples[*quadCount].op, "%c", operatorStack[operatorTop--]);
                    sprintf(quadruples[*quadCount].arg1, "%s", temp);
                    sprintf(quadruples[*quadCount].arg2, "%c", '\0');
                    sprintf(quadruples[*quadCount].result, "T%d", (*quadCount)+1);
                    (*quadCount)++;
                }
            }
            operatorStack[++operatorTop] = expression[i];
            tempCounter = 0;
        }
    }

    for (int j = operatorTop; j >= 0; j--) {
        sprintf(quadruples[*quadCount].op, "%c", operatorStack[j]);
        sprintf(quadruples[*quadCount].arg1, "%s", temp);
        sprintf(quadruples[*quadCount].arg2, "%c", '\0');
        sprintf(quadruples[*quadCount].result, "T%d", (*quadCount)+1);
        (*quadCount)++;
    }
}

void printQuadruples(const Quadruple *quadruples, int quadCount) {
    printf("Quadruples:\n");
    for (int i = 0; i < quadCount; i++) {
        printf("(%s, %s, %s, %s)\n", quadruples[i].op, quadruples[i].arg1, quadruples[i].arg2, quadruples[i].result);
    }
}

int main() {
    char expression[100];
    printf("Enter an arithmetic expression: ");
    scanf("%s", expression);

    Quadruple quadruples[100];
    int quadCount = 0;

    generateThreeAddressCode(expression, quadruples, &quadCount);
    printQuadruples(quadruples, quadCount);

    return 0;
}

