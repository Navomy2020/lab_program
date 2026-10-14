#include <stdio.h>
#include <string.h>

char stack[50], input[50];
int top = -1;

void reduce()
{
    if (top >= 0 && stack[top] == 'i')
    {
        stack[top] = 'E';
        printf("Reduce E -> i\n");
    }
    else if (top >= 2 &&
             stack[top] == 'E' &&
             stack[top - 1] == '+' &&
             stack[top - 2] == 'E')
    {
        top -= 2;
        stack[top] = 'E';
        printf("Reduce E -> E+E\n");
    }
    else if (top >= 2 &&
             stack[top] == 'E' &&
             stack[top - 1] == '*' &&
             stack[top - 2] == 'E')
    {
        top -= 2;
        stack[top] = 'E';
        printf("Reduce E -> E*E\n");
    }
}

int main()
{
    int i;

    printf("Enter input string: ");
    scanf("%s", input);

    printf("\nShift Reduce Steps:\n");

    for (i = 0; input[i] != '\0'; i++)
    {
        stack[++top] = input[i];
        stack[top + 1] = '\0';

        printf("Shift %c\tStack: %s\n", input[i], stack);

        reduce();
        stack[top + 1] = '\0';
    }

    while (top > 0)
    {
        int oldtop = top;
        reduce();

        if (oldtop == top)
            break;

        stack[top + 1] = '\0';
    }

    if (top == 0 && stack[0] == 'E')
        printf("\nString Accepted\n");
    else
        printf("\nString Rejected\n");

    return 0;
}
