#include <stdio.h>

int main() 
{
    signed int w1 = 154;
    signed int result = 0;

    result = ~(w1);
    printf("%d", result);
    
    return 0;
}