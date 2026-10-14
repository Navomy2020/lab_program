%{
#include <stdio.h>

%}

%%
"+"|"-"|"*"|"/"|"%"        { printf("%s : ARITHMETIC OPERATOR\n", yytext); }
"=="|"!="|"<="|">="|"<"|">"   { printf("%s : RELATIONAL OPERATOR\n", yytext); }
.|\n                          ;
%%

int main()
{
    printf("Enter text (Ctrl+D to end):\n");
    yylex();

    return 0;
}

int yywrap()
{
    return 1;
}
