# Array Algorithms (Step-by-Step)

## 1. Linear Search Algorithm

**Goal**: Find the position of an element `target` in an array.

1. **Start** from the first element (index 0).
2. **Compare** the current element with the `target`.
3. If current element == `target`, **return** the current index.
4. Move to the **next** element.
5. Repeat steps 2-4 until the end of the array.
6. If the end is reached and target not found, **return** -1 (Not Found).

**Time Complexity**: $O(n)$

---

## 2. Binary Search Algorithm (Iterative)

**Prerequisite**: The array MUST be **sorted**.

1. **Set** `low` to 0 and `high` to $n-1$.
2. **Calculate** `mid` = `low + (high - low) / 2`.
3. If `arr[mid]` == `target`, **return** `mid`.
4. If `arr[mid]` < `target`, update `low = mid + 1` (Search right half).
5. If `arr[mid]` > `target`, update `high = mid - 1` (Search left half).
6. **Repeat** steps 2-5 while `low <= high`.
7. If loop ends and target not found, **return** -1.

**Time Complexity**: $O(\log n)$
