#include <stdio.h>
#include <stdlib.h>

/* 
 * QUESTION: Merge Sort on Linked List
 * A common college-level advanced LL problem.
 */

struct Node {
    int data;
    struct Node* next;
};

struct Node* sortedMerge(struct Node* a, struct Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    struct Node* result = NULL;
    if (a->data <= b->data) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

void split(struct Node* source, struct Node** front, struct Node** back) {
    struct Node* fast = source->next;
    struct Node* slow = source;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

void mergeSort(struct Node** headRef) {
    struct Node* head = *headRef;
    if (head == NULL || head->next == NULL) return;

    struct Node *a, *b;
    split(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef = sortedMerge(a, b);
}

void push(struct Node** head, int val) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = val;
    node->next = *head;
    *head = node;
}

void print(struct Node* node) {
    while(node) { printf("%d ", node->data); node = node->next; }
    printf("\n");
}

int main() {
    struct Node* a = NULL;
    push(&a, 15); push(&a, 10); push(&a, 5); push(&a, 20); push(&a, 3);
    
    printf("Original: "); print(a);
    mergeSort(&a);
    printf("Sorted List: "); print(a);

    return 0;
}
