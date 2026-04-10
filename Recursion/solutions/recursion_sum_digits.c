#include <stdio.h>

/**
 * QUESTION: Write a C program to calculate the sum of its digits using recursion.
 * 
 * ALGORITHM:
 * 1. Base Case: If number is 0, return 0.
 * 2. Recursive Case: Return (number % 10) + sumDigits(number / 10).
 */

int sumDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumDigits(n / 10);
}

int main() {
    int num;
    printf("Enter a number: ");
    if (scanf("%d", &num) != 1) {
        printf("Error: Please enter a valid integer.\n");
        return 1;
    }

    // Work with absolute value for negative numbers
    int abs_num = num < 0 ? -num : num;

    printf("Sum of digits of %d is: %d\n", num, sumDigits(abs_num));

    return 0;
}
