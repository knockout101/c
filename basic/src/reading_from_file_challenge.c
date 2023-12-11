/*
Reading from a File Challenege

- write a program to find the total number of lines in a text file

- create a file that contains some lines of text

- open your test file

- use the fgetc function to parse characters in a file until you get to the EOF
    - if EOF increment counter

- display as output the total number of lines in the file
*/
#include <stdio.h>

int main(void)
{
    int tempi;
    FILE *fp;
    int counter = 0;

    fp = fopen("file.txt", "r");

    if (!fp)
    {
        perror("File could not be opened!!");
        return -1;
    }

    printf("\n\"\"\n");
    printf("1 - ");

    while((tempi = fgetc(fp)) != EOF)
    {
        printf("%c", tempi);

        if ((char)tempi == '\n')
            printf("%i - ", ++counter + 1);
    }

    printf("\n\"\"\n");

    printf("Number of lines: %i", counter + 1);

    fclose(fp);
    fp = NULL;

    return 0;
}