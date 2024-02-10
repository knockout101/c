/*
Double Pointers Challenge 

(1)
- write a program that creates, assigns, and accesses some double pointers 

1. create a normal integer variable (non pointer) and assign it a random value 
2. create a single integer pointer variable 
3. create a double integer pointer variable 
4. assign the address of the normal integer variable (step 1) to the single pointer (step 2)
5. assign the address of the single pointer (step 2) to the double pointer variable (step 3)

- display the follwoing output using all possible syntax 
    - all possible ways to find value of the normal integer variable (step 1)
    - all possible ways to find address of the nomal integer variable (step 1)
    - all possible ways to find the value of the single pointer variable (step 2)
    - all the possible ways to find the address of the single pointer variable (step 2)
    - all possible ways to print the double pointer value and address (step 3)


(2)
- write a program that includes a function that modifies a pointer value
    - not the value that the pointer is pointing to
    - the actual value of the pointer (the address that the pointer is pointing to)

- essentially this program will be simulating "pass by reference" in the C language
    - you want to change the vlaue of the poitner passed to a function as the function argument 

- first, create a function named allocateMemory that takes a single integer pointer as a function parameter 
    - void allocateMemory(int* ptr);
    - this function should allocate memory for this pointer 

- now create a main function that does the following:
    - creates an integer pointer and initializes it to NULL
    - invokes the allocateMemory function, passing in the integer pointer just created 
    - assign a value to the integer pointer that it is pointing to (de-reference)
    - print the value of what the pointer is pointing to (de-reference)
    - free the pointer 

- now modify your program to use a double pointer 

- modify the function named allocateMemory to take a double pointer of type int as a function parameter 
    - void allocateMemory(int** ptr);
    - this function should allocate memory for this pointer (use the correct syntax)

- now modify your main function that does the following:
    - creates an integer pointer and initializes it to NULL
    - Invokes the allocateMemory function, passing in the address of the integer pointer just created (double pointer)
    - assign a value to the integer pointer that it is pointing to (de-reference)
    - print the value of what the pointer is pointing to (de-reference)
    - free the pointer
*/
#include <stdio.h>
#include <stdlib.h>

void challenge1(void);
void challenge2(void);
void allocateMemory(int** pointer);

int main(void)
{
    challenge1();
    challenge2();

    return 0;
}

void challenge1(void)
{
    printf("\nChallenge 1)\n");
    
    int** holder = NULL;
    int* changer = NULL;
    int number = 6;

    holder = &changer;
    changer = &number;
    printf("\nInt values from each pointer and itself:\n");
    printf("**holder = %d\n", **holder);
    printf("*changer = %d\n", *changer);
    printf("int number = %d\n", number);

    printf("\nSingle pointer's address:\n");
    printf("&number = %p\n", &number);
    printf("changer = %p\n", changer);
    printf("*holder = %p\n", *holder);

    printf("\nDouble pointer's address:\n");
    printf("&changer = %p\n", &changer);
    printf("holder = %p\n", holder);
    
    printf("\nDouble pointer's address and value:\n");
    printf("&holder = %p\n", &holder);
    printf("**holder = %d\n\n", **holder);
}

void challenge2(void)
{
    printf("Challenge 2)\n\n");

    int n = 5;
    int* np = NULL;
    
    allocateMemory(&np);
    
    *np = n;
    printf("*np = %d\n", *np);
    
    free(np);
}

void allocateMemory(int** pointer)
{
    *pointer = (int*)malloc(sizeof(int));
}