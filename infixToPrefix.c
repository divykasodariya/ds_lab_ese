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

int compare(char old, char new)
{
    if(old==new){
        return 1;
    }
    if (((old == '+' || old == '-') && (new == '*' || new == '/' ||  new=='+' || new=='-')) || old==')')
    {
        return 1;
    }
    if (((old == '*' || old == '/') && (new == '*' || new == '/' )) || old==')')
    {
        return 1;
    }
    return 0;
}
int main()
{
    int n=9;
    printf("enter the size of the expression \n");
    scanf("%d", &n);
    char exp[n];
    printf("enter the expression");
   
    scanf("%s", exp);   
    // create a stack
    printf("current exp ; \n");
    for(int i=0;i<n;i++){
        printf("%c ",exp[i]);
    }
    printf("\n");
    size = n;
    char stack[n];
    char ans[n];
    int j =n-1;
    printf("\nthe required postfix expression is \n");
    for (int i = n-1; i >=0 ; i--)
    {   
        printf("%c current read \n",exp[i]);
        if (exp[i] == '(')
        {
        printf("popping until ) is found \n");

            char m = pop(stack);
            while (m != ')' && isEmpty() != 1)
            {
                if(j>=0)ans[j--]=m;
                // printf("%c ", m);
                m = pop(stack);
            }
        }
        else if (exp[i] == ')')
        {
            printf("pushing onto stack \n");
            push(stack, exp[i]);
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
         
            if(isEmpty()==1) {
                printf("pushing onto the stack \n");
                push(stack,exp[i]);
                continue;
            }
            int t = compare(peek(stack), exp[i]);
            if (t == 1)
            {
            printf("pushing onto stack \n");

                push(stack, exp[i]);
            }
            else if (t == 0)
            {
                printf("pop and the push\n");
                while (t != 1 && isEmpty() != 1)
                {
                    char m = pop(stack);
                    if(j>=0)ans[j--]=m;
               
                    // printf("%c ", m);
                    t = compare(m, exp[i]);
                }
                push(stack, exp[i]);
            }
        }
        else
        {
             if(j>=0)ans[j--]=exp[i];
            // printf("%c ", exp[i]);
        }
    }
    while (!isEmpty())
    {
         if(j>=0)ans[j--]=pop(stack);
               
        // printf("%c ", pop(stack));
    }

    for(int i =0;i<n;i++){
        printf("%c ",ans[i]);       
    }
}