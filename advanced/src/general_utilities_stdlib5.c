#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char a[10] = "100";
    char b[10] = "3.14";
    char c[] = "123.243sdf", *end = NULL;
    char d[] = "12312.24 7.0", *end = NULL;
    char e[] = "2030330 This is test", *ptr = NULL;

    int a_value = atoi(a);
    long b_value = atof(b);
    double c_value = strtod(a, &end);
    float d_value = strtof(end, NULL);
    long e_value = strtol(e, &ptr, 10);

    printf("a.) Value = %d\n", a_value);
    printf("b.) Value = %ld\n", b_value);
    printf("c.) Value = %lf\n", c_value);
    printf("d.) Value = %f\n", d_value);
    printf("e.) Value = %ld\n", e_value);

    return 0;
}
