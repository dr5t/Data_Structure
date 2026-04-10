#include <stdio.h>
#include <stdlib.h>

/* 
 * QUESTION: Circular Linked List (CLL) Complete
 * Implement a CLL with Insertion and Traversal logic.
 */

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** last, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    if (*last == NULL) {
        *last = newNode;
        newNode->next = *last; // Points to itself
    } else {
        newNode->next = (*last)->next;
        (*last)->next = newNode;
        *last = newNode;
    }
    printf("Inserted: %d\n", val);
}

void display(struct Node* last) {
    if (last == NULL) return;
    struct Node* head = last->next;
    printf("CLL: ");
    do {
        printf("%d -> ", head->data);
        head = head->next;
    } while (head != last->next);
    printf("(head)\n");
}

int main() {
    struct Node* last = NULL;
    insert(&last, 10);
    insert(&last, 20);
    insert(&last, 30);
    display(last);
    return 0;
}
