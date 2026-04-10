#include <stdio.h>

/* 
 * QUESTION: Linear Search
 * Find the index of a target element in an unsorted array.
 */

int main() {
    int arr[] = {45, 12, 89, 33, 27};
    int size = 5;
    int target = 33;
    int foundIndex = -1;

    printf("Searching for %d in the array...\n", target);

    // Step 1: Iterate through the array
    for (int i = 0; i < size; i++) {
        // Step 2: Compare each element with the target
        if (arr[i] == target) {
            foundIndex = i;
            break; // Target found, stop searching
        }
    }

    // Step 3: Print the result
    if (foundIndex != -1) {
        printf("Element %d found at index %d.\n", target, foundIndex);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}
