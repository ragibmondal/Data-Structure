#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
int main(){
    typedef struct node node;
    node *head, *b,*c,*ptr;
    head=malloc(sizeof(node));
    b=malloc(sizeof(node));
    c=malloc(sizeof(node));

    head->data=1;
    b->data=2;
    c->data=3;

    head->next=b;
    b->next=c;
    c->next=NULL;

    //first insert
    node*first;
    first=malloc(sizeof(node));
    first->data=90;
    first->next=head;
    head=first;

   //middle insert
   node*middle;
   middle=malloc(sizeof(node));
   middle->data=100;
   middle->next=NULL;

   int pos=3;
   pos--;
   node*tr;
   tr=head;
   while(pos!=1){
    tr=tr->next;
    pos--;
   }
   middle->next=tr->next;
   tr->next=middle;

   //last insertion
   node*last;
   last=malloc(sizeof(node));
   last->data=120;
   last->next=NULL;
   c->next=last;
   c=last;

   ptr=head;
   while(ptr!=NULL){
    printf("%d\n",ptr->data);
    ptr=ptr->next;
   }
   return 0;
}
