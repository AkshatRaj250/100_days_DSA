//delete an element from an array

#include<stdio.h>

int main()
{
    int n, arr[n], position, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    printf("Enter the elements of the array: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position where you want to delete an element: ");
    scanf("%d", &position);

    for(i = position - 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    
    n--;

    printf("Array after deletion: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}