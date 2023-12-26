#include <stdio.h>

int main() 
{
    short int w1 = 25;
    short int w2 = 77;
    short int w3 = 0;

    w3 = w1 & 3;

    printf("%d\n", w3);

    return 0;
}