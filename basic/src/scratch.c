#include <stdio.h>

int main(void)
{
    int i = 0;
    int j = i++ + i;
    printf("%d\n", j);

    return 0;
}