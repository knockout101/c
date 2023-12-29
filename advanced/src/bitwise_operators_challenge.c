/*
Bitwise Operators Challenge:

- write a program that reads two integers from the user 

- your program will print the results of applying 
    - the ~ operator to each number 
    - the &, |, ^ operators to the pair
    - the << and >> operations to a specific number 
    - show the results as binary strings (need to write a decimalToBinary function)

*/
#include <stdio.h>
#include <stdlib.h>

char* decimalToBinary(int decimal, char* rVal);

int main(void)
{
    int userInput1, userInput2;

    char temp[32];
    
    printf("Please enter two numbers seperated by a space: ");
    scanf("%d %d", &userInput1, &userInput2);

    printf("\nuserInput1: %d\n", userInput1);
    printf("\nuserInput2: %d\n\n", userInput2);

    printf("~(%d): %d\n\n", userInput1, ~(userInput1));
    printf("~(%d): %d\n\n", userInput2, ~(userInput2));

    printf("%d & %d: %s\n\n", userInput1, userInput2, decimalToBinary(userInput1 & userInput2, temp));
    printf("%d | %d: %s\n\n", userInput1, userInput2, decimalToBinary(userInput1 | userInput2, temp));
    printf("%d ^ %d: %s\n\n", userInput1, userInput2, decimalToBinary(userInput1 ^ userInput2, temp));
    printf("%d >> 2: %s\n\n", userInput1, decimalToBinary(userInput1 >> 2, temp));
    printf("%d << 2: %s\n\n", userInput1, decimalToBinary(userInput1 << 2, temp));

    return 0;
}

char* decimalToBinary(int decimal, char* rVal)
{
    itoa(decimal, rVal, 2);
    return rVal;
}