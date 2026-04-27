#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// BST Insert
struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return createNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

// BST Search
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root; // found or reached NULL
    }

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Driver code
int main() {
    struct Node* root = NULL;

    // Build BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    int key = 40;
    struct Node* result = search(root, key);

    if (result != NULL)
        printf("Key %d found in BST.\n", key);
    else
        printf("Key %d not found in BST.\n", key);

    key = 25;
    result = search(root, key);

    if (result != NULL)
        printf("Key %d found in BST.\n", key);
    else
        printf("Key %d not found in BST.\n", key);

    return 0;
}