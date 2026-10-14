%{
#include <stdio.h>
int vowels = 0, consonants = 0;
%}

%%
[aeiouAEIOU]                       { vowels++; }
[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z]    { consonants++; }
.|\n                                ;
%%

int main()
{
    printf("Enter text (Ctrl+D to end):\n");
    yylex();
    printf("\nVowels     : %d\n", vowels);
    printf("Consonants : %d\n", consonants);
    return 0;
}

int yywrap()
{
    return 1;
}
