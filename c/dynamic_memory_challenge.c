/*
Dynamic Memory Challenge:

- In this challenge, you are going to write a program that tests you understanding of dynamic memory allocation

- write a program that allows a user to input a text string. The program will print the text that was inputted. The porgram will utilize dynamic memory allocation.

- the user can enter the limit of the string they are entering
    - you can use this limit when invoking malloc

- the program should create a char pointer only, no character arrays

- be sure to release the memory that was allocated

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    char * userInput = NULL;

    userInput = (char*)calloc(100, sizeof(char));

    printf("Please enter a string less than 99 characters: ");
    scanf("%s", userInput);

    printf("The value entered: '%s'. At the address [%p] and the size of input is: .", userInput, userInput);

    free(userInput);

    return 0;
}