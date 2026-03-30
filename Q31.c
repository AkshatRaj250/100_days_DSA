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

// Display operation
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    push(10);
    push(20);
    push(30);
    display();

    pop();
    display();

    push(40);
    push(50);
    push(60); // This will show overflow
    display();

    return 0;
}