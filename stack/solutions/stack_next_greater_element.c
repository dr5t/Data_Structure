#include <stdio.h>

/* 
 * QUESTION: Next Greater Element
 * Find the first greater element on the right for each element.
 */

#define MAX 100

void printNGE(int arr[], int n) {
    int stack[MAX], top = -1;

    for (int i = 0; i < n; i++) {
        while (top != -1 && stack[top] < arr[i]) {
            printf("%d --> %d\n", stack[top], arr[i]);
            top--;
        }
        stack[++top] = arr[i];
    }

    while (top != -1) {
        printf("%d --> -1\n", stack[top--]);
    }
}

int main() {
    int arr[] = {11, 13, 21, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printNGE(arr, n);
    return 0;
}
