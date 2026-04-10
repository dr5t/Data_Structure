#include <stdio.h>
#include <stdlib.h>

/**
 * QUESTION: Level Order Traversal (BFS) of a Binary Tree.
 * 
 * ALGORITHM:
 * 1. Create an empty queue.
 * 2. Enqueue the root node.
 * 3. While queue is not empty:
 *    a. Dequeue a node and print it.
 *    b. Enqueue its left child (if not NULL).
 *    c. Enqueue its right child (if not NULL).
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

// Simple Array-based Queue for Tree Nodes
struct Queue {
    int front, rear;
    int size;
    struct Node** array;
};

struct Queue* createQueue(int size) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->size = size;
    queue->front = queue->rear = -1;
    queue->array = (struct Node**)malloc(queue->size * sizeof(struct Node*));
    return queue;
}

int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

void enqueue(struct Queue* queue, struct Node* node) {
    if (queue->rear == queue->size - 1) return;
    if (isEmpty(queue)) queue->front = 0;
    queue->array[++queue->rear] = node;
}

struct Node* dequeue(struct Queue* queue) {
    if (isEmpty(queue)) return NULL;
    struct Node* item = queue->array[queue->front];
    if (queue->front >= queue->rear) queue->front = queue->rear = -1;
    else queue->front++;
    return item;
}

void levelOrder(struct Node* root) {
    if (root == NULL) return;

    struct Queue* queue = createQueue(100);
    enqueue(queue, root);

    while (!isEmpty(queue)) {
        struct Node* curr = dequeue(queue);
        printf("%d ", curr->data);

        if (curr->left) enqueue(queue, curr->left);
        if (curr->right) enqueue(queue, curr->right);
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

    printf("Level Order Traversal: ");
    levelOrder(root);
    printf("\n");

    return 0;
}
