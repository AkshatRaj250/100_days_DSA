#include <stdio.h>

int removeDuplicates(int* nums, int n) {
    if (n == 0) return 0;

    int j = 1; // index for placing unique elements

    for (int i = 1; i < n; i++) {
        if (nums[i] != nums[j - 1]) {
            nums[j] = nums[i];
            j++;
        }
    }

    return j; // number of unique elements
}

int main() {
    int nums[] = {1, 1, 2, 2, 3, 4, 4, 5};
    int n = sizeof(nums) / sizeof(nums[0]);

    int newLength = removeDuplicates(nums, n);

    printf("Unique elements: ");
    for (int i = 0; i < newLength; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}