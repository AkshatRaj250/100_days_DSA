#include <stdio.h>
#include <stdlib.h>

// Node structure for Queue
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Stack structure (linked list)
struct Stack {
    struct Node* top;
};

// Initialize Queue
void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

// Initialize Stack
void initStack(struct Stack* s) {
    s->top = NULL;
}

// Enqueue operation
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
}

// Dequeue operation
int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue Underflow!\n");
        return -1;
    }
    struct Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return val;
}

// Push onto stack
void push(struct Stack* s, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = s->top;
    s->top = newNode;
}

// Pop from stack
int pop(struct Stack* s) {
    if (s->top == NULL) {
        printf("Stack Underflow!\n");
        return -1;
    }
    struct Node* temp = s->top;
    int val = temp->data;
    s->top = s->top->next;
    free(temp);
    return val;
}

// Display Queue
void displayQueue(struct Queue* q) {
    struct Node* temp = q->front;
    printf("Queue: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Reverse Queue using Stack
void reverseQueue(struct Queue* q) {
    struct Stack s;
    initStack(&s);

    // Step 1: Move all elements from queue to stack
    while (q->front != NULL) {
        push(&s, dequeue(q));
    }

    // Step 2: Move all elements back from stack to queue
    while (s.top != NULL) {
        enqueue(q, pop(&s));
    }
}

// Driver code
int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    printf("Original ");
    displayQueue(&q);

    reverseQueue(&q);

    printf("Reversed ");
    displayQueue(&q);

    return 0;
}