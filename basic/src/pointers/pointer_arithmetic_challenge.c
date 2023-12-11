/*
Challenge: tests your understanding of pointer arithmetic and the const modifier

- write a function that calculates the length of a string
    - the functrion should take as a parameter a const char pointer
    - the function can only determine the length of the string using pointer arithmetic
        - incrementation operator (++pointer) to get to the end of the string
    - you are required to use a while loop using the value of the pointer to exit
    - the function should substract two pointers (one pointing to the end of the string and one pointing to the beginning of the string)
    - the function should return an int that is the length of the string passed into the function
*/
#include <stdio.h>


int strlength(const char *ptr);

int main(void)
{

    char string1[] = "dogggytaeslkfjaskl;dfjl;sdkfgj";

    printf("[ %s ] is %d characters long.", string1, strlength(string1));

    return 0;
}

int strlength(const char * ptr)
{
    const char * lastAddress = ptr;

    while (*lastAddress)
        ++lastAddress;

    return lastAddress - ptr;
}