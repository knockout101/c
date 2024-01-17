#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fputs(const char * buffer, FILE *filePtr);

int main(void)
{
    FILE *fp = NULL;

    fp = fopen("Somefile.txt", "w");

    if (!fp)
        exit(1);

    fputs("Hello There, I hope this article will help!", fp);

    //close the file
    fclose(fp);

    return 0;
}