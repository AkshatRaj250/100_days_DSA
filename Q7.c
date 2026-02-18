#include <stdio.h>

// Recursive function to compute Fibonacci numbers
int fib(int n) {
    if (n == 0) {
        return 0;  // Base case
    } else if (n == 1) {
        return 1;  // Base case
    } else {
        return fib(n - 1) + fib(n - 2);  // Recursive case
    }
}

int main() {
    int n = 10;  // Example: compute the 10th Fibonacci number
    printf("fib(%d) = %d\n", n, fib(n));
    return 0;
}