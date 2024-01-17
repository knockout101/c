#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *f = NULL;
    char ch[100];

    if ((f = fopen("myFile.txt", "r+")) == NULL)
    {
        printf("Cannot open the file...\n");
        exit(1);
    }
    
    for(int i = 0; i < 10; i++)
        fprintf(f, "The count number is %d\n", i + 1);

    fclose(f);

    if ((f = fopen("myFile.txt", "r+")) == NULL)
    {
        printf("Cannot open the file...\n");
        exit(1);
    }

    while(!feof(f))
    {
        fgets(ch, 100, f);
        printf("%s", ch);
    }

    return 0;
}