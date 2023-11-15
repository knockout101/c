#include <stdio.h>

int strlenRemake(char arr[]);
void addStrings(const char arr1[], const char arr2[], char result[]);

void main()
{
    char string1[150];

    printf("Please type in a word or phrase and I will tell you the amount of characters in the sentence or word:");
    scanf("%s", string1);


    int length = strlenRemake(string1);

    printf("%d is the length of `%s`", length, string1);
}

int strlenRemake(char arr[])
{
    int counter = 0;

    for (int i = 0; arr[i] != '\0'; i++)
    {
        counter++;
    }
    return counter;
}

void addStrings(const char arr1[], const char arr2[], char result[])
{
    int length1 = strlenRemake(arr1);
    int length2 = strlenRemake(arr2);

    result = arr1;

    for (int i = 0; i < length2; i++)
    {
        result[i + length1] = arr2[i];
    }
    
    result[length1 + length2] = '\0';   
}