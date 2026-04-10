#include <stdio.h>
#include <stdlib.h>

/* 
 * QUESTION: Merge Two Sorted Lists
 * Given two sorted linked lists, merge them into one sorted list.
 */

struct Node {
    int data;
    struct Node* next;
};

struct Node* mergeSorted(struct Node* l1, struct Node* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    struct Node* result = NULL;

    // Use recursive logic for cleaner college-level code
    if (l1->data <= l2->data) {
        result = l1;
        result->next = mergeSorted(l1->next, l2);
    } else {
        result = l2;
        result->next = mergeSorted(l1, l2->next);
    }
    return result;
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
    struct Node *l1 = NULL, *l2 = NULL;

    // L1: 3->5->7
    push(&l1, 7); push(&l1, 5); push(&l1, 3);
    // L2: 2->4->6
    push(&l2, 6); push(&l2, 4); push(&l2, 2);

    printf("List 1: "); printList(l1);
    printf("List 2: "); printList(l2);

    struct Node* mergedHead = mergeSorted(l1, l2);
    printf("Merged: "); printList(mergedHead);

    return 0;
}
