#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * QUESTION: 
 * 1. Check if a Binary Tree is a valid BST.
 * 2. Check if a Binary Tree is Height-Balanced.
 */

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// 1. Is BST Check
// Logic: Every node must be between [min, max] range.
int isBST(struct Node* root, int min, int max) {
    if (root == NULL) return 1;
    if (root->data < min || root->data > max) return 0;
    return isBST(root->left, min, root->data - 1) && 
           isBST(root->right, root->data + 1, max);
}

// 2. Balanced Check Helpers
int height(struct Node* node) {
    if (node == NULL) return 0;
    int lh = height(node->left);
    int rh = height(node->right);
    return 1 + (lh > rh ? lh : rh);
}

int isBalanced(struct Node* root) {
    if (root == NULL) return 1;

    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;

    return 0;
}

int main() {
    /* 
          10
         /  \
        5    20
            /  \
           15   25
    */
    struct Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(25);

    if (isBST(root, INT_MIN, INT_MAX)) printf("Tree is a valid BST.\n");
    else printf("Tree is NOT a valid BST.\n");

    if (isBalanced(root)) printf("Tree is Height-Balanced.\n");
    else printf("Tree is NOT Height-Balanced.\n");

    return 0;
}
