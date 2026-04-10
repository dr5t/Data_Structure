# Stack Practice Questions in C

Stacks are a fundamental LIFO (Last-In-First-Out) data structure. Explore implementations and common application-based problems.

## 1. Implementation Basics
- **Array Implementation:** Implement a stack using a fixed-size array. Include `push`, `pop`, `peek`, `isEmpty`, and `isFull` functions.
- **Linked List Implementation:** Implement a stack using a linked list for dynamic sizing.
- **Generic Stack:** Discuss how you would implement a stack that can store different data types (e.g., using `void*`).

## 2. Expression Evaluation
- **Balanced Parentheses:** Check if the parentheses in an expression (e.g., `{[()]}`) are balanced.
- **Postfix Evaluation:** Write a function to evaluate a postfix expression (e.g., `2 3 + 5 *`).
- **Infix to Postfix:** Convert an infix expression to a postfix expression using the Shunting-yard algorithm.
- **Infix to Prefix:** Convert an infix expression to its prefix form.

## 3. Core Algorithms
- **Reverse String:** Reverse a string using a stack.
- **Sort a Stack:** Sort the elements of a stack using recursion or another temporary stack.
- **Implement Queue using Stacks:** How can you implement a FIFO queue using two stacks?

- **Min-Stack:** Design a stack that supports `push`, `pop`, `top`, and `getMin` in constant $O(1)$ time.

---

## 🌳 BEYOND SYLLABUS (MASTER SET)

### 1. Pattern Mastery (High Efficiency)
- **Monotonic Stack ⭐⭐⭐**: For a given array, find the **Next Greater Element** to the right for every element in $O(n)$.
- **Min-Stack Implementation**: Create a stack that retrieves the minimum element in $O(1)$ time without searching.
- **Valid Parentheses (Advanced)**: Check if an expression with multiple bracket types is balanced.

### 2. Logic & Applications
- **Largest Rectangle in Histogram ⭐⭐**: Given an array of heights, find the largest area of a rectangle that can be formed in the histogram in $O(n)$.
- **Stock Span Problem**: Calculate the span of stock price for all $N$ days.
- **Circular Tour (Gas Station)**: Find the starting point to complete the full circular tour of $N$ gas stations.

### 3. Professional Variations
- **Implement Stack using One Queue**: (Logic) Use recursion to pull the last element of the queue to the front.
- **Sort Stack using Recursion**: Write a program to sort a stack without using loops or extra data structures (other than recursion).

---

## 🔥 EXAM ESSENTIALS (VERY COMMON)
- **Implement Stack using Array**
- **Push & Pop operations** ⭐
- **Peek operation**
- **Check Overflow & Underflow** ⭐
- **Balanced Parentheses** ⭐⭐
- **Infix to Postfix**

## C-Specific Tips
> [!TIP]
> - In an array implementation, the `top` variable should usually start at `-1`.
> - Always check for **Stack Overflow** before pushing and **Stack Underflow** before popping.
