/*
should contain implementations of various string manipulation functions
    - find the frequency of characters in a string 
    - remove all the characters in a string except Alphabets <-- need to look into function that creates this
    - Calculate the length of a string without using strlen 
    - concatenate two strings with using strcat 
    - copy a string manually without using strcpy 
    - find the substring of a given string

***removed the void alphaStrip(char* string) function because segfault unresolved***
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count( char* string, char ch)
{
    int count = 0, i = 0;
    
    while(string[i] != '\0')
    {
        if (string[i++] == ch)
            count++;
    }
    return count;
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
    for(int i = 0; string[i++] != '\0'; count++);
    return count;
}

char* strconcat(char* str1, char* str2)
{
    return strcat(str1, str2);
}

int findSub(char* string, char* subString)
{
    int index = 0, i = 0;

    while(string[i] != '\0')
    {
        if(string[i] == *subString)
        {
            int j = i, k = 0;
            while(subString[k] != '\0')
            {
                if(string[j++] != subString[k++])
                    k = 0;
                    break;
            }
            if(k == 0)
                break;
            else
                index = i;
        }
    }

    return index;
}