#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int data;
    struct Queue* next;
};
typedef struct Queue Queue;

Queue* front=NULL;
Queue* rear=NULL;

void enqueue(int data)
{
    Queue* tmp = (Queue*)malloc(sizeof(Queue));
    if (tmp == NULL)
    {
        printf("Memory allocation FAILED!\n");
        return;
    }
    else
    {
        tmp->data = data;
        tmp->next = NULL;
    }

    if (front == NULL && rear == NULL)
    {
        front = tmp;
        rear = tmp;
    }
    else
    {
        rear->next = tmp;
        rear = tmp;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is UNDERFLOW!\n");
        return;
    }

    Queue* tmp = front;
    front = front->next;
    free(tmp);

    if (front == NULL)
    {
        rear = NULL;
    }
}

void display()
{
    Queue* tmp=front;
    while(tmp!=NULL)
    {
        printf("%d\n\n",tmp->data);
        tmp=tmp->next;
    }
}

int main()
{
    enqueue(100);
    enqueue(200);
    enqueue(300);

    dequeue();
    dequeue();

    display();

    return 0;
}
