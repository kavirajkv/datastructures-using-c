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
    int elem,j;
    int flag=0;
    printf("Enter the element to be deleted: ");
    scanf("%d",&elem);
    for(i=0;i<n;i++)
    {
        if(arr[i]==elem)
        {
            for(j=i;j<n-1;j++)
            {
             arr[i]=arr[i+1];   
            }
            n=n-1;
            flag=1;
            
        }
        if(flag==1)
        {
            arr[i]=arr[i+1];
        }
    }
    if(flag==0)
    printf("Element not found");
    printf("The elements of your array after deletion: ");
    for (i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }

    return 0;
}