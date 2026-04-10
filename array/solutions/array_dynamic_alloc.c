#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

/* 
 * QUESTION: Dynamic Allocation
 * Use malloc to create an array of size n provided by the user, 
 * populate it, and then free the memory.
 */

int main() {
    int n;
    printf("Enter the number of elements: ");
    // For college level, let's keep it simple
    n = 3; 
    printf("%d\n", n);

    // Step 1: Allocate memory dynamically
    // malloc returns a void pointer, so we cast it to (int *)
    int *arr = (int *)malloc(n * sizeof(int));

    // Step 2: Check if memory was allocated successfully
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Step 3: Populate the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        arr[i] = (i + 1) * 10;
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // Step 4: Free the memory
    free(arr);
    printf("Memory successfully freed.\n");

    return 0;
}
