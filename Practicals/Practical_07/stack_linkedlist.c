/*
 * Practical_07: Stack of Integers – Linked List Implementation
 * Operations: Push, Pop, Overflow/Underflow demo, Display
 */

#include <stdio.h>
#include <stdlib.h>

/* ────────────────────────── Node Definition ───────────────────────────── */

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *top = NULL;
int   nodeCount = 0;

/* ────────────────────────── Core Operations ───────────────────────────── */

int isEmpty(void) { return top == NULL; }

/* a. Push */
void push(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        /* Theoretical overflow – memory exhausted */
        printf("  OVERFLOW! Memory allocation failed.\n");
        return;
    }
    newNode->data = val;
    newNode->next = top;
    top = newNode;
    nodeCount++;
    printf("  %d pushed onto stack.\n", val);
}

/* b. Pop */
void pop(void)
{
    if (isEmpty()) {
        printf("  UNDERFLOW! Stack is empty.\n");
        return;
    }
    Node *tmp = top;
    printf("  Popped: %d\n", tmp->data);
    top = top->next;
    free(tmp);
    nodeCount--;
}

/* d. Display */
void displayStack(void)
{
    if (isEmpty()) { printf("  Stack is empty.\n"); return; }
    printf("\n  Stack (TOP → BOTTOM):\n");
    Node *cur = top;
    int i = 1;
    while (cur) {
        printf("  %s[ %d ]\n", (i == 1 ? "TOP → " : "       "), cur->data);
        cur = cur->next;
        i++;
    }
    printf("  Total elements: %d\n", nodeCount);
}

/* c. Overflow / Underflow Demo */
void demoOverflowUnderflow(void)
{
    printf("\n── Underflow Demonstration ─────────────────────\n");
    /* Push a few, pop more than pushed */
    push(10); push(20);
    pop(); pop();
    printf("  Trying to pop from empty stack …\n");
    pop();   /* should print UNDERFLOW */

    printf("\n── Overflow Note ───────────────────────────────\n");
    printf("  In a linked-list stack, overflow occurs only\n");
    printf("  when the system heap is exhausted (malloc fails).\n");
    printf("  This is extremely rare on modern systems.\n");
}

/* ────────────────────────── Main Menu ─────────────────────────────────── */

int main(void)
{
    int choice, val;
    printf("\n═══════════════════════════════════════════════════════\n");
    printf("   Practical_07 : Stack of Integers (Linked List)     \n");
    printf("═══════════════════════════════════════════════════════\n");

    do {
        printf("\n┌────────────────────────────────────────────┐\n");
        printf("│                 MAIN MENU                  │\n");
        printf("├────────────────────────────────────────────┤\n");
        printf("│  1. Push an element onto Stack             │\n");
        printf("│  2. Pop an element from Stack              │\n");
        printf("│  3. Demonstrate Overflow & Underflow       │\n");
        printf("│  4. Display Stack status                   │\n");
        printf("│  0. Exit                                   │\n");
        printf("└────────────────────────────────────────────┘\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter integer to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2: pop();                    break;
            case 3: demoOverflowUnderflow();  break;
            case 4: displayStack();           break;
            case 0: printf("Exiting program. Goodbye!\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
