/*
 * Practical_12: Binary Search Tree (BST) of Integers
 * Initial data: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2
 * Operations: Create, Inorder/Preorder/Postorder traversal, Search, Delete
 */

#include <stdio.h>
#include <stdlib.h>

/* ─────────────────────────── Node Definition ───────────────────────────── */

typedef struct BSTNode {
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

BSTNode *root = NULL;

/* ─────────────────────────── Core Operations ───────────────────────────── */

/* Create / Insert */
BSTNode *newNode(int val)
{
    BSTNode *n = (BSTNode *)malloc(sizeof(BSTNode));
    if (!n) { printf("Memory allocation failed!\n"); exit(1); }
    n->data = val; n->left = n->right = NULL;
    return n;
}

BSTNode *insert(BSTNode *node, int val)
{
    if (!node) return newNode(val);
    if (val < node->data)       node->left  = insert(node->left,  val);
    else if (val > node->data)  node->right = insert(node->right, val);
    else printf("  [Duplicate %d ignored]\n", val);  /* BST ignores duplicates */
    return node;
}

/* ─────────────────────────── Traversals ────────────────────────────────── */

void inorder(BSTNode *node)
{
    if (!node) return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

void preorder(BSTNode *node)
{
    if (!node) return;
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

void postorder(BSTNode *node)
{
    if (!node) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

/* ─────────────────────────── Search ────────────────────────────────────── */

BSTNode *search(BSTNode *node, int key, int *depth)
{
    if (!node) return NULL;
    (*depth)++;
    if (key == node->data) return node;
    if (key < node->data)  return search(node->left,  key, depth);
    return                        search(node->right, key, depth);
}

/* ─────────────────────────── Delete ────────────────────────────────────── */

/* Find in-order successor (smallest in right subtree) */
BSTNode *minNode(BSTNode *node)
{
    while (node->left) node = node->left;
    return node;
}

BSTNode *deleteNode(BSTNode *node, int key)
{
    if (!node) { printf("  Key %d not found in BST.\n", key); return NULL; }

    if (key < node->data)
        node->left  = deleteNode(node->left,  key);
    else if (key > node->data)
        node->right = deleteNode(node->right, key);
    else {
        /* Case 1: leaf node */
        if (!node->left && !node->right) {
            printf("  Deleted leaf node %d.\n", key);
            free(node); return NULL;
        }
        /* Case 2: one child */
        if (!node->left) {
            BSTNode *tmp = node->right;
            printf("  Deleted node %d (had only right child).\n", key);
            free(node); return tmp;
        }
        if (!node->right) {
            BSTNode *tmp = node->left;
            printf("  Deleted node %d (had only left child).\n", key);
            free(node); return tmp;
        }
        /* Case 3: two children – replace with in-order successor */
        BSTNode *succ = minNode(node->right);
        printf("  Deleted node %d – replaced with in-order successor %d.\n",
               key, succ->data);
        node->data  = succ->data;
        node->right = deleteNode(node->right, succ->data);
    }
    return node;
}

/* ─────────────────────────── Pretty Print ──────────────────────────────── */

void printTree(BSTNode *node, int space, int level)
{
    if (!node) return;
    space += 5;
    printTree(node->right, space, level + 1);
    printf("\n");
    for (int i = 5; i < space; i++) printf(" ");
    printf("%d\n", node->data);
    printTree(node->left, space, level + 1);
}

/* ─────────────────────────── Main ─────────────────────────────────────── */

int main(void)
{
    int choice, val;

    printf("\n═══════════════════════════════════════════════════════\n");
    printf("   Practical_12 : Binary Search Tree (BST)            \n");
    printf("═══════════════════════════════════════════════════════\n");

    do {
        printf("\n┌──────────────────────────────────────────────────────┐\n");
        printf("│                    MAIN MENU                         │\n");
        printf("├──────────────────────────────────────────────────────┤\n");
        printf("│  1. Create BST with 6,9,5,2,8,15,24,14,7,8,5,2      │\n");
        printf("│  2. Insert a new element                             │\n");
        printf("│  3. Inorder   Traversal  (Left-Root-Right)           │\n");
        printf("│  4. Preorder  Traversal  (Root-Left-Right)           │\n");
        printf("│  5. Postorder Traversal  (Left-Right-Root)           │\n");
        printf("│  6. Search for a key                                 │\n");
        printf("│  7. Delete an element                                │\n");
        printf("│  8. Display BST structure (rotated)                  │\n");
        printf("│  0. Exit                                             │\n");
        printf("└──────────────────────────────────────────────────────┘\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int data[] = {6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2};
                int len = sizeof(data) / sizeof(data[0]);
                root = NULL;
                printf("  Inserting: ");
                for (int i = 0; i < len; i++) {
                    printf("%d ", data[i]);
                    root = insert(root, data[i]);
                }
                printf("\n  BST created.\n");
                printf("  Inorder (should be sorted): ");
                inorder(root); printf("\n");
                break;
            }
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                printf("  %d inserted.\n", val);
                break;
            case 3:
                printf("  Inorder   : "); inorder(root);   printf("\n"); break;
            case 4:
                printf("  Preorder  : "); preorder(root);  printf("\n"); break;
            case 5:
                printf("  Postorder : "); postorder(root); printf("\n"); break;
            case 6: {
                printf("Enter key to search: ");
                scanf("%d", &val);
                int depth = 0;
                BSTNode *found = search(root, val, &depth);
                if (found)
                    printf("  Element %d FOUND at depth %d.\n", val, depth);
                else
                    printf("  Element %d NOT found in BST.\n", val);
                break;
            }
            case 7:
                printf("Enter element to delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                printf("  Inorder after deletion: ");
                inorder(root); printf("\n");
                break;
            case 8:
                printf("\n  BST Structure (rotated 90°, read right→left = top→bottom):\n");
                printTree(root, 0, 0);
                printf("\n");
                break;
            case 0: printf("Exiting program. Goodbye!\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
