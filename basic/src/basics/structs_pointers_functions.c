/*
Structure Pointers and Functions Challenge

- write a C program that creates a structure pointer and passes it to a function
    - create a structure named item with the following members
        - itemName - pointer
        - quality - int
        - price - float
        - amount - float (stores quantity * price)

- create a function named readItem that takes a structure pointer of type item as a parameter
    - this function should read in (from the user) a product name, price, and quantity
    - the contents read in should be stored in the passed in structure to the function

- create a function named print item that takes as a parameter a structure pointer of type item
    - function prints the contents of the parameter

- the main function should declare an itme and a pointer to the item
    - you will need to allocate memory for the itemName pointer
    - the item pointer should be passed into both the read and print item functions
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readItem(Item *pItemEnd, const Item *pItemStart);
void printItem(const Item *pItem);

struct item
{
    char * itemName;
    int quantity;
    float price;
    float amount;
};

typedef struct item Item;

int main(void)
{
    const int MAXLEN = 50;
    char * pCans = (char*)calloc(MAXLEN, sizeof(char));
    char * ptr = (char*)calloc(MAXLEN, sizeof(char));

    strcpy(ptr, "can of soup");
    strcpy(pCans, "Cans");

    Item tempItem = {
        ptr, 50, 0.99, 50 * 0.99
    };

    Item * pTempItem = &tempItem;

    const Item item1 = {
        pCans, 9999, 0.10, item1.price * item1.quantity
    };

    const Item * pItem1 = &item1;

    printItem(pTempItem);
    printItem(pItem1);

    readItem(pTempItem, pItem1);
    printf("READ IN COMPLETED...");

    printItem(pTempItem);

    free(pCans);
    free(ptr);

    return 0;
}

void printItem(const Item *pItem)
{
    printf("\nItem: %s\n\nQuantity: %i\n\nPrice: $%.2f\n\nTotal: $%.2f\n\n", pItem->itemName, pItem->quantity, pItem->price, pItem->quantity * pItem -> price);
}

void readItem(Item *pItemEnd, const Item *pItemStart)
{
    pItemEnd->itemName = pItemStart->itemName;
    pItemEnd->quantity = pItemStart->quantity;
    pItemEnd->price = pItemStart->price;
}