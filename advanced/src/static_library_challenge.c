/*
Implement static library
*/
#include <stdlib.h>
#include <stdio.h>

#include "strfuncs.h"

int main(void)
{
    char sample[100] = "Sample";
    char* subString = "mpl";
    char* sample2 = "12(Hello)";

    char* buffer = (char*)malloc(sizeof(char)*100); // 100 char buffer
    
    printf("%s + %s = %s\n", sample, subString, strconcat(sample, subString));

    strcopy(sample, "Sample");

    printf("%s,  letter `%c` count: %d\n", sample, 'm', count(sample, 'm'));
    printf("%stripped: \n", sample2);
    alphaStrip(sample2);
    printf("%s\n", sample2);
    printf("%s length is: %i\n", sample, strlength(sample));
    strcopy(buffer, sample);
    printf("%s\n", buffer);

    free(buffer);

    return 0;
}
