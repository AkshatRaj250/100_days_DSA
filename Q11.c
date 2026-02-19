#include<stdio.h>

int main(){
    int rows, col;

    printf("Enter number of rows: ");
    scanf("%d",&rows);
    printf("Enter number of columns: ");
    scanf("%d",&col);

    int a[rows][col], b[rows][col], sum[rows][col];

    //for first matrix
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d",&a[i][j]);
        }
        
    }
    
    //for second matrix
    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d",&b[i][j]);
        }
        
    }

    //for sum
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
        
    }

    //for display
    printf("Sum of the matrices:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d\t", sum[i][j]);
        }

        printf("\n");  
    }

    return 0;
}