#include <stdio.h>

int sumPrimaryDiagonal(int n, int matrix[n][n]) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][i];  // add diagonal element
    }
    return sum;
}

int main() {
    int n;

    // Input size
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    int matrix[n][n];

    // Input matrix elements
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate and print sum of primary diagonal
    int sum = sumPrimaryDiagonal(n, matrix);
    printf("Sum of primary diagonal elements = %d\n", sum);

    return 0;
}