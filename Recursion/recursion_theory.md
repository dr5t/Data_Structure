# Recursion Theory & Concepts (Exam Guide)

## 1. Definition

**Recursion** is a programming technique where a function calls itself directly or indirectly to solve a problem. It breaks down a complex problem into smaller, more manageable sub-problems of the same type.

### Key Components of a Recursive Function:

1.  **Base Case**: The condition under which the function stops calling itself. Without a base case, the function will call itself infinitely, leading to a **Stack Overflow**.
2.  **Recursive Case**: The part of the function where the actual recursion happens. Here, the function calls itself with a modified (usually smaller) version of the original problem.

---

## 2. Recursion vs Iteration

| Feature | Recursion | Iteration |
| :--- | :--- | :--- |
| **Logic** | Uses function calls. | Uses loops (`for`, `while`). |
| **State** | Managed via the call stack. | Managed via local variables. |
| **Memory** | High (each call creates a stack frame). | Low (uses a fixed amount of memory). |
| **Performance** | Can be slower due to overhead. | Generally faster. |
| **Code Size** | Usually shorter and more readable. | Can be longer for complex logic. |

---

## 3. Stack Memory in Recursion

When a recursive function is called, a new **Activation Record** (also known as a **Stack Frame**) is created on the system stack.

### What's inside a Stack Frame?

- Local variables of the function.
- Parameters passed to the function.
- Return address (where to go back after the function finishes).

### The Process:

1.  **Winding Phase**: The function keeps calling itself, and stack frames are pushed onto the stack.
2.  **Unwinding Phase**: Once the base case is reached, the functions start returning, and stack frames are popped off the stack one by one.

> [!CAUTION]
> **Stack Overflow**: This occurs when the recursion is too deep or the base case is never reached, exhausting the available stack memory.

---

## 4. Types of Recursion

- **Direct Recursion**: Function A calls function A.
- **Indirect Recursion**: Function A calls function B, and function B calls function A.
- **Tail Recursion**: The recursive call is the *last* operation in the function. (Modern compilers can optimize this to be as efficient as iteration).
- **Non-Tail Recursion**: There is some work remaining after the recursive call returns.
