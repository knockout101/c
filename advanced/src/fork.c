#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    // make two process which run same program after this instruction
    printf("this is before the fork\n");

    fork();

    printf("process: %d ending!\n", getpid());
    return 0;
}

