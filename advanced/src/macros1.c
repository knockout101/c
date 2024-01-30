#include <stdio.h>

#define PI 3.14 // symbolic constant 

#define PRNT(a, b) \
    printf("Value 1 = %d\n", a); \
    printf("value 2 = %d\n", b);

int main(void)
{
    int x = 2, y = 3;

    PRNT(x, y);

    return 0;
}