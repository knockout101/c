#include <stdio.h>

int main(void)
{
    int data[10], sum = 0, i = 0;
    
    while(i < 100)
        sum += data[i], ++i;

    int j = (f1(), f2()); // evaulates f1 and then f2 and assigns the result of f2 to j

    for(i = 0, j = 100; i != 10; ++i, j -= 10)
        printf("Hello"),
        printf(" "),
        printf("World!"); // comma operators used to move mutliple statements between multiple lines but has to be terminated by semicolon.

    return 0;
}