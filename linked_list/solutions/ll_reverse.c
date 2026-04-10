#include <stdio.h>
#include <stdlib.h>

/* 
 * QUESTION: Reverse Linked List
 * Reverse a linked list in a single pass iteratively.
 */

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertAtTail(struct Node** headRef, int val) {
    struct Node* newNode = createNode(val);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

// Function to reverse the list
void reverse(struct Node** headRef) {
    struct Node *prev = NULL, *current = *headRef, *next = NULL;
    
    while (current != NULL) {
        next = current->next;  // Store next node
        current->next = prev;  // Reverse the link
        prev = current;        // Move prev to current
        current = next;        // Move current to next
    }
    *headRef = prev; // Update head to the last node processed
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    insertAtTail(&head, 1);
    insertAtTail(&head, 2);
    insertAtTail(&head, 3);

    printf("Original list: ");
    display(head);

    printf("Reversing the list...\n");
    reverse(&head);

    printf("Reversed list: ");
    display(head);

    return 0;
}
