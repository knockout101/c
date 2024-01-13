/*
Char input and output functions Challenge 

- write a program to count the number of words and characters in a file OR from standard input 

- this program can take zero command-line arguments or one command-line argument 
    - if there is no argument, it is interpreted as the name of a file 
    - if there is no argument, the standard input(stdin) is to be used for input
*/
#include <stdio.h>

int main(void)
{
    FILE *fp = NULL;
    int ch = '\0', count = 0;
    
    fp = fopen("./notes/c99.txt", "r");

    if(!fp)
    {
        printf("The file is unable to be opened.\n");

        return 1;
    }
    while((ch = fgetc(fp)) != EOF)
        {
            if(ch <= 90 && ch >= 65)
                count++;
            if(ch <= 122 && ch >= 97)
                count++;
        }

    printf("The number of characters in this file are: %d\n", count);

    fclose(fp);

    return 0;
}