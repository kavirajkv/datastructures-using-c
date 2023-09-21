//stack implementation using array

#include<stdio.h>
#define max 10

int stack[max],top=-1;

void push(int x){
    if(top=max-1){
        printf("stack overflow");
    }
    else{
        stack[top++]=x;
    }
}

void pop(){
    if(top==-1){
        printf("stack underflow");
    }
    else{
       return stack[top--];
    }
}