#include <stdio.h>

// Recursive function to compute a^b
int power(int a, int b) {
    if (b == 0) {
        return 1;  // Base case: anything raised to 0 is 1
    } else {
        return a * power(a, b - 1);  // Recursive case
    }
}

int main() {
    int a = 2, b = 5;  // Example: compute 2^5
    printf("%d^%d = %d\n", a, b, power(a, b));
    return 0;
}