#include <stdio.h>

extern int count;

extern void write_extern(void)
{
    printf("count is %d\n", count);
}

void foo(void)
{
    extern char text[][50];
    extern int i;

    i = 100;
}