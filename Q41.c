#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure with front and rear pointers
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Initialize queue
void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

// Enqueue operation (insert at rear)
void enqueue(struct Queue* q, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("%d enqueued.\n", val);
}

// Dequeue operation (remove from front)
void dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue Underflow! Cannot dequeue.\n");
        return;
    }

    struct Node* temp = q->front;
    printf("%d dequeued.\n", temp->data);
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL; // Queue becomes empty
    }

    free(temp);
}

// Display queue
void display(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = q->front;
    printf("Queue elements: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Driver code
int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);

    dequeue(&q);
    display(&q);

    enqueue(&q, 40);
    display(&q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q); // Underflow case
    display(&q);

    return 0;
}