#include <stdio.h>
#include <stdlib.h>

/* 
 * QUESTION: Linked List-based Stack
 * Implement a dynamic stack using a linked list.
 */

struct Node {
    int data;
    struct Node* next;
};

// Function to push a value onto the stack
void push(struct Node** topRef, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error!\n");
        return;
    }
    newNode->data = val;
    newNode->next = *topRef; // New node points to old top
    *topRef = newNode;       // New node becomes the top
    printf("Pushed %d (LL)\n", val);
}

// Function to pop a value
int pop(struct Node** topRef) {
    if (*topRef == NULL) {
        printf("Stack Underflow!\n");
        return -1;
    }
    struct Node* temp = *topRef;
    int data = temp->data;
    *topRef = (*topRef)->next; // Move top to next node
    free(temp);
    return data;
}

void display(struct Node* top) {
    printf("Stack (top to bottom): ");
    while (top != NULL) {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* top = NULL;

    push(&top, 100);
    push(&top, 200);
    push(&top, 300);
    display(top);

    printf("Popped: %d\n", pop(&top));
    display(top);

    return 0;
}
