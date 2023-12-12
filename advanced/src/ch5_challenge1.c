/*
1st Challenge

- write a small program that declares the following variables
    - int varialbe with block scope and temporary storage
    - a global double variable thatis only accessible inside this file 
    - a global float variable thatis accessible within the entire program
    - a float local variable with permanent storage
    - a register int variable 
    - a function that is only accessible with the file it is defined

2nd Challenge

- write a program that finds the sum of various numbers

- you cannot pass any variable representing the running total to the sum() function

3rd Challenge

- create a program that shares a variable amongst two files

- create a src file named main.c
    - include global variable used as a loop counter
    - uses global variable to iterate through a loop 5 times
        - inside should invoke a function that is defined in another file ( no not use an include file)
        - display function should take no parameters

- create another src file named display.c
    - display function is defined in this file
        - displays the global variable from main.c (+= 1)
*/

#include <stdio.h>

static double y = 0;

float count = 0; 

static void onlyHere(void);
static int sum(const int number);

extern void display(void);

int main(void)
{
    int x;

    static float forever = 0;

    register int regVar = 20;

    printf("%d\n", sum(15));
    printf("%d\n", sum(45));
    printf("%d\n", sum(10));

    while(count < 5)
        display();

    return 0;
}

static void onlyHere(void)
{
    printf("Hello");
}

static int sum(const int number)
{
    y += number;

    return (int)y;
}