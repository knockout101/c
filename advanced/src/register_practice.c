#include <stdio.h>

int main(void)
{
    register int x; // register variable

    // int * a = &x; <-- not ok to do

    int y = 100;

    register int *y = &y; // this is ok to do. Registers can be pointers, but you cannot get the address of a register using dereferencing. error: address of register variable requested

    for (x = 1; x < 15; x++)
        printf("%d", x);

    return 0;
}