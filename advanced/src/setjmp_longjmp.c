#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

jmp_buf buf;

int main()
{
    int i = setjmp(buf);

    printf("i = %d\n", i);
    if (i != 42)
        longjmp(buf, 42); // second argument to longjmp function provides the return value

    printf("Does this line get printed?\n");

    return 0;
}