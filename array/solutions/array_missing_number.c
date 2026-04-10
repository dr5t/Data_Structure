#include <stdio.h>

/* 
 * QUESTION: Find Missing Number
 * An array contains n-1 integers from 1 to n. Find the one missing.
 * Concept: Sum of first n natural numbers = n*(n+1)/2
 */

int findMissing(int arr[], int n) {
    // Total sum should be n*(n+1)/2
    int total = (n + 1) * (n + 2) / 2;
    for (int i = 0; i < n; i++) {
        total -= arr[i];
    }
    return total;
}

int main() {
    int arr[] = {1, 2, 4, 5, 6}; // 3 is missing
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Here n = 5 elements, so total range is 1 to 6
    int missing = findMissing(arr, n);
    printf("The missing number is: %d\n", missing);

    return 0;
}
