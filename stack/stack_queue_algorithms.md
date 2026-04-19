# Stack & Queue Algorithms (Step-by-Step)

## 1. Stack Algorithms (Array Implementation)

### Push(val)

1. Check if `top == MAX - 1` (Overflow).
2. Increment `top`: `top = top + 1`.
3. Set `arr[top] = val`.

### Pop()

1. Check if `top == -1` (Underflow).
2. Retrieve `val = arr[top]`.
3. Decrement `top`: `top = top - 1`.
4. Return `val`.

---

## 2. Queue Algorithms (Circular)

### Enqueue(val)

1. Check if `(rear + 1) % MAX == front` (Queue Full).
2. If empty, set `front = 0`.
3. Update `rear`: `rear = (rear + 1) % MAX`.
4. Set `arr[rear] = val`.

### Dequeue()

1. Check if `front == -1` (Queue Empty).
2. Retrieve `val = arr[front]`.
3. If `front == rear` (Last element), set `front = rear = -1`.
4. Else, update `front`: `front = (front + 1) % MAX`.
5. Return `val`.

---

## 3. Priority Queue (Heapify Logic)

### Insert (Enqueue)

1. Insert the element at the end of the heap (array).
2. **Heapify-Up**: Compare with parent. If larger, swap and repeat until it reaches the root or parent is larger.

### Remove (Dequeue - Extract Max)

1. Replace the root with the last element.
2. Decrease heap size.
3. **Heapify-Down**: Compare root with children. Swap with the larger child and repeat downwards.

---

## 4. Sliding Window Maximum (O(n) Deque)

1. Create a `deque` (indices of elements).
2. For each element $i$:
   - Remove indices from front if they are outside the window $[i-k+1, i]$.
   - Remove indices from back if $arr[i] \ge arr[back]$.
   - Add $i$ to back.
   - Front of deque is the max for the current window.

---

## 5. Practice Problem Algorithms

### Balanced Parentheses

1. Initialize an empty stack.
2. Traverse the expression:
   - If current char is an opening bracket (`(`, `{`, `[`), **Push** it.
   - If current char is a closing bracket (`)`, `}`, `]`):
     - If stack is empty, **return False** (Unbalanced).
     - **Pop** from stack. If the popped bracket doesn't match the closing one, **return False**.
3. After traversal, if stack is empty, **return True**; else **return False**.

### Stack using Queues (Push-Efficient)

- **Push(x)**: Perform `enqueue(q1, x)`.
- **Pop()**:
  1. Dequeue all elements from `q1` except the last one and enqueue them into `q2`.
  2. The remaining element in `q1` is the one to return.
  3. Swap the names of `q1` and `q2`.

### Queue using Stacks (Enqueue-Efficient)

- **Enqueue(x)**: Perform `push(s1, x)`.
- **Dequeue()**:
  1. If `s2` is empty, pop all elements from `s1` and push them into `s2`.
  2. Pop from `s2` and return the value.
