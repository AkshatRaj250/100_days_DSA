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

// Find LCA in BST
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    // If both values are smaller, LCA is in left subtree
    if (n1 < root->data && n2 < root->data)
        return findLCA(root->left, n1, n2);

    // If both values are greater, LCA is in right subtree
    if (n1 > root->data && n2 > root->data)
        return findLCA(root->right, n1, n2);

    // Otherwise, root is the LCA
    return root;
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

    int n1 = 20, n2 = 40;
    struct Node* lca = findLCA(root, n1, n2);
    if (lca != NULL)
        printf("LCA of %d and %d is %d\n", n1, n2, lca->data);

    n1 = 20; n2 = 60;
    lca = findLCA(root, n1, n2);
    if (lca != NULL)
        printf("LCA of %d and %d is %d\n", n1, n2, lca->data);

    return 0;
}