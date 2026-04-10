#include <stdio.h>
#include <stdlib.h>

/* 
 * QUESTION: Linked List-based Queue
 * Implement a FIFO queue using a linked list.
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
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
    printf("Enqueued (LL): %d\n", val);
}

int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue Underflow!\n");
        return -1;
    }

    struct Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) q->rear = NULL;

    free(temp);
    return data;
}

int main() {
    struct Queue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    return 0;
}
