#include <stdio.h>

int main(void)
{
    char string[] = "Hello World!";
    int i = 0;

    while(string[i] != '\0')
    {
        if(string[i] != '\n')
            putchar(string[i]);

        i++;
    }
    

    return 0;
}