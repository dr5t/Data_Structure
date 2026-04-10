#include <stdio.h>

/* 
 * QUESTION: Sliding Window Maximum
 * Find the maximum in every window of size k.
 * Optimized O(n) approach using a Monotonic Deque.
 */

#define MAX 100

void slidingWindowMax(int arr[], int n, int k) {
    int deque[MAX];
    int front = 0, rear = -1;

    for (int i = 0; i < n; i++) {
        // 1. Remove indices out of window [i-k+1, i]
        while (rear >= front && deque[front] <= i - k) {
            front++;
        }

        // 2. Remove indices corresponding to elements smaller than current
        while (rear >= front && arr[deque[rear]] <= arr[i]) {
            rear--;
        }

        // 3. Add current index to back
        deque[++rear] = i;

        // 4. Output the front of deque as max (only if window is full)
        if (i >= k - 1) {
            printf("%d ", arr[deque[front]]);
        }
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    printf("Sliding Window Maximum (k=%d): ", k);
    slidingWindowMax(arr, n, k);

    return 0;
}
