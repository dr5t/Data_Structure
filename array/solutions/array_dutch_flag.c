#include <stdio.h>

/* 
 * QUESTION: Dutch National Flag Problem
 * Sort an array of 0s, 1s, and 2s in O(n) time.
 */

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int arr[] = {0, 1, 2, 0, 1, 2, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(&arr[low], &arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else { // arr[mid] == 2
            swap(&arr[mid], &arr[high]);
            high--;
        }
    }

    printf("Sorted array (0s, 1s, 2s): ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
