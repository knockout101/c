#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[255];
    int ch = '\0';
    char *p = NULL;

    if (fgets(buf, sizeof(buf), stdin))
    {
        p = strchr(buf, '\n');
        if (p)
        {
            *p = '\0';
        }
        else
        {
            while(((ch = getchar()) != '\n') && !feof(stdin) && !ferror(stdin));
        }
    }
    else
    {
        return 1;
    }

    printf("Our buffer contains: %s\n", buf);

    return 0;
}