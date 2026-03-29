#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial
struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

// Utility function to create a new node
struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// Insert term at end
struct Node* insertTerm(struct Node* head, int coeff, int pow) {
    struct Node* newNode = createNode(coeff, pow);

    if (head == NULL) return newNode;

    struct Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Traverse and display polynomial
void displayPolynomial(struct Node* head) {
    if (!head) {
        printf("Polynomial is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp) {
        printf("%dx^%d", temp->coeff, temp->pow);
        temp = temp->next;
        if (temp) printf(" + ");
    }
    printf("\n");
}

// Driver code
int main() {
    struct Node* poly = NULL;

    // Example polynomial: 5x^2 + 4x^1 + 2
    poly = insertTerm(poly, 5, 2);
    poly = insertTerm(poly, 4, 1);
    poly = insertTerm(poly, 2, 0);

    printf("Polynomial: ");
    displayPolynomial(poly);

    return 0;
}