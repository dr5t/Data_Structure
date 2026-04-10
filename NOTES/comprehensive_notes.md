# Comprehensive Data Structures & Algorithms Notes

Welcome to the master notes! This document consolidates all core theory and algorithms in an easy-to-understand format, perfect for exam preparation.

---

## 1. Important Theory (The Basics)

### What is a Data Structure?
A **Data Structure** is a specialized way of organizing, managing, and storing data in a computer so that it can be accessed and modified efficiently. 

### Types of Data Structures
1.  **Linear Data Structures**: Elements are arranged in a sequence or a linear list.
    - *Examples*: Arrays, Linked Lists, Stacks, Queues.
2.  **Non-Linear Data Structures**: Elements are not arranged in a sequence; they are organized hierarchically or in a network.
    - *Examples*: Trees, Graphs.

### Complexity Analysis (Big-O Basics)
-   **Time Complexity**: Describes the amount of time an algorithm takes to run relative to the input size $n$.
    - $O(1)$: Constant time (Fastest).
    - $O(\log n)$: Logarithmic time (Very efficient).
    - $O(n)$: Linear time (Fair).
    - $O(n^2)$: Quadratic time (Slow for large $n$).
-   **Space Complexity**: Describes the amount of memory an algorithm uses relative to the input size $n$.

### Memory Management: Static vs Dynamic
-   **Static Memory**: Size is fixed at compile-time (e.g., standard Arrays in C). It is allocated on the **Stack**.
-   **Dynamic Memory**: Size can change at runtime (e.g., using `malloc` for Linked Lists). It is allocated on the **Heap**.

### Abstract Data Type (ADT)
An **ADT** is a mathematical model for data types where the data type is defined by its behavior (operations) from the point of view of a user, rather than how it is implemented.
- *Example*: The **Stack ADT** defines *what* `push` and `pop` do, but doesn't specify *how* they are implemented (could be array or linked list).

---

## 2. Core Algorithms (Simplified)

### Binary Search (Trace Example)
**Logic**: Works only on **sorted** arrays. It repeatedly divides the search interval in half.

**Traced Example**: Search for `x = 7` in `arr = [1, 3, 5, 7, 9, 11]`
1.  **Initial**: `low = 0`, `high = 5`.
2.  **Step 1**: `mid = (0+5)/2 = 2`. `arr[2]` is `5`. Since `5 < 7`, move `low` to `mid + 1 = 3`.
3.  **Step 2**: `low = 3`, `high = 5`. `mid = (3+5)/2 = 4`. `arr[4]` is `9`. Since `9 > 7`, move `high` to `mid - 1 = 3`.
4.  **Step 3**: `low = 3`, `high = 3`. `mid = (3+3)/2 = 3`. `arr[3]` is `7`. **Match Found!**

### Fibonacci Special Focus (Must Practice)
Fibonacci is a sequence where each number is the sum of the two preceding ones ($0, 1, 1, 2, 3, 5, 8, \dots$).

#### 1. Recursive Solution (The "Conceptual" way)
```c
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
```
- **Pros**: Short and easy to understand.
- **Cons**: Extremely slow for large $n$ ($O(2^n)$) because it recalculates same values.

#### 2. Iterative Solution (The "Efficient" way)
```c
int fib(int n) {
    int prev=0, curr=1, next;
    for(int i=2; i<=n; i++) {
        next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}
```
- **Pros**: Fastest performance ($O(n)$) and uses least memory ($O(1)$).
- **Cons**: Requires managing multiple variables.

#### 3. Optimized (DP - Memoization)
Stashing previously calculated values in an array so you never calculate the same term twice.
- **Complexity**: $O(n)$ time and $O(n)$ space.

#### Exam Twist: Printing nth term vs. Series
- **Print nth**: Just call the function once for $n$.
- **Print series**: Wrap the iterative logic in a loop or modify the iterative function to print `curr` at each step.

#### Time Complexity Comparison
| Method | Time Complexity | Space Complexity | Recommendation |
| :--- | :--- | :--- | :--- |
| **Recursive** | $O(2^n)$ | $O(n)$ (Stack) | Avoid for $n > 30$. |
| **Iterative** | $O(n)$ | $O(1)$ | **Best for Exams.** |
| **DP** | $O(n)$ | $O(n)$ (Array) | Use for repeated queries. |

### Sorting: Bubble vs Insertion
-   **Bubble Sort**: Compare adjacent elements and swap them if they are in the wrong order. Repeat until the largest "bubbles" to the end.
-   **Insertion Sort**: Like sorting playing cards in your hand. Pick an element and insert it into its correct position in the "sorted portion" on the left.

---

## 3. Summaries of Key Data Structures

### Arrays
- **Definition**: Collection of similar types stored in contiguous memory.
- **Operations**: Insertion and Deletion take $O(n)$ time because elements might need to be shifted.

### Linked Lists
- **Definition**: A sequence of nodes where each node contains data and a pointer to the next node.
- **Insertion/Deletion**: Very fast ($O(1)$) if you already have a pointer to the location, as no shifting is required.

### Stacks (LIFO)
- **Operations**: `Push` (Add to top), `Pop` (Remove from top).
- **Application**: Balanced Parentheses - Use a stack to remember which brackets are currently open.

### Queues (FIFO)
- **Operations**: `Enqueue` (Add to back), `Dequeue` (Remove from front).
- **Circular Queue**: Connects the end back to the front to save space in array implementations.

---

## 4. Most Repeatable Exam Questions
1.  Binary Search implementation + Dry Run.
2.  Linked List Reversal.
3.  Circular Queue implementation steps.
4.  Balanced Parentheses checking using Stack.
5.  Comparison of Recursive vs Iterative Fibonacci.
