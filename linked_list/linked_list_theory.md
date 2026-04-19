# Linked List Theory & Concepts (Exam Guide)

## 1. Definitions

### What is a Linked List?

A **Linked List** is a linear data structure where elements are not stored in contiguous memory locations. Instead, each element (called a **Node**) contains a data field and a reference (**Pointer**) to the next node in the sequence.

### Types of Linked Lists

1. **Singly Linked List**: Each node points to the *next* node only. Traversal is one-way.
2. **Doubly Linked List**: Each node has two pointers: `next` and `prev`. Allows two-way traversal.
3. **Circular Linked List**: The last node points back to the `head` instead of `NULL`.

---

## 2. Structure of a Node (in C)

In C, a node is typically defined using a `struct`.

```c
struct Node {
    int data;           // Data part
    struct Node* next;  // Pointer to the next node
};

```

---

## 3. Dynamic Memory Allocation

Unlike arrays (where space is reserved at compile-time), linked lists use **Dynamic Memory Allocation**. Memory is allocated on the **heap** at runtime using C standard library functions:

- **`malloc()`**: Allocates a block of memory of a specific size.
- **`free()`**: De-allocates (releases) memory back to the system when no longer needed.
- **Example**: `struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));`

---

## 4. Concept Questions

### Why Linked List over Array?

1. **Dynamic Size**: Can grow or shrink at runtime.
2. **Ease of Insertion/Deletion**: No need to shift elements; we only update pointers.
3. **Efficient Memory Usage**: No wasted space if we don't know the exact size in advance.

### Advantages & Disadvantages

**Advantages**:
- Flexibility in size.
- Efficient insertions/deletions at any position.

**Disadvantages**:
- **Memory Overhead**: Extra memory is required for pointers.
- **Sequential Access**: No random access; we must traverse from the start to find an element ($O(n)$).
- **Reverse Traversal**: Difficult/impossible in Singly Linked Lists.
- **Cache Locality**: Poor, because nodes are scattered in memory.
