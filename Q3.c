//linear search with compaarison count

#include<stdio.h>

int main()
{
    int n, arr[n], x, i, count = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    printf("Enter the elements of the array: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element you want to search: ");
    scanf("%d", &x);

    for(i = 0; i < n; i++)
    {
        count++;
        if(arr[i] == x)
        {
            printf("Element found at position %d\n", i + 1);
            break;
        }
    }

    if(i == n)
    {
        printf("Element not found in the array\n");
    }

    printf("Number of comparisons made: %d\n", count);

    return 0;
}