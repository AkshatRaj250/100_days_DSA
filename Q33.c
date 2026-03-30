#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

// Stack for operators
char stack[MAX];
int top = -1;

// Push operation
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = c;
}

// Pop operation
char pop() {
    if (top == -1) {
        return -1;
    }
    return stack[top--];
}

// Peek top of stack
char peek() {
    if (top == -1) return -1;
    return stack[top];
}

// Operator precedence
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Convert infix to postfix
void infixToPostfix(char* infix) {
    char postfix[MAX];
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // If operand, add to postfix
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        // If '(', push to stack
        else if (ch == '(') {
            push(ch);
        }
        // If ')', pop until '('
        else if (ch == ')') {
            while (peek() != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        // Operator
        else {
            while (peek() != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (peek() != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
    printf("Postfix Expression: %s\n", postfix);
}

// Driver code
int main() {
    char infix[] = "A+(B*C-(D/E^F)*G)*H";
    printf("Infix Expression: %s\n", infix);
    infixToPostfix(infix);
    return 0;
}