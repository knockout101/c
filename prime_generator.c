#include <stdio.h>
#include <stdbool.h>


bool checkPrime(long int testNum)
{
    for (int j = 2; j < testNum; j++)
        {
            if (testNum % j == 0)
            {
                return false;
            }
        }

    return true;
}

int main()
{
    long int userNum;
    long int lastPrime;

    printf("Please select a number and I will find the closest prime number: ");
    scanf("%ld", &userNum);
    printf("\nYou selected: %ld\n", userNum);

    if (checkPrime(userNum))
    {
        printf("%ld is prime!", userNum);
        return 0;
    }

    for (int i = 2; i < userNum; i++)
    {
        if (checkPrime(i)){
            lastPrime = i;
        }

        
    }

    printf("\n%ld\n\n", lastPrime);

    return 0;
}