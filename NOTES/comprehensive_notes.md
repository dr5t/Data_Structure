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

## 6. Linked List (Must Practice)

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
- **Zig-zag Traversal**: Use two stacks to change directions at each level.
- **Construct from Traversals**: Use Preorder to find Root and Inorder to find Left/Right boundaries.

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
