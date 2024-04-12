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

int main(void)
{
    pid_t current = 0;
    pid_t parent_id = getpid();

    printf("Parent PID: %u", parent_id);

    
    pid_t child1 = fork();
    if(getpid() == parent_id)
        pid_t child2 = fork();
    pid_t child3 = fork();

    printf("Child 1 PID: %u", child1);
    if(getpid() != parent_id && getpid())
        printf("Parent of child 1 PID: %u", getppid());

    return 0;
}
