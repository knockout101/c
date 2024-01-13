#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf buf;

void myFunction()
{
    printf("in myFunction()\n");
    longjmp(buf, 1);

    printf("You never see this, because I long jumped\n");
}

int main(void)
{
    if (setjmp(buf))
        printf("back in main function\n");

    else
    {
        printf("First time through\n");
        myFunction();
    }

    return 0;
}