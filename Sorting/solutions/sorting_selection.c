#include <stdio.h>

/* 
 * QUESTION: Selection Sort
 * Find the minimum element from unsorted part and put it at the beginning.
 */

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        // Swap
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int n = 5;
    selectionSort(arr, n);
    printf("Sorted array (Selection Sort): ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
