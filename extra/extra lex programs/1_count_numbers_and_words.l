%{
#include <stdio.h>
int numbers = 0, words = 0;
%}

%%
[0-9]+            { numbers++; }
[a-zA-Z]+         { words++; }
.|\n              ;
%%

int main()
{
    printf("Enter text (Ctrl+D to end):\n");
    yylex();
    printf("\nNumbers : %d\n", numbers);
    printf("Words   : %d\n", words);
    return 0;
}

int yywrap()
{
    return 1;
}
