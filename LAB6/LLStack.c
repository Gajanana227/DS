#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;

Node *createNode(int value)
{
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;

}

void displayList(Node *head)
{
    while(head!=NULL)
    {
        printf("%d->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}

typedef struct
{
    Node *top;

}LinkedList;

void push(LinkedList *stack,int value)
{
    Node *newNode=createNode(value);
    newNode->next=stack->top;
    stack->top=newNode;
}

int pop(LinkedList *stack)
{
    if(stack->top==NULL)
    {
        printf("stack is empty\n");
        return -1;
    }
    int poppedValue=stack->top->data;
    Node *temp=stack->top;
    stack->top=stack->top->next;
    free(temp);

    return poppedValue;
}

int main()
{

    LinkedList stack;
    stack.top=NULL;

    printf("Stack operations:\n");
    push(&stack,10);
    push(&stack,20);
    push(&stack,30);
    displayList(stack.top);

    printf("Popped from stack:%d\n",pop(&stack));
    printf("Popped from stack:%d\n",pop(&stack));

    displayList(stack.top);
    return 0;
}
