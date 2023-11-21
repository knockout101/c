// strlen, strcpy() strncpy() strcat(), strncat() strcmp() strncmp()

#include <string.h>
#include <stdio.h>

int main()
{
    char myString1[] = "Tristan";

    char myString2[] = " is cool.";

    char temp[50];

    strncpy(temp, myString1, sizeof(temp) - 1);
    printf("`%s` is %d characters long", temp, strlen(temp));

    printf("\n%s\n", strncat(myString1, myString2, sizeof(myString2)));

    return 0;
}