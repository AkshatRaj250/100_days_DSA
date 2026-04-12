#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue node for building tree
struct QNode {
    struct Node* treeNode;
    struct QNode* next;
};

// Queue structure
struct Queue {
    struct QNode* front;
    struct QNode* rear;
};

// Create new tree node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue operations
void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

void enqueue(struct Queue* q, struct Node* node) {
    struct QNode* newQNode = (struct QNode*)malloc(sizeof(struct QNode));
    newQNode->treeNode = node;
    newQNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newQNode;
    } else {
        q->rear->next = newQNode;
        q->rear = newQNode;
    }
}

struct Node* dequeue(struct Queue* q) {
    if (q->front == NULL) return NULL;
    struct QNode* temp = q->front;
    struct Node* node = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return node;
}

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Build tree from level-order array
struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* root = createNode(arr[0]);
    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    int i = 1;
    while (i < n) {
        struct Node* parent = dequeue(&q);

        // Left child
        if (i < n) {
            parent->left = createNode(arr[i++]);
            enqueue(&q, parent->left);
        }

        // Right child
        if (i < n) {
            parent->right = createNode(arr[i++]);
            enqueue(&q, parent->right);
        }
    }
    return root;
}

// Inorder traversal to verify tree
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Driver code
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node* root = buildTree(arr, n);

    printf("Inorder Traversal of constructed tree:\n");
    inorder(root);
    printf("\n");

    return 0;
}