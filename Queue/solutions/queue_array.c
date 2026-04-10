#include <stdio.h>
#include <stdbool.h>

/* 
 * QUESTION: Array-based Queue
 * Implement a simple FIFO queue using an array.
 */

#define MAX 5

struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

void init(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

bool isFull(struct Queue* q) {
    return q->rear == MAX - 1;
}

bool isEmpty(struct Queue* q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueue(struct Queue* q, int val) {
    if (isFull(q)) {
        printf("Queue Full!\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->arr[++(q->rear)] = val;
    printf("Enqueued: %d\n", val);
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Empty!\n");
        return -1;
    }
    return q->arr[(q->front)++];
}

int main() {
    struct Queue q;
    init(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    return 0;
}
