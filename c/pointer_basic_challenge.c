#include <stdio.h>

int main(void)
{
    int specNum = 1356, *pSpecNum = NULL;

    pSpecNum = &specNum;

    printf("\nStarting number is: %d\n\n", specNum);

    printf("Address of pointer: %p\n", &pSpecNum);
    printf("Value of pointer: %p\n", pSpecNum);
    printf("Value of what is pointed at: %d\n", *pSpecNum);
}