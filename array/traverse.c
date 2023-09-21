#include<stdio.h>

int main(){
    int arr[30];
    int i,n;
    printf("Enter the no. of elements in array: ");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        printf("Enter array's %d element:",i);
        scanf("%d",&arr[i]);
    }

    printf("The elements of your array are: ");
    for (i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;


}