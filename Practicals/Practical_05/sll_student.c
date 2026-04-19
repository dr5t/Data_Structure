/*
 * Practical_05: Singly Linked List (SLL) of Student Data
 * Fields: USN, Name, Branch, Sem, PhNo
 * Operations: Front Insert, Display, Count, Insert/Delete at End,
 *             Insert/Delete at Front, Insert/Delete at Position, Reverse
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ─────────────────────────── Node Definition ───────────────────────────── */

typedef struct Student {
    char usn[15];
    char name[30];
    char branch[10];
    int  sem;
    char phno[13];
    struct Student *next;
} Node;

Node *head = NULL;

/* ─────────────────────────── Helper Functions ──────────────────────────── */

Node *createNode(void)
{
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) { printf("Memory allocation failed!\n"); exit(1); }

    printf("  USN    : "); scanf("%s", n->usn);
    printf("  Name   : "); scanf("%s", n->name);
    printf("  Branch : "); scanf("%s", n->branch);
    printf("  Sem    : "); scanf("%d", &n->sem);
    printf("  PhNo   : "); scanf("%s", n->phno);
    n->next = NULL;
    return n;
}

void printNode(Node *n, int idx)
{
    printf("  [%2d] %-12s | %-18s | %-6s | Sem:%-2d | %s\n",
           idx, n->usn, n->name, n->branch, n->sem, n->phno);
}

/* ─────────────────────────── Core Operations ───────────────────────────── */

/* a. Create SLL of N students using front insertion */
void createSLL(void)
{
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d details:\n", i + 1);
        Node *newNode = createNode();
        newNode->next = head;          /* front insertion */
        head = newNode;
    }
    printf("SLL created successfully (front insertion).\n");
}

/* b. Display SLL and count nodes */
void displaySLL(void)
{
    if (!head) { printf("List is empty.\n"); return; }
    int count = 0;
    Node *cur = head;
    printf("\n  %-4s %-12s | %-18s | %-6s | %-6s | %s\n",
           "No.", "USN", "Name", "Branch", "Sem", "PhNo");
    printf("  %s\n", "-------------------------------------------------------------------");
    while (cur) {
        printNode(cur, ++count);
        cur = cur->next;
    }
    printf("  Total nodes: %d\n", count);
}

/* c. Insert at End */
void insertAtEnd(void)
{
    printf("Enter new student details:\n");
    Node *newNode = createNode();
    if (!head) { head = newNode; }
    else {
        Node *cur = head;
        while (cur->next) cur = cur->next;
        cur->next = newNode;
    }
    printf("Node inserted at end.\n");
}

/* c. Delete at End */
void deleteAtEnd(void)
{
    if (!head) { printf("List is empty.\n"); return; }
    if (!head->next) { free(head); head = NULL; }
    else {
        Node *cur = head;
        while (cur->next->next) cur = cur->next;
        free(cur->next);
        cur->next = NULL;
    }
    printf("Last node deleted.\n");
}

/* d. Insert at Front */
void insertAtFront(void)
{
    printf("Enter new student details:\n");
    Node *newNode = createNode();
    newNode->next = head;
    head = newNode;
    printf("Node inserted at front.\n");
}

/* d. Delete at Front */
void deleteAtFront(void)
{
    if (!head) { printf("List is empty.\n"); return; }
    Node *tmp = head;
    head = head->next;
    free(tmp);
    printf("Front node deleted.\n");
}

/* e. Insert at given position (1-based) */
void insertAtPosition(void)
{
    int pos, count = 1;
    printf("Enter position to insert (1-based): ");
    scanf("%d", &pos);
    if (pos <= 0) { printf("Invalid position.\n"); return; }
    printf("Enter new student details:\n");
    Node *newNode = createNode();
    if (pos == 1) { newNode->next = head; head = newNode; return; }
    Node *cur = head;
    while (cur && count < pos - 1) { cur = cur->next; count++; }
    if (!cur) { printf("Position out of range.\n"); free(newNode); return; }
    newNode->next = cur->next;
    cur->next = newNode;
    printf("Node inserted at position %d.\n", pos);
}

/* e. Delete at given position (1-based) */
void deleteAtPosition(void)
{
    if (!head) { printf("List is empty.\n"); return; }
    int pos, count = 1;
    printf("Enter position to delete (1-based): ");
    scanf("%d", &pos);
    if (pos <= 0) { printf("Invalid position.\n"); return; }
    if (pos == 1) { Node *tmp = head; head = head->next; free(tmp); printf("Node deleted.\n"); return; }
    Node *cur = head;
    while (cur->next && count < pos - 1) { cur = cur->next; count++; }
    if (!cur->next) { printf("Position out of range.\n"); return; }
    Node *tmp = cur->next;
    cur->next = tmp->next;
    free(tmp);
    printf("Node at position %d deleted.\n", pos);
}

/* f. Reverse the SLL */
void reverseSLL(void)
{
    if (!head) { printf("List is empty.\n"); return; }
    Node *prev = NULL, *cur = head, *nxt = NULL;
    while (cur) {
        nxt       = cur->next;
        cur->next = prev;
        prev      = cur;
        cur       = nxt;
    }
    head = prev;
    printf("List reversed successfully.\n");
}

/* ─────────────────────────── Main Menu ─────────────────────────────────── */

int main(void)
{
    int choice;
    printf("\n═══════════════════════════════════════════════════\n");
    printf("   Practical_05 : Singly Linked List – Student Data\n");
    printf("═══════════════════════════════════════════════════\n");

    do {
        printf("\n┌─────────────────────────────────────────┐\n");
        printf("│              MAIN MENU                  │\n");
        printf("├─────────────────────────────────────────┤\n");
        printf("│  1. Create SLL (front insertion)        │\n");
        printf("│  2. Display SLL & Count nodes           │\n");
        printf("│  3. Insert at End                       │\n");
        printf("│  4. Delete at End                       │\n");
        printf("│  5. Insert at Front                     │\n");
        printf("│  6. Delete at Front                     │\n");
        printf("│  7. Insert at given Position            │\n");
        printf("│  8. Delete at given Position            │\n");
        printf("│  9. Reverse the SLL                     │\n");
        printf("│  0. Exit                                │\n");
        printf("└─────────────────────────────────────────┘\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createSLL();         break;
            case 2: displaySLL();        break;
            case 3: insertAtEnd();       break;
            case 4: deleteAtEnd();       break;
            case 5: insertAtFront();     break;
            case 6: deleteAtFront();     break;
            case 7: insertAtPosition();  break;
            case 8: deleteAtPosition();  break;
            case 9: reverseSLL();        break;
            case 0: printf("Exiting program. Goodbye!\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
