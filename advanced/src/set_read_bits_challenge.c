/*
Settings and Reading Bits Challenge:

write a program to input any number from a user
    - program should check whether nth bit of the given number is set(1) or not 
    - program should set nth bit of the given number as 1

enter any number: 10
Enter nth bit to check adn set (0-31): 2
The 2 bit is set to 0

Bit set successfully 

Number before setting 2 bit: 10 (in decimal)
Number after setting 2 bit: 14 (in decimal)
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void manipulateBit(int* numb, int bit);
int makeMask(int bit);
int binaryToDecimal(const long long binary);

int main(void)
{
    int userInput, nthBit, *pBit;

    printf("Enter any number: ");
    scanf("%d", &userInput);

    pBit = &userInput;

    printf("Enter the nth bit to check and set (0-31): ");
    scanf("%d", &nthBit);

    if (nthBit > 31)
    {   
        fprintf(stderr, "Nth bit selected is outside of 32 bit range");
        exit(1);
    }

    manipulateBit(pBit, nthBit);

    return 0;
}

void manipulateBit(int* numb, int bit)
{
    const int mask = makeMask(bit);

    printf("\nmask in decimal: %d\n", mask);
}

int makeMask(int bit)
{
    char temp[33];

    for (int i = 0; i < 32; i++)
    {
        if (i == bit)
        {
            temp[i] = '1';
            continue;
        }
        temp[i] = '0';
    }
    temp[33] = '\0';
    
    long long result = atoll(temp);

    if (result == 0L)
        printf("Error in atoll(), could not make string into long long integer value");
        exit(1);

    return binaryToDecimal(result);
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
