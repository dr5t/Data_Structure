#include <stdio.h>

/* 
 * QUESTION: Find Min/Max
 * Find the smallest and largest elements in an array.
 */

int main() {
    int arr[] = {55, 23, 89, 10, 42};
    int size = 5;

    // Step 1: Initialize min and max with the first element
    int min = arr[0];
    int max = arr[0];

    // Step 2: Loop through the rest of the array
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i]; // Update min
        }
        if (arr[i] > max) {
            max = arr[i]; // Update max
        }
    }

    printf("Array elements: ");
    for(int i=0; i<size; i++) printf("%d ", arr[i]);
    
    printf("\nMinimum value: %d\n", min);
    printf("Maximum value: %d\n", max);

    return 0;
}
