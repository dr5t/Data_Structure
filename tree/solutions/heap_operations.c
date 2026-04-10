#include <stdio.h>
#include <stdlib.h>

/**
 * HEAP OPERATIONS (Max-Heap)
 * -------------------------
 * Logic:
 * - Parent of i: (i-1)/2
 * - Left child: 2*i + 1
 * - Right child: 2*i + 2
 */

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the Max-Heap property
// O(log n)
void heapify(int arr[], int n, int i) {
    int largest = i;    // Initialize largest as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to build a Max-Heap from an array
// O(n)
void buildHeap(int arr[], int n) {
    // Start from the last non-leaf node and heapify all nodes
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Function to insert a value into the Max-Heap
// O(log n)
void insert(int arr[], int* n, int val) {
    (*n)++;
    int i = *n - 1;
    arr[i] = val;

    // "Bubble up" the value to its correct position
    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to delete the root (Max element) from the Heap
// O(log n)
int deleteRoot(int arr[], int* n) {
    if (*n <= 0) return -1;

    int rootValue = arr[0];
    // Replace root with the last element
    arr[0] = arr[*n - 1];
    (*n)--;

    // "Heapify down" to restore balance
    heapify(arr, *n, 0);

    return rootValue;
}

// Function for Heap Sort
// O(n log n)
void heapSort(int arr[], int n) {
    // 1. Build Max-Heap
    buildHeap(arr, n);

    // 2. One by one extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root (largest) to end
        swap(&arr[0], &arr[i]);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Helper to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    printf("\n--- BUILDING MAX-HEAP ---\n");
    buildHeap(arr, n);
    printArray(arr, n);

    printf("\n--- INSERTING 15 ---\n");
    int heap[10] = {13, 11, 12, 5, 6, 7}; // Copy built heap
    int heapSize = 6;
    insert(heap, &heapSize, 15);
    printArray(heap, heapSize);

    printf("\n--- DELETING ROOT ---\n");
    deleteRoot(heap, &heapSize);
    printArray(heap, heapSize);

    printf("\n--- HEAP SORT ---\n");
    int arr2[] = {12, 11, 13, 5, 6, 7};
    heapSort(arr2, 6);
    printArray(arr2, 6);

    return 0;
}
