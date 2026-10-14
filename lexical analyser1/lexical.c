#include <stdio.h>
#include <ctype.h>
#include <string.h>
char *keywords[] = {
    "int","float","char","double","if","else","while","for",
    "return","void","break","continue","switch","case","default",
    "do","long","short","unsigned","signed","const"
};
int isKeyword(char str[])
{
    int n = sizeof(keywords) / sizeof(keywords[0]);
    for(int i = 0; i < n; i++)
    {
        if(strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}
int main()
{
    FILE *fp;
    char ch, buffer[100];
    int i;
    fp = fopen("input.c", "r");
    if(fp == NULL)
    {
        printf("Cannot open file.\n");
        return 0;
    }
    while((ch = fgetc(fp)) != EOF)
    {
        if(ch == ' ' || ch == '\t' || ch == '\n')
            continue;
        if(ch == '/')
        {
            char next = fgetc(fp);
            if(next == '/')
            {
                while((ch = fgetc(fp)) != '\n' && ch != EOF);
                continue;
            }
            else if(next == '*')
            {
                while(1)
                {
                    ch = fgetc(fp);
                    if(ch == '*')
                    {
                        if((ch = fgetc(fp)) == '/')
                            break;
                    }
                }
                continue;
            }
            else
            {
                printf("%c : Operator\n", '/');
                ungetc(next, fp);
                continue;
            }
        }
        if(isalpha(ch) || ch == '_')
        {
            i = 0;
            buffer[i++] = ch;
            while((ch = fgetc(fp)) != EOF &&
                 (isalnum(ch) || ch == '_'))
            {
                buffer[i++] = ch;
            }
            buffer[i] = '\0';
            if(ch != EOF)
                ungetc(ch, fp);
            if(isKeyword(buffer))
                printf("%s : Keyword\n", buffer);
            else
                printf("%s : Identifier\n", buffer);
        }
        else if(isdigit(ch))
        {
            i = 0;
            buffer[i++] = ch;
            while((ch = fgetc(fp)) != EOF && isdigit(ch))
            {
                buffer[i++] = ch;
            }
            buffer[i] = '\0';
            if(ch != EOF)
                ungetc(ch, fp);
            printf("%s : Number\n", buffer);
        }
        else if(strchr("+-*=<>!%", ch))
        {
            printf("%c : Operator\n", ch);
        }
        else if(strchr("(){}[],;", ch))
        {
            printf("%c : Separator\n", ch);
        }
        else
        {
            printf("%c : Special Symbol\n", ch);
        }
    }
    fclose(fp);
    return 0;
}
