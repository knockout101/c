/*
Challenge #1

- write a C program that generates 50 random numbers between 
    - -0.5 and 0.5 

- you should output the random numbers 
    - the first line of output should be the number of data 
    - the next 50 lines should be the 50 random numbers 

- you are required to use the srand function, passing in the time function 
    - as a seed to using the rand() function 

Challenge #2 

- write a program that will sort an array of doubles from lowest to highest using the qsort function 

- create a function that takes a double array and a size parameter which generates some random double values 
    - void fillarray(double ar[], int n);

- create a function that displays an array (takes a double array and size)
    - void showarray(const double ar[], int n);

- your main function should
    - create an array 
    - fill it with random numbers 
    - display it
    - sort it using qsort 
    - display the sorted array 

Challenge #3

- write a program to print the current time 
    - you should use the time and ctime functions 
    - you should handle errors using fprintf and the exit function with the correct failure code

Challenge #4

- write a program to compute the number of seconds passed since the beginning of the current month 
    - you should use the localtime, difftime, and mktime functions 
    - you should handle errors using fprintf and the exit function with the correct failure codes 
*/
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

void challenge1(void);
void challenge2(void);
void challenge3(void);
void challenge4(void);
void fillArray(double* ar, int size);
void showArray(double* ar, int size);
int sortDoubles(const void* a, const void* b);


#define MAX_DOUBLE 50

int main(void)
{
    printf("\nChallenge1:\n\n");
    challenge1();
    printf("\nChallenge2:\n\n");
    challenge2();
    printf("\nChallenge3:\n\n");
    challenge3();
    printf("\nChallenge4:\n\n");
    challenge4();

    return 0;
}

void challenge1(void)
{
    srand(time(0));

    printf("50 Random Data points between [-0.5, 0.5]:\n");

    int counter = 0;

    for(int i = 0; i < 50; i++)
    {
        printf("%7.4f ", (((float)rand()/RAND_MAX)) - 0.5);                 // rand()/RAND_MAX range is [0, 1] minus -.5 overall [-0.5, 0.5]
        counter++;
        if(counter > 3)
        {
            putchar('\n');
            counter = 0;
        }
    }

    putchar('\n');
}

void challenge2(void)
{
    double ar[MAX_DOUBLE];

    fillArray(ar, MAX_DOUBLE);

    printf("Random Array\n");
    showArray(ar, MAX_DOUBLE);

    qsort(ar, MAX_DOUBLE, sizeof(double), sortDoubles);

    printf("\nSorted array:\n");
    showArray(ar, MAX_DOUBLE);
}

int sortDoubles(const void* a, const void* b)
{
    const double *A = a, *B = b;
    if(*A > *B)
        return 1;
    else if(*A < *B)
        return -1;
    else
        return 0;
}

void fillArray(double* ar, int size)
{
    for(int i = 0; i < size; i++)
        ar[i] = ((double)rand()/(double)RAND_MAX) * 40;
    
}

void showArray(double* ar, int size)
{
    int count = 0;

    for(int i = 0; i < size; i++)
    {
        count++;
        printf("%9.3f", ar[i]);

        if(count > 3)
        {
            putchar('\n');
            count = 0;
        }
    }
    putchar('\n');
}

void challenge3(void)
{
    time_t calendar;

    time(&calendar);

    printf("Today's date is: %s", ctime(&calendar));
}

void challenge4(void)
{
   time_t current_t, prev_mon, ret;

    time(&current_t);
    time(&prev_mon);

    struct tm* prev_struct = localtime(&current_t);

    prev_struct->tm_mday = 0;
    prev_struct->tm_min = 0;
    prev_struct->tm_hour = 0;
    prev_struct->tm_sec = 0;

    if((ret = mktime(prev_struct)) == -1)
    {
        fprintf(stderr, "Operation failed.");
        exit(EXIT_FAILURE);
    }

    printf("The seconds passed sense the beginning of the month: %.2fs\n", difftime(current_t, ret));
}