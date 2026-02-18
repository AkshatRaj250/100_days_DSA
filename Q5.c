#include <stdio.h>

void mergeLogs(int log1[], int size1, int log2[], int size2, int merged[]) {
    int i = 0, j = 0, k = 0;

    // Merge until one log is exhausted
    while (i < size1 && j < size2) {
        if (log1[i] <= log2[j]) {
            merged[k++] = log1[i++];
        } else {
            merged[k++] = log2[j++];
        }
    }

    // Copy remaining elements from log1
    while (i < size1) {
        merged[k++] = log1[i++];
    }

    // Copy remaining elements from log2
    while (j < size2) {
        merged[k++] = log2[j++];
    }
}

int main() {
    // Example logs (already sorted)
    int log1[] = {1, 4, 7, 10};
    int log2[] = {2, 3, 8, 12, 15};

    int size1 = sizeof(log1) / sizeof(log1[0]);
    int size2 = sizeof(log2) / sizeof(log2[0]);
    int merged[size1 + size2];

    mergeLogs(log1, size1, log2, size2, merged);

    printf("Merged chronological log:\n");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}