#include <stdio.h>

union mixed
{
    char c;
    float f;
    int i;
};


union number
{
    int x;
    double y;
};

void foo(union number n)
{
    union number x = n;
}

int main(void)
{
    union mixed i;

    i.f = 755.223;  // can only access one variable at a time
    
    printf("Float = %f\n", i.f);

    union number value;
    union number *y = &value;

    y->y  = 100.0;  // first y is the union number* y, second y is the union number y, which is a double 
    printf("value of integer x: %d\n", y->x);
    printf("value of integer y: %.1f\n", y->y);



    return 0;
}