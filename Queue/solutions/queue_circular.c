#include <stdio.h>

/* 
 * QUESTION: Circular Queue
 * Efficient use of array space by wrapping around indices.
 */

#define MAX 5

struct CircularQueue {
    int arr[MAX];
    int front, rear;
};

void init(struct CircularQueue* q) { q->front = q->rear = -1; }

void enqueue(struct CircularQueue* q, int val) {
    if ((q->front == 0 && q->rear == MAX - 1) || (q->rear == (q->front - 1) % (MAX - 1))) {
        printf("Queue Full!\n");
        return;
    }
    if (q->front == -1) q->front = q->rear = 0;
    else if (q->rear == MAX - 1 && q->front != 0) q->rear = 0;
    else q->rear++;

    q->arr[q->rear] = val;
    printf("Enqueued: %d\n", val);
}

int dequeue(struct CircularQueue* q) {
    if (q->front == -1) { printf("Queue Empty!\n"); return -1; }
    int data = q->arr[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else if (q->front == MAX - 1) q->front = 0;
    else q->front++;
    return data;
}

int main() {
    struct CircularQueue q; init(&q);
    enqueue(&q, 1); enqueue(&q, 2); enqueue(&q, 3); enqueue(&q, 4); enqueue(&q, 5);
    printf("Dequeued: %d\n", dequeue(&q));
    enqueue(&q, 6); // Should wrap around to index 0
    return 0;
}
