#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char item[])
{
    if (top < MAX - 1)
    {
        strcpy(stack[++top], item);
    }
    else
    {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE); // Terminate the program on stack overflow
    }
}

char *pop()
{
    if (top >= 0)
    {
        return stack[top--];
    }
    else
    {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE); // Terminate the program on stack underflow
    }
}

void postfixToPrefix(char postfix[], char prefix[])
{
    int len = strlen(postfix);
    char operand1[MAX], operand2[MAX], temp[MAX];

    for (int i = 0; i < len; i++)
    {
        if (postfix[i] >= 'a' && postfix[i] <= 'z')
        {
            sprintf(temp, "%c", postfix[i]);
            push(temp);
        }
        else
        {
            strcpy(operand2, pop());
            strcpy(operand1, pop());
            sprintf(temp, "%c%s%s", postfix[i], operand1, operand2);
            push(temp);
        }
    }
    strcpy(prefix, pop());
}

int main()
{
    char postfix[MAX], prefix[MAX];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    postfixToPrefix(postfix, prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}
