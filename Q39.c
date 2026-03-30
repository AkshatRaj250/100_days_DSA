#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Swap utility
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up (bubble up)
void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify down (bubble down)
void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert element
void insert(int val) {
    if (size == MAX) {
        printf("Heap Overflow! Cannot insert %d\n", val);
        return;
    }
    heap[size] = val;
    size++;
    heapifyUp(size - 1);
    printf("%d inserted.\n", val);
}

// Extract minimum element
int extractMin() {
    if (size <= 0) {
        printf("Heap Underflow! Cannot extract.\n");
        return -1;
    }
    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return root;
}

// Display heap
void display() {
    if (size == 0) {
        printf("Heap is empty.\n");
        return;
    }
    printf("Heap elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    insert(20);
    insert(15);
    insert(30);
    insert(5);
    insert(10);

    display();

    printf("Extracted Min: %d\n", extractMin());
    display();

    printf("Extracted Min: %d\n", extractMin());
    display();

    return 0;
}