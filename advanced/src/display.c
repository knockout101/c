/*
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

void display(void)
{
    extern float count;

    printf("The count is %.0f\n", ++count);
}

