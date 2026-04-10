#include <stdio.h>
#include <stdlib.h>

/**
 * PROBLEM: SLIDING WINDOW MAXIMUM
 * ------------------------------
 * Logic:
 * 1. Use a Deque (Double Ended Queue) to store indices of elements.
 * 2. The deque will maintain indices in decreasing order of element values.
 * 3. For each element `arr[i]`:
 *    - Remove indices from the front that are out of the current window.
 *    - Remove indices from the back whose corresponding values are <= `arr[i]`.
 *    - Add current index `i` to the back.
 *    - The front of the deque is the index of the maximum element for the current window.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(k)
 */

typedef struct {
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;
} Deque;

Deque* createDeque(int cap) {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->arr = (int*)malloc(cap * sizeof(int));
    dq->front = 0;
    dq->rear = -1;
    dq->size = 0;
    dq->capacity = cap;
    return dq;
}

void pushBack(Deque* dq, int val) {
    dq->rear = (dq->rear + 1) % dq->capacity;
    dq->arr[dq->rear] = val;
    dq->size++;
}

void popFront(Deque* dq) {
    dq->front = (dq->front + 1) % dq->capacity;
    dq->size--;
}

void popBack(Deque* dq) {
    dq->rear = (dq->rear - 1 + dq->capacity) % dq->capacity;
    dq->size--;
}

int getFront(Deque* dq) {
    return dq->arr[dq->front];
}

int getBack(Deque* dq) {
    return dq->arr[dq->rear];
}

int isEmpty(Deque* dq) {
    return dq->size == 0;
}

void slidingWindowMax(int arr[], int n, int k) {
    Deque* dq = createDeque(n); 

    printf("Sliding Window Maximums: ");

    for (int i = 0; i < n; i++) {
        // 1. Remove element from front if it's out of window
        if (!isEmpty(dq) && getFront(dq) == i - k) {
            popFront(dq);
        }

        // 2. Remove elements from back smaller than current (maintain monotonic property)
        while (!isEmpty(dq) && arr[getBack(dq)] <= arr[i]) {
            popBack(dq);
        }

        // 3. Add current element's index
        pushBack(dq, i);

        // 4. Print max of window (at the front)
        if (i >= k - 1) {
            printf("%d ", arr[getFront(dq)]);
        }
    }
    printf("\n");

    free(dq->arr);
    free(dq);
}

int main() {
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    printf("Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nWindow Size: %d\n", k);

    slidingWindowMax(arr, n, k);

    return 0;
}
