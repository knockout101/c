#include <stdio.h>

int main(void)
{
    char *str = "Jason Instructor 43";
    char name[10], title[10];
    int age, ret;

    ret = sscanf(str, "%s %s %d", name, title, &age);

    printf("Name: %s\n", name);
    printf("Title: %s\n", title);
    printf("Age: %d\n", age);

    return 0;
}