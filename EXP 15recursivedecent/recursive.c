#include <stdio.h>

char input[100];
int pos = 0;
int error_flag = 0;

void E();
void Eprime();
void T();
void Tprime();
void F();

void E()
{
    T();
    if (!error_flag)
        Eprime();
}

void Eprime()
{
    if (input[pos] == '+')
    {
        pos++;
        T();
        if (!error_flag)
            Eprime();
    }
}

void T()
{
    F();
    if (!error_flag)
        Tprime();
}

void Tprime()
{
    if (input[pos] == '*')
    {
        pos++;
        F();
        if (!error_flag)
            Tprime();
    }
}

void F()
{
    if (input[pos] == 'i')
    {
        pos++;
    }
    else if (input[pos] == '(')
    {
        pos++;
        E();

        if (!error_flag && input[pos] == ')')
            pos++;
        else
            error_flag = 1;
    }
    else
    {
        error_flag = 1;
    }
}

int main()
{
    printf("Enter the expression: ");
    scanf("%s", input);

    E();

    if (input[pos] != '\0')
        error_flag = 1;

    if (error_flag)
        printf("Invalid expression\n");
    else
        printf("Valid expression\n");

    return 0;
}
