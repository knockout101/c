/*
Example 1:

int w1 = 3; // 0000 0000 0000 0000 0000 0000 0000 0011

int result = 0;

result = w1 << 1; // 0000 0000 0000 0000 0000 0000 0000 0110

printf("%d", result);

*/
#include <stdio.h>

void shiftLeftExample(int integer, int shift);

int main(void)
{
    unsigned int result = 0, w1 = 4151832098; // 1111 0111 0111 0111 1110 1110 0010 0010
    
    result = w1 >> 1 ; // 0111 1011 1011 1011 1111 0111 0001 0001 = 2075916049

    printf("%d", result);

    return 0;
}

void shiftLeftExample(int integer, int shift)
{
    int result = 0;

    result = integer << shift;

    printf("%d", result);
}