#include <stdio.h>
int array[5];
int f=-1;
int r=-1;
void enqueue(int data){
    if(r==4 && f==0){
        printf("Queue is overflow\n");
    }
    else if(r==-1 && f==-1){
        f=0;
        r=0;
        array[r]=data;}
    else{
        r++;
        array[r]=data;
    }
    
}
void dequeue(){
    if(f==-1 && r==-1){
        printf("Queue is empty\n");
    }
    else if(f==r+1){
      
        printf("Queue is underfollow\n");

    }
    else{
        f++;
    }
}
int main(){
    enqueue(5);
    enqueue(5);
    enqueue(5);
    enqueue(5);
    enqueue(5);
    enqueue(5);
    for(int i=f;i<=r;i++){
        printf("%d\n",array[i]);
    }
    return 0;
}
