# Searching & Sorting Patterns (The "Precision" Guide)

Binary Search is the most powerful $O(\log n)$ tool, but its implementation depends on the condition.

---

## 1. The Binary Search "Decision Tree"

**Logic**: How to decide where to search?

### Template (Search in Rotated Array)

```c
int low = 0, high = n - 1;
while (low <= high) {
    int mid = low + (high - low) / 2;
    if (nums[mid] == target) return mid;

    // Is the Left side sorted?
    if (nums[low] <= nums[mid]) {
        if (target >= nums[low] && target < nums[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    // Otherwise, the Right side must be sorted!
    else {
        if (target > nums[mid] && target <= nums[high])
            low = mid + 1;
        else
            high = mid - 1;
    }
}

```

---

## 2. Searching for Boundaries (First/Last)

**Logic**: Instead of returning `mid`, store it as a "potential candidate" and keep searching.

### C Snippet (First Occurrence)

```c
int res = -1;
while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) {
        res = mid;
        high = mid - 1; // Keep searching left
    } else if (arr[mid] < target) low = mid + 1;
    else high = mid - 1;
}

```

---

## 3. QuickSelect (K-th Element)

**Logic**: Partition like Quick Sort, but only recurse into the part that contains the $K^{th}$ index.

### Logic (Pseudo-code)

```c
int partition(arr, low, high) {
    // Standard partitioning...
}

int quickSelect(arr, low, high, k) {
    int pi = partition(arr, low, high);
    if (pi == k) return arr[pi];
    else if (pi < k) return quickSelect(arr, pi + 1, high, k);
    else return quickSelect(arr, low, pi - 1, k);
}

```

---

## 🎯 Optimization Check: Stability

- **Merge Sort is Stable**: Used when you need to sort items by multiple criteria (e.g., sort by Price, then by Rating).
- **Quick Sort is Unstable**: Used for general data where space efficiency ($O(1)$ extra for in-place) is the priority.
