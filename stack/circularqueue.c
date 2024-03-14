#include <stdio.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;
void enqueue(int x){
  if(rear==-1 && front==-1){
  front=rear=0;
  queue[rear]=x;

  }
  else if((rear+1)%N==front){
    printf("Queueis full\n");

    }
    else{
    rear=rear+1%N;
    queue[rear]=x;
    }

}

void dequeue(){
   if(front==-1 && rear==-1){
   printf("Queue is under follow\n");
   }
   else if(front==rear){
   front=rear=-1;
   }
   else{
   front=(front+1)%N;
   }

}
int main(){
   int i;
   enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    dequeue();
    enqueue(6);
    dequeue();
    dequeue();
    enqueue(7);
    enqueue(8);
   while(front!=i){
   printf("%d",queue[i]);
   i=(i+1)%N;
   }
   return 0;
}
