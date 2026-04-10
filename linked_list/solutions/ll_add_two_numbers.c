#include <stdio.h>
#include <stdlib.h>

/* 
 * QUESTION: Add Two Numbers
 * Numbers are represented as Linked Lists (one digit per node).
 */

struct Node {
    int data;
    struct Node* next;
};

struct Node* push(int val) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = val; n->next = NULL;
    return n;
}

struct Node* addTwoLists(struct Node* l1, struct Node* l2) {
    struct Node *res = NULL, *temp, *prev = NULL;
    int carry = 0, sum;

    while (l1 != NULL || l2 != NULL) {
        sum = carry + (l1 ? l1->data : 0) + (l2 ? l2->data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;

        temp = push(sum);
        if (res == NULL) res = temp;
        else prev->next = temp;

        prev = temp;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    if (carry > 0) prev->next = push(carry);
    return res;
}

void print(struct Node* n) {
    while(n) { printf("%d ", n->data); n = n->next; }
    printf("\n");
}

int main() {
    // 342 (2->4->3) + 465 (5->6->4) = 807 (7->0->8)
    struct Node* l1 = push(2); l1->next = push(4); l1->next->next = push(3);
    struct Node* l2 = push(5); l2->next = push(6); l2->next->next = push(4);

    struct Node* res = addTwoLists(l1, l2);
    printf("Result (L1 + L2): "); print(res);

    return 0;
}
