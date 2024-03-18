#include <stdio.h>

#define MAXSIZE 5 

struct stack
{
    int stk[MAXSIZE];
    int top;
};

typedef struct stack STACK;

STACK s;

void push(void);
void pop(void);
void display(void);


 int main(void)
 {
    int choice;
    int option = 1;
    s.top = -1;

    while(option)
    {
        printf("Select a number for the command\n" 
        "   1. PUSH\n" 
        "   2. POP\n" 
        "   3. DISPLAY\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                push();
                break;
        }
        fflush(stdin);
        printf("Do you want to continue(type 0 or 1)?\n");
        scanf("%d", &option);
    }

    return 0;
 }

 void push()
 {
    int num;
    if(s.top == (MAXSIZE - 1))
    {
        printf("Stack is full");
        return;
    }
    else
    {
        printf("Enter the element to be pushed\n");
        fflush(stdin);
        scanf("%d", &num);
        s.top += 1;
        s.stk[s.top] = num;
    }
    return;
}

void pop()
{
    int num = 0;

    if(s.top == -1)
    {
        printf("The stack is empty\n");
        return (s.top);
    }
    else 
    {
        num = s.stk[s.top];
        s.top -= 1;
    }
    return;
}

void display()
{
    int i = 0;
    if(s.top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        for(i = s.top; i >= 0; i--)
            printf("%d ", s.stk[i]);

        putchar('\n');
    }
}