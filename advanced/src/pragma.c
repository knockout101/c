#include <stdio.h>

#pragma GCC poison printf

int main(void)
{
    printf("hello"); // will throw error

    return 0;
}