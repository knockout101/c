#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>

void signalHandler(int signalVlaue);

int main(void)
{
    int i; // counter used to loop 100 times
    int x; // variable to hold random values between 1-50

    signal(SIGINT, signalHandler); // register signal handler
    srand(time(0));

    for(i = 1; i <= 100; i++)
    {
        x = 1 + rand() % 50;

        if(x == 25)
            raise(SIGINT);

        printf("%4d", i);

        if(i % 10 == 0)
            printf("\n");
    }

    return 0;
}

void signalHandler(int signalValue)
{
    int response; // user's reponse to signal (1 or 2)

    printf("%s%d%s\n%s", "\nInterroptsignal ( ", signalValue, " ) received.", "Do you wish to continue (1 = yes or 2 = no)");
    scanf("%d", &response);

    // check for invalid responses 
    while(response != 1 && response != 2)
    {
        printf("(1 = yes or 2 = no)?");
        scanf("%d", &response);
    }
    if(response == 1) // to go again
    {
        signal(SIGINT, signalHandler); // MUST reregister the signalhandler <--!/\/\/\/\/!--
    }
    else // reponded 2 and program is exited
        exit(EXIT_SUCCESS);
}

