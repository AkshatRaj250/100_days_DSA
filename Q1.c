#include<stdio.h>

int main()
{
    int n, arr[n], position, x,i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    printf("Enter the elements of the array: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position where you want to insert an element: ");
    scanf("%d", &position);

    printf("Enter the element you want to insert: ");
    scanf("%d", &x);

    for(i = n; i >= position; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[position - 1] = x;
    n++;

    printf("Array after insertion: ");
    for(i = 0; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}