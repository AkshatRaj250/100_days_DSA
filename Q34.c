#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure for stack
struct Node {
    int data;
    struct Node* next;
};

// Push operation
void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

// Pop operation
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    struct Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

// Evaluate postfix expression
int evaluatePostfix(char* exp) {
    struct Node* stack = NULL;

    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        // Skip spaces
        if (ch == ' ') continue;

        // If operand, push onto stack
        if (isdigit(ch)) {
            push(&stack, ch - '0');  // convert char to int
        }
        else {
            // Operator: pop two operands
            int val2 = pop(&stack);
            int val1 = pop(&stack);

            switch (ch) {
                case '+': push(&stack, val1 + val2); break;
                case '-': push(&stack, val1 - val2); break;
                case '*': push(&stack, val1 * val2); break;
                case '/': push(&stack, val1 / val2); break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    exit(1);
            }
        }
    }

    // Final result
    return pop(&stack);
}

// Driver code
int main() {
    char exp[] = "23*54*+9-";  // Example postfix expression

    printf("Postfix Expression: %s\n", exp);
    int result = evaluatePostfix(exp);
    printf("Result = %d\n", result);

    return 0;
}