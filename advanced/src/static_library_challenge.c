/*
Implement static library 
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "strfuncs.h"

int main(void)
{
    char sample[100] = "Sample";
    char* subString = "mpl";
    char* sample2 = "12(Hello)";

    char* buffer = (char*)malloc(sizeof(char)*100); // 100 char buffer
    
    printf("%s + %s = ", sample, subString);
    printf("%s\n", strcat(sample, subString));

    strcopy(sample, "Sample");

    printf("%s,  letter `%c` count: %d\n", sample, 'm', count(sample, 'm'));
    printf("%s length is: %i\n", sample, strlength(sample));

    strcopy(buffer, sample);

    printf("buffer = %s\n", buffer);

    free(buffer);

    return 0;
}
