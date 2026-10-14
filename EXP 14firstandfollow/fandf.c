#include <stdio.h>
#include <string.h>
#define MAX 20
char lhs[MAX];
char rhs[MAX][MAX];
char first[MAX][MAX];
char follow[MAX][MAX];
int n;
int ntCount = 0;
int isNonTerminal(char c)
{
    for (int i = 0; i < ntCount; i++)
    {
        if (lhs[i] == c)
            return 1;
    }
    return 0;
}
int addToSet(char set[], char c)
{
    if (strchr(set, c) == NULL)
    {
        int len = strlen(set);
        set[len] = c;
        set[len + 1] = '\0';
        return 1;
    }
    return 0;
}
int getNTIndex(char c)
{
    for (int i = 0; i < ntCount; i++)
    {
        if (lhs[i] == c)
            return i;
    }
    return -1;
}
int main()
{
    int i, j, k;
    int changed;
    printf("Enter number of productions: ");
    scanf("%d", &n);
    printf("Enter productions (use # for epsilon):\n");
    for (i = 0; i < n; i++)
    {
        char production[MAX];
        scanf("%s", production);
        lhs[i] = production[0];
        int found = 0;
        for (j = 0; j < ntCount; j++)
        {
            if (lhs[j] == production[0])
            {
                found = 1;
                break;
            }
        }
        if (!found)
            ntCount++;

        strcpy(rhs[i], production + 2);
    }
    for (i = 0; i < MAX; i++)
    {
        first[i][0] = '\0';
        follow[i][0] = '\0';
    }
    do
    {
        changed = 0;
        for (i = 0; i < n; i++)
        {
            int A = getNTIndex(lhs[i]);
            int nullable = 1;
            for (j = 0; rhs[i][j] != '\0'; j++)
            {
                char symbol = rhs[i][j];
                if (!isNonTerminal(symbol))
                {
                    if (symbol == '#')
                        addToSet(first[A], '#');
                    else
                        changed |= addToSet(first[A], symbol);

                    nullable = 0;
                    break;
                }
                int B = getNTIndex(symbol);
                for (k = 0; first[B][k] != '\0'; k++)
                {
                    if (first[B][k] != '#')
                        changed |= addToSet(first[A], first[B][k]);
                }
                if (strchr(first[B], '#') == NULL)
                {
                    nullable = 0;
                    break;
                }
            }
            if (nullable)
                changed |= addToSet(first[A], '#');
        }
    } while (changed);
    printf("\nFIRST:\n");
    for (i = 0; i < ntCount; i++)
    {
        printf("FIRST(%c) = { ", lhs[i]);

        for (j = 0; first[i][j] != '\0'; j++)
            printf("%c ", first[i][j]);

        printf("}\n");
    }
    addToSet(follow[0], '$');
    do
    {
        changed = 0;
        for (i = 0; i < n; i++)
        {
            int A = getNTIndex(lhs[i]);
            int len = strlen(rhs[i]);
            for (j = 0; j < len; j++)
            {
                char Bsymbol = rhs[i][j];
                if (!isNonTerminal(Bsymbol))
                    continue;
                int B = getNTIndex(Bsymbol);
                int nullable = 1;
                for (k = j + 1; k < len; k++)
                {
                    char symbol = rhs[i][k];
                    if (!isNonTerminal(symbol))
                    {
                        if (symbol != '#')
                            changed |= addToSet(follow[B], symbol);

                        nullable = 0;
                        break;
                    }
                    int C = getNTIndex(symbol);
                    for (int x = 0; first[C][x] != '\0'; x++)
                    {
                        if (first[C][x] != '#')
                            changed |= addToSet(follow[B], first[C][x]);
                    }
                    if (strchr(first[C], '#') == NULL)
                    {
                        nullable = 0;
                        break;
                    }
                }
                if (nullable)
                {
                    for (int x = 0; follow[A][x] != '\0'; x++)
                        changed |= addToSet(follow[B], follow[A][x]);
                }
            }
        }
    } while (changed);
    printf("\nFOLLOW:\n");
    for (i = 0; i < ntCount; i++)
    {
        printf("FOLLOW(%c) = { ", lhs[i]);
        for (j = 0; follow[i][j] != '\0'; j++)
            printf("%c ", follow[i][j]);
        printf("}\n");
    }
    return 0;
}
