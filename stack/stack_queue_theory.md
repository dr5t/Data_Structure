# Stack & Queue Theory & Concepts (Exam Guide)

## 1. Stack (LIFO)
### Definition
A **Stack** is a linear data structure that follows the **Last-In, First-Out (LIFO)** principle. The last element inserted is the first one to be removed.

### Operations
1. **Push**: Insert an element onto the top of the stack.
2. **Pop**: Remove the top element from the stack.
3. **Peek/Top**: View the top element without removing it.
4. **isEmpty**: Check if the stack is empty.

---

## 2. Queue (FIFO)
### Definition
A **Queue** is a linear data structure that follows the **First-In, First-Out (FIFO)** principle. The first element inserted is the first one to be removed.

### Operations
1. **Enqueue**: Insert an element at the **Rear** (back) of the queue.
2. **Dequeue**: Remove an element from the **Front** of the queue.
3. **Front/Rear**: Get the elements at the respective ends.

---

## 3. Types of Queues
1. **Circular Queue**: The last position is connected back to the first position to make a circle. This prevents memory wastage in array implementations.
2. **Priority Queue**: Each element is associated with a priority. Elements with higher priority are dequeued before lower priority ones.
3. **Deque (Double-Ended Queue)**: Elements can be inserted or deleted from **both** the front and the rear.

---

## 4. Concept Questions
### Stack vs Queue Comparison
| Feature | Stack | Queue |
| :--- | :--- | :--- |
| **Principle** | LIFO (Last-In, First-Out) | FIFO (First-In, First-Out) |
| **Access Point** | Single end (Top) | Two ends (Front/Rear) |
| **Pointers** | `top` | `front`, `rear` |
| **Application** | Recursion, Undo logic, DFS | Scheduling, Buffering, BFS |

### Overflow & Underflow
- **Stack Overflow**: Trying to push onto a full stack (limit reached).
- **Stack Underflow**: Trying to pop from an empty stack.
- **Queue Overflow**: `rear == MAX - 1`.
- **Queue Underflow**: `front > rear` or `front == -1`.

### Applications
- **Stack**: Parenthesis checking, Infix-to-Postfix conversion, Function calls (Call Stack).
- **Queue**: CPU Scheduling (Round Robin), Printer queues, Breadth-First Search (BFS).
