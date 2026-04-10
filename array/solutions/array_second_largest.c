#include <stdio.h>
#include <limits.h>

/* 
 * QUESTION: Second Largest Element
 * Find the second largest element in an array in a single traversal (O(n)).
 */

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int first = INT_MIN, second = INT_MIN;

    for (int i = 0; i < n; i++) {
        // If current element is greater than first largest
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        }
        // If element is smaller than first but greater than second
        else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }

    if (second == INT_MIN)
        printf("There is no second largest element\n");
    else
        printf("The second largest element is: %d\n", second);

    return 0;
}
