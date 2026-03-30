#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Deque structure
struct Deque {
    struct Node* front;
    struct Node* rear;
    int size;
};

// Initialize deque
void initDeque(struct Deque* dq) {
    dq->front = dq->rear = NULL;
    dq->size = 0;
}

// Push front
void push_front(struct Deque* dq, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = dq->front;
    newNode->prev = NULL;

    if (dq->front == NULL) {
        dq->front = dq->rear = newNode;
    } else {
        dq->front->prev = newNode;
        dq->front = newNode;
    }
    dq->size++;
    printf("%d pushed at front.\n", val);
}

// Push back
void push_back(struct Deque* dq, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = dq->rear;

    if (dq->rear == NULL) {
        dq->front = dq->rear = newNode;
    } else {
        dq->rear->next = newNode;
        dq->rear = newNode;
    }
    dq->size++;
    printf("%d pushed at rear.\n", val);
}

// Pop front
void pop_front(struct Deque* dq) {
    if (dq->front == NULL) {
        printf("Deque Underflow! Cannot pop front.\n");
        return;
    }
    struct Node* temp = dq->front;
    printf("%d popped from front.\n", temp->data);
    dq->front = dq->front->next;
    if (dq->front) dq->front->prev = NULL;
    else dq->rear = NULL;
    free(temp);
    dq->size--;
}

// Pop back
void pop_back(struct Deque* dq) {
    if (dq->rear == NULL) {
        printf("Deque Underflow! Cannot pop back.\n");
        return;
    }
    struct Node* temp = dq->rear;
    printf("%d popped from rear.\n", temp->data);
    dq->rear = dq->rear->prev;
    if (dq->rear) dq->rear->next = NULL;
    else dq->front = NULL;
    free(temp);
    dq->size--;
}

// Front element
int front(struct Deque* dq) {
    if (dq->front == NULL) {
        printf("Deque is empty.\n");
        return -1;
    }
    return dq->front->data;
}

// Rear element
int back(struct Deque* dq) {
    if (dq->rear == NULL) {
        printf("Deque is empty.\n");
        return -1;
    }
    return dq->rear->data;
}

// Check empty
int empty(struct Deque* dq) {
    return dq->size == 0;
}

// Size
int size(struct Deque* dq) {
    return dq->size;
}

// Display deque
void display(struct Deque* dq) {
    if (dq->front == NULL) {
        printf("Deque is empty.\n");
        return;
    }
    struct Node* temp = dq->front;
    printf("Deque elements: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Driver code
int main() {
    struct Deque dq;
    initDeque(&dq);

    push_back(&dq, 10);
    push_front(&dq, 20);
    push_back(&dq, 30);
    display(&dq);

    pop_front(&dq);
    display(&dq);

    pop_back(&dq);
    display(&dq);

    printf("Front element: %d\n", front(&dq));
    printf("Rear element: %d\n", back(&dq));
    printf("Size: %d\n", size(&dq));
    printf("Empty: %s\n", empty(&dq) ? "Yes" : "No");

    return 0;
}