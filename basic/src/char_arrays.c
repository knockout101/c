#include <stdio.h>
#include <stdbool.h>

int strlenRemake(const char arr[]);
void addStrings(const char arr1[], const char arr2[], char result[]);
int strEqual(const char str1[], const char str2[]);

int main()
{
    char string1[150];
    char array1[] = "dog";
    char array2[] = "dug";
    char result[7];

    printf("Please type in a word or phrase and I will tell you the amount of characters in the sentence or word:");
    scanf("%s", string1);

    int length = strlenRemake(string1);

    printf("%d is the length of `%s`", length, string1);

    addStrings(array1, array2, result);
    printf("\n%s is the result\n\n", result);

    printf("%d is case for string equality", strEqual(array1, array2));

    return 0;
}

int strlenRemake(const char arr[])
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
    int i, j;

    for (i = 0; arr1[i] != '\0'; i++)
    {
        result[i] = arr1[i];
    }

    for (j = 0; arr2[j] != '\0'; j++)
    {
        result[i + j] = arr2[j];
    }

    result[i + j] = '\0';
}

int strEqual(const char str1[], const char str2[])
{
    for (int i = 0; str1[i] != '\0'; i++)
    {
        if (str1[i] != str2[i])
        {
            return 0;
        }
    }

    return 1;
}