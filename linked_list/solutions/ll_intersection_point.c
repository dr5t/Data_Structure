#include <stdio.h>
#include <stdlib.h>

/* 
 * QUESTION: Intersection of Two Linked Lists
 * Find the node where two linked lists merge.
 */

struct Node {
    int data;
    struct Node* next;
};

int getCount(struct Node* head) {
    int count = 0;
    while(head) { count++; head = head->next; }
    return count;
}

struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d = abs(c1 - c2);

    struct Node *ptr1 = head1, *ptr2 = head2;
    // Step: Move the pointer of the longer list by 'd' nodes
    if (c1 > c2) {
        for(int i=0; i<d; i++) ptr1 = ptr1->next;
    } else {
        for(int i=0; i<d; i++) ptr2 = ptr2->next;
    }

    // Step: Move both until they meet
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2) return ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return NULL;
}

int main() {
    // Manual setup of intersecting lists
    struct Node* common = malloc(sizeof(struct Node));
    common->data = 15; common->next = NULL;

    struct Node* h1 = malloc(sizeof(struct Node)); h1->data = 3; h1->next = malloc(sizeof(struct Node)); h1->next->data = 6; h1->next->next = common;
    struct Node* h2 = malloc(sizeof(struct Node)); h2->data = 10; h2->next = common;

    struct Node* intersect = getIntersection(h1, h2);
    if (intersect) printf("Intersection node value: %d\n", intersect->data);
    else printf("No intersection found.\n");

    return 0;
}
