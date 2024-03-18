#include <stdio.h>

struct QNode
{
    int key;
    struct QNode* next;
};

struct Queue
{
    struct QNode* front, *rear;
};

struct QNode* newNode(int k)
{
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode*));
    temp->key = k;
    temp->next = NULL;
    return temp;
}

