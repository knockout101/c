#include <stdio.h>
#include <malloc.h>
#include <string.h>

void foo(int** ptr) // can change the value of the single pointer by passing as double pointer because its pass by copy not by value 
{
    int a = 5;
    *ptr = &a;
}

int main()
{
    int* ptr = NULL;
    ptr = (int*)malloc(sizeof(int));
    *ptr = 10;
    foo(&ptr);

    printf("%d\n", *ptr);

    return 0;
}