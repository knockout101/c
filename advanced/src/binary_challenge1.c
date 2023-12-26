/*
Challenge 1: Converting binary to decimal

- write a function that converts a binary number to a numeric value

- if you have:

long long bin = 01001001;

- you can pass bin as an argument to the function and have the function return an int value of 25 

Challenge 2: Converting decimal to binary 

- write a function that converts an integer to binary value (long long)
    - long long convertDecimalToBinary(int n)

- if you have:

int decimal = 10;

- you can pass decimal as an argument to the function and have the function return a long long value of 1010
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

long long decimalToBinary(int decimal);
int binaryToDecimal(long long binary);
void reverseArray(int* array, const int elements);

int main(void)
{
    printf("%d", binaryToDecimal(10));

    return 0;
}

long long decimalToBinary(int decimal)
{
    long long binaryNumb = 0;

    int temp = decimal, index = 0, rem[20];
    int* pRem = rem;

    while(temp)
    {
        rem[index++] = temp % 2;
        temp = temp / 2;
    }

    printf("\nindex is: %d\n\n", index);
    
    reverseArray(pRem, index + 1);

    for(int i = 0; i < index; i++)
    {
        if (i % 4 == 0 && i != 0)
        {
            printf(" ");
        }
        printf("%d", pRem[i]);
    }

    return binaryNumb;
}

void reverseArray(int* array, const int elements)
{
    int temp[20];

    for(int i = 0; i < elements; i++)
        temp[i] = array[elements - i];

    array = temp;
}

int binaryToDecimal(const long long binary)
{
    int i = 0, decimal = 0;

    char buffer[200];

    ltoa(binary, buffer, 10);

    printf("\nString length of buffer: %d\n", strlen(buffer));

    while(buffer[i])
    {
        if (buffer[i] == '1')
            decimal += pow(2, (strlen(buffer) - 1) - i++);
        else
            i++;
    }
    return decimal;
}