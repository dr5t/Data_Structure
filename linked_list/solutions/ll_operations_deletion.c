#include <stdio.h>
#include <stdlib.h>

/* 
 * QUESTION: Linked List Deletion Guide
 * Complete program demonstrating Beginning, End, and Position deletion.
 */

struct Node {
    int data;
    struct Node* next;
};

// 1. Delete from Beginning (O(1))
void deleteHead(struct Node** head_ref) {
    if (*head_ref == NULL) return;
    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

// 2. Delete from End (O(n))
void deleteTail(struct Node** head_ref) {
    if (*head_ref == NULL) return;
    if ((*head_ref)->next == NULL) {
        free(*head_ref);
        *head_ref = NULL;
        return;
    }
    struct Node* temp = *head_ref;
    while (temp->next->next != NULL) temp = temp->next;
    
    free(temp->next);
    temp->next = NULL;
}

// 3. Delete from Position (O(n))
void deleteAtPos(struct Node** head_ref, int pos) {
    if (*head_ref == NULL) return;
    if (pos == 1) {
        deleteHead(head_ref);
        return;
    }

    struct Node* temp = *head_ref;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++) temp = temp->next;

    if (temp->next == NULL) {
        printf("Position out of range!\n");
        return;
    }

    struct Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
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
    // Pre-populating list: 5->10->15->20
    struct Node* n1 = malloc(sizeof(struct Node)); n1->data = 5;
    struct Node* n2 = malloc(sizeof(struct Node)); n2->data = 10;
    struct Node* n3 = malloc(sizeof(struct Node)); n3->data = 15;
    struct Node* n4 = malloc(sizeof(struct Node)); n4->data = 20;
    head = n1; n1->next = n2; n2->next = n3; n3->next = n4; n4->next = NULL;

    printf("Original: "); printList(head);

    deleteHead(&head);
    deleteTail(&head);
    deleteAtPos(&head, 2);

    printf("After Deletions: ");
    printList(head);

    return 0;
}
