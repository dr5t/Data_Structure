#include <stdio.h>
#include <stdlib.h>

/* 
 * QUESTION: Lowest Common Ancestor (LCA)
 * Find the lowest shared ancestor of two nodes in a Binary Tree.
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

struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->data == n1 || root->data == n2) return root;

    struct Node* leftLCA = findLCA(root->left, n1, n2);
    struct Node* rightLCA = findLCA(root->right, n1, n2);

    if (leftLCA && rightLCA) return root;
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    struct Node* lca = findLCA(root, 4, 5);
    if(lca) printf("LCA of 4 and 5 is: %d\n", lca->data);

    lca = findLCA(root, 4, 6);
    if(lca) printf("LCA of 4 and 6 is: %d\n", lca->data);

    return 0;
}
