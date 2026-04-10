#include <stdio.h>
#include <stdlib.h>

/* 
 * QUESTION: Tree Height and Diameter
 * Height = depth of the tree.
 * Diameter = longest path between any two nodes.
 */

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = val; n->left = n->right = NULL;
    return n;
}

int max(int a, int b) { return (a > b) ? a : b; }

int height(struct Node* node) {
    if (node == NULL) return 0;
    return 1 + max(height(node->left), height(node->right));
}

int diameter(struct Node* root) {
    if (root == NULL) return 0;
    int hL = height(root->left);
    int hR = height(root->right);
    
    int dL = diameter(root->left);
    int dR = diameter(root->right);

    return max(hL + hR + 1, max(dL, dR));
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Height of the tree: %d\n", height(root));
    printf("Diameter of the tree: %d\n", diameter(root));

    return 0;
}
