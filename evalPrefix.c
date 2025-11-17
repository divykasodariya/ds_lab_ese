#include <stdio.h>
#include <ctype.h>
#include <string.h>

int stack[100];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int evaluatePrefix(char exp[]) {
    int n = strlen(exp);

    for (int i = n - 1; i >= 0; i--) {

        if (exp[i] == ' ')
            continue;

        if (isdigit(exp[i])) {
            push(exp[i] - '0');  // convert char digit to int
        }
        else {
            int op1 = pop();
            int op2 = pop();

            switch (exp[i]) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
                case '%': push(op1 % op2); break;
            }
        }
    }

    return pop();
}

int main() {
    char exp[100];

    printf("Enter prefix expression: ");
    fgets(exp, 100, stdin);

    printf("Result = %d\n", evaluatePrefix(exp));
    return 0;
}
