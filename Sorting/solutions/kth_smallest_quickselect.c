#include <stdio.h>
#include <stdlib.h>

/**
 * PROBLEM: K-TH SMALLEST ELEMENT (QUICKSELECT)
 * -------------------------------------------
 * Logic:
 * 1. Choose a pivot (last element in this case).
 * 2. Partition the array such that elements < pivot are on the left.
 * 3. After partitioning, if pivot is at index `k-1`, we found the element.
 * 4. If `k-1 < pivot_index`, recurse on the left side.
 * 5. Else, recurse on the right side.
 * 
 * Time Complexity: Average O(n), Worst O(n^2).
 */

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

int quickSelect(int arr[], int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int index = partition(arr, low, high);

        // If partition index is same as k
        if (index - low == k - 1)
            return arr[index];

        // If partition index is more, recurse for left
        if (index - low > k - 1)
            return quickSelect(arr, low, index - 1, k);

        // Else recurse for right
        return quickSelect(arr, index + 1, high, k - index + low - 1);
    }

    return -1;
}

int main() {
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    printf("Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nFinding %d-rd Smallest Element...\n", k);

    int result = quickSelect(arr, 0, n - 1, k);

    if (result != -1)
        printf("The %d-rd smallest element is: %d\n", k, result);
    else
        printf("K is out of bounds.\n");

    return 0;
}
