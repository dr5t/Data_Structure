#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * QUESTION: Tree Variations
 * Implement logic to check if a binary tree is:
 * 1. Full (Every node has 0 or 2 children)
 * 2. Complete (All levels filled except possibly the last)
 * 3. Perfect (All leaf nodes are at same level)
 */

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int k) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = k;
    node->left = node->right = NULL;
    return node;
}

// Full Binary Tree Check
bool isFull(struct Node* root) {
    if (root == NULL) return true;
    if (root->left == NULL && root->right == NULL) return true;
    if (root->left && root->right)
        return isFull(root->left) && isFull(root->right);
    return false;
}

// Perfect Binary Tree Helper (checks depth)
int findADepth(struct Node* node) {
    int d = 0;
    while (node != NULL) {
        d++;
        node = node->left;
    }
    return d;
}

bool isPerfect(struct Node* root, int d, int level) {
    if (root == NULL) return true;
    if (root->left == NULL && root->right == NULL) return (d == level + 1);
    if (root->left == NULL || root->right == NULL) return false;
    return isPerfect(root->left, d, level + 1) && 
           isPerfect(root->right, d, level + 1);
}

// Complete Binary Tree Check (Count approach)
int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return (1 + countNodes(root->left) + countNodes(root->right));
}

bool isComplete(struct Node* root, int index, int number_nodes) {
    if (root == NULL) return true;
    if (index >= number_nodes) return false;
    return isComplete(root->left, 2 * index + 1, number_nodes) &&
           isComplete(root->right, 2 * index + 2, number_nodes);
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Full Binary Tree: %s\n", isFull(root) ? "YES" : "NO");
    
    int depth = findADepth(root);
    printf("Perfect Binary Tree: %s\n", isPerfect(root, depth, 0) ? "YES" : "NO");
    
    int node_count = countNodes(root);
    printf("Complete Binary Tree: %s\n", isComplete(root, 0, node_count) ? "YES" : "NO");

    return 0;
}
