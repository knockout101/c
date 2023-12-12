#include <stdio.h>

#define peach int
#define int_pointer int *

int_pointer chalk, cheese; // same as int *chalk, cheese; because int_pointer is merely and simply replaced by preprocessor with int *

typedef char * char_ptr;

char_ptr Bently, Rolls_Royce; // both are pointers because they are of type char * respectively

unsigned peach i;

typedef int banana;

unsigned banana u;

typedef int* i_pointer;

int main(void)
{
    i_pointer p;    // same as int *p

    i_pointer a, *b;    // same as int *a, **b;

    i_pointer myArray[10];  // same as int *myArray[10];


    return 0;
}