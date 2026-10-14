%{
#include <stdio.h>

%}

%%
int|float|char|double|void|return|if|else|for|while|do|switch|case|break   { printf("%s : KEYWORD\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*                                                   { printf("%s : IDENTIFIER\n", yytext); }
[0-9]+(\.[0-9]+)?                                                        { printf("%s : NUMBER\n", yytext); }
.|\n                                                                     ;
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
