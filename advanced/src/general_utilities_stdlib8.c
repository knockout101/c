#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char command[50];

    system("pwd\n\n");

    strcpy(command, "ls -l");
    system(command);

    return 0;
}