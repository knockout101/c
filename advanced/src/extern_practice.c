#include <stdio.h>

int i = 5;

char text[255][25];

void foo(void);

int main(void)
{
    printf("%i ", i);
    foo();
    printf("%i\n", i);

    return 0;
}