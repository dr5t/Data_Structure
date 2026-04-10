#include <stdio.h>
#include <stdlib.h>

/**
 * PROBLEM: MIN-STACK (CONSTANT TIME)
 * ---------------------------------
 * Logic:
 * 1. Maintain two stacks: `dataStack` and `minStack`.
 * 2. When pushing `x`:
 *    - Always push `x` to `dataStack`.
 *    - If `minStack` is empty OR `x <= minStack.top`, push `x` to `minStack`.
 * 3. When popping:
 *    - Pop from `dataStack`.
 *    - If the popped element is the same as `minStack.top`, pop from `minStack` too.
 * 
 * Efficiency: $O(1)$ for getMin, push, and pop.
 */

#define MAX 100

typedef struct {
    int items[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int x) {
    if (s->top == MAX - 1) return;
    s->items[++(s->top)] = x;
}

int pop(Stack* s) {
    if (isEmpty(s)) return -1;
    return s->items[(s->top)--];
}

int peek(Stack* s) {
    if (isEmpty(s)) return -1;
    return s->items[s->top];
}

typedef struct {
    Stack dataStack;
    Stack minStack;
} MinStack;

void initMinStack(MinStack* ms) {
    initStack(&ms->dataStack);
    initStack(&ms->minStack);
}

void minStackPush(MinStack* ms, int x) {
    push(&ms->dataStack, x);
    if (isEmpty(&ms->minStack) || x <= peek(&ms->minStack)) {
        push(&ms->minStack, x);
    }
}

void minStackPop(MinStack* ms) {
    if (isEmpty(&ms->dataStack)) return;
    int val = pop(&ms->dataStack);
    if (val == peek(&ms->minStack)) {
        pop(&ms->minStack);
    }
}

int minStackTop(MinStack* ms) {
    return peek(&ms->dataStack);
}

int minStackGetMin(MinStack* ms) {
    return peek(&ms->minStack);
}

int main() {
    MinStack ms;
    initMinStack(&ms);

    printf("Pushing: 5, 2, 10, 2, 7\n");
    minStackPush(&ms, 5);
    minStackPush(&ms, 2);
    minStackPush(&ms, 10);
    minStackPush(&ms, 2);
    minStackPush(&ms, 7);

    printf("Current Min: %d\n", minStackGetMin(&ms)); // Expect 2
    
    printf("Popping 2 elements (7, 2)...\n");
    minStackPop(&ms);
    minStackPop(&ms);
    printf("Current Min: %d\n", minStackGetMin(&ms)); // Expect 2

    printf("Popping 2 elements (10, 2)...\n");
    minStackPop(&ms);
    minStackPop(&ms);
    printf("Current Min: %d\n", minStackGetMin(&ms)); // Expect 5

    return 0;
}
