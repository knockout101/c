/*
 * Interprocess Communication and Signals
 * 
 * Challenge #1
 *
 * - write a program that will test a user's multiplication skills
 *   - the program will ask the user to work on an answer to a simple multiplication program
 *   - keep track of how many answers are correct
 *
 * - the program will keep running forever, unless
 *   - the user presses Ctrl-C or
 *   - the user takes more than 5 seconds to answer the question
 *
 * - when the program ends, it will display the final score (number of answers correct)
 *
 * - the program needs to handle the user pressing Ctrl-C
 *   - will need to handle this signal using the signal or sigaction functions
 * 
 * - the program needs to raise a signal if the user does not answer a question within 5 seconds
 *   - use the alarm function and catch the SIGALRM signal
 *    - also, the process id may differ during different executions
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int score = 0;

void end_game() {

   printf("\nFinal score: %d\n", score);
   exit(0); 
}

void error(char *msg)
{
   fprintf(stderr, "%s: %s\n", msg, strerror(errno));
   exit(1);
}

void alarmHandler(int signum)
{
    error("\n[SIGALRM] You took longer than 5 seconds - exit");
    putchar('\n');
}

void interruptHandler(int signum)
{
    error("\n[SIGINT] program interrupted - exit");
    putchar('\n');
}

int main() {

    signal(SIGALRM, alarmHandler);
    signal(SIGINT, interruptHandler);

    srand (time(0));
   
    while(1) 
    {
        int a = rand() % 11;
        int b = rand() % 11;

        char txt[4];

        printf("\nWhat is %d times %d: ", a, b);
        alarm(5); 
        fgets(txt, 4, stdin);

        int answer = atoi(txt);

        if(answer == a * b)
             score++;
        else
        {
            printf("\nWrong! Score: %d\n", score);
            end_game();
        }
    }
    return 0;
}
