#include <stdio.h>

void swap_values(int x, int y)
{
    int temp;

    temp = x;
    x = y;
    y = temp;

    return;
}

void swap_pointers(int *x, int *y)
{
    int temp;

    temp = *x;

    *x = *y;

    *y = temp;

    return;
}

int main(void)
{
    int a = 100, b = 20;

    printf("Before swap, a : %d\n", a);
    printf("Before swap, b : %d\n", b);

    swap_values(a, b);

    printf("After swap, value of a : %d\n", a);
    printf("After swap, value of b : %d\n", b);

    printf("\n==========================================================\n");
    printf("\n==========================================================\n\n");

    swap_pointers(&a, &b);

    printf("After pointer swap, value of a: %d\n", a);
    printf("After pointer swap, value of b: %d\n", b);

    return 0;
}