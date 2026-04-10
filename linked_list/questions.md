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

## 5. Advanced Challenges
- **Clone List with Random Pointer:** Deep copy a list where nodes have an extra `random` pointer.
- **Flattening:** Flatten a multi-level linked list.
- **LRU Cache:** Implement an LRU cache using a Doubly Linked List for order and a Hash Map (or simplified array-based hash) for access.

## 🔥 MOST IMPORTANT REPEATABLE QUESTIONS
- **Linked List Insertion & Deletion**
- **Reverse a Linked List (Iterative & Recursive)**
- **Find the Middle of a Linked List**
- **Cycle Detection (Floyd's Algorithm)**

## C-Specific Tips
> [!WARNING]
> - Always check if the head is `NULL` before performing operations.
> - When deleting a node, ensure you `free()` the memory to avoid leaks.
> - Be careful with pointer assignments; a single wrong assignment can break the entire list or cause a segmentation fault.
