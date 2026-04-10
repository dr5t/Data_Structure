#include <stdio.h>

/* 
 * QUESTION: Spiral Traversal
 * Print a 2D matrix in spiral order.
 */

int main() {
    int r = 4, c = 4;
    int matrix[4][4] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9,  10, 11, 12},
        {13, 14, 15, 16}
    };

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    printf("Spiral Traversal: ");

    while (top <= bottom && left <= right) {
        // 1. Move Left to Right
        for (int i = left; i <= right; i++) printf("%d ", matrix[top][i]);
        top++;

        // 2. Move Top to Bottom
        for (int i = top; i <= bottom; i++) printf("%d ", matrix[i][right]);
        right--;

        // 3. Move Right to Left
        if (top <= bottom) {
            for (int i = right; i >= left; i--) printf("%d ", matrix[bottom][i]);
            bottom--;
        }

        // 4. Move Bottom to Top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) printf("%d ", matrix[i][left]);
            left++;
        }
    }
    printf("\n");

    return 0;
}
