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
    int elem,pos;
    printf("Enter the element to be  inserted: ");
    scanf("%d",&elem);
    printf("Enter the position you want to insert between 0 to %d: ",n);
    scanf("%d",&pos);
    if(pos>n)
    printf("Index out of range insertion not possible\n");
    else
    {
    for(i=n;i>=pos;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos]=elem;
    n=n+1;
    }
    printf("The elements of array after insertion are:");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}

