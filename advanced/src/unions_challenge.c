/*
Unions Challenge

- write a program that will define a union and then use this union to assign and access its members 

- you must define a union named student that consists of the following three elements
    - char letterGrade
    - int roundedGrade
    - float exactGrade 

- your program should declare two union variables inside the main method (variable 1 and variable 2)

- your program should assign random values to variable 1 
    - you then need to display each value for each member of this union
    - you should notice that something is wrong

- your program should then assign a value (using variable 2) to its member letter grade and then print it

- your program should then assign a value (using variable 2) to its member rounded grade and then print it

- your program should then assign a value (using variable 2) to its member exact grade and then print it

- you should notice the difference in output with variable 1 and variable 2
    - why is there a difference?

Optional Additions 

- declare the union variables by using the option tag in the declaration 

- use pointers as union variables and practice assigning/accessing members 

- display the total size of the union in bytes 

- Initialize a union member by using a designated initializer 

- Add a union inside a structure
*/
#include <stdio.h>
#include <string.h>


typedef struct student
{
    char* name;
    union grade
    {
        char letterGrade;
        int roundedGrade;
        float exactGrade;
    };
} Student;

void print_student(Student *s);

int main(void)
{

    Student student1 = {"Tristan", .letterGrade = 'A', .exactGrade = 65.53, .roundedGrade = 75}, student2, *pstu1 = &student1, *pstu2 = &student2;

    print_student(pstu1);

    student2.name = "Justin";

    printf("\n-----------------------------------------------\n");
    student2.letterGrade = 'B';
    printf("%s's letter grade: %c\n", pstu2->name, pstu2->letterGrade);
    student2.roundedGrade = 95;
    printf("%s's rounded grade: %d\n", pstu2->name, pstu2->roundedGrade);
    student2.exactGrade = 98.3;
    printf("%s's exact grade: %.1f\n", pstu2->name, pstu2->exactGrade);
    printf("Size of structure: %zd\n", sizeof(student1));
    printf("-----------------------------------------------\n\n");

    return 0;
}

void print_student(Student *s)
{
    printf("\n-----------------------------------------------\n");
    printf("%s's letter grade: %c\n", s->name, s->letterGrade);
    printf("%s's rounded grade: %d\n", s->name, s->roundedGrade);
    printf("%s's exact grade: %.1f\n", s->name, s->exactGrade);
    printf("Size of structure: %zd\n", sizeof(*s));
    printf("-----------------------------------------------\n");
}