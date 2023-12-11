#include <stdio.h>

int *squareSelf(int *pnum);

int main(void) 
{
    int input = 6;

    printf("%d\n", input);

    squareSelf(&input);

    printf("%d\n", input);

    return 0;
}

int * squareSelf(int * pnum)
{   
    *pnum = (*pnum * *pnum);
}