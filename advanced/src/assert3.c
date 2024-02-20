#include <stdio.h>
#include <limits.h>
#include <assert.h>

static_assert(CHAR_BIT == 16, "16-bit char falsely assumed"); // only in C11 standard 

int main(void)
{   
    puts("Char is 16 bits.");

    return 0;
}