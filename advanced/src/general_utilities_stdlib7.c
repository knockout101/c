#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    srand(time(0));

    for (int i = 0; i < 10; i++)
        printf(" %d ", rand() % 5 + 1); // modolus operator limits the range of rand()
    
    printf("\n");

    return 0;
}