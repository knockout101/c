#include <stdio.h>

int main()
{
    FILE *fp = NULL;

    fp = fopen("file.txt", "w+");

    if (fp)
        fprintf(fp, "%s %s %s %s %d", "hello", "my", "name", "is", 555);
    
    fclose(fp);
    return 0;
}