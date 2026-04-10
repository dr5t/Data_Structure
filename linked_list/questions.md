# Linked List Practice Questions in C

This document covers questions for Singly, Doubly, and Circular Linked Lists, with an emphasis on manual memory management and pointer logic.

## 1. Foundational Concepts
- **Definition:** Define a `struct Node` with `int data` and a `struct Node* next`.
- **Implementation:** Implement `insertAtHead`, `insertAtTail`, and `deleteNode` functions. Handle `NULL` head cases.
- **Traversal:** Print all elements by iterating with a temporary pointer.
- **Length:** Count the nodes iteratively and recursively.
- **Memory Management:** Write a `freeList` function to correctly deallocate all nodes in a list using `free()`.

## 2. Core Techniques
- **Reverse List:** Reverse a singly linked list in-place (Iterative and Recursive).
- **Find Middle:** Use the "Slow and Fast Pointer" technique to find the middle node.
- **Cycle Detection:** Implement Floyd’s Cycle-Finding Algorithm.
- **Remove N-th Node from End:** Delete the node in a single pass using two pointers.
- **Palindrome Check:** Determine if a linked list is a palindrome (hint: use a stack or reverse the second half).

## 3. Multiple Lists & Sorting
- **Merge Sorted Lists:** Combine two sorted lists into a single sorted list.
- **Intersection Point:** Find the node where two singly linked lists merge.
- **Sort List:** Implement Merge Sort for linked lists.
- **Add Two Numbers:** Represent numbers as linked lists (one digit per node) and add them.

## 4. Doubly & Circular Linked Lists
- **DLL Implementation:** Define a `struct` with `prev` and `next` pointers. Implement insertion and deletion.
- **Reverse DLL:** Reverse a doubly linked list by swapping `next` and `prev` pointers.
- **Circular singly LL:** Create a list where the last node points to the head. Implement traversal (use a `do-while` loop).
- **Split Circular List:** Divide a circular linked list into two halves.

- **LRU Cache:** Implement an LRU cache using a Doubly Linked List for order and a Hash Map (or simplified array-based hash) for access.

---

## 🌳 BEYOND SYLLABUS (MASTER SET)

### 1. Pointer Mastery (High Efficiency)
- **Detect & Remove Loop ⭐⭐⭐**: Write a program to find if a cycle exists, locate the start, and break the loop.
- **Find Intersection Point**: Given two lists, find the node where they merge without extra space (using differential length).
- **Reverse in Groups of K ⭐⭐**: Given a list and a number `k`, reverse every group of `k` nodes.

### 2. Logic & Variations
- **Circular Check**: Determine if a Singly Linked List is circular.
- **Segregate Even & Odd**: Rearrange the list such that all even nodes appear before odd nodes (maintaining relative order).
- **Merge Two Sorted Lists (In-place)**: Merge two lists without creating new nodes.

### 3. Professional Patterns
- **Sentinel Node Deletion**: Remove all nodes with value `val` from a linked list using a dummy head.
- **Flattening**: Flatten a list where each node also has a `child` pointer to another list.

---

## 🔥 EXAM ESSENTIALS (MOST IMPORTANT)
- **Create a Singly Linked List**
- **Insert: At Beginning ⭐, At End ⭐, At Position ⭐**
- **Delete: From Beginning, End, and Position ⭐**
- **Traverse Linked List**
- **Reverse a Linked List** ⭐⭐
- **Find Middle Element**
- **Count Number of Nodes**
- **Search Element in List**

## C-Specific Tips
> [!WARNING]
> - Always check if the head is `NULL` before performing operations.
> - When deleting a node, ensure you `free()` the memory to avoid leaks.
> - Be careful with pointer assignments; a single wrong assignment can break the entire list or cause a segmentation fault.
