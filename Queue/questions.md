# Queue Practice Questions in C

Explore various queue implementations and algorithmic problems. Queues follow the First-In-First-Out (FIFO) principle.

## 1. Implementation Basics
- **Array-based Queue:** Implement a fixed-size queue using an array with `enqueue`, `dequeue`, `front`, and `isEmpty` operations.
- **Linked List Queue:** Implement a dynamic queue using a linked list. Manage `front` and `rear` pointers.
- **Circular Queue:** Implement a circular queue using an array to efficiently reuse space.
- **Double Ended Queue (Deque):** Implement a Deque with operations to add/remove from both ends.

## 2. Core Concepts
- **Full vs Empty Check:** Write robust logic to handle overflow and underflow conditions in fixed-size implementations.
- **Dynamic Resizing:** Modify your array implementation to double in size when the queue is full.

## 3. Algorithmic Problems
- **Reverse a Queue:** Reverse the elements of a queue using a stack or recursion.
- **Implement Stack using Queues:** Create a stack using two queues.
- **Queue using Stacks:** Create a queue using two stacks (standard interview problem).
- **Interleave Halves:** Interleave the first half of the queue with the second half.
- **Generate Binary Numbers:** Use a queue to generate binary numbers from 1 to `n`.

## 4. Priority Queues
- **Simple Priority Queue:** Implement a queue where each element has a priority, and the element with the highest priority is dequeued first.
- **Sliding Window Maximum:** Find the maximum for every contiguous subarray of size `k` using a Deque.

## 5. Advanced Challenges
- **Circular Tour (Gas Station Problem):** Find the starting point to complete a circular tour where you have a set of gas stations.
- **LRU Cache (Concept):** Discuss how a queue (specifically a Deque) is used in the implementation of an LRU cache.

## 🔥 EXAM ESSENTIALS (IMPORTANT)
- **Implement Queue using Array**
- **Enqueue & Dequeue Operations** ⭐
- **Check Overflow & Underflow**
- **Display Queue**
- **Circular Queue Implementation** ⭐⭐

## C-Specific Tips
> [!IMPORTANT]
> - For Linked List implementations, ensure you update the `rear` pointer correctly when the list becomes empty or gets its first element.
> - In Circular Queues, use the modulo operator `%` for index wrapping.
