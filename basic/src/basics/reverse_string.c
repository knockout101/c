#include <stdio.h>
#include <string.h>

void reverseString();
void bubbleSort(char arr[], char result[]);

int main(int argc, char *argv[])
{
    char userInput[50];
    char reversed_str[sizeof(userInput)];
    char sorted_str[sizeof(userInput)];

    printf("Please type a word, and the reverse will be shown back: ");
    scanf("%s", userInput);

    reverseString(userInput, reversed_str);

    printf("%s backwards is: `%s`.\n\n", userInput, reversed_str);

    bubbleSort(userInput);

    return 0;
}

void reverseString(char str[], char reversed_str[])
{
    // Cycle until terminating escape character zero for end of string
    for (int i = 0; i < str[i] != '\0'; i++)
    {
        reversed_str[i] = str[strlen(str) - (i + 1)];
    }

    // Have to add the ending terminating character 
    // otherwise the string will exibit unpredictable behavior
    reversed_str [strlen(str)] = '\0';

}

