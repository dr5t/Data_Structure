#include <stdio.h>

/* 
 * QUESTION: Priority Queue (Max-Heap)
 * Standard college-level implementation using an array to store a binary heap.
 */

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a; *a = *b; *b = temp;
}

// 1. Insert (Enqueue)
void enqueue(int val) {
    if (size >= MAX) return;
    heap[size] = val;
    int i = size;
    size++;

    // Heapify-Up
    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// 2. Extract Max (Dequeue)
int dequeue() {
    if (size <= 0) return -1;
    if (size == 1) {
        size--;
        return heap[0];
    }

    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;

    // Heapify-Down
    int i = 0;
    while (1) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heap[left] > heap[largest]) largest = left;
        if (right < size && heap[right] > heap[largest]) largest = right;

        if (largest != i) {
            swap(&heap[i], &heap[largest]);
            i = largest;
        } else break;
    }
    return root;
}

int main() {
    enqueue(10);
    enqueue(30);
    enqueue(20);
    enqueue(5);

    printf("Priority Queue Extract Max elements:\n");
    printf("%d\n", dequeue()); // Should be 30
    printf("%d\n", dequeue()); // Should be 20

    return 0;
}
