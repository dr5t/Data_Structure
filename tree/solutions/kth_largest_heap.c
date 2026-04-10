#include <stdio.h>
#include <stdlib.h>

/**
 * PROBLEM: FIND K-th LARGEST ELEMENT
 * ---------------------------------
 * Logic: 
 * 1. Maintain a Min-Heap of size K.
 * 2. If current element is larger than Min-Heap root (smallest in heap), 
 *    replace root and Min-Heapify.
 * 3. After processing all elements, the root of the Min-Heap is the K-th largest.
 * 
 * Why Min-Heap?
 * Because the root always holds the SMALLEST of the "K largest" elements, 
 * which is exactly the K-th largest!
 */

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Min-Heapify to maintain smaller elements at top
void minHeapify(int arr[], int size, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && arr[l] < arr[smallest])
        smallest = l;
    if (r < size && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, size, smallest);
    }
}

int findKthLargest(int arr[], int n, int k) {
    // 1. Create a Min-Heap of the first K elements
    // We treat the first K elements of arr as our heap
    int* minHeap = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        minHeap[i] = arr[i];
    }

    // Build Min-Heap for these K elements
    for (int i = k / 2 - 1; i >= 0; i--) {
        minHeapify(minHeap, k, i);
    }

    // 2. Process remaining elements
    for (int i = k; i < n; i++) {
        // If element is larger than the smallest in our "K largest" set
        if (arr[i] > minHeap[0]) {
            minHeap[0] = arr[i];
            minHeapify(minHeap, k, 0);
        }
    }

    int result = minHeap[0];
    free(minHeap);
    return result;
}

int main() {
    int arr[] = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    printf("Array: ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    
    int result = findKthLargest(arr, n, k);
    printf("\n%d-th Largest Element: %d\n", k, result);

    return 0;
}
