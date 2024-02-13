#include <stdio.h>

void send(void* pData, int nLen);
void example2(void);

int main(void)
{
    int i = 10;
    float f = 2.34;
    char ch = 'k';

    void* vptr = NULL;

    vptr = &i;

    printf("Value of i = %d\n", *(int*)vptr);

    vptr = &f;

    printf("Value of f = %f\n", *(float*)vptr);

    vptr = &ch;

    printf("Value of ch = %c\n", *(char*)vptr);

    return 0;
}

void example2(void)
{
    void* pvData = NULL; // all pointers are 8 bytes on 64 bit processor
    int* iData = NULL;
    char* cData = NULL;
    float* fData = NULL;
}

void example3(void)
{
    int aiData[3] = {100, 200, 300};

    void* pvData = &aiData[1];

    pvData += sizeof(int); // can work but not best practice to perform pointer arithmetic

    printf("%d", *(int*)pvData);   
}

