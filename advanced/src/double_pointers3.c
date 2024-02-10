#include <stdio.h>
#include <malloc.h>
#include <string.h>

void foo(char** ptr) // using a double pointer to be able to maintain the changes to *ptr from main when the address gets passed to foo() pass by copy not by value
{
    *ptr = malloc(255);
    strcpy(*ptr, "Hello World");
}

int main()
{
    char* ptr = NULL;

    foo(&ptr);
    printf("%s\n", ptr);

    free(ptr);

    return 0;
}