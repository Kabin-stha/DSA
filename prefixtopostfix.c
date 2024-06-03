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

void reverseString(char str[])
{
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++)
    {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void prefixToPostfix(char prefix[], char postfix[])
{
    int len = strlen(prefix);
    char operand1[MAX], operand2[MAX], temp[MAX];

    reverseString(prefix);

    for (int i = 0; i < len; i++)
    {
        if ((prefix[i] >= 'a' && prefix[i] <= 'z') || (prefix[i] >= 'A' && prefix[i] <= 'Z'))

        {
            sprintf(temp, "%c", prefix[i]);
            push(temp);
        }
        else
        {
            strcpy(operand1, pop());
            strcpy(operand2, pop());
            sprintf(temp, "%s%s%c", operand1, operand2, prefix[i]);
            push(temp);
        }
    }
    strcpy(postfix, pop());
}

int main()
{
    char prefix[MAX], postfix[MAX];
    printf("Enter prefix expression: ");
    scanf("%s", prefix);
    prefixToPostfix(prefix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
