#include <stdio.h>
#include <stdlib.h>

/* 
 * QUESTION: Remove Nth Node From End
 * Remove the node at index N from the tail using two-pointer (fast/slow) logic.
 */

struct Node {
    int data;
    struct Node* next;
};

void removeNthFromEnd(struct Node** head_ref, int n) {
    struct Node *fast = *head_ref, *slow = *head_ref;
    
    // Step 1: Move fast pointer n steps forward
    for (int i = 0; i < n; i++) {
        if (fast == NULL) return; // N is larger than total nodes
        fast = fast->next;
    }

    // Edge Case: If fast becomes NULL, we need to remove the head
    if (fast == NULL) {
        struct Node* temp = *head_ref;
        *head_ref = (*head_ref)->next;
        free(temp);
        return;
    }

    // Step 2: Move both until fast reaches the last node
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // Step 3: slow->next is the node to delete
    struct Node* toDelete = slow->next;
    slow->next = slow->next->next;
    free(toDelete);
}

void push(struct Node** head, int val) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = val; n->next = *head;
    *head = n;
}

void printList(struct Node* n) {
    while(n) { printf("%d -> ", n->data); n = n->next; }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    push(&head, 50); push(&head, 40); push(&head, 30); push(&head, 20); push(&head, 10);
    
    printf("Original: "); printList(head);
    
    int n = 2; // Remove 2nd from end (40)
    removeNthFromEnd(&head, n);
    
    printf("After removing %d-th from end: ", n);
    printList(head);

    return 0;
}
