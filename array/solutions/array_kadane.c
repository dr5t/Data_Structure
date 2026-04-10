#include <stdio.h>

/* 
 * QUESTION: Kadane's Algorithm
 * Find the maximum sum of a contiguous subarray.
 */

int main() {
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max_so_far = arr[0];
    int current_max = arr[0];

    for (int i = 1; i < n; i++) {
        // Step: Either start a new subarray or continue the current one
        if (arr[i] > current_max + arr[i]) {
            current_max = arr[i];
        } else {
            current_max = current_max + arr[i];
        }

        // Update overall max
        if (current_max > max_so_far) {
            max_so_far = current_max;
        }
    }

    printf("Array: ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\nMaximum contiguous sum is: %d\n", max_so_far);

    return 0;
}
