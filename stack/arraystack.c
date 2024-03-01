#include<stdio.h>
int top=-1;
int array[5];
void push(int data){
    if(top==4){
        printf("stack is overfollow\n");

    }
    else{
        top++;
        array[top]=data;
    }
}
void pop(){
    if(top==-1){
        printf("stack is under follow\n");
    
    }
    else{
        top--;
    }
}
int main(){
    push(5);
    push(6);
    push(7);
    push(8);
    push(9);
    push(10);
    for(int i=top;i>=0;i--){
        printf("%d\n",array[i]);

    }
    return 0;
    //ragib
}
