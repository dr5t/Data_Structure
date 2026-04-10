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
