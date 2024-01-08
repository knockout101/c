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
    int userInput, nthBit;

    printf("\nEnter any number: ");
    scanf("%d", &userInput);

    printf("Enter the nth bit to check and set (0-31): ");
    scanf("%d", &nthBit);

    if (nthBit > 31)
    {   
        fprintf(stderr, "Nth bit selected is outside of 32 bit range");
        exit(1);
    }

    printf("\n\nNumber before setting %d bit: %d\n\n", nthBit, userInput);

    manipulateBit(&userInput, nthBit - 1);  // subtracting 1 from nthBit integer for correct indexing

    printf("Number after setting %d bit: %d\n\n", nthBit, userInput);

    return 0;
}

void manipulateBit(int* numb, int bitIndex)
{
    const int mask = makeMask(bitIndex);

    *numb |= mask;
}

int makeMask(int bitIndex)
{
    int biNumb = pow(2, bitIndex);

    return biNumb;
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
