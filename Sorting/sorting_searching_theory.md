# Searching & Sorting Theory (Exam Guide)

## 1. Searching Strategies
### Linear Search vs Binary Search
| Feature | Linear Search | Binary Search |
| :--- | :--- | :--- |
| **Prerequisite** | None (Any array) | **Sorted** array |
| **Logic** | Scan one by one | Divide and Conquer |
| **Time Complexity** | $O(n)$ | $O(\log n)$ |
| **Best Case** | $O(1)$ (First element) | $O(1)$ (Middle element) |
| **Space Complexity** | $O(1)$ | $O(1)$ |

---

## 2. Sorting Concepts
### Stability in Sorting
- **Stable Sort**: Maintains the relative order of elements with equal values.
  - *Example*: If you sort a list of students by "Age", and two students have the same age, a stable sort keeps them in the same order they were in originally.
  - *Stable Sorts*: Bubble Sort, Insertion Sort, Merge Sort.
- **Unstable Sort**: Does not guarantee the original relative order for equal values.
  - *Unstable Sorts*: Selection Sort, Quick Sort, Heap Sort.

### Sorting Algorithms Overview
1. **Bubble Sort**: "Bubbles" the largest element to the end by swapping adjacent elements.
2. **Selection Sort**: "Selects" the minimum element and places it at the start.
3. **Insertion Sort**: "Inserts" each element into its correct position in a sorted subarray.

---

## 3. Complexity Master Table
| Algorithm | Best Case | Average Case | Worst Case | Space | Stability |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Bubble Sort** | $O(n)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | Stable |
| **Selection Sort** | $O(n^2)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | Unstable |
| **Insertion Sort** | $O(n)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | Stable |
| **Merge Sort** | $O(n \log n)$ | $O(n \log n)$ | $O(n \log n)$ | $O(n)$ | Stable |
| **Quick Sort** | $O(n \log n)$ | $O(n \log n)$ | $O(n^2)$ | $O(\log n)$ | Unstable |

---

## 4. Concept Questions
### Why is Binary Search faster?
Binary search reduces the search space by half in every step. For $n=1024$, Linear Search takes up to 1024 steps, while Binary Search takes only 10 steps ($\log_2 1024 = 10$).

### Selection Sort vs Insertion Sort
- Selection sort always takes $O(n^2)$ because it scans the entire remaining list to find the minimum.
- Insertion sort is **adaptive**; if the array is already sorted, it takes $O(n)$.
