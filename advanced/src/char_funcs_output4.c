#include <stdio.h>

int main(void)
{
    FILE *pFile = NULL;
    char c = '\0';

    pFile = fopen("myFile.txt", "w");

    if (pFile != NULL)
    {
        for(c = 'A'; c <= 'Z'; c++)
            fputc(c, pFile);
        
        fclose(pFile);
    }

    return 0;
}