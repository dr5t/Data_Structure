#include <stdio.h>

/* 
 * QUESTION: Implement Stack using Queues
 * Push: O(1)
 * Pop: O(n)
 */

#define MAX 50

struct Queue {
    int arr[MAX];
    int front, rear;
};

void enqueue(struct Queue* q, int x) {
    q->arr[++(q->rear)] = x;
}

int dequeue(struct Queue* q) {
    return q->arr[(q->front)++];
}

struct Stack {
    struct Queue q1, q2;
};

void push(struct Stack* s, int x) {
    enqueue(&s->q1, x);
    printf("Pushed: %d\n", x);
}

int pop(struct Stack* s) {
    if (s->q1.front > s->q1.rear) return -1;

    // Shift all but one to q2
    while (s->q1.rear > s->q1.front) {
        enqueue(&s->q2, dequeue(&s->q1));
    }

    // This is the last element (LIFO)
    int popped = dequeue(&s->q1);

    // Swap q1 and q2
    struct Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;

    return popped;
}

int main() {
    struct Stack s;
    s.q1.front = s.q2.front = 0;
    s.q1.rear = s.q2.rear = -1;

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);

    printf("Popped: %d\n", pop(&s)); // Should be 3
    printf("Popped: %d\n", pop(&s)); // Should be 2

    return 0;
}
