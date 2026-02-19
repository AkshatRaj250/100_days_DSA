#include <stdio.h>

int main() {
    int n;

    // Input size of array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Frequency array (initialized to 0)
    int freq[n];
    for (int i = 0; i < n; i++) {
        freq[i] = -1; // -1 means not counted yet
    }

    // Count frequencies
    for (int i = 0; i < n; i++) {
        if (freq[i] == -1) { // not yet counted
            int count = 1;
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                    freq[j] = 0; // mark as counted
                }
            }
            freq[i] = count;
        }
    }

    // Print frequencies
    printf("Frequency of each distinct element:\n");
    for (int i = 0; i < n; i++) {
        if (freq[i] != 0) {
            printf("%d occurs %d times\n", arr[i], freq[i]);
        }
    }

    return 0;
}