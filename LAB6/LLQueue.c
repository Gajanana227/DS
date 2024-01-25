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
    Node *front;
    Node *rear;

}LinkedList;

void enqueue(LinkedList *queue,int value)
{
    Node *newNode=createNode(value);
    if(queue->front==NULL)
    {
        queue->front=newNode;
        queue->rear=newNode;
    }
    else
    {
       queue->rear->next=newNode;
       queue->rear=newNode;
    }

}

int dequeue(LinkedList *queue)
{
    if(queue->front==NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    int dequeuedvalue=queue->front->data;
    Node *temp=queue->front;
    queue->front=queue->front->next;
    free(temp);

    return dequeuedvalue;
}

int main()
{
    LinkedList queue;
    queue.front=NULL;
    queue.rear=NULL;

    printf("Queue operations:\n");
    enqueue(&queue,40);
    enqueue(&queue,50);
    enqueue(&queue,60);
    displayList(queue.front);

    printf("Popped from queue:%d\n",dequeue(&queue));
    printf("Popped from queue:%d\n",dequeue(&queue));

    displayList(queue.front);
    return 0;
}
