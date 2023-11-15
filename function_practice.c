#include <stdio.h>


// function which finds the greatest common divisor of two non-negative integer values
// function for finding the absolute value of a number
// function to compute square root of a number

float getGCD(int x, int y);
float absoluteValue(float x);
float squareRoot(float x);

int main()
{
    int num1 = 64, num2 = 32;

    float flt1 = -100, flt2 = 1, flt3 = 0;

    printf("\nnumber 1: %d and number 2: %d  GCD: %.2f\n", num1, num2, getGCD(num1, num2));

    printf(
        "\nThis is the absolute value of the floats: `%.1f` = %.1f, `%.1f` = %.1f, `%.1f` = %.1f\n\n", 
        flt1, absoluteValue(flt1), flt2, absoluteValue(flt2), flt3, absoluteValue(flt3)
    );

    return 0;
}

float getGCD(int x, int y)
{
    int result;

    while ((x % y) > 0)
    {
        result = x % y;
        x = y;
        y = result;
    }

    return (float) y;
}

float absoluteValue(float x)
{
    float result;

    if (x >= 0){
        return x;
    }

    result = -(x);

    return result;
}


