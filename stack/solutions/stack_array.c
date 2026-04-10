#include <stdio.h>
#include <stdbool.h>

/* 
 * QUESTION: Array-based Stack
 * Implement a simple stack using an array with 
 * push, pop, and peek operations.
 */

#define MAX 5 // Maximum size of the stack

struct Stack {
    int arr[MAX];
    int top;
};

// Function to initialize the stack
void init(struct Stack* s) {
    s->top = -1; // -1 means the stack is empty
}

// Check if stack is empty
bool isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Check if stack is full
bool isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

// Add an element to the stack
void push(struct Stack* s, int val) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", val);
        return;
    }
    s->arr[++(s->top)] = val;
    printf("Pushed %d onto the stack.\n", val);
}

// Remove the top element
int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Nothing to pop.\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

// Look at the top element
int peek(struct Stack* s) {
    if (isEmpty(s)) return -1;
    return s->arr[s->top];
}

int main() {
    struct Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element is: %d\n", peek(&s));
    printf("Popped element: %d\n", pop(&s));
    printf("Top element now: %d\n", peek(&s));

    return 0;
}
