#include <stdio.h>

/* 
 * QUESTION: Traversal
 * Write a program to print all elements in an array 
 * using both index-based and pointer-based traversal.
 */

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    // 1. Index-based traversal
    printf("Index-based traversal:\n");
    for (int i = 0; i < size; i++) {
        printf("Element at index %d is %d\n", i, arr[i]);
    }

    printf("\n");

    // 2. Pointer-based traversal
    printf("Pointer-based traversal:\n");
    int *ptr = arr; // ptr points to the first element
    for (int i = 0; i < size; i++) {
        printf("Element at address %p is %d\n", (void*)(ptr + i), *(ptr + i));
    }

    return 0;
}
