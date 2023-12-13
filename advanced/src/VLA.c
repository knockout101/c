#include <stdio.h>

void array(int size);
void print2D(const size_t rows, const size_t cols, const int array[rows][cols]);

int main()
{
    size_t rows = 0;
    size_t columns = 0;

    printf("Enter the number of rows you want to store: ");
    scanf("%zd", &rows);

    printf("Enter the number of columns you want to store: ");
    scanf("%zd", &columns);

    float values[rows][columns];

    array(10);

    return 0;
}

void array(int size)
{
    char alpha[size];
    int x = 0;

    while(x < size)
    {
        alpha[x] = 'A' + x;
        printf("alpha is: %c\n", alpha[x]);
        x++;
    }
}

void print2D(const size_t rows, const size_t cols, const int array[rows][cols]);