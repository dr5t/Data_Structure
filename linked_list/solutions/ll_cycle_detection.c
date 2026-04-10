#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 
 * QUESTION: Detect Cycle
 * Check if a linked list has a cycle using 
 * Floyd's Cycle-Finding Algorithm.
 */

struct Node {
    int data;
    struct Node* next;
};

bool hasCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true; // Cycle detected
        }
    }
    return false; // No cycle
}

int main() {
    // Create a manual list with a cycle for testing
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 3;
    
    // Create cycle: 3 -> 2
    head->next->next->next = head->next; 

    if (hasCycle(head)) {
        printf("Cycle detected in the linked list!\n");
    } else {
        printf("No cycle detected.\n");
    }

    return 0;
}
