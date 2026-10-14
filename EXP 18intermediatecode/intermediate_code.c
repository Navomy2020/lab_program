#include <stdio.h>
#include <string.h>

char stack[50][20];
int top = - 1;
int temp = 1;

void push(char str[])
{
    top++;
    strcpy(stack[top], str);
}

void pop(char str[])
{
    strcpy(str, stack[top]);
    top--;
}

int precedence(char op)
{
    if (op == '*' || op == '/')
        return 2;

    if (op == '+' || op == '-')
        return 1;

    return 0;
}

void generate(char op)
{
    char a[20], b[20], result[20];

    pop(b);
    pop(a);

    sprintf(result, "t%d", temp);

    printf("%s = %s %c %s\n", result, a, op, b);

    push(result);

    temp++;
}

int main()
{
    char expr[100];
    char operators[50];
    int optop = -1;
    int i;

    printf("Enter expression: ");
    scanf("%s", expr);

    printf("\nIntermediate Code:\n");

    for (i = 0; expr[i] != '\0'; i++)
    {
        /* Operand */
        if ((expr[i] >= 'a' && expr[i] <= 'z') ||
            (expr[i] >= 'A' && expr[i] <= 'Z') ||
            (expr[i] >= '0' && expr[i] <= '9'))
        {
            char operand[2];

            operand[0] = expr[i];
            operand[1] = '\0';

            push(operand);
        }

        /* Opening parenthesis */
        else if (expr[i] == '(')
        {
            operators[++optop] = expr[i];
        }

        /* Closing parenthesis */
        else if (expr[i] == ')')
        {
            while (optop >= 0 && operators[optop] != '(')
            {
                generate(operators[optop--]);
            }

            optop--;
        }

        /* Operator */
        else
        {
            while (optop >= 0 &&
                   operators[optop] != '(' &&
                   precedence(operators[optop]) >= precedence(expr[i]))
            {
                generate(operators[optop--]);
            }

            operators[++optop] = expr[i];
        }
    }

    /* Process remaining operators */
    while (optop >= 0)
    {
        generate(operators[optop--]);
    }

    printf("Result = %s\n", stack[top]);

    return 0;
}
