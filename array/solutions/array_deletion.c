#include <stdio.h>

/* 
 * QUESTION: Deletion
 * Delete an element at a specific index and shift the remaining elements.
 */

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;
    int indexToDelete = 2; // Deleting '30'

    printf("Original array:\n");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    // Step 1: Check if index is valid
    if (indexToDelete < 0 || indexToDelete >= size) {
        printf("Error: Invalid index!\n");
    } else {
        // Step 2: Shift elements to the left to fill the gap
        for (int i = indexToDelete; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        // Step 3: Decrease the size
        size--;

        printf("Array after deletion at index %d:\n", indexToDelete);
        for (int i = 0; i < size; i++) printf("%d ", arr[i]);
        printf("\n");
    }

    return 0;
}
