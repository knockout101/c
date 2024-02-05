/*
Macros Challenge 

- 1
    - write a program to print the values of the following predefined symbolic constants
        - __LINE__
        - __FILE__
        - __DATE__ 
        - __TIME__ 
        - __STDC__

- 2 
    - write a program that defines a macro that accepts two parameters and returns the sum of the given numbers 

    #define MACRO_NAME(params) MACRO_BODY 

    - your program should have the user enter the two numbers 

    - your program should display the sum as output by invoking the above macro 

- 3
    - write a program to find the square and the cube of a number using macros 

    - your program should have the user enter any number 

    - your program should then display the square and cube of the number as output by invoking the above macros 

- 4
    - write a program to check whether a character is uppercase or lowercase using macros 

    - your program should have the user enter any character (getchar())

    - your program should then display whether the character is upper or lower case as output by invoking the above macros 

Additional Challenges

- further checks on characters 

- logic to check alphabets, digits, alphanumeric, vowels, consonants, special characters, white space etc.
    - some of the above macros can use the other macros 
        - an IS_ALPHANUMERIC macro could use an IS_ALPHABET and IS_DIGIT macros
*/

#include <stdio.h>

#define SQUARE(a) ((a) * (a))
#define CUBE(a) ((a) * (a) * (a))
#define SUM(a,b) ((a) + (b))
#define IS_UPPER(ch) (((int)(ch) > 64 && (int)(ch) < 91) ? 1 : 0)
#define IS_LOWER(ch) (((int)(ch) > 96 && (int)(ch) < 123) ? 1 : 0)

        

void problem1(void)
{   
    printf("\nProblem 1:\n\n");
    printf("file: %s\nline: %d\ndate: %s\ntime: %s\n", __FILE__, __LINE__, __DATE__, __TIME__);
}

void problem2(void)
{
    printf("\nProblem 2:\n\n");
    int a = 0, b = 0;

    printf("Please enter any 2 numbers separated by a space to sum up: ");
    scanf("%d %d", &a, &b);
    printf("The numbers chose: %d and %d\n", a, b);
    printf("The sum of a and b: %d\n", SUM(a, b));
}

void problem3(void)
{
    printf("\nProblem 3:\n\n");
    int a = 0;
    printf("Please select a number to be squared and cubed: ");
    scanf("%d", &a);
    printf("Selected number: %d\n", a);
    printf("Squared: %d\n", SQUARE(a));
    printf("Cubed: %d\n", CUBE(a));
}

void problem4(void)
{
    printf("\nProblem 4:\n\n");
    printf("Please enter a character to check for case: ");
    char ch = getchar();
    if(IS_UPPER(ch))
        printf("%c is uppercase.\n", ch);
    else if(IS_LOWER(ch))
        printf("%c is lowercase.\n", ch);
    else 
        printf("%c is not alphabetical.\n", ch);

}

int main(void)
{
    problem1();
    problem2();
    problem3();
    problem4();

    return 0;
}