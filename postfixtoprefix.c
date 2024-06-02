#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char item[])
{
    strcpy(stack[++top], item);
}

char *pop()
{
    return stack[top--];
}

void postfixToPrefix(char postfix[], char prefix[])
{
    int i, len = strlen(postfix);
    char operand1[MAX], operand2[MAX], temp[MAX];

    for (i = 0; i < len; i++)
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
