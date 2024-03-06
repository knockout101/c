#include <stdio.h>
#include <string.h>

int main(void)
{
    char *p1 = "Jason";
    char *p2 = NULL;

    p2 = strdup(p1);

    printf("Duplicated string is: %s", p2);
    return 0;
}