#include <stdio.h>
#include <ctype.h>

int stack[100];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char exp[]) {
    for (int i = 0; exp[i] != '\0'; i++) {

        // Skip spaces
        if (exp[i] == ' ')
            continue;

        // If operand (digit)
        if (isdigit(exp[i])) {
            push(exp[i] - '0');    // convert char to int
        }

        else {
            int val1 = pop();
            int val2 = pop();

            switch (exp[i]) {
                case '+': push(val2 + val1); break;
                case '-': push(val2 - val1); break;
                case '*': push(val2 * val1); break;
                case '/': push(val2 / val1); break;
                case '%': push(val2 % val1); break;
            }
        }
    }

    return pop();    // Final result
}

int main() {
    char exp[100];

    printf("Enter postfix expression: ");
    fgets(exp, 100, stdin);

    printf("Result = %d\n", evaluatePostfix(exp));
    return 0;
}
