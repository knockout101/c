/*
Writing to files Challenge

- write a program that converts all characters of a file to uppercase and write the results out to a temporary file. 
    Then rename the temporary file to the original filename and remove the temporary file name

- use the fgetc and fputc functions

- use the rename and remove functions

- use the islower function
    - can covert a character to upper case by substracting 32 from it

- display the contents of the original file to standard output
    - in uppercase
*/
#include <stdio.h>
#include <string.h>

int checkFileSize(FILE * filePointer);

int main(void)
{
    FILE *fp = NULL;
    FILE *fp_temp = NULL;
    
    fp_temp = fopen("temp.txt", "w");
    fp = fopen("file.txt", "r+");

    int temp;

    for (temp = fgetc(fp); temp != EOF;)
    {
        if (temp > 96)
            temp -= 32;
        
        fputc(temp, fp_temp);
        
        temp = fgetc(fp);
    }

    fclose(fp_temp);
    fclose(fp);
    fp_temp = NULL;
    fp = NULL;

    remove("file.txt");
    rename("temp.txt", "file.txt");

    fp = fopen("file.txt", "r");

    for (temp = fgetc(fp); temp != EOF;)
    {
        printf("%c", temp);
        
        temp = fgetc(fp);
    }
        
    fclose(fp);
    fp = NULL;

    return 0;
}
