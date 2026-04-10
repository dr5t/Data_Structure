#include <stdio.h>
#include <stdlib.h>

/* 
 * QUESTION: Find Middle Node
 * Find the middle node of a linked list using the 
 * "Fast and Slow Pointer" technique.
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

void findMiddle(struct Node* head) {
    if (head == NULL) return;

    struct Node *slow = head;
    struct Node *fast = head;

    // Fast pointer moves 2 steps, slow moves 1 step
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("The middle element is: %d\n", slow->data);
}

int main() {
    struct Node* head = NULL;
    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);
    insertAtTail(&head, 40);
    insertAtTail(&head, 50);

    printf("List: 10 -> 20 -> 30 -> 40 -> 50 -> NULL\n");
    findMiddle(head);

    return 0;
}
