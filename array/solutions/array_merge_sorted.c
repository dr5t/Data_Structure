#include <stdio.h>

/* 
 * QUESTION: Merge Two Sorted Arrays
 * Logic: Use two pointers to compare and merge both arrays in O(m+n).
 */

void mergeSorted(int arr1[], int n1, int arr2[], int n2, int result[]) {
    int i = 0, j = 0, k = 0;

    // Compare and merge
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }

    // Copy remaining elements
    while (i < n1) result[k++] = arr1[i++];
    while (j < n2) result[k++] = arr2[j++];
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {2, 4, 6, 8, 10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int result[n1 + n2];

    printf("Array 1: "); printArray(arr1, n1);
    printf("Array 2: "); printArray(arr2, n2);

    mergeSorted(arr1, n1, arr2, n2, result);
    
    printf("Merged Array: "); printArray(result, n1 + n2);
