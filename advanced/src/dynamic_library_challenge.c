/*
Dynamic Library Challenge 

- the goal is to create a shared object (dynamic library) and then write a program that uses this library 

- created a C source file named "StringFunctions.c"

- "StringFunctions.c" should contain implementations of various string manipulations
*/
#include <stdio.h>

#include "dstrfuncs.h"

int main(void)
{
    char* string = "sample";

    printf("%s length: %d", string, strlength(string));

    return 0;
}