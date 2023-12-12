#include <stdio.h>

int count;

int i = 0;

void write_extern(void);

int main(void)
{
    count = 5;
    write_extern();

    return 0;
}