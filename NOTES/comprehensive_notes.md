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

### Fibonacci (Recursive vs Iterative)
-   **Recursive**: Calls itself. Easy to write, but slow ($O(2^n)$) because it re-calculates the same values many times.
-   **Iterative**: Uses a loop. Much faster ($O(n)$) and uses very little memory ($O(1)$).

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
