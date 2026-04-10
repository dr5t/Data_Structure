#include <stdio.h>

/**
 * QUESTION: Write a C program to find the factorial of a number using recursion.
 * 
 * ALGORITHM:
 * 1. Base Case: If n is 0 or 1, return 1.
 * 2. Recursive Case: Return n * factorial(n - 1).
 */

long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return (long long)n * factorial(n - 1);
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    if (scanf("%d", &num) != 1 || num < 0) {
        printf("Error: Please enter a non-negative integer.\n");
        return 1;
    }

    printf("Factorial of %d is %lld\n", num, factorial(num));
    return 0;
}
