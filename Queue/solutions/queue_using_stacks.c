#include <stdio.h>

/* 
 * QUESTION: Implement Queue using Stacks
 * Simulate FIFO behavior using two stacks.
 */

#define MAX 100

struct Stack { int arr[MAX], top; };
void push(struct Stack* s, int x) { s->arr[++(s->top)] = x; }
int pop(struct Stack* s) { return s->arr[(s->top)--]; }

struct Queue { struct Stack s1, s2; };

void enqueue(struct Queue* q, int x) {
    push(&q->s1, x);
    printf("Enqueued: %d\n", x);
}

int dequeue(struct Queue* q) {
    if (q->s1.top == -1 && q->s2.top == -1) return -1;
    if (q->s2.top == -1) {
        while (q->s1.top != -1) push(&q->s2, pop(&q->s1));
    }
    return pop(&q->s2);
}

int main() {
    struct Queue q; q.s1.top = q.s2.top = -1;
    enqueue(&q, 1); enqueue(&q, 2);
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    return 0;
}
