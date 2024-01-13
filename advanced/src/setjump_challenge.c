/*
setjmp and longjmp Challenge

- write a program that uses setjmp and longjmp to gracefully handle unrecoverable program errors 
    - when you discover an unrecoverable error, you should transfer control back to the main input loop and start again from there 

- create a function named error_recovery that prints out an error and then uses longjmp to transfer control back to a main function loop

- your main function should include a forever loop that uses setjmp at the top of the loop before processing 

- you can add "dummy" code in your loop that simulates an error (by calling error_recovery) when setjmp returns 0
*/
#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

void errorRecovery()
{
    printf("Error");
    
}

int main(void)
{
    

    return 0;
}