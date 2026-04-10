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

#### 4. Factorial Call Stack (Dry Run)
**Logic**: `fact(n) = n * fact(n-1)`.
**Trace for `fact(3)`**:
1. `fact(3)` calls `fact(2)`
2. `fact(2)` calls `fact(1)` (Base Case reached, returns 1)
3. `fact(2)` becomes `2 * 1 = 2`
4. `fact(3)` becomes `3 * 2 = 6` (Final Result)

#### 5. Reverse a Number Recursively
**Steps**:
1. If number is 0, return.
2. Print `n % 10` (last digit).
3. Call function with `n / 10`.

### Sorting: Bubble vs Insertion

#### 1. Bubble Sort (Pass-by-Pass)
**Example**: `[5, 1, 4]`
- **Pass 1**:
  - Compare `5, 1` → Swap: `[1, 5, 4]`
  - Compare `5, 4` → Swap: `[1, 4, 5]` (Large element `5` is at the end)
- **Pass 2**:
  - Compare `1, 4` → No swap: `[1, 4, 5]`
- **Result**: `[1, 4, 5]`

#### 2. Insertion Sort (The "Card" Way)
**Example**: `[5, 1, 4]`
1. **Initial**: `[5 | 1, 4]` (left side is sorted)
2. **Insert 1**: Compare `1` with `5`. Pull `1` to the front: `[1, 5 | 4]`
3. **Insert 4**: Compare `4` with `5`. Pull `4` between `1` and `5`: `[1, 4, 5 | ]`
4. **Result**: `[1, 4, 5]`

---

## 3. Summaries of Key Data Structures

---

## 5. Arrays (Exam Essentials)

### A. Insert at Position
**Steps**:
1. Increase array size.
2. Shift elements from `index` to `n-1` to the right.
3. Insert `new_element` at `index`.
```c
for (int i = n; i > pos; i--)
    arr[i] = arr[i - 1];
arr[pos] = val;
```
**Dry Run**: `arr = [1, 2, 4], pos = 2, val = 3`
- Shift `arr[2]` to `arr[3]`: `[1, 2, 4, 4]`
- Place `3` at `index 2`: `[1, 2, 3, 4]`

### B. Delete from Position
**Steps**:
1. Shift elements from `index + 1` to `n-1` to the left.
2. Decrease array size.
```c
for (int i = pos; i < n - 1; i++)
    arr[i] = arr[i + 1];
```

### C. Find Second Largest
**Steps**:
1. Initialize `large` and `second` as very small values.
2. If `arr[i] > large`, update `second = large` and `large = arr[i]`.
3. Else if `arr[i] > second` and `arr[i] != large`, update `second = arr[i]`.

### D. Rotate Array (Right by 1)
**Steps**:
1. Store last element in `temp`.
2. Shift all elements to the right.
3. Put `temp` at the first position.
```c
int temp = arr[n-1];
for(int i=n-1; i>0; i--) arr[i] = arr[i-1];
arr[0] = temp;
```

### E. Merge Two Arrays
**Steps**:
1. Create a third array of size `n1 + n2`.
2. Copy elements of first array into it.
3. Copy elements of second array into it starting from `n1`.

---

## 5.1 Beyond Syllabus: High-Weightage Array Patterns

### 1. Two Pointers ⭐⭐⭐
Uses two pointers to process elements, often saving a nested loop.
- **Opposite Directions**: `left=0, right=n-1`. Used for **Two Sum** (on sorted arrays) or **Reversing**.
- **Same Direction (Fast & Slow)**: `slow=0, fast=0`. Used for **Removing Duplicates** or **Detecting Cycles**.

### 2. Sliding Window ⭐⭐⭐
Used to find subarrays that satisfy a condition.
- **Fixed Size**: Maintain a sum of $k$ elements. When window moves, subtract `arr[i-k]` and add `arr[i]`.
- **Variable Size**: Expand `right` to find a condition; shrink `left` to optimize.

### 3. Prefix Sum ⭐⭐
Precomputing a sum array where `P[i] = arr[0] + ... + arr[i]`.
- **Range Sum**: Sum from `L` to `R` = `P[R] - P[L-1]`.
- **Time Complexity**: $O(1)$ query after $O(n)$ precomputation.

---

## 5.2 Advanced 2D Matrix: Rotate In-Place (90°)

**Logic**: To rotate a matrix $90^\circ$ clockwise:
1.  **Transpose** the matrix (swap $A[i][j]$ with $A[j][i]$).
2.  **Reverse** each row.
- **Result**: In-place rotation with $O(1)$ extra space!

---

## 5.3 Array Optimization Tricks

### 1. XOR Property
- `x ^ x = 0`
- `x ^ 0 = x`
- **Use case**: Find the single non-repeating element in an array where every other element repeats twice. Simply XOR all elements!

### 2. XOR of first $N$ numbers
A fast way to find the XOR sum from $1 \dots n$ without a loop:
- If $n \% 4 == 0$: Result is $n$.
- If $n \% 4 == 1$: Result is $1$.
- If $n \% 4 == 2$: Result is $n+1$.
- If $n \% 4 == 3$: Result is $0$.

---

## 6.1 Beyond Syllabus: High-Weightage Linked List Patterns

### 1. Fast & Slow Pointers (Floyd's Algorithm) ⭐⭐⭐
Uses two pointers moving at different speeds (`fast = 2 steps, slow = 1 step`).
- **Use case**: Finding **Middle of List**, **Cycle Detection**, and **Cycle Start Point**.
- **Logic**: If they meet, there is a cycle. After meeting, reset `slow` to `head` and move both 1 step at a time; they will meet at the **Start of the Loop**.

### 2. In-place Reversal ⭐⭐⭐
Reversing the links without creating new nodes.
- **The 3-Pointer Dance**: Maintain `prev`, `curr`, and `next`.
  - `next = curr->next;`
  - `curr->next = prev;`
  - `prev = curr;`
  - `curr = next;`

### 3. Sentinel (Dummy) Nodes ⭐⭐
A dummy node placed at the head of the list.
- **Why?** It avoids checking `if (head == NULL)` repeatedly and simplifies edge cases (like deleting the first node).

---

## 6.2 Loop Detection & Removal Logic

**Problem**: A list has a cycle. Find it and break it.
1.  **Detect**: Use Fast & Slow pointers. If `fast == slow`, loop exists.
2.  **Find Start**: Keep `fast` where they met, move `slow` to `head`. Move both 1 step until they meet again. That's the **loop entry**.
3.  **Break**: Find the node that points back to the loop entry and set its `next` to `NULL`.

---

## 6.3 Advanced Variations

### 1. Circular Doubly Linked List
Useful for structures like **Music Playlists** where you want to loop back to the start or go back to the previous song in one step.

### 2. XOR Linked List (Bonus Insight)
A memory-efficient Doubly Linked List that uses only **one pointer field** per node.
- Each node stores `XOR(Address of Prev, Address of Next)`.
- To traverse, you XOR the stored value with the address of the previous node.

---

### A. Insert at Position
**Steps**:
1. Create new node.
2. Traverse to `index - 1`.
3. Set `newNode->next = current->next`.
4. Set `current->next = newNode`.
```c
struct Node* temp = head;
for(int i=0; i<pos-1; i++) temp = temp->next;
newNode->next = temp->next;
temp->next = newNode;
```

### B. Delete Position
**Steps**:
1. Traverse to `index - 1`.
2. Store `nodeToDelete = current->next`.
3. Set `current->next = nodeToDelete->next`.
4. `free(nodeToDelete)`.

### C. Reverse a Linked List (Dry Run)
**Logic**: Using 3 pointers: `prev`, `curr`, `next`.
```c
while (curr != NULL) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
}
head = prev;
```
**Dry Run**: `1 -> 2 -> 3`
- `curr=1, next=2`: `1->NULL`, `prev=1, curr=2`
- `curr=2, next=3`: `2->1`, `prev=2, curr=3`
- `curr=3, next=NULL`: `3->2`, `prev=3, curr=NULL`
- Result: `3 -> 2 -> 1`

### D. Find Middle Element (Tortoise & Hare)
**Steps**:
1. `slow = head, fast = head`.
2. While `fast != NULL` and `fast->next != NULL`:
   - `slow = slow->next` (1 step)
   - `fast = fast->next->next` (2 steps)
3. `slow` is now at the middle.

---

## 7. Stack & Queue (Common Questions)

### A. Stack Operations
- **Push**: `top++; arr[top] = x;`
- **Pop**: `x = arr[top]; top--; return x;`
- **Overflow**: `top == MAX - 1`
- **Underflow**: `top == -1`

### B. Circular Queue Implementation
**Steps**:
1. Circular Increment: `(index + 1) % MAX`.
2. **Enqueue**:
   - `rear = (rear + 1) % MAX`
   - `arr[rear] = val`
3. **Dequeue**:
   - `val = arr[front]`
   - `front = (front + 1) % MAX`
4. **Full Condition**: `(rear + 1) % MAX == front`.
5. **Empty Condition**: `front == -1`.

### C. Balanced Parentheses (Using Stack)
**Logic**: 
- Push opening brackets `( { [` onto stack.
- When closing bracket `) } ]` appears, pop top and check if they match.
- If stack is empty at end, it's balanced.

### D. Infix to Postfix (Basic Idea)
**Logic**:
- Operands: Print directly.
- Operators: Use stack. If operator in hand has higher precedence than `top`, push. Else, pop and print until precedence is lower.
- Opening Bracket: Push.
- Closing Bracket: Pop until matching opening bracket.

---

## 7.5 Beyond Syllabus: High-Weightage Stack Patterns

### 1. Monotonic Stack ⭐⭐⭐
A stack where elements are always in a specific order (increasing or decreasing).
- **Use case**: Finding the **Next Greater Element** or **Largest Rectangle in Histogram**.
- **Logic**: When a new element arrives, pop all elements from the stack that violate the order, then push the new element.

### 2. Min-Stack Logic ⭐⭐⭐
A stack that keeps track of the minimum element in $O(1)$ time.
- **Two-Stack Approach**: Use one stack for data and a second `minStack` where each level stores the minimum seen so far.
- **Efficiency**: Standard `push`/`pop` operations remain $O(1)$.

---

## 7.6 Advanced Queue Logic: Circular Tour (Gas Station)

**Problem**: Given $N$ gas stations in a circle, find a starting point to complete the full loop.
1. Use a **Queue-like** logic to maintain the `currentBalance`.
2. If `currentBalance` becomes negative at a station, reset the start point to the **next station** and reset balance.
3. Keep track of the `totalBalance` (sum of all fuel - sum of all cost). If `totalBalance < 0`, no tour is possible.

---

## 7.7 Strategy: Stack vs Queue for Reversals
- **Stack for Array Reversal**: $O(n)$ time, $O(n)$ space.
- **Queue for BFS**: Explores neighbor-by-neighbor in $O(n)$.
- **Tip**: To reverse a Queue, you MUST use a Stack (or Recursion).

---

## 8. Trees (The 5-Level Roadmap)

### Level 1: Basics (Foundation)
- **Node Structure**: Contains `data`, and pointers to `left` and `right`.
- **Traversals (In/Pre/Post)**:
    - **Inorder**: Left → Root → Right (Gives sorted order for BST).
    - **Preorder**: Root → Left → Right.
    - **Postorder**: Left → Right → Root.
- **Dry Run (Inorder)**: `[1, 2, 3]` (Binary Tree)
    - Visit `2`, Visit `1`, Visit `3` → `2 1 3`.

### Level 2: Binary Search Tree (BST)
- **Insertion**: Compare `key` with `root`. If smaller, go left. If larger, go right.
- **Searching**: Standard Binary Search logic applied to nodes.
- **Deletion (The 3 Case Rule)**:
    1. **Leaf**: Simply delete the node.
    2. **One Child**: Link the parent directly to the child.
    3. **Two Children**: Replace node with **Inorder Successor** (smallest in right subtree) or Predecessor.

### Level 3: Intermediate Logic
- **Mirroring**: Swap the left and right pointers of every node.
- **Level Order Traversal (BFS)**: Uses a **Queue**.
    - Push Root → Pop Root → Push Left/Right children → Repeat.
- **Check BST**: Ensure every node's value is within its allowed [min, max] range.

### Level 4: Advanced Mastery
- **Lowest Common Ancestor (LCA)**: The shared ancestor furthest from the root.
- **Height-Balanced**: For every node, $|Height(Left) - Height(Right)| \le 1$.
- **Diameter**: The longest path between any two nodes.

### Level 5: Hard / Interview Concepts
---

## 8. Trees: Beyond Syllabus Expansion

### 🔹 1. Tree Variations (Visual Cheat Sheet)
Identifying trees is a common exam favorite.
-   **Full Binary Tree**: Every node has either **0 or 2** children. No node has only 1 child.
-   **Complete Binary Tree**: Every level is completely filled, except possibly the last, and the last level is filled from **left to right**.
-   **Perfect Binary Tree**: All internal nodes have two children and all leaf nodes are at the **same level**.
-   **Skewed Tree**: All nodes have only one child (Left-skewed or Right-skewed). Effectively a Linked List.

### 🔹 2. Heap Mastery (The Priority Queue) ⭐⭐⭐
A **Heap** is a specialized Complete Binary Tree.
-   **Max-Heap**: Root is the largest; every parent $\ge$ children.
-   **Min-Heap**: Root is the smallest; every parent $\le$ children.
-   **Heapify (The Heart of Heap)**:
    -   Compare node with its children.
    -   If child is larger (in Max-Heap), swap and repeat downwards.
    -   *Complexity*: $O(\log n)$ to fix one node, $O(n)$ to build from scratch.
-   **Heap Sort**:
    1.  Build Max-Heap ($O(n)$).
    2.  Swap Root with Last, reduce size, and Heapify ($O(n \log n)$ total).

### 🔹 3. Tree Patterns (Recursive Thinking)
Mastering trees means mastering **Recursion Patterns**:
1.  **DFS Pattern (Bottom-Up)**:
    -   Compute result for Left Subtree.
    -   Compute result for Right Subtree.
    -   Combine them and return to Parent.
    -   *Use for*: Height, Diameter, Balanced check.
2.  **BFS Pattern (Level-Wise)**:
    -   Use a Queue.
    -   Process node, then push its children.
    -   *Use for*: Shortest path in unweighted tree, Top-view, Bottom-view.

### 🔹 4. Optimization: Single Traversal Thinking
Avoid repeated $O(n)$ calls inside a recursive function (which leads to $O(n^2)$).
-   **Example (Balanced Check)**: Instead of calling `height()` inside `isBalanced()`, make `isBalanced()` return the height *while* checking balance. If unbalanced, return -1.

### 🔹 5. Advanced Previews
-   **AVL Tree**: Self-balancing BST. Every node maintains a **Balance Factor** ($-1, 0, 1$). Uses **Rotations** (LL, RR, LR, RL) to fix imbalance.
-   **Trie (Prefix Tree)**: Used for string searching (dictionary, autocomplete). Each node represents a character.
-   **Heap Sort**: Efficiently finds **Kth Largest** element by extracting Max $K$ times.

---

## 🎯 TREE "DO OR DIE" MASTER SET
1. **Traversals** (In/Pre/Post) ⭐⭐⭐
2. **BST Insert/Delete** ⭐⭐⭐
3. **Heapify & Build Heap** ⭐⭐⭐
4. **Height & Diameter** ⭐⭐⭐
5. **Level Order Traversal** ⭐⭐
6. **LCA (Lowest Common Ancestor)** ⭐⭐
*. No node has only 1 child.
```text
      ( )           ( )
     /   \         /   \
   ( )   ( )     ( )   ( )
                /   \
```

### 2. Complete Binary Tree
All levels are completely filled except possibly the last level, and the last level has all nodes as far **left** as possible.
```text
      ( )           ( )
     /   \         /   \
   ( )   ( )     ( )   ( )
  /             /   \
( )           ( )   ( )
```

### 3. Perfect Binary Tree
All internal nodes have two children and all leave nodes are at the **same level**.
```text
      (1)
     /   \
   (2)   (3)
  /  \   /  \
(4)  (5)(6) (7)
```

### 4. Skewed Tree
A tree where every node has only one child (Left-skewed or Right-skewed). Essentially a **Linked List**.

---

## 8.6 Advanced Tree Types

### 1. AVL Tree (Self-Balancing) ⭐
A BST where the height difference (Balance Factor) between left and right subtrees is at most **1**.
- **Balance Factor** = `height(left) - height(right)`.
- If $|BF| > 1$, perform **Rotations**:
  - **LL / RR**: Single rotations.
  - **LR / RL**: Double rotations.

### 2. Heap (Min-Heap / Max-Heap) ⭐⭐
A **Complete Binary Tree** that satisfies the Heap Property.
- **Max-Heap**: Parent $\ge$ Children (Root is largest).
- **Min-Heap**: Parent $\le$ Children (Root is smallest).
- **Storage**: Usually stored in an **Array** for efficiency.
  - Parent of `i`: `(i-1)/2`
  - Left child: `2*i + 1`
  - Right child: `2*i + 2`

### 3. Trie (Prefix Tree)
Used for efficient string searching. Each node represents a character.
- *Use case*: Auto-complete, Dictionary.

---

## 8.7 Heap Mastery (Operations)

### 1. Heapify (The Core)
The process of rearranging a tree to maintain the heap property.
- **Complexity**: $O(\log n)$ for a single node, but building a heap from an array takes $O(n)$.

### 2. Heap Sort
1. Build a Max-Heap from the array.
2. Swap the root (max element) with the last element.
3. Reduce heap size and `heapify` the root.
4. Repeat until sorted.
- **Complexity**: $O(n \log n)$.

---

## 8.8 Tree Optimization Patterns

### 1. Reducing Traversal (O(n²) → O(n))
Many tree problems (like Diameter or Balanced Check) involve recalculating height inside a recursive call.
- **Inefficient**: `isBalanced(root)` calls `height(left)` and `height(right)`, then recurses.
- **Efficient**: Use a **single traversal** where the function returns both the height and the logic result (e.g., using a pointer or a struct).

### 2. Memoization on Trees
Store results of sub-problems to avoid repeated work (common in DP on Trees).

---

## 9. Graphs (Complete Mastery Roadmap)

### Level 1: Graph Representation
- **Adjacency Matrix**: A 2D array `adj[V][V]` where `adj[i][j] = 1` if there is an edge.
    - *Pros*: Fast edge check ($O(1)$).
    - *Cons*: Uses more space ($O(V^2)$).
- **Adjacency List**: An array of linked lists. Each `adj[i]` stores neighbors of `i`.
    - *Pros*: Space-efficient for sparse graphs ($O(V+E)$).

### Level 2: Traversals (BFS & DFS) ⭐⭐⭐
- **BFS (Breadth First Search)**: Uses a **Queue**. Explores neighbor-by-neighbor.
    - *Logic*: Push Source → Pop → Mark Visited → Push Unvisited Neighbors → Repeat.
- **DFS (Depth First Search)**: Uses a **Stack** (or Recursion). Explores as deep as possible.
    - *Logic*: Visit Node → Mark Visited → Recurse for Unvisited Neighbors.

### Level 3: Intermediate Logic
- **Cycle Detection**:
    - **Undirected**: Use DFS; if you find a visited neighbor that is NOT the parent, it's a cycle.
    - **Directed**: Use DFS; if you find a node currently in the **Recursion Stack**, it's a cycle.
- **Connected Components**: Total number of separate "islands" in the graph. Found by counting how many times you need to start a new BFS/DFS to visit all nodes.

### Level 4: Advanced Algorithms
- **Topological Sort**: A linear ordering of vertices such that for every directed edge $uv$, $u$ comes before $v$. (Only for DAGs).
- **Dijkstra's Algorithm**: Finds the shortest path from a source to all other nodes in a weighted graph (no negative weights).
- **Minimum Spanning Tree (MST)**: 
    - **Prim's**: Grows the tree from a starting node by picking the smallest edge connected to the current tree.
    - **Kruskal's**: Sorts all edges and adds them if they don't form a cycle.

### Level 5: Hard / Interview Mastery
- **Bellman-Ford**: Shortest path (handles negative weights).
- **Floyd-Warshall**: All-pairs shortest path ($O(V^3)$).
- **Kosaraju's Algorithm**: Finds Strongly Connected Components in 3 steps (DFS Stack → Transpose → DFS).

---

## 10. Hashing (Fast Access)

### Collision Resolution Strategies
1. **Open Addressing** (Linear Probing): If index `H(k)` is full, try `(H(k)+1) % size`.
    - *Cons*: Primary clustering (elements bunch together).
2. **Chaining**: Every cell of the hash table is a linked list. Multiple keys at the same index are added to the list.
    - *Pros*: Never "fills up" conceptually; easier to handle deletions.

---

## 🚀 THE GRAND MASTER COMPLEXITY TABLE

Use this table for 1-minute revision before the exam:

| Data Structure | Access | Search | Insertion | Deletion | Space |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Array** | $O(1)$ | $O(n)$ | $O(n)$ | $O(n)$ | $O(n)$ |
| **Stack** | $O(n)$ | $O(n)$ | $O(1)$ | $O(1)$ | $O(n)$ |
| **Queue** | $O(n)$ | $O(n)$ | $O(1)$ | $O(1)$ | $O(n)$ |
| **Linked List** | $O(n)$ | $O(n)$ | $O(1)$ | $O(1)$ | $O(n)$ |
| **Binary Search Tree** | $O(\log n)$ | $O(\log n)$ | $O(\log n)$ | $O(\log n)$ | $O(n)$ |
| **Hash Table** | N/A | $O(1)$ | $O(1)$ | $O(1)$ | $O(n)$ |
| **Graph** | N/A | $O(V+E)$ | $O(1)$ | $O(1)$ | $O(V+E)$ |

> [!IMPORTANT]
> - Hash Table worst-case search is $O(n)$ (if all keys collide).
> - BST worst-case is $O(n)$ if the tree is skewed (looks like a linked list).
