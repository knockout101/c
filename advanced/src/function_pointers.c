#include <stdio.h>

int somedisplay();
void funct1(int);
void funct2(int);

typedef void FuncType(int);

int main(void)
{
    // typedef function pointer method, convention

    FuncType *func_ptr2 = NULL;

    func_ptr2 = funct1;

    (*func_ptr2)(100);

    func_ptr2 = funct2;

    (*func_ptr2)(200);

    // Basic way of doing function pointers
    int (*func_ptr)();

    func_ptr = somedisplay;

    printf("\nAddress of function somedisplay is %p\n", func_ptr);

    (*func_ptr)();

    return 0;
}

int somedisplay()
{
    printf("\n---Displaying some texts---\n");
    return 0;
}

void func1(testarg)
{
    printf("funct1 got an argument of %d\n", testarg);
}

void funct2(testarg)
{
    printf("funct2 got an argument of %d\n", testarg);
}