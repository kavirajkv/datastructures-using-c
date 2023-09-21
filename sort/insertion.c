/*Insertion sort is taking a new element and comparing with its before element if smaller it inserts before it and
its before til key<i-1*/

#include<stdio.h>

void insertionsort(int arr[],int size){
    for(int i=1;i<size;i++){
        int key=arr[i];   //initializing key as i th element
        int j=i-1; //to compare with before element
        while(key<arr[j] && j>=0){    
            arr[j+1]=arr[j];   //if key is less then before element
            j--;  //to compare with every element till j>=0 if successive elements also less than key
        }
        arr[j+1]=key;  //when key can't move further i.e greater than before value
    }
}

void printarray(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("\t%d",arr[i]);
    }
}

int main(){
    int arr1[]={8,4,6,2,1};
    int size=sizeof(arr1)/sizeof(arr1[0]);
    insertionsort(arr1,size);
    printf("the sorted array\n");
    printarray(arr1,size);
    return 0;
}