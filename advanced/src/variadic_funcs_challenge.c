/*
Variadic Function Challenge

- write a program that creates a variadic function that will allow a programmer to add any amount of numbers (integers) that they would like to be added together 

- in order to know how many numbers are being passed to this variadic function, you can use the first argument as the number of arguments
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

long addUp(int count, ...);

int main(void)
{
    printf("The sum of all the numbers: %ld", addUp(3, 30, 120, 1000));
}

long addUp(int count, ...)
{
    va_list fargs;
    va_start(fargs, count);

    long sum = 0;

    for(int i = 0; i < count; i++)
    {
        sum += va_arg(fargs, long);
    }

    va_end(fargs);

    return sum;
}