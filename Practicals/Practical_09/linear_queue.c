/*
 * Practical_09: Linear QUEUE of Characters – Array Implementation
 * MAX size defined at compile time.
 * Operations: Insert, Delete, Overflow/Underflow demo, Display
 */

#include <stdio.h>

#define MAX 8

/* ────────────────────────── Queue Structure ───────────────────────────── */

char queue[MAX];
int  front = -1, rear = -1;

/* ────────────────────────── Core Operations ───────────────────────────── */

int isFull(void)  { return rear == MAX - 1; }
int isEmpty(void) { return front == -1 || front > rear; }

/* a. Insert (Enqueue) */
int enqueue(char c)
{
    if (isFull()) return 0;           /* Overflow */
    if (front == -1) front = 0;
    queue[++rear] = c;
    return 1;
}

/* b. Delete (Dequeue) */
int dequeue(char *c)
{
    if (isEmpty()) return 0;          /* Underflow */
    *c = queue[front++];
    if (front > rear) { front = rear = -1; }  /* reset when empty */
    return 1;
}

/* d. Display */
void displayQueue(void)
{
    if (isEmpty()) { printf("  Queue is empty.\n"); return; }
    printf("\n  Queue (FRONT → REAR):\n  ");
    for (int i = front; i <= rear; i++)
        printf("[ %c ]", queue[i]);
    printf("\n  FRONT = %d  |  REAR = %d  |  Size = %d / %d\n",
           front, rear, rear - front + 1, MAX);
}

/* ────────────────────────── Menu Handlers ──────────────────────────────── */

void menuEnqueue(void)
{
    char c;
    printf("Enter character to insert: ");
    scanf(" %c", &c);
    if (enqueue(c))
        printf("  '%c' inserted into queue.\n", c);
    else
        printf("  OVERFLOW! Queue is full (MAX = %d).\n", MAX);
}

void menuDequeue(void)
{
    char c;
    if (dequeue(&c))
        printf("  Deleted element: '%c'\n", c);
    else
        printf("  UNDERFLOW! Queue is empty.\n");
}

/* c. Overflow / Underflow Demo */
void demoOverflowUnderflow(void)
{
    printf("\n── Overflow Demonstration ──────────────────────\n");
    char test[] = "ABCDEFGHIJ";     /* more than MAX */
    for (int i = 0; test[i]; i++) {
        printf("  Inserting '%c' … ", test[i]);
        if (enqueue(test[i]))
            printf("OK  (rear=%d)\n", rear);
        else
            printf("OVERFLOW! (MAX=%d reached)\n", MAX);
    }

    printf("\n── Underflow Demonstration ─────────────────────\n");
    char c;
    while (!isEmpty()) dequeue(&c);
    printf("  Queue now empty. Trying to delete …\n");
    if (!dequeue(&c))
        printf("  UNDERFLOW!\n");
}

/* ────────────────────────── Main Menu ─────────────────────────────────── */

int main(void)
{
    int choice;
    printf("\n═══════════════════════════════════════════════════════\n");
    printf("   Practical_09 : Linear Queue of Characters           \n");
    printf("   Array Implementation  |  MAX Size = %d             \n", MAX);
    printf("═══════════════════════════════════════════════════════\n");

    do {
        printf("\n┌────────────────────────────────────────────────┐\n");
        printf("│                   MAIN MENU                    │\n");
        printf("├────────────────────────────────────────────────┤\n");
        printf("│  1. Insert element into Linear Queue           │\n");
        printf("│  2. Delete element from Linear Queue           │\n");
        printf("│  3. Demonstrate Overflow & Underflow           │\n");
        printf("│  4. Display Queue status                       │\n");
        printf("│  0. Exit                                       │\n");
        printf("└────────────────────────────────────────────────┘\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: menuEnqueue();            break;
            case 2: menuDequeue();            break;
            case 3: demoOverflowUnderflow();  break;
            case 4: displayQueue();           break;
            case 0: printf("Exiting program. Goodbye!\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
