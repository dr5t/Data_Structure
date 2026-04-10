#include <stdio.h>

/* 
 * QUESTION: Binary Search
 * Implement binary search on a sorted array.
 */

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60}; // Array must be sorted
    int size = 6;
    int target = 40;
    
    int low = 0;
    int high = size - 1;
    int foundIndex = -1;

    printf("Searching for %d using Binary Search...\n", target);

    while (low <= high) {
        int mid = low + (high - low) / 2; // Calculate middle index

        if (arr[mid] == target) {
            foundIndex = mid;
            break;
        } else if (arr[mid] < target) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }

    if (foundIndex != -1) {
        printf("Element %d found at index %d.\n", target, foundIndex);
    } else {
        printf("Element %d not found.\n", target);
    }

    return 0;
}
