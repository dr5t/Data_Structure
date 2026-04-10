#include <stdio.h>
#include <stdlib.h>

/* 
 * QUESTION: Queue using Linked List
 * Implementation using both 'front' and 'rear' pointers to achieve O(1) performance.
 */

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

void init(struct Queue* q) {
    q->front = q->rear = NULL;
}

void enqueue(struct Queue* q, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        printf("Enqueued: %d\n", val);
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
    printf("Enqueued: %d\n", val);
}

int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue Underflow!\n");
        return -1;
    }

    struct Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;

    // If front becomes NULL, then rear also should be NULL
    if (q->front == NULL) q->rear = NULL;

    free(temp);
    return val;
}

int main() {
    struct Queue q;
    init(&q);

    enqueue(&q, 100);
    enqueue(&q, 200);
    enqueue(&q, 300);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    return 0;
}
