#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct treeNode
{
    int data;
    struct treeNode* leftPtr;
    struct treeNode* rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode* TreeNodePtr;

void insertNode(TreeNodePtr* treePtr, int value);
void inOrder(TreeNodePtr treePtr);
void PostOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);

int main(void)
{
    int i = 0; // counter t o loop from 1-10
    int item = 0;
    TreeNodePtr rootPtr = NULL;

    srand(time(NULL));
    printf("The numbers being placed in the tree are:\n");

    for(i = 1; i <= 10; i++)
    {
        item = rand() % 15;
        printf("%3d", item);
        insertNode(&rootPtr, item);
    }
    
    printf("\n\nThe preOrder traversal is:\n");
    preOrder(rootPtr);

    return 0;
}

void insertNode(TreeNodePtr* treePtr, int value)
{
    if(*treePtr == NULL)
    {
        *treePtr = malloc(sizeof(TreeNode));

        if(*treePtr != NULL) // check if TreeNodePtr 
        // assigns values to the new leaf node
        {
            (*treePtr)->data = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        }
        else
            printf("%d not inserted. No memory available.\n", value);
    }
    else
    {
        if(value < (*treePtr)->data)
        {
            insertNode(&((*treePtr)->leftPtr), value);
        }
        else if(value > (*treePtr)->data)
        {
            insertNode(&((*treePtr)->rightPtr), value);
        }
        else
        {
            printf("dup");
        }
    }
}

void inOrder(TreeNodePtr treePtr)
{
    if(treePtr != NULL)
    {
        inOrder(treePtr->leftPtr);
        printf("%3d", treePtr->data);
        inOrder(treePtr->rightPtr);
    }
}

void preOrder(TreeNodePtr treePtr)
{
    if(treePtr != NULL)
    {
        printf("%3d", treePtr->data);
        preOrder(treePtr->leftPtr);
        preOrder(treePtr->rightPtr);
    }
}

void postOrder(TreeNodePtr treePtr)
{
    if(treePtr != NULL)
    {
        postOrder(treePtr->leftPtr);
        postOrder(treePtr->rightPtr);
        printf("%3d", treePtr->data);
    }
}