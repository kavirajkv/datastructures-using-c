/*quick sort 
-first fix first or last element as pivot
-then start a loop from start if ith element is less than pivot swap and increment i and repeat
till it reaches end finds no lesser value then swap pivot with current+1 
now you found exact position of pivot split the array before and after pivot
recursively call quicksort of divided array */

// C code to implement quicksort

#include<stdio.h>

//swap function
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

//function to find the pivot
int partition(int arr[],int low,int high){
    int pivot=arr[low]; //first element as pivot
    int i=low+1; 

    for(int j=1;j<high;j++){
        if(arr[j]<pivot){
            swap(&arr[j],&arr[i]);
            i++;
        }
    }
    swap(&arr[i-1],&arr[low]);
    return (i-1);
}

//function to recursively sort the elements
void quicksort(int arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

//function to print array
void printarray(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("\t%d",arr[i]);
    }
}

int main(){
    int arr1[]={8,4,6,2,1};
    int size=sizeof(arr1)/sizeof(arr1[0]);
    quicksort(arr1,0,size);
    printf("the sorted array\n");
    printarray(arr1,size);
    return 0;
}

