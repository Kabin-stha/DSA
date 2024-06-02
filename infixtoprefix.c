#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item)
{
    stack[++top] = item;
}

char pop()
{
    return stack[top--];
}

int precedence(char symbol)
{
    return (symbol == '+' || symbol == '-') ? 1 : (symbol == '*' || symbol == '/') ? 2
                                              : (symbol == '^')                    ? 3
                                                                                   : 0;
}

void infixToPrefix(char infix[], char prefix[])
{
    int i, j = 0;
    strrev(infix);
    for (i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == ')')
            infix[i] = '(';
        else if (infix[i] == '(')
            infix[i] = ')';
    }

    for (i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] >= 'a' && infix[i] <= 'z')
            prefix[j++] = infix[i];
        else if (infix[i] == '(')
            push(infix[i]);
        else if (infix[i] == ')')
        {
            while (stack[top] != '(')
                prefix[j++] = pop();
            pop();
        }
        else
        {
            while (precedence(stack[top]) >= precedence(infix[i]))
                prefix[j++] = pop();
            push(infix[i]);
        }
    }
    while (top != -1)
        prefix[j++] = pop();
    prefix[j] = '\0';
    strrev(prefix);
}

int main()
{
    char infix[MAX], prefix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}
