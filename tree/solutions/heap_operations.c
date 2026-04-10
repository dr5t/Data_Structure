#include <stdio.h>
#include <stdlib.h>

/**
 * QUESTION: Final Heap Mastery
 * Implement Max-Heap with Build, Insert, and Delete.
 * 
 * LOGIC:
 * 1. Heapify: Maintain heap property by "bubbling down" an element.
 * 2. Insert: Add at end and "bubble up".
 * 3. Delete: Replace root with last element and "bubble down".
 */

#define MAX_SIZE 100

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Max-Heapify logic
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Build a Max-Heap from an unsorted array
void buildHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

// Insert into Heap
void insertNode(int arr[], int *n, int val) {
    arr[*n] = val;
    int i = *n;
    (*n)++;

    // Bubble Up (Fix Heap property)
    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Delete Root (Highest Priority)
void deleteRoot(int arr[], int *n) {
    int lastElement = arr[*n - 1];
    arr[0] = lastElement;
    (*n)--;
    heapify(arr, *n, 0);
}

void printHeap(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[MAX_SIZE] = {10, 5, 3, 2, 4};
    int n = 5;

    buildHeap(arr, n);
    printf("Max Heap: "); printHeap(arr, n);

    printf("Inserting 15...\n");
    insertNode(arr, &n, 15);
    printHeap(arr, n);

    printf("Deleting Root (15)...\n");
    deleteRoot(arr, &n);
    printHeap(arr, n);

    return 0;
}
