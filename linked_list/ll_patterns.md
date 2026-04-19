# Linked List Algorithm Patterns (The "Pointer" Cheat Sheet)

Manipulation of pointers is the key to solving complex linked list problems.

---

## 1. Fast & Slow Pointers (The "Tortoise & Hare")

**Logic**: Two pointers move at different speeds.
**Efficiency**: $O(n)$ time, $O(1)$ space.

### C Template (Cycle Detection)

```c
struct Node *slow = head, *fast = head;
while (fast != NULL && fast->next != NULL) {
    slow = slow->next;          // Move 1 step
    fast = fast->next->next;    // Move 2 steps
    if (slow == fast) return 1; // Cycle found!
}

```

---

## 2. In-place Reversal (The "3-Pointer Dance")

**Logic**: Change the `next` pointers of nodes to point backwards.

### C Template (Iterative)

```c
struct Node *prev = NULL, *curr = head, *next = NULL;
while (curr != NULL) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
}
head = prev;

```

---

## 3. Recursive Reversal (The "Elegant" Strategy)

**Logic**: Use the call stack to reach the end and then flip the links on the way back.

### C Template (Recursive)

```c
struct Node* reverse(struct Node* head) {
    if (head == NULL || head->next == NULL) return head;
    struct Node* rest = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

```

---

## 🎯 Comparison: Iterative vs. Recursive Reversal

| Feature | Iterative | Recursive |
| :--- | :--- | :--- |
| **Space** | $O(1)$ (Optimal) | $O(n)$ (Call stack overhead) |
| **Logic** | Easier to trace with pointers. | More elegant/shorter code. |
| **Suitability**| Best for manual memory management. | Use when space is not a concern. |

---

## Bonus Insight: XOR Linked List

An XOR Linked List saves space by storing only one pointer per node:
`node->npx = (prev) XOR (next)`.
To move forward, you calculate `next = (prev) XOR (node->npx)`.
This is an advanced variation often discussed in concept-heavy exams!
