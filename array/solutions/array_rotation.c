#include <stdio.h>

/* 
 * QUESTION: Array Rotation (Left)
 * Move all elements to the left by d positions.
 * E.g., [1,2,3,4,5] rotated by 2 becomes [3,4,5,1,2]
 */

void rotateLeft(int arr[], int d, int n) {
    int temp[d];
    // Copy first d elements to temp
    for (int i = 0; i < d; i++) temp[i] = arr[i];

    // Shift rest of the elements
    for (int i = d; i < n; i++) arr[i - d] = arr[i];

    // Copy temp back to end
    for (int i = 0; i < d; i++) arr[n - d + i] = temp[i];
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int d = 2; // Positions to rotate

    printf("Original array: "); printArray(arr, n);
    
    rotateLeft(arr, d, n);
    
    printf("After Left Rotation by %d: ", d); printArray(arr, n);

    return 0;
}
