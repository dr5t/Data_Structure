#include <stdio.h>
#include <stdlib.h>

/**
 * PROBLEM: DETECT AND REMOVE LOOP
 * ------------------------------
 * Logic:
 * 1. Use Fast & Slow pointers to detect a loop.
 * 2. If a loop is found, move `slow` to `head`.
 * 3. Keep `fast` where it is.
 * 4. Move both pointers one step at a time until they meet.
 * 5. This meeting point is the loop entry.
 * 6. Find the node before the entry and set its `next = NULL`.
 * 
 * Efficiency: $O(n)$ time, $O(1)$ extra space.
 */

struct Node {
    int data;
    struct Node* next;
};

// Function to detect and remove a loop
void detectAndRemoveLoop(struct Node* head) {
    if (head == NULL || head->next == NULL) return;

    struct Node *slow = head, *fast = head;

    // 1. Detect loop using Floyd's Algorithm
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }

    // 2. If no loop exists
    if (slow != fast) return;

    printf("Loop detected!\n");

    // 3. Find the loop start
    slow = head;
    if (slow == fast) {
        // Special case: Loop starts at head
        while (fast->next != slow) fast = fast->next;
    } else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // 4. Remove loop
    fast->next = NULL;
    printf("Loop removed successfully.\n");
}

// Helper to push node
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Helper to print list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    push(&head, 50);
    push(&head, 40);
    push(&head, 30);
    push(&head, 20);
    push(&head, 10);

    // Create a loop for testing: 10 -> 20 -> 30 -> 40 -> 50 -> 30 (loop back)
    head->next->next->next->next->next = head->next->next;

    detectAndRemoveLoop(head);

    printf("Linked List after removing loop: ");
    printList(head);

    return 0;
}
