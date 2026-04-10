#include <stdio.h>

/**
 * QUESTION: Write a C program to find the nth Fibonacci number and print the sequence using recursion.
 * 
 * ALGORITHM:
 * 1. Base Case: If n is 0 return 0, if n is 1 return 1.
 * 2. Recursive Case: Return fib(n-1) + fib(n-2).
 */

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("Enter the number of terms for the Fibonacci sequence: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Error: Please enter a non-negative integer.\n");
        return 1;
    }

    printf("Fibonacci Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    printf("The %dth Fibonacci number is: %d\n", n, fibonacci(n));

    return 0;
}
