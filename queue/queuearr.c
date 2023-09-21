//queue implementation using array
//First In First Out (insert at back remove at front)

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int q[MAX],front=-1,rear=-1;
void enqueue(int x){
    if(rear==MAX-1){
        printf("Queue is full");
    }
    if(front==-1){
        front=0;
        rear=0;
        q[front]=x;
    }
    else{
        rear++;
        q[rear]=x;
    }
}

void dequeue(){
    if(front==-1){
        printf("queue is empty");
    }
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        front++;
    }
}

void display(){
    if(front==-1){
        printf("queue is empty");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d",q[i]);
        }
    }

}

int main(){
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    dequeue();
    display();
    return 0;
    
    
}