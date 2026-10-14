%{
#include <stdio.h>
#include <stdlib.h>
%}

%%

int|float|char|double|void|return|if|else|for|while {
    printf("%s : KEYWORD\n", yytext);
}

[0-9]+ {
    printf("%s : NUMBER\n", yytext);
}

[a-zA-Z_][a-zA-Z0-9_]* {
    printf("%s : IDENTIFIER\n", yytext);
}

[\+\-\*\/=] {
    printf("%s : OPERATOR\n", yytext);
}

[;(),{}] {
    printf("%s : DELIMITER\n", yytext);
}

[ \t\n]+ ;

. {
    printf("%s : INVALID\n", yytext);
}

%%

int main()
{
    printf("Enter a program:\n");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
