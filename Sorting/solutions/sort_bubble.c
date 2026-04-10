#include <stdio.h>
#include <stdbool.h>

/* 
 * QUESTION: Bubble Sort
 * Logic: Compare adjacent elements and swap if they are in the wrong order.
 */

void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // Optimization: If no two elements were swapped by inner loop, then break
        if (!swapped) break;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original: "); printArray(arr, n);
    bubbleSort(arr, n);
    printf("Sorted:   "); printArray(arr, n);
    
    return 0;
}
