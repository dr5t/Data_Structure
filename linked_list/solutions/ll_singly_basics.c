#include <stdio.h>
#include <stdlib.h>

/* 
 * QUESTION: Singly Linked List Basics
 * Create a simple program to insert elements at the head 
 * and display the list.
 */

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the head of the list
void insertAtHead(struct Node** headRef, int val) {
    struct Node* newNode = createNode(val);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to display the list
void display(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL; // Initialize empty list

    printf("Inserting 10, 20, 30 at the head...\n");
    insertAtHead(&head, 10);
    insertAtHead(&head, 20);
    insertAtHead(&head, 30);

    display(head);

    return 0;
}
