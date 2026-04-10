#include <stdio.h>
#include <stdlib.h>

/* 
 * QUESTION: Binary Tree Traversals
 * Implement In-order, Pre-order, and Post-order traversals recursively.
 */

struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// In-order: Left -> Root -> Right
void printInorder(struct Node* node) {
    if (node == NULL) return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

// Pre-order: Root -> Left -> Right
void printPreorder(struct Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

// Post-order: Left -> Right -> Root
void printPostorder(struct Node* node) {
    if (node == NULL) return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
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

    printf("Pre-order: "); printPreorder(root); printf("\n");
    printf("In-order: "); printInorder(root); printf("\n");
    printf("Post-order: "); printPostorder(root); printf("\n");

    return 0;
}
