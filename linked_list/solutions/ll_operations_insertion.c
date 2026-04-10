#include <stdio.h>
#include <stdlib.h>

/* 
 * QUESTION: Linked List Insertion Guide
 * Complete program demonstrating Head, Tail, and Position insertion.
 */

struct Node {
    int data;
    struct Node* next;
};

// 1. Insert at Beginning (O(1))
void insertAtHead(struct Node** head_ref, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *head_ref;
    *head_ref = newNode;
}

// 2. Insert at End (O(n))
void insertAtTail(struct Node** head_ref, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    struct Node* temp = *head_ref;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

// 3. Insert at Position (O(n))
void insertAtPos(struct Node** head_ref, int val, int pos) {
    if (pos == 1) {
        insertAtHead(head_ref, val);
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    
    struct Node* temp = *head_ref;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtHead(&head, 5);
    insertAtPos(&head, 15, 3); // Position 3 (between 10 and 20)

    printf("Full List: ");
    printList(head);

    return 0;
}
