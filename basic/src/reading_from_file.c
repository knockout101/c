#include <stdio.h>

int main(void)
{
    FILE *fp;
    int c;

    fp = fopen("file.txt", "r");

    if (fp == NULL)
    {
        perror("Error in opening file");
        return -1;
    }

    while ((c = fgetc(fp)) != EOF)
        printf("%c", c);
    
    fclose(fp);
    fp = NULL;

    return 0;
}