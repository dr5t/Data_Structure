/*
 * Practical_11: Searching and Sorting on Integer Array
 * a. Linear Search
 * b. Binary Search
 * c. Selection Sort
 * d. Bubble Sort
 * e. Insertion Sort
 * f. Quick Sort
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

/* ─────────────────────────── Utility ───────────────────────────────────── */

void readArray(int arr[], int *n)
{
    printf("Enter number of elements (max %d): ", MAX_SIZE);
    scanf("%d", n);
    if (*n <= 0 || *n > MAX_SIZE) { printf("Invalid size.\n"); exit(1); }
    printf("Enter %d integers:\n  ", *n);
    for (int i = 0; i < *n; i++) scanf("%d", &arr[i]);
}

void printArray(const int arr[], int n)
{
    printf("  [ ");
    for (int i = 0; i < n; i++) printf("%d%s", arr[i], i < n-1 ? ", " : " ");
    printf("]\n");
}

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

/* ─────────────────────────── a. Linear Search ──────────────────────────── */

void linearSearch(const int arr[], int n)
{
    int key;
    printf("Enter key to search: ");
    scanf("%d", &key);
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("  Element %d found at index %d (position %d).\n", key, i, i+1);
            found = 1;
        }
    }
    if (!found) printf("  Element %d NOT found in array.\n", key);
    printf("  Comparisons made: %d  (O(n) worst-case)\n", n);
}

/* ─────────────────────────── b. Binary Search ──────────────────────────── */

void binarySearch(int arr[], int n)
{
    /* Sort first */
    int sorted[MAX_SIZE];
    memcpy(sorted, arr, n * sizeof(int));
    /* Using simple sort for prerequisite */
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (sorted[j] > sorted[j+1]) swap(&sorted[j], &sorted[j+1]);

    printf("  Sorted array for binary search:\n  ");
    printArray(sorted, n);

    int key, lo = 0, hi = n - 1, comps = 0, found = -1;
    printf("Enter key to search: ");
    scanf("%d", &key);

    while (lo <= hi) {
        comps++;
        int mid = lo + (hi - lo) / 2;
        printf("  [Step %2d] lo=%d hi=%d mid=%d  arr[mid]=%d\n",
               comps, lo, hi, mid, sorted[mid]);
        if (sorted[mid] == key)   { found = mid; break; }
        else if (sorted[mid] < key) lo = mid + 1;
        else                        hi = mid - 1;
    }
    if (found >= 0)
        printf("  Element %d found at sorted index %d.\n", key, found);
    else
        printf("  Element %d NOT found.\n", key);
    printf("  Comparisons: %d  (O(log n))\n", comps);
}

/* ─────────────────────────── c. Selection Sort ─────────────────────────── */

void selectionSort(int arr[], int n)
{
    int sorted[MAX_SIZE];
    memcpy(sorted, arr, n * sizeof(int));
    printf("  Before: "); printArray(sorted, n);

    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (sorted[j] < sorted[minIdx]) minIdx = j;
        swap(&sorted[i], &sorted[minIdx]);
        printf("  Pass%2d: "); printArray(sorted, n);
    }
    printf("  After (sorted): "); printArray(sorted, n);
    printf("  Complexity: O(n²) comparisons, O(n) swaps\n");
}

/* ─────────────────────────── d. Bubble Sort ────────────────────────────── */

void bubbleSort(int arr[], int n)
{
    int sorted[MAX_SIZE];
    memcpy(sorted, arr, n * sizeof(int));
    printf("  Before: "); printArray(sorted, n);

    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (sorted[j] > sorted[j+1]) { swap(&sorted[j], &sorted[j+1]); swapped = 1; }
        }
        printf("  Pass%2d: "); printArray(sorted, n);
        if (!swapped) { printf("  (Early termination – already sorted)\n"); break; }
    }
    printf("  After (sorted): "); printArray(sorted, n);
    printf("  Complexity: O(n²) worst, O(n) best (with early exit)\n");
}

/* ─────────────────────────── e. Insertion Sort ─────────────────────────── */

void insertionSort(int arr[], int n)
{
    int sorted[MAX_SIZE];
    memcpy(sorted, arr, n * sizeof(int));
    printf("  Before: "); printArray(sorted, n);

    for (int i = 1; i < n; i++) {
        int key = sorted[i], j = i - 1;
        while (j >= 0 && sorted[j] > key) { sorted[j+1] = sorted[j]; j--; }
        sorted[j+1] = key;
        printf("  Insert %2d: "); printArray(sorted, n);
    }
    printf("  After (sorted): "); printArray(sorted, n);
    printf("  Complexity: O(n²) worst, O(n) best\n");
}

/* ─────────────────────────── f. Quick Sort ─────────────────────────────── */

int partition(int arr[], int lo, int hi)
{
    int pivot = arr[hi], i = lo - 1;
    for (int j = lo; j < hi; j++) {
        if (arr[j] <= pivot) { i++; swap(&arr[i], &arr[j]); }
    }
    swap(&arr[i+1], &arr[hi]);
    return i + 1;
}

void quickSortHelper(int arr[], int lo, int hi, int *step)
{
    if (lo < hi) {
        int pi = partition(arr, lo, hi);
        printf("  Step%2d (pivot=%d at idx %d): ", ++(*step), arr[pi], pi);
        /* Print full array */
        printf("[ ");
        for (int i = 0; i <= hi; i++) {        /* print sub-array range */
            if (i == pi) printf("*%d* ", arr[i]);
            else         printf("%d ", arr[i]);
        }
        printf("]\n");
        quickSortHelper(arr, lo, pi - 1, step);
        quickSortHelper(arr, pi + 1, hi, step);
    }
}

void quickSort(int arr[], int n)
{
    int sorted[MAX_SIZE];
    memcpy(sorted, arr, n * sizeof(int));
    printf("  Before: "); printArray(sorted, n);
    int step = 0;
    quickSortHelper(sorted, 0, n - 1, &step);
    printf("  After (sorted): "); printArray(sorted, n);
    printf("  Complexity: O(n log n) average, O(n²) worst\n");
}

/* ─────────────────────────── Main Menu ─────────────────────────────────── */

int main(void)
{
    int arr[MAX_SIZE], n = 0;
    int choice;

    printf("\n═══════════════════════════════════════════════════════\n");
    printf("   Practical_11 : Searching and Sorting on Arrays      \n");
    printf("═══════════════════════════════════════════════════════\n");

    do {
        printf("\n┌────────────────────────────────────────────────────┐\n");
        printf("│                    MAIN MENU                       │\n");
        printf("├────────────────────────────────────────────────────┤\n");
        printf("│  1. Input / Reset array                            │\n");
        printf("│  2. Display current array                          │\n");
        printf("│  3. Linear Search                                  │\n");
        printf("│  4. Binary Search (sorts a copy first)             │\n");
        printf("│  5. Selection Sort (on a copy)                     │\n");
        printf("│  6. Bubble Sort    (on a copy)                     │\n");
        printf("│  7. Insertion Sort (on a copy)                     │\n");
        printf("│  8. Quick Sort     (on a copy)                     │\n");
        printf("│  0. Exit                                           │\n");
        printf("└────────────────────────────────────────────────────┘\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice >= 3 && n == 0) {
            printf("  Please input the array first (option 1).\n");
            continue;
        }

        switch (choice) {
            case 1: readArray(arr, &n); printf("  Array stored.\n"); break;
            case 2: if (n) { printf("  Current array: "); printArray(arr, n); }
                    else printf("  Array is empty.\n"); break;
            case 3: linearSearch(arr, n);  break;
            case 4: binarySearch(arr, n);  break;
            case 5: selectionSort(arr, n); break;
            case 6: bubbleSort(arr, n);    break;
            case 7: insertionSort(arr, n); break;
            case 8: quickSort(arr, n);     break;
            case 0: printf("Exiting program. Goodbye!\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
