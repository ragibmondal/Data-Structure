#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *pre;
    struct node *next;
};

int main()
{
    typedef struct node node;
    node *head,*second,*third,*ptr;
    head=malloc(sizeof(node));
    second=malloc(sizeof(node));
    third=malloc(sizeof(node));

    head->data=5;
    head->next=second;
    head->pre=NULL;

    second->data=6;
    second->next=third;
    second->pre=head;

    third->data=7;
    third->next=NULL;
    third->pre=second;

    ptr=head;
    while(ptr!= NULL)
    {
      printf("%d\n",ptr->data);
        ptr=ptr->next;
    }

    return 0;
}
