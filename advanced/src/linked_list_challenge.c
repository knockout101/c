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
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node* nextPtr;
} node_t;

typedef node_t* ListNodePtr;

void insertAtBeginning(ListNodePtr* head, int value);
void insertAtEnd(ListNodePtr* head, int value);
void insert(ListNodePtr* head, int value, int position);
int delete(ListNodePtr* head, int value);
void update(ListNodePtr* head, int value, int updated_value);
int findFirst(ListNodePtr head, int value);
void printList(ListNodePtr head);
bool isEmpty(ListNodePtr head);


int main(void)
{
    ListNodePtr head = NULL;
    int select = 0, select2 = 0, choice, ret;

    while(choice != 8)
    {
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

        ret = scanf("\n %d", &choice);

        if(ret > 0)
        {
            switch(choice)
            {
                case 1:
                    /* Insert at beginning */
                    printf("Enter a number value to be stored in the node at the beginning: ");
                    scanf("%d", &select);
                    insertAtBeginning(&head, select);
                    printList(head);
                    break;
                case 2:
                    /* Insert at end */
                    printf("Enter a number value to be stored in the node at the end: ");
                    scanf("%d", &select);
                    insertAtEnd(&head, select);
                    printList(head);
                    break;
                case 3:
                    /* Insert at position, or if position is out of range, add to the end */
                    printf("Enter a value and a position separated by a space (value position): ");
                    scanf("%d %d", &select, &select2);
                    insert(&head, select, select2);
                    printList(head);
                    break;
                case 4:
                    /* Check if empty, then delete's value if found in the list */
                    if(!isEmpty(head))
                    {
                        printf("Enter a value to be deleted from the list: ");
                        scanf("%d", &select);
                        delete(&head, select);
                        printList(head);
                    }
                    else
                        printf("\n[LINKED LIST] delete failed. List empty\n\n");
                    break;
                case 5:
                    /* check if empty, then update value if found in the list */
                    if(!isEmpty(head))
                    {
                        printf("enter the value being replaced followed by the value that is going to be replacing it (replaced, new_value): ");
                        scanf("%d %d", &select, &select2);
                        update(&head, select, select2);
                        printList(head);
                    }
                    else
                        printf("\nList is empty, no values to update\n\n");
                    break;
                case 6:
                    /* check if empty, then prints index (position) of the first found value selected */
                    if(!isEmpty(head))
                    {
                        printf("Enter a value you'd like to find in the linked list (returns first find): ");
                        scanf("%d", &select);
                        printf("\nIndex: %d\n\n", findFirst(head, select));
                        printList(head);
                    }
                    else
                        printf("\nList is empty, no values to update\n\n");
                    break;
                case 7:
                    printList(head);
                    break;
                default:
                    break;
            } // switch end
        } // if end
        else
        {
            printf("\nEnter must be between 1-8\n\n");
            fflush(stdin);
            continue;
        }
    } // while end
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

void insert(ListNodePtr* head, int value, int position)
{
    ListNodePtr currentPtr, prevPtr, newPtr;
    int count = 0;

    newPtr = malloc(sizeof(node_t));

    if(newPtr != NULL)
    {
        newPtr->data = value;
        newPtr->nextPtr = NULL;

        prevPtr = NULL;
        currentPtr = *head;

        while(currentPtr != NULL && count < position)
        {
            count++;
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
        while(currentPtr != NULL && currentPtr->data != value)
            currentPtr = currentPtr->nextPtr;
        
        if(currentPtr != NULL)
            currentPtr->data = updated_value;
        else
            printf("\nThe value %d, doesn't exist in list\n", value);
    }
}
int findFirst(ListNodePtr head, int value)
{
    ListNodePtr currentPtr = head;
    int count = 0;

    if(currentPtr->data == value)
        return count;
    else
    {
        while(currentPtr != NULL && currentPtr->data != value)
        {
            currentPtr = currentPtr->nextPtr;
            count++;
        }
        if(currentPtr == NULL)
        {
            printf("\nNo value was found\n\n");
            return -1;
        }
        else
            return count;
    }
}

void printList(ListNodePtr head)
{
    ListNodePtr currentPtr = head;

    if(currentPtr == NULL)
    {
        printf("\n[LINKED LIST] empty\n\n");
    }
    else
    {
        printf("\n[LINKED LIST] ");
        while(currentPtr != NULL)
        {
            printf("%d --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL\n\n");
    }
}

bool isEmpty(ListNodePtr head)
{
    return head == NULL;
}