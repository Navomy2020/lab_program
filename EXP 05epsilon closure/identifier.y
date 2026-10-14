%{
#include <stdio.h>
#include <ctype.h>

int yylex(void);
int yyerror(char *s);
%}

%token LETTER DIGIT

%%

identifier:
      LETTER
    | identifier LETTER
    | identifier DIGIT
    ;

%%

int yylex(void)
{
    int ch = getchar();

    if (isalpha(ch))
        return LETTER;

    if (isdigit(ch))
        return DIGIT;

    if (ch == '\n' || ch == EOF)
        return 0;

    return ch;
}

int yyerror(char *s)
{
    return 1;
}

int main()
{
    printf("Enter an identifier: ");

    if (yyparse() == 0)
        printf("Valid identifier\n");
    else
        printf("Invalid identifier\n");

    return 0;
}
