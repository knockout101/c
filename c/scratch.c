#include <stdio.h>



int main(void)
{
    long num1 = 0;
    long num2 = 0;
    long *pnum = NULL;

    pnum = &num1;
    *pnum = 2L;
    ++num2;
    num2 += *pnum;

    pnum = &num2;
    ++*pnum;

    printf("num1 = %ld num2 = %ld *pnum = %ld *pnum + num2 = %ld\n", num1, num2, *pnum, (*pnum + num2));

    return 0;
}