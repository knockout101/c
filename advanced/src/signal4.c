#include <signal.h>

#include <signal.h>
#include <sys/signal.h>

void nothing(int signum) { /* DO NOTHING */ }

int main(void)
{
    signal(SIGINT, nothing);
    while(1);
    return 0;
}

