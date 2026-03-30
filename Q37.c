#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int pq[MAX];
int size = 0;

// Enqueue operation
void enqueue(int val) {
    if (size == MAX) {
        printf("Priority Queue Overflow! Cannot insert %d\n", val);
        return;
    }
    pq[size++] = val;
    printf("%d enqueued.\n", val);
}

// Dequeue operation (remove element with smallest value)
void dequeue() {
    if (size == 0) {
        printf("Priority Queue Underflow! Cannot dequeue.\n");
        return;
    }

    // Find index of smallest element
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }

    printf("%d dequeued (highest priority).\n", pq[minIndex]);

    // Shift elements left
    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}

// Display operation
void display() {
    if (size == 0) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", pq[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    enqueue(30);
    enqueue(10);
    enqueue(20);
    enqueue(5);
    display();

    dequeue();
    display();

    enqueue(15);
    enqueue(2);
    display();

    dequeue();
    dequeue();
    display();

    return 0;
}