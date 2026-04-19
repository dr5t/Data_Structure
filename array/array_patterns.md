# Array Algorithm Patterns (The "Mastery" Guide)

Most "hard" array problems are just combinations of these 3 pillars.

---

## 1. Two Pointers (The "Opposite" Strategy)

**Logic**: Use two pointers starting at both ends of a **sorted** array to find a pair.
**Efficiency**: $O(n)$ time vs $O(n^2)$ for nested loops.

### C Template

```c
int left = 0, right = n - 1;
while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == target) return 1; // Found!
    else if (sum < target) left++;
    else right--;
}

```

---

## 2. Sliding Window (The "Subarray" Strategy)

**Logic**: Maintain a contiguous range (window) that slides across the array.
**Efficiency**: Saves redundant calculations.

### C Template (Fixed Window)

```c
int windowSum = 0;
for (int i = 0; i < k; i++) windowSum += arr[i]; // First window

for (int i = k; i < n; i++) {
    windowSum += arr[i] - arr[i-k]; // Slide!
    // Process windowSum...
}

```

---

## 3. Prefix Sum (The "Range Query" Strategy)

**Logic**: Precompute cumulative sums to answer range queries instantly.

### C Template

```c
int prefix[n];
prefix[0] = arr[0];
for (int i = 1; i < n; i++)
    prefix[i] = prefix[i-1] + arr[i];

// Sum between L and R:
int rangeSum = (L == 0) ? prefix[R] : prefix[R] - prefix[L-1];

```

---

## 🎯 Pro-Tip: Rotate Matrix in-place

To rotate a 2D matrix by $90^\circ$:
1. **Transpose**: `Swap(A[i][j], A[j][i])` for all $i < j$.
2. **Reverse Rows**: `Reverse(A[i][0...n-1])`.

This is the most standard $O(1)$ space logic for matrix rotation.
