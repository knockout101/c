/*
write a program that declares a structure and prints out it's content
    - create an emplee structure with 3 members
        -name
        -hireDate
        -salary
    
    - declare and init an instance of an employee type

    - read in a second employee from the console and store it in a structure of type employee

    - print out the contents of each employee
*/
#include <stdio.h>

struct employee
{
    char name[50];
    char hireDate[15];
    float salary;
} Employee;

int main(void)
{
    struct employee emp1 = {"Mike", "10/15/20", 75000.00f};

    printf("employee: emp1 = [%s] [hired: %s] [$%.2f]", emp1.name, emp1.hireDate, emp1.salary);

    printf("\nEnter employee information: \n");
    printf("Name: ");
    scanf("%s", emp1.name);

    printf("\nHire Date: ");
    scanf("%s", emp1.hireDate);

    printf("\nSalary: ");
    scanf("%f", &emp1.salary);

    printf("employee: emp1 = [%s] [hired: %s] [$%.2f]", emp1.name, emp1.hireDate, emp1.salary);

    return 0;
}