#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) { stack[++top] = item; }
char pop() { return stack[top--]; }
int precedence(char c) { return (c == '+' || c == '-') ? 1 : (c == '*' || c == '/') ? 2   : (c == '^')               ? 3                                                : 0; }

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

void infixToPrefix(char infix[], char prefix[])
{
    reverseString(infix);
    for (int i = 0; infix[i]; i++)
    {
        if (infix[i] == ')')
            infix[i] = '(';
        else if (infix[i] == '(')
            infix[i] = ')';
    }

    int j = 0;
    for (int i = 0; infix[i]; i++)
    {
        if (isalpha(infix[i]))
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
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i]))
                prefix[j++] = pop();
            push(infix[i]);
        }
    }
    while (top != -1)
        prefix[j++] = pop();
    prefix[j] = '\0';
    reverseString(prefix);
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
