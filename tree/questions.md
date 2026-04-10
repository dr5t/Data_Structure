# Tree Practice Questions (5-Level Roadmap)

## 🔰 LEVEL 1: BASICS (Foundation)
- **Node Implementation:** Define a `struct Node` with `left`, `right`, and `data`.
- **Traversals ⭐⭐⭐:** Implement Inorder, Preorder, and Postorder recursively.
- **Node Counting:**
  - Count Total Nodes.
  - Count Leaf Nodes (nodes with no children).
  - Count Non-leaf Nodes.
- **Height of Tree ⭐⭐⭐:** Find the maximum depth of the tree.
- **Search:** Find if an element exists in a simple Binary Tree.

## ⚙️ LEVEL 2: BINARY SEARCH TREE (CORE + EXAM)
- **BST Insertion ⭐⭐⭐:** Create a BST from a set of values.
- **BST Searching ⭐⭐⭐:** Find a value in a BST in $O(log n)$ average time.
- **BST Deletion ⭐⭐⭐:** Implement deletion for all cases:
  - Case 1: Leaf node.
  - Case 2: Node with one child.
  - Case 3: Node with two children (Inorder Successor).
- **Min/Max in BST:** Find the smallest and largest elements.

## 🧠 LEVEL 3: INTERMEDIATE (Logic Building)
- **Mirror Image ⭐:** Convert a tree to its mirror version.
- **Check if BST ⭐⭐:** Validate whether a Binary Tree satisfies BST properties.
- **Level Order Traversal (BFS) ⭐⭐⭐:** Print tree level-by-level using a Queue.
- **Nodes at Level K:** Count or print all nodes at distance $k$ from root.

## 🚀 LEVEL 4: ADVANCED (High-Level Mastery)
- **Lowest Common Ancestor (LCA) ⭐⭐⭐:** Find the shared ancestor furthest from root.
- **Diameter of Tree ⭐⭐:** Find the longest path between any two nodes.
- **Balanced Check ⭐⭐:** Check if $|Height(Left) - Height(Right)| \le 1$ for all nodes.
- **Path Root-to-Node:** Print the path from root to a target node.

## 🔥 LEVEL 5: HARD / INTERVIEW
- **Serialize & Deserialize Tree:** Convert tree to array/string and back.
- **Construct Tree from Traversals:** Build a unique tree using Inorder and Preorder/Postorder arrays.
- **Zig-zag Traversal:** Print nodes in alternating left-to-right and right-to-left order.

---

## 🌳 BEYOND SYLLABUS (MASTER SET)

### 1. Pattern Mastery (Recursive Thinking)
- **DFS Recursive Template:** Implement a function that returns a value from its children (e.g., `Max Depth`).
- **BFS (Level-wise):** Print the average value of each level.
- **Divide & Conquer:** Check if a tree is a **Subtree** of another tree.

### 2. Binary Tree Variations
- **Full vs. Complete Check:** Write code to verify if a tree is Full or Complete.
- **Perfect Tree Height:** Given `n` nodes, is it possible to form a Perfect Binary Tree?

### 3. Heap Operations (MUST DO) ⭐⭐⭐
- **Build Heap:** Convert an unsorted array into a Max-Heap in $O(n)$.
- **Heap Insertion & Deletion:** Implement both for a Min-Heap.
- **K-th Largest Element:** Solve using a Min-Heap of size `k`.
- **Heap Sort:** Implement the full sorting algorithm.

### 4. Advanced Tree Logic
- **AVL Single Rotation:** Implement `leftRotate` and `rightRotate`.
- **Optimization:** Solve "Check if Balanced"👉 If weak here → nothing ahead will work.

## 🚀 LEVEL 6: BEYOND SYLLABUS - PATTERNS
- **Recursive Pattern Mastery:** Solve 5 different tree problems using the same "Bottom-Up" DFS pattern.
- **Return Values:** Write a function that returns a boolean, an int, and a pair of values (depth and diameter) from recursion.
- **Top-Down vs Bottom-Up:** Explain the difference with code examples.

## ⚙️ LEVEL 7: BINARY TREE VARIATIONS
- **Identify Variations:** Write functions to check for:
  - Full Binary Tree ⭐
  - Complete Binary Tree ⭐
  - Perfect Binary Tree ⭐
- **Skewed Tree Check:** Identify if a tree is left or right skewed.

## 🧠 LEVEL 8: HEAP SPECIAL FOCUS (CORE)
- **Build Heap:** Implement `build_max_heap()` in $O(n)$ time. ⭐⭐⭐
- **Heapify:** Implement the `heapify()` function (Down-heap). ⭐⭐⭐
- **Insert/Delete:** Implement `insert()` and `delete_root()` for a Max-Heap.
- **Heap Sort:** Sort an array using the Heap algorithm. ⭐⭐

## 🌟 LEVEL 9: ADVANCED TREE TYPES
- **AVL Logic:** Explain (with diagrams) the 4 types of rotations (LL, RR, LR, RL). ⭐
- **Trie Basics:** Implement a basic Trie to insert and search for strings. ⭐⭐
- **Heap Application:** Find the **Kth Largest** element in an array using a Heap. ⭐⭐

## 🔥 LEVEL 10: OPTIMIZATION THINKING
- **Single Traversal:** Convert an $O(n^2)$ Balanced Tree check into an $O(n)$ "single traversal" solution.
- **Space Optimization:** Solve a level-order problem using $O(1)$ extra space (if possible).

## 🎯 TREE "DO OR DIE" MASTER SET
1. **Traversals** (In/Pre/Post) ⭐⭐⭐
2. **BST Insert/Delete** ⭐⭐⭐
3. **Heapify & Build Heap** ⭐⭐⭐
4. **Height & Diameter** ⭐⭐⭐
5. **Level Order Traversal** ⭐⭐
6. **LCA** ⭐⭐
