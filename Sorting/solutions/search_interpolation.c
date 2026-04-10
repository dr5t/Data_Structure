#include <stdio.h>

/* 
 * QUESTION: Interpolation Search
 * Improved binary search for uniformly distributed sorted arrays.
 */

int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = (n - 1);

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x) return low;
            return -1;
        }
        // Formula for position estimation
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]));

        if (arr[pos] == x) return pos;
        if (arr[pos] < x) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

int main() {
    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21};
    int n = 8;
    int x = 18;
    int index = interpolationSearch(arr, n, x);
    if (index != -1) printf("Element %d found at index %d\n", x, index);
    else printf("Element %d not found.\n", x);
    return 0;
}
