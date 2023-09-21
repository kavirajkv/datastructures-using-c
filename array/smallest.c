#include<stdio.h>

int main()
{
    int arr[100];
    int n, i;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    int smallest=arr[0];
    for(i=0;i<n;i++)
    {
        if(arr[i]<smallest)
        {
            smallest=arr[i];
        }
    }
    printf("Smallest element is %d",smallest);
    return 0;
}
