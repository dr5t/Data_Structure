/*
 * Practical_06: Stack of Integers – Array Implementation
 * MAX size defined at compile time.
 * Operations: Push, Pop, Palindrome check, Overflow/Underflow demo, Display
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

/* ────────────────────────── Stack Structure ───────────────────────────── */

int stack[MAX];
int top = -1;

/* ────────────────────────── Core Operations ───────────────────────────── */

int isFull(void)  { return top == MAX - 1; }
int isEmpty(void) { return top == -1; }

/* a. Push */
int push(int val)
{
    if (isFull()) return 0;          /* Overflow */
    stack[++top] = val;
    return 1;
}

/* b. Pop */
int pop(int *val)
{
    if (isEmpty()) return 0;         /* Underflow */
    *val = stack[top--];
    return 1;
}

int peek(void) { return isEmpty() ? -1 : stack[top]; }

/* e. Display */
void displayStack(void)
{
    if (isEmpty()) { printf("Stack is empty.\n"); return; }
    printf("\n  Stack (TOP → BOTTOM):\n  ");
    for (int i = top; i >= 0; i--)
        printf(i == top ? "[ %d ] ← TOP\n  " : "[ %d ]\n  ", stack[i]);
    printf("\n  Size used: %d / %d\n", top + 1, MAX);
}

/* ────────────────────────── Menu Handlers ─────────────────────────────── */

void menuPush(void)
{
    int val;
    printf("Enter integer to push: ");
    scanf("%d", &val);
    if (push(val))
        printf("  %d pushed onto stack.\n", val);
    else
        printf("  OVERFLOW! Stack is full (MAX = %d).\n", MAX);
}

void menuPop(void)
{
    int val;
    if (pop(&val))
        printf("  Popped: %d\n", val);
    else
        printf("  UNDERFLOW! Stack is empty.\n");
}

/* c. Palindrome check using stack */
void palindromeCheck(void)
{
    char str[50];
    int  tmpStack[50], tmpTop = -1;

    printf("Enter a string to check palindrome: ");
    scanf("%s", str);
    int len = strlen(str);

    /* Push all characters */
    for (int i = 0; i < len; i++) tmpStack[++tmpTop] = (int)tolower(str[i]);

    /* Pop and compare */
    int isPalin = 1;
    for (int i = 0; i < len; i++) {
        if ((char)tmpStack[tmpTop--] != tolower(str[i])) { isPalin = 0; break; }
    }
    printf("  \"%s\" is %sa palindrome.\n", str, isPalin ? "" : "NOT ");
}

/* d. Demonstrate Overflow and Underflow */
void demoOverflowUnderflow(void)
{
    printf("\n── Overflow Demonstration ──────────────────────\n");
    int tmpTop = top;   /* save state */
    int tmpStack[MAX];
    memcpy(tmpStack, stack, sizeof(stack));

    /* Fill to MAX */
    for (int i = 1; i <= MAX + 1; i++) {
        printf("  Pushing %d … ", i);
        if (push(i))
            printf("OK (top=%d)\n", top);
        else
            printf("OVERFLOW! (MAX=%d reached)\n", MAX);
    }

    printf("\n── Underflow Demonstration ─────────────────────\n");
    /* Empty the stack */
    int v;
    while (!isEmpty()) { pop(&v); }
    printf("  Popping from empty stack … ");
    if (!pop(&v))
        printf("UNDERFLOW!\n");

    /* Restore original stack */
    top = tmpTop;
    memcpy(stack, tmpStack, sizeof(stack));
}

/* ────────────────────────── Main Menu ─────────────────────────────────── */

int main(void)
{
    int choice;
    printf("\n═══════════════════════════════════════════════════════╗\n");
    printf("   Practical_06 : Stack of Integers (Array, MAX = %d)  ║\n", MAX);
    printf("═══════════════════════════════════════════════════════╝\n");

    do {
        printf("\n┌───────────────────────────────────────────────┐\n");
        printf("│                  MAIN MENU                    │\n");
        printf("├───────────────────────────────────────────────┤\n");
        printf("│  1. Push an element onto Stack                │\n");
        printf("│  2. Pop an element from Stack                 │\n");
        printf("│  3. Check Palindrome (using Stack)            │\n");
        printf("│  4. Demonstrate Overflow & Underflow          │\n");
        printf("│  5. Display Stack status                      │\n");
        printf("│  0. Exit                                      │\n");
        printf("└───────────────────────────────────────────────┘\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: menuPush();               break;
            case 2: menuPop();                break;
            case 3: palindromeCheck();        break;
            case 4: demoOverflowUnderflow();  break;
            case 5: displayStack();           break;
            case 0: printf("Exiting program. Goodbye!\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
