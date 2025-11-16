#include <stdio.h>
#include <stdlib.h>
int size;
int top = -1;
int isFull()
{
    if (top == size-1)
    {
        return 1;
    }
    return 0;
}
int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}
char pop(char stack[])
{
    if (isEmpty() == 1)
        return ' ';
    int ele = stack[top];
    top--;
    return ele;
}
char peek(char stack[])
{
    if (isEmpty() == 1)
        return ' ';
    int ele = stack[top];
    return ele;
}
void push(char stack[], char data)
{
    if (isFull() != 1)
    {
        top++;
        stack[top] = data;
    }
}
// a + b
// a b +
int compare(char old, char new)
{
   
    if (((old == '+' || old == '-') && (new == '*' || new == '/')) || old=='(')
    {
        return 1;
    }
    return 0;
}
int main()
{
    int n;
    printf("enter the size of the expression \n");
    scanf("%d", &n);
    char exp[n];
    printf("enter the expression");
    scanf("%s", exp);   
    // create a stack
    size = n;
    char stack[n];
    printf("\nthe required postfix expression is \n");
    for (int i = 0; i < n; i++)
    {
        if (exp[i] == ')')
        {

            char m = pop(stack);
            while (m != '(' && isEmpty() != 1)
            {
                printf("%c ", m);
                m = pop(stack);
            }
        }
        else if (exp[i] == '(')
        {
            push(stack, exp[i]);
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            int t = compare(peek(stack), exp[i]);
            if (t == 1)
            {
                push(stack, exp[i]);
            }
            else if (t == 0)
            {
                while (t != 1 && isEmpty() != 1)
                {
                    char m = pop(stack);
                    printf("%c ", m);
                    t = compare(m, exp[i]);
                }
                push(stack, exp[i]);
            }
        }
        else
        {
            printf("%c ", exp[i]);
        }
    }
    while (!isEmpty())
    {
        printf("%c ", pop(stack));
    }
}