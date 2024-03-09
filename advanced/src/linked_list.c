#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node* nextPtr;
} node_t;

typedef node_t* ListNodePtr;

/* Prototypes */
void insert(ListNodePtr *head, char value);
void insertAtEnd(ListNodePtr *head, char value);
void insertAtBeginning(ListNodePtr *head, char value);
char delete(ListNodePtr* head, char value);
void deleteAtBeginning(ListNodePtr* head);
int isEmpty(ListNodePtr head);
void printList(ListNodePtr currentPtr);

int main(void)
{
    ListNodePtr head = NULL;
    int choice = 0;
    char item = '\0';
    
    printf("Enter your choice:\n"
    "   1 to insert an element into the list in alphabetical order"
    "   2 to insert an element at the end of the list.\n"
    "   3  to insert an element at the beginning of the list.\n"
    "   4 to delete an element from the list.\n"
    "   5 to delete an element from the beginning of the list.\n"
    "   6 to end.\n");

    printf("::");
    scanf("%d", &choice);

    while(choice != 6)
    {
        switch(choice)
        {
            case 1:
                printf("Enter a character: ");
                scanf("\n%c", &item);
                insert(&head, item);
                printList(head);
                break;
            case 2:
                printf("Enter a character: ");
                scanf("\n%c", &item);
                insertAtEnd(&head, item);
                printList(head);
                break;  
                
            case 3:
                printf("Enter a character: ");
                scanf("\n%c", &item);
                insertAtBeginning(&head, item);
                printList(head);
                break;

            case 4:
                if(!isEmpty(head))
                {
                    printf("Enter character to be deleted: ");
                    scanf("\n%c", &item);

                    if(delete(&head, item))
                    {
                        printf("%c deleted.\n", item);
                        printList(head);
                    }
                    else
                    {
                        printf("%c not found.\n\n", item);
                    }
                    
                }
                else
                    printf("List is empty.\n\n");
                break;
                
            case 5:
                if(!isEmpty(head))
                {
                    deleteAtBeginning(&head);
                    printf("%c deleted.\n", item);
                    printList(head);
                }
                else
                    printf("List is empty.\n\n");
                break;
                
        }  
    }

    return 0;
}