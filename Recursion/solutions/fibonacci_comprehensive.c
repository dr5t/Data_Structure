#include <stdio.h>
#include <stdlib.h>

/**
 * QUESTION: 
 * Write a C program to implement the Fibonacci sequence using three different approaches:
 * 1. Recursive (Simple)
 * 2. Iterative (Efficient)
 * 3. Dynamic Programming (Optimized Memoization)
 * 
 * Twist: Ability to print the nth term or the entire series up to n.
 */

// Approach 1: Recursive (Simple)
// Time Complexity: O(2^n) - Highly inefficient for large n
// Space Complexity: O(n) - Maximum depth of the recursion stack
long long fib_recursive(int n) {
    if (n <= 1) return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// Approach 2: Iterative (Efficient)
// Time Complexity: O(n)
// Space Complexity: O(1) - Most space-efficient version
long long fib_iterative(int n) {
    if (n <= 1) return n;
    long long prev = 0, curr = 1, next;
    for (int i = 2; i <= n; i++) {
        next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

// Approach 3: Dynamic Programming (Memoization)
// Time Complexity: O(n)
// Space Complexity: O(n) - To store the memoization array
long long fib_dp_memo(int n, long long* memo) {
    if (memo[n] != -1) return memo[n];
    if (n <= 1) return n;
    memo[n] = fib_dp_memo(n - 1, memo) + fib_dp_memo(n - 2, memo);
    return memo[n];
}

void print_series(int n) {
    printf("Fibonacci Series up to n=%d: ", n);
    for (int i = 0; i <= n; i++) {
        printf("%lld ", fib_iterative(i));
    }
    printf("\n");
}

int main() {
    int n, choice;
    printf("--- Fibonacci Special Focus ---\n");
    printf("Enter the value of n: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Error: Please enter a non-negative integer.\n");
        return 1;
    }

    printf("\nSelect Option:\n");
    printf("1. Recursive (Slowest)\n");
    printf("2. Iterative (Most Efficient Space)\n");
    printf("3. Dynamic Programming (Time Optimized)\n");
    printf("4. Print Series up to n\n");
    printf("Choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Calculating using Recursion...\n");
            printf("The %dth Fibonacci term is: %lld\n", n, fib_recursive(n));
            break;
        case 2:
            printf("Calculating using Iteration...\n");
            printf("The %dth Fibonacci term is: %lld\n", n, fib_iterative(n));
            break;
        case 3:
            printf("Calculating using Dynamic Programming...\n");
            long long* memo = (long long*)malloc((n + 1) * sizeof(long long));
            for (int i = 0; i <= n; i++) memo[i] = -1;
            printf("The %dth Fibonacci term is: %lld\n", n, fib_dp_memo(n, memo));
            free(memo);
            break;
        case 4:
            print_series(n);
            break;
        default:
            printf("Invalid choice!\n");
    }

    /* 
     * TIME COMPLEXITY COMPARISON:
     * Recursive: Exponential - O(2^n). For n=50, this takes billions of calls.
     * Iterative: Linear - O(n). Single pass through a for loop.
     * DP: Linear - O(n). Solves each subproblem exactly once.
     */

    return 0;
}
