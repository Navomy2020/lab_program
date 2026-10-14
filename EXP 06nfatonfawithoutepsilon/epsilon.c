#include <stdio.h>

int n;
int matrix[10][10];
int closure[10][10];

void findClosure(int state, int current)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (matrix[current][i] == 1 && closure[state][i] == 0)
        {
            closure[state][i] = 1;
            findClosure(state, i);
        }
    }
}

int main()
{
    int i, j;

    printf("Enter number of states: ");
    scanf("%d", &n);

    printf("Enter epsilon transition matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        closure[i][i] = 1;
        findClosure(i, i);
    }

    printf("\nEpsilon Closure:\n");

    for (i = 0; i < n; i++)
    {
        printf("E-Closure(q%d) = { ", i);

        for (j = 0; j < n; j++)
        {
            if (closure[i][j] == 1)
                printf("q%d ", j);
        }

        printf("}\n");
    }

    return 0;
}
