#include <stdio.h>

#define Warning(...) fprintf(stderr, __VA_ARGS__)
#define UpTo(i, n) for ((i) = 0; (i) < (n); (i)++)

#define PI 3.14
#define CIRCLE_AREA(x) ((PI) * (x) * (x))

double circleArea(double x)
{
    return 3.14 * x * x;
}

int main(void)
{
    Warning("%s: this program is here\n", "Jason");

    int i = 0;

    UpTo(i, 4);
    printf("i = %d\n", i);

    int area = CIRCLE_AREA(4), c = 5;
    printf("Area is %d\n", area);


    return 0;
}