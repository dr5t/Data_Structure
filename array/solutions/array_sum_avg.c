#include <stdio.h>

/* 
 * QUESTION: Sum & Average
 * Calculate the total sum and the average value of all elements in an array.
 */

int main() {
    int n, i;
    int arr[100];
    float sum = 0, average;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i]; // Accumulate sum
    }

    average = sum / n; // Calculate average

    printf("\nSum of elements = %.2f\n", sum);
    printf("Average of elements = %.2f\n", average);

    return 0;
}
