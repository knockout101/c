/*
 * Challenge #2
 *
 * - write a program to create one parent with tree children processes (four processes)
 *   - must use the fork() function
 * - your program should contain output that indentifies each parent and each child 
 *   - will need to write if statements to check process id's returned from the fork() call, so that the output information is correct
 *     - "parent", "first child", "second child", "third child"
 *     - utilize the getpid() and getppid() functions to display each processes id
 *
 * - at some instance of time, it is not necessary that child process will execute first or parent process will be first allotted CPU
 *    - any process may get CPU assigned, at some quantum time
 *    - also, the process id may differ during different executions
 */
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_PID 3

int pid_list[MAX_PID + 1];

int findPID(pid_t pid);

int main(void)
{
    int count = 0, me = 0;

    pid_t parent_id = getpid();

    if(getpid() == parent_id)
        printf("Parent PID: %d\n", parent_id);
    
    for(int i = 0; i < 3; i++, count++)
    {
        // Parent forking and adding child PID to a list of children PID's
        if(getpid() == parent_id)
            pid_list[i] = fork();
    }
    // Child Only
    if((me = getppid()) == parent_id)
    {
        for(int l = 0; l < MAX_PID; l++)
        {
           if(pid_list[l] == getpid())
                printf("Child %d\n", l);
        }

        int pid = getpid();
        printf("My PID is: %d || Parent PID: %d <-- Child %d\n", pid, getppid(), findPID(pid));
    }
    // Parent Only
    if(getpid() == parent_id)
    {
        for(int t = 0; t < MAX_PID; t++)
        {
            printf("PID%d = %d\n", t+1, pid_list[t]);
        }
    }
    return 0;
}

int findPID(pid_t pid)
{
    for(int i = 0; i < MAX_PID; i++)
    {
        if(pid_list[i] == pid)
            return i;
    }
    return 0;
}
