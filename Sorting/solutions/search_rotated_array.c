#include <stdio.h>

/**
 * PROBLEM: SEARCH IN ROTATED SORTED ARRAY
 * --------------------------------------
 * Logic:
 * 1. Calculate mid.
 * 2. If nums[mid] == target, return mid.
 * 3. Identify which side is sorted:
 *    - If nums[low] <= nums[mid], the left side is sorted.
 *      - If target is within [nums[low], nums[mid]], search left.
 *      - Otherwise, search right.
 *    - Else, the right side must be sorted.
 *      - If target is within [nums[mid], nums[high]], search right.
 *      - Otherwise, search left.
 * 
 * Time Complexity: O(log n)
 */

int search(int nums[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) return mid;

        // Left half is sorted
        if (nums[low] <= nums[mid]) {
            if (target >= nums[low] && target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // Right half is sorted
        else {
            if (target > nums[mid] && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 0;

    printf("Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nTarget: %d\n", target);

    int result = search(arr, n, target);

    if (result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found.\n");

    return 0;
}
