#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <debugapi.h>

int main(void)
{
    printf("Testing SIGSTOP\n");
    DebugActiveProcess()
    printf("I am back\n\n");
    return 0;
}