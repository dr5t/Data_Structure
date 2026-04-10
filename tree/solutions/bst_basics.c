#include <stdio.h>
#include <stdlib.h>

/* 
 * QUESTION: Binary Search Tree (BST) Basics
 * Implement insertion and search in a BST.
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

// Insert a value into BST
struct Node* insert(struct Node* node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    return node;
}

// Search for a value in BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (root->data < key)
        return search(root->right, key);

    return search(root->left, key);
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Find the node with the minimum value (successor finding)
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Find the node with the maximum value
struct Node* maxValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->right != NULL)
        current = current->right;
    return current;
}

// Delete a value from BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;

    // Search for the node to be deleted
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // CASE 1 & 2: Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // CASE 3: Node with two children
        // Get the inorder successor (smallest in the right subtree)
        struct Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Original In-order traversal: ");
    inorder(root);
    printf("\n");

    printf("Min value in BST: %d\n", minValueNode(root)->data);
    printf("Max value in BST: %d\n", maxValueNode(root)->data);

    printf("\nDeleting 20 (Leaf)...\n");
    root = deleteNode(root, 20);
    inorder(root); printf("\n");

    printf("Deleting 30 (One child)...\n");
    root = deleteNode(root, 30);
    inorder(root); printf("\n");

    printf("Deleting 50 (Two children - Root)...\n");
    root = deleteNode(root, 50);
    inorder(root); printf("\n");

    return 0;
}
