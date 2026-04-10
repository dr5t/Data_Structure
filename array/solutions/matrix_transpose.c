#include <stdio.h>

/* 
 * QUESTION: Matrix Transpose
 * Convert rows into columns and columns into rows.
 */

int main() {
    int r = 2, c = 3;
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int Transpose[3][2];

    printf("Original Matrix (2x3):\n");
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) printf("%d ", A[i][j]);
        printf("\n");
    }

    // Step: Transpose logic
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            Transpose[j][i] = A[i][j];
        }
    }

    printf("\nTransposed Matrix (3x2):\n");
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            printf("%d ", Transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}
