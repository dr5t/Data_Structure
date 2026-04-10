#include <stdio.h>
#include <stdlib.h>

/**
 * QUESTION: 
 * 1. Count Total Nodes, Leaf Nodes, and Non-Leaf Nodes.
 * 2. Convert a Binary Tree to its Mirror Image.
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

// 1. Total Nodes
int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// 2. Leaf Nodes (No children)
int countLeafNodes(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// 3. Non-Leaf Nodes
int countNonLeafNodes(struct Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return 0;
    return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
}

// 4. Mirror of a Tree
void mirror(struct Node* node) {
    if (node == NULL) return;
    
    // Recurse left and right
    mirror(node->left);
    mirror(node->right);

    // Swap pointers
    struct Node* temp = node->left;
    node->left = node->right;
    node->right = temp;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    /* 
          1
         / \
        2   3
       / \
      4   5
    */
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Total Nodes: %d\n", countNodes(root));
    printf("Leaf Nodes: %d\n", countLeafNodes(root));
    printf("Non-Leaf Nodes: %d\n", countNonLeafNodes(root));

    printf("\nOriginal Inorder: "); inorder(root); printf("\n");
    mirror(root);
    printf("Mirrored Inorder: "); inorder(root); printf("\n");

    return 0;
}
