#include <stdio.h>

int main()
{
    char string[100];
    int a = 10, b = 20, c = 0;
    c = a + b;

    sprintf(string, "Sum of %d and %d is %d", a, b, c);

    puts(string);

    return 0;
}