/*
Recursion Challenge

- write a program that will calculate the sum of number from 1 to n using recursion
*/
#include <stdio.h>

int addUp(int n);

int main(void)
{
    printf("%d", addUp(9));

    return 0;
}

int addUp(int n)
{
    if(n == 0)
        return 0;
    else
    {
        return n + addUp(n-1);
    }
}