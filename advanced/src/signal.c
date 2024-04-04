#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main(void)
{
    printf("Testing SIGSTOP\n");
    raise(SIGSTOP);
    printf("I am back\n\n");
    return 0;
}
