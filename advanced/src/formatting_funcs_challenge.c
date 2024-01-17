/*
Formatting Functions Challenge 

- write a program that takes as input, a set of numbers from a file and write even, odd and prime numbers to standard output 

- you can use either fscanf or (fgets and sscanf) to accomplish the above 

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkPrime(int number);
int checkEven(int number);
int checkOdd(int number);

int main(void)
{
    FILE *f = NULL;
    int ret, rNum;

    if(!(f = fopen("./notes/numbers.txt", "r")))
    {
        printf("Numbers.txt could not be opened.\n");
        exit(EXIT_FAILURE);
    }
    
    while(ret = fscanf(f, "%d", &rNum) != -1)
    {
        checkPrime(rNum);
        checkEven(rNum);
        checkOdd(rNum);
    }

    return 0;
}

int checkPrime(int number)
{
    int temp = 0;
    for(int i = 2; i < number/2; i++)
    {
        if(number % i == 0)
        {
            temp++;
            break;
        }
    }
    
    if(temp == 0 && number >= 1)
        printf("%d is prime\n", number);
}

int checkEven(int number)
{
    if (number % 2 == 0)
        printf("%d is even\n", number);
}

int checkOdd(int number)
{
    char buffer[100];
    int rtn;
    const char oddNumbers[] = "13579";

    if((rtn = sprintf(buffer, "%d", number)) > 0)
    {
        char cNum = buffer[strlen(buffer) - 1];

        for(int i = 0; i < strlen(oddNumbers); i++)
        {
            if(cNum == oddNumbers[i])
                printf("%d is odd\n", number);
        }
    }
}

