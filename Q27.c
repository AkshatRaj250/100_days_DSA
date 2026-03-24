#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Utility function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to count length of a linked list
int getLength(struct Node* head) {
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}

// Function to find intersection point
struct Node* getIntersectionNode(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Advance longer list by 'diff'
    if (len1 > len2) {
        while (diff--) head1 = head1->next;
    } else {
        while (diff--) head2 = head2->next;
    }

    // Traverse both lists together
    while (head1 && head2) {
        if (head1 == head2) return head1;  // Intersection found
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL; // No intersection
}

// Driver code
int main() {
    // Create two linked lists that intersect
    struct Node* common = createNode(15);
    common->next = createNode(30);

    // First list: 10 -> 20 -> 15 -> 30
    struct Node* head1 = createNode(10);
    head1->next = createNode(20);
    head1->next->next = common;

    // Second list: 5 -> 15 -> 30
    struct Node* head2 = createNode(5);
    head2->next = common;

    struct Node* intersection = getIntersectionNode(head1, head2);

    if (intersection)
        printf("Intersection point is: %d\n", intersection->data);
    else
        printf("No intersection found.\n");

    return 0;
}