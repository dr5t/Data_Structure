/*
 * Practical_10: Circular QUEUE of Characters – Array Implementation
 * MAX size defined at compile time.
 * Operations: Insert, Delete, Overflow/Underflow demo, Display
 *
 * Key difference from Linear Queue:
 *   front and rear wrap around using modulo arithmetic.
 *   One slot is kept empty to distinguish full from empty.
 */

#include <stdio.h>

#define MAX 8

/* ────────────────────────── Queue Structure ───────────────────────────── */

char queue[MAX];
int  front = 0, rear = 0;
/* Condition: empty when front == rear
              full  when (rear+1) % MAX == front  (one slot wasted) */

/* ────────────────────────── Core Operations ───────────────────────────── */

int isFull(void)  { return (rear + 1) % MAX == front; }
int isEmpty(void) { return front == rear; }

/* a. Insert (Enqueue) */
int enqueue(char c)
{
    if (isFull()) return 0;           /* Overflow */
    rear = (rear + 1) % MAX;
    queue[rear] = c;
    return 1;
}

/* b. Delete (Dequeue) */
int dequeue(char *c)
{
    if (isEmpty()) return 0;          /* Underflow */
    front = (front + 1) % MAX;
    *c = queue[front];
    return 1;
}

/* d. Display */
void displayQueue(void)
{
    if (isEmpty()) { printf("  Circular Queue is empty.\n"); return; }
    printf("\n  Circular Queue (FRONT → REAR, circular):\n  ");
    int i = (front + 1) % MAX;
    int count = 0;
    while (1) {
        printf("[ %c ]", queue[i]);
        count++;
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n  Elements: %d / %d  |  front index = %d  |  rear index = %d\n",
           count, MAX - 1, front, rear);

    /* Visual ring */
    printf("\n  Circular ring view (index 0 … %d):\n  ", MAX - 1);
    for (int j = 0; j < MAX; j++) {
        if (j == front) printf("[F:%2s]", (j == rear ? "FR" : " "));
        else if (j == rear)  printf("[R:%2c]", queue[j]);
        else {
            /* check if slot is occupied */
            int occ = 0;
            int cur = (front + 1) % MAX;
            for (int k = 0; k < count; k++) {
                if (cur == j) { occ = 1; break; }
                cur = (cur + 1) % MAX;
            }
            printf("[%c:%2c]", occ ? ' ' : '_', occ ? queue[j] : '-');
        }
    }
    printf("\n");
}

/* ────────────────────────── Menu Handlers ──────────────────────────────── */

void menuEnqueue(void)
{
    char c;
    printf("Enter character to insert: ");
    scanf(" %c", &c);
    if (enqueue(c))
        printf("  '%c' inserted (rear = %d).\n", c, rear);
    else
        printf("  OVERFLOW! Circular Queue is full (capacity = %d).\n", MAX - 1);
}

void menuDequeue(void)
{
    char c;
    if (dequeue(&c))
        printf("  Deleted element: '%c' (front = %d).\n", c, front);
    else
        printf("  UNDERFLOW! Circular Queue is empty.\n");
}

/* c. Overflow / Underflow Demo */
void demoOverflowUnderflow(void)
{
    /* Save state */
    int sf = front, sr = rear;

    printf("\n── Overflow Demonstration ──────────────────────\n");
    front = rear = 0;  /* reset */
    char test[] = "ABCDEFGH";  /* capacity is MAX-1 = 7 */
    for (int i = 0; test[i]; i++) {
        printf("  Inserting '%c' … ", test[i]);
        if (enqueue(test[i]))
            printf("OK  (rear=%d)\n", rear);
        else
            printf("OVERFLOW! (capacity=%d)\n", MAX - 1);
    }

    printf("\n── Underflow Demonstration ─────────────────────\n");
    char c;
    while (!isEmpty()) dequeue(&c);
    printf("  Queue now empty. Trying to delete …\n");
    if (!dequeue(&c))
        printf("  UNDERFLOW!\n");

    /* Restore state */
    front = sf; rear = sr;
}

/* ────────────────────────── Main Menu ─────────────────────────────────── */

int main(void)
{
    int choice;
    printf("\n═══════════════════════════════════════════════════════\n");
    printf("   Practical_10 : Circular Queue of Characters         \n");
    printf("   Array Implementation  |  MAX Size = %d (cap = %d)  \n", MAX, MAX - 1);
    printf("═══════════════════════════════════════════════════════\n");

    do {
        printf("\n┌──────────────────────────────────────────────────┐\n");
        printf("│                    MAIN MENU                     │\n");
        printf("├──────────────────────────────────────────────────┤\n");
        printf("│  1. Insert element into Circular Queue           │\n");
        printf("│  2. Delete element from Circular Queue           │\n");
        printf("│  3. Demonstrate Overflow & Underflow             │\n");
        printf("│  4. Display Circular Queue status                │\n");
        printf("│  0. Exit                                         │\n");
        printf("└──────────────────────────────────────────────────┘\n");
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
