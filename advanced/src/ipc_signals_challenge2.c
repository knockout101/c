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
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <string.h>


#define SHM_SIZE 1024 /* 1k shared memory segment */

void* create_shared_memory(size_t size)
{
    int protection = PROT_READ | PROT_WRITE;
    int visibility = MAP_SHARED | MAP_ANONYMOUS;
    return mmap(NULL, size, protection, visibility, -1, 0);
}

int main(void)
{
    int i = 0, status = 0, shmloc = 0;
    pid_t parent = getpid(), res;
    printf("Parent PID: %d\n", parent);

    // Creating shared memory
    int* shmem = (int*)create_shared_memory(sizeof(int));

    // Check for error
    if(shmem == NULL)
    {
        fprintf(stderr, "Failed to create shared memory");
        exit(EXIT_FAILURE);
    }


    // Creating n processes < 50
    while(i++ < 10)
    {
        if(getpid() == parent)
        {
            fork();
        }
    }
    // Child Code
    if(getppid() == parent)
    {
        *shmem += 1;
        printf("Child PID: %d  -- #%d\n", getpid(), *shmem);
        exit(1);
    }
    // wait for all processes to end
    while((res = wait(&status)) > 0);

    return 0;
}
