#include <stdio.h>

/* 
 * QUESTION: Reverse Array
 * Reverse the elements of an array in-place.
 */

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;

    printf("Original array: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    // Step: Swap elements from outside moving in
    int start = 0;
    int end = size - 1;

    while (start < end) {
        // Simple swap logic
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }

    printf("Reversed array: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
