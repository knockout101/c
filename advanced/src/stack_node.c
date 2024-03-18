#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct node* link;
} node_t;

typedef node_t* stackPtr;

// global variables
stackPtr top = NULL;

void push(int data);
void pop();
int peek();
void display();
int isEmpty();



int main(void)
{
    push(1);
    push(2);
    push(3);
    push(4);

    display();

    pop();
    pop();

    display();

    return 0;
}

void push(int data)
{
    stackPtr newNode;
    
    newNode = malloc(sizeof(node_t));

    if(newNode != NULL)
    {
        newNode->data = data;
        newNode->link = top;
        top = newNode;
    }
    else
        printf("No space available to allocate");
}

int isEmpty()
{
    return top == NULL;
}

void pop()
{
    stackPtr temp = NULL;
    if(top != NULL)
    {
        temp = top;
        top = temp->link;
        temp->link = NULL;
        free(temp);
    }
}

int peek()
{
    if(top == NULL)
        return -1;
    else
        return top->data;
}

void display()
{
    stackPtr temp = NULL;

    if(top != NULL)
    {
        temp = top;
        printf("[STACK] ");
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        putchar('\n');
    }
    else
        printf("\nThe stack is empty\n\n");
}