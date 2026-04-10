#include <stdio.h>
#include <stdlib.h>

/* 
 * QUESTION: Stack using Linked List
 * A professional implementation with dedicated Push, Pop, and Peek functions.
 */

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Heap Overflow! Cannot allocate memory.\n");
        return;
    }
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d to stack\n", val);
}

int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow!\n");
        return -1;
    }
    struct Node* temp = *top;
    int popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}

int peek(struct Node* top) {
    if (top == NULL) return -1;
    return top->data;
}

void display(struct Node* top) {
    printf("Stack (Top to Bottom): ");
    while (top != NULL) {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* stack = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(stack);

    printf("Popped element: %d\n", pop(&stack));
    printf("Current Top: %d\n", peek(stack));

    return 0;
}
