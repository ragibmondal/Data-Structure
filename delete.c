#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
int main() {
    struct node *head = malloc(sizeof(struct node));
    struct node *second = malloc(sizeof(struct node));
    struct node *third = malloc(sizeof(struct node));
    struct node *fourth = malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;

    second->data = 8;
    second->next = third;

    third->data = 9;
    third->next = fourth;

    fourth->data = 10;
    fourth->next = NULL;
    struct node *temp;
    temp=head;
    head=head->next;
    free(temp);
    temp=NULL;
    /*struct node *lastdel;
    lastdel=head;
    while(lastdel->next->next!=NULL){
        lastdel=lastdel->next;
    }
    free(lastdel->next);

     lastdel->next=NULL;*/
     struct node *middle1,*middle2;
     middle1=head;
     middle2=head;
     int pos=2;
     while(pos!=1){
        middle1=middle2;
        middle2=middle2->next;
        pos--;
     }
     middle1->next =middle2->next;
     free(middle2);
     middle2=NULL;

    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}
