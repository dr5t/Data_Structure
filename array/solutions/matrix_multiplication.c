#include <stdio.h>

/* 
 * QUESTION: Matrix Multiplication
 * Multiply two matrices A (m x n) and B (n x p).
 */

int main() {
    int r1 = 2, c1 = 2;
    int r2 = 2, c2 = 2;
    
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int Product[2][2] = {0};

    // Step: Standard matrix multiplication logic
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                Product[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("Resultant Matrix (Product):\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", Product[i][j]);
        }
        printf("\n");
    }

    return 0;
}
