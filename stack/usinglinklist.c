#include <stdio.h>
#include <stdio.h>
struct node{
    int data;
    struct node*next;
};
struct node *head=NULL,*temp;
void push(int val){
    struct node*newnode =malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=head;
    head=newnode;

}
void pop(){
    if(head==NULL){
        printf("stack is empty\n");
    }
    else{
        printf("poped elements=%d\n",head->data);
        temp=head;
        head=head->next;
    }
}
int main(){
    push(4);
    push(5);
    push(6);
    push(7);
    pop();
    pop();
    struct node*ptr;
    ptr=head;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    
    }
    return 0;
    //ragib
}
