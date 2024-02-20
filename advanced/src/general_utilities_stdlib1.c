#include <stdio.h>
#include <stdlib.h>

FILE *openFile(const char *file)
{
    FILE *inFile;

    if((inFile = fopen(file, "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s for reading.\n", file);
        exit(EXIT_FAILURE);
    }
    return inFile;
}