#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

int main()
{
    FILE *fp = NULL;
    char words[MAX];

    if((fp = fopen("data.txt", "a+")) == NULL); // a+ allows read and writing to the file where when you write to the file it is appended to the EOF
    {
        fprintf(stdout, "Cannot open file.\n");
        exit(EXIT_FAILURE);
    }

    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");

    while((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
        fprintf(fp, "%s\n", words);

    puts("File contents:");
    rewind(fp);

    while(fscanf(fp, "%s", words) == 1)
        puts(words);

    puts("Done!");

    if(fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");

    fclose(fp);

    return 0;
}