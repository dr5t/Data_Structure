#include <stdio.h>
#include <stdlib.h>

/**
 * PROBLEM: REVERSE IN GROUPS OF K
 * ------------------------------
 * Logic:
 * 1. Count if we have K nodes left.
 * 2. If not, return the current head (no changes).
 * 3. Reverse the first K nodes iteratively.
 * 4. Recurse for the rest of the list.
 * 5. Attach the reversed rest to the current node.
 * 
 * Efficiency: $O(n)$ time.
 */

struct Node {
    int data;
    struct Node* next;
};

// Function to reverse a group of K nodes
struct Node* reverseKGroup(struct Node* head, int k) {
    if (head == NULL) return NULL;

    struct Node* curr = head;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    int count = 0;

    // First, check if there are K nodes remaining
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Now, `next` is pointing to the (k+1)-th node
    // Recursively call for the rest of the list and link it
    if (next != NULL) {
        head->next = reverseKGroup(next, k);
    }

    // `prev` is now the new head of this reversed group
    return prev;
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

    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    int k = 3;
    printf("Original List: ");
    printList(head);

    head = reverseKGroup(head, k);

    printf("Reversed in Groups of %d: ", k);
    printList(head);

    return 0;
}
