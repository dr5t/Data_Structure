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

## 4. Advanced Challenges
- **Next Greater Element:** For each element in an array, find the first greater element on its right side in $O(n)$ time.
- **Largest Rectangle in Histogram:** Find the area of the largest rectangle that can be formed within a given histogram.
- **Stock Span Problem:** Calculate the stock span for each day given daily prices.
- **Min-Stack:** Design a stack that supports `push`, `pop`, `top`, and `getMin` in constant $O(1)$ time.

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
