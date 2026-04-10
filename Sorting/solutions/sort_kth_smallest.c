#include <stdio.h>

/* 
 * QUESTION: Find Kth Smallest Element
 * Logic: QuickSelect algorithm (Partitioning logic like QuickSort).
 * Complexity: O(n) Average, O(n^2) Worst Case.
 */

void swap(int* a, int* b) {
    int temp = *a; *a = *b; *b = temp;
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

        // If index is the k-th element, return it
        if (index - low == k - 1) return arr[index];

        // If k is less than index, search left
        if (index - low > k - 1)
            return quickSelect(arr, low, index - 1, k);

        // Otherwise search right
        return quickSelect(arr, index + 1, high, k - (index - low + 1));
    }
    return -1;
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    printf("Array: ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    
    int result = quickSelect(arr, 0, n - 1, k);
    printf("\nThe %drd smallest element is: %d\n", k, result);

    return 0;
}
