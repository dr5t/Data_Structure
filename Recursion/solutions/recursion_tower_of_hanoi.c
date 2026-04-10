#include <stdio.h>

/**
 * QUESTION: Write a C program to solve the Tower of Hanoi problem using recursion.
 * 
 * ALGORITHM:
 * 1. Base Case: If n=1, move the disk from Source to Destination.
 * 2. Recursive Case:
 *    a. Move n-1 disks from Source to Auxiliary.
 *    b. Move n-th disk from Source to Destination.
 *    c. Move n-1 disks from Auxiliary to Destination.
 */

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    
    // Move n-1 disks from Source to Auxiliary
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    
    // Move the n-th disk from Source to Destination
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    
    // Move n-1 disks from Auxiliary to Destination
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n;
    printf("Enter number of disks: ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Error: Please enter a positive integer.\n");
        return 1;
    }

    printf("Steps for %d disks:\n", n);
    towerOfHanoi(n, 'A', 'C', 'B'); // A: Source, B: Auxiliary, C: Destination
    
    return 0;
}
