/*
Variable Length Arrays

- write program to read elements in an array and find the sum of array elements

Example:
Input elements: 10, 20, 30, 40, 50

Output:
Sum of all elements = 150

- you must use a vla for the size of your array

- the obvious benefit of allowing varible-length arrays is that you don't have to know in advance of your program running, how much memory to allocate for your array variables
*/

#include <stdio.h>

int sum(const size_t rows, const size_t cols, int array[rows][cols])
{
    int sum = 0;

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            sum += array[i][j];
    return sum;
}

int main(void)
{
    size_t rows;
    size_t cols;

    printf("Enter the number of rows for the array: ");
    scanf("%zd", &rows);
    printf("Enter the number of rows for the array: ");
    scanf("%zd", &cols);

    int array1[rows][cols];
    printf("Sum of everything in the array: %d", sum(rows, cols, array1));

    return 0;
}