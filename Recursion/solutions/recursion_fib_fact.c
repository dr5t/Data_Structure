#include <stdio.h>

/* 
 * QUESTION: Recursion Basics
 * Implement Factorial and Fibonacci series using recursion.
 */

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 5;
    printf("Factorial of %d is: %d\n", n, factorial(n));
    
    printf("Fibonacci series up to %d: ", n);
    for (int i = 0; i < n; i++) printf("%d ", fibonacci(i));
    printf("\n");

    return 0;
}
