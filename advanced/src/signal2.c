#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void handler_dividebyzero(int signum);

int main(void)
{
    int result = 0;
    int v1 = 0, v2 = 0;
    
    void (*sigHandlerReturn)(int);

    sigHandlerReturn = signal(SIGFPE, handler_dividebyzero);

    if(sigHandlerReturn == SIG_ERR)
    {
        perror("Signal Error: ");
        return 1;
    }

    v1 = 121;
    v2 = 0;
    result = v1/v2;
    printf("Result of divide by zero is %d\n", result);
    return 0;
}

void handler_dividebyzero(int signum)
{
    if (signum = SIGFPE)
    {
        printf("Received SIGFPE, Divide by Zero Exception\n");
        exit(0);
    }
    else
    {
        printf("Received %d signal\n", signum);
        return;
    }
}
