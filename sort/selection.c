/* initialize the ith element of first for loop as min value and have another loop starts from i+1 
if any smaller element found swap it */


#include<stdio.h>

//swap function
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}


void selectionsort(int arr[],int size){
    for(int i=0;i<size;i++){
        int min=i; //initializing first value as min value or i th element as min
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[min]){    //if j th element (any element after i) < i th element store that as min and compare with all rest elemts
                min=j;
            }
        }
        if(arr[i]!=arr[min]){
            swap(&arr[min],&arr[i]); //after comparing with every elements if min value found swap 
        }
        
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
    selectionsort(arr1,size);
    printf("the sorted array\n");
    printarray(arr1,size);
    return 0;
}


