#include <stdio.h>

/**
 * QUESTION: Write a C program to calculate x raised to power n (x^n) using recursion.
 * 
 * ALGORITHM:
 * 1. Base Case: If n is 0, return 1.
 * 2. Recursive Case: Return x * power(x, n - 1).
 */

double power(double x, int n) {
    // Base case: any number to the power of 0 is 1
    if (n == 0) return 1;
    
    // Handling negative exponents
    if (n < 0) return 1 / power(x, -n);
    
    // Recursive case
    return x * power(x, n - 1);
}

int main() {
    double base;
    int exponent;

    printf("Enter base (x): ");
    scanf("%lf", &base);
    printf("Enter exponent (n): ");
    scanf("%d", &exponent);

    printf("%.2lf raised to the power %d is %.4lf\n", base, exponent, power(base, exponent));

    return 0;
}
