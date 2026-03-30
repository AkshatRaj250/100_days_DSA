#include <stdio.h>
#include <stdlib.h>

#define MAX 5   // Maximum size of stack

int stack[MAX];
int top = -1;

// Push operation
void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", val);
        return;
    }
    stack[++top] = val;
    printf("%d pushed onto stack.\n", val);
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop.\n");
        return;
    }
    printf("%d popped from stack.\n", stack[top--]);
}

// Display stack contents
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// Driver code to verify stack operations
int main() {
    // Push elements
    push(10);
    push(20);
    push(30);
    display();

    // Pop one element
    pop();
    display();

    // Push more elements
    push(40);
    push(50);
    push(60); // This will cause overflow
    display();

    // Pop all elements
    pop();
    pop();
    pop();
    pop();
    pop(); // This will cause underflow
    display();

    return 0;
}