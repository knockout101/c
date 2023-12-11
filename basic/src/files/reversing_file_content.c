/*
Print the contents of a file in reverse order

- write a program that will print the contents of a file in reverse order

- use the fseek function to seek to the end of the file

- use the ftell function to get the position of the file pointer

- display as output the file in reverse order
*/
#include <stdio.h>


int main(void)
{
    FILE * fp = NULL;

    fp = fopen("file.txt", "r+");

    long start = ftell(fp);
    long interval = 0;

    int c;

    fseek(fp, 0, SEEK_END);
    
    for (;ftell(fp) != start; interval++)
    {
        printf("%l", ftell(fp));
        fseek(fp, interval, SEEK_END);
    }

    fclose(fp);
    fp = NULL;


    return 0;
}