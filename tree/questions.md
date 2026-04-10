# Tree Practice Questions in C

Explore hierarchical data structures, focusing on Binary Trees and Binary Search Trees (BSTs).

## 1. Implementation & Traversals
- **Node Definition:** Define a `struct Node` with `int data`, and pointers to `left` and `right`.
- **DFS Traversals:** Implement In-order, Pre-order, and Post-order traversals recursively.
- **BFS Traversal (Level-Order):** Print elements level by level (requires a queue).
- **Iterative Traversal:** Challenge yourself by implementing In-order traversal using a stack instead of recursion.

## 2. Basic Properties
- **Tree Height:** Find the maximum depth/height of the tree.
- **Node Count:** Count the total number of nodes in the tree.
- **Leaf Count:** Count the number of leaf nodes (nodes with no children).
- **Check Balance:** Determine if a binary tree is height-balanced.

## 3. Binary Search Trees (BST)
- **Insert & Search:** Implement functions to insert a value and search for a value in a BST.
- **Deletion:** Implement the logic to delete a node from a BST (consider all cases: leaf, one child, two children).
- **Validate BST:** Check if a given binary tree is a valid BST.
- **Min/Max in BST:** Find the smallest and largest elements in a BST ($O(h)$ time).

## 4. Intermediate Problems
- **Lowest Common Ancestor (LCA):** Find the LCA for two given nodes in a Binary Tree and a BST.
- **Diameter of Tree:** Find the longest path between any two nodes in a tree.
- **Mirror Tree:** Create the mirror image of a binary tree by swapping left and right children.
- **Nodes at Distance K:** Print all nodes at distance `K` from the root.

## 5. Advanced Challenges
- **Serialize & Deserialize:** Convert a tree into a string/array and back into a tree.
- **Tree to DLL:** Convert a binary tree to a doubly linked list in-place.
- **BST from Sorted Array:** Construct a height-balanced BST from a sorted array.
- **AVL Tree Basics:** Discuss rotation concepts (LL, RR, LR, RL) for maintaining tree balance.

## C-Specific Tips
> [!IMPORTANT]
> - Always remember to handle the base case `if (root == NULL)` in recursive functions to avoid segmentation faults.
> - When deleting nodes, ensure you `free()` the memory to prevent leaks.
