/*
Linked List Challenge

- write a program that performs operations on a linked list 

- you need to create a linked list that stores integers and uses pointers 

- your program should perform the following operations
    - insert node at first 
    - insert node at last 
    - insert node at position
    - delete node from any position
    - Update node value 
    - search element in the linked list 
    - display list 
    - exit
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* nextPtr;
} node_t;

typedef node_t* ListNodePtr;

void insertAtBeginning(ListNodePtr* head, int value);
void insertAtEnd(ListNodePtr* head, int value);
void insert(ListNodePtr* head, int value);
int delete(ListNodePtr* head, int value);
void update(ListNodePtr* head, int value, int updated_value);
node_t findFirst(ListNodePtr* head, int value);

void printList(ListNodePtr head);

int main(void)
{
    ListNodePtr head = NULL;
    int choice = 0, select = 0, select2 = 0;

    printf("Please enter a number to choose from the list:\n"
        "   1 - insert node at beginning\n"
        "   2 - insert node at the end\n"
        "   3 - insert node into specific position\n"
        "   4 - delete node from any position\n"
        "   5 - update node value\n"
        "   6 - find first element in the linked list\n"
        "   7 - display list\n"
        "   8 - exit program\n");

    printf(">> ");
    scanf("%d", &choice);

    while(choice != 8)
    {
        switch(choice)
        {
            case 1:
                printf("Enter a number value to be stored in the node: ");
                scanf("%d", &select);
                insertAtBeginning(&head, select);
                printList(head);
                break;
            case 2:
                printf("Enter a number value to be stored in the node: ");
                scanf("%d", &select);
                insertAtEnd(&head, select);
                printList(head);
                break;
            case 3:
                printf("Enter a number value to be stored in the node: ");
                scanf("%d", &select);
                insert(&head, select);
                printList(head);
                break;
            case 4:
                printf("Enter a position to delete the node from: ");
                scanf("%d", &select);
                delete(&head, select);
                printList(head);
                break;
            case 5:
                printf("enter a position followed by a whole number to update that position (x y): ");
                scanf("%d %d", &select, &select2);
                update(&head, select, select2);
                printList(head);
                break;
            case 6:
                printf("Enter a value you'd like to find in the linked list (returns first find): ");
                scanf("%d", select);
                findFirst(&head, select);
                printList(head);
                break;
            case 7:
                printList(head);
                break;
        }
    }
    
    return 0;
}

void insertAtBeginning(ListNodePtr* head, int value)
{
    ListNodePtr new_node = malloc(sizeof(node_t));
    new_node->data = value;
    new_node->nextPtr = *head;
    *head = new_node;
}

void insertAtEnd(ListNodePtr* head, int value)
{
    ListNodePtr current = *head;

    if(current != NULL)
    {
        while(current->nextPtr != NULL)
            current = current->nextPtr;
        
        current->nextPtr = malloc(sizeof(node_t));
        current->nextPtr->data = value;
        current->nextPtr->nextPtr = NULL;
    }
    else
    {
        current->nextPtr = malloc(sizeof(node_t));
        current->nextPtr->data = value;
        current->nextPtr->nextPtr = NULL;
        *head = current;
    }
}

void insert(ListNodePtr* head, int value)
{
    ListNodePtr currentPtr, prevPtr, newPtr;

    newPtr = malloc(sizeof(node_t));

    if(newPtr != NULL)
    {
        newPtr->data = value;
        newPtr->nextPtr = NULL;

        prevPtr = NULL;
        currentPtr = *head;

        while(currentPtr->nextPtr != NULL && value > currentPtr->data)
        {
            prevPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }
        if(prevPtr == NULL)
        {
            newPtr->nextPtr = *head;
            *head = newPtr;
        }
        else
        {
            prevPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else
        printf("The memory was not able to be allocated for %d", value);
}

int delete(ListNodePtr* head, int value)
{
    ListNodePtr prevPtr, currentPtr, tempPtr;
    
    if(value == (*head)->data)
    {
        tempPtr = *head;
        *head = (*head)->nextPtr;
        free(tempPtr);
        return value;
    }
    else 
    {
        currentPtr = *head;
        prevPtr = NULL;
        
        while(currentPtr->nextPtr != NULL && currentPtr->data != value)
        {
            prevPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }
        if(currentPtr != NULL)
        {
            tempPtr = currentPtr;
            prevPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return value;
        }
    }

    return -1;
}
void update(ListNodePtr* head, int value, int updated_value)
{
    ListNodePtr currentPtr = *head;
    
    if(currentPtr->data == value)
        currentPtr->data = updated_value;
    else
    {
        while(currentPtr->nextPtr != NULL && currentPtr->data != value)
            currentPtr = currentPtr->nextPtr;
        
        if(currentPtr != NULL)
            currentPtr->data = updated_value;
    }
}
node_t findFirst(ListNodePtr* head, int value)
{
    ListNodePtr currentPtr = *head;

    if(currentPtr->data == value)
        return currentPtr;
}