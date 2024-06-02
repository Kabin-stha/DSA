#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct
{
    char *items[MAX];
    int top;
} Stack;

void push(Stack *stack, char *item)
{
    stack->items[++stack->top] = item;
}

char *pop(Stack *stack)
{
    return stack->items[stack->top--];
}

char *postfixToInfix(char *postfix)
{
    Stack stack = {.top = -1};
    for (int i = 0; postfix[i]; i++)
    {
        if (isspace(postfix[i]))
            continue;
        char *infix = (char *)malloc(MAX * sizeof(char));
        if (isalnum(postfix[i]))
        {
            sprintf(infix, "%c", postfix[i]);
        }
        else
        {
            char *op2 = pop(&stack);
            char *op1 = pop(&stack);
            sprintf(infix, "(%s%c%s)", op1, postfix[i], op2);
            free(op1);
            free(op2);
        }
        push(&stack, infix);
    }
    return pop(&stack);
}

int main()
{
    char postfix[MAX];
    printf("Enter a postfix expression: ");
    fgets(postfix, MAX, stdin);
    postfix[strcspn(postfix, "\n")] = 0;
    char *infix = postfixToInfix(postfix);
    printf("Infix expression: %s\n", infix);
    free(infix);
    return 0;
}
//dog days are over
