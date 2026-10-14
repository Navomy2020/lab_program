%{
#include <stdio.h>
int upper = 0, lower = 0;
%}

%%
[A-Z]     { upper++; }
[a-z]     { lower++; }
.|\n      ;
%%

int main()
{
    printf("Enter text (Ctrl+D to end):\n");
    yylex();
    printf("\nUppercase letters : %d\n", upper);
    printf("Lowercase letters : %d\n", lower);
    return 0;
}

int yywrap()
{
    return 1;
}
