//C program forn binary search

#include<stdio.h>

int binarysearch(int arr[],int size,int target){
    int mid;
    int left=0;
    int right=size-1;
    

    while (left <= right){
        mid=(left+right)/2;

        if(arr[mid]==target){
            return mid;
        }

        if(arr[mid]<target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return -1;
}


int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 6;
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = binarysearch(arr,size,target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}