%{
#include <stdio.h>
int digits = 0, spaces = 0, special = 0;
%}

%%
[0-9]        { digits++; }
[ \t]        { spaces++; }
[a-zA-Z\n]   ;
.            { special++; }
%%

int main()
{
    printf("Enter text (Ctrl+D to end):\n");
    yylex();
    printf("\nDigits             : %d\n", digits);
    printf("Spaces             : %d\n", spaces);
    printf("Special characters : %d\n", special);
    return 0;
}

int yywrap()
{
    return 1;
}
