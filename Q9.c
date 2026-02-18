#include <stdio.h>
#include <string.h>

// Recursive function to print string in reverse
void mirror(char str[], int index) {
    if (index < 0) {
        return;  // Base case: stop when index goes below 0
    }
    printf("%c", str[index]);  // Print current character
    mirror(str, index - 1);    // Recursive call with previous index
}

int main() {
    char codeName[] = "SECRET";  // Example code name
    int length = strlen(codeName);

    printf("Original: %s\n", codeName);
    printf("Mirror: ");
    mirror(codeName, length - 1);  // Start from last character
    printf("\n");

    return 0;
}