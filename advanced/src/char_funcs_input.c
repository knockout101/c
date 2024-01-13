#include <stdio.h>

int main(void)
{
    char ch = '\0';

    ch = getc(stdin);

    printf("read in character %c\n");

    printf("Reading in character: %c\n", getchar());

    return 0;
}