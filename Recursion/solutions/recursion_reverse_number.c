#include <stdio.h>

/**
 * QUESTION: Write a program to reverse a number using recursion.
 * 
 * ALGORITHM:
 * 1. Base Case: If n is 0, return.
 * 2. Print n % 10 (the last digit).
 * 3. Call the function again with n / 10.
 */

void reverseNumber(int n) {
    if (n == 0) return;
    printf("%d", n % 10);
    reverseNumber(n / 10);
}

int main() {
    int num;
    printf("Enter a number to reverse: ");
    if (scanf("%d", &num) != 1) {
        printf("Error: Please enter a valid integer.\n");
        return 1;
    }

    if (num == 0) {
        printf("Reversed Number: 0\n");
    } else {
        printf("Reversed Number: ");
        if (num < 0) {
            printf("-");
            num = -num;
        }
        reverseNumber(num);
        printf("\n");
    }

    return 0;
}
