#include <stdio.h>

/* 
 * QUESTION: Matrix Addition
 * Add two m x n matrices and store the result in a third matrix.
 */

int main() {
    int rows = 2, cols = 2;
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int Sum[2][2];

    printf("Matrix A:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) printf("%d ", A[i][j]);
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) printf("%d ", B[i][j]);
        printf("\n");
    }

    // Step: Add corresponding elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Sum[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("\nResultant Matrix (Sum):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", Sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}
