#include <stdio.h>
#include <string.h>

int main(void)
{
    long multiple[] = {15L, 25L, 35L, 45L};
    long * p = multiple;

    for (int i = 0; i < (multiple, sizeof(multiple)); ++i)
        printf(
            "multiple[%d] = %c *(p+%d) = %c &multiple[%d] = %p p+%d = %p\n\n",
            i, multiple[i], i, *(p + i), i, &multiple[i], i, p+i
        );
    
    return 0;
}