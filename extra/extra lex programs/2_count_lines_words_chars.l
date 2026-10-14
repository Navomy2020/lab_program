%{
#include <stdio.h>
int lines = 0, words = 0, chars = 0;
%}

%%
\n          { lines++; chars++; }
[ \t]+      { chars += yyleng; }
[^ \t\n]+   { words++; chars += yyleng; }
%%

int main()
{
    printf("Enter text (Ctrl+D to end):\n");
    yylex();
    printf("\nLines      : %d\n", lines);
    printf("Words      : %d\n", words);
    printf("Characters : %d\n", chars);
    return 0;
}

int yywrap()
{
    return 1;
}
