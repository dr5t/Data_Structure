#include <stdio.h>
#include <stdlib.h>

/**
 * PROBLEM: NEXT GREATER ELEMENT
 * ----------------------------
 * Logic:
 * 1. Use a Monotonic Stack to store elements for which we haven't found the next greater yet.
 * 2. Traverse the array. For each element `arr[i]`:
 *    - While stack is not empty and `stack.top < arr[i]`:
 *      - Pop element and set its next greater as `arr[i]`.
 *    - Push current element `arr[i]` onto stack.
 * 3. Elements remaining in stack have no next greater (-1).
 * 
 * Efficiency: $O(n)$ time.
 */

#define MAX 100

typedef struct {
    int items[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int x) {
    if (s->top == MAX - 1) return;
    s->items[++(s->top)] = x;
}

int pop(Stack* s) {
    if (isEmpty(s)) return -1;
    return s->items[(s->top)--];
}

int peek(Stack* s) {
    if (isEmpty(s)) return -1;
    return s->items[s->top];
}

void findNextGreater(int arr[], int n) {
    Stack s;
    initStack(&s);
    int* result = (int*)malloc(n * sizeof(int));

    // We store indices in the stack to easily mapped results
    for (int i = 0; i < n; i++) {
        while (!isEmpty(&s) && arr[peek(&s)] < arr[i]) {
            int index = pop(&s);
            result[index] = arr[i];
        }
        push(&s, i);
    }

    // Remaining elements in stack have no next greater
    while (!isEmpty(&s)) {
        int index = pop(&s);
        result[index] = -1;
    }

    // Print result
    printf("Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nNext Greater Elements: ");
    for (int i = 0; i < n; i++) printf("%d ", result[i]);
    printf("\n");

    free(result);
}

int main() {
    int arr[] = {4, 5, 2, 25, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    findNextGreater(arr, n);

    return 0;
}
