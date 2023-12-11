#include <stdio.h>

int main(void)
{
    FILE *fp;
    char str[61];
    int c;

    fp = fopen("file.txt", "r");

    if (fp == NULL)
    {
        perror("Error in opening file");
        return -1;
    }

    if (fgets(str, 60, fp) != NULL)
        printf("%s", str + 1);
    
    fclose(fp);
    fp = NULL;

    return 0;
}