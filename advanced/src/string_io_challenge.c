/*
String IO Function Challenge

- write a program that takes two command-line arguments 
    - first is a character 
    - the second is a filename 

- the reqwuirements of the program are that it should print only those lines in the file containing the given character 
    - lines in a file are identified by a terminating '\n'
    - assume that no line is more than 256 characters long 

- you are required to use fgets or getline (or both) for reading of the file 
    - use puts to display the output 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char *buffer = NULL, ch = *argv[1], *fileName = argv[2];
    size_t bufsize = 256;
    FILE *fp = NULL;

    buffer = (char*)malloc(bufsize * sizeof(char));

    fp = fopen(fileName, "r");

    if (!fp)
    {
        puts("The file could not be opened");
        exit(1);
    }
        
    
    while(getline(&buffer, &bufsize, fp) != -1)
    {
        for(int i = 0; i != '\n'; i++)
        {
            if(buffer[i] == ch)
            {
                puts(buffer);
                break;
            }
        }
    }

    free(buffer);

    fclose(fp);

    return 0;
}