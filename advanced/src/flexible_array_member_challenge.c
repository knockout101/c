/*
Flexible Array Member Challenge

- write a program that uses a flexible array member inside a structure

- create a structure named myArray that has a length member and a flexible array member named array 

- read in from the user the size of the array at runtime 

- allocate memory for the structure based on this size read in from the user 

- set the length member and fill the array with seom dummy data 

- print the array elements
*/

#include <stdio.h>
#include <stdlib.h>

struct example
{
    int pNum;
    int answerSize;
    int answer[];
};

struct example* createExample(struct example* a, int pNum, int answerSize, int answer[]);

void printExample(struct example* example);

int main(void)
{
    int userInput = 0, i = 0;

    printf("Please enter the answer to problem X: ");
    scanf("%d", &userInput);

    int array[userInput];

    while(i++ < userInput)
    {
        array[i] = 50 + (i + 1);
    }

    struct example* ptr = createExample(ptr, 1, userInput, array);

    printExample(ptr);

    return 0;
}

void printExample(struct example* example)
{
    printf("Example number: %d\n", example->pNum);
    printf("Answer is: ");

    int i = 0;

    while(i++ < example->answerSize)
        printf("%d", example->answer[i]);
    
    printf("\n");
}

struct example* createExample(struct example* a, int pNum, int answerSize, int answer[])
{
    a = (struct example*)malloc(sizeof(*a) + sizeof(int) * answerSize);

    a->pNum = pNum;
    a->answerSize = answerSize;

    int i = 0;

    while(i++ < a->answerSize)
        (a->answer)[i] = answer[i];

    return a;
}