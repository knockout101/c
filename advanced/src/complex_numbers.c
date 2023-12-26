#include <stdio.h>
#include <complex.h>
#include <stdlib.h>

#define __STDC_WANT_LIB_EXT1__ 1

int main()
{
    #ifdef __STDC_WANT_LIB_EXT1__
        printf("Complex nubmers are not supported.\n");
        exit(1);
    #else
        printf("Complex numbers are supported.\n");
    #endif
}