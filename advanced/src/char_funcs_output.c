#include <stdio.h>

int main(void)
{
    char ch = '\0';
    FILE *fp = NULL;

    if (fp = fopen("scratch.c", "rw"))
    {
        ch = getc(fp);
        while(ch != EOF)
        {
            putc(ch, fp);
            ch = getc(fp);
        }
        fclose(fp);
    }

    return 0;
}