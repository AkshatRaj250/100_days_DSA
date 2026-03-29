#include <stdio.h>
#include <stdlib.h>

// Node structure
struct ListNode {
    int val;
    struct ListNode* next;
};

// Utility function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to rotate list right by k places
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;

    // Step 1: Find length and tail
    int length = 1;
    struct ListNode* tail = head;
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    // Step 2: Normalize k
    k = k % length;
    if (k == 0) return head;

    // Step 3: Find new tail (length - k - 1)th node
    int stepsToNewTail = length - k;
    struct ListNode* newTail = head;
    for (int i = 1; i < stepsToNewTail; i++) {
        newTail = newTail->next;
    }

    // Step 4: Set new head
    struct ListNode* newHead = newTail->next;

    // Step 5: Rotate
    newTail->next = NULL;
    tail->next = head;

    return newHead;
}

// Utility function to print list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// Driver code
int main() {
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original List:\n");
    printList(head);

    int k = 2;
    head = rotateRight(head, k);

    printf("List after rotating by %d places:\n", k);
    printList(head);

    return 0;
}