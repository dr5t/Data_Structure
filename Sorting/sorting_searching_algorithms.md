# Searching & Sorting Algorithms (Step-by-Step)

## 1. Sorting Algorithms
### Bubble Sort
1. Traverse from $i = 0$ to $n-1$.
2. In each pass, traverse from $j = 0$ to $n-i-1$.
3. If `arr[j] > arr[j+1]`, **Swap** them.
4. **Optimization**: If no swap occurred in a pass, the array is already sorted. Return.

### Selection Sort
1. Traverse from $i = 0$ to $n-1$.
2. Assume $i$ is the minimum index (`min_idx = i`).
3. Traverse from $j = i+1$ to $n-1$.
4. If `arr[j] < arr[min_idx]`, update `min_idx = j`.
5. **Swap** `arr[i]` with `arr[min_idx]`.

### Insertion Sort
1. Traverse from $i = 1$ to $n-1$.
2. Pick `key = arr[i]`.
3. Shift elements of `arr[0..i-1]` that are greater than `key` to one position ahead.
4. Insert `key` at the correct empty location.

---

## 2. Advanced Algorithms
### Merge Two Sorted Arrays (Two-pointer)
1. Initialize $i=0, j=0, k=0$.
2. While both arrays have elements:
   - If `A[i] < B[j]`, then `C[k++] = A[i++]`.
   - Else, `C[k++] = B[j++]`.
3. Copy remaining elements from $A$ or $B$.

### QuickSelect (kth smallest element)
1. Pick a pivot element.
2. Partition the array so elements $< pivot$ are on the left and $> pivot$ are on the right.
3. If pivot position $pos$ is equal to $k-1$, return `arr[pos]`.
4. If $k-1 < pos$, search in the **left** partition.
5. Else, search in the **right** partition.
