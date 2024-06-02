#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char item[])
{
    if (top == (MAX - 1))
    {
        printf("Stack Overflow\n");
        return;
    }
    strcpy(stack[++top], item);
}

char *pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

void prefixToInfix(char prefix[], char infix[])
{
    int i, len = strlen(prefix);
    char operand1[MAX], operand2[MAX], temp[MAX];

    for (i = len - 1; i >= 0; i--)
    {
        if (prefix[i] >= 'a' && prefix[i] <= 'z')
        {
            sprintf(temp, "%c", prefix[i]);
            push(temp);
        }
        else
        {
            strcpy(operand1, pop());
            strcpy(operand2, pop());
            sprintf(temp, "(%s%c%s)", operand1, prefix[i], operand2);
            push(temp);
        }
    }
    strcpy(infix, pop());
}

int main()
{
    char prefix[MAX], infix[MAX];
    printf("Enter prefix expression: ");
    scanf("%s", prefix);
    prefixToInfix(prefix, infix);
    printf("Infix expression: %s\n", infix);
    return 0;
}
