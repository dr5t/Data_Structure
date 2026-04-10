#include <stdio.h>
#include <stdlib.h>

/* 
 * QUESTION: Doubly Linked List (DLL) Complete
 * Implement a DLL with Insertion (Head, Tail) 
 * and Deletion operations.
 */

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertAtHead(struct Node** head, int val) {
    struct Node* node = createNode(val);
    if (*head != NULL) (*head)->prev = node;
    node->next = *head;
    *head = node;
    printf("Inserted at Head: %d\n", val);
}

void insertAtTail(struct Node** head, int val) {
    struct Node* node = createNode(val);
    if (*head == NULL) {
        *head = node;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = node;
    node->prev = temp;
    printf("Inserted at Tail: %d\n", val);
}

void deleteNode(struct Node** head, int val) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    while (temp != NULL && temp->data != val) temp = temp->next;
    
    if (temp == NULL) return; // Value not found

    if (temp->prev != NULL) temp->prev->next = temp->next;
    else *head = temp->next;

    if (temp->next != NULL) temp->next->prev = temp->prev;

    free(temp);
    printf("Deleted Node: %d\n", val);
}

void display(struct Node* head) {
    printf("DLL: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    insertAtHead(&head, 10);
    insertAtHead(&head, 20);
    insertAtTail(&head, 30);
    display(head);

    deleteNode(&head, 10);
    display(head);

    return 0;
}
