#include <stdio.h>
#include <string.h>

/**
 * QUESTION: Write a C program to reverse a string using recursion.
 * 
 * ALGORITHM:
 * 1. Base Case: If the string is empty or has one character, return.
 * 2. Recursive Case: Swap the first and last character, then recurse on the remaining substring.
 */

void reverseString(char* str, int start, int end) {
    if (start >= end) {
        return;
    }

    // Swap first and last character
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursive call
    reverseString(str, start + 1, end - 1);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character if it exists
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    printf("Original String: %s\n", str);
    reverseString(str, 0, len - 1);
    printf("Reversed String: %s\n", str);

    return 0;
}
