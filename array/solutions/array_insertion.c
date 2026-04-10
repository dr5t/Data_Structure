#include <stdio.h>

/* 
 * QUESTION: Insertion
 * Insert an element at a specific index in an array. 
 * Handle the case where the array is full.
 */

int main() {
    int arr[10] = {10, 20, 30, 40, 50}; // Capacity is 10
    int size = 5; // Current number of elements
    int capacity = 10;
    
    int elementToInsert = 25;
    int indexToInsert = 2;

    printf("Original array:\n");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    // Step 1: Check if there is space
    if (size >= capacity) {
        printf("Error: Array is full!\n");
    } else {
        // Step 2: Shift elements to the right to make space
        // We start from the end and move towards the target index
        for (int i = size; i > indexToInsert; i--) {
            arr[i] = arr[i - 1];
        }

        // Step 3: Insert the new element
        arr[indexToInsert] = elementToInsert;
        size++;

        printf("Array after insertion of %d at index %d:\n", elementToInsert, indexToInsert);
        for (int i = 0; i < size; i++) printf("%d ", arr[i]);
        printf("\n");
    }

    return 0;
}
