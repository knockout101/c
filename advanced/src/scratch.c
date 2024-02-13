/*
Total Monthly
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int strcopy(char* buffer, char* string);
int strlength(char* const string);
char* alphaStrip(char* string);

int main(void)
{
    char *string = "Hello1";

    printf("%s", alphaStrip(string));

    return 0;
}

int strcopy(char* buffer, char* string)
{
    int i = 0;
    while(string[i] != '\0')
    {
        buffer[i] = string[i];
        i++;
    }

    buffer[i] = '\0';

    return 1;
}

int strlength(char* const string)
{
    int count = 0;
    for(int i = 0; string[i] != '\0'; i++)
        count++;
    return count;
}

char* alphaStrip(char* string)
{
    int i , j = 0;

    char temp[100];

    for(i = 0; string[i] != '\0'; ++i)
    {
        if(isalpha(string[i]))
            temp[j++] = string[i];
    }

    temp[j] = '\0';

    for(i = 0; i < strlength(string); i++)
        string[i] = '\0';

    strcopy(string, temp);

    return string;
}

