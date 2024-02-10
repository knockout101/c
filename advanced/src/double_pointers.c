#include <stdio.h>

int main(void)
{
    int a = 10;

    int *p1 = NULL;
    int **p2 = NULL;

    p1 = &a;
    p2 = &p1;

    printf("Adress of a = %u\n", &a);
    printf("Adress of p1 = %u\n", &p1);
    printf("Adress of p2 = %u\n", &p2);

    return 0;
}