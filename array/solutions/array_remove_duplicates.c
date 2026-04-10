#include <stdio.h>

/* 
 * QUESTION: Remove Duplicates
 * From a SORTED array, remove duplicates and return new size.
 */

int removeDuplicates(int arr[], int n) {
    if (n == 0 || n == 1) return n;

    int j = 0; // Index for next unique element
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            arr[j++] = arr[i];
        }
    }
    arr[j++] = arr[n - 1]; // Copy last element
    return j;
}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);

    n = removeDuplicates(arr, n);

    printf("\nAfter removing duplicates: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
