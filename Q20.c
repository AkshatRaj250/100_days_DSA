#include <stdio.h>
#include <stdlib.h>

// Hash map node
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

// Simple hash function
int hash(int key, int size) {
    return (key % size + size) % size;
}

// Insert or update in hash map
void insert(Node** table, int size, int key) {
    int idx = hash(key, size);
    Node* curr = table[idx];
    while (curr) {
        if (curr->key == key) {
            curr->value++;
            return;
        }
        curr = curr->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = 1;
    newNode->next = table[idx];
    table[idx] = newNode;
}

// Get frequency of a key
int get(Node** table, int size, int key) {
    int idx = hash(key, size);
    Node* curr = table[idx];
    while (curr) {
        if (curr->key == key) return curr->value;
        curr = curr->next;
    }
    return 0;
}

int countZeroSumSubarrays(int arr[], int n) {
    int size = 10007; // hash table size
    Node** table = (Node**)calloc(size, sizeof(Node*));
    int prefixSum = 0;
    int count = 0;

    // Insert prefix sum = 0 initially
    insert(table, size, 0);

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];
        count += get(table, size, prefixSum);
        insert(table, size, prefixSum);
    }

    return count;
}

int main() {
    int arr[] = {1, -1, 2, -2, 3, -3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Number of zero-sum subarrays: %d\n", countZeroSumSubarrays(arr, n));
    return 0;
}