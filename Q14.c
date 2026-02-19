#include <stdio.h>
#include <stdbool.h>

// Function to check if a matrix is identity
bool isIdentityMatrix(int n, int matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j && matrix[i][j] != 1) {
                return false; // diagonal element not 1
            }
            else if (i != j && matrix[i][j] != 0) {
                return false; // non-diagonal element not 0
            }
        }
    }
    return true;
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

    // Check identity matrix
    if (isIdentityMatrix(n, matrix)) {
        printf("The matrix is an Identity Matrix.\n");
    } else {
        printf("The matrix is NOT an Identity Matrix.\n");
    }

    return 0;
}